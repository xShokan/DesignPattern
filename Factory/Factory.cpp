//
// Created by shokanxu on 4/21/2022.
//

class Product{};

class ConcreteProductA : public Product{};

class ConcreteProductB : public Product{};

class Factory{
public:
    virtual Product* CreateProduct() = 0;
};

class ConcreteFactoryA : public Factory{
public:
    virtual Product* CreateProduct() override{
        return new ConcreteProductA();
    };
};

class ConcreteFactoryB : public Factory{
public:
    virtual Product* CreateProduct() override{
        return new ConcreteProductB();
    };
};

int main(){
    Factory* Factory1 = new ConcreteFactoryA();
    Product* Product1 = Factory1->CreateProduct();

    Factory* Factory2 = new ConcreteFactoryB();
    Product* Product2 = Factory1->CreateProduct();
}