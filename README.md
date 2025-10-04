# 🎲 Pengocok Dadu Otomatis & Koreksi Jawaban Berbasis Arduino

## 🧩 Deskripsi Proyek
Proyek ini merupakan **alat edukatif interaktif** yang menggabungkan konsep **pengocokan dadu otomatis** dengan **sistem koreksi jawaban**.  
Menggunakan **Arduino**, alat ini dapat menampilkan hasil dadu secara acak, menerima **jawaban dari pengguna melalui keypad**, serta memberikan **respon suara dan gerakan servo** untuk menunjukkan hasil **benar atau salah**. [AIR FORCE - Al Irsyad Purwokerto]

---

## ⚙️ Fitur Utama
- 🎲 **Simulasi pengocokan dadu otomatis** menggunakan servo.  
- 🔢 **Input jawaban melalui keypad 4x4**.  
- 💬 **Tampilan hasil di LCD I2C 16x2**.  
- 🔈 **DFPlayer Mini** memainkan suara efek atau respon.  
- ✅ **Koreksi jawaban otomatis** – jika hasil dadu sesuai jawaban, servo & DFPlayer memberi respon “benar”, jika tidak, respon “salah”.

---

## 🧠 Library yang Digunakan
Pastikan library berikut telah diinstal di Arduino IDE:
```cpp
#include <LiquidCrystal_I2C.h>    // LCD I2C 16x2
#include <Keypad.h>               // Input keypad 4x4
#include <EEPROM.h>               // (opsional) penyimpanan nilai
#include <SoftwareSerial.h>       // Komunikasi DFPlayer Mini
#include <Servo.h>                // Kendali servo motor
#include <DFPlayer_Mini_Mp3.h>    // Pemutar suara MP3
```

---

## 🪛 Koneksi Hardware
| Komponen          | Pin Arduino  | Keterangan                   |
| ----------------- | ------------ | ---------------------------- |
| **LCD I2C**       | SDA/SCL      | Alamat `0x27`                |
| **Keypad 4x4**    | 2–9          | Baris: 9,8,7,6; Kolom: 5–2   |
| **Servo**         | 12           | Mengocok dadu & respon hasil |
| **Tombol Start**  | 11           | Mulai pengocokan             |
| **DFPlayer Mini** | RX=15, TX=14 | Komunikasi SoftwareSerial    |
| **Speaker**       | DFPlayer Out | Efek suara dadu / koreksi    |

## 🎮 Fungsi Utama
- Servo_Putar(int x)
  - Menggerakkan servo secara cepat bolak-balik untuk meniru efek pengocokan dadu.
- Kalkulator()
  - Dapat dikembangkan menjadi fungsi penerima input jawaban, membandingkan dengan hasil dadu, dan menentukan status benar/salah.
- DFPlayer
  - Memainkan file audio MP3 dari SD card sebagai efek:
      - /mp3/0001.mp3 → suara “benar”
      - /mp3/0002.mp3 → suara “salah”
      - /mp3/0003.mp3 → efek suara dadu
   
---

## Contacs us : 
* [Frendi RoboTech](https://www.instagram.com/frendi.co/)
* [Whatsapp : +6287888227410](https://wa.me/+6287888227410)
* [Email    : frendirobotech@gmail.com](https://mail.google.com/mail/u/0/?view=cm&tf=1&fs=1&to=frendirobotech@gmail.com)

---

## 👨‍💻 Author
Dikembangkan oleh: Imam Sa'id Nurfrendi [Reog Robotic & Robotech Electronics]  
Lisensi: Open Source (MIT)
