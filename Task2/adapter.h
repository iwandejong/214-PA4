#ifndef ADAPTER_H
#define ADAPTER_H

#include "query.h"
#include "target.h"
#include <sstream>
#include <vector>

class Adapter : public Target {
    private:
        Query* adaptee;
    public:
        Adapter(Query* adaptee) {
            this->adaptee = adaptee;
        }
        std::string ORMRequest(std::string data) {
            std::cout << "Received original ORMRequest: " << data << std::endl;
            std::string specialData = convertToServiceFormat(data);
            return adaptee->ORMRequest(specialData);
        }
        std::string convertToServiceFormat(std::string data) {
            std::istringstream iss(data);
            std::vector<std::string> tokens;

            std::string token;
            while (iss >> token) {
                tokens.push_back(token);
            }

            if (tokens.size() >= 4 && tokens[0] == "FROM" && tokens[2] == "SELECT" && tokens[3] == "*") {
                std::ostringstream oss;
                oss << "SELECT * FROM " << tokens[1];
                for (size_t i = 4; i < tokens.size(); ++i) {
                    oss << " " << tokens[i];
                }
                return oss.str();
            }

            return data;
        }



};

#endif // ADAPTER_H