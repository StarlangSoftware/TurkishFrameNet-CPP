//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "LexicalUnit.h"

LexicalUnit::LexicalUnit(XmlElement *node) {
    XmlElement* elementNode;
    this->synSetId = node->getAttributeValue("ID");
    elementNode = node->getFirstChild();
    while (elementNode != nullptr){
        frameElements.push_back(elementNode->getPcData());
        elementNode = elementNode->getNextSibling();
    }
}

int LexicalUnit::size() {
    return frameElements.size();
}

vector<string> LexicalUnit::getFrameElements() {
    return frameElements;
}
