//
//  EncryptionStrings.hpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/3/17.
//
//

#ifndef EncryptionStrings_hpp
#define EncryptionStrings_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class EncryptionStrings
{
private:
    
    String keyString;
    String inputTextString;
    String outputTextString;
    
public:
    
    void setKey(const String &input);
    
    void clearStrings();
    void getTextFromTextEditorsAndFillStrings(const String &key, const String &input);
    
    String getInputString();
    String getOutputString();
    String getKeyString();
    
    int getInputStringLength();
    int getOutputStringLenght();
    int getKeyStringLength();
    
    void addToOutputString(const char &input);
    
    char getSpecifiedInputStringChar(const int &requestedNumber);
    char getSpecifiedKeyStringChar(const int &requestedNumber);
};

#endif /* EncryptionStrings_hpp */
