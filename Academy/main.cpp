#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define DELIMETR "\n-----------------------"

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETRS  last_name,  first_name,  age

class Human 
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	//Constructors:
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//Methods:
	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}

};

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GiVE_PARAMETRS  speciality,  group,  rating,  attendance

class Student :public Human
{
	std:: string speciality;
	std::string group;
	double rating;//успеваемость
	double attendance;//посещаемость
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendanmce()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//Constructors:
	Student
	(
		HUMAN_TAKE_PARAMETRS,
		STUDENT_TAKE_PARAMETRS
	):Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//Methods:
	void info()const override
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETRS const std::string& speciality, int experiance
#define TEACHER_GIVE_PARAMETRS speciality, experiance

class Teacher :public Human
{
	std::string speciality;
	int experiance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experiance()const
	{
		return experiance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experiance(int experiance)
	{
		this->experiance = experiance;
	}
	//Constructors:
	Teacher
	(
		HUMAN_TAKE_PARAMETRS,
		TEACHER_TAKE_PARAMETRS
	) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experiance(experiance);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//Methods:
	void info()const override
	{
		Human::info();
		cout << speciality << " " << experiance << endl;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, const std::string& subject)
		:Student(HUMAN_GIVE_PARAMETRS, STUDENT_GiVE_PARAMETRS)
	{
		this->subject = subject;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	
	void info() const override
	{
		Student::info();
		cout << subject << endl;
	}

};

//#define INHERITANCE
#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.Info();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 99);
	student.info();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.info();

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "VV_220", 40, 60, "How to catch Heisenberg");
	graduate.info();
#endif // INHERITANCE

	Human* group[] =
	{
		new Human("Montana", "Antonio", 25),
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 99),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "VV_220", 40, 60, "How to catch Heisenberg"),
		new Student("Vercetty","Tomy",30,"Theft","Vice",98,99),
		new Teacher("Diar","Ricardo",50,"Weapons distribution",20)
	};

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
		cout << DELIMETR << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

}