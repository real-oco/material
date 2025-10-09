#include <bits/stdc++.h>
using namespace std;

class Account {
private:
// Encapsulation – Keeping data safe inside a class
    string owner;
    double balance;
// owner and balance are private
// They can only be accessed via public methods
// This protects data from being changed improperly

public:
    Account(string name, double initialBalance) {
        owner = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    string getOwner() const {
        return owner;
    }
};

// Inheritance – Reusing code by creating specialized classes
// SavingsAccount inherits from Account
// Reuses deposit/withdraw logic
// Adds specialized behavior (interest)
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string name, double balance, double rate) : Account(name, balance), interestRate(rate) {}

    void addInterest() {
        deposit(getBalance() * interestRate);
    }
};





void printAccountInfo(const Account& acc) {
// Abstraction – Hiding internal details and exposing only essentials
//    User doesn't need to know how balance is stored or updated
//    Only cares about deposit, withdraw, and getBalance()
//    Internal logic is hidden, but essential features are exposed


    cout << "Owner: " << acc.getOwner() << "\n";
    cout << "Balance: " << acc.getBalance() << "\n";
}


//  Polymorphism – Same interface, different behavior

// Base class pointer BaseAccount* can point to derived classes
// Calls correct showAccountType() at runtime (virtual function)
// Enables flexible and extensible code


class BaseAccount {
public:
    virtual void showAccountType() {
        cout << "Base Account\n";
    }
    virtual ~BaseAccount() {}
};

class CheckingAccount : public BaseAccount {
public:
    void showAccountType() override {
        cout << "Checking Account\n";
    }
};

class BusinessAccount : public BaseAccount {
public:
    void showAccountType() override {
        cout << "Business Account\n";
    }
};

void displayType(BaseAccount* acc) {
    acc->showAccountType();
}





int main(){
    Account a1("Rushi",199);
    printAccountInfo(a1);
    return 0;
}