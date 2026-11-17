// Experiment 9: Custom exception hierarchy for a banking transaction scenario
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class BankException : public exception {
protected:
    string msg;
public:
    explicit BankException(string m) : msg(move(m)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};
class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException(double bal, double req)
        : BankException("Insufficient funds: balance " + to_string(bal) + ", requested " + to_string(req)) {}
};
class InvalidAmountException : public BankException {
public:
    explicit InvalidAmountException(double a) : BankException("Invalid amount: " + to_string(a)) {}
};
class AccountLockedException : public BankException {
public:
    AccountLockedException() : BankException("Account is locked") {}
};

class Account {
    double balance; bool locked;
public:
    Account(double b, bool l = false) : balance(b), locked(l) {}
    void withdraw(double amt) {
        if (locked) throw AccountLockedException();
        if (amt <= 0) throw InvalidAmountException(amt);
        if (amt > balance) throw InsufficientFundsException(balance, amt);
        balance -= amt;
        cout << "Withdrew " << amt << ", new balance " << balance << "\n";
    }
};

int main() {
    Account acc(1000), locked(500, true);
    try { acc.withdraw(300); acc.withdraw(-50); }
    catch (const InvalidAmountException& e) { cout << "[InvalidAmount] " << e.what() << "\n"; }
    try { acc.withdraw(5000); }
    catch (const InsufficientFundsException& e) { cout << "[Insufficient] " << e.what() << "\n"; }
    try { locked.withdraw(10); }
    catch (const BankException& e) { cout << "[BankException base] " << e.what() << "\n"; }  // base catches derived
    catch (...) { cout << "Unknown error\n"; }
    return 0;
}
