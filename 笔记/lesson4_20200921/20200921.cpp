#include <iostream>
using namespace std;


#if 0
int main()
{
	int a = 10;
	const int& ra = a;

	// ra = 100;
	a = 200;

	double d = 12.34;
	
	const int& rd = d;

	d = 56.78;
	cout << rd << endl;
	return 0;
}
#endif



#if 0
// ��������һ������ʹ������д���ӵļ�
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

 
// typedef�Ǹ�����ȡ������
typedef A::B STUB;




int main()
{
	A stuA;
	stuA.sutB.c = 10;

	// ����������stuA�ṹ����sutB��Ա�е�c���ʵ��ر��

	stuA.sutB.c = 20;
	stuA.sutB.c = 30;


	// �����Ǹ�һ������ȡ������
	int& rc = stuA.sutB.c;
	rc = 40;


	// ����һ��B�ṹ��ı���
	A::B b1;
	A::B b2;
	A::B b3;
	
	STUB b4;
	return 0;
}
#endif



#if 0
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}


// ����������Ϊ�������β�----�����Ͽ���ȡ��C�����е�һ��ָ��
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}


// ���ڸô�ӡ����---������ͨ���β�����ⲿʵ�ε�
// ���飺�������ͨ���β����ı��ⲿʵ�ε�����£�������const����������Ϊ�β�
void Print(const int& r)
{
	// ���ǣ�����д�����ʱ��  ��һ��
	//r = 100;
	cout << r << endl; 
}


// �������˼����
// ��C�����У�дһ��������ר����������int*���͵�ָ�룬Swap���������ʵ�֣�
// ��C++�����У�дһ��������ר����������int*���͵�ָ�룬Swap���������ʵ�֣�

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



#if 0
// �����õķ�ʽ��Ϊ��������ֵʱ��
// һ�����ܷ��غ���ջ�Ͽռ�----���ͣ��ֲ�����
// ��Ϊ�����������󣬺������ڲ��ľֲ������ͱ�������
// ������ⲿ�����õķ�ʽ�����պ����ķ���ֵ���ⲿ������ʵ�����õľ���һ��Ƿ����ڴ�ռ�

// ���أ�ֻҪ���ص�ʵ��/�������ܺ�������������
// ���磺ȫ�ֱ������ֲ���̬�������������͵Ĳ���
int& Add(int left, int right)
{
	int ret = left + right;
	cout << "&ret = " << &ret << endl;
	return ret;
}


int& TestRetRef(int& ra)
{
	ra = 10;
	return ra;
}


int main()
{
	// result����Add������ret�ֲ������ı���
	int& result = Add(1,2);
	//cout << "&result = " << &result << endl;
	//Add(3, 4);
	//Add(5, 6);

	int a = 0;
	int& r = TestRetRef(a);
	return 0;
}
#endif


// ��C++�У��������������ַ�ʽ��
// ��ֵ������ַ��������
// ��ֵ���β���ʵ�ε�һ�ݿ��������ε�Ч�ʵͣ�����ͨ���βθı��ⲿ��ʵ��
// ����ַ���βα������ʵ�εĵ�ַ������Ч�ʸߣ�����ͨ���βθı��ⲿ��ʵ��
// �����ã��β�ʵ����ʵ�εı��������۴���Ч��Ҳ�Ƚϸߣ�����ͨ���βθı��ⲿ��ʵ��---���Դﵽ��ָ�����Ƶ�Ч�������ұ�ָ������Ը��߸���ȫ


#if 0
// �����ñȴ�ֵ��Ч�ʸ�
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


#if 0
// ����ַ�ʹ���Ч�ʵ�����
// ��ֵ�ʹ�������Ч���ϼ���һ��
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


#if 0
// C++�������и�Ƶ��Ŀ�����ú�ָ����ʲô����

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