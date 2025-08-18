#include<bits/stdc++.h>

using namespace std;
class BankAccount{
    double balance;
    public:
    BankAccount(double balance=0) : balance(balance){}
    BankAccount(BankAccount& other) : balance(other.balance){}
    void showBalance() const{cout<<"Balance : "<<balance<<"$\n";}
    void deductBalance(double amount){balance = max(0.0, balance - amount);}
    friend ostream& operator<<(ostream& out, BankAccount &b);
};
ostream& operator<<(ostream& out, BankAccount &b){
    out<<b.balance;
    return out;
}
int main(){
    BankAccount account1, account2(1000);
    cout<<"Account 1"<<endl;
    account1.showBalance();
    cout<<"Account 2"<<endl;
    account2.showBalance();
    BankAccount account3(account2);
    cout<<"Account 3"<<endl;
    account3.showBalance();
    cout<<"Deducting 200$ from Account 3";
    account3.deductBalance(200);
    cout<<"Account 2 (after copying into Account 3 showing no change)"<<endl;
    account2.showBalance();
    int* ptr = new int(5);
    cout<<*ptr<<endl;
    delete ptr;
    cout<<*ptr;
    return 0;
}