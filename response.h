//
// Created by Chenyi Zhao on 2019-10-15.
//

#ifndef BLOCKCHAIN_RESPONSE_H
#define BLOCKCHAIN_RESPONSE_H

#include <string>

class Response {
public:
    virtual std::string getInfo() = 0;
};

#endif //BLOCKCHAIN_RESPONSE_H
