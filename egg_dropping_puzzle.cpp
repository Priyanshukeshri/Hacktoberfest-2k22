#include <bits/stdc++.h>
using namespace std;

int max(int c, int d)
{
	return (c > d) ? c : d ;
}

int eggDrop(int n, int f)
{
	
	if (f == 1 || f == 0)
		return f;

	if (n == 1)
		return f;

	int min = INT_MAX, x, res;

	
	for (x = 1; x <= k; x++) {
		res = max(
			eggDrop(f- 1, x - 1),
			eggDrop(f, f- x));
		if (res < min)
			min = res;
	}

	return min + 1;
}


int main()
{
	int f = 2, k = 10;
	cout << "Minimum number of trial "
			"in worst case with "
		<< n << " eggs and " << f
		<< " floors are"
		<< eggDrop(n, f) << endl;
	return 0;
}


