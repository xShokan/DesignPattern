//
// Created by shokan on 3/5/2022.
//
#include <string>
#include <iostream>

class Object {
public:
    std::string Name;
};
class Aggregate;
class Iterator {
private:
    Aggregate* AggregateObj;
    int Count = 0;
public:
    Iterator(Aggregate* Obj) : AggregateObj(Obj) {}

    Object* First();
    Object* End();
    Object* operator++();
    Object* Get();
};

class Aggregate {
public:
    Object* List[10];
    int Num = 10;
    Iterator* CreateIterator(){
        return new Iterator(this);
    }
};

Object* Iterator::First() {
    if (AggregateObj->Num > 0){
        return AggregateObj->List[0];
    }
    else
        return nullptr;
}

Object* Iterator::End() {
    if (AggregateObj->Num > 0){
        return AggregateObj->List[AggregateObj->Num - 1];
    }
    else
        return nullptr;
}

Object* Iterator::operator++() {
    Count++;
    if (Count < AggregateObj->Num){
        return AggregateObj->List[Count];
    }
    return nullptr;
}

Object* Iterator::Get() {
    if (Count < AggregateObj->Num){
        return AggregateObj->List[Count];
    }
    return nullptr;
}

int main(){
    Object* Arr[2];
    Object* Obj1 = new Object();
    Obj1->Name = "This is Obj1";
    Arr[0] = Obj1;
    Object* Obj2 = new Object();
    Obj2->Name = "This is Obj2";
    Arr[1] = Obj2;

    Aggregate* AggregateObj = new Aggregate();
    memcpy(AggregateObj->List, Arr, sizeof(Arr));
    AggregateObj->Num = 2;

    for (Iterator* Iter = AggregateObj->CreateIterator();Iter->Get();++(*Iter)) {
        std::cout << Iter->Get()->Name << std::endl;
    }

    return 0;
}