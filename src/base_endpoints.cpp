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


#include "../utils/base_endpoints.h"
#include "../utils/logger.h"


// API Key for the API
const char* API_KEY = "1234567890";


// Create a JSON object from the response
nlohmann::json Response::to_json() const {
    return nlohmann::json{{"status", status_code}, {"message", message}};
}


// Convert the JSON object to a string
std::string Response::to_string() const {
    return to_json().dump();
}


// Check the API Key for the request if it is valid
bool check_api_key(const std::string &api_key) {
    return api_key == API_KEY;
}


nlohmann::json get_teapot() {
    // Create a JSON object
    nlohmann::json response;
    response["message"] = "I'm a teapot!";
    response["author"] = "Neko Nik";
    response["website"] = "https://NekoNik.com";
    response["status"] = 418;

    // add log message
    auto logger = get_logger();
    logger->info("Returning a teapot JSON object, status code: 418, Someone requested a teapot!");
    return response;
}
