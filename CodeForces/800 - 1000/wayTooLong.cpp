#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    int numCases;

    scanf("%d", &numCases);

    while(numCases--) {

        cin >> s;

        if(s.length() > 10) printf("%c%d%c\n", s[0], s.length() - 2, s[s.length() - 1]);

        else cout << s << endl;

    }

    return 0;

}