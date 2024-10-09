#include <bits/stdc++.h>

using namespace std;

bool check(long long int mid,vector<long long int>v,long long int c){
    long long int lastpos=v[0];
    long long int cnt=1;
    for(int i=1;i<v.size();i++){
        if(abs(v[i]-lastpos)>=mid){
            cnt++;
            lastpos=v[i];
        }
    }
    return cnt>=c;
}

int main(){
long long int t;
cin>>t;

while(t--){
    long long int n,c;
    cin>>n>>c;
    vector<long long int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long int lo=0;
    long long int hi=v[n-1]-v[0];
    long long int mid,ans=0;
    while(lo+1<hi){
        mid=lo+(hi-lo)/2;
        if(check(mid,v,c)){
            ans=mid;
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    cout<<ans<<endl;
}
return 0;
}
