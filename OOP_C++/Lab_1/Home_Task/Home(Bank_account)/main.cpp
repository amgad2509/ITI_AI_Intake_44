#include <iostream>
#include <string.h>

using namespace std;


class BankAccount {
private:
    char accountHolder[50];
    int balance;
    char id[10];  // Account ID
    char name[50];  // Account Name

public:
    // Setter method for initializing the account ID
    void setId(char* accountId) {
        strcpy(id, accountId);
    }

    // Getter method for retrieving the account ID
    char* getId(){
        return id;
    }

    // Setter method for initializing the account name
    void setName(char* accountName) {
        strcpy(name, accountName);
    }

    // Getter method for retrieving the account name
    const char* getName(){
        return name;
    }

    // Setter method for initializing the account holder
    void setHolder(const char* holder) {
        strcpy(accountHolder, holder);
    }

    // Getter method for retrieving the account holder
    char* getHolder(){
        return accountHolder;
    }

    // Setter method for initializing the account balance
    void setBalance(int initialBalance) {
        balance = initialBalance;
    }

    // Getter method for retrieving the account balance
    int getBalance(){
        return balance;
    }

    //Deposit funds into the account
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw funds from the account
    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << ". New balance: $" << balance << endl;
        } else if (balance < amount) {
            cout << "Insufficient balance." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    //Display account information
    void displayInfo() {
        cout << "Account ID: " << getId() << endl;
        cout << "Account Name: " << getName() << endl;
        cout << "Account Holder: " << getHolder() << endl;
        cout << "Balance: $" << getBalance() << endl;
    }
};

int main() {
    BankAccount myAccount;

    // Set account attributes using setter methods
    myAccount.setId("12345");
    myAccount.setName("Account");
    myAccount.setHolder("Amgad Shalaby");
    myAccount.setBalance(1000.0);

    // Display account information
    myAccount.displayInfo();

    // Deposit and withdraw funds
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);

    // Display updated account information
    myAccount.displayInfo();

    return 0;
}
