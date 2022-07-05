// STL_newspeciTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <functional>
#include <vector>
#include <map>

namespace STLTest {

    void _do(const std::string str, std::function<void* ()> cb)
    {
        std::cout << str << std::endl; 
        std::cout<<*((std::string*)cb()) << std::endl;
    }
    void Lamada_Test()
    {
        /*
        * 语法：
        * [...](...) mutable throwSpec ->retType{statement}
        */
        //用法一：
        auto lam = [] {std::cout << "Hello Lamada" << std::endl; };
        //用法二：带参数得lamada
        auto lam2 =[](const std::string& str) {std::cout << "Hello Lamada, there is a input argument: " <<str<< std::endl; };
        lam2("OK");
        //用法三：带返回值类型的lamada
        double (*func_ptr)() = []()->double {return 44; };
        double val = func_ptr();
        std::cout << "lamada_retVal = "<< val << std::endl;
        decltype(func_ptr()) ret = 77;
        std::cout << ret << std::endl;
        //用法四：用lamada写回调函数
        std::string str2("Use a lamada to callback");
        _do(str2, [=]() mutable ->void* {
            std::string str(",Modify the string");
            str2 += str;
            return &str2;
            });

        //用法五：用lamada表达式来修改域外数据
        //显示法
        auto lam3 = [&val] {
            std::cout << "Original Value:" <<val<<std::endl;
            val++;
            std::cout << "Modified Value:" << val << std::endl;
        };
        val = 10;
        lam3();
    }

    template <class T>
    void printElems(const T& coll)
    {
        for (const auto& it : coll)
        {
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }
    void Range_Based_for_Test()
    {
        std::cout << "********************************" << std::endl;
        std::cout << "Range-based for循环 " << std::endl;
        std::vector<int> list{ 1,2,3,4,5,6,7,8,9 };
        for (const auto& it : list)
        {
            std::cout << it << "";
        }
        std::cout << std::endl;
       //打印某个容器中的所有元素
        std::cout << std::endl;
        std::vector<std::string> vec_coll{"Hello","Welcome to", "here", "in", "Hunang."};
        printElems(vec_coll);

        for (const auto& it : { 1,2,3,4,5,566,56,56,5,65,6,5 })
        {
            std::cout << it << " ";
        }
        std::cout << std::endl;

    }

    void String_Literal_Test()
    {
        std::cout << "*******************************" << std::endl;
        std::cout << "New String Literal Test" << std::endl;
        //Raw String Literral;将转义字符全部变成普通字符输出
        std::cout<<R"ec(Raw String Literral: a\n\\\\nc \ec \ec \ec  \\bn()")ec"<<std::endl;
        //Encoded String Literal 编码字符串字面量
        //u8 将字符处理成utf-8的字符格式
        std::cout << u8":orange: :one: :two: 中国人"<<std::endl;
        //u 字符为char16_t类型 两个字节
        std::cout << u"123456789" << std::endl;//00007FF 7 D 3 2 1 5 2 E 8
        std::cout << u"abcdefg" << std::endl;  //00007FF 7 7 0 5 7 5 1 B 8
        //U 字符为char32_t类型 4个字节
        std::cout << U"123456789" << std::endl; //00007FF7705751C8    
        std::cout << U"abcdefg" << std::endl;   //00007FF770575330
        //L 字符为宽字符 wchar_t
        std::cout << L"中国人" << std::endl;    // 00007FF748585350
        std::cout << L"0123456789" << std::endl;// 00007FF748584E10


    }

}

int main()
{
    STLTest::Lamada_Test();
    STLTest::Range_Based_for_Test();
    STLTest::String_Literal_Test();

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
