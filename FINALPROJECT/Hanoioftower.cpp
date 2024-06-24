#include <iostream>
#include <stack>

int moveDisk(int disk, int source, int dest) {
    std::cout << "Pindahkan cincin " << disk << " dari menara " << source << " ke menara " << dest << std::endl;
    return disk;
}

void hanoi(int n, std::stack<int>& source, std::stack<int>& dest, std::stack<int>& aux1, std::stack<int>& aux2, int sourceTower, int destTower) {
    if (n == 1) {
        int topDisk = source.top();
        source.pop();
        dest.push(topDisk);
        moveDisk(topDisk, sourceTower, destTower);
        return;
    }
    
    if (n == 2) {
        int topDisk = source.top();
        source.pop();
        aux1.push(topDisk);
        moveDisk(topDisk, sourceTower, 3);

        topDisk = source.top();
        source.pop();
        dest.push(topDisk);
        moveDisk(topDisk, sourceTower, destTower);

        topDisk = aux1.top();
        aux1.pop();
        dest.push(topDisk);
        moveDisk(topDisk, 3, destTower);

        return;
    }
    
    hanoi(n - 2, source, aux1, aux2, dest, sourceTower, 4);
    
    int topDisk = source.top();
    source.pop();
    aux1.push(topDisk);
    moveDisk(topDisk, sourceTower, 3);

    topDisk = source.top();
    source.pop();
    aux2.push(topDisk);
    moveDisk(topDisk, sourceTower, 4);

    topDisk = aux1.top();
    aux1.pop();
    dest.push(topDisk);
    moveDisk(topDisk, 3, destTower);

    topDisk = aux2.top();
    aux2.pop();
    dest.push(topDisk);
    moveDisk(topDisk, 4, destTower);

    hanoi(n - 2, aux1, dest, source, aux2, 3, destTower);
}

int main() {
    int n;
    std::cout << "Masukkan jumlah cincin: ";
    std::cin >> n;

    std::stack<int> tower1, tower2, tower3, tower4;

    // Memasukkan cincin ke tower pertama
    for (int i = n; i >= 1; i--) {
        tower1.push(i);
    }

    std::cout << "Langkah-langkah pemindahan cincin:\n";
    hanoi(n, tower1, tower4, tower2, tower3, 1, 4);
    
    return 0;
}
