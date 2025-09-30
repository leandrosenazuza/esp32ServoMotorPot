/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-servo-motor-controlled-by-potentiometer
 */
#include <Arduino.h>
#include <ESP32Servo.h>

#define PIN_POTENTIOMETER_1 34 // ESP32 pin GPIO36 (ADC0) onnected to potentiometer
#define PIN_POTENTIOMETER_2 32 // ESP32 pin GPIO36 (ADC0) onnected to potentiometer

#define PIN_SERVO_1 25 // ESP32 pin GPIO26 onnected to servo motor
#define PIN_SERVO_2 26 // ESP32 pin GPIO26 onnected to servo motor

Servo myServo;
Servo myServo2;

void setup()
{
  Serial.begin(115200);

  analogSetAttenuation(ADC_11db);

  myServo.attach(PIN_SERVO_1);
  myServo2.attach(PIN_SERVO_2);
}

void loop()
{
  int analogValue1 = analogRead(PIN_POTENTIOMETER_1);
  int analogValue2 = analogRead(PIN_POTENTIOMETER_2);

  int angle1 = map(analogValue1, 0, 4095, 0, 180);
  int angle2 = map(analogValue2, 0, 4095, 0, 180);

  myServo.write(angle1);
  myServo2.write(angle2);

  Serial.print("Analog value 1: ");
  Serial.print(analogValue1);
  Serial.print(" => Angle: ");
  Serial.println(angle1);
  Serial.print("Analog value 2: ");
  Serial.print(analogValue2);
  Serial.print(" => Angle: ");
  Serial.println(angle2);
  delay(100);
}