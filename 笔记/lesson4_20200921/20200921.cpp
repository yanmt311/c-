lesson4
Ŀ¼��
֪ʶ��1�����õ�����
	1.1 �������ͺ�ʵ������һ��
	1.2 �������ͺ�ʵ�����Ͳ�һ�£���������ʱ�ռ���г��ԣ�
֪ʶ��2�����õ�����
	2.1 ��������һ������ʹ������д���ӵļ�
	2.2 ����������Ϊ�������β�
	2.3 �����õķ�ʽ��Ϊ��������ֵ
֪ʶ��3���������αȽ�
	��C++�У��������������ַ�ʽ����ֵ������ַ��������
    3.1 ��ֵ���β���ʵ�ε�һ�ݿ��������ε�Ч�ʵͣ�����ͨ���βθı��ⲿ��ʵ��
    3.2 ����ַ���βα������ʵ�εĵ�ַ������Ч�ʸߣ�����ͨ���βθı��ⲿ��ʵ��
    3.3 �����ã��β�ʵ����ʵ�εı��������۴���Ч��Ҳ�Ƚϸߣ�����ͨ���βθı��ⲿ��ʵ��---���Դﵽ��ָ�����Ƶ�Ч�������ұ�ָ��ɶ��Ը��߸���ȫ
	3.4 �����ñȴ�ֵ��Ч�ʸ�
	3.5 ��ַ�ʹ�������Ч���ϼ���һ��
֪ʶ��4�����ú�ָ�������
	
	

#include <iostream>
using namespace std;

֪ʶ��1�����õ�����
1.1 �������ͺ�ʵ������һ��
#if 0
int main()
{
	int a = 10;
	const int& ra = a;

	// ra = 100;
	a = 200;
	return 0;
}
#endif

1.2 �������ͺ�ʵ�����Ͳ�һ�£���������ʱ�ռ���г��ԣ�
#if 0
int main()
{
	double d = 12.34;
	
	const int& rd = d;

	d = 56.78;
	cout << rd << endl;
	return 0;
}
#endif
���䣺�������ͺ�ʵ�����Ͳ�һ�£�����ǰ��const��ԭ��
	  ��������ʱ�ռ���г���
----------------------------------------------------------------------------------------------------------------------------

֪ʶ��2�����õ�����
2.1 ��������һ������ʹ������д���ӵļ�
#if 0
struct A
{
	int a;
	int b;

	struct B
	{
		int c;
		int d;
	};
	
	B sutB;
};

int main()
{
	A stuA;
	stuA.sutB.c = 10;

	// ����������stuA�ṹ����stuB��Ա�е�c���ʵ��ر��

	stuA.sutB.c = 20;
	stuA.sutB.c = 30;

	int& rc = stuA.sutB.c;
	rc = 40;

	return 0;
}
#endif

//typedef�����õ�����
//typedef���Ǹ�����ȡ������
//����:��һ������ȡ������
#if 0
struct A
{
	int a;
	int b;

	struct B
	{
		int c;
		int d;
	};
	
	B sutB;
};

typedef A::B STUB;

int main()
{
	A stuA;
	stuA.sutB.c = 10;
	stuA.sutB.c = 20;
	stuA.sutB.c = 30;

	// �����Ǹ�һ������ȡ�����ģ�rc��stuA.sutB.c�ı�����
	int& rc = stuA.sutB.c;
	rc = 40;

	// ����һ��B�ṹ��ı���
	A::B b1;
	A::B b2;
	A::B b3;
	
	//typedef���Ǹ�����ȡ������(STUB��A::B�ı���)
	STUB b4;
	return 0;
}
#endif
--------------------------------------------------------------------------------------

2.2 ����������Ϊ�������β�
//ʹ��ָ��
#if 0
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b);
	return 0;
}
#endif


//����������Ϊ�������β�----�����Ͽ���ȡ��C�����е�һ��ָ��
//left��a�ı�����right��b�ı���
//&left = &a    &right = &b
#if 0
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	return 0;
}
#endif


ȱ�㣺������ͨ���β�����ⲿʵ�εģ���������bug
#if 0
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Print(int& r)
{
	r = 100;//���Ӵ�����䣬��ͨ���β�����ⲿʵ�εģ�ȫ����Ϊ100
	cout << r << endl; 
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b);
	Print(a);//100
	Print(b);//100

	Swap(a, b);
	Print(a);//100
	Print(b);//100
	return 0;
}
#endif


���������ʹ��const������
// ���ڸô�ӡ����---������ͨ���β�����ⲿʵ�ε�
// ���飺�������ͨ���β����ı��ⲿʵ�ε�����£�������const����������Ϊ�β�
#if 0
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Print(const int& r)
{	
	//r = 100; ---����
	cout << r << endl; 
}

