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

//[Headers] You can add your own extra header files here...

#include "ThreeKeys.hpp"

//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (inputTextEditor = new TextEditor ("inputTextEditor"));
    inputTextEditor->setMultiLine (true);
    inputTextEditor->setReturnKeyStartsNewLine (false);
    inputTextEditor->setReadOnly (false);
    inputTextEditor->setScrollbarsShown (true);
    inputTextEditor->setCaretVisible (true);
    inputTextEditor->setPopupMenuEnabled (true);
    inputTextEditor->setText (TRANS("Input Text Here"));

    addAndMakeVisible (outputTextEditor = new TextEditor ("outputTextEditor"));
    outputTextEditor->setMultiLine (true);
    outputTextEditor->setReturnKeyStartsNewLine (false);
    outputTextEditor->setReadOnly (false);
    outputTextEditor->setScrollbarsShown (true);
    outputTextEditor->setCaretVisible (true);
    outputTextEditor->setPopupMenuEnabled (true);
    outputTextEditor->setText (TRANS("Text Output Displayed Here"));

    addAndMakeVisible (keyTextEditor = new TextEditor ("keyText"));
    keyTextEditor->setMultiLine (true);
    keyTextEditor->setReturnKeyStartsNewLine (false);
    keyTextEditor->setReadOnly (false);
    keyTextEditor->setScrollbarsShown (true);
    keyTextEditor->setCaretVisible (true);
    keyTextEditor->setPopupMenuEnabled (true);
    keyTextEditor->setColour (TextEditor::backgroundColourId, Colours::white);
    keyTextEditor->setText (TRANS("Input Key Here"));

    addAndMakeVisible (encryptDecryptText = new TextButton ("new button"));
    encryptDecryptText->setButtonText (TRANS("Encrypt / Decrypt Text"));
    encryptDecryptText->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    encryptDecryptText->addListener (this);

    addAndMakeVisible (clearText = new TextButton ("new button"));
    clearText->setButtonText (TRANS("Clear Text"));
    clearText->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    clearText->addListener (this);

    addAndMakeVisible (swapText = new TextButton ("new button"));
    swapText->setTooltip (TRANS("Swap Text is handy for using multiple encryption types back-to-back.  It is also used for testing purposes, to reassure that the encryption is working both ways."));
    swapText->setButtonText (TRANS("Swap Text"));
    swapText->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    swapText->addListener (this);

    addAndMakeVisible (decryptionModeToggle = new ToggleButton ("decryptionModeToggle"));
    decryptionModeToggle->setButtonText (TRANS("Decrypt"));
    decryptionModeToggle->addListener (this);
    decryptionModeToggle->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (encryptionModeToggle = new ToggleButton ("encryptionModeToggle"));
    encryptionModeToggle->setButtonText (TRANS("Encrypt"));
    encryptionModeToggle->addListener (this);
    encryptionModeToggle->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (copyToClipboard = new TextButton ("copyToClipboard"));
    copyToClipboard->setButtonText (TRANS("Copy"));
    copyToClipboard->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    copyToClipboard->addListener (this);

    addAndMakeVisible (pasteToInput = new TextButton ("pasteToInput"));
    pasteToInput->setButtonText (TRANS("Paste"));
    pasteToInput->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    pasteToInput->addListener (this);

    addAndMakeVisible (encryptionType = new ComboBox ("encryptionType"));
    encryptionType->setTooltip (TRANS("3Keys - My custom encryption that\'s more of a proof of concept than a secure system.  Recommended to not use for sensitive data.\n"
    "\n"
    "XOR - Standaard xclusive or / Bitwise Encryption"));
    encryptionType->setEditableText (false);
    encryptionType->setJustificationType (Justification::centredLeft);
    encryptionType->setTextWhenNothingSelected (TRANS("Encryption Type"));
    encryptionType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    encryptionType->addItem (TRANS("3Keys"), 1);
    encryptionType->addItem (TRANS("XOR"), 2);
    encryptionType->addItem (TRANS("Reverse Word"), 3);
    encryptionType->addItem (TRANS("Reverse All"), 4);
    encryptionType->addItem (TRANS("None"), 5);
    encryptionType->addListener (this);

    addAndMakeVisible (productNameLabel = new Label ("productNameLabel",
                                                     TRANS("The Lyons\' Den Encryption")));
    productNameLabel->setFont (Font ("Britannic Bold", 58.40f, Font::plain));
    productNameLabel->setJustificationType (Justification::centredLeft);
    productNameLabel->setEditable (false, false, false);
    productNameLabel->setColour (Label::textColourId, Colours::white);
    productNameLabel->setColour (TextEditor::textColourId, Colours::black);
    productNameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (historyTextEditor = new TextEditor ("new text editor"));
    historyTextEditor->setMultiLine (false);
    historyTextEditor->setReturnKeyStartsNewLine (false);
    historyTextEditor->setReadOnly (true);
    historyTextEditor->setScrollbarsShown (true);
    historyTextEditor->setCaretVisible (false);
    historyTextEditor->setPopupMenuEnabled (true);
    historyTextEditor->setText (String());

    addAndMakeVisible (historyLabel = new Label ("historyLabel",
                                                 TRANS("History")));
    historyLabel->setFont (Font (15.00f, Font::plain));
    historyLabel->setJustificationType (Justification::centredLeft);
    historyLabel->setEditable (false, false, false);
    historyLabel->setColour (Label::textColourId, Colours::white);
    historyLabel->setColour (TextEditor::textColourId, Colours::black);
    historyLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (646, 385);


    //[Constructor] You can add your own custom stuff here..

    // highlights all text in text editors when clicked on
    // so user can easily type over the previous message
    keyTextEditor->setSelectAllWhenFocused(true);
    inputTextEditor->setSelectAllWhenFocused(true);
    outputTextEditor->setSelectAllWhenFocused(true);

    // start app with encryption mode on
    encryptionModeToggle->setToggleState(true, dontSendNotification);

    // make history editor capable of holding multiple lines
    // so each new item can print to its own line
    historyTextEditor->setMultiLine(true);

    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    inputTextEditor = nullptr;
    outputTextEditor = nullptr;
    keyTextEditor = nullptr;
    encryptDecryptText = nullptr;
    clearText = nullptr;
    swapText = nullptr;
    decryptionModeToggle = nullptr;
    encryptionModeToggle = nullptr;
    copyToClipboard = nullptr;
    pasteToInput = nullptr;
    encryptionType = nullptr;
    productNameLabel = nullptr;
    historyTextEditor = nullptr;
    historyLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff343434));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    inputTextEditor->setBounds (4, 105, 336, 136);
    outputTextEditor->setBounds (4, 245, 336, 136);
    keyTextEditor->setBounds (4, 61, 336, 40);
    encryptDecryptText->setBounds (344, 105, 147, 136);
    clearText->setBounds (344, 337, 147, 44);
    swapText->setBounds (344, 245, 147, 44);
    decryptionModeToggle->setBounds (416, 54, 75, 24);
    encryptionModeToggle->setBounds (344, 54, 75, 24);
    copyToClipboard->setBounds (344, 291, 73, 44);
    pasteToInput->setBounds (418, 291, 73, 44);
    encryptionType->setBounds (344, 77, 147, 24);
    productNameLabel->setBounds (1, -6, 646, 63);
    historyTextEditor->setBounds (495, 77, 147, 304);
    historyLabel->setBounds (496, 53, 147, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == encryptDecryptText)
    {
        //[UserButtonCode_encryptDecryptText] -- add your button handler code here..

        // make sure key has text in it (without this, the app will crash with no text in key)
        if (!keyTextEditor->isEmpty())
        {
            // set background color of keyTextEditor white as long as we aren't in
            // one of the modes that doesn't use a key - key is greyed and disabled in these modes
            if (encryptionType->getSelectedIdAsValue() != 3 &&
                encryptionType->getSelectedIdAsValue() != 4)
            {
                keyTextEditor->setColour (TextEditor::backgroundColourId, Colours::white);
            }

            // Begin threeKeys
            if(encryptionType->getSelectedIdAsValue() == 1)
            {
                enterThreeKeys();
            }

            // Begin XOR
            if(encryptionType->getSelectedIdAsValue() == 2)
            {
                //enterXOR(); - turned off until fixed
            }

            // Begin Reverse Word
            if(encryptionType->getSelectedIdAsValue() == 3)
            {
                enterReverseWord();
            }

            // Begin Reverse All
            if(encryptionType->getSelectedIdAsValue() == 4)
            {
                enterReverseAll();
            }

            // Begin none
            if(encryptionType->getSelectedIdAsValue() == 5)
            {
                // Simply route input text to output text
                outputTextEditor->setText(inputTextEditor->getText());
            }
        }

        // Send message specifying what to do, which also serves as a temp key
        else
        {
            // change color to highlight the fact the user didn't input a key
            keyTextEditor->setColour (TextEditor::backgroundColourId, Colour (0xffcd9292));
            keyTextEditor->setText("Please Enter a Key");
        }

        printHistory();

        //[/UserButtonCode_encryptDecryptText]
    }
    else if (buttonThatWasClicked == clearText)
    {
        //[UserButtonCode_clearText] -- add your button handler code here..

        // clear all text fields
        keyTextEditor->clear();
        inputTextEditor->clear();
        outputTextEditor->clear();
        historyTextEditor->clear();

        // clear string
        historyOfEncryption.clear();

        //[/UserButtonCode_clearText]
    }
    else if (buttonThatWasClicked == swapText)
    {
        //[UserButtonCode_swapText] -- add your button handler code here..

        // swap field
        inputTextEditor->setText(outputTextEditor->getText());
        outputTextEditor->clear();

        //[/UserButtonCode_swapText]
    }
    else if (buttonThatWasClicked == decryptionModeToggle)
    {
        //[UserButtonCode_decryptionModeToggle] -- add your button handler code here..

        // if decrypt mode was on at button push, turn off and flip encrypt mode on
        if(!decryptionModeToggle->getToggleState())
            encryptionModeToggle->setToggleState(true, dontSendNotification);

        // if decrypt mode is off, turn on and turn encrypt mode off
        else
            encryptionModeToggle->setToggleState(false, dontSendNotification);

        //[/UserButtonCode_decryptionModeToggle]
    }
    else if (buttonThatWasClicked == encryptionModeToggle)
    {
        //[UserButtonCode_encryptionModeToggle] -- add your button handler code here..

        // if encrypt mode was on at button push, turn off and flip decrypt mode on
        if(!encryptionModeToggle->getToggleState())
            decryptionModeToggle->setToggleState(true, dontSendNotification);

        // if encrypt mode is off, turn on and turn decrypt mode off
        else
            decryptionModeToggle->setToggleState(false, dontSendNotification);

        //[/UserButtonCode_encryptionModeToggle]
    }
    else if (buttonThatWasClicked == copyToClipboard)
    {
        //[UserButtonCode_copyToClipboard] -- add your button handler code here..

        // copy text from output to clipboard
        SystemClipboard::copyTextToClipboard(outputTextEditor->getText());

        //[/UserButtonCode_copyToClipboard]
    }
    else if (buttonThatWasClicked == pasteToInput)
    {
        //[UserButtonCode_pasteToInput] -- add your button handler code here..

        // paste text from clipboard to input
        inputTextEditor->setText(SystemClipboard::getTextFromClipboard());

        // change modes for a paste (its assumed that a paste means the user wants to decrypt
        decryptionModeToggle->setToggleState(true, dontSendNotification);
        encryptionModeToggle->setToggleState(false, dontSendNotification);

        //[/UserButtonCode_pasteToInput]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == encryptionType)
    {
        //[UserComboBoxCode_encryptionType] -- add your combo box handling code here..

        // these options don't require a key (reverse all and reverse word)
        // so turn off keyTextEditor
        if(encryptionType->getSelectedIdAsValue() == 3 ||
           encryptionType->getSelectedIdAsValue() == 4)
        {
            keyTextEditor->setEnabled(false);
            keyTextEditor->setColour(TextEditor::backgroundColourId, Colours::grey);
            keyTextEditor->setText("No Key Needed For This Mode");
        }

        else
        {
            keyTextEditor->setEnabled(true);
            keyTextEditor->setColour(TextEditor::backgroundColourId, Colours::white);
            keyTextEditor->setText(TRANS("Input Key Here"));
        }

        //[/UserComboBoxCode_encryptionType]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MainComponent::enterThreeKeys()
{
    // clear output and input to start with blank strings
    threeKeysObject.clearStrings();

    // put text from text fields into the JUCE strings
    threeKeysObject.getTextFromTextEditorsAndFillStrings(keyTextEditor->getText(), inputTextEditor->getText());

    // encrypt / decrypt text
    threeKeysObject.encryptDecryptMessage(encryptionModeToggle->getToggleState());

    // set output text editor to new text
    outputTextEditor->setText(threeKeysObject.getOutputString());
}

void MainComponent::enterXOR()
{
    // clear output and input to start with blank strings
    xorObject.clearStrings();

    // put text from text fields into the JUCE strings
    xorObject.getTextFromTextEditorsAndFillStrings(keyTextEditor->getText(), inputTextEditor->getText());

    // if decrypt mode is on, convert from hex to ASCII
    if (decryptionModeToggle->getToggleState())
    {
        // convertFromHexToString
    }

    // resize key
    xorObject.resizeKey();

    // encrypt / decrypt text
    xorObject.bitwiseEncryption();

    // if encrypt mode is on, convert from ASCII to hex
    if (encryptionModeToggle->getToggleState())
    {
        xorObject.convertStringToHex();
    }

    // set output text editor to new text
    outputTextEditor->setText(xorObject.getOutputString());
}

void MainComponent::enterReverseAll()
{
    // clear output and input to start with blank strings
    reverseStringObject.clearStrings();

    // put text from text fields into the JUCE strings
    reverseStringObject.getTextFromTextEditorsAndFillStrings(keyTextEditor->getText(), inputTextEditor->getText());

    // reverse string
    reverseStringObject.reverseEntireString();

    // set output text editor to new text
    outputTextEditor->setText(reverseStringObject.getOutputString());
}

void MainComponent::enterReverseWord()
{
    // clear output and input to start with blank strings
    reverseStringObject.clearStrings();

    // put text from text fields into the JUCE strings
    reverseStringObject.getTextFromTextEditorsAndFillStrings(keyTextEditor->getText(), inputTextEditor->getText());

    // reverse word
    reverseStringObject.reverseWord();

    // set output text editor to new text
    outputTextEditor->setText(reverseStringObject.getOutputString());
}

void MainComponent::printHistory()
{
    // make sure key has test before recording history
    if(!keyTextEditor->isEmpty())
    {
        if(swapText->isDown())
            historyOfEncryption += "Text Swap\n";

        // history for when encryption is turned on
        if(encryptionModeToggle->getToggleState())
        {
            // check for threeKeys
            if(encryptionType->getSelectedIdAsValue() == 1)
            {
                historyOfEncryption += "Three keys - Encrypt\n";
            }

            // check for XOR
            if(encryptionType->getSelectedIdAsValue() == 2)
            {
                historyOfEncryption += "XOR\n";
            }

            // check Reverse Word
            if(encryptionType->getSelectedIdAsValue() == 3)
            {
                historyOfEncryption += "Reverse Word\n";
            }

            // check Reverse String
            if(encryptionType->getSelectedIdAsValue() == 4)
            {
                historyOfEncryption += "Reverse String\n";
            }
        }
        // history for when encryption is turned off
        else if(!encryptionModeToggle->getToggleState())
        {
            // check for three keys
            if(encryptionType->getSelectedIdAsValue() == 1)
            {
                historyOfEncryption += "Three keys - Decrypt\n";
            }

            // check for XOR
            if(encryptionType->getSelectedIdAsValue() == 2)
            {
                historyOfEncryption += "XOR\n";
            }

            // check Reverse Word
            if(encryptionType->getSelectedIdAsValue() == 3)
            {
                historyOfEncryption += "Reverse Word\n";
            }

            // check Reverse String
            if(encryptionType->getSelectedIdAsValue() == 4)
            {
                historyOfEncryption += "Reverse String\n";
            }
        }
    }

    // display updated history
    historyTextEditor->setText(historyOfEncryption);
}

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
                 fixedSize="1" initialWidth="646" initialHeight="385">
  <BACKGROUND backgroundColour="ff343434"/>
  <TEXTEDITOR name="inputTextEditor" id="cd5cf2088e4b8391" memberName="inputTextEditor"
              virtualName="" explicitFocusOrder="0" pos="4 105 336 136" initialText="Input Text Here"
              multiline="1" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="outputTextEditor" id="20825e2d4e657e11" memberName="outputTextEditor"
              virtualName="" explicitFocusOrder="0" pos="4 245 336 136" initialText="Text Output Displayed Here"
              multiline="1" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="keyText" id="b5d11893eb6accf3" memberName="keyTextEditor"
              virtualName="" explicitFocusOrder="0" pos="4 61 336 40" bkgcol="ffffffff"
              initialText="Input Key Here" multiline="1" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="3bbb40b8fcf75027" memberName="encryptDecryptText"
              virtualName="" explicitFocusOrder="0" pos="344 105 147 136" buttonText="Encrypt / Decrypt Text"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="c83123a33c17aff6" memberName="clearText"
              virtualName="" explicitFocusOrder="0" pos="344 337 147 44" buttonText="Clear Text"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="3966e441c06b33be" memberName="swapText"
              virtualName="" explicitFocusOrder="0" pos="344 245 147 44" tooltip="Swap Text is handy for using multiple encryption types back-to-back.  It is also used for testing purposes, to reassure that the encryption is working both ways."
              buttonText="Swap Text" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="decryptionModeToggle" id="eb69d3a92b08680f" memberName="decryptionModeToggle"
                virtualName="" explicitFocusOrder="0" pos="416 54 75 24" txtcol="ffffffff"
                buttonText="Decrypt" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="encryptionModeToggle" id="feb87990a59e0b0d" memberName="encryptionModeToggle"
                virtualName="" explicitFocusOrder="0" pos="344 54 75 24" txtcol="ffffffff"
                buttonText="Encrypt" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TEXTBUTTON name="copyToClipboard" id="f46788f09ba91384" memberName="copyToClipboard"
              virtualName="" explicitFocusOrder="0" pos="344 291 73 44" buttonText="Copy"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="pasteToInput" id="7be5641456548145" memberName="pasteToInput"
              virtualName="" explicitFocusOrder="0" pos="418 291 73 44" buttonText="Paste"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="encryptionType" id="a9555f9683e5e791" memberName="encryptionType"
            virtualName="" explicitFocusOrder="0" pos="344 77 147 24" tooltip="3Keys - My custom encryption that's more of a proof of concept than a secure system.  Recommended to not use for sensitive data.&#10;&#10;XOR - Standaard xclusive or / Bitwise Encryption"
            editable="0" layout="33" items="3Keys&#10;XOR&#10;Reverse Word&#10;Reverse All&#10;None"
            textWhenNonSelected="Encryption Type" textWhenNoItems="(no choices)"/>
  <LABEL name="productNameLabel" id="393e5f12893a9600" memberName="productNameLabel"
         virtualName="" explicitFocusOrder="0" pos="1 -6 646 63" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="The Lyons' Den Encryption"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Britannic Bold" fontsize="58.399999999999998579" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="ca80c40e51273743" memberName="historyTextEditor"
              virtualName="" explicitFocusOrder="0" pos="495 77 147 304" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <LABEL name="historyLabel" id="e8c5107a1bcb8805" memberName="historyLabel"
         virtualName="" explicitFocusOrder="0" pos="496 53 147 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="History" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
