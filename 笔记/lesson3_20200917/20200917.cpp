lesson3
Ŀ¼��
֪ʶ��1����������
	1.1 ����--��ͬһ�����������������������Ƶ�ͬ��������
		ͬ���������β��б�(�������� �� ���� �� ˳��)���벻ͬ
		����������ʵ�ֹ��������������Ͳ�ͬ������
	1.2 ����ֵ����ȷ���Ƿ񹹳�����
	1.3 (1)ΪʲôC++֧�ֺ������أ���C���Բ�֧�ֺ��������أ�
	��C����û�취֧�����أ���Ϊͬ������û�취���֡�
		��C++��ͨ���������ι��������֣�ֻҪ������ͬ�����γ��������־Ͳ�һ������֧�������ء�

		vs��һ�����ɿ�����������������ɻ�����������ʱ��
			Ԥ����--->����-->���--->����--->���ɿ�ִ�г���
		C/C++����������ЩԴ�ļ��ǵ������б�������
	(2)C++�к������صײ�����ô����ģ�
	��c��_Add��
		c++��?Add@@YAHHH@Z
	1.4 C++���ܷ�һ����������C�ķ�������룿
	���ܣ�ͨ��extern "C" --��������������Դ���
	1.5 ��������ʱ�����λ����������ط������壬���ᷢ������
	
֪ʶ��2����ֵ�ʹ�ַ
	(1)��ֵ������ͨ���βθı��ⲿ��ʵ�Σ���Ϊ�β���ʵ�ε�һ�ݿ���
	(2)����ַ�������Ҫͨ���βθı��ⲿ��ʵ��
		���⣺ָ����ܲ���ȫ---ÿ��ʹ��ʱ����Ҫ��ָ���п�
			  ����Ŀɶ��ԱȽϲ�
			  
֪ʶ��3������
	3.1 ���õ�����--�ܲ��ܹ���������ֵ�ķ�ʽ�����Σ��ں���ʵ����Ҳ����ֵ�ķ�ʽ������������Ҳ�뵽�ﵽָ�����Ƶ�Ч��
		���left��right�ܹ���ʵ�εı����ͺ��� 
		����---����������һ������
		ע�⣺���ò����¶���һ�����������Ǹ��Ѵ��ڱ���ȡ��һ��������
			  ����������Ϊ���ñ��������ڴ�ռ䣬���������õı�������ͬһ���ڴ�ռ䡣
	3.2 ���õ���ʽ
		����& ���ñ�����(������) = ����ʵ�壻
		&����������֮�󣬱�ʾ���õı��	
	3.3 �������ͱ�������ʵ����ͬ�����͵�
	3.4 �������ͱ����ڶ���ʱ����Ҫ��ʼ��---����������Ͳ�֪��ra������˭�ı���
	3.5 һ�����������ж������---->һ��ʵ������ж������
	3.6 ����һ������һ��ʵ����ٲ�������������ʵ����
	3.7 ���ú������õ�ʵ�������������һ����?	
	������һ������һ��ʵ�壬�ٲ�������������ʵ�壬�������������������ڣ�ֻ�ܺ�һ��ʵ����
		���ú������õ�ʵ�������������һ������������һ���ģ�����ʵ������õ����ڳ���
	3.8 ������ --��const
	

#include <iostream>
using namespace std;

֪ʶ��1����������
1.1 ����--��ͬһ�����������������������Ƶ�ͬ��������
	ͬ���������β��б�(�������� �� ���� �� ˳��)���벻ͬ
	����������ʵ�ֹ��������������Ͳ�ͬ������
#if 0
int Add(int left, int right) 
{
	return left+right; 
}
double Add(double left, double right) 
{
	return left+right; 
}
long Add(long left, long right) 
{
	return left+right; 
}
int main()
{
	Add(10, 20);
	Add(10.0, 20.0);
	Add(10L, 20L);
	return 0; 
}
#endif

1.2 ����ֵ����ȷ���Ƿ񹹳�����
#if 0
short Add(short left, short right) 
{
	return left+right; 
}
int Add(short left, short right) 
{
	return left+right; 
}
#endif

1.3 (1)ΪʲôC++֧�ֺ������أ���C���Բ�֧�ֺ��������أ�
	��C����û�취֧�����أ���Ϊͬ������û�취���֡�
		��C++��ͨ���������ι��������֣�ֻҪ������ͬ�����γ��������־Ͳ�һ������֧�������ء�

		vs��һ�����ɿ�����������������ɻ�����������ʱ��
			Ԥ����--->����-->���--->����--->���ɿ�ִ�г���
		C/C++����������ЩԴ�ļ��ǵ������б�������
	(2)C++�к������صײ�����ô����ģ�
	��c��_Add��
		c++��?Add@@YAHHH@Z
//c��������
#if 0
int Add(int left, int right);    //_Add
{
	return left + right;
}
double Add(double left, double right);  // _Add
{
	return left + right;
}

int main()
{
	Add(10, 30);
	Add(1.2, 3.4);
	return 0;
}
#endif
//������ǰ����_,����ʱ����__,c�������еĹ��򲻱�
#if 0
int _Add(int left, int right);
int main()
{
	_Add(1, 2);  // __Add
	return 0;
}
#endif
//c++�������� -- H����int��N����double
#if 0
int Add(int left, int right);    //C++��������int Add(int left, int right)�޸�Ϊ��?Add@@YAHHH@Z
{
	return left + right;
}

double Add(double left, double right);  //C++������double Add(double left, double right)����Ϊ��?Add@@YANNN@Z
{
	return left + right;
}

double Add(int left, double right);

