#pragma once
#include <iostream>
using namespace std;

class MyString final
{
public:
	//MyString() = default;
	MyString();
	// 3������
	MyString(const char* ch);
	explicit MyString(size_t len);
	MyString(const MyString& ob);
	MyString(MyString&& ob);

	// 2����ֵ
	MyString& operator=(const MyString& ob);
	MyString& operator=(MyString&& ob) ;
	
	//MyString operator + (const MyString& ob);
	// 1������
	~MyString();

	const MyString& GetString()
	{
		m_refCount++;
		return *this;
	}

	void PrintStringInfo() const
	{
		m_refCount++;
		cout << this->m_ch << endl;
	}

	size_t GetLen() const
	{
		m_refCount++;
		return this->m_len;
	}

	//void SetLen(size_t len)
	//{
	//	m_len = len;	
	//}
private:
	char* m_ch;
	size_t m_len;
	size_t m_allc;
	//mutable int m_refCount;
};

