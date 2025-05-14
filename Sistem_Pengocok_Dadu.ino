#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(15, 14);

LiquidCrystal_I2C lcd(0x27 , 16 , 2);

Servo myServo;

#define Tombol 11

const byte ROWS = 4; //BARIS
const byte COLS = 4; //KOLOM

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char customKey;         //Variabel penampung input keypad
int number = 0;         //Variabel penampung nilai angka
int number_input = 1;

char step;
enum {inAngkaPertama, inAngkaKedua, inAngkaKetiga, outHasil};
String strAngkaPertama = "", strAngkaKedua = "", strAngkaKetiga = "";
int angkaPertama, angkaKedua, angkaKetiga ;
int hasil;
char operasi, operasi1;
int Key = 0;


int loop1 = 0,
    loop2 = 0,
    c = 1;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  mySerial.begin(9600);
  mp3_set_serial(mySerial);
  mp3_set_volume(100);
  myServo.attach(12);
  pinMode(Tombol, INPUT_PULLUP);
  myServo.write(45);
}

void Servo_Putar(int x) {
  for (int startt = 0; startt <= x; startt++) {
    for (int i = -120; i <= 70; i++) {
      myServo.write(i);
      delay(1);
    }
    for (int y = 90; y <= 140; y++) {
      myServo.write(y);
      delay(1);
    }
    delay(50);
  }
}

void loop() {
  if (digitalRead(Tombol) == LOW) {
    lcd.clear();
    while (loop1 <= 0) {
      lcd.setCursor(0, 0);
      lcd.print("     SIAP!    ");
      Servo_Putar(10);
      myServo.write(170);
      delay(1000);
      myServo.write(45);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("MASUKKAN ANGKA");
      delay(1000);
      lcd.clear();
      loop1 = loop1 + 1;
    }
    loop1 = 0;
  }
  Kalkulator();

}
