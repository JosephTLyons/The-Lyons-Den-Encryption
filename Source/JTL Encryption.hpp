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

void encryptDecryptMessage(String userKey, String inputText,
                           String &outputText, bool encryptionMode);

void wordToNumberConverter(int &keyNum, String &key);
void runThroughRandomNumbers(int keyNum);
void fillKey(char keyBeingFilled[]);

char encryptMessage(String keyForEncrypting, char input);
char decryptMessage(String KeyForDecrypting, char input);

const int ASCII_RANGE_SIZE_94 = 94;   //Range from ASCII value 32 to 126 = 94
const int SHIFT_SET_32        = 32;   //Move range up 32 values form (0-93) to (32 to 126)


#endif /* JTL_Encryption_hpp */
