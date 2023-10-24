#include "SortingAlgorithms.h"

//-------------------------------------------------------------------------------------------------
//MergeSort
void merging(vector <int>& v, int left, int pivot, int right, pair <int, int>& op)
{
	vector <int> sup(v.size(), 0);
	for (int i = left; i <= pivot; i++) //support vector
		sup[i] = v[i];

	int i = left, j = pivot + 1;

	for (int k = left; k <= right; k++)
	{
		op.first++;
		if (i <= pivot)
		{
			if (j <= right)
			{
				if (sup[i] < sup[j])
				{
					v[k] = sup[j];
					j++;
				}
				else
				{
					v[k] = sup[i];
					i++;
				}
			}
			else
			{
				v[k] = sup[i];
				i++;
			}
		}
		else
		{
			v[k] = sup[j];
			j++;
		}
	}
}

void merge(vector <int>& v, int left, int right, pair <int, int>& op)
{
	if (right == left) return; //end of splitting vector

	int pivot = (left + right) / 2;

	//recursion - splitting to one element vectors
	merge(v, left, pivot, op);
	merge(v, pivot + 1, right, op);
	//merging from the end
	merging(v, left, pivot, right, op);
	op.second++;
}

void mergeSort(vector <int> v, bool k, int& nr)
{
	pair <int, int> op = { 0,0 };	//Comparisions and vector merges
	auto start = chrono::steady_clock::now(); //start measuring time
	merge(v, 0, v.size() - 1, op);
	auto end = chrono::steady_clock::now(); //stop measuring time
	if (k)
	{
		cout << "MergeSort - Time:" << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds";	//sorting time
		cout << " - Comparisons: " << op.first << endl;
		out << v.size() << ";" << nr << ";Merge;" << chrono::duration_cast<chrono::microseconds>(end - start).count() << ";" << op.first << ";" << 0 << endl;
	}
	else
		cout << "MergeSort - Comparisons: " << op.first << " - Merges: " << op.second << endl << endl;
}
//-------------------------------------------------------------------------------------------------
//HeapSort
void insert_vertex(vector <int>& data, int& heap_range, pair <int, int>& op)
{
	int c = 0;
	int r = 0;
	int new_id = heap_range;
	while (new_id > 0)
	{
		int parent_id = new_id / 2;
		c = c + 1;
		if (data[parent_id] > data[new_id])
		{
			swap(data[new_id], data[parent_id]);
			r = r + 1;
			new_id = parent_id;
		}
		else break;
	}
	op.first += c;
	op.second += r;
}

void remove_root(vector <int>& data, int& heap_range, pair <int, int>& op)
{
	int c = 0;
	int r = 0;

	swap(data[heap_range], data[0]);
	heap_range = heap_range - 1;
	int element_id = 0;
	int left_child = 1;
	while (element_id < heap_range)
	{
		int min_son;
		if (left_child + 1 <= heap_range)
		{
			c = c + 1;
			if (data[left_child] > data[left_child + 1])
				min_son = left_child + 1;
			else min_son = left_child;
		}
		else min_son = left_child;
		c = c + 1;
		if (data[min_son] < data[element_id])
		{
			swap(data[element_id], data[min_son]);
			r = r + 1;
			element_id = min_son;
		}
		else break;

		left_child = element_id * 2 + 1;
		if (left_child > heap_range) break;
	}
	op.first += c;
	op.second += r;
}

