#ifndef JSON_H
#define JSON_H

#include <memory>
#include <string>
#include <vector>

/**
 * @brief A struct that can store JSON data
 */
typedef struct {
public:
    std::string key;
    union {
        std::string string_val;
        double number_val;
        bool boolen_val;
    };
} JsonData;

/**
 * @brief Json management class
 */
class Json {
public:
    /**
     * @brief Constructor of default Json object
     * @see Json(std::string key)
     */
    Json();
    /**
     * @brief Constructor of a Json object that holds specific key
     * @param key key of Json data
     * @see Json()
     */
    Json(std::string key);

    /**
     * @brief Add a Json object
     * @param val Json object
     */
    void add(Json val);

    /**
     * @brief Add a JsonData struct
     * @param val JsonData object
     */
    void add(JsonData val);

private:
    std::unique_ptr<std::vector<std::string>> _subcrided_topics;
};

#endif