1.2.1.2方式二：将成员函数声明和定义分开
声明在头文件类中，定义在源文件

#include "Person.h"

#include <iostream>
using namespace std;


// 注意：成员函数如果放在类外来进行定义
// 成员函数名之前必须要加：类名::  表明该函数是那个类的成员函数
// 如果没有加，就相当于是在全局作用域中定义了一个函数 --- 会编译报错，说未定义标识符

void Person::InitPerson(char name[], char gender[], int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void Person::Eat()
{
	cout << "biajibiaji" << endl;
}

void Person::Sleep()
{
	cout << "呼呼呼~" << endl;
}

void Person::PrintPersonInfo()
{
	cout << _name << "-" << _gender << "-" << _age << endl;
}