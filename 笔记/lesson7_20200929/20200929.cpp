#include <iostream>
using namespace std;

֪ʶ��1����μ���һ����/����Ĵ�С�� --- �����Ĵ洢��ʽ
#if 0
// �������֪�������ж�������Щ����
class  Student
{
public:
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
	Student s1,s2,s3;
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	
	cout << sizeof(s1) << endl;
	return 0;
}
#endif

֪ʶ��2��������Ĵ�С������
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
	// ���ۣ���һ����Ĵ�С--->ֻ�轫����"��Ա����"��������ע���ڴ����
	cout << sizeof(A) << endl;   // 4
	cout << sizeof(B) << endl;   // 1
	cout << sizeof(C) << endl;   // 1
}
#endif


֪ʶ��3���յĽṹ���Ƕ����أ�
// ��������C++�У���struct��������Ľṹ�������
// ����
#if 0
struct D
{};

int main()
{
	cout << sizeof(D) << endl;
}
#endif


��������⣺�ṹ����ʼλ�õ�ƫ����
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

	// ���󣺸���һ���ṹ��AA��Ȼ���ٸ�AA�е�һ����Աc
	// ��Ҫ֪����AA�ṹ���е�c��Ա����ڽṹ����ʼλ�õ�ƫ�����Ƕ��٣�
	cout << offsetof(AA, c) << endl;//8 ��Ϊint 4 �� char����4 ������ʼƫ����Ϊ8
	return 0;
}
#endif


֪ʶ��4��c�����У��ṹ����η��ʳ�Ա
#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

// ����Ҫʵ��һ�������ṹ�����ͱ����ķ���
void InitStudent(Student* ps, char* name, char* gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}

// ��ӡ�Ǹ�ѧ������Ϣ�����뽫��ѧ�����͵Ľṹ�����͵ı���������
void PrintStudent(Student* ps)
{
	printf("%s-%s-%d\n", ps->_name, ps->_gender, ps->_age);
}

int main()
{
	struct Student s1, s2, s3;
	InitStudent(&s1, "Peter", "��", 18);
	InitStudent(&s2, "David", "��", 19);
	InitStudent(&s3, "Lily", "Ů", 18);

	PrintStudent(&s1);
	PrintStudent(&s2);
	PrintStudent(&s3);
	return 0;
}
#endif
 
֪ʶ��5��c++�У��ṹ����η��ʳ�Ա  ֻ�ǽ�c�е�ps����this
#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

// ����Ҫʵ��һ�������ṹ�����ͱ����ķ���
void InitStudent(Student* this, char* name, char* gender, int age)
{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
}

// ��ӡ�Ǹ�ѧ������Ϣ�����뽫��ѧ�����͵Ľṹ�����͵ı���������
void PrintStudent(Student* this)
{
	printf("%s-%s-%d\n", this->_name, this->_gender, this->_age);
}

int main()
{
	struct Student s1, s2, s3;
	InitStudent(&s1, "Peter", "��", 18);
	InitStudent(&s2, "David", "��", 19);
	InitStudent(&s3, "Lily", "Ů", 18);

	PrintStudent(&s1);
	PrintStudent(&s2);
	PrintStudent(&s3);
	return 0;
}
#endif



֪ʶ��6����ӡthis��ַ���۲쵱ǰ���õ����ĸ�����
		 thisֻ���ڳ�Ա��������ʹ��
#if 0
class  Student
{
public:
	// ��Ա����
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
	//cout << this << endl;//thisֻ���ڳ�Ա��������ʹ�ã���������������ʹ��
	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif



֪ʶ��7��this������Ϊ ������* const
#if 0
class  Student
{
public:
	// ��Ա����
	char _name[20];
	char _gender[3];
	int _age;

public:
	void InitStudent(char name[], char gender[], int age);
	{
		// ���ܸ�thisָ�������и�ֵ----Student* const this
		//                          ������* const
		//this = nullptr;//������ʾ����������ܵ�����ֵ
		cout << this << endl;

		// ����thisָ�룬��Ա������֪���������ڲ����Ǹ�����
		// ע�⣺�Գ�Ա�����Ĳ�������ͨ��thisָ�������е�
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
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif




֪ʶ��8��this�����ε��β�
#if 0
class  Student
{
public:
	// ��Ա����
	char _name[20];
	char _gender[3];
	int _age;

public:
	// ��Ա����
	// �������ú���������������ʵ������4������
	// ����һ�������ǣ����ص�thisָ��
	// ��д�����ڼ䣬�û�������ʽ����thisָ�룬�������ڱ������ʱ�����Զ�����thisָ��Ĳ���
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
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif


֪ʶ��9��thisһ��ͨ��ecx�Ĵ����Զ����ݣ���ʱ���õ���Լ��
9.1 ecx�Ĵ����Զ�����
#if 0
class  Student
{
public:
	// ��Ա����
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
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	return 0;
}
#endif


9.2 ����Լ��
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


9.3 ���ַ�ʽ������
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
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.TestFunc(1);
	s2.TestFunc(1, 2);
	s3.TestFunc(1, 2, 3);
	return 0;
}
#endif


����֪ʶ��10��ȫ�ֱ�����ʹ��֮ǰ�����ȶ���
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



֪ʶ��10����Ա���������е�����λ�ã�Ϊʲô�����������������ʵ�ֵġ�
		  ��Ա�����������������λ�������ж��壬���ҿ�����"�����Ա����"��ʹ��
		  ���൱�ڣ���Ա�����������ڳ�Ա������ȫ�ֱ���
		  
// ��Ա�����ں󣬳�Ա������ʹ����ǰ����������ô�������أ�
// ��Ϊ�����������������������ࣺ

/*
1. ��ʶ������
2. ����ʶ�����еĳ�Ա����
3. ���ʶ�����еĳ�Ա���������Գ�Ա���������޸�----��Ҫ������thisָ��
*/
class  Student
{
public:

	/*
	����this��
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
	����this��
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
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
}




