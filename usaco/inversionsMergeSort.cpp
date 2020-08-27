// Counting inversions. Modified Merge Sort. O(NlgN).
//Osman Ay. July 2020.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

vector<int> X;
long long N, result;
//------------------------------------------
//Merge two sorted parts of X
void merge(int left, int right)
{
	vector<int> temp;
	int middle = (left + right) / 2;
	int i = left, j = middle + 1;	
	while (i <= middle && j <= right)
	{
		if (X[i] <= X[j])
		{
			temp.push_back(X[i]);
			i++;
		}
		else
		{
			result += middle - i + 1;	//right element is smaller. One or more inversions.
			result = result % MOD;
			temp.push_back(X[j]);
			j++;
		}
	}

	//Add the remainig parts. Only one of the loops will be executed.
	for (int k = i; k <= middle; k++)
		temp.push_back(X[k]);
	for (int k = j; k <= right; k++)
		temp.push_back(X[k]);

	//Copy the temp vector (combined part) into the original vector
	copy(temp.begin(), temp.end(), X.begin() + left);
}
//------------------------------------------
//Divide and Conquer mechanism.
void mergeSort(int left, int right)
{
	//base case: subproblem is small enough not to break.
	if (left == right)
		return;

	//Break the problem into two subproblems
	int middle = (left + right) / 2;
	mergeSort(left, middle);
	mergeSort(middle + 1, right);

	//Combine the solutions of subproblems
	merge(left, right);
}
//------------------------------------------
int main()
{
	cin >> N;
	X.resize(N);
	for(int &x:X)
		cin >> x;

	mergeSort(0, N - 1);
	
	cout << result << endl;
}

