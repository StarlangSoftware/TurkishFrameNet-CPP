//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "Frame.h"
#include <algorithm>

Frame::Frame(const string& _name) {
    this->name = _name;
}

bool Frame::lexicalUnitExists(const string& synSetId) const{
    return find(lexicalUnits.begin(), lexicalUnits.end(), synSetId) != lexicalUnits.end();
}

string Frame::getLexicalUnit(int index) const{
    return lexicalUnits.at(index);
}

string Frame::getFrameElement(int index) const{
    return frameElements.at(index);
}

int Frame::lexicalUnitSize() const{
    return lexicalUnits.size();
}

int Frame::frameElementSize() const{
    return frameElements.size();
}

string Frame::getName() const{
    return name;
}

void Frame::addLexicalUnit(const string& lexicalUnit) {
    lexicalUnits.emplace_back(lexicalUnit);
}

void Frame::addFrameElement(const string& frameElement) {
    frameElements.emplace_back(frameElement);
}
