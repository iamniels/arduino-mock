#include "arduino-mock/Arduino.h"
#include <ctime>
 #define SECS_YR_2000  ((time_t)(946684800UL)) // the time at the start of y2k

static ArduinoMock* arduinoMock = NULL;
ArduinoMock* arduinoMockInstance() {
  if(!arduinoMock) {
    arduinoMock = new ArduinoMock();
  }
  return arduinoMock;
}

void releaseArduinoMock() {
  if(arduinoMock) {
    delete arduinoMock;
    arduinoMock = NULL;
  }
}

ArduinoMock::ArduinoMock() {
  currentMillis = 0;
  const time_t sysTime = time(0) - SECS_YR_2000;
  setMillisRaw(sysTime*1000);
}

void pinMode(uint8_t a, uint8_t b) {
  assert (arduinoMock != NULL);
  arduinoMock->pinMode(a, b);
}
void digitalWrite(uint8_t a, uint8_t b) {
  assert (arduinoMock != NULL);
  arduinoMock->digitalWrite(a, b);
}

int digitalRead(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->digitalRead(a);
}

int analogRead(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->analogRead(a);
}

void analogReference(uint8_t mode) {
  UNUSED(mode);
}

void analogWrite(uint8_t a, int b) {
  assert (arduinoMock != NULL);
  arduinoMock->analogWrite(a, b);
}

time_t millis(void) {
  assert (arduinoMock != NULL);
  const time_t sysTime = time(0) - SECS_YR_2000;
  arduinoMock->setMillisRaw(sysTime*1000000);
  arduinoMock->millis();
  return arduinoMock->getMillis();
}

uint8_t digitalPinToPort(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->digitalPinToPort(a);
}
uint8_t digitalPinToBitMask(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->digitalPinToBitMask(a);
}
uint8_t* portOutputRegister(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->portOutputRegister(a);
}
uint8_t* portInputRegister(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->portInputRegister(a);
}

uint8_t* digitalPinToPCICR(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->digitalPinToPCICR(a);
}
uint8_t digitalPinToPCICRbit(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->digitalPinToPCICRbit(a);
}
uint8_t* digitalPinToPCMSK(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->digitalPinToPCMSK(a);
}
uint8_t digitalPinToPCMSKbit(uint8_t a) {
  assert (arduinoMock != NULL);
  return arduinoMock->digitalPinToPCMSKbit(a);
}

time_t micros(void) {
  return 0;
}
void delay(time_t a) {
  assert (arduinoMock != NULL);
  arduinoMock->delay(a);
}
void delayMicroseconds(unsigned int us) {
  UNUSED(us);
}

time_t pulseIn(uint8_t pin, uint8_t state, time_t timeout) {
  UNUSED(pin);
  UNUSED(state);
  UNUSED(timeout);
  return 0;
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder,
              uint8_t val) {
  UNUSED(dataPin);
  UNUSED(clockPin);
  UNUSED(bitOrder);
  UNUSED(val);
}

uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
  UNUSED(dataPin);
  UNUSED(clockPin);
  UNUSED(bitOrder);
  return 0;
}

void attachInterrupt(uint8_t, void (*)(void), int mode) {
  UNUSED(mode);
}

void detachInterrupt(uint8_t) {}

void interrupts(void) {}

void noInterrupts(void) {}
