#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string number, string holder, double initialBalance)
    {
        accountNumber = number;
        accountHolderName = holder;
        setBalance(initialBalance);
    }

    void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
    }

    bool withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const
    {
        return balance;
    }

    string getAccountSummary() const
    {
        return accountHolderName + " | Account: " + accountNumber;
    }

private:
    void setBalance(double amount)
    {
        balance = amount >= 0 ? amount : 0;
    }
};

int main()
{
    BankAccount account("PK102938", "Ahmad Azad", 10000);

    account.deposit(2500);
    account.withdraw(4000);

    cout << account.getAccountSummary() << "\n";
    cout << "Balance: " << account.getBalance() << "\n";

    return 0;
}
