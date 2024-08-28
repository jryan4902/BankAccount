#ifndef PROJECT3_H // define header
#define PROJECT3_H

#include "Account.h" //includes account files

void openAcct(vector<Account>& accts);
void deposit(vector<Account>& accts);
void withdraw(vector<Account>& accts);
void printAccts(vector<Account>& accts);
void fastTransfer(vector<Account>& accts); //New fast transfer function

#endif 
