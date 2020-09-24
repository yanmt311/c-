lesson3
目录：
知识点1：函数重载
	1.1 概念--在同一作用域中声明几个功能类似的同名函数，
		同名函数的形参列表(参数个数 或 类型 或 顺序)必须不同
		常用来处理实现功能类似数据类型不同的问题
	1.2 返回值不能确定是否构成重载
	1.3 (1)为什么C++支持函数重载，而C语言不支持函数重载呢？
	答：C语言没办法支持重载，因为同名函数没办法区分。
		而C++是通过函数修饰规则来区分，只要参数不同，修饰出来的名字就不一样，就支持了重载。

		vs是一个集成开发环境，当点击生成或者重新生成时：
			预处理--->编译-->汇编--->链接--->生成可执行程序
		C/C++编译器对这些源文件是单独进行编译器的
	(2)C++中函数重载底层是怎么处理的？
	答：c：_Add；
		c++：?Add@@YAHHH@Z
	1.4 C++中能否将一个函数按照C的风格来编译？
	答：能，通过extern "C" --采用条件编译可以处理
	1.5 函数重载时不传参会引起函数重载发生歧义，但会发生重载
	
知识点2：传值和传址
	(1)传值：不能通过形参改变外部的实参，因为形参是实参的一份拷贝
	(2)传地址：如果想要通过形参改变外部的实参
		问题：指针可能不安全---每次使用时必须要对指针判空
			  代码的可读性比较差
			  
知识点3：引用
	3.1 引用的引入--能不能够继续按照值的方式来传参，在函数实现中也按照值的方式来操作，但是也想到达到指针类似的效果
		如果left和right能够是实参的别名就好了 
		引用---别名：另外一个名字
		注意：引用不是新定义一个变量，而是给已存在变量取了一个别名，
			  编译器不会为引用变量开辟内存空间，它和它引用的变量共用同一块内存空间。
	3.2 引用的形式
		类型& 引用变量名(对象名) = 引用实体；
		&出现在类型之后，表示引用的标记	
	3.3 引用类型必须与其实体是同种类型的
	3.4 引用类型变量在定义时必须要初始化---否则编译器就不知道ra到底是谁的别名
	3.5 一个变量可以有多个引用---->一个实体可以有多个别名
	3.6 引用一旦引用一个实体后，再不能引用其他的实体了
	3.7 引用和其引用的实体的生命周期是一样的?	
	答：引用一旦引用一个实体，再不能引用其他的实体，该引用在其生命周期内，只能和一个实体结合
		引用和其引用的实体的生命周期在一个作用域中是一样的，其他实体比引用的周期长。
	3.8 常引用 --加const
	

#include <iostream>
using namespace std;

知识点1：函数重载
1.1 概念--在同一作用域中声明几个功能类似的同名函数，
	同名函数的形参列表(参数个数 或 类型 或 顺序)必须不同
	常用来处理实现功能类似数据类型不同的问题
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

1.2 返回值不能确定是否构成重载
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

1.3 (1)为什么C++支持函数重载，而C语言不支持函数重载呢？
	答：C语言没办法支持重载，因为同名函数没办法区分。
		而C++是通过函数修饰规则来区分，只要参数不同，修饰出来的名字就不一样，就支持了重载。

		vs是一个集成开发环境，当点击生成或者重新生成时：
			预处理--->编译-->汇编--->链接--->生成可执行程序
		C/C++编译器对这些源文件是单独进行编译器的
	(2)C++中函数重载底层是怎么处理的？
	答：c：_Add；
		c++：?Add@@YAHHH@Z
//c编译器中
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
//函数名前面有_,编译时两个__,c编译器中的规则不变
#if 0
int _Add(int left, int right);
int main()
{
	_Add(1, 2);  // __Add
	return 0;
}
#endif
//c++编译器中 -- H代表int、N代表double
#if 0
int Add(int left, int right);    //C++编译器将int Add(int left, int right)修改为：?Add@@YAHHH@Z
{
	return left + right;
}

