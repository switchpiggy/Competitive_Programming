// Maximum submatrix of the same letter in a letter matrix.
//Histogram solution. O(K*N(M + M)). K is 26. 
//Osman Ay. May 2020.

#include<iostream> 
#include <vector>
#include<stack> 
#include <algorithm>
#include <string>

using namespace std;

int N, M;
vector<string> matrix;
vector<int> bars;
//------------------------------------------
void readInput()
{
	cin >> N >> M;
	matrix.resize(N);
	for (int i = 0; i < N; i++)
		cin >> matrix[i];
}
//------------------------------------------
//Largest area under the histogram
int go()
{
	//s stores indices of bars in non-decreasing order 
	stack<int> s;

	int tempRes, res = 0;

	// Proceeds bars one by one
	int i = 0;
	while (i < M)
	{
		// current bar is not smaller than the last added bar in stask 
		if (s.empty() || bars[s.top()] <= bars[i])
		{
			s.push(i);
			i++;
			continue;
		}

		//current bar is smaller. Pop the bars in the stack
		//and calculate are for the poped bar until the current 
		//bar is not shorter than the popped bar.

		int sTop = s.top();  //index of top element 
		s.pop();

		if (s.empty())
			tempRes = bars[sTop] * i;
		else
			tempRes = bars[sTop] * (i - s.top() - 1);

		res = max(res, tempRes);
	}

	// Keep popping the remaining bars from the stack and calculate 
	// area for each popped bar. 
	while (!s.empty())
	{
		int sTop = s.top();
		s.pop();
		if (s.empty())
			tempRes = bars[sTop] * i;
		else
			tempRes = bars[sTop] * (i - s.top() - 1);

		res = max(res, tempRes);
	}
	return res;
}
//------------------------------------------
int main()
{
	readInput();
	int res = 0;

	for (char ch = 'a'; ch <= 'z'; ch++)
	{

		bars.resize(M, 0);

		for (int i = 0; i < N; i++)
		{
			for (int j=0; j<M; j++)
			{
				char letter = matrix[i][j];

				if (letter != ch)
					bars[j] = 0;
				else
					bars[j]++;
			}
			res = max(res, go());
		}
	}
	cout << res << endl;
}