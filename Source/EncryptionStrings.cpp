//
//  EncryptionStrings.cpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/3/17.
//
//

#include "EncryptionStrings.hpp"

void EncryptionStrings::clearStrings()
{
    inputTextString.clear();
    outputTextString.clear();
}

void EncryptionStrings::getTextFromTextEditorsAndFillStrings(const String &key, const String &input)
{
    keyString       = key;
    inputTextString = input;
}

String EncryptionStrings::getInputString()
{
    return inputTextString;
}

String EncryptionStrings::getOutputString()
{
    return outputTextString;
}

String EncryptionStrings::getKeyString()
{
    return outputTextString;
}

int EncryptionStrings::getInputStringLenght()
{
    return inputTextString.length();
}

int EncryptionStrings::getOutputStringLenght()
{
    return outputTextString.length();
}

int EncryptionStrings::getKeyStringLength()
{
    return keyString.length();
}

void EncryptionStrings::addToOutputString(const char &input)
{
    outputTextString += input;
}

char EncryptionStrings::getSpecifiedInputStringChar(const int &requestedNumber)
{
    return inputTextString[requestedNumber];
}

char EncryptionStrings::getSpecifiedKeyStringChar(const int &requestedNumber)
{
    return keyString[requestedNumber];
}

