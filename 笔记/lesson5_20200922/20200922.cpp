lesson5
Ŀ¼��
֪ʶ��1��const���εĳ���---�����ں��滻
֪ʶ��2��C++�У�ʹ��const���εĳ�����ȡ��C�����еĺ�
	2.1 ��
	2.2 const���εĳ���
	2.3 ֤����c++��const���εı���Ϊ���������ܱ��޸�
	2.4 c++�У�const���εĳ�������ں������
֪ʶ��3����������
֪ʶ��4��������������
	4.1 �����������ռ任ʱ��
	4.2 ����ѭ���͵ݹ���������������������Զ��Ż�.
	4.3 �������������������������Ӵ���
	���䣺���ȱ�ݣ�ʹ���������������
֪ʶ��5��auto
	5.1 auto����
	5.2 auto��ָ����ʹ�� ---��һ��
	5.3 auto�����ý��ʹ�� --Ҫ��&����
	5.4 auto���Զ���������--����ͬһ����
	5.5 auto����ʹ�õ���������
		5.5.1 auto������Ϊ�����Ĳ���
		5.5.2 auto����ֱ������
	5.6 auto������ʹ�ó���
		5.6.1 �������͵�����
		5.6.2 ��Χforѭ��
		
		
		
#include <iostream>
using namespace std;
֪ʶ��1��const���εĳ���---�����ں��滻

	c++����const���εı���һ���Ϊ����������const�޸ĵĳ��������к��滻�����á�
	     ���к��滻�����ڱ���׶Σ�����ʹ��const������λ�ã��ó�����ֵ����ó�������&�����⣩
	c��const���εı������ܳ�Ϊ������ֻ�ܳ�Ϊ�����޸ĵı�����
��1���۲�a��*pa��ֵ
#if 0
int main(){
	
	const int a = 10;
	int* pa = (int*) &a;//&a���������Ϊconst int*�������õ�ַָ��Ŀռ��е����ݲ��������ġ�
	*pa = 100;
	
	printf("%d\n",a);//10
	cout << a << endl;//10 ---�ڱ���׶Σ�����ʹ��const������λ�ã��ó�����ֵ����ó�������&������
	cout << *pa << endl;//100

}
#endif

��2���۲�a��b��MAX��*paֵ

	a��c++��const���εĳ���
	b������
	MAX����
	*pa��ָ��
	*&a��a

#if 0
#define  MAX 10            //��
int main()
{
	const int a = 10;      //c++��const���εĳ���
	int* pa = (int*)&a;    // &a��������� const int*--->�����õ�ַָ��Ŀռ������ݲ������޸�
	*pa = 100              //ָ��
	int b = 20;            //����b
	
	//�۲�a,b,MAX����࣬����a��MAXû�н����ڴ���ʣ�ֱ�ӽ���ѹջ����bҪ��ȡ������ֵ��ѹջ
	printf("%d\n", MAX);   // *&a<==>a 
	printf("%d\n", a);     
	printf("%d\n", b);
	printf("%d\n", *&a);   //*&a�������a����--->��Ȼ��a����--->�滻Ϊ10

	cout << a << endl;     //����cout << 10 << endl;
	cout << *pa << endl;
	return 0;
}
#endif
ע�⣺�ڴ���a��ֵ�Ѿ���Ϊ100�ˣ�����a����û�з����ڴ��ַ�����Լ�ʹ�ڴ����ݸı䣬���������Ҳ��û��ģ�
      *pa���Ϊ100����Ϊ��������ڴ�ռ䡣
--------------------------------------------------------------------------------------------------------------------------------------

֪ʶ��2��C++�У�ʹ��const���εĳ�����ȡ��C�����еĺ�
2.1 ��
#if 0
#define  MAX 10
int main()
{
	// ����Ԥ����׶λᱻ�����������滻

	int a = 100;
	a = MAX;  // ���������Ԥ����׶��Ѿ����޸�Ϊ��a = 10;
	return 0;
}
#endif

