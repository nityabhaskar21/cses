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

//RUNTIME ERROR
string update_str(string str) {
    string updatedStr = "@";

    for (int i = 0; i < str.size(); i++) {
        updatedStr += '#';
        updatedStr += str[i];
    }
    updatedStr += '#';
    updatedStr += '$';

    return updatedStr;
}

string find_longest_palindrome(string str) {
    string updatedStr = update_str(str);
    int updatedLen = updatedStr.length();

    int center = 0; 
    int knownRange = 0;

    int lenPalindrome = 0;
    int startPalindromeIndex = 0;
    int endPalindromeIndex = 0;

    vector<int> lps(updatedLen, 0);

    for (int i = 1; i < updatedLen - 1; i++) {
        if (i < knownRange) {
            int mirrorIndex = center - (i - center);
            lps[i] = min(lps[mirrorIndex], knownRange - 1);
        }
        
        while (updatedStr[i-(lps[i] + 1)] == updatedStr[i+(lps[i] + 1)]) {
            lps[i]++;
        }
        if (i + lps[i] > knownRange) {
            center = i;
            knownRange = i + lps[i];
        }
        if (lps[i] > lenPalindrome) {
            lenPalindrome = lps[i];
            startPalindromeIndex = i - (lenPalindrome - 1);
            endPalindromeIndex = i + (lenPalindrome - 1);
        }
    }

    int originalStrStart = (startPalindromeIndex - 2) / 2;
    return str.substr(originalStrStart, lenPalindrome);

}
 

int main()
{
    fast_cin();

    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    #endif

    string str;
    cin>>str;

    cout<<find_longest_palindrome(str);

    return 0;
}