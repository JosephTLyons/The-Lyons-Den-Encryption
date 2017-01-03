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

#include <vector>

using namespace std;

class ThreeKeys
{
    
private:
    
    const int ASCII_RANGE_SIZE_94 = 94; //Range from ASCII value 32 to 126 = 94
    const int SHIFT_SET_32        = 32; //Move range up 32 values form (0-93) to (32 to 126)
    String keyString;
    String inputTextString;
    String outputTextString;
    vector<char> key1;
    vector<char> key2;
    vector<char> key3;
    
    void convertKeyToNumber(int &keyNumber);
    void clearAndResizeKeys();
    void fillKeys(const int &keyNumber);
    void cycleThroughRandomNumbers(const int &keyNumber);
    void fillKey(vector<char> &keyBeingFilled);
    
    char encryptLetter(const char &input, vector<char> &currentKey);
    char decryptLetter(const char &input, vector<char> &currentKey);
    
public:
    
    void clearStrings();
    void getTextFromTextEditorsAndFillStrings(const String &key, const String &input);
    void encryptDecryptMessage(bool encryptionMode);
    String getOutputString();
};

#endif /* JTL_Encryption_hpp */
