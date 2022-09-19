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
int change(int amount, vector<int>& coins) {
    int coinSize = coins.size();
    vector<vector<int>> v(coinSize+1, vector<int>(amount+1, 0));
    
    for (int i = 0; i <=coinSize; i++) {
        for (int j = 0; j<=amount; j++) {
            if (j==0) {
                v[i][j] = 1;
            }
        }
    }
    
    for (int i = 1; i <=coinSize; i++) {
        for (int j = 1; j<=amount; j++) {
            if (coins[i-1] <= j) {
                v[i][j] = (v[i-1][j] + v[i][j-coins[i-1]]) % MOD_INT;
            } else {
                v[i][j] = v[i-1][j];
            }
        }
    }
    
    return v[coinSize][amount] ;
}

int main()
{
    fast_cin();

    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    #endif
    int n;
    int x;
    cin>> n >> x;

    vector<int> coins(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout<< change(x, coins);

    return 0;
}