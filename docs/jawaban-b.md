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

## 4. file pipeline_parser.hpp dan vision_to_mavros.hpp.


## 5. Firmware dan Sistem Benam
1. firmware dan perbedaannya dengan perangkat lunak (software)
- Firmware adalah perangkat lunak tingkat rendah yang biasanya langsung pada hardware agar bisa langsung mengontrol hardware. Biasanya disimpan di memori non-volatile (flash/ROM).
- Perbedaannya dengan software pada umumnya adalah kalau software berhubungan dengan pengguna, firmware dengan elektroniknya. Sehingga, beberapa hal seperti UI, update yang sering, dan tidak real-time terdapat pada software. Selain itu, biasanya software terletak pada OS.
- Peran firmware dalam UAV
    - membaca sensor (IMU, GPS, barometer)
    - menjalankan kontrol (PID)
    - mengatur motor (ESC)
    - mengelola komunikasi (telemetri)
- Contoh firmware UAV: PX4, ArduPilot 
2. RTOS
- RTOS adalah sistem operasi yang menjamin respon tepat waktu (deterministik) terhadap suatu kejadian.
- Mengapa penting? UAV memiliki kontrol motor yang harus memiliki delay seminimal mungkin (tepat waktu) agar kontrol bisa berjalan dengan baik. Tanpa RTOS, UAV bisa tidak stabil bahkan crash karena keterlambatan menerima task
- Beberapa fitur RTOS :
    - task scheduling
    - real-time constraint
- Contoh RTOS di UAV: NuttX, FreeRTOS
3. UART, SPI, I2C
- Komunikasi serial = data dikirim bit demi bit antar perangkat
- UART (Universal Asynchronous Receiver Transmitter)
    - Fitur :
        - Asynchronous (tanpa clock)
        - Point-to-point
        - Sederhana
        - Kecepatan sedang
    - Penggunaan di UAV
        - GPS
        - Telemetri (radio)
        - Debugging
- SPI (Serial Peripheral Interface)
    - Fitur :
        - Synchronous (pakai clock)
        - Master–slave
        - Cepat
        - Banyak kabel
    - Penggunaan di UAV
        - IMU (gyro, accelerometer)
        - Flash memory
- I2C (Inter-Integrated Circuit)
    - Fitur :
        - Synchronous
        - Banyak device di satu bus
        - Lambat tapi hemat kabel
    - Penggunaan di UAV
        - Barometer
        - Magnetometer
        - Sensor suhu

# Jurusan Concept
## 1. konsep dasar ROS2 (Humble)
1. Nodes
- Node adalah program kecil yang menjalankan satu tugas spesifik dalam sistem robot/UAV
- Di ROS, satu node = satu fungsi utama
- Bagaikan sebuah pesawat, setiap bagian dikendalikan satu orang. Ada yang pemantau menggunakan kamera, ada yang mount senjata, ada yang menjadi pilot. Semuanya mengerjakan satu tugas spesifik
2. Topics
- jalur komunikasi satu arah untuk mengirim data tanpa henti
- Di ROS, node bisa publish (mengirim data) dan subscribe (menerima data)
- Bagaikan radio broadcast, pengirim tidak peduli siapa yang menerima, penerima tinggal mendengarkan
3. Services
- Service adalah komunikasi dua arah: request dan response
- Dipakai untuk aksi cepat & sekali jalan
- nanya sesuatu terus nunggu jawabannya 
4. Parameters
- nilai konfigurasi yang bisa dibaca/diubah oleh node saat runtime
- Seperti aturan tertulis tapi tidak disampaikan
    - Aturan tidak bicara
    - Aturan tidak mengirim pesan
    - Aturan bisa diganti
5. Actions
- Task berdurasi lama yang bisa dimonitor
- Analoginya seperti menyuruh sebuah robot mengerjakan sesuatu, dan setiap dia sampai ke checkpoint, laporkan. Proses ini tidak berhenti sampai disuruh
