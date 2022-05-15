#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
public:
    virtual void case01()=0;
    virtual void case02()=0;
    virtual ~Product();
protected:
    Product();
private:
};

class ProductA:public Product
{
public:
    ProductA();
    virtual void case01();
    virtual void case02();
    ~ProductA();
};

class ProductB:public Product
{
public:
    ProductB();
    virtual void case01();
    virtual void case02();
    ~ProductB();
};

#endif // PRODUCT_H
