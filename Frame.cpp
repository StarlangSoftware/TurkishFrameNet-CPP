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

LexicalUnit Frame::getLexicalUnit(int index) {
    return lexicalUnits.at(index);
}

int Frame::size() {
    return lexicalUnits.size();
}

string Frame::getName() {
    return name;
}
