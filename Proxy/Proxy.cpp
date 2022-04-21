//
// Created by shokanxu on 4/21/2022.
//
#include <iostream>

class Base{
public:
    virtual void Request(){}
};

class RealObj : public Base{
public:
    virtual void Request() override{
        std::cout << "RealObj Request" << std::endl;
    }
};

class Proxy : public Base{
private:
    RealObj* Obj;
public:
    virtual void Request() override{
        if (!Obj){
            Obj = new RealObj;
        }
        Obj->Request();
    }
};

class Client{
private:
    Proxy* ProxyObj;
public:
    void TestFunc(){
        if (!ProxyObj){
            ProxyObj = new Proxy();
        }
        ProxyObj->Request();
    }
};

int main(){
    Client* ClientObj = new Client();
    ClientObj->TestFunc();
}