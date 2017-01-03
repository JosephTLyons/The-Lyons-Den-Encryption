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
#include "EncryptionStrings.hpp"

#include <vector>

using namespace std;

class ThreeKeys : public EncryptionStrings
{
    
private:
    
    const int ASCII_RANGE_SIZE_94 = 94; //Range from ASCII value 32 to 126 = 94
    const int SHIFT_SET_32        = 32; //Move range up 32 values form (0-93) to (32 to 126)
    vector<char> caesarKey1;
    vector<char> caesarKey2;
    vector<char> caesarKey3;
    
    int convertKeyToNumber();
    void clearAndResizeKeys();
    void fillCaesarKeys(const int &keyNumber);
    void cycleThroughRandomNumbers(const int &keyNumber);
    void fillCaesarKey(vector<char> &caesarKeyBeingFilled);
    
    char encryptLetter(const char &input, vector<char> &currentCaesarKey);
    char decryptLetter(const char &input, vector<char> &currentCaesarKey);
    
public:
    
    void encryptDecryptMessage(bool encryptionEnabled);
};

#endif /* JTL_Encryption_hpp */
