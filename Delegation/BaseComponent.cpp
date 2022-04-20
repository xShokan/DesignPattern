//
// Created by shokanxu on 4/14/2022.
//

#include <iostream>
#include <utility>
#include "BaseComponent.h"

using namespace std;

void BaseComponent::Update() {
    cout << "Update BaseComponent" << endl;
}

void BaseComponent::Register(BaseComponent *Comp) {
    UpdateComps.push_back(Comp);
}

void BaseComponent::BroadCast() {
    for (const auto& Comp: UpdateComps) {
        Comp->Update();
    }
}

void BaseComponent::SetName(string NewName) {
    this->Name = std::move(NewName);
}
