// ATM Banking Program Developed by PRIYANSHU

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//===================================================================================
class Bank {
public:
    double startBalance;
    double accountBalance;
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    virtual void payBills() = 0;
    virtual void details() = 0;
    virtual void interest() = 0;
    virtual void accountExit() = 0;
};

//===================================================================================
class ATMAccountHolders : public Bank {
private:
    string accountHolders;
    string accountHoldersAddress, branch;
    int accountNumber;

public:
    ATMAccountHolders() {
        accountNumber = 5678;
        accountHolders = "PRIYANSHU, HARSH, ADITYA, MONU";
        accountHoldersAddress = "ROOM NO. 106, SADBHAVNA HOSTEL, CGC LANDRAN";
        startBalance = 30000.00;
        accountBalance = 123.00;
        branch = "MOHALI";
    }

    void deposit() override;
    void withdraw() override;
    void payBills() override;
    void details() override;
    void interest() override;
    void accountExit() override;
};

//===================================================================================
void ATMAccountHolders::deposit() {
    system("cls");
    cout << "\n====================== ATM ACCOUNT DEPOSIT SYSTEM ======================\n\n";
    cout << "Current Balance: $" << accountBalance << "\n";
    cout << "Enter the amount to deposit: $";
    double amount;
    cin >> amount;

    if (amount > 0) {
        accountBalance += amount;
        cout << "New Balance: $" << accountBalance << "\n";
    } else {
        cout << "Invalid amount entered.\n";
    }

    system("pause");
}

//===================================================================================
void ATMAccountHolders::withdraw() {
    system("cls");
    cout << "\n====================== ATM ACCOUNT WITHDRAWAL ======================\n\n";
    cout << "Current Balance: $" << accountBalance << "\n";
    cout << "Enter the amount to withdraw (Max $9000): $";
    double amount;
    cin >> amount;

    if (amount > accountBalance || amount > 9000 || amount <= 0) {
        cout << "Insufficient balance or amount exceeds limit.\n";
    } else {
        accountBalance -= amount;
        cout << "Withdrawal successful. New Balance: $" << accountBalance << "\n";
    }

    system("pause");
}

//===================================================================================
void ATMAccountHolders::payBills() {
    system("cls");
    cout << "\n====================== ATM BILL PAYMENT ======================\n\n";
    cout << "Do you want to pay $2000 for the electricity bill?\n";
    cout << "Press 1 for Yes, 0 for No: ";
    int r;
    cin >> r;

    if (r == 1) {
        if (accountBalance >= 2000) {
            accountBalance -= 2000;
            cout << "Bill paid. New Balance: $" << accountBalance << "\n";
        } else {
            cout << "Insufficient funds to pay bill.\n";
        }
    } else if (r == 0) {
        cout << "Bill payment skipped.\n";
    } else {
        cout << "Invalid choice.\n";
    }

    system("pause");
}

//===================================================================================
void ATMAccountHolders::details() {
    system("cls");
    cout << "\n====================== ATM ACCOUNT DETAILS ======================\n\n";
    cout << "Account Holders: " << accountHolders << "\n";
    cout << "Address: " << accountHoldersAddress << "\n";
    cout << "Branch: " << branch << "\n";
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Current Balance: $" << accountBalance << "\n";
    system("pause");
}

//===================================================================================
void ATMAccountHolders::interest() {
    system("cls");
    cout << "\n====================== INTEREST PAYMENT ======================\n\n";
    cout << "Annual interest rate: 10%\n";
    double interestAmount = accountBalance * 0.10 / 2; // 6 months = half year
    double totalWithInterest = accountBalance + interestAmount;

    cout << "Accumulated Interest (6 months): $" << interestAmount << "\n";
    cout << "Total Balance with Interest: $" << totalWithInterest << "\n";

    system("pause");
}

//===================================================================================
void ATMAccountHolders::accountExit() {
    system("cls");
    cout << "\n====================== EXITING ATM ======================\n\n";
    cout << "Thank you for using the ATM. Goodbye!\n\n";
    exit(0);
}

//===================================================================================
int main() {
    ATMAccountHolders account;
    system("Color 1b");

    cout << "\n============================ WELCOME TO ATM ============================\n";
    time_t now = time(0);
    cout << "\tToday's date and time: " << ctime(&now) << endl;

    int access;
    cout << "Press 1 to access your account via PIN.\n";
    cout << "Press 0 for help.\n";
    cin >> access;

    if (access == 1) {
        system("cls");
        int pin;
        cout << "\nEnter your account PIN (1 attempt allowed): ";
        cin >> pin;

        if (pin == 12345) {
            int choice;
            do {
                system("cls");
                system("Color 1a");
                cout << "\n====================== ATM MAIN MENU ======================\n";
                cout << "1. Cash Deposit\n";
                cout << "2. Cash Withdrawal\n";
                cout << "3. Balance Inquiry\n";
                cout << "4. Pay Bills\n";
                cout << "5. Interest Info\n";
                cout << "0. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1: account.deposit(); break;
                    case 2: account.withdraw(); break;
                    case 3: account.details(); break;
                    case 4: account.payBills(); break;
                    case 5: account.interest(); break;
                    case 0: account.accountExit(); break;
                    default: cout << "Invalid choice.\n"; system("pause"); break;
                }
            } while (choice != 0);
        } else {
            system("cls");
            system("Color 1c");
            cout << "Incorrect PIN entered. No further attempts allowed.\n";
            cout << "Please contact your bank representative.\n";
            exit(1);
        }
    } else {
        system("cls");
        cout << "\nYou must have the correct PIN number to access this account.\n";
        cout << "Contact your bank for assistance.\n";
        exit(1);
    }

    return 0;
}
