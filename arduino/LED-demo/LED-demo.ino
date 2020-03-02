void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

long lastMillis = 0;
int counter = 0;

void loop() {
  while (Serial.available() > 0) {
    int x = Serial.read();
    if (x == 'X') {
      digitalWrite(LED_BUILTIN, 1);
    } else {
      digitalWrite(LED_BUILTIN, 0);
    }
  }

  if (millis() > lastMillis + 1500) {
    lastMillis = millis();
    // Single-character ASCII output, A to J:
    Serial.write('A' + counter);
    counter = (counter + 1) % 10;
  }
}
