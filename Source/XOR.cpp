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
    String tempHolder;
    
    for(int i = 0; i < getInputStringLength(); i++)
    {
        tempHolder += getSpecifiedKeyStringChar(i) ^ getSpecifiedInputStringChar(i);
    }
    
    setInput(tempHolder);
}

void XOR::convertStringToHex()
{
    String tempHolder;
    
    for(int i = 0; i < getInputStringLength(); i++)
    {
        tempHolder += (int) getSpecifiedInputStringChar(i);
    }
    
    setOutput(tempHolder);
}

//void XOR::convertHexToString()
//{
//    setOutput(getInputString().toHexString(10));
//}
