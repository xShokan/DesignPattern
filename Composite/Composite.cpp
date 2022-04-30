//
// Created by shokanxu on 4/29/2022.
//
#include <set>
#include <string>
#include <iostream>

class Component {
public:
    Component(std::string _Name) : Name(std::move(_Name)) {}

    std::string Name;

    virtual void Add(Component* Obj){};
    virtual void Remove(Component* Obj){};
    virtual void Display(){
        std::cout << Name << std::endl;
    };
};

class Composite : public Component {
private:
    std::set<Component*> ComponentList{};
public:
    using Component::Component;
    virtual void Add(Component *Obj) override {
        ComponentList.insert(Obj);
    }

    virtual void Remove(Component *Obj) override {
        ComponentList.erase(Obj);
    }
    virtual void Display() override {
        Component::Display();
        for (const auto& OneComponent : ComponentList) {
            OneComponent->Display();
        }
    }
};

class Leaf : public Component {
public:
    using Component::Component;
};

int main(){
    auto* Root = new Composite("Root");
    auto* LeafA = new Leaf("LeafA");
    auto* Component = new Composite("ComponentA");
    auto* LeafB = new Leaf("LeafB");
    auto* LeafC = new Leaf("LeafC");

    Component->Add(LeafB);
    Component->Add(LeafC);
    Root->Add(LeafA);
    Root->Add(Component);

    Root->Display();
}