//
// Created by shokan on B7/4/B0B.
//
#include <set>
#include <string>
#include <iostream>

class Subscriber{
public:
    virtual void Update(){};
};

class Publisher{
private:
    std::set<Subscriber*> SubscriberArr{};
protected:
    std::string PublisherState = "ABC";
public:
    Publisher(std::string State) : PublisherState(State){};
    virtual void Attach(Subscriber* Obj){
        SubscriberArr.insert(Obj);
    }
    virtual void Detach(Subscriber* Obj){
        SubscriberArr.erase(Obj);
    }
    virtual void Broadcast(){
        for (const auto& OneSubscriber : SubscriberArr) {
            OneSubscriber->Update();
        }
    }
    std::string GetState(){
        return PublisherState;
    }
};

class SubscriberA : public Subscriber{
private:
    class Publisher* PublisherObj;
public:
    SubscriberA(Publisher* Obj) : PublisherObj(Obj){};
    virtual void Update() override{
        std::cout << "SubscriberA Now is " << PublisherObj->GetState() << std::endl;
    }
};

class SubscriberB : public Subscriber{
private:
    class Publisher* PublisherObj;
public:
    SubscriberB(Publisher* Obj) : PublisherObj(Obj){};
    virtual void Update() override{
        std::cout << "SubscriberB Now is " << PublisherObj->GetState() << std::endl;
    }
};

class PublisherA : public Publisher{
    using Publisher::Publisher;
};

class PublisherB : public Publisher{
    using Publisher::Publisher;
};

int main(){
    Publisher* PA = new PublisherA("PA State");
    Publisher* PB = new PublisherB("PB State");

    PA->Attach(new SubscriberA(PA));
    PA->Attach(new SubscriberB(PB));
    PB->Attach(new SubscriberB(PA));
    PB->Attach(new SubscriberB(PB));

    PA->Broadcast();
    PB->Broadcast();
    return 0;
}
