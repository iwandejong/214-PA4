#ifndef CHECKTOKEN_H
#define CHECKTOKEN_H
#include "handler.h"
class CheckToken:public handler{
    public:
        CheckToken() {
            // newUser.printMemoryAddress();
        }
        void handle(string request,user& passOn){
            if(request == "Check"){
                cout<<"Checking Token in handle"<<endl;
                if(passOn.getNonce() != "0" && passOn.getToken() !="0"){
                    cout<<"Token success"<<endl;
                    cout<<"What would you like to request"<<endl;
                    string userRequest;
                    cin>>userRequest;
                    handler::handle(userRequest,passOn);
                }
                else{
                    cout<<"Error"<<endl;
                }
            }
        }
};
#endif