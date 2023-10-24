#include "Libraries.h"
#include "SequenceFromKeyboard.h"
#include "Test.h"
using namespace std;

std::ofstream out;

void print(std::vector <int>& v)
{
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

int main()
{
	do
	{
		cin.clear();
		cin.sync();
		system("pause");
		system("cls");
		cout << "-------Sorting algorithms-------" << endl;
		cout << "1 - Read from console\n2 - Tests\n3 - Exit\nChoose option: ";
		char o = getch();
		cout << o << endl;
		switch (o)
		{
		case '1':
			keyboard();
			break;
		case '2':
			test();
			break;
		case '3':
			return 0;
			break;
		default:
			cout << "Write correct value!" << endl;
		}
	} while (true);
}
