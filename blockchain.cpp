//
// Created by Chenyi Zhao on 2019-10-15.
//

#include <sstream>
#include <string>
#include "blockchain.h"
#include "block.h"
#include "sha256.h"
#include "message.h"
#include "trans_data.h"
#include "record.h"

Blockchain::Blockchain() {
    // initialize genesis block when create the block chain.
    Record *r= new Trans_Data("NA","NA", 0, "GENISIS BLOCK");
    Block *genesisBlock = new Block(0,"0000", 123, r);
    chain.emplace_back(genesisBlock);
}

Blockchain::~Blockchain() {
    for (auto client:clients) {
        delete client;
    }
}


// add a new block to the existing chain
void Blockchain::addBlock(Record *record) {
    int index = curIndex();
    std::string prevHash = getLastBlock()->hashBlock();
    unsigned int proof = newProof();
    Block *b = new Block(index, prevHash, proof, record);
    chain.emplace_back(b);
    Message m("A new block has been added");
    notifyClients(&m);
}


int Blockchain::curIndex() {
    return chain.size();
}


Block *Blockchain::getLastBlock() {
    return chain.back();
}


// this function is crucial to the block chain
// the proof of the new block is determined by the data of the previous block
// therefore, we are able to verify if the data is unchanged
unsigned int Blockchain::newProof() {
    std::string prevHash = getLastBlock()->hashBlock();
    unsigned int prevProof =  getLastBlock()->getProof();
    unsigned int proof = 1;
    // increments until find the correct number that satisfies the requirement
    while (true) {
        std::stringstream ss;
        ss << prevHash << proof << prevProof;
        std::string s = sha256(ss.str());
        if (s.substr(0,4) == "0000") break;
        else proof += 1;
    }
    return proof;
}


// the function is able to verify the data of each blocks is unchanged
bool Blockchain::checkValidity() {
    // loop through the chain to check every block
    for (std::vector<Block *>::iterator it = chain.begin() ; it != (chain.end() - 1); ++it) {
        std::vector<Block *>::iterator next = it+1;
        std::stringstream ss;
        ss << (*it)->hashBlock() << (*next)->getProof() << (*it)->getProof();
        std::string s = sha256(ss.str());
        if (s.substr(0,4) != "0000") return false;
    }
    return true;
}


void Blockchain::registerClient(Observer *client) {
    clients.emplace_back(client);
}


void Blockchain::notifyClients(Response *response) {
    for (auto c:clients){
        c->notify(response);
    }
}