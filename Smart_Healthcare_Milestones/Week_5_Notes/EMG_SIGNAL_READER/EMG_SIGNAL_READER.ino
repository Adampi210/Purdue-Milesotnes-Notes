#define BAUD_RATE 9600
#define EMG_SIGNAL_PIN A0

void setup() {
  Serial.begin(9600);
  pinMode(EMG_SIGNAL_PIN, INPUT);
}

void loop() {
  Serial.println(analogRead(EMG_SIGNAL_PIN));
  delay(10);
}
