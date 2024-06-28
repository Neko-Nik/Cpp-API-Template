// utils/base_endpoints.h
#ifndef BASE_ENDPOINTS_H
#define BASE_ENDPOINTS_H

#include "json.hpp"

// Response model message and status code
struct Response {
    int status_code;
    std::string message;

    nlohmann::json to_json() const {
        return nlohmann::json{{"status", status_code}, {"message", message}};
    }
};

// Return a teapot JSON object
nlohmann::json get_teapot();

#endif // BASE_ENDPOINTS_H
