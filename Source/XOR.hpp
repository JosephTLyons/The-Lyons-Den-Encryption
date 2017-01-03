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
    
    void makeUpperCase();
    void resizeKey();
    void bitwiseEncryption();


};

#endif /* XOR_hpp */
