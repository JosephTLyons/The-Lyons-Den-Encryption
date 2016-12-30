//
//  Key.hpp
//  JTL Text Encryption 2.0
//
//  Created by Joseph Lyons on 10/6/16.
//  Copyright © 2016 Joseph Lyons. All rights reserved.
//

#ifndef Key_hpp
#define Key_hpp

#include <iostream>
#include <string>

// Takes input from the user and stores it in the incoming text of type string
void stringInput(string &key);

// Resizes the key to be the same size, or bigger, than the input string
// This is done so that at any given index, the input element has a corresponding
// key element
void resizeKey(string &key, const string &input);

#endif /* Key_hpp */
