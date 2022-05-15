#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <iostream>
template <class T>
class Product
{
public:
    virtual T& getProductAttribute()=0;
    virtual void setProductAttribute(const T& attri)=0;
    virtual ~Product(){std::cout<<"Product destructor"<<std::endl;}
protected:
    Product(){std::cout<<"Product constructor"<<std::endl;}
};

template<class T>
class ProductA:public Product<T>
{
public:
    ProductA(){std::cout<<"ProductA no parameter constructor"<<std::endl;}
    ProductA(T attri):mattri(attri){std::cout<<"ProductA parameter constructor"<<std::endl;}
    T& getProductAttribute(){return this->mattri;}
    void setProductAttribute(const T& attri){this->mattri = attri;}
    ~ProductA(){std::cout<<"ProductA constructor"<<std::endl;}
private:
    T mattri;
};

template<class T>
class ProductB:public Product<T>
{
public:
    ProductB(){std::cout<<"ProductB no parameter constructor"<<std::endl;}
    ProductB(T attri):mattri(attri){std::cout<<"ProductB parameter constructor"<<std::endl;}
    T& getProductAttribute(){return this->mattri;}
    void setProductAttribute(const T& attri){this->mattri = attri;}
    ~ProductB(){std::cout<<"ProductB constructor"<<std::endl;}
private:
    T mattri;
};


#endif // PRODUCT_HPP

