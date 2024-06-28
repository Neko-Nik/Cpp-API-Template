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


nlohmann::json get_teapot() {
    // Create a JSON object
    nlohmann::json response;
    response["message"] = "I'm a teapot!";
    response["author"] = "Neko Nik";
    response["website"] = "https://NekoNik.com";
    response["status"] = 418;

    // add log message

    return response;
}
