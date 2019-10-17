//
// Created by Chenyi Zhao on 2019-10-15.
//

#include "block.h"
#include "sha256.h"
#include <ctime>
#include <sstream>

Block::Block(int i, std::string prevH, unsigned int p, Record *r):
index{i}, prevHash{prevH}, proof{p}, record{r} {
    timeStamp = time(nullptr);
}


Block::~Block() {
    delete record;
}


std::string Block::hashBlock() {
    std::stringstream ss;
    ss << index << timeStamp << prevHash << proof << record->returnRecord();
    return sha256(ss.str());
}


unsigned int Block::getProof() {
    return proof;
}


std::string Block::getPrevHash() {
    return prevHash;
}