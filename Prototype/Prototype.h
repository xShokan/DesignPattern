//
// Created by shokanxu on 4/14/2022.
//

#ifndef UNTITLED_PROTOTYPE_H
#define UNTITLED_PROTOTYPE_H
#include <string>
using namespace std;

class Prototype {
private:
    string Name;
public:
    Prototype(string Name):Name(Name){};

    virtual Prototype* clone();

    void PrintName();
};

class ConcreatePrototype : public Prototype{
public:
    using Prototype::Prototype;

    virtual Prototype * clone() override;
};

class Client{
public:
    void TestClone();
};


#endif //UNTITLED_PROTOTYPE_H