2.2 const���εĳ���
#if 0
int main()
{
	const int a = 10;
	int* pa = (int*)&a;

	printf("%d\n", a);
	printf("%d\n", *pa);
	return 0;
}
#endif

2.3 ֤����c++��const���εı���Ϊ���������ܱ��޸�
#if 0
int main()
{
	const int a = 10;

	 int array[a];
	//a = 10;

	return 0;
}
#endif

2.4 c++�У�const���εĳ�������ں������
#if 0
// ����滻������Ԥ����׶�----���Ǻ겻��
// const���εĳ����滻�����ڱ���׶�---->��const���εĳ����������͵ģ���˻�������ͼ��


// �겻��������ͼ�⣬��Ϊ����Ԥ����׶��Ѿ����滻
#define PI  "3.14"


// pi��������double���͵�   "3.14"���ַ�������   ����׶�֪�����Ͳ�ƥ�������
const double pi = "3.14";

// һ������£���C++�� ������ʹ��const���εĳ�����ȡ��C�����еĺ�
// ��Ϊ��const���ε������Ѿ��ǳ����ˣ����һ�������ͼ�⣬�Ⱥ곣��ʹ����������ȫ

int main()
{
	int r = 2;

	double s = PI * r * r;   // ���滻��s = "3.14" * r * r;

	double s = pi * r * r;
	return 0;
}
#endif
-----------------------------------------------------------------------------------------------------------------
���ȱ�ݣ�
#if 0
#define MAX(a, b) (a > b ? a : b)


int main()
{
	int a = 10;
	int b = 20;

	cout << MAX(++b, a) << endl;  //���������Ԥ����׶α��滻Ϊ�� cout <<(a > b ? a : b)<< endl;
	cout << MAX("hello", 100) << endl;

	return 0;
}
#endif
------------------------------------------------------

֪ʶ��3����������
		ע�⣺��C++�У�һ����ڱȽ϶�С�ĺ���������д���������� ---��inline

��c++�У��곣�� --- ʹ��const���εĳ��������
		 �꺯�� --- ʹ��inline���ε���������������
debug����ģʽ����������Ĭ���ǲ���չ���� 
	--- debug��Ҫ�������Դ���ģ��������������������չ���ˣ�����Ͳ���������ˡ�
releaseģʽ�£��������Դ�����Ż��Ƿǳ��ߵġ�ռ�ÿռ��С��


�꺯��������������ȱ�㣺չ�������ɴ�������
#if 0
inline int Add(int left, int right)
{
	return left + right;
}
int main()
{
	// ��Releaseģʽ�£��������Դ�����Ż��Ƿǳ��ߵģ�Add�ĺ��������Ѿ�û���ˣ�ֱ�Ӹ���30
	// ��Release�汾�£�main�����е�5�д���ֱ�ӱ��Ż��ɣ�printf("%d\n", 30);
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b); 
	printf("%d\n", c);		
	
	return 0;
}
#endif
---------------------------------------------------------------------

֪ʶ��4�������������ԣ�
1.inline��һ���Կռ任ʱ���������ʡȥ���ú��������
  ���Դ���ܳ�������ѭ��/�ݹ�ĺ���������ʹ����Ϊ����������

2.inline���ڱ���������ֻ��һ�����飬���������Զ��Ż�.
  �������Ϊinline�ĺ���������ѭ��/�ݹ�ȵȣ��������Ż�ʱ����Ե�������
  
3.inline�����������Ͷ�����룬����ᵼ�����Ӵ���
  ��Ϊinline��չ������û�к�����ַ�ˣ����Ӿͻ��Ҳ�����
  
4.1 �����������ռ任ʱ��
#if 0
inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int a = 10;
	int b = 20;	
	// ���裺Add������5�д���  --- �ռ任ʱ�������
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);	
	return 0;
}
#endif

4.2 ����ѭ���͵ݹ���������������������Զ��Ż�.
#if 0
inline void TestInline()
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n");
	}
}

inline int Fac(int N)
{
	if (N == 0)
		return 1;

	return Fac(N - 1)*N;
}

