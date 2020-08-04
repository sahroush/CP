#include <bits/stdc++.h>

using namespace std;

const int maxn  = 3e6;

#define endl '\n'
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n , q , sq,nxt[maxn],dist[maxn],last[maxn],comp[maxn],a[maxn];

void solve(int i){
    comp[i] = i/sq;if(a[i]+i > n)a[i] = n+1 - i;
    if(i + a[i] == n+1)
        nxt[i] = 0 , last[i] = i , dist[i] = 1;
    else if(comp[i] == comp[i+a[i]])
        nxt[i] = nxt[i+a[i]] , last[i] = last[i+a[i]] , dist[i] = dist[i + a[i]] + 1;
    else
        nxt[i] = i + a[i] ,last[i] = last[i+a[i]], dist[i] = 1;
}

int main(){
    migmig
    cin >> n >> q;
    sq = sqrt(n);
    for(int i = 1 ; i <= n; i ++)
        cin >> a[i];
    for(int i = n ; i ; i --)
        solve(i);
    while(q -- ){
        int t; cin >> t;
        if(t){
            int cur , sum = 0 , lst = 0;cin >> cur;
            while(cur!=0)
                sum += dist[cur],lst = last[cur],cur = nxt[cur];
            cout << lst << ' ' << sum << endl;
        }
        else{
            int pos , x; cin >> pos >> x;
            if(x+pos > n) x = n+1 - pos;a[pos] = x;
            for(int i = pos ; i and comp[i] == comp[pos] ; i --)
                solve(i);
        }
    }
    return(0);
}