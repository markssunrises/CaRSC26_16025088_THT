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