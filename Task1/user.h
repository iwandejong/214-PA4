#ifndef USER_H
#define USER_H
using namespace std;
#include <string>
class user{
    private:
        string nonce;
        string token;
    public:
        void setNonce(string non){
            this->nonce = non;
            // cout<<"nonce set in user to"<<nonce<<endl;
        }
        string getNonce(){
            return this->nonce;
        }
        user(){
            nonce = "0";
            token = "0";
        }
        void setToken(string tok){
            this->token = tok;
        }
        string getToken(){
            return this->token;
        }
        void printMemoryAddress() {
            cout << "Memory Address of this user object: " << this << endl;
        }
};
#endif