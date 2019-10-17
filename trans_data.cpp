//
// Created by Chenyi Zhao on 2019-10-15.
//

#include "trans_data.h"
#include "sha256.h"
#include <sstream>

Trans_Data::Trans_Data(std::string s, std::string r, double amt, std::string des):
Record(), sender{s}, recipient{r}, amount{amt}, description{des} {}


std::string Trans_Data::returnRecord() {
    std::stringstream ss;
    ss << sender << recipient << amount << description;
    return ss.str();
}