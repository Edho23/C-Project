#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LD {
private:
    Node* head;
    Node* tail;

public:
    LD() : head(nullptr), tail(nullptr) {}

    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "Linked List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (tail == nullptr) {
            cout << "Linked List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    bool searchForward(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool searchBackward(int val) {
        Node* temp = tail;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->prev;
        }
        return false;
    }

    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "Linked List is empty!" << endl;
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found in the list!" << endl;
        } else {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp;
            } else {
                tail = temp;
            }
            delete toDelete;
        }
    }

    ~LD() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LD list;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan Data (Maju)\n";
        cout << "2. Tampilkan Data (Mundur)\n";
        cout << "3. Cari Data (Maju)\n";
        cout << "4. Cari Data (Mundur)\n";
        cout << "5. Hapus Data\n";
        cout << "6. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai yang ingin ditambahkan: ";
                cin >> value;
                list.addNode(value);
                break;
            case 2:
                cout << "Data dalam Linked List (Maju): ";
                list.displayForward();
                break;
            case 3:
                cout << "Data dalam Linked List (Mundur): ";
                list.displayBackward();
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dicari (Maju): ";
                cin >> value;
                if (list.searchForward(value)) {
                    cout << "Nilai " << value << " ditemukan dalam Linked List." << endl;
                } else {
                    cout << "Nilai " << value << " tidak ditemukan dalam Linked List." << endl;
                }
                break;
            case 5:
                cout << "Masukkan nilai yang ingin dicari (Mundur): ";
                cin >> value;
                if (list.searchBackward(value)) {
                    cout << "Nilai " << value << " ditemukan dalam Linked List." << endl;
                } else {
                    cout << "Nilai " << value << " tidak ditemukan dalam Linked List." << endl;
                }
                break;
            case 6:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}