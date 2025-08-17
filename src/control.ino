int inputarr[3] = {10, 11, 12};
int outputarr[3] = {6, 7, 8};

unsigned long before = 0;
bool locked = false;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(inputarr[i], INPUT_PULLUP); //추후 수정 내부풀업
    pinMode(outputarr[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();
  if (locked && (now - before > 700)) {
    locked = false;
  } 

  if (pressed() != -1 && locked == false) {
    Serial.println(pressed());
    before = millis();
    locked = true;
    delay(200);
  }
}

int pressed() {
  for (int col = 0; col < 3; col++) {
    for (int i = 0; i < 3; i++) { 
      digitalWrite(outputarr[i], LOW);
    }
    digitalWrite(outputarr[col], HIGH);

    for (int row = 0; row < 3; row++) {
      if (digitalRead(inputarr[row]) == HIGH) {
        return row * 3 + col + 1;
      }
    }
  }
  return -1;
}
