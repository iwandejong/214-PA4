#ifndef HANDLER_H
#define HANDLER_H
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include "user.h"
using namespace std;
class handler{
    public:
        virtual ~handler(){
            if(successor){
                delete successor;
            }
        }
        //take out declaring new user
        handler(): successor(0){
            // newUser.printMemoryAddress();
        };
        void add(handler* next){
            if(successor){
                successor->add(next);
            }
            else{
                successor = next;
            }
        }
        virtual void handle(string request,user& passOn) {
            if(successor){
                successor->handle(request,passOn);
            }
        };
        void setNonce(string input){
            cout<<"nonce set"<<endl;
            this->newUser.setNonce(input);
        }
        string getNonce(){
            return this->newUser.getNonce();
        }
        void setToken(string input){
            cout<<"token set"<<endl;
            this->newUser.setToken(input);
        }
        string getToken(){
            return this->newUser.getToken();
        }
    protected:
        user newUser;
    private:
        handler* successor;
};
#endif