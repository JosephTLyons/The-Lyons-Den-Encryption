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

void encryptDecryptMessage(const String &userKey, const String &inputText,
                           String &outputText, const bool &encryptionMode);

void convertKeyToNumber(int &keyNum, const String &key);
void cycleThroughRandomNumbers(const int &keyNum);
void fillKey(char keyBeingFilled[]);

char encryptMessage(const String &keyForEncrypting, const char &input);
char decryptMessage(const String &KeyForDecrypting, const char &input);

const int ASCII_RANGE_SIZE_94 = 94;   //Range from ASCII value 32 to 126 = 94
const int SHIFT_SET_32        = 32;   //Move range up 32 values form (0-93) to (32 to 126)


#endif /* JTL_Encryption_hpp */
