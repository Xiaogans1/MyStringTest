#pragma once
#include <iostream>
using namespace std;

enum Encoding {
	ASCLL = 0, //unicode 编码
	UTF8,
	UTF16,
	UTF32
};

class MyString final
{
public:
	//MyString() = default;
	MyString();
	// 3个构造
	MyString(const char* ch);
	explicit MyString(size_t len);
	MyString(const MyString& ob);
	MyString(MyString&& ob);

	// 2个赋值
	MyString& operator=(const MyString& ob);
	MyString& operator=(MyString&& ob) ;
	
	//MyString operator + (const MyString& ob);
	// 1个析构
	~MyString();

	//const MyString& GetString()
	//{
	//	m_refCount++;
	//	return *this;
	//}

	//void PrintStringInfo() const
	//{
	//	m_refCount++;
	//	cout << this->m_ch << endl;
	//}

	//size_t GetLen() const
	//{
	//	m_refCount++;
	//	return this->m_len;
	//}

	//void SetLen(size_t len)
	//{
	//	m_len = len;	
	//}

	static Encoding GetEncoding() 
	{
		return s_encoding;
	}

	static void SetEncoding(Encoding encoding)
	{
		s_encoding = encoding;
	}
private:
	char* m_ch;
	size_t m_len;
	size_t m_allc;
	size_t m_available;
	//mutable int m_refCount;

	static Encoding s_encoding;
};

