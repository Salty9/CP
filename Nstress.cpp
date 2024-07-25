#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <chrono>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll H, M, A; cin >> H >> M >> A;
    ll ans = 0;
    for(int i = 0; i < H - 1; i++){
        ans += 2+ (A + H*M*i)/(H - 1) - (H*M*i + H - 2)/(H - 1) + (H*M*(i+1))/(H-1) - (H*M - A + H*M*i + H-2)/(H - 1);
    }
    if(H*M % 2 == 0) ans -= (A == H*M/2);
    ans--;
    cout << ans << endl;
}