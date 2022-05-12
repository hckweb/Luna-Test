#ifndef MQQT_H
#define MQQT_H

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

class Mqqt {
public:
    void begin(const std::string broker, uint16_t port);
    void subscribe(const std::string topic);
    void publish(const std::string topic, const std::string message);
    void set_callback(void (*callback)(const std::string income_msg));

private:
    void (*_callback)(const std::string);
    std::unique_ptr<std::vector<std::string>> _subcrided_topics;
};

#endif