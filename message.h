//
// Created by Chenyi Zhao on 2019-10-16.
//

#ifndef BLOCKCHAIN_MESSAGE_H
#define BLOCKCHAIN_MESSAGE_H

#include "response.h"
#include <string>

class Message: public Response {
    std::string info;

public:
    Message(std::string info);
    std::string getInfo() override ;

};

#endif //BLOCKCHAIN_MESSAGE_H
