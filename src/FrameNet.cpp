//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "FrameNet.h"

FrameNet::FrameNet() {
    XmlDocument xmlDocument = XmlDocument("framenet.xml");
    xmlDocument.parse();
    XmlElement* rootNode = xmlDocument.getFirstChild();
    XmlElement* frameNode = rootNode->getFirstChild();
    while (frameNode != nullptr){
        Frame currentFrame = Frame(frameNode->getAttributeValue("NAME"));
        XmlElement* lexicalUnits = frameNode->getFirstChild();
        XmlElement* lexicalUnit = lexicalUnits->getFirstChild();
        while (lexicalUnit != nullptr){
            currentFrame.addLexicalUnit(lexicalUnit->getPcData());
            lexicalUnit = lexicalUnit->getNextSibling();
        }
        XmlElement* frameElements = lexicalUnits->getNextSibling();
        XmlElement* frameElement = frameElements->getFirstChild();
        while (frameElement != nullptr){
            currentFrame.addFrameElement(frameElement->getPcData());
            frameElement = frameElement->getNextSibling();
        }
        frames.emplace_back(currentFrame);
        frameNode = frameNode->getNextSibling();
    }
}

bool FrameNet::lexicalUnitExists(const string& synSetId) const{
    for (const Frame& frame : frames){
        if (frame.lexicalUnitExists(synSetId)){
            return true;
        }
    }
    return false;
}

vector<Frame> FrameNet::getFrames(const string& synSetId) const{
    vector<Frame> result;
    for (const Frame& frame : frames){
        if (frame.lexicalUnitExists(synSetId)){
            result.emplace_back(frame);
        }
    }
    return result;
}

int FrameNet::size() const{
    return frames.size();
}

Frame FrameNet::getFrame(int index) const{
    return frames.at(index);
}
