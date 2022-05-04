//
// Created by shokan on 4/5/2022.
//
#include <iostream>

class Implementor {
public:
    virtual void Func(){};
};

class ConcreteImplementorA : public Implementor {
public:
    virtual void Func() override{
        std::cout << "ConcreteImplementorA Func" << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    virtual void Func() override{
        std::cout << "ConcreteImplementorB Func" << std::endl;
    }
};

class Object {
protected:
    Implementor* ImpObj;
public:
    Object(Implementor* Obj) : ImpObj(Obj) {}
    virtual void Operation(){
        ImpObj->Func();
    }
};

class ConcreteObj : public Object {
public:
    using Object::Object;
};

int main(){
    ConcreteObj* ObjA = new ConcreteObj(new ConcreteImplementorA());
    ConcreteObj* ObjB = new ConcreteObj(new ConcreteImplementorB());
    ObjA->Operation();
    ObjB->Operation();

    return 0;
}