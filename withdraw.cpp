#include <iostream>
#include <stdexcept>
using namespace std;

void withdraw(double& balance, double amount){
    if (amount <= 0){
        throw invalid_argument("Amount must be positive");
    }
    if (balance-amount<0){
        throw runtime_error("Insufficient funds for withdraw");
    }
    balance -= amount;
    cout << "Withdraw successful";
}

int main() {

    case 3:
            try{
                    withdraw(...)
            }catch(const invalid_argument){
                cout << "..." << e.what();
            }...
            catch(...){
                cout << "Unexpected" << endl;
            }
}