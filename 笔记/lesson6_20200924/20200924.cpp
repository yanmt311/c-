֪ʶ��1��c��c++struct
	1.1 c�����еĽṹ��--�����Զ��庯��
	1.2 c++�нṹ����Զ��庯�������ҷ��ʲ���Ҫstruct������
	1.3 class��
		1.3.1 ����һ����
			1.3.1.1 ��ʽһ������Ա���������������ж���
			1.3.1.2 ��ʽ��������Ա������������ֿ�
		1.3.2 �����Ͷ��������
		1.3.3 ��װ������޶���������������--��this
		
		
		
#include <iostream>
using namespace std;

֪ʶ��1��
	��C++�У�struct������������;Ϳ��Կ�����һ������
	C�����еĽṹ�� ��C++�� ҡ��һ�� ���--->������һ����
	
	
1.1 c�����еĽṹ��--�����Զ��庯��
    ���ڽṹ���еĳ�Ա�������ʷ�ʽ��Ҫ��struct
	eg��struct Student s1;
#if 0
struct  Student 
{
	// �ṹ���еı���
	char _name[20];
	char _gender[3];
	int _age;

	void SetAge(int age)
	{
		_age = age;
	}
};

int main()
{
	// ��C�����еķ�ʽ
	struct Student s1;
	s1._age = 10;
	return 0;
}
#endif

1.2 c++�нṹ����Զ��庯�������ҷ��ʲ���Ҫstruct������
#if 0
struct  Student 
{
	// �ṹ���еı���
	char _name[20];
	char _gender[3];
	int _age;


	// �ṹ���еĺ���
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
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
	// ��C++��
	Student s2;
	s2.InitStudent("Peter", "��", 18);
	s2.SetAge(10);
	return 0;
}
#endif
1.3 class��
#if 0
// ֻ��������C++�У����Ҫ�����࣬���Ǹ�ϲ��ʹ��class�Ĺؼ���
1.3.1 ����һ����
1.3.1.1 ��ʽһ������Ա���������������ж���
class  Student
{
private:
	// ��Ա����
	char _name[20];
	char _gender[3];
protected:
	int _age;

public:
	// ��Ա����
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	// ע�⣺��Ա������������ڲ�����ж��壬��Ա�������ܻᱻ���������������������Դ�
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};
#endif

1.3.2 �����Ͷ��������
#if 0 
class  Student
{
	// ��Ա����
	char _name[20];
	char _gender[3];
	int _age;

	// ��Ա����
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
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
	// Student�����������Խ��俴����ѧ����һ��Ⱥ��
	// s����Student�ඨ������Ķ���

	Student s;

	// ���뱨����ΪStudent����һ�������ѧ�������ǲ��ܽ����֡��Ա�����ŵ�Student��
	//Student.InitStudent("Peter", "��", 18);

	// s��һ��������ڵ�ѧ�������ǲſ��Խ����֡��Ա�����ŵ������ѧ��������
	// �����޷�����private�ĳ�Ա
	s.InitStudent("Peter", "��", 18);
	s.PrintStudent();

	//s._age = 10;
	return 0;
}
#endif

1.3.3 ��װ������޶���������������--��this
class  Student
{
private:
	// ��Ա����
	char _name[20];
	char _gender[3];
	int _age;

public:
	// ��Ա����
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	// ע�⣺��Ա������������ڲ�����ж��壬��Ա�������ܻᱻ���������������������Դ�
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
	Student s1, s2,s3;
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 20);
	s3.InitStudent("Lucy", "Ů", 19);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}