//
//  JTL Encryption.hpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 12/30/16.
//
//

#ifndef JTL_Encryption_hpp
#define JTL_Encryption_hpp

#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;

void EncryptDecryptMessage(String key, String inputText, String OutputText);

void WordToNumberConverter(int &PassNumber, String &Password);
void RunThroughRandomNumbers(int PasswordNum);
void FillKey(char KeyBeingFilled[]);

char EncryptMessage(char KeyForEncrypting[], char Input);
char DecryptMessage(char KeyForDecrypting[], char Input);

const int ASCII_RANGE_SIZE_94 = 94;   //Range from ASCII value 32 to 126 = 94
const int SHIFT_SET_32        = 32;   //Move range up 32 values form (0-93) to (32 to 126)


#endif /* JTL_Encryption_hpp */
