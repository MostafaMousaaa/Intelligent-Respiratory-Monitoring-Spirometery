const int flowSensorPin = 2;
const int buttonPin = 3;

volatile int flowPulseCount = 0;

float calibrationFactor = 7.5;
float flowRate;
float totalMilliLitres = 0;

const int RED_LED = 6;
const int GREEN_LED = 7;
const int BUZZER = 8;

bool isExhaling = false;
bool isReady = false;
bool testCompleted = false;

unsigned long exhaleStartTime = 0;
const unsigned long MIN_EXPIRE_TIME = 6000;
unsigned long lastPulseTime = 0;

// FEV1 / FVC
float fev1_volume = 0;
bool fev1_recorded = false;

void setup() {
  pinMode(flowSensorPin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(flowSensorPin), countPulse, RISING);

  Serial.begin(9600);
  Serial.println("System ready. Press button to start test.");
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if button is pressed to allow test
  if (!isReady && digitalRead(buttonPin) == LOW) {
    delay(50); // simple debounce
    if (digitalRead(buttonPin) == LOW) {
      isReady = true;
      testCompleted = false;
      Serial.println("Button pressed. Ready for exhale...");
      resetFeedback();  // signal user to start
    }
  }

  if (!isReady || testCompleted) {
    return; // skip flow reading
  }

  static unsigned long lastCalcTime = 0;
  if (currentMillis - lastCalcTime >= 250) {
    lastCalcTime = currentMillis;

    if (isExhaling) {
      unsigned long elapsed = currentMillis - exhaleStartTime;

      if (elapsed >= MIN_EXPIRE_TIME) {
        detachInterrupt(digitalPinToInterrupt(flowSensorPin));
        flowRate = 0;
        successFeedback();

        Serial.println("6 sec reached. Expiration done.");

        float fvc = totalMilliLitres / 1000.0;
        float fev1 = fev1_volume / 1000.0;
        float ratio = (fvc > 0) ? (fev1 / fvc) * 100.0 : 0;

        Serial.print("FVC: ");
        Serial.print(fvc, 2);
        Serial.print(" L\t");

        Serial.print("FEV1: ");
        Serial.print(fev1, 2);
        Serial.print(" L\t");

        Serial.print("FEV1/FVC Ratio: ");
        Serial.print(ratio, 1);
        Serial.println(" %");

        while (millis() - lastPulseTime < 2000) {
          delay(100);
        }

        // Reset state for next test
        isExhaling = false;
        isReady = false;
        testCompleted = true;
        totalMilliLitres = 0;
        fev1_volume = 0;
        fev1_recorded = false;

        attachInterrupt(digitalPinToInterrupt(flowSensorPin), countPulse, RISING);
        Serial.println("Press button to start next test.");
        return;
      }

      noInterrupts();
      int pulseCount = flowPulseCount;
      flowPulseCount = 0;
      interrupts();

      flowRate = (pulseCount / calibrationFactor) * (1000.0 / 250.0);
      lastPulseTime = currentMillis;

      float flowMilliLitres = (flowRate / 60.0) * 250.0;
      totalMilliLitres += flowMilliLitres;

      if (!fev1_recorded && (elapsed >= 1000)) {
        fev1_volume = totalMilliLitres;
        fev1_recorded = true;
      }

      Serial.print("Flow: ");
      Serial.print(flowRate, 2);
      Serial.print(" L/min\t");

      Serial.print("Vol: ");
      Serial.print(totalMilliLitres / 1000.0, 3);
      Serial.print(" L\t");

      Serial.print("Time: ");
      Serial.print(elapsed / 1000.0, 2);
      Serial.println(" s");

    } else {
      noInterrupts();
      int pulseCount = flowPulseCount;
      flowPulseCount = 0;
      interrupts();

      flowRate = (pulseCount / calibrationFactor) * (1000.0 / 250.0);

      if (flowRate > 0.5) {
        isExhaling = true;
        exhaleStartTime = currentMillis;
        lastPulseTime = currentMillis;
        totalMilliLitres = 0;
        fev1_volume = 0;
        fev1_recorded = false;
        Serial.println("Exhale started...");
      }
    }
  }
}

void countPulse() {
  flowPulseCount++;
}

void successFeedback() {
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  tone(BUZZER, 1000, 200);
}

void resetFeedback() {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  tone(BUZZER, 500, 400);
  delay(400);
  noTone(BUZZER);
  digitalWrite(RED_LED, LOW);
}