int main()
{
	int a = 10;
	int b = 20;
	Swap(&a, &b);
	Print(a);
	Print(b);

	Swap(a, b);
	Print(a);
	Print(b);
	return 0;
}
#endif

// �������˼����
// ��C�����У�дһ��������ר����������int*���͵�ָ�룬Swap���������ʵ�֣�
// ��C++�����У�дһ��������ר����������int*���͵�ָ�룬Swap���������ʵ�֣�
    c++�У�һ��ָ�봫�� ---������
	       ����ָ�봫�� ---��һ��ָ�������
�������õ�����
----------------------------------------------------------------------------------------------------------


2.3 �����õķ�ʽ��Ϊ��������ֵʱ��
// һ�����ܷ��غ���ջ�Ͽռ�----���ͣ��ֲ�����
// ��Ϊ�����������󣬺������ڲ��ľֲ������ͱ�������
// ������ⲿ�����õķ�ʽ�����պ����ķ���ֵ���ⲿ������ʵ�����õľ���һ��Ƿ����ڴ�ռ�

#if 0
int& Add(int left, int right)
{
	int ret = left + right;
	cout << "&ret = " << &ret << endl;
	return ret;
}

int main()
{
	// result����Add������ret�ֲ������ı���
	int& result = Add(1,2);
	cout << "&result = " << &result << endl;
	Add(3, 4);
	Add(5, 6);
	return 0;
}
#endif

//���������
// ���أ�ֻҪ���ص�ʵ��/�������ܺ�������������
// ���磺ȫ�ֱ������ֲ���̬�������������͵Ĳ���
#if 0
int& TestRetRef(int& ra)
{
	ra = 10;
	return ra;
}
int main()
{
	int a = 0;
	int& r = TestRetRef(a);
	return 0;
}
#endif
---------------------------------------------------------------------------------------------------

֪ʶ��3���������αȽ�
// ��C++�У��������������ַ�ʽ��
// ��ֵ������ַ��������
// ��ֵ���β���ʵ�ε�һ�ݿ��������ε�Ч�ʵͣ�����ͨ���βθı��ⲿ��ʵ��
// ����ַ���βα������ʵ�εĵ�ַ������Ч�ʸߣ�����ͨ���βθı��ⲿ��ʵ��
// �����ã��β�ʵ����ʵ�εı��������۴���Ч��Ҳ�Ƚϸߣ�����ͨ���βθı��ⲿ��ʵ��---���Դﵽ��ָ�����Ƶ�Ч�������ұ�ָ��ɶ��Ը��߸���ȫ

3.1 �����ñȴ�ֵ��Ч�ʸ�
#if 0
#include <time.h>
struct A{ int a[10000]; };

void TestFunc1(A a){}

void TestFunc2(A& a){}

void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1(a);
	size_t end1 = clock();


	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(a);
	size_t end2 = clock();


	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	TestRefAndValue();
	return 0;
}
#endif

3.2 ��ַ�ʹ�������Ч���ϼ���һ��
#if 0
#include <time.h>
struct A{ int a[10000]; };

void TestFunc1(A* a){}

void TestFunc2(A& a){}

void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1(&a);
	size_t end1 = clock();


	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2(a);
	size_t end2 = clock();


	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A*)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		TestRefAndValue();
		cout << endl;
	}  
	return 0;
}
#endif
----------------------------------------------------------------------------

֪ʶ��4��C++�������и�Ƶ��Ŀ�����ú�ָ����ʲô����
#if 0


void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}


// ����������Ϊ�������β�----�����Ͽ���ȡ��C�����е�һ��ָ��
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	Swap(&a, &b);   // ����int*
	Swap(a, b);     // ����int&

	int* pa = &a;
	*pa = 100;

	int& ra = a;
	ra = 100;

	return 0;
}
#endif


#if 0
int main()
{
	int a = 10;
	int& ra = a;

	int* p = &a;

	int b = 20;
	p = &b;

	char c = 'a';
	char& rc = c;
	char* pc = &c;

	rc++;
	pc++;
	cout << sizeof(rc) << endl;
	cout << sizeof(pc) << endl;

	int*p1;
	int** p2;
	int*** p3;

	int d = 10;
	int& rd = d;
	//int&& rrd = d;
	//int&&& rrrd = d;

	// C++11���������ֵ����
	const int&& rrd = 10;
	return 0;
}
#endif


int main()
{
	const int a = 10;
	int* pa = (int*)&a;

	*pa = 100;

	cout << a << endl;
	cout << *pa << endl;
	return 0;
}