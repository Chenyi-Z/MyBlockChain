//
// Created by Chenyi Zhao on 2019-10-15.
//

#ifndef BLOCKCHAIN_TRANS_DATA_H
#define BLOCKCHAIN_TRANS_DATA_H
#include "record.h"
#include <string>

class Trans_Data: public Record {
    std::string sender;
    std::string recipient;
    double amount;
    std::string description;
public:
    Trans_Data(std::string sender, std::string recipient, double amount, std::string description);
    std::string returnRecord() override;
};

#endif //BLOCKCHAIN_TRANS_DATA_H
