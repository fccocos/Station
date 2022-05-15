#ifndef CREATOR_HPP
#define CREATOR_HPP
#include "product.hpp"

template <class T>
class Creator
{
public:
    virtual~Creator(){std::cout<<"Creator destructor"<<std::endl;}
    virtual Product<T>* createProduct()=0;

    T& showCreator(){ return this->mAttribute;}
    T& showProduct(){
        Product<T>* pro = createProduct();
        return pro->getProductAttribute();

    }
    void setAttri(const T& attri){this->mAttribute = attri;}
protected:
    Creator(){std::cout<<"Creator no parameter constructor"<<std::endl;}
    Creator(T Attribute):mAttribute(Attribute){std::cout<<"Creator parameter constructor"<<std::endl;}
private:
    T mAttribute;
};

template <class T>
class ConcreteProductA:public Creator<T>
{
public:
    ConcreteProductA(){std::cout<<"ConcreteProductA non-parameter constructor"<<std::endl;}
    ConcreteProductA(T attri):Creator<T>(attri){std::cout<<"ConcreteProductA parameter constructor"<<std::endl;}
    ~ConcreteProductA(){std::cout<<"ConcreteProductA destructor"<<std::endl;}
    Product<T>* createProduct(){

        return new ProductA<T>();
    }
};

template <class T>
class ConcreteProductB:public Creator<T>
{
public:
    ConcreteProductB(){std::cout<<"ConcreteProductB non-parameter constructor"<<std::endl;}
    ConcreteProductB(T attri):Creator<T>(attri){std::cout<<"ConcreteProductB parameter constructor"<<std::endl;}
    ~ConcreteProductB(){std::cout<<"ConcreteProductB destructor"<<std::endl;}
    Product<T>* createProduct(){

       return new ProductB<T>();
    }
};
#endif // CREATOR_HPP
