
#include <LiquidCrystal.h>  // include the library code
/**********************************************************/
// initialize the library with the numbers of the interface pins
void flash_led();
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
const uint8_t mute_button_pin = 3;
const uint8_t buzzer_pin = 5;
const uint8_t led_pin = 7;
const uint32_t ldr_pin = A0;
const uint32_t sampleTime = 900;  //200 ms
const uint32_t ldr_threshold = 700;
/*********************************************************/
void setup() {
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows:
  pinMode(mute_button_pin, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(ldr_pin, INPUT);
  Serial.begin(9600);
}
/*********************************************************/
uint8_t received_data = 0;
uint8_t warning_flag = 0;
uint8_t ON_flag = 1;
//int receiveData();
void loop() {
  /*
  listen to receive data
  */

  /*
  1 ==> fume sensor [fire detected]
  2 ==> ultrsonic sensor [door open]
  3 ==> magnetic sensor [intrusion]
  4 ==> ON
  5 ==> OFF
  */
  //receive data from LDR
  //delay(100);
  //Serial.println(digitalRead(mute_button_pin));
  if (warning_flag && ON_flag) {
    digitalWrite(buzzer_pin, 1);
    flash_led();

    if (digitalRead(mute_button_pin)) {
      delay(5000);
      lcd.clear();
      warning_flag = 0;
      digitalWrite(buzzer_pin, 0);
      digitalWrite(led_pin, 0);
      received_data = 0;
    };
  } else if (received_data == 1 && ON_flag) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Fire detected");
    delay(100);
    lcd.setCursor(0, 1);
    lcd.print("Check Fire plz");
    delay(100);
    warning_flag = 1;
    received_data = 0;
  } else if (received_data == 2 && ON_flag) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Door Opened");
    delay(100);
    lcd.setCursor(2, 2);
    lcd.print("Check door");
    delay(100);
    warning_flag = 1;
    received_data = 0;
  } else if (received_data == 3 && ON_flag) {
    lcd.clear();
    lcd.setCursor(1, 4);
    lcd.print("Intrusion");
    delay(100);
    lcd.setCursor(2, 0);
    lcd.print("Check thieves");
    delay(100);
    warning_flag = 1;
    received_data = 0;
  } else if (received_data == 4) {
    lcd.clear();
    lcd.setCursor(0, 2);
    lcd.print("Turning On");
    delay(100);
    ON_flag = 1;
    received_data = 0;
  } else if (received_data == 5) {
    lcd.clear();
    lcd.setCursor(0, 2);
    lcd.print("Turning Off");
    ON_flag=0;
    received_data = 0;
  }
  if (!warning_flag) {
    int ldr_value = analogRead(ldr_pin);
    //Serial.print("rlod : ");

    //Serial.println(ldr_value);
    if (ldr_value > ldr_threshold) {
      received_data = receiveData();
      Serial.print("recive : ");
      Serial.println(received_data);
    }
    if (received_data == -1) Serial.println("555555555555555555555555555555555555555555555555555555555555555555555555555555555555");
  }
  //  Serial.println(received_data);
  // Serial.println(analogRead(ldr_pin));
  // delay(50);
  //delay(100);
  /*lcd.print("Arduino");
  delay(4000);
  lcd.setCursor(2, 1);
  lcd.print("Talaat");
  delay(4000);
  lcd.clear();
  lcd.blink();
  delay(4000);
  lcd.setCursor(7, 1);
  delay(3000);
  lcd.noBlink();
  lcd.cursor();
  delay(4000);
  lcd.noCursor();
  lcd.clear();*/
}
void flash_led() {
  uint32_t previous_time = 0;
  uint8_t flag = 0;
  while (!digitalRead(mute_button_pin)) {
    uint32_t current_time = millis();
    if (current_time - previous_time >= 250) {
      if (flag) digitalWrite(led_pin, 1);
      else digitalWrite(led_pin, 0);
      flag = !flag;
      previous_time = current_time;
    }
  }
}
int receiveData() {
  while (analogRead(ldr_pin) >= ldr_threshold) {}
  int flag_count = 0;
  uint8_t edge_flag = 0;
  unsigned long start_time = millis();
  while (millis() - start_time < 3000) {
    Serial.println(analogRead(ldr_pin));
    if (!edge_flag) {
      if (analogRead(ldr_pin) >= ldr_threshold) {
        edge_flag = 1;
      }
    } else {
      if (analogRead(ldr_pin) < ldr_threshold) {
        flag_count += 1;
        edge_flag=0;
      }
    }
  }
  switch (flag_count) {
    case 0:
      return -1;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    case 3:
      return 3;
      break;
    case 4:
      return 4;
      break;
    case 5:
      return 5;
      break;
    default:
      return -1;
  }
}

// int receiveData() {
//   /*
//   1 ==> fume sensor (fire)
//   2 ==> ultrasonic (door open)
//   3 ==> magnetic (intrusion)
//   4 ==> ON (lcd,buzzer,led active)
//   5 ==> OFF (lcd,buzzer,led inactive)
//   */
//   uint32_t signalStartTime;
//   uint32_t signalDuration;

//   int received = 0;
//   while (analogRead(ldr_pin) >= ldr_threshold) {
//     // signalDuration = millis() - signalStartTime;
//     // if (signalDuration > sampleTime) {
//     //   return 0; //timeout
//     // }
//   }
//   for (int i = 2; i > 0; i--) {
//     delay(1000);
//     uint8_t flag = 1;

//     signalStartTime = millis();
//     // while (analogRead(ldr_pin) <= ldr_threshold) {
//     //   signalDuration = millis() - signalStartTime;
//     //   if (signalDuration > sampleTime) {
//     //     return 0; // timeout
//     //   }
//     // }
//     while (analogRead(ldr_pin) >= ldr_threshold) {
//       delay(100);
//       signalDuration = millis() - signalStartTime;
//       if (signalDuration > sampleTime / 1.5) {
//         Serial.println("hoooooooooooooo");
//         if (analogRead(ldr_pin) > ldr_threshold) {

//           received |= (1 << i);
//           break;
//         } else {
//           received &= (0 << i);
//           break;
//         }
//         flag = 0;
//       }
//       if (signalDuration > 2 * sampleTime) return -1;
//     }

//     if (flag) {
//       while (analogRead(ldr_pin) < ldr_threshold) {
//         delay(100);
//         signalDuration = millis() - signalStartTime;
//         if (signalDuration > sampleTime / 1.5) {
//           Serial.println("haaaaaaaaaaaaaaaaaaa");
//           if (analogRead(ldr_pin) > ldr_threshold) {
//             received |= (1 << i);
//             break;
//           } else {
//             received &= (0 << i);
//             break;
//           }
//         }
//         if (signalDuration < sampleTime) {
//           delay(sampleTime - signalDuration);
//         }
//         if (signalDuration > 2 * sampleTime) return -1;
//       }
//       signalDuration = millis() - signalStartTime;


//     } else {
//       if (signalDuration < sampleTime) {
//         delay(sampleTime - signalDuration);
//       }
//     }
//     // Serial.println(received);
//   }
//     Serial.println("--------------------------------------------------------------------");
//     return received;
// }
/************************************************************/