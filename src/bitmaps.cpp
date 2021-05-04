/////////////////////////////////////////////////////////////////////////////
// Purpose:   Contains various images handling functions
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020-2021 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../LICENSE
/////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <fstream>
#include <map>

#include <wx/mstream.h>  // Memory stream classes

#include <tttextfile.h>

#include "bitmaps.h"

wxImage GetHeaderImage(ttlib::cview filename, size_t* p_original_size, ttString* p_mime_type)
{
    wxImage image;

    if (!ttlib::file_exists(filename))
    {
        FAIL_MSG(ttlib::cstr() << filename << " passed to GetHeaderImage doesn't exist");
        return image;
    }

    std::ifstream fileOriginal(filename, std::ios::binary | std::ios::in);
    if (!fileOriginal.is_open())
    {
        FAIL_MSG(ttlib::cstr() << filename << " passed to GetHeaderImage could not be read");
        return image;
    }
    std::string in_buf(std::istreambuf_iterator<char>(fileOriginal), {});
    if (in_buf.size() < 1)
    {
        FAIL_MSG(ttlib::cstr() << filename << " is empty!");
        return image;
    }

    // Turn this into a null-terminated string. We don't care what's at the end, because it won't be a number.
    in_buf[in_buf.size() - 1] = 0;

    size_t image_buffer_size = 0;
    size_t actual_size = 0;

    auto buf_ptr = strchr(in_buf.c_str(), '[');
    if (buf_ptr)
    {
        image_buffer_size = ttlib::atoi(++buf_ptr);
    }

    buf_ptr = strchr(buf_ptr, '{');
    if (!buf_ptr)
    {
        FAIL_MSG(ttlib::cstr() << filename << " doesn't contain an opening brace");
        return image;
    }

    if (!image_buffer_size)
    {
        // wxFormBuilder doesn't add the size of the image in brackets so we have to parse it without storing the
        // results in order to calculate the size, then parse it again to actually store the data in an image buffer.

        auto save_ptr = buf_ptr;

        do
        {
            if (ttlib::is_digit(*buf_ptr))
            {
                ++image_buffer_size;

                // Step over any hex digit
                if (buf_ptr[0] == '0' && (buf_ptr[1] == 'x' || buf_ptr[1] == 'X'))
                    buf_ptr += 2;

                // Now step over the digit, then fall through and step over the first character following the digit
                do
                {
                    ++buf_ptr;
                } while (ttlib::is_digit(*buf_ptr));

                if (!*buf_ptr)
                    break;  // This will be a corrupted file since it didn't end with a closing '}' character
            }
            ++buf_ptr;
        } while (*buf_ptr);

        buf_ptr = save_ptr;
    }

    auto image_buffer = std::make_unique<unsigned char[]>(image_buffer_size);
    unsigned char* ptr_out_buf = image_buffer.get();

    // TODO: [KeyWorks - 05-04-2021] Issue #191 is going to be harder to implement if we use the regular code for parsing
    // wxFormBuilder files since they use hex digits and spaces. It should be safe to assume that if no array size was
    // specified, then it's a wxFormBuilder file and we should process it differently.

    do
    {
        if (ttlib::is_digit(*buf_ptr))
        {
            // TODO: [KeyWorks - 05-04-2021] The needs a complete rewrite -- see issue #191
            ptr_out_buf[actual_size] = static_cast<unsigned char>(ttlib::atoi(buf_ptr));

            if (++actual_size > image_buffer_size)
            {
                FAIL_MSG(ttlib::cstr() << filename << " actual image size is larger that the size specified in brackets");
                return image;
            }

            // Step over any hex digit
            if (buf_ptr[0] == '0' && (buf_ptr[1] == 'x' || buf_ptr[1] == 'X'))
                buf_ptr += 2;

            // Now step over the digit, then fall through and step over the first character following the digit
            do
            {
                ++buf_ptr;
            } while (ttlib::is_digit(*buf_ptr));

            if (!*buf_ptr)
                break;  // This will be a corrupted file since it didn't end with a closing '}' character
        }
        ++buf_ptr;
    } while (*buf_ptr);

    wxMemoryInputStream stream(image_buffer.get(), actual_size);

    wxImageHandler* handler;
    auto& list = wxImage::GetHandlers();
    for (auto node = list.GetFirst(); node; node = node->GetNext())
    {
        handler = (wxImageHandler*) node->GetData();
        if (handler->CanRead(stream))
        {
            if (handler->LoadFile(&image, stream))
            {
                if (p_original_size)
                    *p_original_size = actual_size;
                if (p_mime_type)
                    *p_mime_type = handler->GetMimeType();

                return image;
            }
        }
    }

    return image;
}
