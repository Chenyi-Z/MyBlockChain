//
// Created by Chenyi Zhao on 2019-10-15.
//

#ifndef BLOCKCHAIN_RECORD_H
#define BLOCKCHAIN_RECORD_H

#include <string>

class Record{
public:
    virtual std::string returnRecord() = 0;
};

#endif //BLOCKCHAIN_RECORD_H
