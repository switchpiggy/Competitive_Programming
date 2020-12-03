#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    ll cur = 1, sum = 0, sum2 = 0, cur2 = 2, cnt = 0, cnt2 = 0;
    while(sum + cur <= a) {
        sum += cur;
        cnt++;
        cur += 2;
    }

    while(sum2 + cur2 <= b) {
        sum2 += cur2;
        cnt2++;
        cur2 += 2;
    }

    if(cnt <= cnt2) cout << "Vladik\n";
    else cout << "Valera\n";
}