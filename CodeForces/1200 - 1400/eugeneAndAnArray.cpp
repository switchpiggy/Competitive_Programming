#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn];
ll sum[maxn];
map<ll, int>pos;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 0;
	int maxl = 1;
	for (int i = 0; i <= n; i++) {
		if (pos.count(sum[i])) {
			maxl = max(pos[sum[i]] + 2,maxl);
		}
		ans += i - maxl + 1;
		pos[sum[i]] = i;
	}
	printf("%lld\n", ans);
}