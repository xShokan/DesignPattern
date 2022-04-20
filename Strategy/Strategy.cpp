//
// Created by shokanxu on 4/20/2022.
//

#include <iostream>

class BaseStrategy {
public:
    virtual void Algorithm1(){}
    virtual void Algorithm2(){}
};

class Strategy1 : public BaseStrategy{
public:
    virtual void Algorithm1() override{
        std::cout << "Strategy1 Algorithm1" << std::endl;
    }
    virtual void Algorithm2() override{
        std::cout << "Strategy1 Algorithm2" << std::endl;
    }
};

class Strategy2 : public BaseStrategy{
public:
    virtual void Algorithm1() override{
        std::cout << "Strategy2 Algorithm1" << std::endl;
    }
    virtual void Algorithm2() override{
        std::cout << "Strategy2 Algorithm2" << std::endl;
    }
};

class Context{
private:
    BaseStrategy* Strategy;
public:
    void SetStrategy(BaseStrategy* TempStrategy){
        Strategy = TempStrategy;
    }
    void ExecStrategyAlgo1(){
        Strategy->Algorithm1();
    }
    void ExecStrategyAlgo2(){
        Strategy->Algorithm2();
    }
};

int main(){
    Context* ContextObj = new Context;
    ContextObj->SetStrategy(new Strategy1());
    ContextObj->ExecStrategyAlgo1();
    ContextObj->ExecStrategyAlgo2();
    ContextObj->SetStrategy(new Strategy2());
    ContextObj->ExecStrategyAlgo1();
    ContextObj->ExecStrategyAlgo2();
}
