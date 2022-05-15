#include "product.h"
#include <iostream>



Product::~Product(){std::cout<<"Product constructor"<<std::endl;}

Product::Product(){std::cout<<"Product destructor"<<std::endl;}




ProductA::ProductA(){std::cout<<"ProductA constructor"<<std::endl;}
void  ProductA::case01(){std::cout<<"A::case1"<<std::endl;}
void  ProductA::case02(){std::cout<<"A::case2"<<std::endl;}
ProductA::~ProductA(){std::cout<<"ProductA destructor"<<std::endl;}



ProductB::ProductB(){std::cout<<"ProductB constructor"<<std::endl;}
void ProductB::case01(){std::cout<<"B::case1"<<std::endl;}
void ProductB::case02(){std::cout<<"B::case2"<<std::endl;}
ProductB::~ProductB(){std::cout<<"ProductB destructor"<<std::endl;}
