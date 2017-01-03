//
//  XOR.hpp
//  JTL Encryption GUI
//
//  Created by Joseph Lyons on 1/2/17.
//
//

#ifndef XOR_hpp
#define XOR_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class XOR
{
    
private:
    
    String keyString;
    String inputTextString;
    String outputTextString;
    
public:
    
    void clearStrings();
    void getTextFromTextEditorsAndFillStrings(const String &key, const String &input);


};

#endif /* XOR_hpp */
