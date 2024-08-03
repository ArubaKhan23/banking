#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountHolderName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& name, int accNumber, double initialBalance)
        : accountHolderName(name), accountNumber(accNumber), balance(initialBalance) {}

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew: $" << amount << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient funds." << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount." << std::endl;
        }
    }

    // Method to get current balance
    double getBalance() const {
        return balance;
    }

    // Method to display account information
    void displayAccountInfo() const {
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    // Method to get account number
    int getAccountNumber() const {
        return accountNumber;
    }
};

void createAccount(std::vector<BankAccount>& accounts) {
    std::string name;
    int accNumber;
    double initialBalance;

    std::cout << "Enter account holder's name: ";
    std::cin.ignore(); // To ignore any leftover newline character
    std::getline(std::cin, name);
    std::cout << "Enter account number: ";
    std::cin >> accNumber;
    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;

    BankAccount newAccount(name, accNumber, initialBalance);
    accounts.push_back(newAccount);
    std::cout << "Account created successfully!" << std::endl;
}

BankAccount* findAccount(std::vector<BankAccount>& accounts, int accNumber) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accNumber) {
            return &account;
        }
    }
    return nullptr;
}

void depositMoney(std::vector<BankAccount>& accounts) {
    int accNumber;
    double amount;

    std::cout << "Enter account number: ";
    std::cin >> accNumber;
    BankAccount* account = findAccount(accounts, accNumber);
    if (account) {
        std::cout << "Enter deposit amount: ";
        std::cin >> amount;
        account->deposit(amount);
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void withdrawMoney(std::vector<BankAccount>& accounts) {
    int accNumber;
    double amount;

    std::cout << "Enter account number: ";
    std::cin >> accNumber;
    BankAccount* account = findAccount(accounts, accNumber);
    if (account) {
        std::cout << "Enter withdrawal amount: ";
        std::cin >> amount;
        account->withdraw(amount);
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void checkBalance(std::vector<BankAccount>& accounts) {
    int accNumber;

    std::cout << "Enter account number: ";
    std::cin >> accNumber;
    BankAccount* account = findAccount(accounts, accNumber);
    if (account) {
        std::cout << "Current balance: $" << account->getBalance() << std::endl;
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void displayAccountInfo(std::vector<BankAccount>& accounts) {
    int accNumber;

    std::cout << "Enter account number: ";
    std::cin >> accNumber;
    BankAccount* account = findAccount(accounts, accNumber);
    if (account) {
        account->displayAccountInfo();
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void showMenu() {
    std::cout << "1. Create a new account" << std::endl;
    std::cout << "2. Deposit money" << std::endl;
    std::cout << "3. Withdraw money" << std::endl;
    std::cout << "4. Check balance" << std::endl;
    std::cout << "5. Display account information" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

int main() {
    std::vector<BankAccount> accounts;
    int choice;

    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                depositMoney(accounts);
                break;
            case 3:
                withdrawMoney(accounts);
                break;
            case 4:
                checkBalance(accounts);
                break;
            case 5:
                displayAccountInfo(accounts);
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;

    } while (choice != 6);

    return 0;
}

