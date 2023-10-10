#ifndef TARGET_H
#define TARGET_H

#include <string>

class Target {
    public:
        virtual std::string ORMRequest(std::string data) = 0;
        virtual ~Target() {};
};

#endif // TARGET_H