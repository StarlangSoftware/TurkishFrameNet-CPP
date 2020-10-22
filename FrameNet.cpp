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

int FrameNet::size() {
    return frames.size();
}

Frame FrameNet::getFrame(int index) {
    return frames.at(index);
}
