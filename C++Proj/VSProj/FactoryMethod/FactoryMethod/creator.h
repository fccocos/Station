#ifndef CREATOR_H
#define CREATOR_H

class Product;

//实现业务相关的核心逻辑
class Creator
{
public:
    virtual Product* createProduct()=0;
    void doOthersSomething();
    virtual ~Creator()=0;
protected:
     Creator();
};
class ConcreteProuductA:public Creator
{
public:
    ConcreteProuductA();
    virtual Product * createProduct() override;
    ~ConcreteProuductA();
};
class ConcreteProuductB:public Creator
{
public:
    ConcreteProuductB();
    virtual Product * createProduct() override;
    ~ConcreteProuductB();
};

#endif // CREATOR_H
