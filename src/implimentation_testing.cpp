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


// Function to handle any implimentation for the API
// Pre Implimentation Functions are listed here

#include "../utils/logger.h"
#include "../utils/implimentation_testing.h"


// Function which accepts a JSON object and returns a JSON object
nlohmann::json pre_implimentations(const nlohmann::json &request_body) {
    nlohmann::json response;
    response["message"] = "Not yet implimented";
    response["status_code"] = 501;
    response["body_sent"] = request_body;

    auto logger = get_logger();
    logger->info("Pre-Implimentation Functions are not yet implimented");

    return response;
}
