//
// Created by Olcay Taner YILDIZ on 25.01.2025.
//

#ifndef FRAMENET_FRAMEELEMENTLIST_H
#define FRAMENET_FRAMEELEMENTLIST_H

#include "FrameElement.h"
#include <vector>

using namespace std;

class FrameElementList {
private:
    vector<FrameElement> frameElements;
public:
    FrameElementList(const string& frameElementList);
    string to_string() const;
    void updateConnectedId(const string& previousId, const string& currentId);
    void addPredicate(const string& predicateId);
    void removePredicate();
    bool containsPredicate() const;
    bool containsPredicateWithId(const string& predicateId) const;
    vector<string> getFrameElements();
    bool containsFrameElement(const string& frameElementType, const string& frame, const string& id) const;
};


#endif //FRAMENET_FRAMEELEMENTLIST_H
