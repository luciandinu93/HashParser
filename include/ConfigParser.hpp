#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

namespace HashParser{
    class ConfigParser{
    private:
        std::string fileName;
        std::ifstream configFile;
        std::unordered_map<std::string, std::string> configurations;

    public:
        ConfigParser();

        ConfigParser(std::string fileName);

        ~ConfigParser();

        /* Check if a string is full with spaces, tabs, or other redundant character */
        static bool isSpace(std::string toCheck);

        /* Serialize a configFile line to a property-value pair */
        void SerializeProperty(std::string);

        /* Read and maintain all the configurations from the input file */
        void parse();

        /* Return a value of a property */
        std::string GetConfigValue(std::string key);

        /* Print all the property-value pairs */
        friend std::ostream& operator<<(std::ostream& out, HashParser::ConfigParser& parser){
            for(auto it = parser.configurations.begin(); it != parser.configurations.end(); ++it){
                out<<"Property: "<<it->first<<" = "<<it->second<<std::endl;
            }

            return out;
        }

        
    };
}