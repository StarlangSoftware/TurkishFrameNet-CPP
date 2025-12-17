//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#ifndef FRAMENET_FRAMENET_H
#define FRAMENET_FRAMENET_H

#include "Frame.h"

class FrameNet {
private:
    vector<Frame> frames;
public:
    FrameNet();
    [[nodiscard]] bool lexicalUnitExists(const string& synSetId) const;
    [[nodiscard]] vector<Frame> getFrames(const string& synSetId) const;
    [[nodiscard]] int size() const;
    [[nodiscard]] Frame getFrame(int index) const;
};


#endif //FRAMENET_FRAMENET_H
