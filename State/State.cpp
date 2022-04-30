//
// Created by shokan on 28/4/2022.
//
#include <iostream>

class State{
public:
    virtual void SetNextState(class Context* ContextObj){};
};

class Context {
private:
    State* StateObj;
public:
    void SetState(State* Obj){
        StateObj = Obj;
    }
    void Request(){
        StateObj->SetNextState(this);
    }
};

class ConcreteStateA : public State {
public:
    virtual void SetNextState(Context* ContextObj);
};

class ConcreteStateB : public State {
public:
    virtual void SetNextState(Context* ContextObj);
};

class ConcreteStateC : public State {
public:
    virtual void SetNextState(Context* ContextObj);
};

void ConcreteStateA::SetNextState(Context *ContextObj){
    std::cout << "Next is ConcreteStateB" << std::endl;
    ContextObj->SetState(new ConcreteStateB());
}

void ConcreteStateB::SetNextState(Context *ContextObj){
    std::cout << "Next is ConcreteStateC" << std::endl;
    ContextObj->SetState(new ConcreteStateC());
}

void ConcreteStateC::SetNextState(Context *ContextObj){
    std::cout << "Next is ConcreteStateA" << std::endl;
    ContextObj->SetState(new ConcreteStateA());
}

int main(){
    Context* Obj = new Context();
    Obj->SetState(new ConcreteStateA());

    Obj->Request();
    Obj->Request();
    Obj->Request();
    Obj->Request();
    Obj->Request();
}