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
// #include "json.hpp"
#include "utils/logger.h"
#include "utils/base_endpoints.h"
#include "utils/implimentation_testing.h"


int main() {
    crow::SimpleApp app;

    app.loglevel(crow::LogLevel::DEBUG);
    auto logger = get_logger();
    logger->info("Starting the server");


    // GET - /teapot - Return a Author JSON object
    CROW_ROUTE(app, "/teapot").methods("GET"_method)([]() {
        return crow::response(418, get_teapot().dump());
    });


    // POST - /execute - Execute a command and return the output
    CROW_ROUTE(app, "/testing").methods("POST"_method)([](const crow::request &req) {
        // Validate the API key from X-API-KEY header
        if (!check_api_key(req.get_header_value("X-API-KEY"))) {
            return crow::response(401, "{\"message\": \"Unauthorized\", \"status\": 401}");
        }
        
        // TODO: Implement the POST request validations
        // if (!post_req_validations(req)) {
        //     return crow::response(400, "{\"message\": \"Bad Request, Invalid JSON\", \"status\": 400}");
        // }

        // Parse the JSON request body if it is present
        auto request_body = nlohmann::json::parse(req.body);

        // Call the pre-implimentation function
        nlohmann::json response_data = pre_implimentations(request_body);

        // write a log message
        CROW_LOG_INFO << "Received a POST request with JSON" << response_data.dump();

        // Return the JSON response
        return crow::response(501, response_data.dump());
    });

    auto _a = app.port(8086).multithreaded().run_async();

    return 0;
}
