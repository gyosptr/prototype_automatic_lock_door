#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int indikatorledMerah = 6;  // Indikator LED di pin 6
int indikatorledHijau =7; // Relay doorlock di pin 7
String readString;
const int servokunci = 9;
const int servopintu= 10;
Servo servokun;
Servo servopint;

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  delay (100);
  lcd.setCursor(0,0);
  lcd.print("sedang memuat....");
  
 Serial.begin(9600);// Sesuaikan dengan Baudrate bluetooth anda
 

  lcd.setCursor(0,0);
  lcd.print("Pintu Siap Untuk");
  lcd.setCursor(0,1);
  lcd.print("Akses Bluetooth");
    
  pinMode(indikatorledHijau, OUTPUT); // 
  pinMode(indikatorledMerah, OUTPUT);  // 
  
  digitalWrite(indikatorledHijau, HIGH); // Aktifkan 
  digitalWrite(indikatorledMerah, HIGH);   // Aktifkan 
 }

void loop() 
{
    
  while (Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() >0) {
    Serial.println(readString);
    if (readString == "buka pintu") // Jika hasil Keypad benar
    {
      servokun.attach(servokunci);
      servokun.write(110);
      delay(1000);
      servokun.detach();
      lcd.clear();
      delay(100);
      lcd.setCursor(1,0);
      lcd.print("AKSES DITERIMA");
      lcd.setCursor(1,1);
      lcd.print("loading");
      delay (200);
      lcd.setCursor(8,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(9,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(10,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(11,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(12,1);
      lcd.print(".");
      delay (300);
      lcd.setCursor(13,1);
      lcd.print(".");
      delay (500);
      lcd.setCursor(14,1);
      lcd.print(".");
      delay (1000);
     
      servopint.attach(servopintu);
      servopint.write(150);
      delay(1000);
      servopint.detach();
      lcd.clear();
      delay(100);
      lcd.setCursor(0,0);
      lcd.print("Berikan Perintah");
      lcd.setCursor(0,1);
      lcd.print("untuk menutup");
      digitalWrite(indikatorledHijau, HIGH); // Aktifkan relay selama 15 detik
      digitalWrite(indikatorledMerah, LOW);   // Aktifkan indikator Terbuka  
      readString="";
      
    }
    else if (readString  == "tutup pintu")     {
      servopint.attach(servopintu);
      servopint.write (40);
      delay(1000);
      servopint.detach();
      lcd.clear();
      delay (100);
      lcd.setCursor(1,0);
      lcd.print("AKSES DITERIMA");
     lcd.setCursor(1,1);
      lcd.print("loading");
      delay (200);
      lcd.setCursor(8,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(9,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(10,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(11,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(12,1);
      lcd.print(".");
      delay (300);
      lcd.setCursor(13,1);
      lcd.print(".");
      delay (500);
      lcd.setCursor(14,1);
      lcd.print(".");
      delay (1000);
     
      servokun.attach(servokunci);
      servokun.write(150);
      delay(1000);
      servokun.detach();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Berikan Perintah");
      lcd.setCursor(0,1);
      lcd.print("untuk Membuka");
      digitalWrite(indikatorledHijau, LOW); // Aktifkan relay selama 15 detik
      digitalWrite(indikatorledMerah, HIGH);   // Aktifkan indikator Terbuka
      readString="";
     }
     else {
       lcd.clear();
      delay (100);
      lcd.setCursor(0,0);
      lcd.print("AKSES DITOLAK!");
      lcd.setCursor(0,1);
      lcd.print("Berikan Perintah");
     readString="";
     }
       
  }
  }
  


   