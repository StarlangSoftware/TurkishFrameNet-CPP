//
// Created by Olcay Taner YILDIZ on 22.10.2020.
//

#include "FrameNet.h"

FrameNet::FrameNet() {
    ifstream inputStream;
    string fileName;
    inputStream.open("../files.txt", ifstream::in);
    while (inputStream.good()){
        getline(inputStream, fileName);
        frames.emplace_back(Frame(fileName.substr(0, fileName.find(".xml")), XmlDocument("../Frames/" + fileName)));
    }
    inputStream.close();
}

bool FrameNet::lexicalUnitExists(string synSetId) {
    for (Frame frame : frames){
        if (frame.lexicalUnitExists(synSetId)){
            return true;
        }
    }
    return false;
}

vector<Frame> FrameNet::getFrames(string synSetId) {
    vector<Frame> result;
    for (Frame frame : frames){
        if (frame.lexicalUnitExists(synSetId)){
            result.emplace_back(frame);
        }
    }
    return result;
}

int FrameNet::size() {
    return frames.size();
}

Frame FrameNet::getFrame(int index) {
    return frames.at(index);
}
