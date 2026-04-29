/*
#include <Arduino.h>
#include <ESP32Servo.h>

Servo myServo;
const int servoPin = 5;       // Servo signal pin
const int touchPin = 8;       // Touch sensor signal pin

int currentAngle = 0;         // Current servo position
int direction = 1;            // +1 = increasing angle, -1 = decreasing
bool lastTouchState = LOW;    // For edge detection (detect when pressed)
bool inprogress = false;   // To avoid multiple triggers
void setup() {
  Serial.begin(115200);

  myServo.setPeriodHertz(50);             // 50 Hz servo signal
  myServo.attach(servoPin, 500, 2400);

  pinMode(touchPin, INPUT);
  myServo.write(currentAngle);

  Serial.println("Touch sensor + Servo control initialized.");
}

void loop() {
  bool touchState = digitalRead(touchPin);

  // Detect rising edge (touch just activated)
  if (touchState == HIGH && lastTouchState == LOW && !inprogress) {
    inprogress = true;
    Serial.println("Touch detected!");

    currentAngle = 50;
    // Move servo
    myServo.write(currentAngle);
    Serial.printf("Moved to %d degrees\n", currentAngle);

    delay(3000); // small debounce delay

    myServo.write(0);
    inprogress = false;

  }

  lastTouchState = touchState;
}

/* #include <Adafruit_NeoPixel.h>

#define LED_PIN   10    // DIN pin connected to GPIO47
#define LED_COUNT 1     // Number of WS2812 LEDs

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();          // Initialize library
  pixels.clear();          // Set all pixels to 'off'
  pixels.show();
  Serial.println("setup complete");
}

void loop() {
  // RED
  Serial.println("entering the loop");
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  delay(3000);
  Serial.println("red");

  // GREEN
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();
  delay(3000);
  Serial.println("green");

  // BLUE
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show();
  delay(3000);
  Serial.println("blue");
}
 */
  /* // OFF
  pixels.clear();
  pixels.show();
  delay(3000);
   */
/* #define TEST_PIN 16  // The GPIO you want to test

void setup() {
  // Initialize serial (optional, for debugging)
  Serial.begin(115200);
  Serial.println("Starting GPIO 15 test...");

  // Configure the pin as output
  pinMode(TEST_PIN, OUTPUT);
}

void loop() {
  // Turn pin HIGH
  digitalWrite(TEST_PIN, HIGH);
  Serial.println("GPIO 15 HIGH");
  delay(5000);  // Wait 5 seconds

  // Turn pin LOW
  digitalWrite(TEST_PIN, LOW);
  Serial.println("GPIO 15 LOW");
  delay(5000);  // Wait 5 seconds
} */

/* #define LED_BUILTIN 2  // change to 8, 48, or 2 if needed

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(500);
}
 */
