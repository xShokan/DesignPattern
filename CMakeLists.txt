cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp
        Delegation/BaseComponent.cpp Delegation/BaseComponent.h
        Delegation/Component1.h Delegation/Component1.cpp
        Delegation/Component2.h Delegation/Component2.cpp
        Prototype/Prototype.h Prototype/Prototype.cpp
        Strategy/Strategy.cpp)

add_executable(Strategy Strategy/Strategy.cpp)
add_executable(Decorator Decorator/Decorator.cpp Builder/Builder.cpp)
add_executable(Proxy Proxy/Proxy.cpp)
add_executable(Factory Factory/Factory.cpp)
add_executable(Template Template/Template.cpp)
add_executable(Facade Facade/Facade.cpp)
add_executable(Builder Builder/Builder.cpp)
add_executable(Observer Observer/Observer.cpp)
add_executable(Observer1 Observer/Observer1.cpp)
add_executable(State State/State.cpp)
add_executable(Adapter Adapter/Adapter.cpp)
add_executable(Memento Memento/Memento.cpp)