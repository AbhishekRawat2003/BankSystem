#include <iostream>
#include <vector>
using namespace std;
#include <fstream>
#include <iomanip>
typedef double d;
class BankAccount
{
private:
    int accountNumber;
    string holderName;
    string accountType;
    d balance;
    string pin;

public:
    BankAccount() {}
    BankAccount(int accNo, string name, string type, d bal, string usePin)
    {
        accountNumber = accNo;
        holderName = name;
        accountType = type;
        balance = bal;
        pin = usePin;
    }
    int getAccountNumber() const
    {
        return accountNumber;
    }
    string getHolderName() const
    {
        return holderName;
    }
    d getBalance() const
    {
        return balance;
    }
    bool verifyPin(string enteredPin)
    {
        return pin == enteredPin;
    }
    void deposit(d amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount Deposited Successfully!" << endl;
        }
        else
        {
            cout << "Invlaid Deposit Amount!" << endl;
        }
    }
    void withdraw(d amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid Withdrawal Amount!" << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient Balance!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful!" << endl;
        }
    }
    void displayAccount() const
    {
        cout << "\n==================================" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Holder Name    : " << holderName << endl;
        cout << "Account Type   : " << accountType << endl;
        cout << "Balance         : Rs. " << fixed << setprecision(2) << balance << endl;
        cout << "==================================" << endl;
    }

    string serialize() const
    {
        return to_string(accountNumber) + "," + holderName + "," +
               accountType + "," + to_string(balance) + "," + pin;
    }
};
class BankSystem
{
private:
    vector<BankAccount> accounts;

public:
    void createAccount()
    {
        int accNo;
        string name, type, pin;
        d initialBalance;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        for (auto &acc : accounts)
        {
            if (acc.getAccountNumber() == accNo)
            {
                cout << "Account Already Exists!" << endl;
                return;
            }
        }
        cin.ignore();

        cout << "Enter Holder name: ";
        getline(cin, name);

        cout << "Enter Account Type (SAVING/CURRENT)";
        getline(cin, type);

        cout << ("Enter initial Balance: Rs. ");
        cin >> initialBalance;

        cout << "Set 4-digits PIN: ";
        cin >> pin;

        BankAccount newAccount(accNo, name, type, initialBalance, pin);
        accounts.push_back(newAccount);
        cout << "\n ==< Account Created Successfully >==" << endl;
    }
    BankAccount *findAccount(int accNo)
    {
        for (auto &acc : accounts)
        {
            if (acc.getAccountNumber() == accNo)
            {
                return &acc;
            }
        }
        return nullptr;
    }
    void depositMoney()
    {
        int accNo;
        d amount;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        BankAccount *acc = findAccount(accNo);

        if (acc == nullptr)
        {
            cout << "Account Not Found!" << endl;
            return;
        }

        cout << "Enter Amount to Deposit: Rs. ";
        cin >> amount;

        acc->deposit(amount);
    }

    void withdrawMoney()
    {
        int accNo;
        d amount;
        string enteredPin;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        BankAccount *acc = findAccount(accNo);

        if (acc == nullptr)
        {
            cout << "Account Not Found!" << endl;
            return;
        }

        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (!acc->verifyPin(enteredPin))
        {
            cout << "Incorrect PIN!" << endl;
            return;
        }

        cout << "Enter Withdrawal Amount: Rs. ";
        cin >> amount;

        acc->withdraw(amount);
    }

    void checkBalance()
    {
        int accNo;
        string enteredPin;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        BankAccount *acc = findAccount(accNo);

        if (acc == nullptr)
        {
            cout << "Account Not Found!" << endl;
            return;
        }

        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (!acc->verifyPin(enteredPin))
        {
            cout << "Incorrect PIN!" << endl;
            return;
        }

        cout << "\nCurrent Balance: Rs. " << fixed << setprecision(2)
             << acc->getBalance() << endl;
    }

    void displayAccountDetails()
    {
        int accNo;
        string enteredPin;

        cout << "\nEnter Account Number: ";
        cin >> accNo;

        BankAccount *acc = findAccount(accNo);

        if (acc == nullptr)
        {
            cout << "Account Not Found!" << endl;
            return;
        }

        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (!acc->verifyPin(enteredPin))
        {
            cout << "Incorrect PIN!" << endl;
            return;
        }

        acc->displayAccount();
    }

    void transferMoney()
    {
        int senderAccNo, receiverAccNo;
        d amount;
        string enteredPin;

        cout << "\nEnter Sender Account Number: ";
        cin >> senderAccNo;

        BankAccount *sender = findAccount(senderAccNo);

        if (sender == nullptr)
        {
            cout << "Sender Account Not Found!" << endl;
            return;
        }

        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (!sender->verifyPin(enteredPin))
        {
            cout << "Incorrect PIN!" << endl;
            return;
        }

        cout << "Enter Receiver Account Number: ";
        cin >> receiverAccNo;

        BankAccount *receiver = findAccount(receiverAccNo);

        if (receiver == nullptr)
        {
            cout << "Receiver Account Not Found!" << endl;
            return;
        }

        cout << "Enter Transfer Amount: Rs. ";
        cin >> amount;

        if (amount <= sender->getBalance())
        {
            sender->withdraw(amount);
            receiver->deposit(amount);
            cout << "Money Transfer Successful!" << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void saveAccountsToFile()
    {
        ofstream file("bank_data.txt");

        for (const auto &acc : accounts)
        {
            file << acc.serialize() << endl;
        }

        file.close();

        cout << "Data Saved Successfully!" << endl;
    }

    void showAllAccounts()
    {
        if (accounts.empty())
        {
            cout << "\nNo Accounts Available!" << endl;
            return;
        }

        cout << "\n========== ALL ACCOUNTS ==========" << endl;

        for (const auto &acc : accounts)
        {
            acc.displayAccount();
        }
    }
};
void Menu()
{
    cout << "\n== WELCOME TO DEVBHOOMI BANK == " << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Display Account Details" << endl;
    cout << "6. Transfer Money" << endl;
    cout << "7. Show All Accounts" << endl;
    cout << "8. Save Data" << endl;
    cout << "9. Exit" << endl;
    cout << "============================================" << endl;
    cout << "Enter Your Choice: ";
}
int main()
{
    BankSystem bank;
    int choice;
    do
    {
        Menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.depositMoney();
            break;

        case 3:
            bank.withdrawMoney();
            break;

        case 4:
            bank.checkBalance();
            break;

        case 5:
            bank.displayAccountDetails();
            break;

        case 6:
            bank.transferMoney();
            break;

        case 7:
            bank.showAllAccounts();
            break;

        case 8:
            bank.saveAccountsToFile();
            break;

        case 9:
            cout << "\nThank You for Using Bank System!" << endl;
            break;
        default:
            cout << "Invalid Choice! Try Again." << endl;
        }
    } while (choice != 9);
    return 0;
}