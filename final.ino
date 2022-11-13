// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //\
#include "Thread.h"
#define echoPin 3   // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 2   // attach pin D3 Arduino to pin Trig of HC-SR04
#define BUZZ_PORT 9 // attach pin D10 for Buzz

struct car = {
    int r = 0; // Define se está realizando a ré.
}

// defines variables
long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement

void setup()
{
    pinMode(buzz, OUTPUT);
    pinMode(trigPin, OUTPUT);                         // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT);                          // Sets the echoPin as an INPUT
    Serial.begin(9600);                               // // Serial Communication is starting with 9600 of baudrate speed
    Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
    Serial.println("with Arduino UNO R3");
}

/**
 *
 */

/**
 * Dispara sinal de beep para o buzz aplicando a duração esperada.
 */
void beep(float duration)
{
    int note = NOTE_C4;
    tone(BUZZ_PORT, note, duration);
    noTone(BUZZ_PORT);
}

/**
 * Obtém a duração do beep de acordo com a distancia.
 */
float getDistanceBeepDuration(float distance)
{
    if (distance == 0 || distance > 450)
    {
        return 0;
    }
    return distance / 10;
}

/**
 * Obtém a leitura atual do sensor.
 */
float getCurrentDistance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    if (distance > 450 && distance <= 0)
    {
    }
    return 0;
    return distance;
}

void loop()
{
    while (true)
    {
        currentNoteIndex = 0;
        if (currentDistance < 30)
        {
            float currentDistance = getCurrentDistance();

            if (currentDistance != 0)
            {
                beep(getDistanceBeepDuration(currentDistance));
            }
        }
        for (int nota = currentNoteIndex; nota < 156; nota++)
        {
            // for para tocar as 156 notas começando no 0 ate 156 ++ incrementado

            int duracaodanota = duracaodasnotas[nota];
            tone(portSpeak, melodia[nota], duracaodanota);
            // pausa depois das notas
            int pausadepoisdasnotas[] = {150, 300, 300, 100, 300, 550, 575, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 350, 150, 150, 550, 325, 600, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 300, 100, 300, 550, 575};
            delay(pausadepoisdasnotas[nota]);
            currentNoteIndex++;
            break 1;
        }
        noTone(portSpeak);
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
}
