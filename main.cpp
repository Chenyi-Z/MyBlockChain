#include <iostream>
#include "blockchain.h"
#include "observer.h"
#include "record.h"
#include "trans_data.h"
#include "message.h"
#include "response.h"
#include "printOb.h"

int main() {
    Blockchain blockchain;
    Observer *ob = new PrintOb();
    blockchain.registerClient(ob);
    Record *r1 = new Trans_Data("Mike", "Will", 233, "first transaction");
    blockchain.addBlock(r1);
    // check if each block has not been hacked;

    if (blockchain.checkValidity()) {
        Message message("The check has complete, no error has occurred.");
        blockchain.notifyClients(&message);
    } else {
        Message message("The check has complete, error has occurred.");
        blockchain.notifyClients(&message);
    }

    return 0;
}