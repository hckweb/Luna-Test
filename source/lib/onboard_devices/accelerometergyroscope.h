#ifndef ACCELEROMETERGYROSCOPE_H
#define ACCELEROMETERGYROSCOPE_H

#include "../peripheral/i2c.h"

#include <ctime>
#include <memory>

typedef struct {
    double x;
    double y;
    double z;
} accelerometer_s;

typedef struct {
    double x;
    double y;
    double z;
} gyro_s;

class AccelerometerGyroscope {
public:
    AccelerometerGyroscope(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    AccelerometerGyroscope(const AccelerometerGyroscope&) = delete; // copy constructor is deleted

    double accelerometer_x();
    double accelerometer_y();
    double accelerometer_z();
    accelerometer_s accelerometer();

    double gyro_x();
    double gyro_y();
    double gyro_z();
    gyro_s gyro();

private:
    std::unique_ptr<I2c> _i2c;
    gyro_s _gyro;
    accelerometer_s _accelerometer;
};

#endif