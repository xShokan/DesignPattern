//
// Created by shokan on 4/5/2022.
//
#include <iostream>
#include <string>

class Object;
class Mediator {
public:
    virtual void Send(std::string Message, Object* Obj) {};
};

class Object {
protected:
    Mediator* MediatorObj;
public:
    Object(Mediator* Obj) : MediatorObj(Obj) {}
    virtual void Send(std::string Message) {
        MediatorObj->Send(Message, this);
    }
    virtual void Notify(std::string Message) {}
};

class ConcreteObjectA : public Object {
public:
    using Object::Object;
    virtual void Send(std::string Message) override{
        std::cout << "ConcreteObjectA Send" << Message << std::endl;
        Object::Send(Message);
    }
    virtual void Notify(std::string Message) override{
        std::cout << "ConcreteObjectA Receive" << Message << std::endl;
    }
};

class ConcreteObjectB : public Object {
public:
    using Object::Object;
    virtual void Send(std::string Message) override{
        std::cout << "ConcreteObjectB Send " << Message << std::endl;
        Object::Send(Message);
    }
    virtual void Notify(std::string Message) override{
        std::cout << "ConcreteObjectB Receive" << Message << std::endl;
    }
};

class ConcreteMediator : public Mediator {
private:
    ConcreteObjectA* ObjA;
    ConcreteObjectB* ObjB;
public:
    void SetObjA(ConcreteObjectA* Obj){
        ObjA = Obj;
    }
    void SetObjB(ConcreteObjectB* Obj){
        ObjB = Obj;
    }
    virtual void Send(std::string Message, Object *Obj) override{
        if (Obj == ObjA){
            ObjB->Notify(Message);
        }
        else{
            ObjA->Notify(Message);
        }
    }
};

int main(){
    ConcreteMediator* MediatorObj = new ConcreteMediator();
    ConcreteObjectA* ObjA = new ConcreteObjectA(MediatorObj);
    ConcreteObjectB* ObjB = new ConcreteObjectB(MediatorObj);
    MediatorObj->SetObjA(ObjA);
    MediatorObj->SetObjB(ObjB);

    ObjA->Send("This is A");
    ObjB->Send("This is B");

    return 0;
}