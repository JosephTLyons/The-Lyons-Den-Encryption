//
//  XOR.hpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/2/17.
//
//

#ifndef XOR_hpp
#define XOR_hpp

#include "../JuceLibraryCode/JuceHeader.h"
#include "EncryptionStrings.hpp"

class XOR : public EncryptionStrings
{

public:
    
    void resizeKey();
    void bitwiseEncryption();
    void convertStringToHex();

};

#endif /* XOR_hpp */
