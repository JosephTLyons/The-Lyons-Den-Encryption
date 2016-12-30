//
//  Encryption.hpp
//  JTL Text Encryption 2.0
//
//  Created by Joseph Lyons on 10/6/16.
//  Copyright © 2016 Joseph Lyons. All rights reserved.
//

#ifndef Encryption_hpp
#define Encryption_hpp

#include <string>

using namespace std;

// Encrypts and decrypts text using a simple exclusive OR technique
void encryptDecrypt(const string &key, const string &inputText, string &encryptedText);

#endif /* Encryption_hpp */
