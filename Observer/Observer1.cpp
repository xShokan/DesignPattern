//
// Created by shokan on B7/4/B0B.
//
#include <set>
#include <string>
#include <iostream>

class Subscriber{
public:
    void (*UpdateFunc)(void* PublisherObj);
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
            OneSubscriber->UpdateFunc(this);
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
    SubscriberA(Publisher* Obj, void (*P)(void* Pub)){
        PublisherObj = Obj;
        UpdateFunc = P;
    }
};

class SubscriberB : public Subscriber{
private:
    class Publisher* PublisherObj;
public:
    SubscriberB(Publisher* Obj, void (*P)(void* Pub)) : PublisherObj(Obj){
            UpdateFunc = P;
    }
};

class PublisherA : public Publisher{
    using Publisher::Publisher;
};

class PublisherB : public Publisher{
    using Publisher::Publisher;
};

void UpdateA(void* Obj){
    if (auto PublisherObj = static_cast<Publisher*>(Obj)){
        std::cout << "SubscriberA Now is " << PublisherObj->GetState() << std::endl;
    }
}

void UpdateB(void* Obj){
    if (auto PublisherObj = static_cast<Publisher*>(Obj)){
        std::cout << "SubscriberB Now is " << PublisherObj->GetState() << std::endl;
    }
}

int main(){
    Publisher* PA = new PublisherA("PA State");
    Publisher* PB = new PublisherB("PB State");

    Subscriber* PASA = new SubscriberA(PA, UpdateA);
    Subscriber* PASB = new SubscriberA(PB, UpdateA);
    Subscriber* PBSA = new SubscriberB(PA, UpdateB);
    Subscriber* PBSB = new SubscriberB(PB, UpdateB);

    PA->Attach(PASA);
    PA->Attach(PASB);
    PB->Attach(PBSA);
    PB->Attach(PBSB);

    PA->Broadcast();
    PB->Broadcast();
    return 0;
}
