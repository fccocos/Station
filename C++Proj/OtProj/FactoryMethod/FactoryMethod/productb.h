#ifndef PRODUCTB_H
#define PRODUCTB_H
#include "product.h"

class ProductB : public Product
{
public:
    ProductB();
    virtual void case01() override;
    virtual void case02() override;
    ~ProductB();
};

#endif // PRODUCTB_H
