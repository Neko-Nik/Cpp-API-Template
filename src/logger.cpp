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


#include "../utils/logger.h"

std::shared_ptr<spdlog::logger> get_logger() {
    static std::shared_ptr<spdlog::logger> logger = nullptr;
    if (!logger) {
        auto max_size = 1048576 * 500;  // 500 MB
        auto max_files = 3;
        logger = spdlog::rotating_logger_mt("NekoNikCppAPI", "logs/NekoNikCppAPI.log", max_size, max_files);
    }
    return logger;
}
