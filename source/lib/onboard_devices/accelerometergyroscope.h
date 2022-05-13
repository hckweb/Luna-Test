#ifndef ACCELEROMETERGYROSCOPE_H
#define ACCELEROMETERGYROSCOPE_H

#include "../peripheral/i2c.h"

#include <ctime>
#include <memory>

/**
 * @brief Acclerometer struct that can hold x, y and z values
 */
typedef struct {
    double x;
    double y;
    double z;
} accelerometer_s;

/**
 * @brief Gyroscope struct that can hold x, y and z values
 */
typedef struct {
    double x;
    double y;
    double z;
} gyro_s;

/**
 * @brief Accelerometer Gyroscope module management class
 */
class AccelerometerGyroscope {
public:
    /**
     * @brief Constructer of Accelerometer Gyroscope class
     * @param sda SDA pin
     * @param scl SCL pin
     */
    AccelerometerGyroscope(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    AccelerometerGyroscope(const AccelerometerGyroscope&) = delete; // copy constructor is deleted

    /**
     * @brief Get x value of accelerometer
     * @return X value of accelerometer
     */
    double accelerometer_x();

    /**
     * @brief Get y value of accelerometer
     * @return Y value of accelerometer
     */
    double accelerometer_y();

    /**
     * @brief Get z value of accelerometer
     * @return Z value of accelerometer
     */
    double accelerometer_z();

    /**
     * @brief Get values of accelerometer
     * @return Value of accelerometer
     */
    accelerometer_s accelerometer();

    /**
     * @brief Get x value of gyroscope
     * @return X value of gyroscope
     */
    double gyro_x();

    /**
     * @brief Get y value of gyroscope
     * @return Y value of gyroscope
     */
    double gyro_y();

    /**
     * @brief Get z value of gyroscope
     * @return Z value of gyroscope
     */
    double gyro_z();

    /**
     * @brief Get value of gyroscope
     * @return Values of gyroscope
     */
    gyro_s gyro();

private:
    std::unique_ptr<I2c> _i2c;
    gyro_s _gyro;
    accelerometer_s _accelerometer;
};

#endif