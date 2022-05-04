//
// Created by shokan on 4/5/2022.
//
#include <iostream>
#include <list>

class Receiver {
public:
    void Action() {
        std::cout << "Receiver Action" << std::endl;
    }
};

class Command {
protected:
    Receiver* ReceiverObj;
public:
    Command(Receiver* Obj) : ReceiverObj(Obj) {}
    virtual void Execute() {}
};

class ConcreteCommandA : public Command {
public:
    using Command::Command;
    virtual void Execute() override {
        std::cout << "ConcreteCommandA Execute" << std::endl;
        ReceiverObj->Action();
    }
};

class ConcreteCommandB : public Command {
public:
    using Command::Command;
    virtual void Execute() override {
        std::cout << "ConcreteCommandB Execute" << std::endl;
        ReceiverObj->Action();
    }
};

class Invoker {
private:
    std::list<Command*> CommandList{};
public:
    void AddCommand(Command* Obj){
        CommandList.push_back(Obj);
    }
    void RemoveCommand(Command* Obj){
        CommandList.remove(Obj);
    }
    void Broadcast(){
        for (const auto& OneCommand : CommandList) {
            OneCommand->Execute();
        }
    }
};

int main(){
    Invoker* Ivk = new Invoker();
    Receiver* Rcv = new Receiver();
    ConcreteCommandA* CmdA = new ConcreteCommandA(Rcv);
    ConcreteCommandB* CmdB = new ConcreteCommandB(Rcv);
    Ivk->AddCommand(CmdA);
    Ivk->AddCommand(CmdB);

    Ivk->Broadcast();
}