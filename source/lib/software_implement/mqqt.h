#ifndef MQQT_H
#define MQQT_H

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

/**
 * @brief MQQT protocol class
 */
class Mqqt {
public:
    /**
     * @brief Begin the MQQT via broker and port
     */
    void begin(const std::string broker, uint16_t port);

    /**
     * @brief Subscribe a MQQT topic
     */
    void subscribe(const std::string topic);

    /**
     * @brief Publish a message on a MQQT topic
     */
    void publish(const std::string topic, const std::string message);

    /**
     * @brief Setting callback to read income message
     */
    void set_callback(void (*callback)(const std::string& income_msg));

private:
    void (*_callback)(const std::string);
    std::unique_ptr<std::vector<std::string>> _subcrided_topics;
};

#endif