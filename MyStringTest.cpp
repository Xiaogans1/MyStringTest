// MyStringTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MyString.h"

void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printMyStringInfo(MyString& myStr)
{
	std::cout << sizeof(myStr) << std::endl;
}

int main()
{
	int a = 1;
	int&& move_a = std::move(a);
	std::cout << a << std::endl;
	std::cout << move_a << std::endl;
	//int x = 1, y = 2;
	//++x = 1;
	//x++ = 2;
	//std::cout << "x = " << x << ", y = " << y << std::endl;
	//mySwap(x, y);
	//std::cout << "x = " << x << ", y = " << y << std::endl;*/
	//
	//MyString strT("hello");
	//printMyStringInfo(strT);
	//MyString str1("hi");  // 
	//MyString str2(str1);  // 左值引用传递方式
	//MyString str3 = std::move(str1); // 有名字右值引用传递方式 --> static_cast<MyString&&>(str1)

	//std::cout << &"hi" << std::endl; // 字符串字面量是有地址的左值
	//const char* p1 = "hi";
	//const char* p2 = "hi";
	
	//std::cout << &(std::move(str1)) << std::endl; // 右值无法取地址
	//MyString str4;
	//str4 = str3;
	//(str4 = str3) = str2;
	//str4 = std::move(str2);

	//MyString str5(5);
	//MyString str6 = 5;
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
