#include <bits/stdc++.h>

using namespace std;

#define s(n) scanf("%lld", &n);

bool comp(pair<int, int> x, pair<int, int>y) {

    return x.second < y.second;

}

int main() {

    long long int n, r, avg;

    vector<pair<long long int, long long int>> v;

    s(n);

    s(r);

    s(avg);

    long long int sum = n * avg;

    long long int s = 0;

    long long int numEssays = 0;

    for(int i = 0; i < n; ++i) {

        long long int c, d;

        s(c);

        s(d);

        v.push_back(make_pair(r - c, d));

        s += c;

    }

    sort(v.begin(), v.end(), comp);

    auto itr = v.begin();

    while(s < sum) {

        int i = min(sum - s, itr->first);

        numEssays += i * itr->second;

        s += i;

        itr++;

    }

    printf("%lld", numEssays);



}