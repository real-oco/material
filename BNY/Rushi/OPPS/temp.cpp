#include <bits/stdc++.h>
using namespace std;

class Account {
private:
//encapsulation
int balance;
string name;
public:
Account(int balance ,string name){
this->balance=balance;
this->name=name;
}
void getBalance(){
    cout<<"balance is : "<<balance<<endl;
}
void updateBalance(int val){
if(val+balance>=0){
    balance+=val;
}
}
//abstraction
void getAccountInfo(Account a){
    cout<<a.getBalance()<<endl;
}
};

//inheritance
class SavingsAccount : public Account{
private: 
int interestRate;
public:
SavingsAccount(int balance , string name , int interestRate):Account(balance,name){
this->interestRate=interestRate;
}
};


int main(){
    
    return 0;
}