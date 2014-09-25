#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_
#include <vector>
using namespace std;

// insertion sort here
long long insertionSort(vector<int>& v){
	int length = v.size();
	int i; 
	long long count = 0;
	for (i = 1; i < length; i++)
	{
		int x = i;
		while (x > 0 && (v[x - 1] > v[x]))
		{
			int temp = v[x];
			v[x] = v[x - 1];
			v[x - 1] = temp;
			count++;
			x--;
		}
	}
	return count;
}

#endif
