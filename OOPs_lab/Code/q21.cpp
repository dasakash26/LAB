#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

#define INTEREST 0.05

int id = 0;

class SavingsAccount
{
public:
    int id;
    double balance;
    char name[30];

    SavingsAccount() : id(0), balance(0.0)
    {
        name[0] = '\0';
    }
};

SavingsAccount createAccount(const char *name, double balance)
{
    SavingsAccount account;
    account.id = ++id;
    strcpy(account.name, name);
    if (balance < 1000)
    {
        cout << "Minimum balance should be 1000\n";
        return createAccount(name, 1000);
    }
    account.balance = balance;
    return account;
}

void deposit(SavingsAccount *account, double amount)
{
    account->balance += amount;
    cout << "Amount deposited successfully\n";
}

void withdraw(SavingsAccount *account, double amount)
{
    if (account->balance - amount < 1000)
    {
        cout << "Insufficient balance\n";
        return;
    }
    account->balance -= amount;
    cout << "Amount withdrawn successfully\n";
}

int main()
{
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;
    
    SavingsAccount *accounts = new SavingsAccount[n];
    srand(static_cast<unsigned>(time(nullptr)));
    
    double totalInterest = 0;
    for (int i = 0; i < n; i++)
    {
        double balance = (rand() % (100000 - 1000)) + 1000;
        char name[30];
        sprintf(name, "Account %d", i + 1);
        accounts[i] = createAccount(name, balance);
        double interest = accounts[i].balance * INTEREST;
        totalInterest += interest;
        accounts[i].balance += interest;
        cout << "Interest to " << accounts[i].name << " is: " << interest << "\n";
    }
    cout << "Total interest: " << totalInterest << "\n";

    delete[] accounts;  // Free dynamically allocated memory
    return 0;
}
