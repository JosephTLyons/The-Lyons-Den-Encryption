//
//  key.cpp
//  JTL Text Encryption 2.0
//
//  Created by Joseph Lyons on 10/6/16.
//  Copyright © 2016 Joseph Lyons. All rights reserved.
//

#include <iostream>
using namespace std;

// Takes input from the user and stores it in the incoming text of type string
void stringInput(string &text)
{
    char letter = '\0';
    
    // Get input from user and store in string
    for (int i = 0; letter != '\n'; i++)
    {
        letter = cin.get();
        text.push_back(letter);
    }
    
    // Remove newline leftover in key
    text.pop_back();
}

// Resizes the key to be the same size, or bigger, than the input string
// This is done so that at any given index, the input element has a corresponding
// key element
void resizeKey(string &key, const string &input)
{
    string duplicateOfInput = key;
    
    // As long as key is smaller than input, add the same string
    // In key to key
    for (; key.length() < input.length();)
    {
        key += duplicateOfInput;
    }
}
