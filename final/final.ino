// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //\
#include "Thread.h"
#define echoPin 9    // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 8    // attach pin D3 Arduino to pin Trig of HC-SR04
#define portSpeak 7  // attach pin D10 for Buzz

// struct car ={
//   int r = 0; // Define se está realizando a ré.
// }

// defines variables
long duration;  // variable for the duration of sound wave travel
int distance;   // variable for the distance measurement

void setup() {
  pinMode(portSpeak, OUTPUT);
  pinMode(trigPin, OUTPUT);                          // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);                           // Sets the echoPin as an INPUT
  Serial.begin(9600);                                // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test");  // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

/**
 *
 */

/**
 * Dispara sinal de beep para o buzz aplicando a duração esperada.
 */
void beep(float duration) {
  // int note = 660;
  // tone(portSpeak, note, duration);
  tone(portSpeak,1500);
  delay(1000); 
  noTone(portSpeak);
  delay(1000);
}

/**
 * Obtém a duração do beep de acordo com a distancia.
 */
float getDistanceBeepDuration(float distance) {
  if (distance == 0 || distance > 450) {
    return 1000;
  }
  return 500;
}

/**
 * Obtém a leitura atual do sensor.
 */
float getCurrentDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if (distance > 450 && distance <= 0) {

    return 0;
  }
  return distance;
}

int melodia[] = { 660, 660, 660, 510, 660, 770, 380, 510, 380, 320, 440, 480, 450, 430, 380, 660, 760, 860, 700, 760, 660, 520, 580, 480, 510, 380, 320, 440, 480, 450, 430, 380, 660, 760, 860, 700, 760, 660, 520, 580, 480, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 500, 760, 720, 680, 620, 650, 1020, 1020, 1020, 380, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 585, 550, 500, 380, 500, 500, 500, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 500, 760, 720, 680, 620, 650, 1020, 1020, 1020, 380, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 585, 550, 500, 380, 500, 500, 500, 500, 500, 500, 500, 580, 660, 500, 430, 380, 500, 500, 500, 500, 580, 660, 870, 760, 500, 500, 500, 500, 580, 660, 500, 430, 380, 660, 660, 660, 510, 660, 770, 380 };
int pausadepoisdasnotas[] = { 150, 300, 300, 100, 300, 550, 575, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 350, 150, 150, 550, 325, 600, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 300, 100, 300, 550, 575 };
int duracaodasnotas[] = { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 80, 100, 100, 100, 80, 50, 100, 80, 50, 80, 80, 80, 80, 100, 100, 100, 100, 80, 100, 100, 100, 80, 50, 100, 80, 50, 80, 80, 80, 80, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 200, 80, 80, 80, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 200, 80, 80, 80, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 60, 80, 60, 80, 80, 80, 80, 80, 80, 60, 80, 60, 80, 80, 80, 80, 80, 60, 80, 60, 80, 80, 80, 80, 80, 80, 100, 100, 100, 100, 100, 100, 100 };
void loop() {
  int currentNoteIndex = 0;
  while (true) {
    // duraçao de cada not
    float currentDistance = getCurrentDistance();
    if (currentDistance <= 30 && currentDistance != 0) {
      while (true) {
        Serial.print("Distance:");
        Serial.print(distance);
        Serial.println(" cm");
        // Serial.print('\n');
        currentDistance = getCurrentDistance();
        beep(getDistanceBeepDuration(currentDistance));
        if (currentDistance > 30) {
          
          break;
        }
      }
    } else {
      int duracaodanota = duracaodasnotas[currentNoteIndex];
      tone(portSpeak, melodia[currentNoteIndex], duracaodanota);
      delay(pausadepoisdasnotas[currentNoteIndex]);
      noTone(portSpeak);      
      currentNoteIndex++;
      Serial.println(" cm");
    }

    if (currentNoteIndex > 154) {
      currentNoteIndex = 0;
    }
    // noTone(portSpeak);

    Serial.print("Distance: ");
    Serial.print(distance);
  }
}
