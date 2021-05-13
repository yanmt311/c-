lesson5
目录：
知识点1：const修饰的常量---类似于宏替换
知识点2：C++中，使用const修饰的常量来取代C语言中的宏
	2.1 宏
	2.2 const修饰的常量
	2.3 证明在c++中const修饰的变量为常量，不能被修改
	2.4 c++中，const修饰的常量相比于宏的优势
知识点3：内联函数
知识点4：内联函数特性
	4.1 内联函数：空间换时间
	4.2 对于循环和递归的内联函数，编译器会自动优化.
	4.3 内联函数定义和声明分离会链接错误
	补充：宏的缺陷，使用内联函数来解决
知识点5：auto
	5.1 auto定义
	5.2 auto和指针结合使用 ---都一样
	5.3 auto和引用结合使用 --要加&区分
	5.4 auto可以定义多个变量--必须同一类型
	5.5 auto不能使用的两个场景
		5.5.1 auto不能作为函数的参数
		5.5.2 auto不能直接来声
	5.6 auto的两种使用场景
		5.6.1 复杂类型的推演
		5.6.2 范围for循环
		
		
		
#include <iostream>
using namespace std;
知识点1：const修饰的常量---类似于宏替换

	c++，被const修饰的变量一般称为常量，而被const修改的常量还具有宏替换的作用。
	     其中宏替换就是在编译阶段，所有使用const常量的位置，用常量的值代替该常量（除&常量外）
	c，const修饰的变量不能称为常量，只能称为不能修改的变量。
例1：观察a和*pa的值
#if 0
int main(){
	
	const int a = 10;
	int* pa = (int*) &a;//&a结果的类型为const int*，表明该地址指向的空间中的内容不允许被更改。
	*pa = 100;
	
	printf("%d\n",a);//10
	cout << a << endl;//10 ---在编译阶段，所有使用const常量的位置，用常量的值代替该常量（除&常量）
	cout << *pa << endl;//100

}
#endif

例2：观察a，b，MAX，*pa值

	a：c++中const修饰的常量
	b：变量
	MAX：宏
	*pa：指针
	*&a：a

#if 0
#define  MAX 10            //宏
int main()
{
	const int a = 10;      //c++中const修饰的常量
	int* pa = (int*)&a;    // &a结果的类型 const int*--->表明该地址指向的空间中内容不允许被修改
	*pa = 100              //指针
	int b = 20;            //变量b
	
	//观察a,b,MAX反汇编，发现a和MAX没有进行内存访问，直接进行压栈，而b要先取变量的值再压栈
	printf("%d\n", MAX);   // *&a<==>a 
	printf("%d\n", a);     
	printf("%d\n", b);
	printf("%d\n", *&a);   //*&a结果就是a本身--->既然是a本身--->替换为10

	cout << a << endl;     //类似cout << 10 << endl;
	cout << *pa << endl;
	return 0;
}
#endif
注意：内存中a的值已经改为100了，但是a变量没有访问内存地址，所以即使内存数据改变，输出的数据也是没变的，
      *pa结果为100，因为其访问了内存空间。
--------------------------------------------------------------------------------------------------------------------------------------

知识点2：C++中，使用const修饰的常量来取代C语言中的宏
2.1 宏
#if 0
#define  MAX 10
int main()
{
	// 宏在预处理阶段会被宏体来进行替换

	int a = 100;
	a = MAX;  // 该条语句在预处理阶段已经被修改为：a = 10;
	return 0;
}
#endif

2.2 const修饰的常量
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

2.3 证明在c++中const修饰的变量为常量，不能被修改
#if 0
int main()
{
	const int a = 10;

	 int array[a];
	//a = 10;

	return 0;
}
#endif

2.4 c++中，const修饰的常量相比于宏的优势
#if 0
// 宏的替换发生在预处理阶段----但是宏不会
// const修饰的常量替换发生在编译阶段---->而const修饰的常量是有类型的，因此会参与类型检测


// 宏不会进行类型检测，因为其在预处理阶段已经被替换
#define PI  "3.14"


// pi的类型是double类型的   "3.14"是字符串类型   编译阶段知道类型不匹配而报错
const double pi = "3.14";

// 一般情况下：在C++中 更建议使用const修饰的常量来取代C语言中的宏
// 因为：const修饰的内容已经是常量了，而且会参与类型检测，比宏常量使用起来更安全

int main()
{
	int r = 2;

	double s = PI * r * r;   // 宏替换：s = "3.14" * r * r;

	double s = pi * r * r;
	return 0;
}
#endif
-----------------------------------------------------------------------------------------------------------------
宏的缺陷：
#if 0
#define MAX(a, b) (a > b ? a : b)


