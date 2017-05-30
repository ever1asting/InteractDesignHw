#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <HMC5883L.h>
#include <Servo.h>

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include <Wire.h>
#endif
#define LED_PIN 5
#define INTERRUPT_PIN 2
#define CalThreshold 0


MPU6050 mpu;
HMC5883L mag;
Servo servo;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

int offsetX = 100, offsetY = -300, offsetZ = 5;
int16_t mx, my, mz;
int servoval;

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
  mpuInterrupt = true;
}

void setup() {
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
  Wire.setClock(400000);
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  Serial.begin(38400);
  while (!Serial);

  Serial.println("Initializing I2C devices...");
  mag.initialize();
  /*mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);*/

  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(mag.testConnection() ?
                 "HMC5883L connection successful" :
                 "HMC5883L connection failed");
  /*Serial.println(mpu.testConnection() ?
                 "MPU6050 connection successful" :
                 "MPU6050 connection failed");*/

  servo.attach(9);
  servoval = 0;
  servo.write(servoval);

  /*Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();*/

  /*mpu.setI2CMasterModeEnabled(false);
    mpu.setI2CBypassEnabled(true) ;
    mpu.setSleepEnabled(false);
    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788);*/

  // make sure it worked (returns 0 if so)
  /*if (devStatus == 0) {
    // turn on the DMP, now that it's ready
    Serial.println(F("Enabling DMP..."));
    mpu.setDMPEnabled(true);

    // enable Arduino interrupt detection
    Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();

    // set our DMP Ready flag so the main loop() function knows it's okay to use it
    dmpReady = true;

    // get expected DMP packet size for later comparison
    packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
    // ERROR!
    // 1 = initial memory load failed
    // 2 = DMP configuration updates failed
    // (if it's going to break, usually the code will be 1)
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
    }*/

  // configure LED for output
  pinMode(LED_PIN, OUTPUT);
  mag.setSampleAveraging(HMC5883L_AVERAGING_8);
  //calibrateMag();

}

void loop() {
  /*if (!dmpReady) return;
    while (!mpuInterrupt && fifoCount < packetSize);
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();*/

  mag.getHeading(&mx, &my, &mz);
  int heading = calculateHeading(mx, my, mz);

  /*if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
    // reset so we can continue cleanly
    mpu.resetFIFO();
    } else if (mpuIntStatus & 0x02) {
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
    mpu.getFIFOBytes(fifoBuffer, packetSize);
    fifoCount -= packetSize;*/
  Serial.print("mag:\t");
  Serial.print(mx - offsetX); Serial.print("\t");
  Serial.print(my - offsetY); Serial.print("\t");
  Serial.print(mz - offsetZ); Serial.print("\t");
  Serial.print(heading); Serial.println("\t");
  // display Euler angles in degrees
  /*mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    Serial.print("ypr\t");
    Serial.print(ypr[0] * 180 / M_PI);
    Serial.print("\t");
    Serial.print(ypr[1] * 180 / M_PI);
    Serial.print("\t");
    Serial.println(ypr[2] * 180 / M_PI);
    }*/

  /*float xh, yh, ayf, axf;
    ayf = ay / 57.0; // Convert to rad
    axf = ax / 57.0; // Convert to rad
    xh = mx * cos(ayf) + my * sin(ayf) * sin(axf) - mz * cos(axf) * sin(ayf);
    yh = my * cos(axf) + mz * sin(axf);

    int rev = 0;
    int var_compass = atan2((double)yh, (double)xh) * (180 / PI) - 90;
    if (var_compass > 0) {
    var_compass = var_compass - 360;
    }
    var_compass = 360 + var_compass;

    Serial.print("heading:\t");
    if (var_compass >= 180) {
    var_compass -= 180;
    rev = 1;
    }
    Serial.print(var_compass); Serial.print("\t");*/

  int rev = 0;
  if (heading >= 180) {
    heading -= 180; rev = 1;
  }
  
  servoval = map(heading, 0, 179, 159, 0);
  Serial.print("servo:\t");
  Serial.println(servoval);
  servo.write(servoval);

  digitalWrite(LED_PIN, rev);

  delay(1000);
}

void calibrateMag()
{
  int x, y, z;
  int xMax, xMin, yMax, yMin, zMax, zMin;
  mag.getHeading(&x, &y, &z);
  xMax = xMin = x;
  yMax = yMin = y;
  zMax = zMin = z;
  offsetX = offsetY = offsetZ = 0;

  Serial.println("Starting Calibration......");
  Serial.println("Please turn your device around in 20 seconds");

  for (int i = 0; i < 2000; i++) {
    mag.getHeading(&x, &y, &z);
    if (x > xMax) xMax = x;
    if (x < xMin) xMin = x;
    if (y > yMax) yMax = y;
    if (y < yMin) yMin = y;
    if (z > zMax) zMax = z;
    if (z < zMin) zMin = z;
    delay(10);
    if (i % 100 == 0) {
      if (abs(xMax - xMin) > CalThreshold)
        offsetX = (xMax + xMin) / 2;
      if (abs(yMax - yMin) > CalThreshold)
        offsetY = (yMax + yMin) / 2;
      if (abs(zMax - zMin) > CalThreshold)
        offsetZ = (zMax + zMin) / 2;
      Serial.print(offsetX);
      Serial.print(" ");
      Serial.print(offsetY);
      Serial.print(" ");
      Serial.println(offsetZ);
    }
  }

  if (abs(xMax - xMin) > CalThreshold)
    offsetX = (xMax + xMin) / 2;
  if (abs(yMax - yMin) > CalThreshold)
    offsetY = (yMax + yMin) / 2;
  if (abs(zMax - zMin) > CalThreshold)
    offsetZ = (zMax + zMin) / 2;

  Serial.print("offsetX:");
  Serial.print("");
  Serial.print(offsetX);
  Serial.print(" offsetY:");
  Serial.print("");
  Serial.print(offsetY);
  Serial.print(" offsetZ:");
  Serial.print("");
  Serial.println(offsetZ);
}

int calculateHeading(int x, int y, int z)
{
  float headingRadians = atan2((double)((y) - offsetY),
                               (double)((x) - offsetX));
  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // For Bytom / Poland declination angle is 4'26E (positive)
  // For Beijing declination angle is 59°11'W (negative)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  //float declinationAngle = -(59 + (11.0 / 60.0)) / (180 / M_PI);
  //headingRadians += declinationAngle;
  int headingDegrees = headingRadians * 180 / M_PI;
  if (headingDegrees >= 360) headingDegrees -= 360;
  if (headingDegrees < 0) headingDegrees += 360;
  return headingDegrees;
}
