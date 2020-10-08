#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //a, b, c and 10 <= a, b, c <= 99

    for(ll a = 10; a <= 99; ++a) {
        for(ll b = 10; b <= 99; ++b) {
            for(ll c = 10; c <= 99; ++c) {
                if(a * a * a + 3 * b * b * b + 9 * c * c * c == 9 * a * b * c + 1) {
                    cout << a << ' ' << b << ' ' << c << '\n';
                    return 0;
                }
            }
        }
    }
}