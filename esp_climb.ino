
/**
 * @file climbingWallPusher.ino
 * @brief Arduino-based climbing wall pusher timer and feedback system.
 *
 * Dependencies:
 * - TM1637TinyDisplay library for display control.
 * - pitches.h and melodies.h for tone and melody definitions.
 *
 * Note:
 * - This program uses code from https://www.arduino.cc/en/Tutorial/Tone for tone generation and melody playback.
 *
 * @author Santiago Borja
 * @date 7 - jul - 2025
 */
//hello sara

#include <TM1637TinyDisplay.h>
#include "pitches.h"
#include "melodies.h"

// Pin setup
#define BUTTON_PIN                  32 //Wire to GND (pressed = 0), use 10K resistor
#define BUZZER_PIN                  19
#define LED_PIN                     14 //Use 220 to 300 resistor

//TM1637TinyDisplay 7 segment 4 digit display
#define CLK 11
#define DIO 10
TM1637TinyDisplay display           = TM1637TinyDisplay(CLK, DIO);
const int BRIGHTNESS_DISPLAY        = 5; //(0=dimmest 7=brightest)
const uint8_t allON[]               = {0xff, 0xff, 0xff, 0xff};
const uint8_t allOFF[]              = {0x00, 0x00, 0x00, 0x00};

int mode = 0; //0=countdown, 1=stopwatch, 2=results

void setup() {
  Serial.println("setup");
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  display.setBrightness(BRIGHTNESS_DISPLAY);
  display.clear();
  display.flipDisplay();
  mode = 0;
}

int startTime = 0;
int elapsedTime = 0;

void loop() {
  if (mode == 0) {
    runCountDown();
    mode = 1;
    startTime = millis();
    elapsedTime = 0;
  }

  if (mode == 1) { //Run stopwatch:
    elapsedTime = ( millis() - startTime ) / 100;
    display.showNumberDec(elapsedTime, false);
  }

  if (digitalRead(BUTTON_PIN) == 0) { 
    Serial.println("Button pressed");
    turnLightOn();
    playMelody();
    turnLightOff();
    mode = 2;
  }

  if (mode == 2) {
    flashResults();
  }

  delay(100);
}

/**
 * Flash results on the display until powered off.
 */
void flashResults(){
  Serial.println("Flash results");
  display.clear();
  delay(1000);
  display.showNumberDec(elapsedTime, false);
  delay(1000);
}

void turnLightOn(){
  digitalWrite(LED_PIN, HIGH);
}
void turnLightOff(){
  digitalWrite(LED_PIN, LOW);
}

void playMelody(){
  int size = sizeof(noteDurations) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZER_PIN);
  }
}

void playTone(int freq, int duration) {
  tone(BUZZER_PIN, freq, duration);
  delay(duration * 1.3);
  noTone(BUZZER_PIN);
}

void runCountDown(){
  Serial.println("runCountDown");
  int toneDuration = 200; // milliseconds
  for (int i = 3; i >= 0; i--) {
    Serial.println(i);
    display.showNumberDec(i, false);
    turnLightOn();
    if (i == 0) {
      toneDuration = 800;
    }
    playTone(countdownNotes[i], toneDuration);
    turnLightOff();
    delay(800);
  }
}