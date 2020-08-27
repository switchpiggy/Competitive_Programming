//Tip: to speed things up, try using prefix sums or partial sums in an array to perform faster calculations
//Instead of the initial brute force algorithm we used, we could've precalculated everything into a prefix sum array, making things much faster
//First, we calculate, for each index i from 0 to n - m + 1, if t occurred starting from that index. If so, we add it to the prefix sum array at index i.
//We do this by calculating if each char from i to i + m in s is equal to every char from 0 to m in t.
// Next, we can update all the sum[] from s[n - m + 1] to s[n] to s[n - m], since the string t wouldn't be able to fit into s beyond that point.
// Lastly, we can calculate the queries in O(1) time by calculating the number of valid substrings using prefix sums.


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, q, a, b;
string s, t;
ll sum[1005];
bool f[1005];

int main() {
    scanf("%lld %lld %lld", &n, &m, &q);
    cin >> s >> t;

    sum[0] = 0;

    for(ll i = 0; i < n - m + 1; ++i) {
        bool flag = false;

        for(ll j = 0; j < m; ++j) {
            if(s[i + j] != t[j]) flag = true;
        }

        f[i] = !flag;
        sum[i + 1] = sum[i] + f[i];
    }

    for(ll i = max(0ll, n - m + 1); i < n; ++i) {
        sum[i + 1] = sum[i];
    }

    for(ll i = 0; i < q; ++i) {
        scanf("%lld %lld", &a, &b);
        a--;
        b -= m - 1;
        if(b >= a) printf("%lld\n", sum[b] - sum[a]);
        else printf("0\n");
    }

    return 0;
}