#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
  
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template<typename S, typename T>
using hash_table = gp_hash_table<S, T, custom_hash>;
// Usage: hashtable<int, int> for map<int, int> basically
// replacement for unordered_set<K>, use gp_hash_table<K, null_type>
// Note: the operator needs to be able to hash the typename S


// untested but could be used for pairs 
// the hashes need to be non symmetric ((a, b) and (b, a) should give diff hash)
// eg: splitmix64(x.first ^ splitmix64(x.second) ^ FIXED_RANDOM) works
// but splitmix64(x.first ^ x.second ^ FIXED_RANDOM) doesnt since (1, 2) and (2, 1) give same hash

// maybe this for pairs

// size_t operator()(pair<uint64_t, uint64_t> x) const {
// static const uint64_t FIXED_RANDOM =
//     chrono::steady_clock::now().time_since_epoch().count();
//     return splitmix64(x.first ^ splitmix64(x.second) ^ FIXED_RANDOM);
// }

//maybe this for strings

// size_t operator()(string x) const {
//   static const uint64_t FIXED_RANDOM =
//       chrono::steady_clock::now().time_since_epoch().count();
//   uint64_t hash = 0;
//   for (char c : x){
//       hash = splitmix64(hash ^ (c + 1) ^ FIXED_RANDOM);
//   }
//   return hash; 
// }