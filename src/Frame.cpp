//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "Frame.h"
#include <utility>

Frame::Frame(string name) {
    this->name = std::move(name);
}

bool Frame::lexicalUnitExists(string synSetId) {
    for (const string& lexicalUnit : lexicalUnits){
        if (lexicalUnit == synSetId){
            return true;
        }
    }
    return false;
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

void Frame::addLexicalUnit(string lexicalUnit) {
    lexicalUnits.emplace_back(lexicalUnit);
}

void Frame::addFrameElement(string frameElement) {
    frameElements.emplace_back(frameElement);
}
