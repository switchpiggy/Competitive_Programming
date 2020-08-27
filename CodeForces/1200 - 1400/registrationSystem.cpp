#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

//NOTE: std::to_string(int) turns an int into a string
//Use hashing for O(1) instant access

ll n;
map<string, ll> names;
string x;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        cin >> x;

        if(names[x] == 0) printf("OK\n");
        else {
            string c = to_string(names[x]);
            cout << x << c << endl;
        }
        names[x]++;
    }
}
