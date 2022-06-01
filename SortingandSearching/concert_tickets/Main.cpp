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
 

void solve(){
}
int main()
{
    fast_cin();

    // #ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    // #endif
    long no_tickets = 0;
    long no_people = 0;
    cin>>no_tickets>>no_people;

    v64 tickets, people, answer;

    int i = 0;
    ll e = 0;

    while (i < no_tickets) {
        cin>>e;
        tickets.pb(e);
        i++;
    }
    i = 0;
    while (i < no_people) {
        cin>>e;
        people.pb(e);
        i++;
    }
 
    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < people.size(); i++) {
        int j = 0;
        for (j = 0; j < tickets.size(); j++) {
            if (people[i] > tickets[j]) break;
        }
        if (tickets.size() == 0) {
            people.push_back(-1);
            break;
        }
        for (auto it = tickets.begin(); it != tickets.end(); ++it) {
            if (*it > people[i] && it != tickets.begin()) {
                answer.push_back(*(it-1));
                tickets.erase(it-1);
                break;
            }
            else if (*it > people[i] && it == tickets.begin()) {
                answer.push_back(-1);
                break;
            }
        }
        
    }
    for(int i = 0; i < answer.size(); i++) {
        cout<<answer.at(i)<<endl;
    }

    return 0;
}