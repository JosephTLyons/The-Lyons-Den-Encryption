//
//  XOR.cpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/2/17.
//
//

#include "XOR.hpp"

void XOR::clearStrings()
{
    inputTextString.clear();
    outputTextString.clear();
}

void XOR::getTextFromTextEditorsAndFillStrings(const String &key, const String &input)
{
    keyString       = key;
    inputTextString = input;
}



