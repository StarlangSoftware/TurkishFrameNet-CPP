//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#ifndef FRAMENET_FRAME_H
#define FRAMENET_FRAME_H
#include <string>
#include <vector>
#include "XmlElement.h"
#include "XmlDocument.h"

using namespace std;

class Frame {
private:
    string name;
    vector<string> lexicalUnits;
    vector<string> frameElements;
public:
    explicit Frame(const string& _name);
    bool lexicalUnitExists(const string& synSetId);
    void addLexicalUnit(const string& lexicalUnit);
    void addFrameElement(const string& frameElement);
    string getLexicalUnit(int index);
    string getFrameElement(int index);
    int lexicalUnitSize();
    int frameElementSize();
    string getName();
};


#endif //FRAMENET_FRAME_H
