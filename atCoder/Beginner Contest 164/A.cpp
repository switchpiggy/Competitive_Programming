#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll s, w;

int main() {
    cin >> s >> w;
    if(w >= s) cout << "unsafe" << endl;
    else cout << "safe" << endl;

    return 0;
}