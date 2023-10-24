#pragma once
#include "Libraries.h"
using namespace std;
extern ofstream out;
extern void print(std::vector <int>& v);
//MergeSort
void merging(vector <int>& v, int left, int pivot, int right, pair <int, int>& op);
void merge(vector <int>& v, int left, int right, pair <int, int>& op);
void mergeSort(vector <int> v, bool k, int& nr);
//HeapSort
void insert_vertex(vector <int>& data, int& heap_range, pair <int, int>& op);
void remove_root(vector <int>& data, int& heap_range, pair <int, int>& op);
void heapSort(vector <int> v, bool k, int& nr);
//InsertionSort
void insertionSort(vector <int> v, bool k, int& nr);
//ShellSort
void insertionSortParam(vector <int>& v, int p, pair<int, int>& op);
void shellSort(vector <int> v, bool k, int& nr);
//QuickSort
void quick(vector <int>& v, int left, int right, bool& k, pair <int, int>& op);
void quickSort(vector <int> v, bool k, int& nr);