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

//[Headers]

#include "key.hpp"

//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (inputText = new TextEditor ("inputText"));
    inputText->setMultiLine (true);
    inputText->setReturnKeyStartsNewLine (false);
    inputText->setReadOnly (false);
    inputText->setScrollbarsShown (true);
    inputText->setCaretVisible (true);
    inputText->setPopupMenuEnabled (true);
    inputText->setText (TRANS("Input Text Here"));

    addAndMakeVisible (outputEncryptedText = new TextEditor ("new text editor"));
    outputEncryptedText->setMultiLine (true);
    outputEncryptedText->setReturnKeyStartsNewLine (false);
    outputEncryptedText->setReadOnly (false);
    outputEncryptedText->setScrollbarsShown (true);
    outputEncryptedText->setCaretVisible (true);
    outputEncryptedText->setPopupMenuEnabled (true);
    outputEncryptedText->setText (TRANS("Encrypted Text Ouputs Here"));

    addAndMakeVisible (keyText = new TextEditor ("keyText"));
    keyText->setMultiLine (true);
    keyText->setReturnKeyStartsNewLine (false);
    keyText->setReadOnly (false);
    keyText->setScrollbarsShown (true);
    keyText->setCaretVisible (true);
    keyText->setPopupMenuEnabled (true);
    keyText->setText (TRANS("Input Key Here"));

    addAndMakeVisible (encryptDecryptText = new TextButton ("new button"));
    encryptDecryptText->setButtonText (TRANS("Encrypt / Decrypt Text"));
    encryptDecryptText->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    encryptDecryptText->addListener (this);

    addAndMakeVisible (clearText = new TextButton ("new button"));
    clearText->setButtonText (TRANS("Clear Text"));
    clearText->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    clearText->addListener (this);

    addAndMakeVisible (swapText = new TextButton ("new button"));
    swapText->setButtonText (TRANS("Swap Text"));
    swapText->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    swapText->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 350);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    inputText = nullptr;
    outputEncryptedText = nullptr;
    keyText = nullptr;
    encryptDecryptText = nullptr;
    clearText = nullptr;
    swapText = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    inputText->setBounds (8, 56, 336, 136);
    outputEncryptedText->setBounds (8, 200, 336, 136);
    keyText->setBounds (8, 8, 336, 40);
    encryptDecryptText->setBounds (348, 56, 147, 135);
    clearText->setBounds (348, 200, 147, 135);
    swapText->setBounds (348, 6, 147, 42);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

    String tempHolderForSwap;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == encryptDecryptText)
    {
        //[UserButtonCode_encryptDecryptText]
        
        keyString       = keyText->getText();
        inputTextString = inputText->getText();
        
        
        
        //[/UserButtonCode_encryptDecryptText]
    }
    else if (buttonThatWasClicked == clearText)
    {
        //[UserButtonCode_clearText] -- add your button handler code here..

        // clear all text fields
        keyText->clear();
        inputText->clear();
        outputEncryptedText->clear();

        // reset text
//        keyText->setText("Input Key Here");
//        inputText->setText("Input Text Here");
//        outputEncryptedText->setText("Encrypted Text Ouputs Here");

        //[/UserButtonCode_clearText]
    }
    else if (buttonThatWasClicked == swapText)
    {
        //[UserButtonCode_swapText] -- add your button handler code here..

        // swap fields
        tempHolderForSwap = inputText->getText();

        inputText->setText(outputEncryptedText->getText());
        outputEncryptedText->setText(tempHolderForSwap);

        //[/UserButtonCode_swapText]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode]
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="3" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="500" initialHeight="350">
  <BACKGROUND backgroundColour="ff000000"/>
  <TEXTEDITOR name="inputText" id="cd5cf2088e4b8391" memberName="inputText"
              virtualName="" explicitFocusOrder="0" pos="8 56 336 136" initialText="Input Text Here"
              multiline="1" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="20825e2d4e657e11" memberName="outputEncryptedText"
              virtualName="" explicitFocusOrder="0" pos="8 200 336 136" initialText="Encrypted Text Ouputs Here"
              multiline="1" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="keyText" id="b5d11893eb6accf3" memberName="keyText" virtualName=""
              explicitFocusOrder="0" pos="8 8 336 40" initialText="Input Key Here"
              multiline="1" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="3bbb40b8fcf75027" memberName="encryptDecryptText"
              virtualName="" explicitFocusOrder="0" pos="348 56 147 135" buttonText="Encrypt / Decrypt Text"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="c83123a33c17aff6" memberName="clearText"
              virtualName="" explicitFocusOrder="0" pos="348 200 147 135" buttonText="Clear Text"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="3966e441c06b33be" memberName="swapText"
              virtualName="" explicitFocusOrder="0" pos="348 6 147 42" buttonText="Swap Text"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
