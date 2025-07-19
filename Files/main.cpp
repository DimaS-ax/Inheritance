#include<iostream>
#include<fstream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	//1 Содать поток:
	std::ofstream fout;

	//2 Открываем поток
	fout.open("file.txt", std::fstream::app);//app-append (добавит в конец)

	//3 Пишем в поток
	fout << "Hello Files!" << endl;

	//4 Потоки как холодильник,если он открыт,его нужно закрыть
	fout.close();


	system("notepad file.txt");
#endif // WRITE_TO_FILE

	//1 Создаем и открываем поток
	std::ifstream fin("file.txt");

	//2 Проверяем открылся ли поток
	if (fin.is_open())
	{
		while (!fin.eof())// eof - End of file
		{
			const int SIZE = 256;
			char sz_buffer[SIZE] = {};
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close(); //Поток есть смысл закрывать,если он открыть
	}
	else
	{
		std::cerr << "Error: file not foud" << endl;
	}
}