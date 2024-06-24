#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <windows.h>
#include <string>
#include <climits>
#include <algorithm>

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
        cout << "==>";
    }
    else
    {
        cout << "   ";
    }
}

vector<string> dijkstra(const string &start, const string &end, const unordered_map<string, vector<Edge>> &graph)
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

    if (path[0] == start)
    {
        return path;
    }
    else
    {
        return {};
    }
}

int main()
{
    unordered_map<string, vector<Edge>> graph = {
        {"Surabaya", {{"Gresik", 21}, {"Sidoarjo", 20}, {"Krian", 30}, {"Bangkalan", 33}}},
        {"Gresik", {{"Surabaya", 21}, {"Sidoarjo", 54}, {"Mojokerto", 54}, {"Lamongan", 30}, {"Krian", 43}}},
        {"Sidoarjo", {{"Surabaya", 20}, {"Gresik", 54}, {"Mojokerto", 40}, {"Pasuruan", 38}, {"Krian", 19}, {"Gempol", 11}}},
        {"Mojokerto", {{"Gresik", 54}, {"Sidoarjo", 40}, {"Jombang", 31}, {"Lamongan", 49}, {"Pasuruan", 65}, {"Batu", 65}, {"Krian", 20}, {"Gempol", 36}}},
        {"Krian", {{"Surabaya", 30}, {"Gresik", 43}, {"Sidoarjo", 19}, {"Mojokerto", 20}}},
        {"Jombang", {{"Mojokerto", 31}, {"Lamongan", 85}, {"Kediri", 43}, {"Nganjuk", 39}, {"Babat", 55}, {"Pare", 26}}},
        {"Bojonegoro", {{"Lamongan", 67}, {"Tuban", 42}, {"Madiun", 98}, {"Ngawi", 74}, {"Nganjuk", 68}, {"Babat", 37}}},
        {"Lamongan", {{"Gresik", 30}, {"Mojokerto", 49}, {"Jombang", 85}, {"Bojonegoro", 67}, {"Tuban", 55}, {"Babat", 29}}},
        {"Tuban", {{"Bojonegoro", 42}, {"Lamongan", 55}, {"Tuban", 55}, {"Babat", 29}}},
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
        {"Malang", {{"Blitar", 81}, {"Pasuruan", 53}, {"Lumajang", 128}, {"Batu", 20}, {"Kepanjen", 19}}},
        {"Pasuruan", {{"Sidoarjo", 38}, {"Mojokerto", 64}, {"Malang", 53}, {"Probolinggo", 38}, {"Gempol", 26}}},
        {"Gempol", {{"Sidoarjo", 11}, {"Mojokerto", 36}, {"Malang", 56}, {"Pasuruan", 26}}},
        {"Probolinggo", {{"Pasuruan", 38}, {"Lumajang", 50}, {"Situbondo", 97}}},
        {"Lumajang", {{"Probolinggo", 50}, {"Jember", 65}, {"Kepanjen", 109}}},
        {"Kepanjen", {{"Blitar", 61}, {"Lumajang", 109}, {"Malang", 19}, {"Batu", 37}}},
        {"Bondowoso", {{"Situbondo", 34}, {"Jember", 133}}},
        {"Situbondo", {{"Probolinggo", 97}, {"Bondowoso", 34}, {"Banyuwangi", 94}}},
        {"Jember", {{"Lumajang", 65}, {"Bondowoso", 33}, {"Banyuwangi", 106}}},
        {"Banyuwangi", {{"Situbondo", 94}, {"Jember", 106}}},
        {"Bangkalan", {{"Surabaya", 33}, {"Sampang", 62}}},
        {"Sampang", {{"Bangkalan", 62}, {"Pamekasan", 32}}},
        {"Pamekasan", {{"Sampang", 62}, {"Sumenep", 53}}},
        {"Sumenep", {{"Pamekasan", 53}}},
        {"Batu", {
                     {"Mojokerto", 65},
                     {"Malang", 20},
                     {"Blitar", 73},
                     {"Pare", 59},
                 }},
        {"Babat", {{"Jombang", 55}, {"Bojonegoro", 37}, {"Lamongan", 29}, {"Tuban", 29}}},
        {"Pare", {{"Kediri", 26}, {"Jombang", 26}, {"Batu", 29}, {"Blitar", 51}}},

    };

    while (true)
    {
        string start, end;
        system("cls");
        gotoxy(2, 4);
        cout << "=====================================" << endl;
        gotoxy(2, 5);
        cout << "|            MENU ADMIN             |" << endl;
        gotoxy(2, 6);
        cout << "|         SELAMAT DATANG " << "\t      | " << endl;
        gotoxy(2, 7);
        cout << "=====================================" << endl;
        gotoxy(2, 8);
        cout << "========== APLIKASI MAPS ==========" << endl;
        gotoxy(2, 9);
        cout << "|\t                              |" << endl;
        gotoxy(2, 10);
        cout << "|\t                              |" << endl;
        gotoxy(2, 11);
        cout << "|\t                              |" << endl;
        gotoxy(2, 12);
        cout << "|\t                              |" << endl;
        gotoxy(2, 13);
        cout << "|\t                              |" << endl;
        gotoxy(2, 14);
        cout << "|\t                              |" << endl;
        gotoxy(2, 15);
        cout << "=====================================" << endl;
        int posisi = 1;
        int tekan = 0;
        cout << "\nMasukkan kota asal (atau 'exit' untuk keluar): ";
        cin >> start;
        if (start == "exit")
            break;
        cout << "Masukkan kota tujuan: ";
        cin >> end;
        if (end == "exit")
            break;

        vector<string> path = dijkstra(start, end, graph);

        if (!path.empty())
        {
            cout << "Lintasan terpendek dari " << start << " ke " << end << " adalah: ";
            for (const string &city : path)
            {
                cout << city << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Tidak ada lintasan dari " << start << " ke " << end << endl;
        }
    }

    return 0;
}