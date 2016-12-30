//
//  Encryption.cpp
//  JTL Text Encryption 2.0
//
//  Created by Joseph Lyons on 10/6/16.
//  Copyright © 2016 Joseph Lyons. All rights reserved.
//

#include "encryption.hpp"
#include <iostream>

using namespace std;

// Encrypts and decrypts text using a simple exclusive OR technique
void encryptDecrypt(const String &key, const String &inputText, String &encryptedText)
{
    for (int i = 0; i < inputText.length(); i++)
    {
        encryptedText += key[i] ^ inputText[i];
    }
}
