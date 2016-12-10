#define TWI_FREQ 37390L
#include <Wire.h> // MUST COME AFTER TWI_FREQ DEF

#define WRITE 0x02 // supposedly, from the datasheet..
#define REG_MFG 0x08 // 8-bit register, should return "HiTechnc"
#define NUM_BYTES 8
#define M1_MODE 0x44
#define M1_PWR 0x45
#define M2_MODE 0x47
#define M2_PWR 0x46

#define POWER_ONLY B00 // booooo!
#define CONST_SPD B01 // [inhales] ...boi
#define RUN_TO_POS B10
#define RESET_ENC B11


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(true); // done with run, so stop
}

void motor1(char pct) {
  Wire.beginTransmission(WRITE);
  Wire.write(M1_PWR);
  Wire.write(pct);
  Wire.endTransmission(0); // keeps connection alive
}
void motor2(char pct) {
  Wire.beginTransmission(WRITE);
  Wire.write(M2_PWR);
  Wire.write(pct);
  Wire.endTransmission(0); // keeps connection alive
}

void motor1Mode(byte mode) {
  Wire.beginTransmission(WRITE);
  Wire.write(M1_MODE);
  Wire.write(mode);
  Wire.endTransmission(0);
}

void motor2Mode(byte mode) {
  Wire.beginTransmission(WRITE);
  Wire.write(M2_MODE);
  Wire.write(mode);
  Wire.endTransmission(0);
}

