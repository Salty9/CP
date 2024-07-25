#include <bits/stdc++.h>
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
#define vin(a) for(auto& x: a) cin >> x;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> bool ckmin(T& a, T b){ return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, T b){ return b > a ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}

// ostream &operator<<(ostream &os,const ll &v) {
//     if(v==0) return (os<<"0");
//     ll num=v;
//     if(v<0) os<<'-',num=-num;
//     string s;
//     for(;num>0;num/=10) s.pb((char)(num%10)+'0');
//     reverse(all(s));
//     return (os<<s);
// }

long long gcd(ll x, ll y){
    return gcd((long long) x, (long long) y);
}

struct Q{
    ll n, d;
    Q(ll x, ll y){
        // if(y == 0) assert(false);
        n = x/gcd(x, y);
        d = y/gcd(x, y);
    }
};

Q operator*(Q x, ll y){
    return Q(x.n * y, x.d);
}
Q operator+(Q x, Q y){
    ll lcm = (x.d/gcd(x.d, y.d))*y.d;
    return Q((lcm/x.d)*x.n + (lcm/y.d)*y.n, lcm);
}
ll floor(Q x){
    return x.n/x.d;
}
ll ceil(Q x){
    return (x.n + x.d - 1)/x.d;
}

ll floor(ll x, ll y){
    return x/y;
}
ll ceil(ll x, ll y){
    return (x + y - 1)/y;
}
// ostream& operator<<(ostream& out, Q x){
//     out << double(x.n)/double(x.d);
//     // out << x.n << "/" << x.d << endl;
//     return out;
// }
void solve(int tc = 0) {
    ll H, M, A; cin >> H >> M >> A;
    // ans could be in the order 10^18 if all variables maximum
    // mod never changes the fractional part
    // t change does change the fractional part
    // arbitrarily many residues ?? yes
    // issue is i was assuming after reset @ t = 0 the actual time they meet could be fractiona

    // Q T(H*M, H - 1);
    // ld T = double(H*M)/(H-1);
    // Q T(H*M, H - 1);
    
    // ld T_alpha = (1.0*A)/(H-1); // time to gain alpha angular distance
    // Q T_alpha(A, H - 1);
    // ld T_alpha = alpha/v;
    // ld T_other = (360 - alpha)/v; 
    // ld T_other = double(M*H - A)/(H - 1);
    // Q T_other(M*H - A, H - 1);
    // dbg(T_alpha, T_other);
    ll ans = 0;
    for(int i = 0; i < H - 1; i++){
        // dbg(T*i, T_alpha, T*(i+1), T_other);
        // dbg(T, i, T*i);
        // Q a = T*i;
        // Q b = T*i + T_alpha;
        // Q c = T*i + T_other;
        // Q d = T*(i+1);
        // dbg(a, b, c, d);
        // ans += (floor(T_alpha + T*i) - ceil(T*i) + 1) + (floor(T*(i+1)) - ceil(T_other + T*i) + 1);
        ans += 2+floor(A + H*M*i, H - 1) - ceil(H*M*i, H - 1) + floor(H*M*(i+1), H-1) - ceil(H*M - A + H*M*i, H - 1);
    }
    if(H*M % 2 == 0) ans -= (A == H*M/2);
    ans--;
    cout << ans << endl;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
solve();
}