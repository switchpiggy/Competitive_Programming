#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c;

int main() {
    cin >> a >> b >> c;
    
    if(c - b - a > 0 && a * b * 4 < (c - b - a) * (c - b - a)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}