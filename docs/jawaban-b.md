# Jawaban Soal B

## 1. Pemrograman berorientasi objek
### a. konsep-konsep dasar OOP
- Class 
    - definisi : Blueprint / cetak biru yang mendefinisikan atribut dan perilaku
```cpp
class UAV {
public:
    double speed;
    void fly() {
        // do something
    }
};
```
- Object 
    - definisi : Hasil jadi dari class
```cpp
UAV drone1;
drone1.fly();
```

- Abstraction
    - definisi : Hanya menampilkan luarannya dan menyembunyikan detail
```cpp
class UAV {
public:
    void fly(); // detail disembunyikan
};
```

- Encapsulation
    - definisi : melindungi data agar tidak bisa diubah sembarangan
```cpp
class UAV {
private:
    double battery;
public:
    double getBattery() {
        return battery;
    }
};
```

- Inheritance
    definisi : class baru yang mewariskan class lama
```cpp
class FixedWing : public UAV {
};
```
- Polymorphism
    - definisi : Method dengan nama sama, tapi perilaku berbeda tergantung objeknya
```cpp
class UAV:
    def fly(self):
        print("UAV terbang")

class FixedWing(UAV):
    def fly(self):
        print("Fixed-wing")

class Quadrotor(UAV):
    def fly(self):
        print("Quadrotor")
```

### b. Design pattern

## 2. C++
1. #include <file_name> vs include "file_name"
    - Include <> digunakan untuk menginput library standar atau eksternal
    - Include "" digunakan untuk menginput file buatan sendiri
2. #ifdef, #ifndef, #endif dan #pragma once
    - ifndef (if not defined): Memeriksa "Apakah file ini sudah pernah di define"
    - #ifdef (if defined) : Kebalikan dari #ifndef, digunakan jika ingin mengeksekusi kode hanya jika suatu file sudah didefinisikan
    - #endif: Menandai akhir dari blok pemeriksaan (pemeriksaan ifndef/ifdef)
    - pragma once : Fungsinya sama persis dengan Include Guards, namun lebih praktis. Tidak perlu menulis ifdef, ifndef, dan endif
3. namespace dan scope resolution operator (::)
    - Namespace = mencegah konflik nama
    - :: = mengakses sesuatu di dalam namespace
4. #define vs using
    - #define = preprocessor, tidak punya tipe
    - using = fitur C++, aman dan punya tipe
5. Pointer (*) dan Address-of (&)
    - & = mengambil alamat memori
    - " * " = menyimpan / mengakses data lewat alamat
6. Pass by Value vs Pass by Reference
    - Pass by value = dikopi
    - Pass by reference = data asli diubah
7. std::unique_ptr vs std::shared_ptr
- unique_ptr
    - satu pemilik, tidak bisa dibagi
    - paling cepat & aman
- shared_ptr
    - anyak pemilik, pakai reference counting
    - lebih fleksibel tapi lebih berat

## 3. Multithreading
### a. Penjelasan konsep
- Multithreading adalah teknik di mana satu program menjalankan beberapa kode (thread) sekaligus agar lebih cepat, responsif, dan efisien. Setiap thread berbagi memori dan resource yang sama, tetapi memiliki alur instruksi sendiri.

### b. Contoh kasus
- Klik kode [Di sini](../src/b/daspro/multithreading.py)
- ![Simulasi](../lampiran/b/multithreading.py-CaRSC26_16025088_THT.gif)
