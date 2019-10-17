//
// Created by Chenyi Zhao on 2019-10-16.
//

#include "printOb.h"
#include <iostream>

void PrintOb::notify(Response *response) {
    std::cout << response->getInfo() << std::endl;
}