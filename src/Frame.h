//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#ifndef FRAMENET_FRAME_H
#define FRAMENET_FRAME_H
#include <string>
#include <vector>

using namespace std;

class Frame {
private:
    string name;
    vector<string> lexicalUnits;
    vector<string> frameElements;
public:
    explicit Frame(const string& _name);
    [[nodiscard]] bool lexicalUnitExists(const string& synSetId) const;
    void addLexicalUnit(const string& lexicalUnit);
    void addFrameElement(const string& frameElement);
    [[nodiscard]] string getLexicalUnit(int index) const;
    [[nodiscard]] string getFrameElement(int index) const;
    [[nodiscard]] int lexicalUnitSize() const;
    [[nodiscard]] int frameElementSize() const;
    [[nodiscard]] string getName() const;
};


#endif //FRAMENET_FRAME_H
