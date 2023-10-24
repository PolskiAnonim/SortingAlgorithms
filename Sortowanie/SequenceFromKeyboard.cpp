#include "SequenceFromKeyboard.h"

using namespace std;

vector<int> split(string& sentence)
{
	int position = 0;
	int i = 0;
	int j = 0;
	int x = 0;
	string word;
	vector<int>v;
	sentence += ' ';

	while ((position = sentence.find(' ', position + i)) != string::npos && v.size() < 10)
	{
		word = sentence.substr(j + i, position - j - i);
		if (word.size() > 0)
		{
			x = strtol(word.c_str(), NULL, 10);
			v.push_back(x);
		}
		i = 1;
		j = position;

	}
	return v;
}

void keyboard()
{
	int nr = 0;
	string s;
	cout << "Write sequence (numbers separated by space):" << endl;
	getline(cin, s);
	vector <int> sequence = split(s);
	system("cls");
	cout << "Sequence: ";
	print(sequence);
	mergeSort(sequence, 0, nr);
	heapSort(sequence, 0, nr);
	insertionSort(sequence, 0, nr);
	shellSort(sequence, 0, nr);
	quickSort(sequence, 0, nr);
}