#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <iostream>

class Query {
    public:
        std::string ORMRequest(std::string query) {
            return callORM(query);
        }

    private:
        std::string callORM(std::string query) {
            std::cout << "Calling ORM with query: " << query << std::endl;
            return "Response from ORM received";
        }
};

#endif // QUERY_H
