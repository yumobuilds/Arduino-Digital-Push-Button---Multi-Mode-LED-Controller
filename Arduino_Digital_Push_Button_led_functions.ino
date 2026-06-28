const int buttonPin = 3;
const int whiteLED = 12;
const int blueLED = 13;

int mode = 0;
bool lastButtonState = HIGH;

// Timing
unsigned long previousMillis = 0;

// Blink settings
const unsigned long flashInterval = 200;   // Both LEDs flash
const unsigned long policeInterval = 400;  // Alternate flash

bool ledState = false;

void setup() {
  pinMode(buttonPin, INPUT);

  pinMode(whiteLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  digitalWrite(whiteLED, LOW);
  digitalWrite(blueLED, LOW);
}

void loop() {

  bool buttonState = digitalRead(buttonPin);

  // Detect button press (active LOW module)
  if (lastButtonState == HIGH && buttonState == LOW) {

    mode++;

    if (mode > 4)
      mode = 0;

    delay(50); // debounce
  }

  lastButtonState = buttonState;

  switch (mode) {

    case 0:   // OFF
      digitalWrite(whiteLED, LOW);
      digitalWrite(blueLED, LOW);
      break;

    case 1:   // White ON
      digitalWrite(whiteLED, HIGH);
      digitalWrite(blueLED, LOW);
      break;

    case 2:   // Blue ON
      digitalWrite(whiteLED, LOW);
      digitalWrite(blueLED, HIGH);
      break;

    case 3:   // Both flashing together
      if (millis() - previousMillis >= flashInterval) {
        previousMillis = millis();

        ledState = !ledState;

        digitalWrite(whiteLED, ledState);
        digitalWrite(blueLED, ledState);
      }
      break;

    case 4:   // Police lights (alternate)
      if (millis() - previousMillis >= policeInterval) {
        previousMillis = millis();

        ledState = !ledState;

        digitalWrite(whiteLED, ledState);
        digitalWrite(blueLED, !ledState);
      }
      break;
  }
}