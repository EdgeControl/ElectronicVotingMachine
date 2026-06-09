#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//candidate button
#define CAND1_PIN 22
#define CAND2_PIN 23
#define CAND3_PIN 24
#define CAND4_PIN 25
#define CAND5_PIN 26
#define CAND6_PIN 27
#define CAND7_PIN 28
#define CAND8_PIN 29
#define CAND9_PIN 30
#define CAND10_PIN 31
#define CAND11_PIN 32
#define CAND12_PIN 33
#define CAND13_PIN 34
#define CAND14_PIN 35
#define CAND15_PIN 36

// LED indication
#define CAND1_LED 37
#define CAND2_LED 38
#define CAND3_LED 39
#define CAND4_LED 40
#define CAND5_LED 41
#define CAND6_LED 42
#define CAND7_LED 43
#define CAND8_LED 44
#define CAND9_LED 45
#define CAND10_LED 46
#define CAND11_LED 47
#define CAND12_LED 48
#define CAND13_LED 49
#define CAND14_LED 50
#define CAND15_LED 51

//Control pins
#define ADMIN_PIN 7
#define DELETE_PIN 53
#define RESULT_PIN 52
#define FORWARD_PIN 6
#define BACKWARD_PIN 5
#define red 3
#define green 2
#define buzz 4
int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0,c10=0,c11=0,c12=0,c13=0,c14=0,c15=0;
int inc =0;
int dec=3;
bool t=true;
bool Security=false,security=false;
bool del=false,s1=false,s2=false,s3=false,verify = false,allow=false;
void page_1();
void page_2();
void page_3();
void page_4();
void dell();
void (*pages[4])()={page_1,page_2,page_3,page_4};
void Delete();
bool mainmenu();
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() {
//  for(int a =0;a<=20;a++){
//    EEPROM.write(a,0);
//  }
Serial.begin(9600);
lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("EVM Powered By");
  Serial.println("EVM Powered By");
  lcd.setCursor(0,1);
  lcd.print("Bonifon");
  Serial.println("Bonifon");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Booting ");
  for(int i=22;i<=36;i++){//candidate
    pinMode(i, INPUT_PULLUP);
  }
  lcd.setCursor(8,0);
  lcd.print(".");
  for(int j=37;j<=51;j++){//led
    pinMode(j,OUTPUT);
  }
  lcd.setCursor(9,0);
  lcd.print(".");
  //security
  pinMode(ADMIN_PIN, INPUT_PULLUP);
  pinMode(DELETE_PIN, INPUT_PULLUP);
  pinMode(RESULT_PIN, INPUT_PULLUP);
  pinMode(FORWARD_PIN, INPUT_PULLUP);
  pinMode(BACKWARD_PIN, INPUT_PULLUP);
  lcd.setCursor(10,0);
  lcd.print(".");
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(buzz,OUTPUT);
  delay(800);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Main Menu");
  Serial.println("Main Menu");
  digitalWrite(red,1);
digitalWrite(green,0);

  }

