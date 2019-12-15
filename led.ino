void setup() {
  pinMode(12, OUTPUT);    // sets the digital pin 13 as output
}

int agc_mark = 9000 - 40;
int agc_space = 4500 - 40;
int mark = 590 - 20;
int space_0 = 540 - 10;
int space_1 = 1640 - 10;

void send_0() {
  digitalWrite(12, LOW);
  delayMicroseconds(mark);
  digitalWrite(12, HIGH);
  delayMicroseconds(space_0);
}

void send_1() {
  digitalWrite(12, LOW);
  delayMicroseconds(mark);
  digitalWrite(12, HIGH);
  delayMicroseconds(space_1);
}

void send_byte(int c) {
  for (int bits = 0; bits < 8; bits++) {
    if (c & (1 << bits)) {
      send_1();
    } else {
      send_0();
    }
  }
}

void loop() {
  digitalWrite(12, HIGH);
  delay(1000);
  
  digitalWrite(12, LOW);
  delayMicroseconds(agc_mark);
  digitalWrite(12, HIGH);
  delayMicroseconds(agc_space);

  send_byte(0);
  send_byte(255);
  send_byte(3);
  send_byte(255 - 3);

  digitalWrite(12, LOW);
  delayMicroseconds(mark);

  digitalWrite(12, HIGH);
  delay(1000);
}
