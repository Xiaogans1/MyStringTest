#include "MyString.h"
#include <string.h>
#include <stdlib.h>

MyString::MyString()
{
	m_ch = new char[1];
	if (m_ch == nullptr)
	{
		exit(-1);
	}
	*m_ch = '\0';
	m_len = 0;
	m_allc = 1;	
}

MyString::MyString(const char* ch)
{
	if (ch == nullptr)
	{
		m_ch = new char[1];
		if (m_ch == nullptr)
		{
			exit(-1);
		}
		*m_ch = '\0';
		m_len = 0;
		m_allc = 1;
	}
	else
	{
		size_t len = strlen(ch);
		m_ch = new char[len + 1];
		m_len = len;
		m_allc = len + 1;
		if (m_ch == nullptr)
		{
			exit(-1);
		}
		strcpy(m_ch, ch);
	}
}

MyString::MyString(const MyString& ob)
{
	size_t len = strlen(ob.m_ch);
	m_ch = new char[len + 1];
	m_len = len;
	m_allc = len + 1;
	if (m_ch == nullptr)
	{
		exit(-1);
	}
	strcpy(m_ch, ob.m_ch);
}

MyString::MyString(MyString&& ob)
{
	if (ob.m_ch != nullptr)
	{
		m_ch = ob.m_ch;
		m_len = ob.m_len;
		m_allc = ob.m_allc;
		ob.m_ch = nullptr;
	}
}

MyString& MyString::operator=(const MyString& ob)
{
	// 判断是否自身赋值
	if (this != &ob)
	{
		//  释放原有内存
		delete[] m_ch;

		// 充分分配空间
		size_t len = strlen(ob.m_ch);
		m_len = len;
		m_allc = len + 1;
		m_ch = new char[len + 1];
		if (m_ch == nullptr)
		{
			exit(-1);
		}
		// 赋值操作
		strcpy(m_ch, ob.m_ch);
	}
	// 返回当前对象的引用
	return *this;
}
MyString& MyString::operator=(MyString&& ob)
{
	if (this != &ob)
	{
		delete[] m_ch;
		m_ch = ob.m_ch;
		m_len = ob.m_len;
		m_allc = ob.m_allc;
		ob.m_ch = nullptr;
	}

	return *this;
}

MyString::~MyString()
{
	delete[] m_ch;
	m_ch = nullptr;
}
