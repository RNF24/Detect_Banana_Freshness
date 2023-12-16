// include library
#include <Wire.h>
#include<LiquidCrystal_I2C.h>
#include <Arduino_KNN.h>

//pin yang digunakan
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 10;  
const int s3 = 11;  
const int out = 12;
// Variable  
int red = 0;
int blue = 0;
int green = 0;

//KNN
const int INPUTS = 3; //Banyak input
const int CLASSES = 2; //Banyak kelas
const int K = 3;

String label[CLASSES] = {"Mentah", "Matang"};

float sensor[INPUTS];

// Create a new KNNClassifier
KNNClassifier myKNN(INPUTS);
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
    
void setup()   
{  
  lcd.init();// initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Menambah Data");
  delay(5000);
  
  // Input output
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);   
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH); 

  //Objek
  float pisang1[] = { 29.0, 55.0, 31.0 };
  float pisang2[] = { 32.0, 64.0, 31.0 };
  float pisang3[] = { 24.0, 55.0, 29.0 };
  float pisang4[] = { 19.0, 35.0, 20.0 };
  float pisang5[] = { 27.0, 53.0, 28.0 };
  float pisang6[] = { 34.0, 63.0, 36.0 };
  float pisang7[] = { 21.0, 36.0, 23.0 };
  float pisang8[] = { 37.0, 67.0, 39.0 };
  float pisang9[] = { 20.0, 43.0, 24.0 };
  float pisang10[] = { 31.0, 59.0, 31.0 };
  float pisang11[] = { 32.0, 65.0, 35.0 };
  float pisang12[] = { 29.0, 56.0, 30.0 };
  float pisang13[] = { 24.0, 50.0, 28.0 };
  float pisang14[] = { 37.0, 74.0, 40.0 };
  float pisang15[] = { 33.0, 63.0, 35.0 };
  float pisang16[] = { 14.0, 32.0, 18.0 };
  float pisang17[] = { 18.0, 43.0, 25.0 };
  float pisang18[] = { 17.0, 37.0, 22.0 };
  float pisang19[] = { 15.0, 36.0, 20.0 };
  float pisang20[] = { 15.0, 31.0, 19.0 };
  float pisang21[] = { 13.0, 30.0, 18.0 };
  float pisang22[] = { 21.0, 40.0, 28.0 };
  float pisang23[] = { 17.0, 38.0, 23.0 };
  float pisang24[] = { 15.0, 33.0, 20.0 };
  float pisang25[] = { 16.0, 37.0, 21.0 };
  float pisang26[] = { 14.0, 31.0, 19.0 };
  float pisang27[] = { 20.0, 46.0, 28.0 };
  float pisang28[] = { 22.0, 44.0, 28.0 };
  float pisang29[] = { 16.0, 35.0, 22.0 };
  float pisang30[] = { 17.0, 36.0, 21.0 };

  myKNN.addExample(pisang1, 1); //1 mentah 2 matang
  myKNN.addExample(pisang2, 1);
  myKNN.addExample(pisang3, 1);
  myKNN.addExample(pisang4, 1);
  myKNN.addExample(pisang5, 1);
  myKNN.addExample(pisang6, 1);
  myKNN.addExample(pisang7, 1);
  myKNN.addExample(pisang8, 1);
  myKNN.addExample(pisang9, 1);
  myKNN.addExample(pisang10, 1);
  myKNN.addExample(pisang11, 1);
  myKNN.addExample(pisang12, 1);
  myKNN.addExample(pisang13, 1);
  myKNN.addExample(pisang14, 1);
  myKNN.addExample(pisang15, 1);
  myKNN.addExample(pisang16, 2);
  myKNN.addExample(pisang17, 2);
  myKNN.addExample(pisang18, 2);
  myKNN.addExample(pisang19, 2);
  myKNN.addExample(pisang20, 2);
  myKNN.addExample(pisang21, 2);
  myKNN.addExample(pisang22, 2);
  myKNN.addExample(pisang23, 2);
  myKNN.addExample(pisang24, 2);
  myKNN.addExample(pisang25, 2);
  myKNN.addExample(pisang26, 2);
  myKNN.addExample(pisang27, 2);
  myKNN.addExample(pisang28, 2);
  myKNN.addExample(pisang29, 2);
  myKNN.addExample(pisang30, 2);

  lcd.setCursor(1,1);
  lcd.print("Data ditambah");
  delay(2000);

  lcd.clear();
}

void loop() 
{  
  int classification;

  lcd.setCursor(1,0);
  lcd.print("Pengujian");
  lcd.setCursor(1,1);
  lcd.print("Letakkan objek");
  delay(5000);
  lcd.clear();

  Sensor(sensor);

  //Klasifikasi objek
  classification = myKNN.classify(sensor, K);

  lcd.setCursor(1,0);
  lcd.print("Hasil Uji");
  lcd.setCursor(1,1);

  //Cetak klasifikasi
  if (classification == 1){
    lcd.print("Mentah");
  }
  else if (classification == 2){
    lcd.print("Matang");
  }
  Serial.println();
  delay(2000);
  lcd.clear();
 }  

void Sensor(float sensor[])
{
 Serial.println("Warna Terdeteksi");
 digitalWrite(s2, LOW);  
 digitalWrite(s3, LOW);  
 red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
 Serial.print("Intensitas merah: ");  
 Serial.println(red, DEC);  
 
 digitalWrite(s3, HIGH);
 blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
 Serial.print("Intensitas biru: ");  
 Serial.println(blue, DEC);
 
 digitalWrite(s2, HIGH); 
 green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
 Serial.print("Intensitas hijau: ");  
 Serial.println(green, DEC);  
}
