lesson2 

目录：
一、输入输出
1、c语言中标准的输入输出在c++中依旧使用
	输入：scanf/getchar/gets
	输出：printf/putchar/puts
2、c++中输入输出更加便捷

	注意：1、cin--输入、cout--输出、<iostream>+using namespace std;
			 比较老的编译器---<iostream.h>
		  2、std命名空间是在c++语言提供；
			--cin和cout包含在std的命名空间中，但不是说std的命名空间中包含cin和cout
			--c语言标准库函数不在std命名空间中
二、函数
1、函数返回值类型--没有返回值，也没有参数
	注意：1、在C语言中：以下代码可以通过编译
		  2、在C++语言中：以下代码不能通过编译
		  3、C++编译器比C语言编译器语法检测更加严格
2、函数参数类型 
	注意：1、在C语言中：以下函数可以通过编译
				--没有显示写返回值类型时，C语言编译器默认函数返回int
		  2、在C++中：以下函数不能通过编译
		  3、C++编译器比C语言编译器语法检测更加严格
3、缺省参数：在定义函数时，可以给函数的参数带上一些默认值
3.1 在调用该函数时，如果没有指定实参则采用该默认值，否则使用指定的实参。			
3.2 分类：
3.2.1 全缺省参数：每个参数都带有默认值 -- 从左至右传参
3.2.2 半缺省参数：部分参数带有默认值
 分析： a     b     c     ---0代表没有默认值、1代表有默认值
		0     1     1     代码可以通过编译
		1     0     1     代码编译失败
		1     1     0     代码编译失败
		0     0     1     可以通过编译
 结论：默认值只能从右往左依次给出
3.2.3 缺省参数可以再声明位置给出，也可以在定义位置给出，但是不能两个位置同时给出 ---只能是全局变量/常量，变量不行
	// 疑问：在声明位置给好？还是在定义的位置给好？ ---声明位置好 
3.2.4 
(1)函数重载：在相同作用域中，函数名字必须要相同，参数列表必须要不同(个数，类型，类型次序)
				参数列表不同体现：
					1.参数个数不同
					2.参数类型不同
					3.参数类型次序不同
		注意：如果两个函数仅仅是返回类型不同，则不能构成重载
(2)函数重载的调用原理：函数重载一定是在编译阶段具体来确定应该调用那个函数

	编译器在编译阶段，会对函数实参类型进行推演，根据推演的实际结果找类型匹配的函数进行调用
	1、如果有类型完全匹配的函数，则直接进行调用
	2、如果没有类型完全匹配的函数，则会进行隐式类型转换
		a、如果隐式类型转换后有对应的函数则进行调用
		b、如果没有对应的函数，或者说转换之后有二义性，则报错
			eg：编译阶段，对形参类型进行推演：int，double
				Add(int, double)-->该函数没有找到
				发现：int和double之间可以进行隐式类型转换  int--->double  double--->int
				Add(int, int) || Add(double, double) 转换之后发现两个函数都可以
				编译器不知道到底应该调用哪一个方法了
				编译报错
				Add(1, 2.2);
				
				
				
				
				
一、输入输出
1、c语言中标准的输入输出在c++中依旧使用
	输入：scanf/getchar/gets
	输出：printf/putchar/puts
2、c++中输入输出更加便捷
	注意：1、cin--输入、cout--输出、<iostream>+using namespace std;
			 比较老的编译器---<iostream.h>
		  2、std命名空间是在c++语言提供；
			--cin和cout包含在std的命名空间中，但不是说std的命名空间中包含cin和cout
			--c语言标准库函数不在std命名空间中

#include <iostream>
using namespace std;

#if 0
int main()
{
	std::cout << "hello world" << std::endl;
	return 0;
}
#endif


二、函数
1、函数返回值类型--没有返回值，也没有参数
	注意：1、在C语言中：以下代码可以通过编译
		  2、在C++语言中：以下代码不能通过编译
		  3、C++编译器比C语言编译器语法检测更加严格
		  
#if 0
void TestFunc()
{

}

int main()
{
	TestFunc();
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10,20,30);
	return 0;
}
#endif
  
2、函数参数类型 
	注意：1、在C语言中：以下函数可以通过编译
				--没有显示写返回值类型时，C语言编译器默认函数返回int
		  2、在C++中：以下函数不能通过编译
		  3、C++编译器比C语言编译器语法检测更加严格
#if 0
#include <stdio.h>
TestFunc(void)
{
	
}

