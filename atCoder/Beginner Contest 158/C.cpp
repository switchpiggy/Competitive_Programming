#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
long double a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    for(long double i = 1; i <= 10000; ++i) {
        if(floor(i * 0.08) == a && floor(i * 0.1) == b)  {
            cout << i << ' ';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}