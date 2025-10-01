#include <iostream>
#include "bank_customer.h"
#include "buyer.h"

enum PrimaryPrompt
{
    LOGIN,
    REGISTER,
    EXIT
};
enum RegisterPrompt
{
    CREATE_BUYER,
    CREATE_SELLER,
    BACK
};
enum LoginPrompt
{
    CHECK_ACCOUNT_STATUS,
    UPGRADE_TO_SELLER,
    CREATE_BANK_ACCOUNT,
    BROWSE_STORE,
    ORDER_FUNCTIONALITY,
    PAYMENT_FUNCTIONALITY,
    LOGOUT,
    DELETE_ACCOUNT,
    EXIT_TO_MAIN_MENU,
    EXIT_PROGRAM
};

using namespace std;

int main()
{
    vector<Buyer *> allUsers;
    int nextUserId = 1;
    Buyer *currentBuyer = nullptr;

    // create a loop prompt
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;
    LoginPrompt loginPrompt = CHECK_ACCOUNT_STATUS;
    while (prompt != EXIT)
    {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);
        switch (prompt)
        {
        case LOGIN:
            cout << "Login selected." << endl;
            cout << "Select an option: " << endl;
            cout << "1. Check Account Status" << endl;
            cout << "2. Upgrade Account to Seller" << endl;
            cout << "3. Create Banking Account" << endl;
            cout << "4. Browse Store Functionality" << endl;
            cout << "5. Order Functionality" << endl;
            cout << "6. Payment Functionality" << endl;
            cout << "7. Logout" << endl;
            cout << "8. Delete Account" << endl;
            cout << "9. Exit to main Menu" << endl;
            cout << "10. Exit Program" << endl;
            int loginChoice;
            cin >> loginChoice;
            loginPrompt = static_cast<LoginPrompt>(loginChoice - 1);
            switch (loginPrompt)
            {
            case CHECK_ACCOUNT_STATUS:
                if (!allUsers.empty())
                {
                    checkAccountStatus(allUsers[0]);
                }
                else
                {
                    cout << "No users registered yet." << endl;
                }
                break;
            case UPGRADE_TO_SELLER:
                cout << "Upgrade Account to Seller selected." << endl;
                upgradeToSeller(currentBuyer);
                break;
            case CREATE_BANK_ACCOUNT:
                if (!allUsers.empty())
                {
                    currentBuyer = allUsers[0];
                    createBankAccount(currentBuyer);
                }
                else
                {
                    cout << "No users registered yet." << endl;
                }
                createBankAccount(currentBuyer);
                break;
            case BROWSE_STORE:
                cout << "Browse Store Functionality selected." << endl;
                break;
            case ORDER_FUNCTIONALITY:
                cout << "Order Functionality selected." << endl;
                break;
            case PAYMENT_FUNCTIONALITY:
                cout << "Payment Functionality selected." << endl;
                break;
            case LOGOUT:
                cout << "Logout selected." << endl;
                break;
            case DELETE_ACCOUNT:
                cout << "Delete Account selected." << endl;
                break;
            case EXIT_TO_MAIN_MENU:
                cout << "Exit to main Menu selected." << endl;
                break;
            case EXIT_PROGRAM:
                cout << "Exit Program selected." << endl;
                prompt = EXIT;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
            /* if Login is selected, based on authority then provide options:
            assume user is logged in as Buyer for now
            1. Chek Account Status (will display if user is Buyer or Seller or both and linked banking account status)
            Will display Buyer, Seller and Banking Account details
            2. Upgrade Account to Seller
            Will prompt user to enter Seller details and create a Seller account linked to Buyer account
            Will reject if a user dont have a banking account linked
            3. Create Banking Account (if not already linked), will be replaced with banking functions
            Must provides: initial deposit amount, Address, Phone number, Email
            Banking functions will provides: Balance checking, Transaction History, Deposit, Withdraw
            4. Browse Store Functionality
            Will display all stores initially
            Need to select a store to browse each store inventory
            Will display all items in the store inventory
            After selecting an item, will display item details and option to add to cart
            After adding to cart, will notify user item is added to cart
            5. Order Functionality
            Will display all items in cart
            Will provide option to remove item from cart
            Will provide option to checkout
            After checkout invoide will be generated (will go to payment functionality)
            6. Payment Functionality
            Will display all listed invoices
            Pick an invoice to pay
            Will display invoice details and total amount
            Will provide option to pay invoice
            Payment is done through confirmation dialogue
            In confirmation dialogue, will display account balance as precursor
            User will need to manually enter invoice id to pay
            After paying balance will be redacted from buyer and added to the responding seller account
            After payment, order status will be changed to paid
            7. Logout (return to main menu)
            Display confirmation dialogue
            If confirmed, return to main menu
            If not, return to Buyer menu
            8. Delete Account (remove both Buyer and Seller account and relevant banking account)
            Display confirmation dialogue
            If confirmed, delete account and return to main menu
            If not, return to Buyer menu
            assume user is logged in as Seller for now
            9. Check Inventory
            10. Add Item to Inventory
            11. Remove Item from Inventory
            12. View Orders (will display all orders placed to this seller
            Only orders with paid status will be listed
            Order details will listing items, quantity, total amount, buyer details, order status (paid, cancelled, completed)
            extra functions
            9. Exit to main Menu
            10. Exit Program
            **/
            break;
        case REGISTER:
            cout << "Register selected." << endl;
            cout << "Select an option: " << endl;
            cout << "1. Create Buyer Account" << endl;
            cout << "2. Create Seller Account" << endl;
            cout << "3. Back" << endl;
            int regChoice;
            cin >> regChoice;
            regPrompt = static_cast<RegisterPrompt>(regChoice - 1);
            switch (regPrompt)
            {
            case CREATE_BUYER:
            {
                std::cout << "Create Buyer Account selected." << std::endl;
                Buyer *newBuyer = Buyer::createBuyer(allUsers, nextUserId);
                std::cout << "Buyer account created successfully! Welcome, "
                          << newBuyer->getName() << "!" << std::endl;
                break;
            }
            case CREATE_SELLER:
                cout << "Create Seller Account selected." << endl;
                /* Create a new Seller Account
                Must provides: Store Name, Store Address, Store Phone number, Store Email
                After finished immediately logged in as Seller
                */
                break;
            case BACK:
                cout << "Back selected." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
            }
            /* if register is selected then went throuhh registration process:
            1. Create a new Buyer Account
            Must provides: Name, Home Address, Phone number, Email
            2. Option to create a Seller Account (will be linked to Buyer account)
            Must provides: Store Name, Store Address, Store Phone number, Store Email
            After finished immediately logged in as Buyer/Seller
            */
            break;
        case EXIT:
            cout << "Exiting." << std::endl;
            break;
        default:
            cout << "Invalid option." << endl;
            break;
        }
        cout << endl;
    }

    // BankCustomer customer1(1, "Alice", 1000.0);
    // Buyer buyer1(1, customer1.getName(), customer1);
    return 1;
}