
#include<bits/stdc++.h>
using namespace std;

int main()
{

	int arr[] = {10, 20, 5, 23 ,42 , 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n);

	cout << "Vector is:\n";
	for (int i=0; i<n; i++)
		cout << vect[i] << " ";


	sort(vect.begin(), vect.end());


	cout << "Vector after sorting is: \n";
	for (int i=0; i<n; i++)
	cout << vect[i] << " ";



	sort(vect.begin(),vect.end(), greater<int>());

	cout << "Vector after sorting in Descending order is: \n";
	for (int i=0; i<n; i++)
	cout << vect[i] << " ";



	reverse(vect.begin(), vect.end());

	cout << "Vector after reversing is: \n";
	for (int i=0; i<n; i++)
		cout << vect[i] << " ";

	cout << "Maximum element of vector is: \n";
	cout << *max_element(vect.begin(), vect.end());

	cout << "Minimum element of vector is: \n";
	cout << *min_element(vect.begin(), vect.end());

	cout << "The summation of vector elements is: \n";
	cout << accumulate(vect.begin(), vect.end(), 0);

	return 0;
}
