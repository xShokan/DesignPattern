//
// Created by shokanxu on 4/14/2022.
//

#ifndef UNTITLED_BASECOMPONENT_H
#define UNTITLED_BASECOMPONENT_H

#include <vector>
#include <string>

using namespace std;


class BaseComponent {

private:
    vector<BaseComponent*> UpdateComps;

    string Name = "BaseComp";

public:
    virtual void Update();

    void SetName(string NewName);

    void Register(BaseComponent* Comp);

    void BroadCast();
};


#endif //UNTITLED_BASECOMPONENT_H
