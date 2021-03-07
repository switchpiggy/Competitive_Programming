#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll d, s, t;

int main() {
    cin >> d >> t >> s;

    if(d <= t * s) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}