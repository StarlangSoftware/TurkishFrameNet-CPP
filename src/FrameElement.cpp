//
// Created by Olcay Taner YILDIZ on 24.11.2020.
//

#include "FrameElement.h"

#include "FrameElement.h"
using namespace std;

/**
 * A constructor of {@link FrameElement} class which takes frameElement string which is in the form of frameElementType$id
 * and parses this string into frameElementType and id. If the frameElement string does not contain '$' then the
 * constructor return a NONE type frameElement.
 *
 * @param argument  FrameElement string containing the frameElementType and id
 */
FrameElement::FrameElement(string frameElement) {
    if (frameElement.find('$') != string::npos){
        frameElementType = frameElement.substr(0, frameElement.find('$'));
        frame = frameElement.substr(frameElement.find('$') + 1, frameElement.rfind('$') - frameElement.find('$') - 1);
        id = frameElement.substr(frameElement.rfind('$') + 1);
    } else {
        frameElementType = "NONE";
    }
}

/**
 * Another constructor of {@link FrameElement} class which takes frameElementType and id as inputs and initializes corresponding attributes
 *
 * @param argumentType  Type of the frameElement
 * @param id  Id of the frameElement
 */
FrameElement::FrameElement(string frameElementType, string frame, string id) {
    this->frameElementType = move(frameElementType);
    this->frame = move(frame);
    this->id = move(id);
}

/**
 * Accessor for frameElementType.
 *
 * @return frameElementType.
 */
string FrameElement::getFrameElementType() {
    return frameElementType;
}

/**
 * Accessor for id.
 *
 * @return id.
 */
string FrameElement::getId() {
    return id;
}

/**
 * Accessor for frame.
 *
 * @return frame.
 */
string FrameElement::getFrame() {
    return frame;
}

/**
 * to_string converts an {@link FrameElement} to a string. If the frameElementType is "NONE" returns only "NONE", otherwise
 * it returns frameElement string which is in the form of frameElementType$id
 *
 * @return string form of frameElement
 */
string FrameElement::to_string() {
    if (frameElementType == "NONE"){
        return frameElementType;
    } else {
        return frameElementType + "$" + frame + "$" + id;
    }
}

