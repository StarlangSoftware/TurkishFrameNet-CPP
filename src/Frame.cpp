//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "Frame.h"
#include <algorithm>

/**
 * Constructor of Frame class which takes inputStream as input and reads the frame
 *
 * @param _name  Name of the frame
 */
Frame::Frame(const string& _name) {
    this->name = _name;
}

/**
 * Checks if the given lexical unit exists in the current frame
 * @param synSetId Lexical unit to be searched.
 * @return True if the lexical unit exists, false otherwise.
 */
bool Frame::lexicalUnitExists(const string& synSetId) const{
    return find(lexicalUnits.begin(), lexicalUnits.end(), synSetId) != lexicalUnits.end();
}

/**
 * Accessor for a given index in the lexicalUnit array.
 * @param index Index of the lexical unit
 * @return The lexical unit at position index in the lexicalUnit array
 */
string Frame::getLexicalUnit(int index) const{
    return lexicalUnits.at(index);
}

/**
 * Accessor for a given index in the frameElements array.
 * @param index Index of the frame element
 * @return The frame element at position index in the frameElements array
 */
string Frame::getFrameElement(int index) const{
    return frameElements.at(index);
}

/**
 * Returns number of lexical units in the current frame
 * @return Number of lexical units in the current frame
 */
int Frame::lexicalUnitSize() const{
    return lexicalUnits.size();
}

/**
 * Returns number of frame elements in the current frame
 * @return Number of frame elements in the current frame
 */
int Frame::frameElementSize() const{
    return frameElements.size();
}

/**
 * Accessor for the name of the frame
 * @return Name of the frame
 */
string Frame::getName() const{
    return name;
}

/**
 * Adds a new lexical unit to the current frame
 * @param lexicalUnit Lexical unit to be added
 */
void Frame::addLexicalUnit(const string& lexicalUnit) {
    lexicalUnits.emplace_back(lexicalUnit);
}

/**
 * Adds a new frame element to the current frame
 * @param frameElement Frame element to be added
 */
void Frame::addFrameElement(const string& frameElement) {
    frameElements.emplace_back(frameElement);
}
