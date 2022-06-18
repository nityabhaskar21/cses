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

// ACCEPTED
 
int main()
{
    fast_cin();

    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    int n = 0;
    cin >> n;

    v64 input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    vector<vector<ll>> t(n, vector<ll>(n, 0));

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                continue;
             }
            else if (i == j) {
                t[i][j] = input[i];
            }
            
            else if (j-i==1) {
                t[i][j] = max(input[i], input[j]);
            }

            else {
                t[i][j] = max(input[i] + min(t[i+1][j-1], t[i+2][j]), input[j] + min(t[i][j-2], t[i+1][j-1]));
            }
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    // cout<<t[0][n-1];

    

    return 0;
}