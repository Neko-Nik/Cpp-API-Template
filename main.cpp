/*
 * Commercial Standard License
 * 
 * This file is part of the Neko Nik C++ API.
 * 
 * This software is licensed under the Commercial Standard License.
 * 
 * You may not redistribute or resell the software.
 * Commercial or educational use is NOT allowed.
 * You are allowed to have this software installed on 3 machine(s) at once.
 * 
 * This product does NOT come with any warranty, express or implied.
 * 
 * The full license can be found in the LICENSE file included with this project.
 * 
 * © Neko Nik <https://www.nekonik.com/impressum>
 * 
 * Contact: admin@nekonik.com
 */


#include "crow.h"
#include "json.hpp"
#include "utils/base_endpoints.h"
#include "utils/logger.h"


const char* API_KEY = "1234567890";


int main() {
    // Create Crow app
    crow::SimpleApp app;

    // Hide the console window and build for production
    // app.loglevel(crow::LogLevel::Warning);
    auto logger = get_logger();
    logger->info("Starting the server");

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
        return crow::response(501, response.to_string());
    });

    auto _a = app.port(8086).multithreaded().run_async();

    return 0;
}
