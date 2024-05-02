//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "FrameNet.h"

/**
 * A constructor of FrameNet class which reads all frame files inside the files2.txt file. For each
 * filename inside that file, the constructor creates a FrameNet.Frame and puts in inside the frames {@link ArrayList}.
 */
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

/**
 * Checks if the given lexical unit exists in any frame in the frame set.
 * @param synSetId Id of the lexical unit
 * @return True if any frame contains the given lexical unit, false otherwise.
 */
bool FrameNet::lexicalUnitExists(const string& synSetId) const{
    for (const Frame& frame : frames){
        if (frame.lexicalUnitExists(synSetId)){
            return true;
        }
    }
    return false;
}

/**
 * Returns an array of frames that contain the given lexical unit in their lexical units
 * @param synSetId Id of the lexical unit.
 * @return An array of frames that contains the given lexical unit.
 */
vector<Frame> FrameNet::getFrames(const string& synSetId) const{
    vector<Frame> result;
    for (const Frame& frame : frames){
        if (frame.lexicalUnitExists(synSetId)){
            result.emplace_back(frame);
        }
    }
    return result;
}

/**
 * Returns number of frames in the frame set.
 * @return Number of frames in the frame set.
 */
int FrameNet::size() const{
    return frames.size();
}

/**
 * Returns the element at the specified position in the frame list.
 * @param index index of the element to return
 * @return The element at the specified position in the frame list.
 */
Frame FrameNet::getFrame(int index) const{
    return frames.at(index);
}
