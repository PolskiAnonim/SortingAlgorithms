#include "Test.h"
using namespace std;

vector<int> generator(int nr, int n)
{
	int i = 0;
	int k = 0;
	vector<int> x;
	if (nr == 1 || nr == 2)	//random sequence
	{
		for (i; i < n; i++)
			x.push_back(rand() % (n * 10) + 1);
		return x;
	}
	else if (nr == 3 || nr == 4)	//increasing sequence
	{
		x.push_back(rand() % 10 + 1);
		for (i; i < n - 1; i++)
			x.push_back(x[i] + rand() % 11);
		return x;
	}
	else if (nr == 5 || nr == 6)	//decreasing sequence
	{
		x.push_back(rand() % 10 + n * 10 - 9);
		for (i; i < n - 1; i++)
			x.push_back(x[i] - rand() % 11);
		return x;
	}
	else if (nr == 7 || nr == 8)	//A shaped
	{
		x.push_back(rand() % 10 + 1);
		for (i; i < (n - 1) / 2; i++)
			x.push_back(x[i] + rand() % 11);
		k = x[i];
		for (i; i < n - 1; i++)
			x.push_back(x[i] - rand() % ((k - 1) / (n / 2)));
		return x;
	}
	else if (nr == 9 || nr == 10)	//V shaped
	{
		x.push_back(rand() % 10 + n * 10 - 9);
		for (i; i < (n - 1) / 2; i++)
			x.push_back(x[i] - rand() % 11);
		k = x[i];
		for (i; i < n - 1; i++)
			x.push_back(x[i] + rand() % ((n * 10 - k) / (n / 2)));
		return x;
	}
}

void test()
{
	out.open("results.txt");
	out << "Length;Type;Sort type;Time;Comparisons;Swapped elements" << endl;
	srand(time(NULL));
	for (int n = 200; n < 2500; n += 200)
	{
		cout << "Sequence length: " << n << endl << endl;

		for (int i = 1; i <= 10; i++)
		{
			vector<int> sequence = generator(i, n);

			mergeSort(sequence, 1, i);
			heapSort(sequence, 1, i);
			insertionSort(sequence, 1, i);
			shellSort(sequence, 1, i);
			quickSort(sequence, 1, i);
			cout << endl;
		}
	}
	out.close();
}