int main()
{
	Add(10, 30);
	Add(10.2, 30.3);
	Add(1, 3.4);
	return 0;
}
#endif

1.4 C++���ܷ�һ����������C�ķ�������룿
	���ܣ�ͨ��extern "C" --��������������Դ���
#if 0
extern "C" int Add(int left, int right);
{
	return left + right;
}
#endif

#if 0
extern "C"{
	int Add1(int left, int right);  // _Add1
	int Add2(int left, int right);  // _Add2
	int Add3(int left, int right);  // _Add3
	int Add4(int left, int right);  // _Add4
}
#endif

1.5 ��������ʱ�����λ����������ط������壬���ᷢ������
#if 0
void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc()
{
	cout << "void TestFunc()" << endl;
}

int main()
{
	TestFunc(10);//���õ�һ������
	TestFunc();//�������õ�һ���������ǵڶ�����������һ������ʱΪĬ��ֵ���ڶ���ֱ�ӵ���
	return 0;
}
#endif

֪ʶ��2����ֵ�ʹ�ַ
	(1)��ֵ������ͨ���βθı��ⲿ��ʵ�Σ���Ϊ�β���ʵ�ε�һ�ݿ���
	(2)����ַ�������Ҫͨ���βθı��ⲿ��ʵ��
		���⣺ָ����ܲ���ȫ---ÿ��ʹ��ʱ����Ҫ��ָ���п�
			  ����Ŀɶ��ԱȽϲ�
#if 0
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
#endif

֪ʶ��3������
3.1 ���õ�����--�ܲ��ܹ���������ֵ�ķ�ʽ�����Σ��ں���ʵ����Ҳ����ֵ�ķ�ʽ������������Ҳ�뵽�ﵽָ�����Ƶ�Ч��
	���left��right�ܹ���ʵ�εı����ͺ��� 
	����---����������һ������
	ע�⣺���ò����¶���һ�����������Ǹ��Ѵ��ڱ���ȡ��һ��������
		  ����������Ϊ���ñ��������ڴ�ռ䣬���������õı�������ͬһ���ڴ�ռ䡣
#if 0
void Swap(int left, int right)
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
	Swap(&a, &b);
	return 0;
}
#endif

3.2 ���õ���ʽ
	����& ���ñ�����(������) = ����ʵ�壻
	&����������֮�󣬱�ʾ���õı��
#if 0
int main()
{
	int a = 10;
	int &ra = a;// Ҫ��a����������Ϊra
	ra = 100;
	return 0;
}
#endif

3.3 �������ͱ�������ʵ����ͬ�����͵�
#if 0
int main()
{
	int a = 10;
	int& ra = a;// ra����a�ı���--ʵ����int���͵ģ�����Ҳ������int���͵�
	ra = 100;
	
	//double& rra = a; -->error --ʵ����int���͵ģ�����Ҳ������double���͵�
	return 0;
}
#endif

3.4 �������ͱ����ڶ���ʱ����Ҫ��ʼ��---����������Ͳ�֪��ra������˭�ı���
#if 0
int main()
{
	int a = 10;
	// int& ra;  ����ʧ��
	int& ra = a;
	return 0;
}
#endif

3.5 һ�����������ж������---->һ��ʵ������ж������
#if 0
int main()
{	
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = a;
	int& ra4 = ra;  // ra����a

	ra = 100;
	ra1 = 200;
	ra2 = 300;
	ra3 = 400;
	return 0;
}
#endif

3.6 ����һ������һ��ʵ����ٲ�������������ʵ����
#if 0
int main()
{	
	int b = 10;
	int& rb = b;

	// rb�Ѿ���b�ı����ˣ���rb���a�ı������ܲ���������
	// ��������rb��Ϊa�ı�����������a��rb��ֵ
	rb = a;   

	// &rb = a;  ���뱨��&rb--->��rbȡ��ַint* = int
	return 0;
}
#endif

3.7 ���ú������õ�ʵ�������������һ����?	
	������һ������һ��ʵ�壬�ٲ�������������ʵ�壬�������������������ڣ�ֻ�ܺ�һ��ʵ����
		���ú������õ�ʵ�������������һ������������һ���ģ�����ʵ������õ����ڳ���
#if 0
int main()
{
	int a = 10;
	int& ra = a;

	if (true)
	{
		int& rra = a;
		rra = 100;
	}

	// rra = 1000;
	return 0;
}
#endif

3.8 ������ --��const
(1) ���õķ�ʽ
#if 0
int main()
{
	// a��һ��������a���ܹ����޸ĵ�
	const int a = 10;
	//a = 100;

	// ���ra��������a����ô���ǾͿ���ͨ��ra���޸�a
	//int& ra = a;  // ����ʧ��
	const int& ra = a;��
	
	//ra = 200;
	const int& b = 10;//���󣬺��治��ʱ����
	return 0;
}
#endif

(2)����ı仯
#if 0
int main()
{
	int a = 10;
	const int& ra = a;
	a = 100;//����100
	return 0;
}
#endif

#if 0
int main()
{
	double d = 12.34;
	const int& rd = d;  // rd�Ѿ���d�ı�����--rd��int���͵ģ�Ӧ��rd��d�����β����õ���
	d = 34.56;
	cout << rd << endl;
	return 0;//���12
}
#endif

���ʣ���һ�룺r��main�����У�û�н����κε��޸ģ�Ϊʲô�ڶ��κ͵�����Add���ý�����r��ֵ����䣬Ϊʲô��
int& Add(int left, int right)
{
	int ret = 0;
	ret = left + right;
	return ret;
}

int main()
{
	int& r = Add(1, 2);
	Add(3, 4);
	Add(5, 6);

	return 0;
}



