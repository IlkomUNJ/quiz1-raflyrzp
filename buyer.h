#ifndef BUYER_H
#define BUYER_H

#include <cstddef>
#include <string>
#include "bank_customer.h"
#include <vector>

using namespace std;

class Buyer
{
private:
    int id;
    string name;
    string address;
    string phoneNumber;
    string email;
    BankCustomer *account; // Association with BankCustomer

public:
    Buyer(int id, const std::string &name, const std::string &address,
          const std::string &phoneNumber, const std::string &email,
          BankCustomer *account0)
        : id(id),
          name(name),
          address(address),
          phoneNumber(phoneNumber),
          email(email),
          account(account0) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getEmail() const { return email; }
    BankCustomer *getAccount() { return account; }

    void setId(int newId) { id = newId; }
    void setName(const std::string &newName) { name = newName; }
    void setAddress(const std::string &newAddress) { address = newAddress; }
    void setPhoneNumber(const std::string &newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const std::string &newEmail) { email = newEmail; }

    static Buyer *createBuyer(std::vector<Buyer *> &allUsers, int &nextUserId)
    {
        std::string name, address, phoneNumber, email;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Address: ";
        std::getline(std::cin, address);
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);
        std::cout << "Enter Email: ";
        std::getline(std::cin, email);

        BankCustomer *newAccount = new BankCustomer(nextUserId, name, 0.0);

        Buyer *newBuyer = new Buyer(nextUserId, name, address, phoneNumber, email, newAccount);

        allUsers.push_back(newBuyer);

        nextUserId++;

        return newBuyer;
    }
};

inline void checkAccountStatus(Buyer *buyer)
{
    if (!buyer)
    {
        cout << "No buyer is currently logged in!" << endl;
        return;
    }

    cout << "ACCOUNT STATUS" << endl;
    cout << "Buyer ID   : " << buyer->getId() << endl;
    cout << "Name       : " << buyer->getName() << endl;
    cout << "Address    : " << buyer->getAddress() << endl;
    cout << "Phone      : " << buyer->getPhoneNumber() << endl;
    cout << "Email      : " << buyer->getEmail() << endl;

    BankCustomer *acc = buyer->getAccount();
    if (acc)
    {
        cout << "\nBank Account Linked" << endl;
        cout << "Bank ID    : " << acc->getId() << endl;
        cout << "Owner Name : " << acc->getName() << endl;
        cout << "Balance    : Rp " << acc->getBalance() << endl;
    }
    else
    {
        cout << "\n(No bank account linked yet)" << endl;
    }
}

inline void createBankAccount(Buyer *buyer)
{
    if (!buyer)
    {
        cout << "No buyer is currently logged in!" << endl;
        return;
    }

    if (buyer->getAccount())
    {
        cout << "Bank account already exists for this buyer!" << endl;
        return;
    }

    double initialBalance;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankCustomer *newAcc = new BankCustomer(buyer->getId(), buyer->getName(), initialBalance);

    cout << "Bank account created successfully!" << endl;
    cout << "Bank ID    : " << newAcc->getId() << endl;
    cout << "Owner Name : " << newAcc->getName() << endl;
    cout << "Balance    : Rp " << newAcc->getBalance() << endl;
}

inline void upgradeToSeller(Buyer *buyer)
{
    if (!buyer)
    {
        cout << "No buyer is currently logged in!" << endl;
        return;
    }

    BankCustomer *acc = buyer->getAccount();
    if (!acc)
    {
        cout << "You must create a bank account first before upgrading to Seller!" << endl;
        return;
    }

    string shopName, shopAddress;
    cout << "Enter Shop Name: ";
    cin.ignore();
    getline(cin, shopName);
    cout << "Enter Shop Address: ";
    getline(cin, shopAddress);

    cout << "\nSELLER ACCOUNT CREATED" << endl;
    cout << "Buyer ID     : " << buyer->getId() << endl;
    cout << "Owner Name   : " << buyer->getName() << endl;
    cout << "Shop Name    : " << shopName << endl;
    cout << "Shop Address : " << shopAddress << endl;
    cout << "Bank Linked  : " << acc->getName()
         << " (Balance: Rp " << acc->getBalance() << ")" << endl;
}

#endif // BUYER_H