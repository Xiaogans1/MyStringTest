#pragma once
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
private:
	char* m_ch;
	size_t m_len;
	size_t m_allc;
};

