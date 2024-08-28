#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Account.h"
using namespace std;


//open account function
void openAcct(vector<Account>& accts){
    //variables
    string name;
    float initialAmount;

    cout << "Enter the account name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the initial deposit amount: ";
    cin >> initialAmount;
    
    //opens account and deposits ammount
    Account newAcct(name, initialAmount);
    accts.push_back(newAcct);

    cout << "Account opened: " << accts.back().getAcctNum() << " --- "
    << accts.back().getName() << ": $" << accts.back().getBalance() << endl;

}

//depost function
void deposit(vector<Account>& accts){
    int acctNum;
    float amt;

    cout << "Enter account number: ";
    cin >> acctNum;

    //detects if the account is found and outputs ammount
    bool found = false;
    for (auto& acct : accts) {
        if (acct.getAcctNum() == acctNum) {
            found = true;
            cout << "Enter deposit amount: ";
            cin >> amt;
            acct.deposit(amt);
            cout << "Deposit successful. New balance: $" << acct.getBalance() << endl; //calls function
        }
    }
    if (!found) {
        cout << "Account number " << acctNum << " not found." << endl;
    }
}

void withdraw(vector<Account>& accts){
    int acctNum;
    string findName; //new string omplemented for security
    float amt;

    cout << "Enter account number: ";
    cin >> acctNum;
    cin.ignore();

    //detects account and withdraws money out of amount
    bool found = false;
    for (auto& acct : accts) {
        if (acct.getAcctNum() == acctNum) {
            found = true;
            cout << "Enter customer name for security purposes: ";
            getline(cin, findName);

        if(findName == acct.getName()){
            cout << "Enter withdrawal amount: ";
            cin >> amt;
            if (acct.withdraw(amt)) {
                cout << "Withdrawal successful. New balance: $" << acct.getBalance() << endl; // calls function
            } else {
                cout << "Withdrawal failed." << endl;
            }
            break;
        }else{
            cout << "Account name and/or number did not match. Access is denied." << endl;
        }
        }
    }
    if (!found) {
        cout << "Account number " << acctNum << " not found." << endl;
    }
}

void fastTransfer(vector<Account>& accts){ // new transfer function
    int sAcctNum; //source variable
    int dAcctNum; //destination variable

    cout << "$40 Fast Transfer: source -> destination" << endl;

    cout << "Enter account source number: "; // prompt user to enter account #s
    cin >> sAcctNum;

    cout << "Enter account destination number: ";
    cin >> dAcctNum;
    

    bool sFound = false, dFound = false;
    for(auto& acct : accts){ //loop that searches for account num to match
        if(acct.getAcctNum() == sAcctNum){
            sFound = true;
        }
        if(acct.getAcctNum() == dAcctNum){
            dFound = true;
        }
    }

    if(sFound && dFound){
        for(auto& acct : accts){
            if (acct.getAcctNum() == sAcctNum) {

                acct.withdraw(40.0);
                cout << "$40 Fast Transfer processed: " << sAcctNum << " -> " << dAcctNum << endl;
            }
            if (acct.getAcctNum() == dAcctNum) {
                acct.deposit(40.0);
            }
        }
    }else{
        cout << "Error: Source or destination account number not found. Please try again." << endl;
    }
}

void printAccts(vector<Account>& accts){
    if (accts.empty()) {
        cout << "No accounts available." << endl;
    } else {
        cout << "+------------------------------------------------------+" << "\n";
        cout << "| Account Number | Name | Balance                      |" << "\n";
        for (const auto& acct : accts) {
        cout << "| " << acct.getAcctNum() << " | " << acct.getName() << " | $" << acct.getBalance() << " |" << "\n";
        }
        cout << "+------------------------------------------------------+" << "\n";
    }
}






int main() {
    vector<Account> accounts;
    char userChoice;

    //print the display
    do {
        cout << "+------------------------------------------------------+" << "\n";
        cout << "|          Computer Science and Engineering            |" << "\n";
        cout << "|         CSCE 1040 - Computer Programming II          |" << "\n";
        cout << "|   Jake Gonzales   jrg0466   jakegonzales@my.unt.edu  |" << "\n";
        cout << "+------------------------------------------------------+" << "\n";

        cout << "+------------------------------------------------------+" << "\n";
        cout << "| Enter account selection                              |" << "\n";
        cout << "| 1: Open new account                                  |" << "\n";
        cout << "| 2: Deposit into account                              |" << "\n";
        cout << "| 3: Withdraw from account                             |" << "\n";
        cout << "| 4: Fast transfer $40 into account                    |" << "\n";
        cout << "| 5: Print a list of all accounts                      |" << "\n";
        cout << "| 6: End transaction (Exit)                            |" << "\n";
        cout << "+------------------------------------------------------+" << "\n";

        cout << "> ";
        cin >> userChoice;

        //calling the inputs to the functions
        switch(userChoice){
            case '1':
                openAcct(accounts);
                break;
            case '2':
                deposit(accounts);
                break;
            case '3': 
                withdraw(accounts);
                break;
            case '4':
                fastTransfer(accounts);
                break;
            case '5':
                printAccts(accounts);
                break;
            case '6':
                cout << "Thank you for choosing our bank!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again" << endl;
        }
    } while (userChoice != '6');

return 0;
}
