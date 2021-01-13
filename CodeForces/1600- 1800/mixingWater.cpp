#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll T;
int h, c, t; //eps = 0.00000000001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> h >> c >> t;
        if(h + c - 2 * t >= 0) {
            cout << "2\n";
            continue;
        }
        int a = h - t;
        int b = 2 * t - c - h;
		int k = 2 * (a / b) + 1;
		long long val1 = abs(k / 2 * 1ll * c + (k + 1) / 2 * 1ll * h - t * 1ll * k);
		long long val2 = abs((k + 2) / 2 * 1ll * c + (k + 3) / 2 * 1ll * h - t * 1ll * (k + 2));
		cout << (val1 * (k + 2) <= val2 * k ? k : k + 2) << '\n';
    }

    //cout << check(5) << ' ' << check(7) << '\n';

    return 0;
}