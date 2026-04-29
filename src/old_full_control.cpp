/*#include <Arduino.h>
#include <ESP32Servo.h>

constexpr int SERVO_PIN = 5;     // SG90 signal
constexpr int TOUCH_PIN = 7;     // Touch sensor output

// Timing (ms)
constexpr unsigned long TEN_MIN   = 10000; //600000UL;   // 10 * 60 * 1000
constexpr unsigned long TWO_HOURS = 10000; //7200000UL;  // 2 * 60 * 60 * 1000

Servo myServo;

// Small helper: move to 90°, then back to 0° (short blocking pulse ~1s total)
void pulseServo90() {
  myServo.write(50);
  delay(3000);          // allow move to 90° (SG90 ~0.12s/60°, 500ms is safe)
  myServo.write(0);
  delay(500);          // allow return to 0°
}

// Simple finite-state machine for the sequence
enum class SeqState {
  IDLE,
  PULSE_NOW,
  WAIT_10_MIN,
  PULSE_AFTER_10_MIN,
  WAIT_2_HOURS,
  PULSE_AFTER_2_HOURS,
  DONE
};

SeqState state = SeqState::IDLE;
bool sequenceStarted = false;

unsigned long nextActionAt = 0;      // when the next step should fire (millis)

// Edge-detect + debounce for touch
bool lastTouch = LOW;
unsigned long lastTouchEdgeAt = 0;
constexpr unsigned long DEBOUNCE_MS = 150;
bool inprogress = false;

void setup() {
  Serial.begin(115200);

  pinMode(TOUCH_PIN, INPUT);   // For modules like TTP223, HIGH on touch (active-high)
  myServo.setPeriodHertz(50);
  myServo.attach(SERVO_PIN, 500, 2400);  // SG90 typical pulse limits
  myServo.write(0);

  Serial.println("Ready: Touch once to start the 0→90→0 sequence (now, +10min, +2hr).");
}

void loop() {
  // ---- Touch edge detection (rising edge) ----
  bool touch = digitalRead(TOUCH_PIN);
  unsigned long now = millis();
  
  if (touch == HIGH && lastTouch == LOW && (now - lastTouchEdgeAt) > DEBOUNCE_MS && !inprogress) {  
    lastTouchEdgeAt = now;
    Serial.println("Touch detected.");
    if (!sequenceStarted) {
      sequenceStarted = true;
      inprogress = true;
      state = SeqState::PULSE_NOW;
      Serial.println("Sequence started.");
    } else {
      Serial.println("Sequence already running; ignoring touch.");
    }
  }
  lastTouch = touch;

  // ---- Sequence state machine ----
  switch (state) {
    case SeqState::IDLE:
      // Waiting for first touch
      break;

    case SeqState::PULSE_NOW:
      Serial.println("Step 1: Pulse NOW (0→90→0).");
      pulseServo90();
      nextActionAt = now + TEN_MIN;
      state = SeqState::WAIT_10_MIN;
      Serial.println("Waiting 10 minutes for Step 2...");
      break;

    case SeqState::WAIT_10_MIN:
      if ((long)(now - nextActionAt) >= 0) {
        state = SeqState::PULSE_AFTER_10_MIN;
      }
      break;

    case SeqState::PULSE_AFTER_10_MIN:
      Serial.println("Step 2: Pulse after 10 minutes (0→90→0).");
      pulseServo90();
      nextActionAt = now + TWO_HOURS;
      state = SeqState::WAIT_2_HOURS;
      Serial.println("Waiting 2 hours for Step 3...");
      break;

    case SeqState::WAIT_2_HOURS:
      if ((long)(now - nextActionAt) >= 0) {
        state = SeqState::PULSE_AFTER_2_HOURS;
      }
      break;

    case SeqState::PULSE_AFTER_2_HOURS:
      Serial.println("Step 3: Pulse after 2 hours (0→90→0).");
      pulseServo90();
      state = SeqState::DONE;
      Serial.println("Sequence complete.");
      break;

    case SeqState::DONE:
      // Do nothing. To allow re-trigger after completion, uncomment below:
      // sequenceStarted = false; state = SeqState::IDLE;
      inprogress = false;
      break;
  }
}
*/