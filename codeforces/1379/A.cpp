/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q , n;
string s;

int cnt(string s){
    int ans = 0;
    string cur = "";
    for(int i = 0 ; i < n ; i ++){
        cur += s[i];
        if(cur.size() > 7){
            string d = "";
            for(int i = 1 ; i < 8 ; i ++)
                d += cur[i];
            cur = d;
        }
        if(cur.size() == 7)
            ans += (cur == "abacaba");
    }
    return(ans);
}

string solve(int st){
    string res = s;
    for(int i = 0 ; i < st  ; i ++)
        if(res[i] == '?') res[i] = 'x';
    for(int i = st; i < n ; i ++){
        if(i - st == 0){
            if(res[i]!='a' and res[i]!= '?')
                return("FUCK");
            res[i] = 'a';
        }
        if(i - st == 1){
            if(res[i]!='b' and res[i]!= '?')
                return("FUCK");
            res[i] = 'b';
        }
        if(i - st == 2){
            if(res[i]!='a' and res[i]!= '?')
                return("FUCK");
            res[i] = 'a';
        }
        if(i - st == 3){
            if(res[i]!='c' and res[i]!= '?')
                return("FUCK");
            res[i] = 'c';
        }
        if(i - st == 4){
            if(res[i]!='a' and res[i]!= '?')
                return("FUCK");
            res[i] = 'a';
        }
        if(i - st == 5){
            if(res[i]!='b' and res[i]!= '?')
                return("FUCK");
            res[i] = 'b';
        }
        if(i - st == 6){
            if(res[i]!='a' and res[i]!= '?')
                return("FUCK");
            res[i] = 'a';
        }
        if(i - st > 6 and res[i]=='?')
            res[i] = 'x';
    }
    return(res);
}

int32_t main(){
    migmig;
    cin >> q;
    while(q --){
        cin >> n >> s;int ans = -1; 
        for(int i = 0 ; i <= n-7 ; i ++){
            
            if(solve(i) != "FUCK" and cnt(solve(i)) == 1){
                //dokme(solve(i));
                ans = i;
            }
        }
        if(ans == -1){
            cout << "No" << endl;
            
        }
        else{
            cout << "Yes" << endl;
            cout << solve(ans) << endl;}
    }




    return(0);
}