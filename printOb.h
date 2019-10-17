//
// Created by Chenyi Zhao on 2019-10-16.
//

#ifndef BLOCKCHAIN_PRINTOB_H
#define BLOCKCHAIN_PRINTOB_H

#include "observer.h"

// This class is a example of how observer pattern will work in this scenario
class PrintOb: public Observer{
public:
    void notify(Response *response) override;
};

#endif //BLOCKCHAIN_PRINTOB_H
