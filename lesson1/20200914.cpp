c++ѧϰ��ܣ�

���ף������﷨+��Ͷ���+��̬�ڴ����+ģ��+STL����
���ף��̳кͶ�̬+�������Ľ���+STL����+C++11�﷨+�쳣+����ת��+���ݽṹ+��Ŀ


һ��
	1�� c����֮��������
		c++֮����������.˹����˹��¬�� ---Ϊ�˽��ں�ģ�黯����c���ԵĻ����Ͻ�����չ����������Ļ��ơ�
		c++98:����STL��׼ģ���
		c++11:��������������ԣ�auto�ؼ��֡�����������׼�̡߳���������
	2����װ���̳С���̬---���������ص�
	3��c++���µ����򣺲���ϵͳ����������˿������˹�����python�����繤�ߡ���Ϸ������Ƕ��ʽ���򡢷ֲ�ʽӦ�á�����ͼ�����ƶ��豸��
����
	1��c���ԵĹؼ��֣����ĸ��汾���ж��ٹؼ��� --- 32
	2��c++98�еĹؼ��֣�63��
	3����1�������ռ䣺���������ͻ��������Ⱦ
       ��2�������ռ�Ķ����ʽ��
                 �ؼ��֣�namespace    
			a�������ʽ
			b�������ռ����Ƕ��
			c����ͬһ�����У����Զ�����������ͬ�������ռ�
	ע�⣺1����ͬ���Ƶ����������ռ䣬���������Ʋ�����ͬ����ͬ�������в��ܳ�����ͬ�����֣�
		  2����ͬ���ƵĶ�������ռ��У�Ҳ���ܳ�����ͬ��������Ϊ�������Ὣ�����ͬ���Ƶ������ռ����պϲ���һ��
	4�������ռ��г�Ա��ʹ�÷�ʽ
		(1)�������ռ�����::��Ա
		(2)����N���������ռ���ĳЩ��Ա���ʵķǳ�Ƶ��
		(3)������N�����ռ�������Ա�ڵ�ǰ�ļ���ʹ�÷ǳ�Ƶ��
����
    C++�е���������
    ���룺cin >> b >> c;

	�����cout << a << " " << b << " " << c << endl;


�ġ����� 
#if 0
// �����ռ䶨���ʽ
namespace N
{
	// ����
	// ����
}
#endif



#if 0
// ���ֶ��巽ʽ
// 1. �����ʽ
namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}


// 2. �����ռ����Ƕ��
// �����ڣ�һ��ѧУ�п��԰������ѧԺ
namespace N2
{
	int a = 30;
	int b = 40;

	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int c = 10;
		int d = 20;

		int Mul(int left, int right)
		{
			return left*right;
		}
	}
}


#if 0
namespace N
{
	int a = 10;

	//Ƕ�׵ķ�ʽ----���ַ�ʽ�����ͻ
	// �൱�����N�����ռ����ְ�����һ��N�������ռ�
	namespace N
	{
		int b = 10;
		int a = 10;
	}
}
#endif

// 3. ��ͬһ�����У����Զ�����������ͬ�������ռ�
// �����ͻ
// �������Ὣ�����ͬ���Ƶ������ռ�ϲ���һ��
int a = 10;
namespace N1
{
	//int a = 30;
	int Div(int left, int right)
	{
		return left / right;
	}
}
#endif



#include <stdio.h>
#if 0
// �����ռ��г�Ա��ʹ�÷�ʽ
// ����һ�������ռ�����::��Ա
namespace N
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}


int a = 20;

int main()
{
	int a = 30;

	// �ͽ�ԭ��
	printf("%d\n", a);

	// �������ȫ���������е�a
	// ::�����������
	// ::a  ��ȷ˵��Ҫ����ȫ���������е�a
	printf("%d\n", ::a);


	// ����N�����ռ��е�a
	printf("%d\n", N::a);
	return 0;
}
#endif


#if 0
namespace N
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}


// ����������N���������ռ���ĳЩ��Ա���ʵķǳ�Ƶ��
// �ŵ㣺д�������
// ȱ�㣺������ļ�������ͬ���Ƶı������ߺ������ͻ������ͻ
// ���������ͻ����ô�죿----���շ�ʽ1ʹ�ü���

// ����������֮���൱�ڽ�N�����ռ��е�a���ɵ�ǰ�ļ���һ��ȫ�ֱ�����ʹ��
using N::a;


// ������ļ���Ҳ��һ��a����Ȼ�������ͻ��ֻ�ܰ��շ�ʽ1������ʹ��
//int a = 10;

int main()
{
	int a = 10;

	// ����N�����ռ��е�a
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);

	// Ϊ��д����򵥣���Ҫֱ�ӷ���N�����ռ��е�a
	printf("%d\n", a);
	return 0;
}
#endif


#if 0
// ������������N�����ռ�������Ա�ڵ�ǰ�ļ���ʹ�÷ǳ�Ƶ��

namespace N
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}


//using N::a;
//using N::b;
//using N::Add;

// ����ǰN�����ռ������еĳ�Ա���ɸ��ļ���ȫ�ֱ���
// �ŵ㣺ʹ�÷ǳ���
// ȱ�ݣ�������ͻ�ĸ��ʿ��ܻ�ǳ���
// ���������ͻ����������շ�ʽ1ʹ��
using namespace N;

int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", a);

	printf("%d\n", N::b);
	printf("%d\n", N::b);
	printf("%d\n", N::b);
	printf("%d\n", N::b);
	printf("%d\n", b);

	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	return 0;
}
#endif



// C++�е���������
// ע�⣺C���������������ķ�ʽ��c++���Ծɿ���ʹ��----��ΪC++Ҫ����C����

// C++�Լ����Ǹ���һ�����������ķ�ʽ����ΪC���������������ʽ̫�鷳��

#if 0
int main()
{
	int a = 10;
	scanf("%d%d", &a);

	printf("%d\n", 10, 20, 30);
	printf("%d %s %f\n", 10);
	return 0;
}
#endif

// ע�⣺<iostream.h>  �ɿ��а�����
//#include <iostream.h>

#include <iostream>
using namespace std;


int main()
{
	int a, b, c;
	cin >> a;
	cin >> b >> c;

	cout << a << " " << b << " " << c << endl;

	cout << 10;
	cout << 12.34 << "\n";
	cout << "hello" << 123 << "world!!!" << endl;

	return 0;
}