//
// Created by shokanxu on 4/21/2022.
//
#include <iostream>

class AbstractClass{
public:
    virtual void Behavior1(){};
    virtual void Behavior2(){};
    void TemplateFunc(){
        Behavior1();
        Behavior2();
    }
};

class ConcreteClassA : public AbstractClass{
public:
    virtual void Behavior1() override{
        std::cout << "ConcreteClassA Behavior1" << std::endl;
    }
    virtual void Behavior2() override{
        std::cout << "ConcreteClassA Behavior2" << std::endl;
    }
};

class ConcreteClassB : public AbstractClass{
public:
    virtual void Behavior1() override{
        std::cout << "ConcreteClassB Behavior1" << std::endl;
    }
    virtual void Behavior2() override{
        std::cout << "ConcreteClassB Behavior2" << std::endl;
    }
};

int main(){
    AbstractClass* ObjA  = new ConcreteClassA();
    ObjA->TemplateFunc();
    AbstractClass* ObjB  = new ConcreteClassB();
    ObjB->TemplateFunc();
}