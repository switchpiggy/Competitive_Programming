#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, c, a, b;

int main() {
	scanf("%lld", &n);
    while(n-- && scanf("%lld %lld", &x, &y)) {
        c += max(0ll, min(x, y) - max(a, b) + (a != b));
        a = x;
        b = y;
    }
	printf("%lld\n", c + 1);
}