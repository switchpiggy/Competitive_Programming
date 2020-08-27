#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
	int n, d, a, b;
	cin >> n >> d >> a >> b;
	int c1, c2;
	vector <pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		cin >> c1 >> c2;
		v.push_back({ a * c1 + b * c2, i });
	}
	sort(v.begin(), v.end());
	int i = 0;
	vector <int> rez;
	while (i < v.size() && d >= v[i].first) {
		d -= v[i].first;
		rez.push_back(v[i].second);
		i++;
	}
	cout << i << '\n';
	for (auto o : rez)
		cout << o << ' ';
	return 0;
}