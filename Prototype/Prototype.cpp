//
// Created by shokanxu on 4/14/2022.
//

#include <iostream>
#include "Prototype.h"

Prototype *Prototype::clone() {
    return new Prototype(Name);
}

void Prototype::PrintName() {
    cout << "PrintName " << Name << endl;
}

void Client::TestClone() {
    ConcreatePrototype* TestPrototype = new ConcreatePrototype("TestPrototype");
    ConcreatePrototype* TestPrototype1 = dynamic_cast<ConcreatePrototype*>(TestPrototype->clone());
    ConcreatePrototype* TestPrototype2 = dynamic_cast<ConcreatePrototype*>(TestPrototype->clone());
    ConcreatePrototype* TestPrototype3 = dynamic_cast<ConcreatePrototype*>(TestPrototype->clone());
    TestPrototype1->PrintName();
    TestPrototype2->PrintName();
    TestPrototype3->PrintName();
}

Prototype *ConcreatePrototype::clone() {
    return new ConcreatePrototype("ConcreatePrototype");
}
