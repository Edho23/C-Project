#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
public:
    Account(int accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            cout << "Saldo tidak mencukupi." << endl;
            return false;
        }
    }

private:
    int accountNumber;
    double balance;
};

class Admin {
public:
    Admin(const string& username, const string& password)
        : username(username), password(password) {}

    bool authenticate(const string& inputUsername, const string& inputPassword) const {
        return (inputUsername == username && inputPassword == password);
    }

    void viewTransactionHistory(const vector<Account>& accounts) const {
        cout << "Laporan Transaksi:" << endl;
        for (const Account& account : accounts) {
            cout << "Rekening #" << account.getAccountNumber() << " - Saldo: Rp." << account.getBalance() << endl;
        }
    }

private:
    string username;
    string password;
};

class ATM {
public:
    ATM() : admin("FAWAZ", "12345") {
        accounts.push_back(Account(12345, 1000.0));
        accounts.push_back(Account(54321, 500.0));
    }

    void displayMenu() {
        cout << "Pilih opsi:" << endl;
        cout << "1. Cek Saldo" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Tarik Tunai" << endl;
        cout << "4. Admin Login" << endl;
        cout << "5. Keluar" << endl;
    }

    void run() {
        int choice;
        while (true) {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    adminLogin();
                    break;
                case 5:
                    cout << "Terima kasih telah menggunakan ATM. Sampai jumpa!" << endl;
                    return;
                default:
                    cout << "Opsi tidak valid. Silakan coba lagi." << endl;
            }
        }
    }

private:
    vector<Account> accounts;
    Admin admin;

    void checkBalance() {
        int accountNumber;
        cout << "Masukkan nomor rekening: ";
        cin >> accountNumber;

        for (const Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Saldo rekening Anda: RP." << account.getBalance() << endl;
                return;
            }
        }

        cout << "Nomor rekening tidak valid." << endl;
    }

    void deposit() {
        int accountNumber;
        double amount;
        cout << "Masukkan nomor rekening: ";
        cin >> accountNumber;

        for (Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Masukkan jumlah yang akan disetor: Rp.";
                cin >> amount;
                account.deposit(amount);
                cout << "Setoran berhasil." << endl;
                return;
            }
        }

        cout << "Nomor rekening tidak valid." << endl;
    }

    void withdraw() {
        int accountNumber;
        double amount;
        cout << "Masukkan nomor rekening: ";
        cin >> accountNumber;

        for (Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Masukkan jumlah yang akan ditarik: Rp.";
                cin >> amount;
                if (account.withdraw(amount)) {
                    cout << "Penarikan berhasil." << endl;
                }
                return;
            }
        }

        cout << "Nomor rekening tidak valid." << endl;
    }

    void adminLogin() {
        string inputUsername, inputPassword;
        cout << "Masukkan username admin: ";
        cin >> inputUsername;
        cout << "Masukkan password admin: ";
        cin >> inputPassword;

        if (admin.authenticate(inputUsername, inputPassword)) {
            cout << "Admin login berhasil." << endl;
            adminMenu();
        } else {
            cout << "Username atau password admin tidak valid." << endl;
        }
    }

    void adminMenu() {
        while (true) {
            cout << "Opsi Admin:" << endl;
            cout << "1. Laporan Transaksi" << endl;
            cout << "2. Keluar sebagai Admin" << endl;
            int adminChoice;
            cin >> adminChoice;

            switch (adminChoice) {
                case 1:
                    admin.viewTransactionHistory(accounts);
                    break;
                case 2:
                    cout << "Admin logout." << endl;
                    return;
                default:
                    cout << "Opsi admin tidak valid. Silakan coba lagi." << endl;
            }
        }
    }
};

int main() {
    ATM atm;
    atm.run();
    return 0;
}
