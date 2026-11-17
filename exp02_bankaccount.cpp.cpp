// Experiment 2: Class hierarchy, access specifiers, member functions (BankAccount)
#include <iostream>
#include <string>
using namespace std;

class Account {
private:                     // accessible only inside Account
    double balance;
protected:                   // accessible in Account and derived classes
    string owner;
    int accNo;
public:                      // accessible everywhere
    Account(int no, string name, double bal) : balance(bal), owner(name), accNo(no) {}
    virtual ~Account() {}
    void deposit(double amt) {
        if (amt <= 0) { cout << "Invalid amount\n"; return; }
        balance += amt;
    }
    bool withdraw(double amt) {
        if (amt <= 0 || amt > balance) { cout << "Withdrawal failed\n"; return false; }
        balance -= amt; return true;
    }
    double getBalance() const { return balance; }
    virtual void display() const {
        cout << "Acc#" << accNo << " | " << owner << " | Balance: " << balance << "\n";
    }
};

class SavingsAccount : public Account {
    double rate;
public:
    SavingsAccount(int no, string n, double bal, double r) : Account(no, n, bal), rate(r) {}
    void addInterest() { deposit(getBalance() * rate / 100); }
    void display() const override {
        cout << "[Savings] "; Account::display();
        cout << "  Owner (protected, accessed in derived): " << owner << ", rate " << rate << "%\n";
    }
};

class CurrentAccount : public Account {
    double overdraft;
public:
    CurrentAccount(int no, string n, double bal, double od) : Account(no, n, bal), overdraft(od) {}
    void display() const override {
        cout << "[Current] "; Account::display();
        cout << "  Overdraft limit: " << overdraft << "\n";
    }
};

int main() {
    SavingsAccount s(101, "Asha", 5000, 4.5);
    CurrentAccount c(202, "Ravi", 10000, 2000);
    s.deposit(1500); s.withdraw(500); s.addInterest();
    c.withdraw(20000);   // fails
    c.deposit(250);
    s.display(); c.display();
    // s.balance = 1;   // ERROR: balance is private
    return 0;
}
