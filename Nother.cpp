#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <chrono>
using namespace std;
#ifdef LOCAL_PROJECT
#include "debug.hpp"
#else
#define dbg(...)
#endif

typedef long long ll;
int main() {
#ifdef LOCAL_PROJECT
    auto begin = std::chrono::high_resolution_clock::now();
#endif
    
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

ll H, M, A; cin >> H >> M >> A;
ll ans = 0;
for(int i = 0; i < H - 1; i++){
    ans += 2+ (A + H*M*i)/(H - 1) - (H*M*i + H - 2)/(H - 1) + (H*M*(i+1))/(H-1) - (H*M - A + H*M*i + H-2)/(H - 1);
    // ans += 2+(A + M*i)/(H - 1) - (M*i + H - 2)/(H - 1) + (M*(i+1))/(H-1) - (M - A + M*i + H-2)/(H - 1);
    // ans += (i + 7)/2 + (i+ 5)/3 + (i+ 3)/4 + (i+4)/5 + i/6 + i/7 + i/8 + i/9;
}
if(H*M % 2 == 0) ans -= (A == H*M/2);
ans--;
cout << ans << endl;



#ifdef LOCAL_PROJECT
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}