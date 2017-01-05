//
//  Reverse String.cpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/5/17.
//
//

#include "Reverse String.hpp"

void ReverseString::reverseEntireString()
{
    String tempHolder;
    
    for (int i = getInputStringLength(); i >= 0; i--)
    {
        tempHolder += getSpecifiedInputStringChar(i);
    }
    
    setOutput(tempHolder);
}
