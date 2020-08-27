#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    string c;

    string t;

    cin >> s >> c >> t;

    bool flag = false;

    for(int i = 0; i < s.length(); ++i) {

        if(t.find(s[i]) != string::npos) {

            t.erase(t.find(s[i]), 1);

        } else flag = true;

    }

    for(int i = 0; i < c.length(); ++i) {

        if(t.find(c[i]) != string::npos) {

            t.erase(t.find(c[i]), 1);

        } else flag = true;

    }

    if(t != "") flag = true;

    if(flag) printf("NO");

    else printf("YES");

}