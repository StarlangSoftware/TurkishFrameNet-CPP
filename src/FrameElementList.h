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
    explicit FrameElementList(const string& frameElementList);
    [[nodiscard]] string to_string() const;
    void updateConnectedId(const string& previousId, const string& currentId) const;
    void addPredicate(const string& predicateId);
    void removePredicate();
    [[nodiscard]] bool containsPredicate() const;
    [[nodiscard]] bool containsPredicateWithId(const string& predicateId) const;
    [[nodiscard]] vector<string> getFrameElements() const;
    [[nodiscard]] bool containsFrameElement(const string& frameElementType, const string& frame, const string& id) const;
};


#endif //FRAMENET_FRAMEELEMENTLIST_H
