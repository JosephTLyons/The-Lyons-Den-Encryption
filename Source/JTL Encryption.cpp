//
//  JTL Encryption.cpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 12/30/16.
//
//

#include "JTL Encryption.hpp"

/*
 
 --------------------- BUGS AND FIXES ------------------------------

 use of const / & on parameters that apply
 different types of encryption with drop down list
 
 --------------------- NEW FEATURES --------------------------------
 
 change JTL encryption into a class and clean up code heavily
 if neigther option is selected, output "please select a mode"
 have text disappear when clicking the mouse on it
 tool tips
 option for secret input of message?
 
 */

// main entry point for encryption of a JUCE string
void encryptDecryptMessage(const String &userKey, const String &inputText,
                           String &outputText, const bool &encryptionMode)
{
    int  keyNumber = 1;
    
    //One larger 0 - 93, not using 0
    char key1[ASCII_RANGE_SIZE_94] = {0};
    char key2[ASCII_RANGE_SIZE_94] = {0};
    char key3[ASCII_RANGE_SIZE_94] = {0};
    
    char InputCharacter1, InputCharacter2, InputCharacter3;
    
    // Turn key into a number
    convertKeyToNumber(keyNumber, userKey);
    
    // Seed number for my random number generator
    srand(keyNumber);
    
    // CYCLE THROUGH THE RANDOM NUMBERS WITH PASSWORDNUMBER TO ARRIVE AT A TRULY RANDOM
    // NUMBER AND FILL THREE KEYS, EACH WITH THEIR OWN UNIQUE SET OF NUMBERS
    cycleThroughRandomNumbers(keyNumber);
    fillKey(key1);
    cycleThroughRandomNumbers(keyNumber);
    fillKey(key2);
    cycleThroughRandomNumbers(keyNumber);
    fillKey(key3);
    
    // encrypt messages
    if (encryptionMode == true)
    {
        for (int i = 0; i < inputText.length(); i++)
        {
            InputCharacter1 = inputText[i];
            
            InputCharacter2 = encryptMessage(key1, InputCharacter1);
            InputCharacter3 = encryptMessage(key2, InputCharacter2);
            
            outputText += encryptMessage(key3, InputCharacter3);
        }
    }

    // decrypt messages
    else
    {
        for (int i = 0; i < inputText.length(); i++)
        {
            InputCharacter1 = inputText[i];
            
            InputCharacter2 = decryptMessage(key3, InputCharacter1);
            InputCharacter3 = decryptMessage(key2, InputCharacter2);
            
            outputText += decryptMessage(key1, InputCharacter3);
        }
    }
}

void convertKeyToNumber(int &keyNum, const String &key)
{
    for (int i = 0; i < key.length(); i++)
    {
        keyNum += (int) key[i];
        keyNum += i;
    }
}

// Cycles through random numbers randomly to help arrive at a truly random number
void cycleThroughRandomNumbers(const int &keyNum)
{
    int LoopLimit = rand() / keyNum;
    
    for (int i = 0; i <= LoopLimit; ++i)
    {
        rand();
    }
}

// Fills the key array with random characters
void fillKey(char keyBeingFilled[])
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

char encryptMessage(const String &keyForEncrypting, const char &input)
{
    //-32 to get range back into 1-95 (range of Key)
    return keyForEncrypting[((int) input) - SHIFT_SET_32];
}

char decryptMessage(const String &KeyForDecrypting, const char &input)
{
    for (int Count = 0; Count < ASCII_RANGE_SIZE_94; ++Count)
    {
        if ((int) input == KeyForDecrypting[Count])
        {
            //+32 to get back into 32-126 ASCII range
            return (char) Count+SHIFT_SET_32;
        }
    }
    
    return 0;
}
