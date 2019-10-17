//
// Created by Chenyi Zhao on 2019-10-16.
//

#include "message.h"

Message::Message(std::string in): info{in} {}

std::string Message::getInfo() {
    return info;
}