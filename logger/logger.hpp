/* SIMPLE VECTOR2 STRUCTS
 *   
 * Logs messages to the console with 3 different colors depending on the log type specified
 * Stores all errors into a vector 
 * 
 * TODO: Push errors into log file 
*/

#pragma once 

#include <iostream>
#include <vector>
#include <sstream>

#define LOG_COLOR_START "\033[1;"
#define LOG_COLOR_END "\033[0m"

#define LOG_RED "31m"
#define LOG_YELLOW "33m"
#define LOG_GREEN "32m"
#define LOG_MAGENTA "35m"

namespace utilz
{
    class logger
    {
        public:
            enum LOG_TYPE
            {
                DEFAULT,
                WARNING, 
                SUCCESS,
                ERROR,
            };

            template <typename T>
                static void log(T message) 
                {
                    std::cout << LOG_COLOR_START << LOG_MAGENTA << "[LOG] ->" << LOG_COLOR_END << " " << message; 
                }

            template <typename T>
                static void log(T message, LOG_TYPE type) 
                {

                    std::ostringstream ss;
                    switch (type)
                    {
                        case ERROR: 
                            std::cout << LOG_COLOR_START << LOG_RED << "[ERROR] ->" << LOG_COLOR_END << " " << message; 
                            ss << message;
                            errors.push_back(ss.str());
                            break;
                        case WARNING:
                            std::cout << LOG_COLOR_START << LOG_YELLOW << "[WARNING] ->" << LOG_COLOR_END << " " << message; 
                            break;
                        case SUCCESS:
                            std::cout << LOG_COLOR_START << LOG_GREEN << "[SUCCESS] ->" << LOG_COLOR_END << " " << message; 
                            break;
                        case DEFAULT:
                            std::cout << LOG_COLOR_START << LOG_MAGENTA << "[LOG] ->" << LOG_COLOR_END << " " << message; 
                            break;
                    }
                }

            static void print_errors()
            {
                for (std::string error : errors)
                    std::cout << error << std::endl;
            }

            static std::vector<std::string> get_errors() { return errors; }
        private:
            inline static std::vector<std::string> errors;
    };
}
