//
// Created by shokan on 29/4/2022.
//
#include <string>
#include <iostream>

class Memento {
public:
    std::string State;

    Memento(std::string _State) : State(_State){}
};

class Originator {
public:
    std::string State;
    Memento* CreateMemento(){
        return new Memento(State);
    }
    void SetMemento(Memento* Obj){
        State = Obj->State;
    }
    void PrintState(){
        std::cout << "State Now is " << State << std::endl;
    }
};

class Caretaker {
private:
    Memento* MementoObj;
public:
    void SetMemento(Memento* Obj){
        MementoObj = Obj;
    }
    Memento* GetMemento(){
        return MementoObj;
    }
};

int main(){
    Originator* OG = new Originator();
    OG->State = "On";
    OG->PrintState();

    Caretaker* CT = new Caretaker();
    CT->SetMemento(OG->CreateMemento());

    OG->State = "Off";
    OG->PrintState();

    OG->SetMemento(CT->GetMemento());
    OG->PrintState();

    return 0;
}

