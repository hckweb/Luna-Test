#include "../externel_devices/positioningmodule.h"
#include "../onboard_devices/accelerometergyroscope.h"
#include "../onboard_devices/rtc.h"
#include "../onboard_devices/temperature.h"
#include "json.h"
#include "mqqt.h"

int func()
{
    Temperature temp(GPIO_no::GPIO0, GPIO_no::GPIO1);
    JsonData temp_json;
    temp_json.key = "Temperature";
    temp_json.number_val = temp();
    //
    RTC rtc(GPIO_no::GPIO0, GPIO_no::GPIO1);
    JsonData rtc_json;
    rtc_json.key = "Date";
    rtc_json.string_val = rtc.get_time();
    //
    PositioningModule gps(GPIO_no::GPIO2, GPIO_no::GPIO3);

    JsonData latitude_json;
    latitude_json.key = "latitude";
    latitude_json.string_val = std::to_string(gps.get_latitude());

    JsonData longitude_json;
    longitude_json.key = "longitude";
    longitude_json.string_val = std::to_string(gps.get_longitude());

    Json gps_json("GPS");
    gps_json.add(latitude_json);
    gps_json.add(longitude_json);
    //
    AccelerometerGyroscope accgyro(GPIO_no::GPIO0, GPIO_no::GPIO1);

    JsonData accelerometer_x_json;
    accelerometer_x_json.key = "x";
    accelerometer_x_json.number_val = accgyro.accelerometer_x();

    JsonData accelerometer_y_json;
    accelerometer_y_json.key = "y";
    accelerometer_y_json.number_val = accgyro.accelerometer_y();

    JsonData accelerometer_z_json;
    accelerometer_z_json.key = "z";
    accelerometer_z_json.number_val = accgyro.accelerometer_z();

    Json accelerometer_json("Accelerometer");
    accelerometer_json.add(accelerometer_x_json);
    accelerometer_json.add(accelerometer_y_json);
    accelerometer_json.add(accelerometer_z_json);

    JsonData gyroscope_x_json;
    gyroscope_x_json.key = "x";
    gyroscope_x_json.number_val = accgyro.gyro_x();

    JsonData gyroscope_y_json;
    gyroscope_y_json.key = "y";
    gyroscope_y_json.number_val = accgyro.gyro_y();

    JsonData gyroscope_z_json;
    gyroscope_z_json.key = "z";
    gyroscope_z_json.number_val = accgyro.gyro_z();

    Json gyroscope_json("Gyroscope");
    gyroscope_json.add(gyroscope_x_json);
    gyroscope_json.add(gyroscope_y_json);
    gyroscope_json.add(gyroscope_z_json);

    Json root;
    root.add(temp_json);
    root.add(rtc_json);
    root.add(gps_json);
    root.add(accelerometer_json);
    root.add(gyroscope_json);

    return 0;
}

/*
{
  "Temperature": 27.5,
  "Date": "2022-06-12T23:35:36.000Z",
  "GPS": {
    "latitude": 38.423733,
    "longitude": 27.142826
  },
  "Accelerometer": {
    "x": 1,
    "y": -0.7,
    "z": 1.5
  },
  "Gyroscope": {
    "x": 4.1,
    "y": -1.7,
    "z": -1.5
  }
}
*/