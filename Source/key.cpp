//
//  key.cpp
//  JTL Text Encryption 2.0
//
//  Created by Joseph Lyons on 10/6/16.
//  Copyright © 2016 Joseph Lyons. All rights reserved.
//

#include "key.hpp"

#include <iostream>
using namespace std;


// Resizes the key to be the same size, or bigger, than the input string
// This is done so that at any given index, the input element has a corresponding
// key element
void resizeKey(String &key, const String &input)
{
    String duplicateOfInput = key;
    
    // As long as key is smaller than input, add the same string
    // In key to key
    for (; key.length() < input.length();)
    {
        key += duplicateOfInput;
    }
}
