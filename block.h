//
// Created by Chenyi Zhao on 2019-10-15.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include "record.h"
#include <string>

class Block{
    int index; // index of this block in the chain
    time_t timeStamp; // time that the block is being created
    std::string prevHash;
    unsigned int proof;
    Record *record;

public:
    Block(int index, std::string prevHash, unsigned int proof, Record *record);
    ~Block();
    std::string hashBlock();
    unsigned int getProof();
    std::string getPrevHash();

};



#endif //BLOCKCHAIN_BLOCK_H