void loop() {
 

 while(Security){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Admin vote");
  Serial.println("Admin vote");
  verify = mainmenu();
  
  while(verify){
  if(allow){
    if (digitalRead(CAND1_PIN) == LOW) {
    digitalWrite(CAND1_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(1);
    showMessage("Vote Registered");
    Serial.println("Candidate 1");
    digitalWrite(CAND1_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND2_PIN) == LOW) {
    digitalWrite(CAND2_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(11);
    showMessage("Vote Registered");
    Serial.println("Candidate 2");
    digitalWrite(CAND2_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND3_PIN) == LOW) {
    digitalWrite(CAND3_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(21);
    showMessage("Vote Registered");
    Serial.println("Candidate 3");
    digitalWrite(CAND3_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND4_PIN) == LOW) {
    digitalWrite(CAND4_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(31);
    showMessage("Vote Registered");
    Serial.println("Candidate 4");
    digitalWrite(CAND4_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND5_PIN) == LOW) {
    digitalWrite(CAND5_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(41);
    showMessage("Vote Registered");
    Serial.println("Candidate 5");
    digitalWrite(CAND5_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  }else if (digitalRead(CAND6_PIN) == LOW) {
    digitalWrite(CAND6_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(51);
    showMessage("Vote Registered");
    Serial.println("Candidate 6");
    digitalWrite(CAND6_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND7_PIN) == LOW) {
    digitalWrite(CAND7_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(61);
    showMessage("Vote Registered");
    Serial.println("Candidate 7");
    digitalWrite(CAND7_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND8_PIN) == LOW) {
    digitalWrite(CAND8_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(71);
    showMessage("Vote Registered");
    Serial.println("Candidate 8");
    digitalWrite(CAND8_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND9_PIN) == LOW) {
    digitalWrite(CAND9_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(81);
    showMessage("Vote Registered");
    Serial.println("Candidate 9");
    digitalWrite(CAND9_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  }  else if (digitalRead(CAND10_PIN) == LOW) {
    digitalWrite(CAND10_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(91);
    showMessage("Vote Registered");
    Serial.println("Candidate 10");
    digitalWrite(CAND10_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND11_PIN) == LOW) {
    digitalWrite(CAND11_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(101);
    showMessage("Vote Registered");
    Serial.println("Candidate 11");
    digitalWrite(CAND11_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND12_PIN) == LOW) {
    digitalWrite(CAND12_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(111);
    showMessage("Vote Registered");
    Serial.println("Candidate 12");
    digitalWrite(CAND12_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND13_PIN) == LOW) {
    digitalWrite(CAND13_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(121);
    showMessage("Vote Registered");
    Serial.println("Candidate 13");
    digitalWrite(CAND13_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  }else if (digitalRead(CAND14_PIN) == LOW) {
    digitalWrite(CAND14_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(131);
    showMessage("Vote Registered");
    Serial.println("Candidate 14");
    digitalWrite(CAND14_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  } else if (digitalRead(CAND15_PIN) == LOW) {
    digitalWrite(CAND15_LED,HIGH);
    digitalWrite(buzz,HIGH);
    incrementVote(141);
    showMessage("Vote Registered");
    Serial.println("Candidate 15");
    digitalWrite(CAND15_LED,LOW);
    digitalWrite(buzz,LOW);
    delay(200);
  }}
  if (digitalRead(RESULT_PIN) == LOW) {
    delay(200);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Closing Vote");
    Serial.println("Closing Vote");
    for(int i=0;i<3;i++){
      lcd.setCursor(13+i,0);
      lcd.print(".");
      delay(60);
    }
    
     viewvote();}
     
  
   if(digitalRead(ADMIN_PIN)==LOW){
    delay(200);
    allow=true;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Allowed ");
    Serial.println("Allowed ");
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
  }
 }}
   if(digitalRead(ADMIN_PIN)==LOW){
    delay(200);
    Security=true;
//    verify=false;
  }
  else if (digitalRead(RESULT_PIN) == LOW) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Result Menu");
    Serial.println("Result Menu");
    lcd.setCursor(0,1);
    lcd.print("Viewing Vote");
    Serial.println("Viewing Vote");
    for(int i=0;i<3;i++){
      lcd.setCursor(13+i,1);
      lcd.print(".");
      Serial.print(".");
      delay(60);
    }
    t= true;
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Press up and");
     Serial.println("Press up and");
     lcd.setCursor(0,1);
     lcd.print("Down to View Vote");
     Serial.println("Down to View Vote");
    while(t){
     
      
      if((digitalRead(FORWARD_PIN)==LOW)&&(digitalRead(BACKWARD_PIN)==LOW)){
        
        t=false;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Exit to Main");
        Serial.println("Exit to Main");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
  lcd.print("Main Menu");
  Serial.println("Main Menu");
digitalWrite(red,1);
digitalWrite(green,0);
      }
     else if(digitalRead(FORWARD_PIN)==LOW){
      delay(200);
        dec=inc-1;
        pages[inc]();
//        lcd.print(inc);
        inc=inc+1;
//        page_1();
        if(inc>=4){
          delay(200);
          inc=0;
        }
        delay(100);
      }
      else if(digitalRead(BACKWARD_PIN)==LOW){
        delay(200);
        inc=dec+1;
        pages[dec]();
        dec=dec-1;
//        page_2();
        if(dec<0){
          delay(200);
          dec=3;
        }
        delay(100);
      }
      
    }
  }else if(digitalRead(DELETE_PIN)==0){
    delay(200);
    del=true;
     while(del){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Delete Menu");
      Serial.println("Delete Menu");
  lcd.setCursor(0, 1);
  lcd.print("Enter psw");
  Serial.println("Enter psw");
     dell();
    
  if(digitalRead(CAND1_PIN)==0){
    delay(200);
    s1=true;
  }
  
 delay(50);
    while(s1){
  lcd.setCursor(10, 1);
  lcd.print("*");
  Serial.print("*");
 dell();
  if(digitalRead(CAND4_PIN)==0){
    s2=true;
    delay(200);
  }
  
  delay(50);
      while(s2){
        lcd.setCursor(11, 1);
  lcd.print("*");
  Serial.print("*");
  dell();
  if (digitalRead(CAND15_PIN)==0){
    s3=true;
    delay(200);
  }
  
  delay(50);
        while(s3){
          lcd.setCursor(12, 1);
  lcd.print("*");
  Serial.print("*");
          Delete();
         
        }
      }
    }
  }
  }
 
}

void incrementVote(int candidateAddress) {
  int value;
  delay(200);
  EEPROM.get(candidateAddress,value);
  delay(200);
//  if (count < 255)/
  EEPROM.put(candidateAddress, value + 1);
  delay(200); // Debounce delay
}

void showMessage(String message) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
  digitalWrite(green,LOW);
  digitalWrite(red,HIGH);
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press Security");
  Serial.println("Press Security");
  lcd.setCursor(0, 1);
  lcd.print("To Vote");
  Serial.println("To Vote");
  Security=false;
  allow =false;
}

void page_1() {
  Serial.print("C1 : ");
  Serial.println(EEPROM.get(1,c1));
  Serial.print("C2 : ");
  Serial.println(EEPROM.get(11,c2));
  Serial.print("C3 : ");
  Serial.println(EEPROM.get(21,c3));
  Serial.print("C4 : ");
  Serial.println(EEPROM.get(31,c4));
  lcd.clear();
  lcd.setCursor(0, 0);
  
  lcd.print("C1:");
  lcd.setCursor(4, 0);
  lcd.print(EEPROM.get(1,c1));
  delay(200);
  lcd.setCursor(8, 0);
  lcd.print("C2:");
  lcd.setCursor(12, 0);
  lcd.print(EEPROM.get(11,c2));
  delay(200);
  lcd.setCursor(0, 1);
  lcd.print("C3:");
  lcd.setCursor(4, 1);
  lcd.print(EEPROM.get(21,c3));
  delay(200);
  lcd.setCursor(8, 1);
  lcd.print("C4:");
  lcd.setCursor(12, 1);
  lcd.print(EEPROM.get(31,c4));
  delay(200);
//  delay(5000);
//  lcd.clear();
}
void page_2() {
  Serial.print("C5 : ");
  Serial.println(EEPROM.get(41,c5));
  Serial.print("C6 : ");
  Serial.println(EEPROM.get(51,c6));
  Serial.print("C7 : ");
  Serial.println(EEPROM.get(61,c7));
  Serial.print("C8 : ");
  Serial.println(EEPROM.get(71,c8));
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("C5:");
  lcd.setCursor(4, 0);
  lcd.print(EEPROM.get(41,c5));
  delay(200);
  lcd.setCursor(8, 0);
  lcd.print("C6:");
  lcd.setCursor(12, 0);
  lcd.print(EEPROM.get(51,c6));
  delay(200);
  lcd.setCursor(0, 1);
  lcd.print("C7:");
  lcd.setCursor(4, 1);
  lcd.print(EEPROM.get(61,c7));
  delay(200);
  lcd.setCursor(8, 1);
  lcd.print("C8:");
  lcd.setCursor(12, 1);
  lcd.print(EEPROM.get(71,c8));
  delay(200);
//  delay(5000);
//  lcd.clear();
}
void page_3() {
  Serial.print("C9 : ");
  Serial.println(EEPROM.get(81,c9));
  Serial.print("C10 : ");
  Serial.println(EEPROM.get(91,c10));
  Serial.print("C11 : ");
  Serial.println(EEPROM.get(101,c11));
  Serial.print("C12 : ");
  Serial.println(EEPROM.get(111,c12));
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("C9:");
  lcd.setCursor(4, 0);
  lcd.print(EEPROM.get(81,c9));
  delay(200);
  lcd.setCursor(8, 0);
  lcd.print("C10:");
  lcd.setCursor(12, 0);
  lcd.print(EEPROM.get(91,c10));
  delay(200);
  lcd.setCursor(0, 1);
  lcd.print("C11:");
  lcd.setCursor(4, 1);
  lcd.print(EEPROM.get(101,c11));
  delay(200);
  lcd.setCursor(8, 1);
  lcd.print("C12:");
  lcd.setCursor(12, 1);
  lcd.print(EEPROM.get(111,c12));
  delay(200);
//  delay(5000);
//  lcd.clear();
}
void page_4() {
  Serial.print("C13 : ");
  Serial.println(EEPROM.get(121,c13));
  Serial.print("C14 : ");
  Serial.println(EEPROM.get(131,c14));
  Serial.print("C15 : ");
  Serial.println(EEPROM.get(141,c15));

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("C13:");
  lcd.setCursor(4, 0);
  lcd.print(EEPROM.get(121,c13));
  delay(200);
  lcd.setCursor(8, 0);
  lcd.print("C14:");
  lcd.setCursor(12, 0);
  lcd.print(EEPROM.get(131,c14));
  delay(200);
  lcd.setCursor(0, 1);
  lcd.print("C15:");
  lcd.setCursor(4, 1);
  lcd.print(EEPROM.get(141,c15));
  delay(200);
  
}
void dell(){
   if((digitalRead(FORWARD_PIN)==LOW)&&(digitalRead(BACKWARD_PIN)==LOW)){
        
        del=false;
        s1=false;
        s2=false;
        s3=false;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Exit to Main");
        Serial.println("Exit to Main");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
  lcd.print("Main Menu");
  Serial.println("Main Menu");
digitalWrite(red,1);
digitalWrite(green,0);
      }
}
void Delete(){
  for (int i=0;i<=160;i++){
    EEPROM.update(i,0);
    
  }
  del=false;
  s1=false;
  s2=false;
  s3=false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Deleted ");
  Serial.println("Deleted ");
  digitalWrite(red,1);
digitalWrite(green,0);
  delay(1200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Main Menu");
  Serial.println("Main Menu");
}
bool mainmenu(){
  del=true;
  while(del){
      
  lcd.setCursor(0, 1);
  lcd.print("Enter psw");
  Serial.println("Enter psw");
      if((digitalRead(FORWARD_PIN)==LOW)&&(digitalRead(BACKWARD_PIN)==LOW)){
        delay(200);
        Security =false;
        security =false;
        del=false;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Exit to Main");
        Serial.println("Exit to Main");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
  lcd.print("Main Menu");
  Serial.println("Main menu");
digitalWrite(red,1);
digitalWrite(green,0);
      }
    
  if(digitalRead(CAND1_PIN)==0){
    delay(200);
    s1=true;
  }
  
 delay(50);
    while(s1){
  lcd.setCursor(10, 1);
  Serial.print("*");
  lcd.print("*");
  if(digitalRead(CAND4_PIN)==0){
    delay(200);
    s2=true;
  }
  
  delay(50);
      while(s2){
        lcd.setCursor(11, 1);
        Serial.print("*");
  lcd.print("*");
  if(digitalRead(CAND15_PIN)==0){
    delay(200);
    s3=true;
  }
  
  delay(50);
        while(s3){
          lcd.setCursor(12, 1);
          Serial.println("*");
  lcd.print("*");
          del=false;
          s1=false;
          s2=false;
          s3=false;
          security=true;
          delay(200);
        }
      }
    }
  }
  delay(100);
  return security;
}
void viewvote(){
   t= true;
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Press up and");
     lcd.setCursor(0,1);
     lcd.print("Down to View Vote");
    while(t){
     
      
      if((digitalRead(FORWARD_PIN)==LOW)&&(digitalRead(BACKWARD_PIN)==LOW)){
        delay(200);
        t=false;
        verify=false;
    Security=false;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Exit to Main");
        Serial.println("Exit to Main");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
  lcd.print("Main Menu");
  Serial.println("Main Menu");
digitalWrite(red,1);
digitalWrite(green,0);
      }
     else if(digitalRead(FORWARD_PIN)==LOW){
      delay(200);
        dec=inc-1;
        pages[inc]();
//        lcd.print(inc);
        inc=inc+1;
//        page_1();
        if(inc>=4){
          delay(200);
          inc=0;
        }
        delay(100);
      }
      else if(digitalRead(BACKWARD_PIN)==LOW){
        delay(200);
        inc=dec+1;
        pages[dec]();
        dec=dec-1;
//        page_2();
        if(dec<0){
          delay(200);
          dec=3;
        }
        delay(100);
      }
      
    }
}
