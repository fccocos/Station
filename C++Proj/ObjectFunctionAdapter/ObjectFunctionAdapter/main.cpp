#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Adapter1st: public binary_function<int, int,void>
{
public:
	void operator()(int i, int val) const
	{
		cout << i << "+" << val << "=" << i + val << endl;
	}

};

class Compare
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
struct print
{
	void operator()(int a) { cout << a << endl; }
};

void test()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(6);
	v.push_back(11);
	v.push_back(5);
	for_each(v.begin(), v.end(), bind2nd(Adapter1st(), 2));
	sort(v.begin(), v.end(), Compare());
	for_each(v.begin(), v.end(), print());
	for_each(v.begin(), v.end(), bind2nd(Adapter1st(), 2));

}

int main()
{
	test();
}