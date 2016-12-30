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
#include "../JuceLibraryCode/JuceHeader.h"


// Resizes the key to be the same size, or bigger, than the input string
// This is done so that at any given index, the input element has a corresponding
// key element
void resizeKey(String &key, const String &input);

#endif /* Key_hpp */
