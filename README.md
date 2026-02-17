# Program Penyelesaian LinkedIn Queens dengan Algoritma Brute Force

## A. Penjelasan Singkat
Program ini adalah aplikasi berbasis (CLI) yang dirancang untuk mencari solusi dari permainan teka-teki LinkedIn Queens. Permainan ini mengharuskan penempatan $N$ buah Ratu pada papan berukuran $N \times N$ dengan batasan-batasan berikut:
* Setiap baris hanya boleh berisi tepat satu Ratu.
* Setiap kolom hanya boleh berisi tepat satu Ratu.
* Setiap wilayah warna (region) yang berbeda hanya boleh berisi tepat satu Ratu.
* Ratu tidak boleh bersentuhan satu sama lain secara diagonal, kolom dan baris.

Algoritma yang digunakan adalah **Brute Force** dengan memanfaatkan permutasi. Strategi ini secara otomatis menjamin aturan baris dan kolom terpenuhi, sehingga proses validasi difokuskan pada aturan wilayah warna dan posisi diagonal.

## B. Requirement 
Untuk menjalankan program ini, diperlukan:
* **Menginstall C++ Compiler** : Jika belum menginstall bisa lihat [di sini](https://code.visualstudio.com/docs/languages/cpp) untuk tutorial lebih lanjut.
* **Menginstall C++ Compiler** : Clone reporsitory ini dengan perintah
```bash
git clone https://github.com/ucupsss/Tucil1_13524014.git
```

## C. Cara Mengkompilasi Program
Gunakan perintah berikut pada terminal atau command prompt untuk mengkompilasi kode sumber:
```bash
g++ -o solver main.cpp
```
Lalu gunakan perintah berikut untuk run program
``` bash
./solver
```
