#include <iostream>
using namespace std;

class ATM {
private:
    double balance;
    string pin;

public:
    ATM(double init_balance, string init_pin) {
        balance = init_balance;
        pin = init_pin;
    }

    bool checkPIN(string input_pin) {
        return input_pin == pin;
    }

    void displayBalance() const {
        cout << "Current balance: $" << balance << endl;
    }

    void addFunds(double amount) {
        if (amount > 0)
        {
            balance += amount;
            cout << "$" << amount << " has been deposited." << endl;
        }
        else
        {
            cout << "Please enter a valid amount." << endl;
        }
    }

    void withdrawFunds(double amount) {
        if (amount <= 0) 
        {
            cout << "Enter a valid withdrawal amount." << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds. Your current balance is $" << balance << "." << endl;
        }
        else 
        {
            balance -= amount;
            cout << "$" << amount << " has been withdrawn." << endl;
        }
    }

    void showOptions() const {
        cout << "\nATM Options:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
    }
};

int main() {
    ATM atm(1000.00, "4321");  
    string entered_pin;
    int option;
    double amount;

    cout << "Welcome to your ATM!" << endl;

    
    cout << "Enter your PIN: ";
    cin >> entered_pin;

    if (!atm.checkPIN(entered_pin)) {
        cout << "Incorrect PIN. Exiting..." << endl;
        return 0;
    }

   
    do {
        atm.showOptions();
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
        case 1:
            atm.displayBalance();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            atm.addFunds(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            atm.withdrawFunds(amount);
            break;
        case 4:
            cout << "Thank you for using the ATM. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }

    } while (option != 4);

    return 0;
}
