#include <iostream>
using namespace std;

// Definisi struktur untuk node dari linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node** head_ref, int new_data) {
    // Alokasikan node baru
    Node* new_node = new Node();
    Node* last = *head_ref;

    // Masukkan data ke dalam node baru
    new_node->data = new_data;
    //new_node->next = declared next (nullptr);

    // Jika linked list kosong, jadikan node baru sebagai head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // Jika linked list tidak kosong, iterasi hingga ke node terakhir
    while (last->next != nullptr) {
        last = last->next;
    }

    // Hubungkan node terakhir dengan node baru
    last->next = new_node;
}

// Fungsi untuk menghapus node berdasarkan nilai data
void deleteNode(Node** head_ref, int key) {
    // Simpan pointer ke head node dan inisialisasi node sebelumnya
    Node* temp = *head_ref;
    Node* prev = nullptr;

    // Jika head node sendiri yang harus dihapus
    if (temp != nullptr && temp->data == key) {
        *head_ref = temp->next; // Ubah head
        delete temp;            // Bebaskan memori head yang dihapus
        return;
    }

    // Cari node yang akan dihapus, simpan node sebelumnya agar bisa mengubah pointer
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Jika key tidak ditemukan di linked list
    if (temp == nullptr) return;

    // Hapus node dari linked list
    prev->next = temp->next;

    // Bebaskan memori dari node yang dihapus
    delete temp;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    // Inisialisasi linked list sebagai kosong
    Node* head = nullptr;

    // Menambahkan elemen ke linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    // Mencetak linked list sebelum penghapusan
    cout << "Linked list sebelum penghapusan: ";
    printList(head);

    // Menghapus node dengan nilai data 2
    cout << "Menghapus 2 dari linked list" << endl;
    deleteNode(&head, 2);

    // Mencetak linked list setelah penghapusan
    cout << "Linked list setelah penghapusan: ";
    printList(head);

    return 0;
}
