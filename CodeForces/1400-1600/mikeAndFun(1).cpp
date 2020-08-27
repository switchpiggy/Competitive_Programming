#include <iostream>
using namespace std;
const int MAX = 505;
int a[MAX][MAX], res[MAX];
int n, m, q;
void calc(int i)
{
	res[i] = 0;
	int cnt = 0;
	for (int j = 0; j <= m; j++)
		if (a[i][j])
			cnt++;
		else
		{
			res[i] = max(res[i], cnt);
			cnt = 0;
		}
}
int main()
{
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
		calc(i);
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] ^= 1;
		calc(x - 1);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, res[i]);
		cout << ans << endl;
	}
	return 0;
}