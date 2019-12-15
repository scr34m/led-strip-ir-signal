#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 1

// 1st mul for arduino
// 2nd mul for RPi3
int agc_mark = 9000 - 40 - 0;
int agc_space = 4500 - 40 - 0;
int mark = 590 - 20 - 50;
int space_0 = 540 - 10 - 65;
int space_1 = 1640 - 10 - 65;

void send_0() {
  digitalWrite(4, LOW);
  usleep(mark);
  digitalWrite(4, HIGH);
  usleep(space_0);
}

void send_1() {
  digitalWrite(4, LOW);
  usleep(mark);
  digitalWrite(4, HIGH);
  usleep(space_1);
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

void send_command(int c) {
  digitalWrite(4, LOW);
  usleep(agc_mark);
  digitalWrite(4, HIGH);
  usleep(agc_space);

  send_byte(0);
  send_byte(255);
  send_byte(c);
  send_byte(255 - c);
}

int main (int argc, char** argv)
{
  if (argc != 2)
    return 1;

  char* p;
  long v = strtol(argv[1], &p, 10);
  printf("Command: %ld\n", v);

  if (wiringPiSetup () == -1)
    return 1;

  pinMode (4, OUTPUT);         // aka BCM_GPIO pin 23

  digitalWrite(4, HIGH);
  delay(1000);

  send_command(v);

  digitalWrite(4, LOW);
  usleep(mark);

  digitalWrite(4, HIGH);

  return 0;
}