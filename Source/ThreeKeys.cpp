//
//  JTL Encryption.cpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 12/30/16.
//
//

#include "ThreeKeys.hpp"

/*
 
 --------------------- BUGS AND FIXES ------------------------------
 
 clean up code heavily
 --------------------- NEW FEATURES --------------------------------
 
 different types of encryption with drop down list
 tool tips
 toggle option for secret input of message?
 option to generate random key for the user (use a 4th key to do this)
 -add copy and paste button for key
 -rename original copy and paste to output copy, input paste
 
 */

void ThreeKeys::clearStrings()
{
    inputTextString.clear();
    outputTextString.clear();
}

void ThreeKeys::getTextFromTextEditorsAndFillStrings(const String &key, const String &input)
{
    keyString       = key;
    inputTextString = input;
}

// main entry point for encryption of a JUCE string
void ThreeKeys::encryptDecryptMessage(bool encryptionMode)
{
    int  keyNumber = 1;
    char inputCharacter1, inputCharacter2, inputCharacter3;
    
    convertKeyToNumber(keyNumber);
    
    // Seed number for my random number generator
    srand(keyNumber);
    
    clearAndResizeKeys();

    fillKeys(keyNumber);

    // encrypt mode selected
    if (encryptionMode == true)
    {
        for (int i = 0; i < inputTextString.length(); i++)
        {
            // triple encrypt one character at a time
            inputCharacter1 = inputTextString[i];
            inputCharacter2 = encryptLetter(inputCharacter1, key1);
            inputCharacter3 = encryptLetter(inputCharacter2, key2);
            
            // store that character
            outputTextString += encryptLetter(inputCharacter3, key3);
        }
    }

    // decrypt mode selected
    else
    {
        for (int i = 0; i < inputTextString.length(); i++)
        {
            // triple encrypt one character at a time
            inputCharacter1 = inputTextString[i];
            inputCharacter2 = decryptLetter(inputCharacter1, key3);
            inputCharacter3 = decryptLetter(inputCharacter2, key2);
            
            // store that character
            outputTextString += decryptLetter(inputCharacter3, key1);
        }
    }
}

String ThreeKeys::getOutputString()
{
    return outputTextString;
}

void ThreeKeys::convertKeyToNumber(int &keyNumber)
{
    for (int i = 0; i < keyString.length(); i++)
    {
        keyNumber += (int) keyString[i];
        keyNumber += i;
    }
}

void ThreeKeys::clearAndResizeKeys()
{
    key1.clear();
    key2.clear();
    key3.clear();
    
    key1.resize(ASCII_RANGE_SIZE_94);
    key2.resize(ASCII_RANGE_SIZE_94);
    key3.resize(ASCII_RANGE_SIZE_94);
}

void ThreeKeys::fillKeys(const int &keyNumber)
{
    // CYCLE THROUGH THE RANDOM NUMBERS WITH PASSWORDNUMBER TO ARRIVE AT A TRULY RANDOM
    // NUMBER AND FILL THREE KEYS, EACH WITH THEIR OWN UNIQUE SET OF NUMBERS
    
    cycleThroughRandomNumbers(keyNumber);
    fillKey(key1);
    cycleThroughRandomNumbers(keyNumber);
    fillKey(key2);
    cycleThroughRandomNumbers(keyNumber);
    fillKey(key3);
}

// Cycles through random numbers randomly to help arrive at a truly random number
void ThreeKeys::cycleThroughRandomNumbers(const int &keyNumber)
{
    int LoopLimit = rand() / keyNumber;
    
    for (int i = 0; i <= LoopLimit; ++i)
    {
        rand();
    }
}

// Fills the key array with random characters
void ThreeKeys::fillKey(vector<char> &keyBeingFilled)
{
    int RandomNumber;
    int KeySpot, j;
    
    for (KeySpot = 0; KeySpot < ASCII_RANGE_SIZE_94; ++KeySpot)
    {
        // limits numbers to 0-93, then shifts up to 32-126 ASCII range
        RandomNumber = SHIFT_SET_32 + rand() % ASCII_RANGE_SIZE_94;
        
        //this bit of code checks to make sure new rand number isn't already used before
        for (j = 0; j <= KeySpot; ++j)
        {
            if (keyBeingFilled[j] == RandomNumber)
            {
                // limits numbers to 0-93, then shifts up to 32-126 ASCII range
                RandomNumber = SHIFT_SET_32 + rand() % ASCII_RANGE_SIZE_94;
                
                // reset counter of outer loop to check all the spots again
                j = -1;
            }
        }
        
        keyBeingFilled[KeySpot] = (char) RandomNumber;
    }
}

char ThreeKeys::encryptLetter(const char &input, vector<char> &currentKey)
{
    //-32 to get range back into 1-95 (range of Key)
    return currentKey[((int) input) - SHIFT_SET_32];
}

char ThreeKeys::decryptLetter(const char &input, vector<char> &currentKey)
{
    for (int Count = 0; Count < ASCII_RANGE_SIZE_94; ++Count)
    {
        if ((int) input == currentKey[Count])
        {
            //+32 to get back into 32-126 ASCII range
            return (char) Count+SHIFT_SET_32;
        }
    }
    
    return 0;
}
