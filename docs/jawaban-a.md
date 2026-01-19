# Jawaban Soal A

## 1. Analisis Kondisi (10 Poin)
- marknicho07@gmail.com

## 2. Source Control Management (16 poin)

### a. 4 commands dalam Git dan jelaskan kegunaan serta contoh penggunaannya.
1. git init
    - kegunaan : untuk menginisiasi suatu folder menjadi git repository
    - contoh penggunaan : D:\projects\drone\CaRSC26_16025088_THT> git init : Artinya menginisiasi folder CaRSC26_16025088_THT ke git
2. git branch
    - kegunaan : mengelola cabang dari pengerjaan kode
    - contoh penggunaan : git branch [nama-branch]: Membuat cabang baru.
3. git add
    - kegunaan : memindahkan perubahan file ke area persiapan (belum disimpan secara permanen)
    - contoh penggunaan : git add . : Menambahkan semua perubahan dan file baru di direktori saat ini ke Staging Area. 
4. git commit
    - kegunaan : menyimpan perubahan secara permanen yang telah dipilih (dengan git add)
    - contoh penggunaan : git commit -m "Pesan penjelasan perubahan di sini" : melakukan commit dan memberikan pesan

### b. menghubungkan Git dan VSCode dengan GitHub
- ![Source Control](../lampiran/a/screenshot_source_control.jpg)

### c. Tamatkan 4 topik Main pertama
- ![Git branching](../lampiran/a/screenshot_source_control.jpg)

### d. Git SSH Security
- ![Git ssh Security](../lampiran/a/Screenshot_git_ssh_security.jpg)

### e. Branch

## 3. Pengenalan Ground Control Station

### a. Install mission planner
- ![Mission planner](../lampiran/a/Screenshot_missionplanner.jpg)

### b. Kegunaan utama mission planner
- Memantau telemetry secara real time
- Membuat planning untuk misi penerbangan yang dimungkinkan untuk dilakukannya penentuan titik koordinat, ketinggian, dan kecepatan yang akan dilaksanakan oleh wahana terbang
- Memungkinkan pengaturan prosedur otomatis jika terjadi fail 
- Kalibrasi dan konfigurasi, memastikan stabilitas terbang dan akurasi navigasi drone

### c. Misi sederhana
- [Klik di sini untuk melihat file Waypoint Pemetaan](../lampiran/a/waypoint_pemetaan_80x100.waypoints)

## 4. Development environment
instalasi ubuntu menggunakan wsl

### a. ubuntu tools
- ![Ubuntu tools](../lampiran/a/linux_tools.jpg)

### b. instalasi ROS 2 
- ![Demo Talker Listener](../lampiran/a/demo_ros2_jazzy.jpg)


## 5. Dasar-dasar UAV

### a. Perbedaan VTOL, HTOL, dan Hybrid
- VTOL
    - Mekanisme Terbang
        - Gaya angkat dihasilkan langsung dari rotor yang berputar, sama seperti helikopter. Namun, dalam UAV, biasanya menggunakan 4 rotor (quadcopter) karena software lebih sederhana dengan lebih fokus ke kontrol kecepatan tiap rotornya, sementara konsep 1 rotor memerlukan kontrol mekanika juga yang cukup rumit
        - Rotor mempercepat aliran udara ke bawah (bentuk baling-baling menggunakan bentuk airfoil) sehingga UAV terdorong ke atas (hukum newton 3)
        - Tidak memerlukan kecepatan maju (seperti landasan) untuk menghasilkan lift
        - Hover dicapai dengan menyeimbangkan thrust dengan berat (F = mg)
    - Karakteristik
        - Take-off/landing : vertikal (tanpa runaway)
        - Kontrol
            - Roll & pitch : mengubah kecepatan rotor agar terjadi pitch (perbedaan thrust)
            - Yaw : mengatur kecepatan rotor juga untuk membuat perbedaan torsi rotor
    - Kelebihan
        - Hover presisi tinggi
        - kompleksitas mekanik rendah (khususnya multicopter)
        - Stabil dalam area sempit
    - Kekurangan
        - Boros baterai
        - Tidak efisien untuk perjalanan jauh (gaya angkat bergantung sepenuhnya pada rotor, tidak bisa memanfaatkan udara seperti menggunakan wing)

- HTOL 
    - Mekanisme terbang
        - Lift dihasilkan oleh sayap tetap (airfoil) akibat aliran udara saat UAV bergerak maju
        - Menggunakan prinsip Bernoulli + hukum newton : Tekanan bawah sayap > atas sayap. Sehingga udara mendorong UAV ke atas
        - Membutuhkan airspeed minimum untuk terbang (udara yang cukup untuk mendorong UAV ke atas)
    - Karakteristik
        - Take-off/Landing : horizontal (bisa menggunakan runaway, catapult, atau launcher untuk mencapai minimum speed)
        - kontrol
            - aileron (kemudi pada sayap) untuk membuat pesawat roll
            - Elevator (kemudi pada sayap belakang) untuk membuat pesawat pitch
            - Rudder (kemudi pada ekor) untuk kontrol Yaw
    - Kelebihan
        - Efisiensi tinggi (bantuan dari gaya angkat oleh udara)
        - Jangkauan panjang
        - Kecepatan jelajah tinggi
    - Kekurangan
        - Tidak bisa hover
        - Perlu area take-off/landing
        - Kurang presisi pada titik tertentu
- Hybrid 
    - mekanisme terbang 
        - Memiliki dual mode terbang
            - VTOL mode : menggunakan rotor vertikal untuk menghasilkan lift seperti multicopter sehingga bisa hover
            - Cruise mode : Memiliki sayap yang dengan menggunakan propeller yang memberikan thrust horizontal, bisa terbang seperti UAV HTOL
        - Dua macam transisi
            - Rotor yang berputar arah (lebih efisien karena rotor tetap terpakai untuk menambah kecepatan, tetapi lebih rumit)
            - Rotor mati saat mode cruise (rotor tidak berputar dan tetap menghadap vertikal)
    - karakteristik
        - Take-off / landing: Vertikal
        - Cruise: Horizontal seperti fixed-wing
    - Kelebihan
        - Tidak butuh runaway dan bisa hover, tetapi tetap bisa terbang jauh
        - Sangat fleksibel, bisa digunakan untuk small area maupun wide area
    - Kekurangan
        - Biaya lebih mahal
        - Sistem lebih kompleks
        - Lebih berat karena memiliki dual system