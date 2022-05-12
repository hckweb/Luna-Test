#ifndef JSON_H
#define JSON_H

#include <memory>
#include <string>
#include <vector>

typedef struct {
public:
    std::string key;
    union {
        std::string string_val;
        double number_val;
        bool boolen_val;
    };
} JsonData;

class Json {
public:
    Json();
    Json(std::string key);

    void add(Json val);
    void add(JsonData val);

private:
    std::unique_ptr<std::vector<std::string>> _subcrided_topics;
};

#endif