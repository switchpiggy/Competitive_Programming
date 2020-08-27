#include<bits/stdc++.h>

using namespace std;

int a, b, maxa;

void use_battery(int s)
{
	if(s == 1) a = min(a + 1, maxa);
	--b;	
}

void use_accum()
{
	--a;
}

int main()
{
	int ans = 0;
	int n;
	cin >> n >> b >> a;
	maxa = a;
	vector<int> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++)
	{
		if(a == 0 && b == 0)
			break;
		else if(a == 0)
			use_battery(s[i]);
		else if(b == 0)
			use_accum();
		else if(s[i] == 1 && a < maxa)
			use_battery(s[i]);
		else use_accum();
		ans++;
	}
	cout << ans << endl;
}