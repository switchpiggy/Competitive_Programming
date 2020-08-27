#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> x, pair<int, int> y) {

    return x.second < y.second;

}

int main() {
    int n;

    vector<pair<int, int>> v;

    long long int res = 0;

    cin >> n;

    for(int i = 0; i < n; ++i) {

        int a, b;

        cin >> a >> b;

        v.push_back(make_pair(a, b));

    }

    sort(v.begin(), v.end(), comp);

    vector<pair<int, int>> u(v);

    sort(u.begin(), u.end());

    for(auto i = v.begin(); i != v.end(); ++i) {

        for(auto j = i + 1; j != v.end(); ++j) {

            if(i->second == j->second) {

                for(auto k = u.begin(); k != u.end(); ++k) {

                    if(k != j && k != i)
                        if((k->first == i->first || k->first == j->first)) res += abs(i->first - j->first) * abs(k->second - i->second);

                }

            }

            if(j->second > i->second) break;

        }

    }

    cout << res%1000000007;

    return 0;

}