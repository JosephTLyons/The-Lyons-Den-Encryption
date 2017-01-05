//
//  EncryptionStrings.cpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/3/17.
//
//

#include "EncryptionStrings.hpp"

void EncryptionStrings::setKey(const String &input)
{
    keyString.clear();
    keyString = input;
}

void EncryptionStrings::setInput(const String &input)
{
    inputTextString.clear();
    inputTextString = input;
}

void EncryptionStrings::setOutput(const String &input)
{
    outputTextString.clear();
    outputTextString = input;
}

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
    return keyString;
}

int EncryptionStrings::getInputStringLength()
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

