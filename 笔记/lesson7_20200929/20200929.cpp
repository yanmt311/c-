#include <iostream>
using namespace std;

知识点1：如何计算一个类/对象的大小？ --- 类对象的存储方式
#if 0
// 如果我们知道对象中都包含哪些内容
class  Student
{
public:
	// 成员变量
	char _name[20];
	char _gender[3];
	int _age;

public:
	// 成员函数
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	// 注意：成员函数如果在类内部类进行定义，成员函数可能会被编译器当成内联函数来对待
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};


int main()
{
	Student s1,s2,s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	
	cout << sizeof(s1) << endl;
	return 0;
}
#endif

知识点2：特殊类的大小？空类
#if 0
class A
{
public:
	void SetA(int a)
	{
		_a = a;
	}

private:
	int _a;
};


class B
{
public:
	void TestB()
	{}
};


class C
{
	
};
int main()
{
	// 结论：求一个类的大小--->只需将类中"成员变量"加起来，注意内存对齐
	cout << sizeof(A) << endl;   // 4
	cout << sizeof(B) << endl;   // 1
	cout << sizeof(C) << endl;   // 1
}
#endif


知识点3：空的结构体是多少呢？
// 分析：在C++中，用struct定义出来的结构体就是类
// 空类
#if 0
struct D
{};

int main()
{
	cout << sizeof(D) << endl;
}
#endif


相关面试题：结构体起始位置的偏移量
#if 0 
struct AA
{
	int a;
	char b;
	double c;
	char d;
};

int main()
{

	// 需求：给你一个结构体AA，然后再给AA中的一个成员c
	// 想要知道：AA结构体中的c成员相对于结构体起始位置的偏移量是多少？
	cout << offsetof(AA, c) << endl;//8 因为int 4 ； char对齐4 所以起始偏移量为8
	return 0;
}
#endif


知识点4：c语言中，结构体如何访问成员
#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

// 必须要实现一个操作结构体类型变量的方法
void InitStudent(Student* ps, char* name, char* gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}

// 打印那个学生的信息，必须将该学生类型的结构体类型的变量传进来
void PrintStudent(Student* ps)
{
	printf("%s-%s-%d\n", ps->_name, ps->_gender, ps->_age);
}

int main()
{
	struct Student s1, s2, s3;
	InitStudent(&s1, "Peter", "男", 18);
	InitStudent(&s2, "David", "男", 19);
	InitStudent(&s3, "Lily", "女", 18);

	PrintStudent(&s1);
	PrintStudent(&s2);
	PrintStudent(&s3);
	return 0;
}
#endif
 
知识点5：c++中，结构体如何访问成员  只是将c中的ps换成this
#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

// 必须要实现一个操作结构体类型变量的方法
void InitStudent(Student* this, char* name, char* gender, int age)
{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
}

// 打印那个学生的信息，必须将该学生类型的结构体类型的变量传进来
void PrintStudent(Student* this)
{
	printf("%s-%s-%d\n", this->_name, this->_gender, this->_age);
}

int main()
{
	struct Student s1, s2, s3;
	InitStudent(&s1, "Peter", "男", 18);
	InitStudent(&s2, "David", "男", 19);
	InitStudent(&s3, "Lily", "女", 18);

	PrintStudent(&s1);
	PrintStudent(&s2);
	PrintStudent(&s3);
	return 0;
}
#endif



知识点6：打印this地址来观察当前调用的是哪个对象
		 this只能在成员函数体内使用
#if 0
class  Student
{
public:
	// 成员变量
	char _name[20];
	char _gender[3];
	int _age;

public:
	
	void InitStudent(char name[], char gender[], int age);
	{
	
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};


int main()
{
	//cout << this << endl;//this只能在成员函数体内使用，不能再主函数中使用
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif



知识点7：this的类型为 类类型* const
#if 0
class  Student
{
public:
	// 成员变量
	char _name[20];
	char _gender[3];
	int _age;

public:
	void InitStudent(char name[], char gender[], int age);
	{
		// 不能给this指针来进行赋值----Student* const this
		//                          类类型* const
		//this = nullptr;//报错，提示左操作数不能等于右值
		cout << this << endl;

		// 有了this指针，成员函数就知道现在是在操作那个对象
		// 注意：对成员变量的操作都是通过this指针来进行的
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif




知识点8：this是隐形的形参
#if 0
class  Student
{
public:
	// 成员变量
	char _name[20];
	char _gender[3];
	int _age;

public:
	// 成员函数
	// 看起来该函数有三个参数，实际上有4个参数
	// 另外一个参数是：隐藏的this指针
	// 在写代码期间，用户不用显式给出this指针，编译器在编译代码时，会自动加上this指针的参数
	void InitStudent(char name[], char gender[], int age)
	{
		cout << this << endl;	
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}

};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif


知识点9：this一般通过ecx寄存器自动传递，有时采用调用约定
9.1 ecx寄存器自动传递
#if 0
class  Student
{
public:
	// 成员变量
	char _name[20];
	char _gender[3];
	int _age;

public:
	
	void InitStudent(char name[], char gender[], int age)
	{
		cout << this << endl;

		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	return 0;
}
#endif


9.2 调用约定
#if 0
class  Student
{
public:
	char _name[20];
	char _gender[3];
	int _age;

public:
	void TestFunc(...){};
};


int main()
{
	Student s1, s2, s3;
	s1.TestFunc(1);
	s2.TestFunc(1, 2);
	s3.TestFunc(1, 2, 3);
	return 0;
}
#endif


9.3 两种方式的区别
#if 0
class  Student
{
public:
	char _name[20];
	char _gender[3];
	int _age;

public:
	void InitStudent(char name[], char gender[], int age);
	void TestFunc(...);
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.TestFunc(1);
	s2.TestFunc(1, 2);
	s3.TestFunc(1, 2, 3);
	return 0;
}
#endif


引入知识点10：全局变量在使用之前必须先定义
int g_a = 10;

int main()
{
	g_a = 10;
	return 0;
}

void TestFunc()
{
	g_a = 10;
}



知识点10：成员变量再类中的任意位置，为什么不报错？编译器是如何实现的。
		  成员变量可以再类的任意位置来进行定义，而且可以再"任意成员函数"中使用
		  就相当于：成员变量就类似于成员函数的全局变量
		  
// 成员变量在后，成员变量的使用在前，编译器怎么不报错呢？
// 因为：编译器是这样子来处理类：

/*
1. 先识别类名
2. 再来识别类中的成员变量
3. 最后识别类中的成员函数，并对成员函数进行修改----主要是增加this指针
*/
class  Student
{
public:

	/*
	增加this后：
	void InitStudent(Student* const this, char name[], char gender[], int age)
	{
	    strcpy(this->_name, name);
	    strcpy(this->_gender, gender);
	    this->_age = age;
	}
	*/
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	/*
	增加this后：
	void PrintStudent(Student* const this)
	{
		printf("%s\n", this->_name);
		printf("%s\n", this->_gender);
		printf("%d\n", this->_age);
	}
	*/
	void PrintStudent()
	{
		printf("%s\n", _name);
		printf("%s\n", _gender);
		printf("%d\n", _age);
	}

private:
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
}