void heapSort(vector <int> v, bool k, int& nr)
{
	pair <int, int> op = { 0,0 };
	int l = v.size();
	int heap_range = 0;

	auto start = chrono::steady_clock::now();	//start measuring time
	//heap construction
	for (int i = 1; i < l; i++)
	{
		heap_range++;
		insert_vertex(v, heap_range, op);
	}
	//remove root and fixing heap
	for (int i = 0; i < l; i++)
	{
		remove_root(v, heap_range, op);
	}
	auto end = chrono::steady_clock::now();	//stop measuring time
	if (k)
	{
		cout << "HeapSort - Time:" << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds";
		cout << " - Comparisons: " << op.first << " - Swapped elements: " << op.second << endl;
		out << v.size() << ";" << nr << ";Heap;" << chrono::duration_cast<chrono::microseconds>(end - start).count() << ";" << op.first << ";" << op.second << endl;
	}
	else
		cout << "HeapSort - Comparisons: " << op.first << " - Swapped elements: " << op.second << endl << endl;
}
//-------------------------------------------------------------------------------------------------
//InsertionSort
void insertionSort(vector <int> v, bool k, int& nr)
{
	pair <int, int> op = { 0,0 };
	int l = v.size();
	auto start = chrono::steady_clock::now();	//start neasuring time

	for (int i = 1; i < l; i++)
	{
		int id = i;
		for (int j = i - 1; j > -1; j--)
		{
			op.first++;
			if (v[j] < v[id])
			{
				swap(v[j], v[id]);
				id--;
				op.second++;
			}
			else break;
		}
	}
	auto end = chrono::steady_clock::now();	//stop measuring time
	if (k)
	{
		cout << "InsertionSort - Time:" << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds";
		cout << " - Comparisons: " << op.first << " - Swapped elements: " << op.second << endl;
		out << v.size() << ";" << nr << ";Insertion;" << chrono::duration_cast<chrono::microseconds>(end - start).count() << ";" << op.first << ";" << op.second << endl;
	}
	else
		cout << "InsertionSort - Comparisons: " << op.first << " - Swapped elements: " << op.second << endl << endl;
}
//ShellSort
void insertionSortParam(vector <int>& v, int p, pair<int, int>& op)	//insertion sort for sorting some elements
{
	int l = v.size();

	for (int i = 0; i < p; i++)
	{
		for (int j = i + p; j < l; j += p)
		{
			int id = j;
			for (int k = j - p; k > -1; k -= p)
			{
				op.first++;
				if (v[k] < v[id])
				{
					swap(v[k], v[id]);
					id = id - p;
					op.second++;
				}
				else break;
			}
		}
	}

}

void shellSort(vector <int> v, bool k, int& nr)
{
	pair <int, int> op = { 0,0 };
	int gap = 1;
	int p = 1;
	int l = v.size();

	while (true)	//calculate gap sequence
	{
		int x = (p - 1) / 2;
		if (x <= ceil(double(l) / 3))
			gap = x;
		else break;
		p = p * 3;
	}
	p /= 3;
	auto start = chrono::steady_clock::now();	//start measuring time
	while (gap > 0)
	{
		insertionSortParam(v, gap, op);
		p = p / 3;
		gap = (p - 1) / 2;
	}
	auto end = chrono::steady_clock::now();	//stop measuring time
	if (k)
	{
		cout << "ShellSort - Time:" << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds";
		cout << " - Comparisons: " << op.first << " - Swapped elements: " << op.second << endl;
		out << v.size() << ";" << nr << ";Shell;" << chrono::duration_cast<chrono::microseconds>(end - start).count() << ";" << op.first << ";" << op.second << endl;
	}
	else
		cout << "Comparisons: " << op.first << " - Swapped elements: " << op.second << endl << endl;
}
//-------------------------------------------------------------------------------------------------
//QuickSort
vector <int> p;
void quick(vector <int>& v, int left, int right, bool& k, pair <int, int>& op)
{
	int i = left;
	int j = right;
	int x = v[right];
	if (!k)
		p.push_back(x);
	do
	{
		while (v[i] > x)
		{
			op.first++;
			i++;
		}

		while (v[j] < x)
		{
			op.first++;
			j--;
		}

		if (i <= j)
		{
			swap(v[i], v[j]);
			op.second++;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) 
		quick(v, left, j, k, op);

	if (right > i) 
		quick(v, i, right, k, op);
}



void quickSort(vector <int> v, bool k, int& nr)
{
	if (!k)
	{
		cout << "ShellSort" << endl;
		if (v.size() == 10)
			cout << "Wartosc przyrostu: 4" << endl;
		cout << "Wartosc przyrostu : 1" << endl;
	}
	pair <int, int> op = { 0,0 };
	auto start = chrono::steady_clock::now();	//start measuring time
	quick(v, 0, v.size() - 1, k, op);
	auto end = chrono::steady_clock::now();		//stop measuring time
	if (k)
	{
		cout << "QuickSort - Time:" << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds";
		cout << " - Comparisons: " << op.first << " - Swapped elements: " << op.second << endl;
		out << v.size() << ";" << nr << ";Quick;" << chrono::duration_cast<chrono::microseconds>(end - start).count() << ";" << op.first << ";" << op.second << endl;
	}
	else
	{
		cout << "QuickSort" << endl;
		cout << "Pivot values: ";
		for (int i = 0; i < p.size(); i++)
			cout << p[i] << " ";
		cout << "\nComparisons: " << op.first << " - Swapped elements: " << op.second << endl << endl;

		cout << "Sorted sequence: ";
		print(v);
		p.clear();
	}
}
