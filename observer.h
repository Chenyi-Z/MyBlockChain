//
// Created by Chenyi Zhao on 2019-10-15.
//

#ifndef BLOCKCHAIN_OBSERVER_H
#define BLOCKCHAIN_OBSERVER_H

#include "response.h"

class Observer {
public:
    virtual void notify(Response *response) = 0;
};


#endif //BLOCKCHAIN_OBSERVER_H
