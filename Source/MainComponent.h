/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_9002020A4DD09B20__
#define __JUCE_HEADER_9002020A4DD09B20__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "ThreeKeys.hpp"
#include "XOR.hpp"
#include "Reverse String.hpp"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public Component,
                       public ButtonListener,
                       public ComboBoxListener
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void enterThreeKeys();
    void enterXOR();
    void enterReverseAll();
    void enterReverseWord();

    void fillHistoryString();
    void printHistoryString();

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    ThreeKeys threeKeysObject;
    XOR       xorObject;
    ReverseString reverseStringObject;
    String historyOfEncryption;

    // simply added to engage tool tips
    TooltipWindow toolTips;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextEditor> inputTextEditor;
    ScopedPointer<TextEditor> outputTextEditor;
    ScopedPointer<TextEditor> keyTextEditor;
    ScopedPointer<TextButton> encryptDecryptText;
    ScopedPointer<TextButton> clearText;
    ScopedPointer<TextButton> swapText;
    ScopedPointer<ToggleButton> decryptionModeToggle;
    ScopedPointer<ToggleButton> encryptionModeToggle;
    ScopedPointer<TextButton> copyToClipboard;
    ScopedPointer<TextButton> pasteToInput;
    ScopedPointer<ComboBox> encryptionType;
    ScopedPointer<Label> productNameLabel;
    ScopedPointer<TextEditor> historyTextEditor;
    ScopedPointer<Label> historyLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9002020A4DD09B20__
