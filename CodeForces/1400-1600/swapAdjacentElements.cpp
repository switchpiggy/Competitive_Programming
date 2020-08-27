#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200020;
 
char s[N];
 
int n, val[N], sum[N];
 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++ ) {
		scanf("%d", &val[i]);
		val[i] -- ;
	}
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 0; i < n; i ++ ) {
		if (i > 0) {
			sum[i] = sum[i - 1] + s[i] - '0';
		}
	}
	// for (int i = 0; i < n; i ++ ) {
	// 	cout << sum[i] << endl;
	// }
	for (int i = 0; i < n; i ++ ) {
		if (abs(val[i] - i) > abs(sum[val[i]] - sum[i])) {
			printf("NO\n");
			// cout << i << endl;
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}