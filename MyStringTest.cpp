// MyStringTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MyString.h"

using namespace std;

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

MyString funcGetString()
{
	//MyString obj;
	return MyString();
}

MyString funcGetStringWithMore()
{
	MyString obj;
	return std::move(obj); // 画蛇添足
}

MyString funcGetStringComplicated(int i)
{
	MyString obj1;
	MyString obj2;
	if (i == 1)
	{
		return obj1;
	}
	else
	{
		return obj2;
	}
}

int main()
{
	cout << "funcGetString" << endl;
	MyString s1 = funcGetString();

	cout << "funcGetStringWithMore" << endl;
	MyString s2 = funcGetStringWithMore();

	cout << "funcGetStringComplicated" << endl;
	MyString s3 = funcGetStringComplicated(1);
	//int a = 1;
	//int&& move_a = std::move(a);
	//std::cout << a << std::endl;
	//std::cout << move_a << std::endl;
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
