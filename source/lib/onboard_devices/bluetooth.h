#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "../peripheral/uart.h"

#include <memory>
#include <vector>

/**
 * @brief 128bit UUID struct
 */
typedef struct {
    uint8_t Uuid_byte1;
    uint8_t Uuid_byte2;
    uint8_t Uuid_byte3;
    uint8_t Uuid_byte4;
    uint8_t Uuid_byte5;
    uint8_t Uuid_byte6;
    uint8_t Uuid_byte7;
    uint8_t Uuid_byte8;
    uint8_t Uuid_byte9;
    uint8_t Uuid_byte10;
    uint8_t Uuid_byte11;
    uint8_t Uuid_byte12;
    uint8_t Uuid_byte13;
    uint8_t Uuid_byte14;
    uint8_t Uuid_byte15;
    uint8_t Uuid_byte16;
} BLEUuid;

/**
 * @brief GATT permission struct
 */
enum class BLEPermission {
    GATT_PERM_READ_ENCRYPTED,
    GATT_PERM_READ_ENC_MITM,
    GATT_PERM_WRITE,
    GATT_PERM_WRITE_ENCRYPTED,
    GATT_PERM_WRITE_ENC_MITM,
    GATT_PERM_WRITE_SIGNED,
    GATT_PERM_WRITE_SIGNED_MITM,
    GATT_PERM_READ_AUTHORIZATION,
    GATT_PERM_WRITE_AUTHORIZATION,
};

/**
 * @brief BLE Characteristic management class
 */
class BLECharacteristic {
public:
    /**
     * @brief Constructer of BLE Characteristic class
     * @param BLEUuid UUID
     * @param BLEPermission GATT permission
     */
    BLECharacteristic(BLEUuid, BLEPermission);
};

/**
 * @brief BLE Service management class
 */
class BLEService {
public:
    /**
     * @brief Constructer of BLE Service class
     * @param BLEUuid UUID
     */
    BLEService(BLEUuid);

    /**
     * @brief Add a characteristic to current service
     * @param BLECharacteristic BLE Characteristic
     */
    void add_characteristic(BLECharacteristic&);

private:
    std::unique_ptr<std::vector<BLECharacteristic>> _characterics;
};

/**
 * @brief BLE GATT Server management class
 */
class BLEGATTServer {
public:
    /**
     * @brief Constructer of BLE GATT Server constructer
     * @param BLEUuid UUID
     */
    BLEGATTServer(BLEUuid);

    /**
     * @brief Start server
     */
    void start_server();

    /**
     * @brief Add a service to current server
     * @param BLEService BLE Service
     */
    void add_service(BLEService&);

private:
    std::unique_ptr<std::vector<BLEService>> _services;
};

/**
 * @brief BlueTooth management class
 */
class Bluetooth {
public:
    /**
     * @brief Constructer of BlueTooth class
     * @param tx TX pin
     * @param rx RX pin
     */
    Bluetooth(GPIO_no tx, GPIO_no rx)
    {
        _uart = std::make_unique<Uart>(tx, rx, 115200);
        // something more
    }
    Bluetooth(const Bluetooth&) = delete; // copy constructor is deleted

    /**
     * @brief Add a server
     * @param BLEGATTServer BLE GATT Server
     */
    void add_gatt_server(BLEGATTServer&);

private:
    std::unique_ptr<Uart> _uart;
    std::unique_ptr<std::vector<BLEGATTServer>> _gattservices;
};

#endif

/*
// Example
void func()
{
    //server
    //----server1
    //--------characteristic1
    //--------characteristic2
    //--------characteristic3
    //----server2
    //--------characteristic4
    //--------characteristic5
    //--------characteristic6


    BLEUuid temp_uuid = {
        .Uuid_byte1 = 0xff,
        .Uuid_byte2 = 0xff,
        .Uuid_byte3 = 0xff,
        .Uuid_byte4 = 0xff,
        .Uuid_byte5 = 0xff,
        .Uuid_byte6 = 0xff,
        .Uuid_byte7 = 0xff,
        .Uuid_byte8 = 0xff,
        .Uuid_byte9 = 0xff,
        .Uuid_byte10 = 0xff,
        .Uuid_byte11 = 0xff,
        .Uuid_byte12 = 0xff,
        .Uuid_byte13 = 0xff,
        .Uuid_byte14 = 0xff,
        .Uuid_byte15 = 0xff,
        .Uuid_byte16 = 0x00,
    };

    BLEGATTServer server { temp_uuid };

    temp_uuid.Uuid_byte16 = 0x01;
    BLEService service1 { temp_uuid };

    temp_uuid.Uuid_byte16 = 0x02;
    BLECharacteristic characteristic1 { temp_uuid, BLEPermission::GATT_PERM_READ_AUTHORIZATION };

    temp_uuid.Uuid_byte16 = 0x03;
    BLECharacteristic characteristic2 { temp_uuid, BLEPermission::GATT_PERM_WRITE };

    temp_uuid.Uuid_byte16 = 0x04;
    BLECharacteristic characteristic3 { temp_uuid, BLEPermission::GATT_PERM_WRITE_SIGNED };

    temp_uuid.Uuid_byte16 = 0x05;
    BLEService service2 { temp_uuid };

    temp_uuid.Uuid_byte16 = 0x06;
    BLECharacteristic characteristic4 { temp_uuid, BLEPermission::GATT_PERM_WRITE_ENCRYPTED };

    temp_uuid.Uuid_byte16 = 0x07;
    BLECharacteristic characteristic5 { temp_uuid, BLEPermission::GATT_PERM_WRITE_SIGNED };

    temp_uuid.Uuid_byte16 = 0x08;
    BLECharacteristic characteristic6 { temp_uuid, BLEPermission::GATT_PERM_WRITE_ENC_MITM };

    service1.add_characteristic(characteristic1);
    service1.add_characteristic(characteristic2);
    service1.add_characteristic(characteristic3);

    service2.add_characteristic(characteristic4);
    service2.add_characteristic(characteristic5);
    service2.add_characteristic(characteristic6);

    server.add_service(service1);
    server.add_service(service2);
}
*/