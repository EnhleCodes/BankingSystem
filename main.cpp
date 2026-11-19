#include <iostream>
#include <string>
using namespace std;

// Customer information
string names[3] = {"Sipho", "Naledi", "Kabelo"};
int accNo[3] = {4001, 4002, 4003};
int pinCode[3] = {1111, 2222, 3333};
double money[3] = {4000, 3000, 5000};

// Function declarations
void bankHeading();
int verifyCustomer();
void displayMenu();
int locateCustomer(int acc);
bool amountIsValid(double value);
void addFunds(int customer);
void takeFunds(int customer);
void transferFunds(int customer);
void viewAccount(int customer);

int main()
{
    int loggedInCustomer;
    int choice;

    bankHeading();

    loggedInCustomer = verifyCustomer();

    if (loggedInCustomer == -1)
    {
        cout << "Login failed. Goodbye!" << endl;
        return 0;
    }

    do
    {
        displayMenu();

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addFunds(loggedInCustomer);
                break;

            case 2:
                takeFunds(loggedInCustomer);
                break;

            case 3:
                transferFunds(loggedInCustomer);
                break;

            case 4:
                viewAccount(loggedInCustomer);
                break;

            case 5:
                cout << "Thank you for banking with EasyBank!" << endl;
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

// Bank heading
void bankHeading()
{
    cout << "=================================" << endl;
    cout << "          WELCOME TO EASYBANK    " << endl;
    cout << "=================================" << endl;
}

// Verify customer details
int verifyCustomer()
{
    int account;
    int pin;

    for (int count = 1; count <= 3; count++)
    {
        cout << endl;
        cout << "Enter account number: ";
        cin >> account;

        cout << "Enter PIN: ";
        cin >> pin;

        int customer = locateCustomer(account);

        if (customer >= 0)
        {
            if (pin == pinCode[customer])
            {
                cout << endl;
                cout << "Login successful!" << endl;
                cout << "Welcome, " << names[customer] << "!" << endl;

                return customer;
            }
        }

        cout << "Incorrect account details." << endl;
        cout << "Attempts remaining: " << 3 - count << endl;
    }

    return -1;
}

// Display banking menu
void displayMenu()
{
    cout << endl;
    cout << "========== EASYBANK ==========" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Send Cash" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Exit" << endl;
    cout << "==============================" << endl;
}

// Find customer account
int locateCustomer(int acc)
{
    for (int i = 0; i < 3; i++)
    {
        if (accNo[i] == acc)
        {
            return i;
        }
    }

    return -1;
}

// Validate transaction amount
bool amountIsValid(double value)
{
    return value > 0;
}

// Deposit money
void addFunds(int customer)
{
    double amount;

    cout << "Enter amount to deposit: R";
    cin >> amount;

    if (amountIsValid(amount))
    {
        money[customer] = money[customer] + amount;

        cout << "Deposit successful!" << endl;
        cout << "New balance: R" << money[customer] << endl;
    }
    else
    {
        cout << "Invalid deposit amount." << endl;
    }
}

// Withdraw money
void takeFunds(int customer)
{
    double amount;

    cout << "Enter amount to withdraw: R";
    cin >> amount;

    if (!amountIsValid(amount))
    {
        cout << "Invalid withdrawal amount." << endl;
    }
    else if (amount > money[customer])
    {
        cout << "Insufficient funds!" << endl;
    }
    else
    {
        money[customer] = money[customer] - amount;

        cout << "Withdrawal successful!" << endl;
        cout << "New balance: R" << money[customer] << endl;
    }
}

// Transfer money to another customer
void transferFunds(int customer)
{
    int receiverAccount;
    int receiver;
    double amount;

    cout << "Enter recipient account number: ";
    cin >> receiverAccount;

    receiver = locateCustomer(receiverAccount);

    if (receiver == -1)
    {
        cout << "Recipient account does not exist." << endl;
    }
    else if (receiver == customer)
    {
        cout << "You cannot send cash to your own account." << endl;
    }
    else
    {
        cout << "Enter amount to send: R";
        cin >> amount;

        if (!amountIsValid(amount))
        {
            cout << "Invalid amount." << endl;
        }
        else if (amount > money[customer])
        {
            cout << "Insufficient funds!" << endl;
        }
        else
        {
            money[customer] = money[customer] - amount;
            money[receiver] = money[receiver] + amount;

            cout << "Transfer successful!" << endl;
            cout << "Money sent to: " << names[receiver] << endl;
            cout << "Remaining balance: R" << money[customer] << endl;
        }
    }
}

// Display account information
void viewAccount(int customer)
{
    cout << endl;
    cout << "========== ACCOUNT DETAILS ==========" << endl;
    cout << "Account holder: " << names[customer] << endl;
    cout << "Account number: " << accNo[customer] << endl;
    cout << "Available balance: R" << money[customer] << endl;
    cout << "=====================================" << endl;
}
