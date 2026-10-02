
#include <LiquidCrystal.h>

const int Led  = 8;
const int Buzz = 6;

String comando = "";
String true_password = "SkyPatrol";
String password = "";

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
  pinMode(Buzz, OUTPUT);
  Serial.println("OBDH is ready. Input your command:");
  Serial.println("Commands: On, Off, STATUS");
}

void loop() {
  if (Serial.available() > 0) {
    comando = Serial.readStringUntil('\n');
    comando.trim();

    lcd.clear();
    lcd.setCursor(0, 0);

    if (comando == "On") {
      digitalWrite(Led, HIGH);
      lcd.print("LED On.");
      tone(Buzz, 1000, 200);
      delay(500);
      tone(Buzz, 1000, 200);
      delay(500);
    }
    else if (comando == "Off") {
      digitalWrite(Led, LOW);
      lcd.print("LED Off.");
      tone(Buzz, 1200, 250);
      delay(300);
    }
    else if (comando == "STATUS") {
      if (digitalRead(Led) == HIGH) {
        lcd.print("LED is on.");
      } else {
        lcd.print("LED is off.");
      }
      tone(Buzz, 1400, 350);
      delay(500);
    }
    else if (comando == "game" || comando == "???") {
      for (int i = 0; i < 15; i++) {
        digitalWrite(Led, HIGH);
        delay(100);
        digitalWrite(Led, LOW);
        delay(100);
      }
      tone(Buzz, 850, 250);
      delay(400);
      tone(Buzz, 1000, 300);
      delay(400);
      tone(Buzz, 1300, 300);
      delay(350);
      noTone(Buzz);
      lcd.print("YOU STARTED THE");
      lcd.setCursor(5, 1);
      lcd.print("GAME!");
      delay(3000);
      lcd.clear();
      lcd.print("GUESS PASSWORD:");
      Serial.println("GUESS PASSWORD:");

      while (true) {
        if (Serial.available() > 0) {
          password = Serial.readStringUntil('\n');
          password.trim();
          if (password == true_password) {
            lcd.setCursor(0, 1);
            tone(Buzz, 1000, 200);
            delay(250);
            tone(Buzz, 1200, 200);
            delay(250);
            tone(Buzz, 1400, 300);
            delay(300);
            noTone(Buzz);
            lcd.print("Password is TRUE!");
            Serial.println("CORRECT!");
            digitalWrite(Led, HIGH);
            delay(5000);
            digitalWrite(Led, LOW);
            break;
          } else {
            lcd.setCursor(0, 1);
            lcd.print("Wrong password  ");
            Serial.println("WRONG!");
            tone(Buzz, 400, 300);
            delay(350);
            tone(Buzz, 300, 300);
            delay(350);
            noTone(Buzz);
            lcd.setCursor(0, 1);
            lcd.print("Try again!:   ");
          }
        }
      }
      lcd.clear();
      lcd.print("Game won!");
      delay(3000);
      lcd.clear();
    }
    else {
      lcd.print("Unknown Command.");
      tone(Buzz, 200, 300);
      delay(200);
    }
  }
}
