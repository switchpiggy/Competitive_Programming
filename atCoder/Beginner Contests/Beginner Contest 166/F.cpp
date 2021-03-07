#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, c;
string s;

void no() {
    cout << "No" << endl;
    exit(0);
}

vector<char> ans;

int main() {
    cin >> n >> a >> b >> c;

    if(a + b + c == 0) no();
    else if(a + b + c == 1) {
        char cur;
        if(a) cur = 'A';
        else if(b) cur = 'B';
        else cur = 'C';
        while(n--) {
            ans.push_back(cur);
            cin >> s;
            if(s == "AB") {
                if(cur == 'C') no();
                if(cur == 'A') cur = 'B';
                if(cur == 'B') cur = 'A';
            } else if(s == "AC") {
                if(cur == 'B') no();
                if(cur == 'A') cur = 'C';
                if(cur == 'C') cur = 'A';
            } else {
                if(cur == 'A') no();
                if(cur == 'B') cur = 'C';
                if(cur == 'C') cur = 'B';
            }
        }

        cout << "Yes" << endl;
        for(ll i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    } else {
        cin >> s;
        if(s == "AB" && !a && !b) no();
        if(s == "BC" && !b && !c) no();
        if(s == "AC" && !a && !c) no();

        cout << "Yes" << endl;
        for(ll i = 0; i < ans.size(); ++i) 
    }

    return 0;
}