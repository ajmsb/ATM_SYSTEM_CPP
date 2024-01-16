#include <iostream>
#include <string>
#define log(x) cout << x << endl; // Defined a log function to use instead of cout..

/* Small ATM Project
 * This project is made Using Qt Creator IDE on Macbook.
    - Check Balance
    - Withdraw Money
    - Update Phone Number
    - Change Password
    - Show User Details
*/

using namespace std;

class Account
{
private: // private member variables
    long int m_id;
    int m_password;
    double m_balance;
    string m_name;
    string m_phone;
    double m_lastTransaction;

public:
    //Setter function
    void setData(long int id, int password, double balance, string name, string phone)
    {
        m_id = id;
        m_password = password;
        m_balance = balance;
        m_name = name;
        m_phone = phone;
    }

    //Getter functions
    long int getId() { return m_id; }
    int getPassword() { return m_password; }
    double getBalance() { return m_balance; }
    string getName() { return m_name; }
    string getPhone() { return m_phone; }

    // FUNCTION WITHDRAW MONEY
    void withDrawMoney(double amount);

    // FUNCTION UPDATE Phone NUMBER
    void updatePhoneNumber(string oldPhoneNumber, string newPhoneNumber);

    // FUNCTION CHANGE PASSWORD
    void changePassword(int oldPass, int newPass);

    // FUNCTION SHOW ACCOUNT DETAILS
    void showAccountDetails();
};

void Account::withDrawMoney(double amount)
{
    double minAmount = 10.00;

    if (amount < minAmount) {
        system("clear");
        log("❗️Minimum ammount to be withdrawn is 10€");
    } else if (amount > m_balance) {
        system("clear");
        log("❗️Insufficient balance");
        cout << "  Your Current Balance is : " << getBalance() << "€" << endl;
    } else {
        system("clear");
        m_balance = m_balance - amount;
        m_lastTransaction = amount;
        log("✅ Operation Successfull, Please collect your Money from the Machine.");
        cout << "   Your Current Balance is : " << m_balance << "€" << endl;
    }
}

void Account ::updatePhoneNumber(string oldPhoneNumber, string newPhoneNumber)
{
    if (oldPhoneNumber == m_phone) {
        m_phone = newPhoneNumber;
        system("clear");
        log("✅ Phone Number Updated successfully!");
        log("");
        cin.get();
    } else {
        cerr << "❗️Old phone Number should match the current, Please try again." << endl;
        cin.get();
    }
}

void Account::changePassword(int oldPass, int newPass)
{
    if (oldPass == m_password) {
        m_password = newPass;
        system("clear");
        log("✅ Password changed successfully!");
        log("");
        cin.get();
    } else {
        log("Old Passwords should match the current, please try again.");
        cin.get();
    }
}

void Account::showAccountDetails()
{
    cout << "Account Number: " << m_id << endl;
    cout << "Account Holder Name: " << m_name << endl;
    cout << "Account Holder Phone Number: " << m_phone << endl;
    cout << "Account Last transaction: " << m_lastTransaction << endl;
}

// USER INTERFACE

void welcomeUI(string name)
{
    log("---------BANK NORDEA----------");
    log("");
    cout << "Logged as:  " << name << endl;
    log("");
    log("MENU");
    log("");
    log("1 - Show Balance");
    log("2 - Withdraw Money");
    log("3 - Update Phone Number");
    log("4 - Change Password");
    log("5 - Show Account Details");
    log("6 - Log Off");
}

//

//////////////////////////////////////////////////////////////////////////

int main()
{
    // LOGIN Variables & Menu choices
    int userInput = 0, password;
    long int accountId;

    system("clear");

    Account u1; //Creatign User Object
    // Setting Data
    u1.setData(123456789, 1111, 9000.27, "Jalil", "0452781425"); //User Data

    do {
        // LOGIN Interface
        system("clear");
        log("---------LOGIN----------");
        log("Please Enter your credentials");
        cout << "* Account Number: ";
        cin >> accountId;
        cout << "* Password: ";
        cin >> password;
        system("clear");

        if ((accountId == u1.getId()) && (password == u1.getPassword())) {
            do {
                int oldPassword, newPassword;
                double u_amount;
                string oldPhoneNumber, newPhoneNumber;

                welcomeUI(u1.getName());
                cin >> userInput;
                system("clear");

                switch (userInput) {
                case 1:
                    log("---------Balance----------");
                    log("");
                    cout << "Logged as:  " << u1.getName() << endl;
                    log("");
                    cout << "Your Current Ballance is: " << u1.getBalance() << "€" << endl;
                    log("");
                    break;

                case 2:
                    log("---------Whitdraw Money----------");
                    log("");
                    cout << "Logged as:  " << u1.getName() << endl;
                    log("");
                    log("Enter the amount to be Withdrawn: ");
                    cin >> u_amount;

                    //FUNCTION
                    u1.withDrawMoney(u_amount);
                    break;

                case 3:
                    log("---------Update Phone Number----------");
                    log("");
                    cout << "Logged as:  " << u1.getName() << endl;
                    log("");
                    log("Old Phone Number: ");
                    cin >> oldPhoneNumber;
                    log("New Phone Number: ");
                    cin >> newPhoneNumber;
                    u1.updatePhoneNumber(oldPhoneNumber, newPhoneNumber);
                    break;

                case 4:
                    log("---------Change Password----------");
                    log("");
                    cout << "Logged as:  " << u1.getName() << endl;
                    log("");
                    log("Old password: ");
                    cin >> oldPassword;
                    log("New Password: ");
                    cin >> newPassword;
                    u1.changePassword(oldPassword, newPassword);
                    break;

                case 5:
                    log("---------Account Details----------");
                    log("");
                    u1.showAccountDetails();
                    break;

                case 6:
                    log("---------Log Off----------");
                    log("");
                    cout << "Goodbye: " << u1.getName() << endl;
                    log("");
                    exit(0);
                    break;

                default:
                    log("Invalid input, please try again ...");
                }

            } while (1);
        } else {
            log("Invalid Credentials, Please try loggin again...");
            cin.get();
        }

    } while (1);

    return 0;
}
