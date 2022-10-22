//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "Frame.h"
#include <utility>
#include <algorithm>

Frame::Frame(const string& _name) {
    this->name = _name;
}

bool Frame::lexicalUnitExists(const string& synSetId) {
    return find(lexicalUnits.begin(), lexicalUnits.end(), synSetId) != lexicalUnits.end();
}

string Frame::getLexicalUnit(int index) {
    return lexicalUnits.at(index);
}

string Frame::getFrameElement(int index) {
    return frameElements.at(index);
}

int Frame::lexicalUnitSize() {
    return lexicalUnits.size();
}

int Frame::frameElementSize() {
    return frameElements.size();
}

string Frame::getName() {
    return name;
}

void Frame::addLexicalUnit(const string& lexicalUnit) {
    lexicalUnits.emplace_back(lexicalUnit);
}

void Frame::addFrameElement(const string& frameElement) {
    frameElements.emplace_back(frameElement);
}
