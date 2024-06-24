#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <windows.h>
#include <string>
#include <climits>
#include <algorithm>
#include <conio.h>  // untuk getch()
#include <unistd.h> // for sleep function

using namespace std;

struct Edge
{
    string destination;
    int weight;
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void panah(int pilihan, int posisi)
{
    if (pilihan == posisi)
    {
        cout << "==> ";
    }
    else
    {
        cout << "    ";
    }
}

pair<vector<string>, int> dijkstra(const string &start, const string &end, const unordered_map<string, vector<Edge>> &graph);
void initializeGraph(unordered_map<string, vector<Edge>> &graph);

void handleMenuSelection(int posisi, int &pilihan, unordered_map<string, vector<Edge>> &graph);

void displayMenu(int &pilihan, unordered_map<string, vector<Edge>> &graph);

pair<vector<string>, int> dijkstra(const string &start, const string &end, const unordered_map<string, vector<Edge>> &graph)

{
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    for (const auto &pair : graph)
    {
        dist[pair.first] = INT_MAX;
    }

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        string current = pq.top().second;
        pq.pop();

        if (current == end)
            break;

        for (const auto &edge : graph.at(current))
        {
            string next = edge.destination;
            int weight = edge.weight;
            int newDist = dist[current] + weight;

            if (newDist < dist[next])
            {
                dist[next] = newDist;
                prev[next] = current;
                pq.push({newDist, next});
            }
        }
    }

