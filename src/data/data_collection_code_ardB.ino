#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
    Serial.begin(9600);
    Wire.begin();
    mpu.initialize();

    if (!mpu.testConnection()) {
        Serial.println("MPU6050 connection failed!");
        while (1);
    } else {
        Serial.println("MPU6050 connected!");
    }
}

void loop() {
    int16_t ax, ay, az, gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Convert raw gyro values to degrees/second
    float gyroX = gx / 131.0;
    float gyroY = gy / 131.0;
    float gyroZ = gz / 131.0;

    Serial.print("X: "); Serial.print(gyroX);
    Serial.print(" | Y: "); Serial.print(gyroY);
    Serial.print(" | Z: "); Serial.println(gyroZ);

    delay(100);
}
