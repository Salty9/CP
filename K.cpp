#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stack>
using namespace std;

#ifdef LOCAL_PROJECT
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define rrep(i,a,b) for (int i = a; i >= b; i--)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}


void solve() {
    int n, m; cin >> n >> m; 
    cin.ignore(1); // newline after m

    vi prop(m+1, 0); 
    // 0 = unset, 1 = true, - 1 = false;
    vector<vi> pos(m+1);
    vector<vi> IMPS;

    rep(i, 0, m){
        string s;
        getline(cin, s);
        if(s.find("->") != string::npos){
            // implication = [vector, last one is right side, ! = negative sign]
            vi implication;
            string num = "";
            bool negative = false;
            for(char& c: s){
                if(c == ' ' and num.size()){
                    implication.pb(stoi(num));
                    pos[stoi(num)].pb(IMPS.size());
                    num = "";
                }else if(c == '-' || c == '>'){
                    continue;
                }else if(c == '!'){
                    negative = true;
                }else{
                    num += c;
                }
            }
            assert(num.size());
            if(num.size()) implication.pb(stoi(num));
            if(negative) implication.back() *= -1;

            IMPS.pb(implication);
        }else{
            if(s[0] == '!'){
                //flase          
                s.erase(s.begin());
                prop[stoi(s)] = -1;
            }else{
                // true
                prop[stoi(s)] = 1;
            }
        }
    }
    vi TRUES, FALSES;
    rep(i, 1, m+1){
        if(prop[i] == 1) TRUES.pb(i);
        if(prop[i] == -1) FALSES.pb(i);
    }
    while(FALSES.size()){
        int p = FALSES.back(); FALSES.pop_back();
        for(auto )
    }
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}