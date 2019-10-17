//
// Created by Chenyi Zhao on 2019-10-15.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include <vector>
#include "block.h"
#include "observer.h"

class Response;

class Blockchain {
    std::vector<Block *> chain; // a chain(vector) of blocks
    std::vector<Observer *> clients; // a vector of clients/interfaces that will be received info

public:
    Blockchain();
    ~Blockchain();
    // when a new transaction happens, a new block will be created to store the transaction data
    void addBlock(Record *record);
    // add a new client/interface to the vector
    void registerClient(Observer *client);
    // we can check if our block chain was hacked
    bool checkValidity();
    void notifyClients(Response *response);

private:
    int curIndex();
    Block *getLastBlock();
    unsigned int newProof();

};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
