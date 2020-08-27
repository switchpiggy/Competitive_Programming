#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
#define maxn 100100
int s, b;
long long a[maxn];
struct node{
	long long d; 
	long long g;
} base[maxn];
struct ship {
	long long atk;
	long long num;
	long long ans;
}sh[maxn];
bool cmp1(node a, node b) {
	return a.d < b.d;
}
bool cmp2(ship a, ship b) {
	return a.atk < b.atk;
}
bool cmp3(ship a, ship b) {
	return a.num < b.num;
}
int main() {
	cin >> s >> b;
	for (int i = 1; i <= s; i++)
	{
		cin >> sh[i].atk;
		sh[i].num = i;
	}
	sort(sh + 1, sh + 1 + s, cmp2);
	for (int i = 1; i <= b; i++)
		cin >> base[i].d >> base[i].g;
	sort(base + 1, base + b + 1, cmp1);
	int temp=1;
	for (int i = 1; i <= s; i++)
	{
		sh[i].ans = sh[i - 1].ans;
		while (sh[i].atk >= base[temp].d && temp <= b)
		{
			sh[i].ans += base[temp].g;
			temp++;
		}
	}
	sort(sh + 1, sh + 1 + s, cmp3);
	for (int i = 1; i < s; i++)
		cout << sh[i].ans << " ";
	cout << sh[s].ans << endl;
	return 0;
}