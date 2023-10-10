#include <iostream>

#define RED_TEXT "\x1B[31m"
#define GREEN_TEXT "\x1B[32m"
#define YELLOW_TEXT "\x1B[33m"
#define RESET_TEXT "\x1B[0m"

#include "adapter.h"

int main() {
    Query* SQLQuery = new Query();
    std::cout << RED_TEXT << "SQL Query with previous database" << RESET_TEXT << std::endl;
    std::cout << SQLQuery->ORMRequest("SELECT * FROM table") << std::endl;
    std::cout << std::endl;

    Adapter* newSQLQuery = new Adapter(SQLQuery);
    std::cout << GREEN_TEXT << "SQL Query with [NEW] database" << RESET_TEXT << std::endl;
    std::cout << newSQLQuery->ORMRequest("FROM table SELECT *") << std::endl;
    std::cout << std::endl;

    delete SQLQuery;
    delete newSQLQuery;

    return 0;
}