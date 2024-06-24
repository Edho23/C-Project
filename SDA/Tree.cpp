#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// Node untuk pohon biner
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk menambahkan node ke pohon
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Fungsi untuk mencari data menggunakan DFS (inorder traversal) dan mencatat jalurnya
bool searchDFS(TreeNode* root, int target, vector<int>& path) {
    if (root == nullptr) {
        return false;
    }

    stack<TreeNode*> stack;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        TreeNode* node = stack.top();

        if (node->right == nullptr || node->right == lastVisited) {
            stack.pop();
            path.push_back(node->data);
            if (node->data == target) {
                return true;
            }
            lastVisited = node;
        } else {
            current = node->right;
        }
    }

    return false;
}

// Fungsi untuk mencari data menggunakan BFS (level order traversal) dan mencatat jalurnya
bool searchBFS(TreeNode* root, int target, vector<int>& path) {
    if (root == nullptr) {
        return false;
    }

    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();
        path.push_back(current->data);

        if (current->data == target) {
            return true;
        }

        if (current->left != nullptr) {
            queue.push(current->left);
        }

        if (current->right != nullptr) {
            queue.push(current->right);
        }
    }

    return false;
}

int main() {
    // Inisialisasi array
    int A[15] = {3, 9, 15, 19, 25, 29, 37, 50, 53, 68, 71, 82, 88, 95, 100};

    // Tampilkan data array
    cout << "Data Array: ";
    for (int i = 0; i < 15; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Buat root pohon
    TreeNode* root = nullptr;

    // Masukkan elemen array ke pohon
    for (int i = 0; i < 15; ++i) {
        root = insertNode(root, A[i]);
    }

    while (true) {
        int target;
        cout << "Masukkan data yang ingin dicari (atau -1 untuk keluar): ";
        cin >> target;

        if (target == -1) {
            break;
        }

        // Cari data menggunakan DFS
        vector<int> dfsPath;
        if (searchDFS(root, target, dfsPath)) {
            cout << "Data " << target << " ditemukan dengan DFS (inorder traversal)." << endl;
            cout << "Jalur DFS: ";
            for (int i = 0; i < dfsPath.size(); ++i) {
                cout << dfsPath[i] << " ";
                if (dfsPath[i] == target) break;
            }
            cout << endl;
        } else {
            cout << "Data " << target << " tidak ditemukan dengan DFS (inorder traversal)." << endl;
        }

        // Cari data menggunakan BFS
        vector<int> bfsPath;
        if (searchBFS(root, target, bfsPath)) {
            cout << "Data " << target << " ditemukan dengan BFS (level order traversal)." << endl;
            cout << "Jalur BFS: ";
            for (int i = 0; i < bfsPath.size(); ++i) {
                cout << bfsPath[i] << " ";
                if (bfsPath[i] == target) break;
            }
            cout << endl;
        } else {
            cout << "Data " << target << " tidak ditemukan dengan BFS (level order traversal)." << endl;
        }
    }

    return 0;
}
