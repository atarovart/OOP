#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string m_name;
	unsigned int m_age;
	string m_sex;
	unsigned int m_weight;
public:
	int a;
	void human(string name, unsigned int age, string sex, unsigned int weight)
	{
		m_name = name;
		m_age = age;
		m_sex = sex;
		m_weight = weight;
	}
	void printhuman()
	{
		cout << m_name << endl << m_age << endl << m_sex << endl << m_weight << endl;

	}
};
class Student : public Person
{
public:
	void student(double yearofeducation)
	{
		double m_yearofeducation = yearofeducation;
	}
	void printstudent()
	{
		cout << m_yearofeducation << endl;
	}
private:
	double m_yearofeducation;
};



int main()
{
	Person person1;
	person1.human("Igor", 21, "M", 75);

	Student student1;
	student1.human("Ivan", 29, "M", 91 );
	student1.student(2021);

	Student student2;
	student2.human("Ksenia", 24, "W", 50);
	student2.student(2019);

	int a;
	cout << "Enter number of candidate: " << endl;
	cin >> a;
	if (a == 1)
	{
		cout << person1.printhuman << endl; //Не компилируется. 
	}
	return 0;
}