int main()
{
	int a = 10;
	int b = 20;

	cout << MAX(++b, a) << endl;  //该条语句在预处理阶段被替换为： cout <<(a > b ? a : b)<< endl;
	cout << MAX("hello", 100) << endl;

	return 0;
}
#endif
------------------------------------------------------

知识点3：内联函数
		注意：在C++中，一般对于比较短小的函数，建议写成内联函数 ---加inline

在c++中，宏常量 --- 使用const修饰的常量来替代
		 宏函数 --- 使用inline修饰的内联函数来代替
debug调试模式：内联函数默认是不会展开。 
	--- debug主要是来调试代码的，如果编译器将内联函数展开了，代码就不方便调试了。
release模式下，编译器对代码的优化是非常高的。占用空间更小。


宏函数和内联函数的缺点：展开后会造成代码膨胀
#if 0
inline int Add(int left, int right)
{
	return left + right;
}
int main()
{
	// 在Release模式下，编译器对代码的优化是非常高的，Add的函数调用已经没有了，直接给了30
	// 在Release版本下，main函数中的5行代码直接被优化成：printf("%d\n", 30);
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b); 
	printf("%d\n", c);		
	
	return 0;
}
#endif
---------------------------------------------------------------------

知识点4：内联函数特性：
1.inline是一种以空间换时间的做法，省去调用函数额开销。
  所以代码很长或者有循环/递归的函数不适宜使用作为内联函数。

2.inline对于编译器而言只是一个建议，编译器会自动优化.
  如果定义为inline的函数体内有循环/递归等等，编译器优化时会忽略掉内联。
  
3.inline不建议声明和定义分离，分离会导致链接错误。
  因为inline被展开，就没有函数地址了，链接就会找不到。
  
4.1 内联函数：空间换时间
#if 0
inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	int a = 10;
	int b = 20;	
	// 假设：Add函数中5行代码  --- 空间换时间的做法
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);	
	return 0;
}
#endif

4.2 对于循环和递归的内联函数，编译器会自动优化.
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
	TestInline();//循环
	Fac(5);//递归
	return 0;
}
#endif

4.3 内联函数定义和声明分离会链接错误
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

	cout << MAX(++b, a) << endl;  //该条语句在预处理阶段被替换为： cout <<(a > b ? a : b)<< endl;
	cout << MAX("hello", 100) << endl;

	return 0;
}
#endif

解决了宏的缺陷：结果为21
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

知识点5：C++11中的语法糖
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

	auto aa;//必须进行初始化
	return 0;
}
#endif

5.2 auto和指针结合使用 ---都一样
#if 0
int main()
{
	int a = 10;

	auto* pa1 = &a;
	auto  pa2 = &a;

	// pa1和pa2最终打印的都是int*
	// auto定义指针类型变量时，加*和不加* 没有区别
	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;

	return 0;
}
#endif

5.3 auto和引用结合使用 --要加&区分
#if 0
int main()
{
	int b = 10;
	// rb1是新定义了一个整形的变量
	auto rb1 = b;  //rb1的地址和b的地址不一样
	// rb2是b的别名
	auto& rb2 = b; //rb2的地址和b的地址一样

	// 使用auto来定义引用类型变量时，必须要分&的标记，不加就定义了一个新的变量，加了就是引用
	cout << typeid(rb1).name() << endl;
	cout << typeid(rb2).name() << endl;

	auto  a1 = 10, a2 = 20;

	//auto b1 = 10, b2 = 12.34;
	return 0;
}
#endif

5.4 auto可以定义多个变量--必须同一类型
#if 0
int main()
{
	auto  a1 = 10, a2 = 20;
	//auto b1 = 10, b2 = 12.34;//错误
	return 0;
}
#endif

5.5 auto不能使用的两个场景
5.5.1 auto不能作为函数的参数
      并不是所有的参数都有初始化表达式，因此编译器无法推演a的实际类型
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

5.5.2 auto不能直接来声明数组
#if 0
int main()
{
	//根据类型给数组开辟空间
	int array1[] = { 1, 2, 3 };
	auto array2[] = { 3, 4, 5 };
	return 0;
}
#endif

5.6 auto的两种使用场景
第一种场景：复杂类型的推演
#if 0
#include <map>
#include <string>
int main()
{
	std::map<std::string, std::string> m{ { "apple", "苹果" }, {"orange","橙子"} };
	
	std::map<std::string, std::string>::iterator it1 = m.begin();
	auto it2 = m.begin();
	return 0;
}
#endif

第二种场景：范围for循环
给数组中的每个元素乘2：
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
auto在for循环中的使用
int main()
{
	// 在C++11中
	// for循环还可以这么写
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	
	// 范围for循环
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << " ";
	cout << endl;
	
	return 0;
}
#endif

