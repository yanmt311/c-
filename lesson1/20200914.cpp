c++学习框架：

初阶：入门语法+类和对象+动态内存管理+模板+STL初阶
进阶：继承和多态+二叉树的进阶+STL进阶+C++11语法+异常+类型转化+数据结构+项目


一、
	1、 c语言之父：里奇
		c++之父：本贾尼.斯特劳斯特卢普 ---为了将内核模块化，在c语言的基础上进行拓展，增加了类的机制。
		c++98:引入STL标准模板库
		c++11:增加了许多新特性（auto关键字、新容器、标准线程、新容器）
	2、封装、继承、多态---面向对象的特点
	3、c++从事的领域：操作系统、服务器后端开发、人工智能python、网络工具、游戏开发、嵌入式领域、分布式应用、数字图像处理、移动设备。
二、
	1、c语言的关键字：在哪个版本中有多少关键字 --- 32
	2、c++98中的关键字：63个
	3、（1）命名空间：解决命名冲突或名字污染
       （2）命名空间的定义格式：
                 关键字：namespace    
			a、最常见方式
			b、命名空间可以嵌套
			c、在同一工程中，可以定义多个名字相同的命名空间
	注意：1、相同名称的两个命名空间，变量的名称不能相同（相同作用域中不能出现相同的名字）
		  2、相同名称的多个命名空间中：也不能出现相同的名字因为编译器会将多个相同名称的命名空间最终合并成一个
	4、命名空间中成员的使用方式
		(1)、命名空间名字::成员
		(2)、对N命名命名空间中某些成员访问的非常频繁
		(3)、假设N命名空间中许多成员在当前文件中使用非常频繁
三、
    C++中的输入和输出
    输入：cin >> b >> c;

	输出：cout << a << " " << b << " " << c << endl;


四、代码 
#if 0
// 命名空间定义格式
namespace N
{
	// 变量
	// 函数
}
#endif



#if 0
// 三种定义方式
// 1. 最常见方式
namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}


// 2. 命名空间可以嵌套
// 类似于：一个学校中可以包含多个学院
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

	//嵌套的方式----该种方式不会冲突
	// 相当于外层N命名空间中又包含了一个N的命名空间
	namespace N
	{
		int b = 10;
		int a = 10;
	}
}
#endif

// 3. 在同一工程中，可以定义多个名字相同的命名空间
// 不会冲突
// 编译器会将多个相同名称的命名空间合并成一个
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
// 命名空间中成员的使用方式
// 场景一：命名空间名字::成员
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

	// 就近原则
	printf("%d\n", a);

	// 如果访问全局作用域中的a
	// ::作用域运算符
	// ::a  明确说明要访问全局作用域中的a
	printf("%d\n", ::a);


	// 访问N命名空间中的a
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


// 场景二：对N命名命名空间中某些成员访问的非常频繁
// 优点：写代码简单了
// 缺点：如果该文件中有相同名称的变量或者函数，就会产生冲突
// 如果产生冲突，怎么办？----按照方式1使用即可

// 该条语句加上之后，相当于将N命名空间中的a当成当前文件的一个全局变量来使用
using N::a;


// 如果该文件中也有一个a，必然会产生冲突，只能按照方式1来进行使用
//int a = 10;

int main()
{
	int a = 10;

	// 访问N命名空间中的a
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);

	// 为了写代码简单，想要直接访问N命名空间中的a
	printf("%d\n", a);
	return 0;
}
#endif


#if 0
// 场景三：假设N命名空间中许多成员在当前文件中使用非常频繁

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

// 将当前N命名空间中所有的成员当成该文件的全局变量
// 优点：使用非常简单
// 缺陷：产生冲突的概率可能会非常大
// 如果产生冲突，解决：按照方式1使用
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



// C++中的输入和输出
// 注意：C语言中输入和输出的方式在c++中仍旧可以使用----因为C++要兼容C语言

// C++自己还是搞了一套输入和输出的方式，因为C语言中输入输出方式太麻烦了

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

// 注意：<iostream.h>  旧库中包含的
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