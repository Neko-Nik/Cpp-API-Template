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


#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include <memory>


// Function to get the logger instance
std::shared_ptr<spdlog::logger> get_logger();
