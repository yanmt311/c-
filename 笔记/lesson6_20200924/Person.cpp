#include "Person.h"

#include <iostream>
using namespace std;


// ע�⣺��Ա��������������������ж���
//   ��Ա������֮ǰ����Ҫ�ӣ�����::  �����ú������Ǹ���ĳ�Ա����
// ���û�мӣ����൱������ȫ���������ж�����һ������

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
	cout << "������~" << endl;
}

void Person::PrintPersonInfo()
{
	cout << _name << "-" << _gender << "-" << _age << endl;
}