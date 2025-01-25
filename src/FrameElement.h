//
// Created by Olcay Taner YILDIZ on 24.11.2020.
//

#ifndef FRAMENET_FRAMEELEMENT_H
#define FRAMENET_FRAMEELEMENT_H
#include <string>

using namespace std;

class FrameElement {
private:
    string frameElementType;
    string frame;
    string id;
public:
    explicit FrameElement(const string& frameElement);
    FrameElement(const string& _frameElementType, const string& _frame, const string& _id);
    string getFrameElementType() const;
    string getFrame() const;
    string getId() const;
    string to_string() const;
    void setId(const string& _id);
};


#endif //FRAMENET_FRAMEELEMENT_H