int main()
{
	TestInline();//ѭ��
	Fac(5);//�ݹ�
	return 0;
}
#endif

4.3 �������������������������Ӵ���
#if 0
#include "Add.h"

int main()
{
	Add(10, 20);
	return 0;
}
#endif
----------------------------------------------------

#if 0
#define MAX(a, b) (a > b ? a : b)


int main()
{
	int a = 10;
	int b = 20;

	cout << MAX(++b, a) << endl;  //���������Ԥ����׶α��滻Ϊ�� cout <<(a > b ? a : b)<< endl;
	cout << MAX("hello", 100) << endl;

	return 0;
}
#endif

����˺��ȱ�ݣ����Ϊ21
#if 0
inline int Max(int left, int right)
{
	return left > right ? left : right;
}

int main()
{
	int a = 10;
	int b = 20;

	int c = 0;

	c = Max(++b, a);
	cout << c << endl;
	return 0;
}
#endif
-------------------------------------------------------------------

֪ʶ��5��C++11�е��﷨��
5.1 auto
#if 0
int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int a = 10;

	auto b = a;
	auto c = 'c';
	auto d = 12.34;
	auto r = Add(10, 20);

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(r).name() << endl;

	auto aa;//������г�ʼ��
	return 0;
}
#endif

5.2 auto��ָ����ʹ�� ---��һ��
#if 0
int main()
{
	int a = 10;

	auto* pa1 = &a;
	auto  pa2 = &a;

	// pa1��pa2���մ�ӡ�Ķ���int*
	// auto����ָ�����ͱ���ʱ����*�Ͳ���* û������
	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;

	return 0;
}
#endif

5.3 auto�����ý��ʹ�� --Ҫ��&����
#if 0
int main()
{
	int b = 10;
	// rb1���¶�����һ�����εı���
	auto rb1 = b;  //rb1�ĵ�ַ��b�ĵ�ַ��һ��
	// rb2��b�ı���
	auto& rb2 = b; //rb2�ĵ�ַ��b�ĵ�ַһ��

	// ʹ��auto�������������ͱ���ʱ������Ҫ��&�ı�ǣ����ӾͶ�����һ���µı��������˾�������
	cout << typeid(rb1).name() << endl;
	cout << typeid(rb2).name() << endl;

	auto  a1 = 10, a2 = 20;

	//auto b1 = 10, b2 = 12.34;
	return 0;
}
#endif

5.4 auto���Զ���������--����ͬһ����
#if 0
int main()
{
	auto  a1 = 10, a2 = 20;
	//auto b1 = 10, b2 = 12.34;//����
	return 0;
}
#endif

5.5 auto����ʹ�õ���������
5.5.1 auto������Ϊ�����Ĳ���
      ���������еĲ������г�ʼ�����ʽ����˱������޷�����a��ʵ������
#if 0
void TestAuto(auto a)
{
	printf("%d", a);
}

int main()
{
	return 0;
}
#endif

5.5.2 auto����ֱ������������
#if 0
int main()
{
	//�������͸����鿪�ٿռ�
	int array1[] = { 1, 2, 3 };
	auto array2[] = { 3, 4, 5 };
	return 0;
}
#endif

5.6 auto������ʹ�ó���
��һ�ֳ������������͵�����
#if 0
#include <map>
#include <string>
int main()
{
	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, {"orange","����"} };
	
	std::map<std::string, std::string>::iterator it1 = m.begin();
	auto it2 = m.begin();
	return 0;
}
#endif

�ڶ��ֳ�������Χforѭ��
�������е�ÿ��Ԫ�س�2��
#if 0
int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
		a1[i] *= 2;

	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
		cout << a1[i] << " ";
	cout << endl;
	return 0;
}
#endif

#if 0
auto��forѭ���е�ʹ��
int main()
{
	// ��C++11��
	// forѭ����������ôд
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	
	// ��Χforѭ��
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << " ";
	cout << endl;
	
	return 0;
}
#endif

