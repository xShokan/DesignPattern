//
// Created by shokan on 4/5/2022.
//
#include <iostream>

class Handler {
protected:
    Handler* NextHandler;
public:
    virtual void HandleRequest(int Request){}
    void SetNextHandler(Handler* Obj){
        NextHandler = Obj;
    }
};

class ConcreteHandlerA : public Handler {
public:
    virtual void HandleRequest(int Request) override{
        if (Request > 0 && Request <= 10){
            std::cout << "ConcreteHandlerA HandleRequest " << Request << std::endl;
        }
        else if (NextHandler){
            NextHandler->HandleRequest(Request);
        }
    }
};

class ConcreteHandlerB : public Handler {
public:
    virtual void HandleRequest(int Request) override{
        if (Request > 10 && Request <= 20){
            std::cout << "ConcreteHandlerB HandleRequest " << Request << std::endl;
        }
        else if (NextHandler){
            NextHandler->HandleRequest(Request);
        }
    }
};


class ConcreteHandlerC : public Handler {
public:
    virtual void HandleRequest(int Request) override{
        if (Request > 20 && Request <= 30){
            std::cout << "ConcreteHandlerC HandleRequest " << Request << std::endl;
        }
        else if (NextHandler){
            NextHandler->HandleRequest(Request);
        }
    }
};

int main() {
    ConcreteHandlerA* HandlerA = new ConcreteHandlerA();
    ConcreteHandlerB* HandlerB = new ConcreteHandlerB();
    ConcreteHandlerC* HandlerC = new ConcreteHandlerC();

    HandlerA->SetNextHandler(HandlerB);
    HandlerB->SetNextHandler(HandlerC);

    int RequestArr[3] = {5, 15, 25};
    for (int i = 0; i < 3; ++i) {
        HandlerA->HandleRequest(RequestArr[i]);
    }

    return 0;
}