//
//  Reverse String.cpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/5/17.
//
//

#include "Reverse String.hpp"
#include <ctype.h>

void ReverseString::reverseEntireString()
{
    String tempHolder;
    
    for (int i = getInputStringLength(); i >= 0; i--)
    {
        tempHolder += getSpecifiedInputStringChar(i);
    }
    
    setOutput(tempHolder);
}

void ReverseString::reverseWord()
{
    String tempWordHolder;
    String tempWordReversedHolder;
    String tempStringHolder;
    
    // cycle through input string
    for(int i = 0; i < getInputStringLength(); i++)
    {
        // grab one word at a time as long as its not a white space character
        if(!isspace(getSpecifiedInputStringChar(i)))
        {
            tempWordHolder += getSpecifiedInputStringChar(i);
        }
        
        // if white space character or very last iteration of for - loop
        if (isspace(getSpecifiedInputStringChar(i)) || i == getInputStringLength() - 1)
        {
            // reverse one word
            for (int j = tempWordHolder.length(); j >= 0; j--)
            {
                tempWordReversedHolder += tempWordHolder[j];
            }
            
            // add reversed word to new string and add a space
            tempStringHolder += tempWordReversedHolder;
            tempStringHolder += ' ';
            
            // clear other temp holders
            tempWordHolder.clear();
            tempWordReversedHolder.clear();
        }
    }
    
    // remove final space that is added above and set this to inputTextString
    setOutput(tempStringHolder.dropLastCharacters(1));
}

