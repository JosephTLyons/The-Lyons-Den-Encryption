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
 
 clean up rest of code nicely
 use of const / & on parameters that apply
 
 --------------------- NEW FEATURES --------------------------------
 
 automatically copy the encrypted/decoded message into mac clipboard
 
 */

void encryptDecryptMessage(String userKey, String inputText, String outputText)
{
    int  keyNumber = 1;
    
    char Key1[ASCII_RANGE_SIZE_94] = {0};//One larger 0 - 93, not using 0
    char Key2[ASCII_RANGE_SIZE_94] = {0};
    char Key3[ASCII_RANGE_SIZE_94] = {0};
    
    char InputCharacter1, InputCharacter2, InputCharacter3;
    
    // Turn key into a number
    wordToNumberConverter(keyNumber, userKey);
    
    // Seed number for my random number generator
    srand(keyNumber);
    
    // CYCLE THROUGH THE RANDOM NUMBERS WITH PASSWORDNUMBER TO ARRIVE AT A TRULY RANDOM
    // NUMBER AND FILL THREE KEYS, EACH WITH THEIR OWN UNIQUE SET OF NUMBERS
    runThroughRandomNumbers(keyNumber);
    
    fillKey(Key1);
    
    runThroughRandomNumbers(keyNumber);
    
    fillKey(Key2);
    
    runThroughRandomNumbers(keyNumber);
    
    fillKey(Key3);
    
    // encrypt messages
    for (int i = 0; i < inputText.length(); i++)
    {
        InputCharacter1 = encryptMessage(userKey, inputText[i]);
        InputCharacter2 = encryptMessage(Key1, InputCharacter1);
        InputCharacter3 = encryptMessage(Key2, InputCharacter2);
        
        outputText += encryptMessage(Key3, InputCharacter3);
    }

    // decrypt messages
    for (int i = 0; i < inputText.length(); i++)
    {
        InputCharacter1 = decryptMessage(userKey, inputText[i]);
        InputCharacter2 = decryptMessage(Key1, InputCharacter1);
        InputCharacter3 = encryptMessage(Key2, InputCharacter2);
        
        outputText += decryptMessage(Key3, InputCharacter3);
    }
}

void wordToNumberConverter(int &keyNum, String &key)
{
    for (int i = 0; i < key.length(); i++)
    {
        keyNum += (int) key[i];
        keyNum += i;
    }
}

void runThroughRandomNumbers(int keyNum)
{
    // Cycles through random numbers randomly
    int LoopLimit = rand() / keyNum;
    
    for (int i = 0; i <= LoopLimit; ++i)
    {
        rand();
    }
}

void fillKey(char keyBeingFilled[])
{
    int RandomNumber;
    int KeySpot, j;
    
    for (KeySpot = 0; KeySpot < ASCII_RANGE_SIZE_94; ++KeySpot)
    {
        RandomNumber = SHIFT_SET_32 + rand() % ASCII_RANGE_SIZE_94;//0-93, then shifts up to 32-126 ASCII range
        
        for (j = 0; j <= KeySpot; ++j)//this bit of code checks to make sure new rand number isn't already used before
        {
            if (keyBeingFilled[j] == RandomNumber)
            {
                RandomNumber = SHIFT_SET_32 + rand() % ASCII_RANGE_SIZE_94;//0-93, then shifts up to 32-126
                j = -1;
            }
        }
        
        keyBeingFilled[KeySpot] = (char) RandomNumber;
    }
}

char encryptMessage(String keyForEncrypting, char input)
{
    return keyForEncrypting[((int) input) - SHIFT_SET_32];//-32 to get range back into 1-95 (range of Key)
}

char decryptMessage(String KeyForDecrypting, char input)
{
    for (int Count = 0; Count < ASCII_RANGE_SIZE_94; ++Count)
    {
        if ((int) input == KeyForDecrypting[Count])
        {
            return (char) Count+SHIFT_SET_32;//+32 to get back into 32-126 ASCII range
        }
    }
    
    return 0;
}
