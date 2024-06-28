#include "crow.h"
#include "json.hpp"
#include "utils/base_endpoints.h"


const char* API_KEY = "1234567890";


int main() {
    // Create Crow app
    crow::SimpleApp app;

    // Hide the console window and build for production
    // app.loglevel(crow::LogLevel::Warning);

    // GET - /teapot - Return a Author JSON object
    CROW_ROUTE(app, "/teapot").methods("GET"_method)([]() {
        return crow::response(418, get_teapot().dump());
    });


    // POST - /execute - Execute a command and return the output
    CROW_ROUTE(app, "/execute").methods("POST"_method)([](const crow::request &req) {
        // Validate the API key from X-API-KEY header
        if (req.get_header_value("X-API-KEY") != API_KEY) {
            return crow::response(401, "{\"message\": \"Unauthorized\", \"status\": 401}");
        }

        // Parse the JSON request
        auto json = nlohmann::json::parse(req.body);

        Response response;
        // Not yet implimented
        response.message = "Not yet implimented";
        response.status_code = 501;

        // write a log message
        CROW_LOG_INFO << "Received a POST request with JSON" << json.dump();

        // Return the JSON response
        return crow::response(501, response.to_json());
    });

    auto _a = app.port(8086).multithreaded().run_async();

    return 0;
}