double Add(double left, double right);  //C++编译器double Add(double left, double right)修饰为：?Add@@YANNN@Z
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

1.4 C++中能否将一个函数按照C的风格来编译？
	答：能，通过extern "C" --采用条件编译可以处理
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

1.5 函数重载时不传参会引起函数重载发生歧义，但会发生重载
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
	TestFunc(10);//调用第一个函数
	TestFunc();//到底引用第一个函数还是第二个函数，第一个函数时为默认值，第二个直接调用
	return 0;
}
#endif

知识点2：传值和传址
	(1)传值：不能通过形参改变外部的实参，因为形参是实参的一份拷贝
	(2)传地址：如果想要通过形参改变外部的实参
		问题：指针可能不安全---每次使用时必须要对指针判空
			  代码的可读性比较差
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

知识点3：引用
3.1 引用的引入--能不能够继续按照值的方式来传参，在函数实现中也按照值的方式来操作，但是也想到达到指针类似的效果
	如果left和right能够是实参的别名就好了 
	引用---别名：另外一个名字
	注意：引用不是新定义一个变量，而是给已存在变量取了一个别名，
		  编译器不会为引用变量开辟内存空间，它和它引用的变量共用同一块内存空间。
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

3.2 引用的形式
	类型& 引用变量名(对象名) = 引用实体；
	&出现在类型之后，表示引用的标记
#if 0
int main()
{
	int a = 10;
	int &ra = a;// 要给a区别名，称为ra
	ra = 100;
	return 0;
}
#endif

3.3 引用类型必须与其实体是同种类型的
#if 0
int main()
{
	int a = 10;
	int& ra = a;// ra就是a的别名--实体是int类型的，别名也必须是int类型的
	ra = 100;
	
	//double& rra = a; -->error --实体是int类型的，别名也必须是double类型的
	return 0;
}
#endif

3.4 引用类型变量在定义时必须要初始化---否则编译器就不知道ra到底是谁的别名
#if 0
int main()
{
	int a = 10;
	// int& ra;  编译失败
	int& ra = a;
	return 0;
}
#endif

3.5 一个变量可以有多个引用---->一个实体可以有多个别名
#if 0
int main()
{	
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = a;
	int& ra4 = ra;  // ra就是a

	ra = 100;
	ra1 = 200;
	ra2 = 300;
	ra3 = 400;
	return 0;
}
#endif

3.6 引用一旦引用一个实体后，再不能引用其他的实体了
#if 0
int main()
{	
	int b = 10;
	int& rb = b;

	// rb已经是b的别名了，让rb变成a的别名，能不能做到？
	// 并不是让rb成为a的别名，而是用a给rb赋值
	rb = a;   

	// &rb = a;  编译报错，&rb--->对rb取地址int* = int
	return 0;
}
#endif

3.7 引用和其引用的实体的生命周期是一样的?	
	答：引用一旦引用一个实体，再不能引用其他的实体，该引用在其生命周期内，只能和一个实体结合
		引用和其引用的实体的生命周期在一个作用域中是一样的，其他实体比引用的周期长。
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

3.8 常引用 --加const
(1) 引用的方式
#if 0
int main()
{
	// a是一个常量，a不能够被修改的
	const int a = 10;
	//a = 100;

	// 如果ra可以引用a，那么我们就可以通过ra来修改a
	//int& ra = a;  // 编译失败
	const int& ra = a;、
	
	//ra = 200;
	const int& b = 10;//错误，后面不能时常数
	return 0;
}
#endif

(2)结果的变化
#if 0
int main()
{
	int a = 10;
	const int& ra = a;
	a = 100;//都是100
	return 0;
}
#endif

#if 0
int main()
{
	double d = 12.34;
	const int& rd = d;  // rd已经是d的别名了--rd是int类型的，应该rd将d中整形部分拿到了
	d = 34.56;
	cout << rd << endl;
	return 0;//结果12
}
#endif

疑问：想一想：r在main函数中，没有进行任何的修改，为什么第二次和第三次Add调用结束后，r的值都会变，为什么？
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



