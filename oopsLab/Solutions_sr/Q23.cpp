#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    string name;
    int acc_no;
    double bal;

public:
    SavingsAccount();
    SavingsAccount(string name, int acc_no, double bal);
    void withdraw(double);
    void deposit(double);
    double annualInterest(double);
};

SavingsAccount::SavingsAccount()
{
    name = "";
    acc_no = 0;
    bal = 0.0;
}

SavingsAccount::SavingsAccount(string name, int acc_no, double bal)
{
    this->name = name;
    this->acc_no = acc_no;
    this->bal = bal;
}

void SavingsAccount::withdraw(double amt)
{
    if (this->bal - amt < 1000)
    {
        cout << "Withdrawal not possible due to insufficient minimum balance\n";
        return;
    }
    this->bal -= amt;
    cout << "Withdrawal from A/C " << this->acc_no << " successful: Rs " << amt << "\n";
}

void SavingsAccount::deposit(double amt)
{
    this->bal += amt;
    cout << "Deposit in A/C " << this->acc_no << " successful: Rs " << amt << "\n";
}

double SavingsAccount::annualInterest(double rate)
{
    double interest = this->bal * rate / 100.0;
    return interest;
}

int main()
{
    const int no_of_accs = 100;

    SavingsAccount savac[no_of_accs];
    for (int i = 0; i < no_of_accs; i++)
    {
        
        string name = "Account holder " + to_string(i + 1);
        double bal = 1000.0 * (i + 1);
        savac[i] = SavingsAccount(name, i + 1, bal);
    }

    double rate;
    cout << "Enter rate of interest\n";
    cin >> rate;

    double tot_int = 0.0;

    for (int i = 0; i < no_of_accs; i++)
    {
        double interest = savac[i].annualInterest(rate);
        savac[i].deposit(interest);
        tot_int += interest;
    }
    cout << "Total interest to be paid by bank: Rs " << tot_int << "\n";
}