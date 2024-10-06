#include <bits/stdc++.h>

using namespace std;

int main() {
    // Write C++ code here
    //this problem has corner time complexity test cases we need to be careful and apply the fast io as well as the /n wali bkc
     ios_base::sync_with_stdio(false); cin.tie(0);
    long long int t;
    cin>>t;
    
    while(t--){
        long long int n,m,q;
        cin>>n>>m>>q;
        multiset<long long int>sx,sy,px,py;
        sx.insert(n);
        sy.insert(m);
        px.insert(0);
        py.insert(0);
        px.insert(n);
        py.insert(m);
        while(q--){
            long long int tp;
            cin>>tp;
            if(tp==0){
                long long int x;
                cin>>x;
                if(px.find(x)!=px.end()){
                    cout<<((*sx.rbegin())*(*sy.rbegin()))<<"\n";
                    continue;
                }
                auto it1=px.lower_bound(x);
                it1--;
                auto itr=px.upper_bound(x);
                
                long long int del_v=*itr-*it1;
                sx.erase(sx.find(del_v));
                
                long long int val1=*itr-x;
                long long int val2=x-*it1;
                sx.insert(val1);
                sx.insert(val2);
                px.insert(x);
            }
            else{
                long long int y;
                cin>>y;
                if(py.find(y)!=py.end()){
                   cout<<((*sx.rbegin())*(*sy.rbegin()))<<"\n";
                    continue;
                }
                auto itl = py.lower_bound(y);
				itl--;
				auto itr = py.upper_bound(y);

				long long int del_val = *itr - *itl;
				sy.erase(sy.find(del_val));

				long long int val1 = *itr - y;
				long long int val2 = y - *itl;

				sy.insert(val1);
				sy.insert(val2);
				py.insert(y);
            }
            cout<<((*sx.rbegin())*(*sy.rbegin()))<<"\n";
        }
    }

    return 0;
}