int main()
{
	int ret = TestFunc();
	printf("%d\n", ret);
	return 0;
}
#endif



3、缺省参数：在定义函数时，可以给函数的参数带上一些默认值

3.1 在调用该函数时，如果没有指定实参则采用该默认值，否则使用指定的实参。

#if 0
#include <stdio.h>
void TestFunc(int a=10, int b=20)
{
	printf("%d %d\n", a, b);
}

int main()
{
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);

	//上述调用中，每次调用传递的都是同一组实参
	//不想传递，但是让该函数执行起来后，还可以拿到10,20
	TestFunc();//默认值
	TestFunc(30,40);//指定实参
	TestFunc(300,400);
	return 0;
}
#endif

3.2 分类：
3.2.1 全缺省参数：每个参数都带有默认值 -- 从左至右传参
#if 0
void TestFunc(int a=1, int b=2, int c=3)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

int main()
{
	TestFunc();// 1 2 3

	// 注意：10传递给第一个形参，后两个形参使用默认值
	TestFunc(10);// 10 2 3
	TestFunc(10, 20);//10 20 3
	TestFunc(10, 20, 30);// 10  20  30
	return 0;
}
#endif

3.2.2 半缺省参数：部分参数带有默认值
 分析： a     b     c     ---0代表没有默认值、1代表有默认值
		0     1     1     代码可以通过编译
		1     0     1     代码编译失败
		1     1     0     代码编译失败
		0     0     1     可以通过编译
 结论：默认值只能从右往左依次给出

#if 0
void TestFunc(int a, int b=2, int c=1)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(10);//10 2 1
	TestFunc(10,20);//10 20 1
	TestFunc(10,20,30);//10 20 30
	return 0;
}
#endif

3.2.3 缺省参数可以再声明位置给出，也可以在定义位置给出，但是不能两个位置同时给出 ---只能是全局变量/常量，变量不行
	// 疑问：在声明位置给好？还是在定义的位置给好？ ---声明位置好
#if 0
int g_a = 10;
void TestFunc(int a = g_a);
void TestFunc(int a)
{
	cout << a << endl;
}
#endif


3.2.4 函数重载：在相同作用域中，函数名字必须要相同，参数列表必须要不同(个数，类型，类型次序)
				参数列表不同体现：
					1.参数个数不同
					2.参数类型不同
					3.参数类型次序不同
		注意：如果两个函数仅仅是返回类型不同，则不能构成重载
		
case1：		
#if 0
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

//1和2构成返回值类型不同 ---错误
void TestFunc()//1
{}
int TestFunc()//2
{}

//3和4构成参数类型不同
void TestFunc(int a)//3
{}
void TestFunc(char c)//4
{}

//5和6参数类型次序不同
void TestFunc(int a, char b)//5
{}
void TestFunc(char a, int b)//6
{}

//7和8参数个数不同
void TestFunc()//7
{}
void TestFunc(int a)//8
{}
#endif


case2：
	函数重载的调用原理：函数重载一定是在编译阶段具体来确定应该调用那个函数

	编译器在编译阶段，会对函数实参类型进行推演，根据推演的实际结果找类型匹配的函数进行调用
	1、如果有类型完全匹配的函数，则直接进行调用
	2、如果没有类型完全匹配的函数，则会进行隐式类型转换
		a、如果隐式类型转换后有对应的函数则进行调用
		b、如果没有对应的函数，或者说转换之后有二义性，则报错
			eg：编译阶段，对形参类型进行推演：int，double
				Add(int, double)-->该函数没有找到
				发现：int和double之间可以进行隐式类型转换  int--->double  double--->int
				Add(int, int) || Add(double, double) 转换之后发现两个函数都可以
				编译器不知道到底应该调用哪一个方法了
				编译报错
				Add(1, 2.2);
#if 0
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

int main()
{
	// 单纯从调用位置来看---只看到了一个Add
	Add(10, 20); // int，int--->Add(int, int)

	Add(1.2, 3.4);// double, double--->Add(double, double)

	Add('1', '2'); // char, char--->Add(char,char)--->char和int之间可以进行隐式类型转换--->Add(int,int)

	Add("hello", "world");  // char*,char*--->Add(char*, char*)--->char*既不能隐式转换为int，也不能隐式转换为double

	return 0;
}
#endif

case3：
// C语言不支持函数重载
// C++到底是怎么支持函数重载的？而C语言为什么就不能支持？
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

int main()
{
	return 0;
}