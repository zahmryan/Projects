#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
#include <vector>
#include <random>
#include "InsertionSort.h"
using namespace std;

//Main Quicksort Function
long long quickSort(vector<int>& v, int left = 0, int right = 0){
	int count = 0;
	int a = left;
	if (right == 0){
		right = v.size();
	}
	int b = right;
	count += ((right - left) - 1);
	int pivot = v[left];

	while (a <= b) 
	{
		while (v[a] < pivot)
		{
			a++;
		}
		while (v[b] > pivot)
		{
			b--;
		}
		if (a <= b)
		{
			int temp = v[a];
			v[a] = v[b];
			v[b] = temp;
			a++;
			b--;
		}
	}

	if (left < b) 
	{
		count += quickSort(v, left, b);
	}
	if (a < right)
	{
		count += quickSort(v, a, right);
	}
	return count;
}

#endif

