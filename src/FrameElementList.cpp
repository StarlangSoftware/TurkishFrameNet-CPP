//
// Created by Olcay Taner YILDIZ on 25.01.2025.
//

#include "FrameElementList.h"
#include "StringUtils.h"

/**
 * Constructor of frame element list from a string. The frame elements for a word is a concatenated list of
 * frame element separated via '#' character.
 * @param frameElementList String consisting of frame elements separated with '#' character.
 */
FrameElementList::FrameElementList(const string &frameElementList) {
    vector<string> splitWords = StringUtils::split(frameElementList, "#");
    for (const string& item : splitWords){
        frameElements.emplace_back(item);
    }
}

/**
 * Overloaded toString method to convert a frame element list to a string. Concatenates the string forms of all
 * frame element with '#' character.
 * @return String form of the frame element list.
 */
string FrameElementList::to_string() const {
    if (frameElements.empty()){
        return "NONE";
    } else {
        string result = frameElements[0].to_string();
        for (int i = 1; i < frameElements.size(); i++){
            result += "#" + frameElements[i].to_string();
        }
        return result;
    }
}

/**
 * Replaces id's of predicates, which have previousId as synset id, with currentId.
 * @param previousId Previous id of the synset.
 * @param currentId Replacement id.
 */
void FrameElementList::updateConnectedId(const string &previousId, const string &currentId) {
    for (FrameElement frameElement: frameElements){
        if (frameElement.getId() == previousId){
            frameElement.setId(currentId);
        }
    }
}

/**
 * Adds a predicate argument to the frame element list of this word.
 * @param predicateId Synset id of this predicate.
 */
void FrameElementList::addPredicate(const string &predicateId) {
    if (!frameElements.empty() && frameElements[0].getFrameElementType() == "NONE"){
        frameElements.erase(frameElements.begin());
    }
    frameElements.emplace_back("PREDICATE", "NONE", predicateId);
}

/**
 * Removes the predicate with the given predicate id.
 */
void FrameElementList::removePredicate() {
    for (int i = 0; i < frameElements.size(); i++){
        if (frameElements[i].getFrameElementType() == "PREDICATE"){
            frameElements.erase(frameElements.begin() + i);
            break;
        }
    }
}

/**
 * Checks if one of the frame elements is a predicate.
 * @return True, if one of the frame elements is predicate; false otherwise.
 */
bool FrameElementList::containsPredicate() const {
    for (const FrameElement& frameElement: frameElements){
        if (frameElement.getFrameElementType() == "PREDICATE"){
            return true;
        }
    }
    return false;
}

/**
 * Checks if one of the arguments is a predicate with the given id.
 * @param predicateId Synset id to check.
 * @return True, if one of the arguments is predicate; false otherwise.
 */
bool FrameElementList::containsPredicateWithId(const string &predicateId) const {
    for (const FrameElement& frameElement: frameElements){
        if (frameElement.getFrameElementType() == "PREDICATE" && frameElement.getId() == predicateId){
            return true;
        }
    }
    return false;
}

/**
 * Returns the frame elements as an array list of strings.
 * @return Frame elements as an array list of strings.
 */
vector<string> FrameElementList::getFrameElements() {
    vector<string> result;
    result.reserve(frameElements.size());
    for (const FrameElement& frameElement: frameElements){
        result.emplace_back(frameElement.to_string());
    }
    return result;
}

/**
 * Checks if the given argument with the given type and id exists or not.
 * @param frameElementType Type of the frame element to search for.
 * @param frame frame Name of the frame to search for
 * @param id Id of the frame element to search for.
 * @return True if the frame element exists, false otherwise.
 */
bool
FrameElementList::containsFrameElement(const string &frameElementType, const string &frame, const string &id) const {
    for (const FrameElement& frameElement: frameElements){
        if (frameElement.getFrameElementType() == frameElementType && frameElement.getFrame() == frame && frameElement.getId() == id){
            return true;
        }
    }
    return false;
}
