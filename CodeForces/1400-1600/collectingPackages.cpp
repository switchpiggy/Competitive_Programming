#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%d", &n);

int main() {

    int t;

    s(t);

    while(t--) {

        int n;

        string s;

        bool flag = false;

        s(n);
        
        vector<pair<int, int>> vect(n);

        for(int i = 0; i < n; ++i) {

            int a, b;

            s(a);

            s(b);

            vect[i] = make_pair(a, b);

        }

        sort(vect.begin(), vect.end());

        pair<int, int> prev = make_pair(0, 0);

        for(int i = 0; i < n; ++i) {

            int x = vect[i].first - prev.first;

            int y = vect[i].second - prev.second;

            if(x < 0 || y < 0) {

                printf("NO\n");

                flag = true;
                
                break;

            }

            s += string(x, 'R');

            s += string(y, 'U');

            prev = vect[i];

        }

        if(!flag) cout << "YES" << endl << s << endl;

        

    }



}