#include <iostream>
using namespace std;

֪ʶ��1��this�ܷ�Ϊ��
#if 0
class A
{
public:
	/*
	//this��д��
	void TestFunc(A* const this)
	{
	    this->_t = 10;
		cout << this << endl;
	}

	*/

	void Test()
	{
		cout << "A::Test()" << endl;
	}

	void TestFunc()
	{
		//this->_t = 10;

		Test();
		cout << this << endl;
	}

	int _t;
};

int main()
{
	A a1,a2,a3;

	a1.TestFunc();    // call A::TestFunc(&a1)
	a2.TestFunc();    // call A::TestFunc(&a2)
	a3.TestFunc();    // call A::TestFunc(&a3)

	//A::TestFunc();  //����û�ж����޷�����

	// ��Ա��������Ҫͨ�����������е��ã��ڸó�Ա��������֮ǰ��
	// ��������Ҫ����ǰ����ĵ�ַͨ��ecx�Ĵ������ݸ���Ա����
	// 

	A* pa = &a1;
	pa->TestFunc();   // call A::TestFunc(pa);

	pa = &a2;
	pa->TestFunc();   // call A::TestFunc(pa);


	// ע�⣺pa��A*���͵�ָ�룬Ҳ����˵pa��������ָ��A���͵Ķ���
	//      ���paָ��û�кϷ�ָ��ʱ��һ�㶼�ǽ���ָ����Ϊnullptr
	pa = nullptr;
	pa->TestFunc();
	return 0;
}
#endif

֪ʶ��2:���캯������
#if 0

class Date
{
public:
	void SetDate(int year, int month, int day)
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
	Date d1;
	//d._year = 2020;

	d1.SetDate(2020, 10, 11);
	d1.PrintDate();

	Date d2;
	d2.SetDate(2020, 10, 12);
	d2.PrintDate();

	Date d3;
	d3.SetDate(2020, 10, 12);
	d3.PrintDate();

	Date d4(2020,10,13);
	d4.PrintDate();

	int a;
	a = 10;
	cout << a << endl;

	int b = 10;
	cout << b << endl;

	int c(20);
	cout << c << endl;
	return 0;
}
#endif

֪ʶ��3�����캯���������أ���֤������������������ֻ����һ��
#if 0
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;

		//֤������������������ֻ����һ��
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
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


void TestDate()
{
	Date d1(2020, 10, 11);
	d1.PrintDate();


	// ��������ʱ���������Զ����ù��캯����������������һЩ��ʼֵ
	Date d2;
	d2.PrintDate();

	//���������������Ǵ�������
	Date d3();
}

int main()
{
	TestDate();
	return 0;
}
#endif


֪ʶ��4���������û����ʽ���幹�캯������C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯����
         һ���û���ʽ�������������������
4.1 ����ʽ���幹�캯��
#if 0
// �û�û����ʽ�����κι��캯��---��ʽ���û���û���Լ�д
class Date
{
public:
	void SetDate(int year, int month, int day)
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
	// �Ӹ��
	// Ŀǰ��������û����ʽ���幹�캯�������Ǹ����Ծɿ��Դ������󣬵���������ʱ����������Ҫ�Զ����ù��캯��
	// �ù��캯���������ģ����Ǳ��������ɵ�Ĭ���޲ι��캯��
	Date d;
	return 0;
}
#endif

4.2 �û���ʽ�������������������
class Date
{
public:
	// �û���ʽ�����˴��в����Ĺ��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
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

	Time _t;
};


int main()
{
	// Date�����Ѿ���ʽ�����˴������������Ĺ��캯��
	// ��֤�����������᲻�������޲εĹ��캯���أ�

	// ����������ͨ������������������޲ι��캯����
	// ����������ʧ�������û������


	// ���뱨��error C2512: ��Date��: û�к��ʵ�Ĭ�Ϲ��캯������
	// ��������ʽ�����˹��캯��ʱ�������������������޲ε�Ĭ�Ϲ��캯����

	Date d;  // ����d�����ڼ䣬��������Ҫ�����޲εĹ��캯��
	return 0;
}
#endif






#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}

	void PrintTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
#endif



֪ʶ��5���޲εĹ��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ��
#if 0
class Date
{
public:
	// �޲ι��캯��
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	// ȫȱʡ���캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
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
	Date d1(2020, 10, 11);

   // ���֣������Ե����޲ι��캯��������d2��
	//     Ҳ���Ե���ȫȱʡ�Ĺ��캯��������d2
	// �����˶����ԣ��������ͱ�����
	Date d2;
	return 0;
}
#endif


/*
1. ���û�û����ʽ���幹�캯��ʱ��������������һ���޲ε�Ĭ�Ϲ��캯��
*/

#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
		cout << "Time(int,int,int)" << endl;
	}

	void PrintTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	void SetDate(int year, int month, int day)
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

	Time _t;
};



int main()
{
	Date d;
	return 0;
}
#endif


��������
#if 0
typedef int DataType;

class SeqList
{
public:
	//���캯��
	SeqList(int capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);

		_capacity = capacity;
		_size = 0;
	}

	// ��������
	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	
	//˳����һЩ����
	void PushBack(DataType data)
	{
		// ...
	}

	void PopBack()
	{
		if (!Empty())
		{
			_size--;
		}
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}

	bool Empty()
	{
		return _size == 0;
	}

	// ...
	
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};


void TestSeqList()
{
	SeqList s;
	s.PushBack(10);
	s.PushBack(10);
	s.PushBack(10);

	s.PopBack();
}

int main()
{
	TestSeqList();
	return 0;
}
#endif


������������
class String
{
public:
	//���캯��
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	//��������
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


class Person
{
private:
	String _name;
	int _age;
};

void TestPerson()
{
	Person p;
}

int main()
{
	TestPerson();

	String s("hello world");
	return 0;
}

