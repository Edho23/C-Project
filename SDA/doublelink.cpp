#include <iostream>

using namespace std;

// Definisi struktur untuk node dari double linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Definisi kelas LD untuk double linked list
class LD
{
private:
    Node *head;

public:
    // Konstruktor untuk menginisialisasi head sebagai nullptr
    LD() : head(nullptr) {}

    // Fungsi untuk menambahkan node baru di akhir double linked list
    void append(int new_data)
    {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = nullptr;
        Node *last = head;

        if (head == nullptr)
        {
            new_node->prev = nullptr;
            head = new_node;
            return;
        }

        while (last->next != nullptr)
        {
            last = last->next;
        }

        last->next = new_node;
        new_node->prev = last;
    }

    // Fungsi untuk menghapus node berdasarkan nilai data
    void deleteNode(int key)
    {
        Node *temp = head;

        if (temp != nullptr && temp->data == key)
        {
            head = temp->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    // Fungsi untuk mencari nilai maju
    bool searchForward(int key)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Fungsi untuk mencari nilai mundur
    bool searchBackward(int key)
    {
        Node *last = head;
        if (last == nullptr)
            return false;

        while (last->next != nullptr)
        {
            last = last->next;
        }

        while (last != nullptr)
        {
            if (last->data == key)
            {
                return true;
            }
            last = last->prev;
        }
        return false;
    }

    // Fungsi untuk mencetak linked list dari awal ke akhir
    void printListForward()
    {
        Node *node = head;
        while (node != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    // Fungsi untuk mencetak linked list dari akhir ke awal
    void printListBackward()
    {
        Node *last = head;
        if (last == nullptr)
            return;

        while (last->next != nullptr)
        {
            last = last->next;
        }

        while (last != nullptr)
        {
            cout << last->data << " ";
            last = last->prev;
        }
        cout << endl;
    }
};

// Fungsi utama
int main()
{
    // Membuat objek dari kelas LD
    LD list;

    // Menambahkan elemen ke linked list
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    // Mencetak linked list dari awal ke akhir
    cout << "Linked list (forward): ";
    list.printListForward();

    // Mencetak linked list dari akhir ke awal
    cout << "Linked list (backward): ";
    list.printListBackward();

    // Mencari elemen dalam linked list
    int search_value = 30;
    cout << "Mencari " << search_value << " maju: " << (list.searchForward(search_value) ? "Ditemukan" : "Tidak ditemukan") << endl;
    cout << "Mencari " << search_value << " mundur: " << (list.searchBackward(search_value) ? "Ditemukan" : "Tidak ditemukan") << endl;

    // Menghapus elemen dari linked list
    cout << "Menghapus " << search_value << " dari linked list." << endl;
    list.deleteNode(search_value);

    // Mencetak linked list setelah penghapusan
    cout << "Linked list setelah penghapusan (forward): ";
    list.printListForward();

    cout << "Linked list setelah penghapusan (backward): ";
    list.printListBackward();

    return 0;
}
