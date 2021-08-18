/////////////////////////////////////////////////////////////////////////////
// Purpose:   Utility functions that work with properties
// Author:    Ralph Walden
// Copyright: Copyright (c) 2020 KeyWorks Software (Ralph Walden)
// License:   Apache License -- see ../../LICENSE
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/settings.h>

#include "ttcstr.h"  // ttlib::cstr -- std::string with additional methods

class wxColour;
class wxImage;
class wxPoint;
class wxSize;
class Node;

// Used to index fields in a bitmap property
enum PropIndex
{
    IndexType = 0,
    IndexImage,
    IndexArtID = IndexImage,
    IndexScale
};

ttlib::cstr ClearPropFlag(ttlib::cview flag, ttlib::cview currentValue);
ttlib::cstr ClearMultiplePropFlags(ttlib::cview flags, ttlib::cview currentValue);
ttlib::cstr SetPropFlag(ttlib::cview flag, ttlib::cview currentValue);

// Convert a double to a string without needing to switch locales
ttlib::cstr DoubleToStr(double val);

bool isPropFlagSet(ttlib::cview flag, ttlib::cview currentValue);

wxPoint ConvertToPoint(ttlib::cview value);
wxSize ConvertToSize(ttlib::cview value);
wxSystemColour ConvertToSystemColour(ttlib::cview value);
int ConvertBitlistToInt(ttlib::cview list);

ttlib::cstr ConvertPointToString(const wxPoint& point);
ttlib::cstr ConvertSizeToString(const wxSize& size);
ttlib::cstr ConvertColourToString(const wxColour& colour);
ttlib::cstr ConvertSystemColourToString(long colour);
const char* ConvertFontFamilyToString(wxFontFamily family);

// Used to add escapes to a string that will be handed off to a wxWidgets property editor
ttlib::cstr CreateEscapedText(ttlib::cview str);

// if value begins with 'wx' then it is assumed to be a wxSystemColour
wxColour ConvertToColour(ttlib::cview value);

// Replace escape slashes with the actual character. Affects \\, \\n, \\r, and \\t
ttlib::cstr ConvertEscapeSlashes(ttlib::cview str);

std::vector<ttlib::cstr> ConvertToArrayString(ttlib::cview value);

// Use ConvertToArrayString() to get a vector, this function to get a wxArrayString
wxArrayString ConvertToWxArrayString(ttlib::cview value);

// Converts a GZIP unsigned char array into an image.
wxImage LoadGzipImage(const unsigned char* data, size_t size_data);

// Converts an unsigned char array into an image. This is typically used for loading internal
// #included images
wxImage LoadHeaderImage(const unsigned char* data, size_t size_data);

// Converts a GZIP unsigned char array into a string.
std::string LoadGzipString(const unsigned char* data, size_t size_data);
