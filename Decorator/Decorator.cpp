//
// Created by shokanxu on 4/20/2022.
//
#include <iostream>
class Component{
public:
    virtual void Exec(){};
};

class Decorator : public Component{
protected:
    Component* ComponentObj;
public:
    void SetDecorator(Component* Obj){
        if (!ComponentObj){
            ComponentObj = Obj;
        }
    }
    virtual void Exec() override{}
};

class ConcreteDecoratorA : public Decorator{
private:
    void AddBehaviorA(){
        std::cout << "AddBehaviorA" << std::endl;
    }
public:
    virtual void Exec() override{
        ComponentObj->Exec();
        std::cout << "Exec ConcreteDecoratorA" << std::endl;
        AddBehaviorA();
    }
};

class ConcreteDecoratorB : public Decorator{
private:
    void AddBehaviorB(){
        std::cout << "AddBehaviorB" << std::endl;
    }
public:
    virtual void Exec() override{
        ComponentObj->Exec();
        std::cout << "Exec ConcreteDecoratorB" << std::endl;
        AddBehaviorB();
    }
};

int main(){
    Component* Target = new Component();
    ConcreteDecoratorA* DtA = new ConcreteDecoratorA();
    ConcreteDecoratorB* DtB = new ConcreteDecoratorB();

    DtA->SetDecorator(Target);
    DtB->SetDecorator(DtA);
    DtB->Exec();
    return 0;
}