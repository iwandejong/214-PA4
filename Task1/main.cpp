//! checks token/nonce validity by checking if the value is 0.
//! if yes then no token/nonce has been asked/received
//! else it is correct
#include "ActualRequest.h"
#include "CheckToken.h"
#include "handler.h"
#include "RequestNonce.h"
#include "user.h"
#include "ValidateSignIn.h"
#include <iostream>

int main() {
    //each main handler object has its own user.
    user newUser;
    handler* mainHandler = new handler();
    mainHandler->add(new RequestNonce());
    mainHandler->add(new ValidateSignIn());
    mainHandler->add(new CheckToken());
    mainHandler->add(new ActualRequest());
    //! main commands: "Validate" = validate sign in,"Request" = request nonce,"Check" = check token, !="" = all other requests
    
    cout<<"Requesting Nonce:"<<endl;
    mainHandler->handle("Request",newUser);
    // cout<<endl;
    cout<<endl;
    cout<<"Validating"<<endl;
    mainHandler->handle("Validate",newUser);
    cout<<endl;
    
    // cout<<endl;
    cout<<"Check Token"<<endl;
    mainHandler->handle("Check",newUser);
    cout<<endl;
    // mainHandler->handle("Give me money",newUser);
    // changed every handle to void from string
    delete mainHandler;
    

    return 0;
}