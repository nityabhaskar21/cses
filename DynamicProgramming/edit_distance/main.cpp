#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
int MOD_INT = 1e9+7;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

int main()
{
    fast_cin();

    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> t (s1.size()+1, vector<int>(s2.size()+1, -1));

    for (int i=0; i<=s1.size(); i++) {
        for (int j=0; j<=s2.size(); j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1.at(i-1) == s2.at(j-1)) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    //  for (int i = 1; i <= s1.size(); i++) {
    //     for (int j = 1; j <= s2.size(); j++) {
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int short_length = min(s1.size(), s2.size());
    int long_length = max(s1.size(), s2.size());

    int answer = 0;

    answer = (long_length - short_length) + (short_length - t[s1.size()][s2.size()]);
    cout<<answer;

    return 0;
}