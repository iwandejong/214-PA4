#ifndef REQUESTNONCE_H
#define REQUESTNONCE_H
#include "handler.h"

class RequestNonce:public handler{
    public:
        RequestNonce() {
            // newUser.printMemoryAddress();
        }
        void handle(string request,user& passOn){
            if(request == "Request"){
                cout<<"Requesting user Nonce"<<endl;
                time_t currentTime = time(nullptr);
                tm* timeInfo = localtime(&currentTime);
                char buffer[80];
                strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
                string timestampString(buffer);
                passOn.setNonce(timestampString);
                cout<<"Request successful"<<endl;
                // return timestampString;
            }
            else{
                handler::handle(request,passOn);
            }
        }
};
#endif