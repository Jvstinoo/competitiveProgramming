#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define um unordered_map<int, int>
#define si set<int>
#define sc set<char>
#define usi set<int>
#define usf set<float>

template <typename P>
void swapp(P &a, P &b) {
    P temp = a;
    a = b;
    b = temp;
}

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define lm(it, map) for (auto it = map.begin(); it != map.end(); it++)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/* clang-format on */

/* Main()  function */
int main()
{
    int out = 0;
    int n, rebar;
    cin >> n >> rebar;
    unordered_map<float, int> map;
    f(i,0,n) {
        int pieces;
        float length;
        cin >> pieces >> length;
        map[length] = pieces;
    }

    lm(it, map) {
        float sum = 0;
        bool added = false;
        lm(it2, map) {
            if ((sum + it2->first) <= rebar && it2->second != 0) {
                if (it == it2 && !added) {
                    sum += it2->first;
                    map[it2->first] --;
                    added = true;
                } else {
                    sum += it2->first;
                    map[it2->first] --;
                }
            }
        }
        if (sum != 0) {
            out += 1;
        }
    }
    cout << out;
	return 0;
}
/* Main() Ends Here */
