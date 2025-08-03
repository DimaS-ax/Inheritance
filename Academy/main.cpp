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
	//static const double PI = 3.14;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 3;
	static int count; // Static member declaration
	std::string last_name;
	std::string first_name;
	int age;
public:
	static int get_count()
	{
		return count;
	}
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
		count++;
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		count--;
		cout << "HDestructor:\t" << this << endl;
	}
	//Methods:
	virtual std::ostream& info(std::ostream& os)const
	{
		os.width(LAST_NAME_WIDTH);//метод "width" задает ширину вывода в знакопозици€х
					 //если выводима€ строка меньше,то недостающие символы заполн€ютс€ пробелами
		             //если выводима€ строка больше, она выводитсс€ полностью
		os << std::left;// первый вызов "width" задает выравнивание по правому краю заданного пол€
		os << last_name;
		os.width(FIRST_NAME_WIDTH);
		os << first_name;
		os.width(AGE_WIDTH);
		os << age;
		return os;
		//return os << last_name << " " << first_name << " " << age ;
	}

};
//static member definition: 
int Human::count = 0;//—татическую переменную инициализируем за классами

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.info(os);
	//return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
}

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GiVE_PARAMETRS  speciality,  group,  rating,  attendance

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int GROUP_WIDTH = 8;
	static const int RATTING_WIDTH = 5;
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
	std::ostream& info(std::ostream& os)const override
	{
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(GROUP_WIDTH);
		os << group;
		os.width(RATTING_WIDTH);
		os << rating;
		os.width(RATTING_WIDTH);
		os << attendance;
		return os;
		/*Human::info(os) << " ";
		return os << speciality << " " << group << " " << rating << " " << attendance ;*/
	}
};

#define TEACHER_TAKE_PARAMETRS const std::string& speciality, int experiance
#define TEACHER_GIVE_PARAMETRS speciality, experiance

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int EXPERIENCE_WIDTH = 3;
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
	std::ostream& info(std::ostream& os)const override
	{
		Human::info(os);
		os.width(SPECIALITY_WIDTH);
		os << speciality;
		os.width(EXPERIENCE_WIDTH);
		os << experiance;
		return os;
		/*Human::info(os)<<" ";
		return os << speciality << " " << experiance ;*/
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
	
	std::ostream& info(std::ostream& os) const override
	{
		Student::info(os)<<" ";
		return os << subject ;
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

#ifdef POLYMORPHISM
	Human* group[] =
	{
		new Human("Montana", "Antonio", 25),
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 95, 99),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "VV_220", 40, 60, "How to catch Heisenberg"),
		new Student("Vercetty","Tomy",30,"Theft","Vice",98,99),
		new Teacher("Diar","Ricardo",50,"Weapons distribution",20),
		new Graduate("Targarian","Daineris",22,"Flight","Got",91,92,"How to make smoke"),
		new Teacher("Schwartzneger","Arnold",85,"Heavy Metal",60)
	};

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
		cout << DELIMETR << endl;
	}
	cout << " оличество людей " << Human::get_count() << endl;//—татическа€ переменна€ "COUNT"
	cout << " оличество людей " << group[0]->get_count() << endl;//¬ызвать через обьект
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM


}