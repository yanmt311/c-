֪ʶ��һ�����캯����ε��õ�����

#if 0
class Date
{
public:
	/*
	����
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	*/
	
	/*
	//�������
	//1���Լ��ٶ�дһ���޲ι��캯��
	Date()
	{
		
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//2�����캯��ֱ��д��ȫȱʡ����
	Date(int year = 2021, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	*/
	
	//�˴����õڶ��ַ�����
	
	Date(int year = 2021, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//�����޲ι��캯��
	//Date d0; ---��ʱ���������Ϊϵͳ������Ĭ�ϵĹ��캯����һ���޲ι��캯����һ����ȫȱʡ���캯����
	
	//��������⣬�����ַ�����
	//1���Լ��ٶ�дһ���޲ι��캯��
	//2�����캯��ֱ��д��ȫȱʡ����
	
	//����ȫȱʡ�����Ĺ��캯��
	Date d;//��ʱ����ͨ��
	Date d1(2020, 10, 12);
	return 0;
}
#endif


֪ʶ�������㷽��������ĳ�������е�ֵ�����߸���ĳ��������ֵ
			Date d2(d1);
			int d(c);
#if 0
class Date
{
public:
	// ��Ա����������ʵ�֣����������ܻὫ�䵱����������������
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;

	//	cout << "Date(Date&):" << this << endl;
	//}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//�����޲ι��캯��
	Date d0;
	//����ȫȱʡ�����Ĺ��캯��
	Date d1(2020, 10, 12);
	//����d1�����е�ֵ
	Date d2(d1);

	int a;
	int b = 10;//10
	int c = b; //10
	int d(c);  //10

	return 0;
}
#endif

֪ʶ������ϵͳĬ�����ɵĿ������캯����ǳ���������漰��Դ����

#if 0
// ע�⣺��������漰����Դ����ʱ���������Ҫ��ʽ�ṩ����������
//      �����������н��������Դ�ͷŵ�
//      ������Դй©��

// ע�⣺���������ɵ�Ĭ�Ͽ������캯���ǰ���ǳ������ʽʵ�ֵ�
// ǳ��������һ�������е�����ԭ�ⲻ���Ŀ�������һ��������
// ��������������ͬһ����Դ�������ڶ�������ʱ�÷���Դ���ͷŶ�ζ�����������

// Date��Ŀ������캯���Ƿ�ʵ��û���κ�Ӱ��
// ����String�Ŀ������캯����ʵ�ֲ�����---��Ϊ���������ɵ�Ĭ�Ͽ������캯���ǰ���ǳ�����ķ�ʽʵ�ֵ�

// ע�⣺һ����������漰����Դ����ʱ���������캯���Ǳ���Ҫʵ�ֵ�
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}


	// String��û��ʵ���Լ��Ŀ������캯�����������������һ��
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


void TestString()
{
	String s1("hello world");
	String s2(s1);
}


int main()
{
	TestString();
	return 0;
}
#endif



֪ʶ���ģ���ֵ���������

#if 0
class Date
{
public:
	// ��Ա����������ʵ�֣����������ܻὫ�䵱����������������
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d0;
	Date d1(2020, 10, 12);
	Date d2(d1);
	Date d3(2020, 10, 13);

	// ���ø�ֵ��������غ���
	// ���һ����û����ʽʵ�ָ�ֵ��������غ������������������һ��Ĭ�ϵ�
	// ��ɶ���֮��ĸ�ֵ����
	d1 = d3;

	int a = 10;
	int b = 20;
	a = b;

	return 0;
}
#endif

֪ʶ���壺// ��������漰����Դ����ʱ����ֵ��������غ�������Ҫ��ʽʵ�ֳ���
#if 0
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	String(const String& s)
	{
		cout << "String(const String& s):" << this << endl;
	}


	// String��û��ʵ���Լ��Ŀ������캯�����������������һ��
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


void TestString()
{
	String s1("hello");
	String s2("world");

	// ���ÿ������죬����һ���¶���s3
	String s3(s2);

	// �������칹��
	String s4 = s3;

	// ���������ɵĸ�ֵ����������ǰ���ǳ�����ķ�ʽʵ�ֵ�
	// ��������漰����Դ����ʱ���ᵼ���������������
	// �������������
	// 1. ǳ��������ɺ��һ����Դ�ͷŶ������������
	// 2. s1ԭ���Ŀռ䶪ʧ��--�ڴ�й©
	s1 = s2;
}

int main()
{
	TestString();
	return 0;
}
#endif

֪ʶ��������ֵ���������ע��
class Date
{
public:
	// ��Ա����������ʵ�֣����������ܻὫ�䵱����������������
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	
	//ԭ�ȵ�д��
	bool IsLess(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}

		return false;
	}
	
	// �����Զ������ͣ���������֪����ν�����Ӧ������Ĳ���
	// �����Ҫ�Ը�������������أ��൱�ڸ��߱�������Ը������͵Ķ�����ν��д����������
	bool operator<(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}

		return false;
	}

	// ==
	bool operator==(/*Date* const this, */const Date& d)
	{
		return _year == d._year &&
			   _month == d._month &&
			   _day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// ע�⣺�����������������������
	//void operator@()
	//{

	//}

	Date& operator+=(int days)
	{
		//Date temp(*this);
		//temp._day += days;
		//return temp;
		_day += days;
		return *this;
	}

	Date operator+(int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}

private:
	int _year;
	int _month;
	int _day;
};

enum Data
{ONE, TWO, THREE};

//int operator+(Data a, int b)
//{
//	return a + b;
//}

int main()
{
	Date d1(2020, 10, 12);
	Date d2(2020, 10, 13);

	int a = 10;
	int b = 20;
	if (a < b)
	{
		cout << "a < b" << endl;
	}
	else
	{
		cout << "a >= b" << endl;
	}

	if (d1 < d2)
	{
		cout << "d1 < d2" << endl;
	}
	else
	{
		cout << "d1 >= d2" << endl;
	}

	if (d1.IsLess(d2))
	{
		cout << "d1 < d2" << endl;
	}
	else
	{
		cout << "d1 >= d2" << endl;
	}

	if (d1 != d2)
	{
		cout << "d1 != d2" << endl;
	}
	else
	{
		cout << "d1 == d2" << endl;
	}

	a + 10;
	d1 += 10;

	d2 = d1 + 2;
	return 0;
}




