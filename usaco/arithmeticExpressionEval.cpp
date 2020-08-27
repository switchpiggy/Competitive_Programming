#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
stack<ll> operators, ints;

ll pemdas(char o) {
    if(o == '+' || o == '-') return 1;
    if(o == '*' || o == '/') return 2;
    return 0;
}

int main() {
    getline(cin, s);
    //cout << s << endl;

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == ' ' || i >= (ll)s.length()) continue;
        else if(isdigit(s[i])) {
            ll num = 0;
            while(i < (ll)s.length() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            ints.push(num);
        } else if(s[i] == '(') operators.push('(');
        else if(s[i] == ')') {
            while(!operators.empty() && operators.top() != '(') {
                ll u = ints.top();
                ints.pop();

                ll v = ints.top();
                ints.pop();

                ll op = operators.top();
                operators.pop();

                if(op == '+') ints.push(u + v);
                else if(op == '-') ints.push(v-u);
                else if(op == '*') ints.push(u * v);
                else if(op == '/') ints.push(v/u);
            }
            if(!operators.empty()) operators.pop();
        } else {
            while(pemdas(operators.top()) >= pemdas(s[i]) && !operators.empty()) {
                ll u = ints.top();
                ints.pop();

                ll v = ints.top();
                ints.pop();

                ll op = operators.top();
                operators.pop();

                if(op == '+') ints.push(u + v);
                else if(op == '-') ints.push(v - u);
                else if(op == '/') ints.push(v/u);
                else if(op == '*') ints.push(u * v);
            }
        }
    }

    while(!operators.empty()) {
        ll u = ints.top();
        ints.pop();

        ll v = ints.top();
        ints.pop();

        ll op = operators.top();
        operators.pop();

        if(op == '+') ints.push(u + v);
        else if(op == '-') ints.push(v-u);
        else if(op == '/') ints.push(v/u);
        else if(op == '*') ints.push(u * v);
    }

    printf("%lld\n", ints.top());
}