//
// Created by shokanxu on 4/22/2022.
//
#include <iostream>
#include <vector>
#include <string>

class Product{
std::vector<std::string> Parts;
public:
    void AddPart(const std::string& Part){
        Parts.push_back(Part);
    }
    void Show(){
        for (const auto& Part : Parts) {
            std::cout << Part;
            if (Part != Parts[Parts.size() - 1])
                std::cout << " ";
            else
                std::cout << std::endl;
        }
    }
};

class Builder{
protected:
    Product* product = new Product();
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    Product* GetResult(){
        return product;
    }
};

class ConcreteBuilderA : public Builder{
public:
    virtual void BuildPartA() override{
        product->AddPart("ConcreteBuilderA-PartA");
    }
    virtual void BuildPartB() override{
        product->AddPart("ConcreteBuilderA-PartB");
    }
};

class ConcreteBuilderB : public Builder{
public:
    virtual void BuildPartA() override{
        product->AddPart("ConcreteBuilderB-PartA");
    }
    virtual void BuildPartB() override{
        product->AddPart("ConcreteBuilderB-PartB");
    }
};

class Director{
public:
    void Construct(Builder* builder){
        builder->BuildPartA();
        builder->BuildPartB();
    }
};

int main(){
    Director* director = new Director();

    Builder* builder1 = new ConcreteBuilderA();
    director->Construct(builder1);
    Product* product1 = builder1->GetResult();
    product1->Show();
    std::cout << "--------------" << std::endl;

    Builder* builder2 = new ConcreteBuilderB();
    director->Construct(builder2);
    Product* product2 = builder2->GetResult();
    product2->Show();
}