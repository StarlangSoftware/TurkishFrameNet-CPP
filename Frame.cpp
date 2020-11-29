//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "Frame.h"
#include <utility>

Frame::Frame(string name, XmlDocument xmlDocument) {
    XmlElement* node;
    this->name = std::move(name);
    node = xmlDocument.getFirstChild();
    while (node != nullptr){
        lexicalUnits.emplace_back(LexicalUnit(node));
        node = node->getNextSibling();
    }
}

bool Frame::lexicalUnitExists(string synSetId) {
    for (LexicalUnit lexicalUnit : lexicalUnits){
        if (lexicalUnit.getSynSetId() == synSetId){
            return true;
        }
    }
    return false;
}

LexicalUnit Frame::getLexicalUnitWithId(string synSetId) {
    for (LexicalUnit lexicalUnit : lexicalUnits){
        if (lexicalUnit.getSynSetId() == synSetId){
            return lexicalUnit;
        }
    }
}

void Frame::removeLexicalUnit(LexicalUnit toBeRemoved) {
    for (int i = 0; i < lexicalUnits.size(); i++){
        if (lexicalUnits[i].getSynSetId() == toBeRemoved.getSynSetId()){
            lexicalUnits.erase(lexicalUnits.begin() + i);
        }
    }
}

LexicalUnit Frame::getLexicalUnit(int index) {
    return lexicalUnits.at(index);
}

int Frame::size() {
    return lexicalUnits.size();
}

string Frame::getName() {
    return name;
}
