#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LT {
private:
    Node* head;

public:
    LT() : head(nullptr) {}

    void addNodeDepan(int val){
        Node* newNode =  new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Data " << val << " Berhasil ditambahkan di depan Link list. " << endl;
    }

    void addNodeBelakang(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        } else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Data " << val << " Berhasil ditambahkan di Belakang Link list. " << endl; 
    }

    void addNodeTengah(int val, int pos){
        if(pos <= 0){
            addNodeDepan(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i = 1; i < pos && temp->next != nullptr; i++){
            temp = temp->next;
        }

        if(temp == nullptr){
            cout << "Posisi lebih besar dari panjang Linked List, menambhakan di belakang " << endl;
            addNodeBelakang(val);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Data " << val << " Berhasil ditambahkan di posisi " << pos << " Dalam linked List. " << endl;

    }

 
    void display() {
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

    bool searchNode(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
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
            delete temp;
            cout << "Data " << val << " berhasil dihapus dari linked list." << endl;
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
            delete toDelete;
            cout << "Data " << val << " berhasil dihapus dari linked list." << endl;
        }
    }

 
    ~LT() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LT list;
    int choice, value,pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Depan\n";
        cout << "2. Tambah Data Tengah\n";
        cout << "3. Tambah Data Belakang\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Cari Data\n";
        cout << "6. Hapus Data\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai yang ingin ditambahkan: ";
                cin >> value;
                list.addNodeDepan(value);
                break;
            case 2:
                cout << "Masukkan nilai yang ingin ditambahkan: ";
                cin >> value;
                cout << "Masukkan Posisi yang ingin Di tambahkan :";
                cin >> pos;
                list.addNodeTengah(value,pos);
                break;
            case 3:
                cout << "Masukkan nilai yang ingin ditambahkan: ";
                cin >> value;
                list.addNodeBelakang(value);
                break;
            case 4:
                cout << "Data dalam Linked List: ";
                list.display();
                break;
            case 5:
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> value;
                if (list.searchNode(value)) {
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