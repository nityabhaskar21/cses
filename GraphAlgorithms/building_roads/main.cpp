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
#include <tuple>
 
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

class Graph {
    int n;
    list<int> *l;
    vector<bool> visited;
    vector<pair<int,int>> newEdges;
    public: 
        Graph(int n) {
            this->n = n;
            l = new list<int>[n+1];
            visited.resize(n+1, false);
        }

        void addEdge(int x, int y) {
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void connect_components(int x) {
            visited[x] = true;

            for (auto node:l[x]) {
                if (!visited[node]) {
                    visited[node] = true;
                    connect_components(node);
                }
            }
        }

        int build_roads() {
            int ans = 0;

            connect_components(1);

            for (int i = 1; i <= n; i++) {
                
                for (auto &node : l[i]) {
                    if (!visited[node]) {
                        newEdges.push_back({node, 1});
                        ans++;
                        connect_components(node);
                    }
                }
            }

            for (int i = 2; i <= n; i++) {
                if (!visited[i]) {
                    ans++;
                    visited[i] = true;
                    newEdges.push_back({1, i});
                }
            }
        
            return ans;
        }

        void printNewEdges() {
            cout<<endl;
            for (int i = 0; i < newEdges.size(); i++) {
                cout<<newEdges[i].first<<" "<<newEdges[i].second<<endl;
            }
        }

};

int main()
{
    fast_cin();

    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    #endif

    int cities , roads;

    cin>>cities>>roads;

    Graph g(cities);

    int x, y;
    for (int i = 0; i < roads; i++) {
        cin>>x>>y;
        g.addEdge(x, y);
    }

    cout<<g.build_roads();
    g.printNewEdges();


    return 0;
}