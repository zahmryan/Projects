#ifndef _VERIFYSORT_H_
#define _VERIFYSORT_H_
#include <vector>
using namespace std;

//your verify sort here
bool verifySort(vector<int> v){
	int length = v.size();
	for (int i = 1; i < length; i++)
	{
		if (v[i - 1] > v[i])
		{
			return false;
		}
	}
	return true;
}

#endif
