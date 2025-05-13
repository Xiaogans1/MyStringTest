#include "MyString.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

Encoding MyString::s_encoding = UTF8;
MyString::MyString(): m_len(0), m_allc(1), m_available(m_allc - m_len)
{
	m_ch = new char[1]; // һ����˵�����ڹ��캯����ֱ��new, �п����׳��쳣
	if (m_ch == nullptr)
	{
		exit(-1);
	}
	*m_ch = '\0';
	cout << "MyString()" << endl;
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
	cout << "MyString(const char* ch)" << endl;
}

MyString::MyString(size_t len)
{
	m_ch = new char[len];
	m_len = len - 1;
	m_allc = len;
	if (m_ch == nullptr)
	{
		exit(-1);
	}
	m_ch[len - 1] = '\0';
	cout << "MyString(size_t len)" << endl;
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
	cout << "MyString(const MyString& ob)" << endl;
}

MyString::MyString(MyString&& ob)
{
	if (ob.m_ch != nullptr)
	{
		m_ch = ob.m_ch;
		m_len = ob.m_len;
		m_allc = ob.m_allc;
		ob.m_ch = nullptr;
		ob.m_len = 0;
		ob.m_allc = 0;
	}
	cout << "MyString(MyString&& ob)" << endl;
}

MyString& MyString::operator=(const MyString& ob)
{
	// �ж��Ƿ�����ֵ
	if (this != &ob)
	{
		// ����������Դ
		delete[] m_ch;

		// ��ַ���ռ�
		size_t len = strlen(ob.m_ch);
		m_len = len;
		m_allc = len + 1;
		m_ch = new char[len + 1];
		if (m_ch == nullptr)
		{
			exit(-1);
		}
		// ��ֵ����
		strcpy(m_ch, ob.m_ch);
	}
	// ���ص�ǰ���������
	return *this;
	cout << "operator=(const MyString& ob)" << endl;
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
		ob.m_allc = 0;
		ob.m_len = 0;
	}

	return *this;
	cout << "operator=(MyString&& ob)" << endl;
}

MyString::~MyString()
{
	delete[] m_ch;
	m_ch = nullptr;
	//cout << "~MyString()" << endl;
}
