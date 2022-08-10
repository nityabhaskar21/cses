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

vector<vector<char>> grid;
vector<vector<int>> visited;
vector<vector<int>> path_grid;

bool path_found = false;

int n, m;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int start_i = -1;
int start_j = -1;


int grid_path(int x, int y) {
    visited[x][y] = 1;

    if (path_grid[x][y] != -1) {
        return path_grid[x][y];
    }


    int min_path = INT_MAX ;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy] == 'B') {
            path_found = true;
            visited[xx][yy] = 1;
            path_grid[xx][yy] = 0;
            return path_grid[x][y] = 1;
        }
        if (xx>=0 && yy>=0 && xx<n && yy<m && !visited[xx][yy] && grid[xx][yy]=='.') {
            min_path = min(min_path, 1+grid_path(xx, yy));
        }
    }
 
    return path_grid[x][y] = min_path;
}

int main()
{
    fast_cin();

    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;
    grid.resize(n, vector<char>(m, ' '));
    visited.resize(n, vector<int>(m, 0));
    path_grid.resize(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <m; j++) {
            cin>>grid[i][j];
        }
    }

    int min_path;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <m; j++) {
            if (grid[i][j] == 'A') {
                start_i = i;
                start_j = j;
                min_path = grid_path(i, j);
            }
        }
    }
    // cout<<endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <m; j++) {
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <m; j++) {
    //         cout<<path_grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <m; j++) {
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if (path_found == false) {
        cout<<endl<<"NO";
    } else {
        string path = "";
        int temp_path = path_grid[start_i][start_j];
        int x = start_i;
        int y = start_j;
        do {
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (grid[x][y]=='B') break;
                if (xx>=0 && yy>=0 && xx<n && yy<m && path_grid[xx][yy] == temp_path-1) {
                    x = x+dx[i];
                    y = y+dy[i];
                    // cout<<"temp_path: "<<temp_path<<endl;
                    temp_path--;
                    switch(i) {
                        case 0: path +="L";
                                break;
                        case 1: path +="U";
                                break;
                        case 2: path +="R";
                                break;
                        case 3: path +="D";
                                break;
                    }

                }
            }
        } while(grid[x][y] != 'B');
        cout <<"YES"<<endl<<min_path<<endl<<path;
    }
    

    return 0;
}