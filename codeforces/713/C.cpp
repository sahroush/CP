#include <bits/stdc++.h>
using namespace std;int64_t ans,n,a[3010];priority_queue<int>pq;int main(){cin>>n,pq.push(-1);for(int i=1;i<=n;pq.push(a[i]),i++){cin>>a[i],a[i]+=n-i;if(a[i] < pq.top())ans+=pq.top(),pq.pop(),pq.push(a[i]),ans-=a[i];}cout<<ans;}
