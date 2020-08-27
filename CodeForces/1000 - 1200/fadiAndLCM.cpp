#include <bits/stdc++.h>

using namespace std;

long long int lcm(long long int x, long long int y) {

    return x * y / __gcd(x, y);

}

int main() {

    long long int x, ans;

    cin >> x;

    for(long long int i = 1; i * i <= x; ++i) {

        if(x%i == 0 && lcm(i, x/i) == x) ans = i;

    }

    printf("%lld %lld", ans, x/ans);



}