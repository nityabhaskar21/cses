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

// TLE
int n;

struct project {
    int st; int ed; ll re;
};

bool cmp (project &p1, project &p2) {
    return p1.ed < p2.ed;
}

int findLastIndex(vector<project> &arr, int i) {
    vector<int> endArray;
    for (int j = 0; j < arr.size(); j++) {
        endArray.push_back(arr[j].ed);
    }

    auto it = lower_bound(endArray.begin(), endArray.end(), arr[i].st);
    if (it == endArray.begin()) {
        return 0;
    }
    auto val = ((--it) - endArray.begin())+1;
    return val ;
}

ll solve(vector<project> &arr) {
    ll v[n+1];
    v[0] = 0;

    for (int i = 1; i <= n; i++) {
        ll opt1 = v[i-1];
        ll opt2 = arr[i-1].re;

        // find largest j such that j.ed < i-1.st
        // end day of one task cannot be starting day of any other task.
        int j = findLastIndex(arr, i-1);

        opt2 += v[j];
        v[i] = max(opt1, opt2);
    }
    // for (int i = 0; i <= n; i++) {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    return v[n];
}


int main()
{
    fast_cin();

    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    #endif

    cin >> n;

    vector<project> arr(n);

    for (int i = 0; i < n; i++) {
        cin>>arr[i].st>>arr[i].ed>>arr[i].re;
    }
    sort (arr.begin(), arr.end(), cmp);

    cout<<solve(arr);
    
    return 0;
}