#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Password {
private:
    int code = 17092025;

public:
    int getPassword() {
        return code;
    }
};

class Balance {
public:
    double amount = 5000;
};

Balance money;
double debt = 0;

void deposit();
void withdraw();
void balance();
void credit_acc();
void personal_acc();
void select_acc();
void borrow_money();
void pay_debt();

void select_acc() {
    int choose;

    cout << "==============================" << endl;
    cout << "---- 1. Personal Account ----" << endl;
    cout << "---- 2. Credit Accounts ----" << endl;
    cout << "---- 3. Exit ----" << endl;
    cout << "==============================" << "\n\n";
    cin >> choose;
    cout << endl;

    if (choose == 1) {
        system("cls");
        personal_acc();
    }
    else if (choose == 2) {
        system("cls");
        credit_acc();
    }
    else if (choose == 3) {
        exit(0);
    }
}

void personal_acc() {
    int choose;

    cout << "==============================" << endl;
    cout << "---- 1. Balance ----" << endl;
    cout << "---- 2. Deposit Money ----" << endl;
    cout << "---- 3. Withdraw Money ----" << endl;
    cout << "---- 4. Go Back ----" << endl;
    cout << "==============================" << "\n\n";
    cin >> choose;
    cout << endl;

    if (choose == 1) {
        system("cls");
        balance();
    }

    else if (choose == 2) {
        system("cls");
        deposit();
    }

    else if (choose == 3) {
        system("cls");
        withdraw();
    }

    else if (choose == 4) {
        system("cls");
        select_acc();
    }
}

void credit_acc() {
    int choose;

    cout << "==============================" << endl;
    cout << "---- 1. Borrow money ----" << endl;
    cout << "---- 2. Pay debt ----" << endl;
    cout << "---- 3. Go Back ----" << endl;
    cout << "==============================" << "\n\n";
    cin >> choose;
    cout << endl;

    if (choose == 1) {
        system("cls");
        borrow_money();
    }
    else if (choose == 2) {
        system("cls");
        pay_debt();
    }
    else if (choose == 3) {
        system("cls");
        select_acc();
    }
}

void borrow_money() {
    int draw;
    string back;

    cout << "==============================" << endl;
    cout << "---- Personal Balance: " << money.amount << "$ ----" << endl;
    cout << "---- Current Debt: " << debt << "$ ----" << endl;
    cout << "==============================" << "\n\n";

    cout << "How much money would you like to borrow: ";
    cin >> draw;
    cout << endl;

    if (draw > money.amount) {
        cout << "Not enough personal balance to borrow that much!" << endl;
    }
    else {
        money.amount += draw;
        debt += draw;
        debt *= 2;
        cout << "You borrowed: " << draw << "$" << endl;
    }

    cout << "Type 'back' to go back: ";
    cin >> back;
    if (back == "back") {
        system("cls");
        credit_acc();
    }
}

void pay_debt() {
    int draw;
    string back;

    cout << "==============================" << endl;
    cout << "---- Current Debt: " << debt << "$ ----" << endl;
    cout << "---- Personal Balance: " << money.amount << "$ ----" << endl;
    cout << "==============================" << "\n\n";

    cout << "How much money would you like to pay: ";
    cin >> draw;
    cout << endl;

    if (draw > money.amount) {
        cout << "Not enough money to pay that much!" << endl;
    }
    else if (draw > debt) {
        cout << "You only need to pay " << debt << "$. Paying full debt." << endl;
        money.amount -= debt;
        debt = 0;
    } else {
        money.amount -= draw;
        debt -= draw;
        cout << "You paid: " << draw << "$" << endl;
    }

    cout << "Type 'back' to go back: ";
    cin >> back;
    if (back == "back") {
        system("cls");
        credit_acc();
    }
}

void balance() {
    string back;

    cout << "==============================" << endl;
    cout << "---- Balance: " << money.amount << "$ ----" << endl;
    cout << "==============================" << "\n\n";

    cout << "Type 'back' to go back: ";
    cin >> back;

    if (back == "back") {
        system("cls");
        personal_acc();
    } 
}

void deposit() {
    int draw;
    string back;

    cout << "==============================" << endl;
    cout << "---- Balance: " << money.amount << "$ ----" << endl;
    cout << "==============================" << "\n\n";

    cout << "How much money would you like to deposit: ";
    cin >> draw;
    cout << endl;

    money.amount += draw;

    cout << "==============================" << endl;
    cout << "---- New Balance: " << money.amount << "$ ----" << endl;
    cout << "==============================" << "\n\n";

    cout << "Type 'back' to go back: ";
    cin >> back;
    cout << endl;

    if (back == "back") {
        system("cls");
        personal_acc();
    }
}

void withdraw() {
    int draw;
    string back;

    cout << "==============================" << endl;
    cout << "---- Balance: " << money.amount << "$ ----" << endl;
    cout << "==============================" << "\n\n";

    cout << "How much money would you like to withdraw: ";
    cin >> draw;
    cout << endl;

    if (draw > money.amount) {
        cout << "Not enough money!" << endl;
    } else {
        money.amount -= draw;
    }

    cout << "==============================" << endl;
    cout << "---- New Balance: " << money.amount << "$ ----" << endl;
    cout << "==============================" << "\n\n";

    cout << "Type 'back' to go back: ";
    cin >> back;
    cout << endl;

    if (back == "back") {
        system("cls");
        personal_acc();
    }
}

int main() {
    Password password;
    int checkPass;

    while (true) {
        cout << "Type password: "; 
        cin >> checkPass;
        cout << endl;

        if (checkPass != password.getPassword()) {
            cout << "Wrong password. Try again!" << "\n\n";
        } else {
            system("cls");
            select_acc();
            break;
            
            return 0;
        }
    }
}
