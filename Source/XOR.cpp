//
//  XOR.cpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/2/17.
//
//

#include "XOR.hpp"

void XOR::resizeKey()
{
    String temp = getKeyString();
    
    while (temp.length() < getInputStringLength())
    {
        temp += getKeyString();
    }
    
    setKey(temp);
}

void XOR::bitwiseEncryption()
{
    for(int i = 0; i < getInputStringLength(); i++)
    {
        addToOutputString(getSpecifiedKeyStringChar(i) ^ getSpecifiedInputStringChar(i));
    }
}
