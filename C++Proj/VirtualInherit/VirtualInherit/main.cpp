#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
};
class Sheep :virtual public Animal
{
public:
    int id;
};
class Camel :virtual public Animal
{
public:
    int camel_num;
};
class Alpaca :public Sheep, public Camel
{
public:
    int a;
};

void test()
{
    Alpaca p;
    p.age = 0;
}

int main()
{
    return 0;
}