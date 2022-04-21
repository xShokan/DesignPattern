//
// Created by shokanxu on 4/21/2022.
//
#include <iostream>

class SubSystemA{
public:
    void MethodA(){
        std::cout << "SubSystemA MethodA"  << std::endl;
    }
};

class SubSystemB{
public:
    void MethodB(){
        std::cout << "SubSystemB MethodB"  << std::endl;
    }
};

class SubSystemC{
public:
    void MethodC(){
        std::cout << "SubSystemC MethodC"  << std::endl;
    }
};

class SubSystemD{
public:
    void MethodD(){
        std::cout << "SubSystemD MethodD"  << std::endl;
    }
};

class Facade{
private:
    SubSystemA* SA;
    SubSystemB* SB;
    SubSystemC* SC;
    SubSystemD* SD;
public:
    Facade(){
        SA = new SubSystemA();
        SB = new SubSystemB();
        SC = new SubSystemC();
        SD = new SubSystemD();
    }
    void MethodX(){
        std::cout << "Facade MethodX" << std::endl;
        SA->MethodA();
        SB->MethodB();
    }
    void MethodY(){
        std::cout << "Facade MethodY" << std::endl;
        SC->MethodC();
        SD->MethodD();
    }
};

int main(){
    Facade* FacadeObj = new Facade();
    FacadeObj->MethodX();
    FacadeObj->MethodY();
}