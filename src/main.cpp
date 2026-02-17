#include <bits/stdc++.h>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long cnt = 0;

bool valid(vector<int> &p, vector<vector<char>> &grid, int N)
{
    vector<bool> color(26, false);
    cnt++;
    cout << "Pengecekan ke " << cnt << "\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(p[i] == j) cout << "#";
            else cout << grid[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < N; i++)
    {
        int r = i;
        int c = p[i];

        // cek warna
        int warna = grid[r][c] - 'A';
        if (color[warna])
            return false; // tidak memenuhi syarat satu warna satu queen
        color[warna] = true;

        // cek bersentuhan diagonal apa engga
        for (int j = 0; j < i; j++)
        {
            int k = p[j];

            if (abs(r - j) == 1 and abs(c - k) == 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string namafile;
    cout << "Masukkan nama file : ";
    cin >> namafile;

    ifstream infile(namafile);
    if (!infile)
    {
        cerr << "File " << namafile << " tidak ditemukan\n";
        return 1;
    }

    vector<vector<char>> grid;
    string line;

    set<int> s;
    while (getline(infile, line))
    {
        if (line.empty())
            continue;

        vector<char> row;
        for (char c : line)
        {
            if (isspace(c))
                continue;
            s.insert(c);
            row.push_back(c);
        }
        if (!row.empty())
            grid.push_back(row);
    }

    if ((int)grid.size() == 0)
    {
        cerr << "File kosong\n";
        return 1;
    }

    int N = (int)grid.size();
    for (int i = 0; i < N; i++)
    {
        if (grid[i].size() != N)
        {
            cerr << "Matrix input bukan matriks persegi\n";
            return 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c = grid[i][j];
            if (!(c >= 'A' and c <= 'Z'))
            {
                cerr << "Karakter " << c << " pada baris " << i + 1 << " kolom " << j + 1 << " bukan berupa alfabet kapital";
                return 1;
            }
        }
    }

    vector<int> p(N);
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
    }

    bool found = false;

    auto mulai = high_resolution_clock::now();
    do
    {
        if (valid(p, grid, N))
        {
            found = true;
            break;
        }
    } while (next_permutation(p.begin(), p.end()));

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - mulai);

    if (found)
    {
        cout << "Solusi\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (p[i] == j)
                    cout << '#';
                else
                    cout << grid[i][j];
            }
            cout << "\n";
        }

        cout << "Waktu pencarian : " << duration.count() << " ms\n";
        cout << "Banyak kasus yang ditinjau : " << cnt << "\n";

        cout << "Apakah ingin simpan solusi? (Ya/Tidak) : ";
        string pil;
        cin >> pil;

        if (pil == "Ya" || pil == "ya" || pil == "YA")
        {
            string namasolusi;
            cout << "Masukkan nama file solusi : ";
            cin >> namasolusi;
            ofstream outfile(namasolusi);

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (p[i] == j)
                        outfile << "#";
                    else
                        outfile << grid[i][j];
                }
                outfile << "\n";
            }

            cout << "Solusi disimpan di file " << namasolusi << "\n";
        }
        else if (pil == "Tidak" || pil == "TIDAK" || pil == "tidak")
        {
            cout << "Solusi tidak disimpan\n";
        }
        else
        {
            cout << "Pilihan salah, pilih yang benar ya\n";
        }
    }
    else
    {
        cout << "Tidak ada solusi yang memenuhi \n";
        if (s.size() < N)
        {
            cout << "Tidak ada solusi karena jumlah warna kurang dari N atau jumlah baris";
        }
        cout << "Waktu pencarian : " << duration.count() << " ms\n";
        cout << "Banyak kasus yang ditinjau : " << cnt << "\n";
    }
}