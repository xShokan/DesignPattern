//
// Created by shokan on 4/5/2022.
//
#include <iostream>
#include <string>
#include <map>

class Flyweight {
private:
    std::string Name;
public:
    Flyweight(std::string _Name) : Name(_Name) {}
    void Operation(){
        std::cout << "Operation " << Name << std::endl;
    };
};

class FlyweightFactory {
private:
    std::map<std::string, Flyweight*> FlyweightMap;
public:
    Flyweight* GetFlyweightFactory(std::string key){
        auto Iter = FlyweightMap.find(key);
        if (Iter == FlyweightMap.end()){
            Flyweight* Obj = new Flyweight(key);
            FlyweightMap[key] = Obj;
            return Obj;
        }
        else {
            return Iter->second;
        }
    }
};

int main(){
    FlyweightFactory* FF = new FlyweightFactory();

    Flyweight* Fw1 = FF->GetFlyweightFactory("AA");
    Fw1->Operation();

    Flyweight* Fw2 = FF->GetFlyweightFactory("AB");
    Fw2->Operation();

    Flyweight* Fw3 = FF->GetFlyweightFactory("AA");
    Fw3->Operation();

    return 0;
}