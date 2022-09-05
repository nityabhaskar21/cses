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

class Graph {
    int n;
    list<pair<ll,ll>> *l;

    public:
        Graph(int n) {
            this->n = n;
            this->l = new list<pair<ll,ll>>[n+1];
        }

        void addEdge(int x, int y, ll w) {
            l[x].push_back({y, w});
            // l[y].push_back({x, w});      Since flight is 1 way so directed graph only.
        }

        void shortestPath() {
            vector<ll> distance(n+1, LONG_MAX);

            set<pair<ll,ll>> s;       //pair<weight, node>
            s.insert({0, 1});
            distance[1] = 0;

            while(!s.empty()) {
                auto it = s.begin();
                int node = it->second;
                ll weightTill = it->first;
                s.erase(it);

                for (auto nbr: l[node]) {
                    if (weightTill+nbr.second < distance[nbr.first]) { 
                        auto it2 = s.find({distance[nbr.first], nbr.first});
                        if (it2 != s.end() ) {
                            s.erase(it2);
                        }


                        distance[nbr.first] = weightTill+nbr.second;
                        s.insert(make_pair(distance[nbr.first], nbr.first));
                    }
                }
            }
           for (int i = 1; i <= n; i++) {
                cout<<distance[i]<<" ";
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

    int cities, no_flights;
    cin>>cities>>no_flights;

    Graph g(cities);

    int x, y;
    ll w;
    for (int i = 0; i < no_flights; i++) {
        cin>>x>>y>>w;
        g.addEdge(x, y, w);
    }

    g.shortestPath();

    return 0;
}