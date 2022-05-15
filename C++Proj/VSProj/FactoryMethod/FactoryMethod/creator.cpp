#include "creator.h"
#include <iostream>
#include "product.h"

Creator::Creator()
{
    std::cout<<"Creator constructor"<<std::endl;

}
Creator::~Creator()
{
    std::cout<<"Creator destructor"<<std::endl;
}

void Creator::doOthersSomething()
{

    Product* pro = createProduct();
    pro->case01();
    pro->case02();
}


ConcreteProuductA::ConcreteProuductA()
{
    std::cout<<"ConcreteProuductA constructor"<<std::endl;
}

Product *  ConcreteProuductA::createProduct()
{
    return new ProductA();
}

ConcreteProuductA::~ConcreteProuductA()
{
    std::cout<<"ConcreteProuductA destructor"<<std::endl;
}


ConcreteProuductB::ConcreteProuductB()
{
    std::cout<<"ConcreteProuductB constructor"<<std::endl;
}

Product * ConcreteProuductB::createProduct()
{
    return new ProductB();
}
ConcreteProuductB::~ConcreteProuductB()
{
    std::cout<<"ConcreteProuductB destructor"<<std::endl;
}
