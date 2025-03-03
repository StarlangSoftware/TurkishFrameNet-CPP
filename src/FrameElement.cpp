//
// Created by Olcay Taner YILDIZ on 24.11.2020.
//

#include "FrameElement.h"
using namespace std;

/**
 * A constructor of FrameElement class which takes frameElement string which is in the form of frameElementType$id
 * and parses this string into frameElementType and id. If the frameElement string does not contain '$' then the
 * constructor return a NONE type frameElement.
 *
 * @param frameElement  FrameElement string containing the frameElementType and id
 */
FrameElement::FrameElement(const string& frameElement) {
    if (frameElement.find('$') != string::npos){
        frameElementType = frameElement.substr(0, frameElement.find('$'));
        frame = frameElement.substr(frameElement.find('$') + 1, frameElement.rfind('$') - frameElement.find('$') - 1);
        id = frameElement.substr(frameElement.rfind('$') + 1);
    } else {
        frameElementType = "NONE";
    }
}

/**
 * Another constructor of FrameElement class which takes _frameElementType and _id as inputs and initializes corresponding attributes
 *
 * @param _frameElementType  Type of the frameElement
 * @param _frame  Frame of the frameElement
 * @param _id  Id of the frameElement
 */
FrameElement::FrameElement(const string& _frameElementType, const string& _frame, const string& _id) {
    this->frameElementType = _frameElementType;
    this->frame = _frame;
    this->id = _id;
}

/**
 * Accessor for frameElementType.
 *
 * @return frameElementType.
 */
string FrameElement::getFrameElementType() const{
    return frameElementType;
}

/**
 * Accessor for id.
 *
 * @return id.
 */
string FrameElement::getId() const{
    return id;
}

/**
 * Accessor for frame.
 *
 * @return frame.
 */
string FrameElement::getFrame() const{
    return frame;
}

/**
 * to_string converts an FrameElement to a string. If the frameElementType is "NONE" returns only "NONE", otherwise
 * it returns frameElement string which is in the form of frameElementType$id
 *
 * @return string form of frameElement
 */
string FrameElement::to_string() const{
    if (frameElementType == "NONE"){
        return frameElementType;
    } else {
        return frameElementType + "$" + frame + "$" + id;
    }
}

/**
 * Setter for the id
 * @param id New id of the frame element.
 */
void FrameElement::setId(const string& _id) {
    this->id = _id;
}
