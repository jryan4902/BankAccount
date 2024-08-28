#ifndef ACCOUNT_H //Define the header account
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account{
public:
        Account(); //default constructor
        Account(const string& name, float initialBalance); //constructor overload
        ~Account(); //destructor
        Account& operator=(const Account& other); //copy assignment operator
        static int nextAcct;
        static int setNextAcct;

        void setAcctNum(int tempAcctNum);
        int getAcctNum() const;
        void setName(const string& tempName);
        string getName() const;
        bool deposit(float tempAmount);
        bool withdraw(float tempAmount);
        float getBalance() const;
        static void setNextAcctNum(int nextNum);

private:
        int acctNumber;
        string customerName;
        float balance;
        static int nextAcctNum;
};

#endif
