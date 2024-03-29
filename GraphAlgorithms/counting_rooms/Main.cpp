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

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

//ACCEPTED

void floodfill(vector<vector<char>> &t, vector<vector<int>> &visited, int i, int j) {
    visited[i][j] = 1;

    int x = t.size();
    int y = t[0].size();

    for (int idx = 0; idx < 4; idx++) {
        int xx = i + dx[idx];
        int yy = j + dy[idx];
        if (xx>=0 && xx < x && yy >=0 && yy < y && !visited[xx][yy] && t[xx][yy] == '.') {
            floodfill(t, visited, xx, yy);
        }
    }
}

int main()
{
    fast_cin();

    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;
    vector<vector<char>> t(n, vector<char>(m , ' '));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>t[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    

    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout<<t[i][j]<<" ";
            if (!visited[i][j] && t[i][j]=='.') {
                rooms++;
                floodfill(t, visited, i, j);
            }
        }
        // cout<<endl;
    }
    // cout<<endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<rooms;

    return 0;
}