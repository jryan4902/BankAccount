#include "Account.h" //includes header file

//intitialize default account number
int Account::nextAcctNum = 1000;


//default constructor
Account::Account() : acctNumber(nextAcctNum++), balance(0.0){}

//copy constructor
Account::Account(const string& name, float initialBalance) : acctNumber(nextAcctNum++), customerName(name), balance(initialBalance){}

//Destructor
Account::~Account() {}

// Set account number
void Account::setAcctNum(int tempAcctNum){
    acctNumber = tempAcctNum;
}

// Get account number
int Account::getAcctNum() const{
    return acctNumber;
}

// Set account name
void Account::setName(const string& tempName){
    customerName = tempName;
}

// Get account name
string Account::getName() const {
    return customerName;
}

//copy operator
Account& Account::operator=(const Account& other){
    if(this != &other){
        //allows data member to copy from other
        acctNumber = other.acctNumber;
        customerName = other.customerName;
        balance = other.balance;
    }
    return *this;
}

// Deposit function
bool Account::deposit(float tempAmount){
    if (tempAmount > 0){
        balance += tempAmount;
        return true;
    }
    else {
        cout << "Invalid deposit amount." << endl;
        return false;
    }
}

// Withdraw function
bool Account::withdraw(float tempAmount){
    if (tempAmount > 0 && balance >= tempAmount) {
        balance -= tempAmount;
        return true;
    }
    else {
        cout << "Insufficent funds or invalid amount." << endl;
        return false;
    }
}

// Get balance
float Account::getBalance() const{
    return balance;
}

void Account::setNextAcctNum(int nextNum){
    nextAcctNum = nextNum;
}

