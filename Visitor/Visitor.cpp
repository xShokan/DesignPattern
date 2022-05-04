//
// Created by shokan on 5/5/2022.
//
#include <iostream>
#include <string>
#include <list>

class ConcreteElementA;
class ConcreteElementB;
class Visitor {
public:
    std::string Name;
    virtual void VisitConcreteElementA(ConcreteElementA* Obj){};
    virtual void VisitConcreteElementB(ConcreteElementB* Obj){};
};

// Human
class Element {
public:
    std::string Name;
    virtual void Accept(Visitor* Obj){}
};

// Man
class ConcreteElementA : public Element {
public:
    virtual void Accept(Visitor *Obj) override{
        Obj->VisitConcreteElementA(this);
    }
};

// Woman
class ConcreteElementB : public Element {
public:
    virtual void Accept(Visitor *Obj) override{
        Obj->VisitConcreteElementB(this);
    }
};

// Falling
class ConcreteVisitorA : public Visitor {
public:
    virtual void VisitConcreteElementA(ConcreteElementA *Obj) override{
        std::cout << Obj->Name << " " << this->Name << " VisitConcreteElement" << std::endl;
    }
    virtual void VisitConcreteElementB(ConcreteElementB *Obj) override{
        std::cout << Obj->Name << " " << this->Name << " VisitConcreteElement" << std::endl;
    }
};

// Success
class ConcreteVisitorB : public Visitor {
public:
    virtual void VisitConcreteElementA(ConcreteElementA *Obj) override{
        std::cout << Obj->Name << " " << this->Name << " VisitConcreteElement" << std::endl;
    }
    virtual void VisitConcreteElementB(ConcreteElementB *Obj) override{
        std::cout << Obj->Name << " " << this->Name << " VisitConcreteElement" << std::endl;
    }
};

class ObjectStruct {
private:
    std::list<Element*> ElementArr;
public:
    void Add(Element* Obj){
        ElementArr.push_back(Obj);
    }
    void Remove(Element* Obj){
        ElementArr.remove(Obj);
    }
    void Display(Visitor* Obj){
        for (const auto& OneElement : ElementArr) {
            OneElement->Accept(Obj);
        }
    }
};

int main(){
    ConcreteElementA* CEA = new ConcreteElementA();
    CEA->Name = "Man";
    ConcreteElementB* CEB = new ConcreteElementB();
    CEB->Name = "Woman";
    ObjectStruct* OS = new ObjectStruct();
    OS->Add(CEA);
    OS->Add(CEB);
    // Finish Preparing

    ConcreteVisitorA* CVA = new ConcreteVisitorA();
    CVA->Name = "Falling";
    OS->Display(CVA);

    ConcreteVisitorB* CVB = new ConcreteVisitorB();
    CVB->Name = "Success";
    OS->Display(CVB);

    return 0;
}