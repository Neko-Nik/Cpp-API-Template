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
