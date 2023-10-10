#ifndef SERVER_H
#define SERVER_H
#include "handler.h"
using namespace std;
class ValidateSignIn: public handler{
    public:
        ValidateSignIn() {
            // newUser.printMemoryAddress();
        }
        void handle(string request,user& passOn){
            if(request == "Validate"){
                cout<<"Validating user"<<endl;
                if(passOn.getNonce() == "0"){
                    // return "Failure";
                    cout<<"no nonce"<<endl;
                }
                else{
                    time_t now = time(nullptr);
                    stringstream tokenStream;
                    tokenStream << now << ":" << rand();
                    passOn.setToken(tokenStream.str());
                    // return tokenStream.str();
                }
            }
            else{
                handler::handle(request,passOn);
            }
        } 
};
#endif