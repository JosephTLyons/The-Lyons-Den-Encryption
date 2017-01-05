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
 tool tips
 toggle option for secret input of message?
 option to generate random key for the user (use a 4th key to do this)
 -add copy and paste button for key
 -rename original copy and paste to output copy, input paste
 
 */

// main entry point for encryption of a JUCE string
void ThreeKeys::encryptDecryptMessage(bool encryptionEnabled)
{
    int  keyNumber = convertKeyToNumber();
    char inputCharacter1, inputCharacter2, inputCharacter3;
    
    // Seed number for my random number generator
    srand(keyNumber);
    
    clearAndResizeKeys();

    fillCaesarKeys(keyNumber);

    // encrypt mode selected
    if (encryptionEnabled == true)
    {
        for (int i = 0; i < getInputStringLength(); i++)
        {
            // triple encrypt one character at a time
            inputCharacter1 = getSpecifiedInputStringChar(i);
            inputCharacter2 = encryptLetter(inputCharacter1, caesarKey1);
            inputCharacter3 = encryptLetter(inputCharacter2, caesarKey2);
            
            // store that character
            addToOutputString(encryptLetter(inputCharacter3, caesarKey3));
        }
    }

    // decrypt mode selected
    else
    {
        for (int i = 0; i < getInputStringLength(); i++)
        {
            // triple encrypt one character at a time
            inputCharacter1 = getSpecifiedInputStringChar(i);
            inputCharacter2 = decryptLetter(inputCharacter1, caesarKey3);
            inputCharacter3 = decryptLetter(inputCharacter2, caesarKey2);
            
            // store that character
            addToOutputString(decryptLetter(inputCharacter3, caesarKey1));
        }
    }
}

int ThreeKeys::convertKeyToNumber()
{
    int keyNumber = 0;

    for (int i = 0; i < getKeyStringLength(); i++)
    {
        keyNumber += (int) getSpecifiedKeyStringChar(i);
        keyNumber += i;
    }

    return keyNumber;
}

void ThreeKeys::clearAndResizeKeys()
{
    caesarKey1.clear();
    caesarKey2.clear();
    caesarKey3.clear();
    
    caesarKey1.resize(ASCII_RANGE_SIZE_94);
    caesarKey2.resize(ASCII_RANGE_SIZE_94);
    caesarKey3.resize(ASCII_RANGE_SIZE_94);
}

void ThreeKeys::fillCaesarKeys(const int &keyNumber)
{
    // CYCLE THROUGH THE RANDOM NUMBERS WITH PASSWORDNUMBER TO ARRIVE AT A TRULY RANDOM
    // NUMBER AND FILL THREE KEYS, EACH WITH THEIR OWN UNIQUE SET OF NUMBERS
    
    cycleThroughRandomNumbers(keyNumber);
    fillCaesarKey(caesarKey1);
    cycleThroughRandomNumbers(keyNumber);
    fillCaesarKey(caesarKey2);
    cycleThroughRandomNumbers(keyNumber);
    fillCaesarKey(caesarKey3);
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
void ThreeKeys::fillCaesarKey(vector<char> &caesarKeyBeingFilled)
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
            if (caesarKeyBeingFilled[j] == RandomNumber)
            {
                // limits numbers to 0-93, then shifts up to 32-126 ASCII range
                RandomNumber = SHIFT_SET_32 + rand() % ASCII_RANGE_SIZE_94;
                
                // reset counter of outer loop to check all the spots again
                j = -1;
            }
        }
        
        caesarKeyBeingFilled[KeySpot] = (char) RandomNumber;
    }
}

char ThreeKeys::encryptLetter(const char &input, vector<char> &currentCaesarKey)
{
    //-32 to get range back into 1-95 (range of Key)
    return currentCaesarKey[((int) input) - SHIFT_SET_32];
}

char ThreeKeys::decryptLetter(const char &input, vector<char> &currentCaesarKey)
{
    for (int Count = 0; Count < ASCII_RANGE_SIZE_94; ++Count)
    {
        if ((int) input == currentCaesarKey[Count])
        {
            //+32 to get back into 32-126 ASCII range
            return (char) Count+SHIFT_SET_32;
        }
    }
    
    return 0;
}
