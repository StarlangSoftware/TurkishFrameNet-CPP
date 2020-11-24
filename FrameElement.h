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
    string id;
public:
    FrameElement(string frameElement);
    FrameElement(string frameElementType, string id);
    string getFrameElementType();
    string getId();
    string to_string();
};


#endif //FRAMENET_FRAMEELEMENT_H
