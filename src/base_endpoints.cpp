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
