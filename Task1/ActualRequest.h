#ifndef ACTUALREQUEST_H
#define ACTUALREQUEST_H
#include "handler.h"
class ActualRequest: public handler{
    public:
        ActualRequest() {
            // newUser.printMemoryAddress();
        }
        void handle(string request,user& passOn){
            if(request != ""){
                if(passOn.getNonce() == "0" || passOn.getToken() == "0"){
                    cout<<"Token/Nonce incorrect"<<endl;
                }
                else{
                    cout<<"Request: "<<request<<endl<<endl; 
                }
            }
            // return "Done";
            cout<<"Done"<<endl;
        }
};
#endif