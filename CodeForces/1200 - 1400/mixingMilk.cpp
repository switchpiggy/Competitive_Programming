/*
ID: alanxia1
PROG: milk
LANG: C++
*/



#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int>x, pair<int, int> y) {

    return x.first < y.first;

}

int main() {

    ifstream fin;

    ofstream fout;

    fin.open("milk.in");

    fout.open("milk.out");

    int n, m;

    vector<pair<int, int>> milk;

    fin >> n >> m;

    for(int i = 0; i < m; ++i) {

        int a, b;

        fin >> a >> b;

        milk.push_back(make_pair(a, b));

    }

    fin.close();

    sort(milk.begin(), milk.end(), comp);

    int total = 0;

    auto i = milk.begin();

    int cost = 0;

    while(total < n && i != milk.end()) {

        int t = min(n - total, i->second);

        total += t;

        cost += i->first * t;

        ++i;

    }

    fout << cost << endl;

    fout.close();

    return 0;

}