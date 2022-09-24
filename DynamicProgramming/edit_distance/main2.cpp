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
int edit_distance(string a, string b) {
    int l1 = a.length();
    int l2 = b.length();
    vector<vector<int>> v(l1+1, vector<int>(l2+1, max(l1, l2)));

    for (int i = 0; i <= l1; i++) {
        v[i][0] = i;
    }

    for (int j = 0; j <= l2; j++) {
        v[0][j] = j;
    }

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            int operation = INT_MAX;

            //Remove letter
            operation  = min(operation, v[i-1][j]+1);

            //Replace letter
            operation = min(operation, v[i-1][j-1]+1);

            //Insert letter
            operation = min(operation, v[i][j-1]+1);

            //No operation
            if (a[i-1] == b[j-1]) {
                operation = min(operation, v[i-1][j-1]);
            }
            
            v[i][j] = min(operation, v[i][j]);
        }
    }

    // for (int i = 0; i <= a.length(); i++) {
    //     for (int j = 0; j <= b.length(); j++) {
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return v[l1][l2];

}

int main()
{
    fast_cin();

    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    #endif
    string a, b;
    cin>>a>>b;
    // cout<<a<<" "<<b;

    cout<<edit_distance(a,b);

    return 0;
}