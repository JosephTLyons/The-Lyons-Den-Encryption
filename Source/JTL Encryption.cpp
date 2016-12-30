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
 
 add line comments
 split large dual purpose function into two smaller one purpose functions
 
 clean up rest of code nicely
 use of const / & on parameters that apply
 
 --------------------- NEW FEATURES --------------------------------
 
 automatically copy the encrypted/decoded message into mac clipboard
 
 */

void EncryptDecryptMessage(String key, String inputText, String OutputText)
{
    int  keyNumber = 1;
    
    char Key1[ASCII_RANGE_SIZE_94] = {0};//One larger 0 - 93, not using 0
    char Key2[ASCII_RANGE_SIZE_94] = {0};
    char Key3[ASCII_RANGE_SIZE_94] = {0};
    
    // Turn key into a number
    WordToNumberConverter(keyNumber, key);
    
    // Seed number for my random number generator
    srand(keyNumber);
    
    // CYCLE THROUGH THE RANDOM NUMBERS WITH PASSWORDNUMBER TO ARRIVE AT A TRULY RANDOM
    // NUMBER AND FILL THREE KEYS, EACH WITH THEIR OWN UNIQUE SET OF NUMBERS
    RunThroughRandomNumbers(keyNumber);
    
    FillKey(Key1);
    
    RunThroughRandomNumbers(keyNumber);
    
    FillKey(Key2);
    
    RunThroughRandomNumbers(keyNumber);
    
    FillKey(Key3);
    
    
}

void WordToNumberConverter(int &keyNum, String &key)
{
    for (int i = 0; key[i] != '\n'; i++)
    {
        keyNum += (int) key[i];
        keyNum += i;
    }
}

void RunThroughRandomNumbers(int keyNum)
{
    /* CYCLES THROUGH RANDOM NUMBERS RANDOMLY */
    
    int LoopLimit = rand() / keyNum;
    
    for (int i = 0; i <= LoopLimit; ++i)
    {
        rand();
    }
}

void FillKey(char KeyBeingFilled[])
{
    int RandomNumber;
    int KeySpot, j;
    
    for (KeySpot = 0; KeySpot < ASCII_RANGE_SIZE_94; ++KeySpot)
    {
        RandomNumber = SHIFT_SET_32 + rand() % ASCII_RANGE_SIZE_94;//0-93, then shifts up to 32-126 ASCII range
        
        for (j = 0; j <= KeySpot; ++j)//this bit of code checks to make sure new rand number isn't already used before
        {
            if (KeyBeingFilled[j] == RandomNumber)
            {
                RandomNumber = SHIFT_SET_32 + rand() % ASCII_RANGE_SIZE_94;//0-93, then shifts up to 32-126
                j = -1;
            }
        }
        
        KeyBeingFilled[KeySpot] = (char) RandomNumber;
    }
}

char EncryptMessage(char KeyForEncrypting[], char Input)
{
    return KeyForEncrypting[((int) Input) - SHIFT_SET_32];//-32 to get range back into 1-95 (range of Key)
}

char DecryptMessage(char KeyForDecrypting[], char Input)
{
    for (int Count = 0; Count < ASCII_RANGE_SIZE_94; ++Count)
    {
        if ((int) Input == KeyForDecrypting[Count])
        {
            return (char) Count+SHIFT_SET_32;//+32 to get back into 32-126 ASCII range
        }
    }
    
    return 0;
}
