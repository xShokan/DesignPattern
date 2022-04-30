//
// Created by shokan on 28/4/2022.
//

#include <iostream>

class Adaptee {
public:
    void OldFunc(){
        std::cout << "Adaptee OldFunc" << std::endl;
    }
};

class Adapter {
private:
    Adaptee* AdapteeObj = new Adaptee();
public:
    void NewFunc(){
        AdapteeObj->OldFunc();
    }
};

int main(){
    Adapter* AdapterObj = new Adapter();
    AdapterObj->NewFunc();
}