    vector<string> path;
    for (string at = end; at != ""; at = prev[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    int totalDistance = dist[end];

    if (path[0] == start)
    {
        return make_pair(path, totalDistance);
    }
    else
    {
        return make_pair(vector<string>{}, 0);
    }
}

void initializeGraph(unordered_map<string, vector<Edge>> &graph)
{
    graph = {
        {"Surabaya", {{"Gresik", 21}, {"Sidoarjo", 20}, {"Krian", 30}, {"Bangkalan", 33}}},
        {"Gresik", {{"Sidoarjo", 54}, {"Mojokerto", 54}, {"Lamongan", 30}, {"Krian", 43}, {"Tuban", 89}}},
        {"Sidoarjo", {{"Mojokerto", 40}, {"Krian", 19}, {"Gempol", 11}, {"Surabaya", 20}}},
        {"Mojokerto", {{"Jombang", 31}, {"Lamongan", 49}, {"Batu", 65}, {"Krian", 20}, {"Gempol", 39}}},
        {"Krian", {{"Surabaya", 30}, {"Gresik", 43}, {"Sidoarjo", 19}, {"Mojokerto", 20}}},
        {"Jombang", {{"Mojokerto", 31}, {"Lamongan", 85}, {"Kediri", 43}, {"Nganjuk", 39}, {"Babat", 55}, {"Pare", 26}}},
        {"Bojonegoro", {{"Tuban", 42}, {"Madiun", 98}, {"Ngawi", 74}, {"Nganjuk", 68}, {"Babat", 37}}},
        {"Lamongan", {{"Gresik", 30}, {"Mojokerto", 49}, {"Jombang", 85}, {"Bojonegoro", 67}, {"Babat", 29}, {"Tuban", 73}}},
        {"Tuban", {{"Bojonegoro", 42}, {"Babat", 29}, {"Gresik", 89}, {"Lamongan", 73}}},
        {"Madiun", {{"Bojonegoro", 98}, {"Ngawi", 56}, {"Magetan", 24}, {"Ponorogo", 31}, {"Nganjuk", 50}}},
        {"Ngawi", {{"Bojonegoro", 74}, {"Madiun", 56}, {"Magetan", 36}}},
        {"Magetan", {{"Madiun", 24}, {"Ngawi", 36}, {"Ponorogo", 36}}},
        {"Ponorogo", {{"Madiun", 31}, {"Magetan", 36}, {"Pacitan", 76}, {"Trenggalek", 50}}},
        {"Pacitan", {{"Ponorogo", 76}, {"Trenggalek", 107}}},
        {"Kediri", {{"Jombang", 43}, {"Nganjuk", 32}, {"Tulungagung", 29}, {"Blitar", 43}, {"Pare", 26}}},
        {"Nganjuk", {{"Jombang", 39}, {"Bojonegoro", 68}, {"Madiun", 50}, {"Kediri", 32}}},
        {"Tulungagung", {{"Kediri", 29}, {"Blitar", 36}, {"Trenggalek", 32}}},
        {"Blitar", {{"Kediri", 43}, {"Tulungagung", 36}, {"Malang", 81}, {"Kepanjen", 61}, {"Pare", 51}}},
        {"Trenggalek", {{"Ponorogo", 50}, {"Pacitan", 107}, {"Tulungagung", 32}}},
        {"Malang", {{"Blitar", 81}, {"Pasuruan", 53}, {"Gempol", 56}, {"Batu", 20}, {"Kepanjen", 19}}},
        {"Pasuruan", {{"Sidoarjo", 38}, {"Malang", 53}, {"Probolinggo", 38}, {"Gempol", 26}}},
        {"Gempol", {{"Sidoarjo", 11}, {"Mojokerto", 39}, {"Malang", 56}, {"Pasuruan", 26}}},
        {"Probolinggo", {{"Pasuruan", 38}, {"Lumajang", 50}, {"Situbondo", 97}}},
        {"Lumajang", {{"Probolinggo", 50}, {"Jember", 65}, {"Kepanjen", 109}}},
        {"Kepanjen", {{"Blitar", 61}, {"Lumajang", 109}, {"Malang", 19}, {"Batu", 37}}},
        {"Bondowoso", {{"Situbondo", 34}, {"Jember", 133}}},
        {"Situbondo", {{"Probolinggo", 97}, {"Bondowoso", 34}, {"Banyuwangi", 94}}},
        {"Jember", {{"Lumajang", 65}, {"Bondowoso", 33}, {"Banyuwangi", 106}}},
        {"Banyuwangi", {{"Situbondo", 94}, {"Jember", 106}}},
        {"Bangkalan", {{"Surabaya", 33}, {"Sampang", 62}, {"Sumenep", 146}, {"Pamekasan", 140}}},
        {"Sampang", {{"Bangkalan", 62}, {"Pamekasan", 32}, {"Sumenep", 114}}},
        {"Pamekasan", {{"Sampang", 32}, {"Sumenep", 53}, {"Bangkalan", 140}}},
        {"Sumenep", {{"Pamekasan", 53}, {"Bangkalan", 146}, {"Sampang", 114}}},
        {"Batu", {{"Mojokerto", 65}, {"Malang", 20}, {"Blitar", 73}, {"Pare", 59}}},
        {"Babat", {{"Jombang", 55}, {"Bojonegoro", 37}, {"Lamongan", 29}, {"Tuban", 29}}},
        {"Pare", {{"Kediri", 26}, {"Jombang", 26}, {"Batu", 59}, {"Blitar", 51}}},
    };
}

void handleMenuSelection(int posisi, int &pilihan, unordered_map<string, vector<Edge>> &graph)
{
    switch (posisi)
    {
    case 1:
    {
        while (true) // Tambahkan loop di sini
        {
            string start, end;
            bool validInput = false;

            while (!validInput)
            {
                cout << "\nMasukkan kota asal = ";
                getline(cin, start);
                if (start == "exit")
                    return;

                if (graph.find(start) == graph.end())
                {
                    cout << "Kota asal tidak ditemukan dalam graph. Coba lagi.\n";
                    continue;
                }

                cout << "Masukkan kota tujuan =  ";
                getline(cin, end);
                if (end == "exit")
                    return;

                if (graph.find(end) == graph.end())
                {
                    cout << "Kota tujuan tidak ditemukan dalam graph. Coba lagi.\n";
                    continue;
                }

                validInput = true;
            }

            auto result = dijkstra(start, end, graph);

            if (!result.first.empty())
            {
                cout << "Lintasan terpendek dari " << start << " ke " << end << " adalah: ";
                for (const string &city : result.first)
                {
                    cout << city << " ";
                }
                cout << "Dengan Jarak " << result.second << " km" << endl;
            }
            else
            {
                cout << "Tidak ada lintasan dari " << start << " ke " << end << endl;
            }

            cout << "\nApakah ingin mencari jalur lagi? (y/n): ";
            char choice;
            cin >> choice;
            cin.ignore(); // untuk membersihkan buffer input

            if (choice != 'y' && choice != 'Y')
            {
                break; // Keluar dari loop jika pilihan bukan 'y' atau 'Y'
            }
        }
        break;
    }
    case 2:
        cout << "Keluar dari program." << endl;
        exit(0);
        break;
    }
}

void displayMenu(int &pilihan, unordered_map<string, vector<Edge>> &graph)
{
    system("cls");
    gotoxy(2, 4);
    cout << "======================================" << endl;
    gotoxy(2, 5);
    cout << "|             MENU MAPS              |" << endl;
    gotoxy(2, 6);
    cout << "|           SELAMAT DATANG " << "\t       | " << endl;
    gotoxy(2, 7);
    cout << "======================================" << endl;
    gotoxy(2, 8);
    cout << "=========== APLIKASI MAPS ============" << endl;
    gotoxy(2, 9);
    cout << "|                                    |" << endl;
    gotoxy(2, 10);
    cout << "|                                    |" << endl;
    gotoxy(2, 11);
    cout << "|                                    |" << endl;
    gotoxy(2, 12);
    cout << "======================================" << endl;

    int tekan = 0;
    while (tekan != 13)
    {
        gotoxy(5, 9);
        panah(1, pilihan);
        cout << "1.Cari Jalur Terpendek";
        gotoxy(5, 10);
        panah(2, pilihan);
        cout << "2.Keluar";

        tekan = getch();

        if (tekan == 80)
        {
            pilihan = (pilihan % 2) + 1;
        }
        else if (tekan == 72)
        {
            pilihan = (pilihan - 2 + 2) % 2 + 1;
        }

        if (tekan == 13)
        {
            if (pilihan == 1)
            {
                system("cls");
                handleMenuSelection(pilihan, pilihan, graph);
            }
            else if (pilihan == 2)
            {
                exit(0);
            }
        }
    }
}

int main()
{
    system("COLOR F0");
    int pilihan = 1;
    unordered_map<string, vector<Edge>> graph;

    initializeGraph(graph);

    while (true)
    {
        displayMenu(pilihan, graph);
    }

    return 0;
}