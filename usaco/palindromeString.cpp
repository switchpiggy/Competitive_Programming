#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

void no() {
    printf("NO\n");
    exit(0);
}

int main() {
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    for(ll i = 0; i < (ll)s.length()/2; ++i) {
        if(tolower(s[i]) != tolower(s[(ll)s.length() - i - 1])) no();
    }

    printf("YES\n");

    return 0;
}