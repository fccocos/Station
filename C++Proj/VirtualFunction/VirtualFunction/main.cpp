#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak() { cout << "动物在讲话" << endl; }
};
class Dog :public Animal
{
public:
    void speak() { cout << "狗在讲话" << endl; }
};
void do_work(Animal& obj)
{
    obj.speak();
}
void test01()
{
    Animal p1;
    do_work(p1);

    Dog p2;
    do_work(p2);
}


int main(int argc, char* argv[])
{
	
}