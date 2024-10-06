#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;
    cin>>n;
    
    vector<long long int>s(n);
    
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    
    vector<long long int>left;
    vector<long long int>right;
    
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            for(int k=0;k<s.size();k++){
                long long int hi=s[i]*s[j]+s[k];
                left.push_back(hi);
                if(s[i]!=0){
                    long long int ki=s[i]*(s[j]+s[k]);
                    right.push_back(ki);
                }
            }
        }
    }
    
    sort(right.begin(),right.end());
    long long int cnt=0;
    
    for(int i=0;i<left.size();i++){
        long long int idx=lower_bound(right.begin(),right.end(),left[i])-right.begin();
        long long int idx1=upper_bound(right.begin(),right.end(),left[i])-right.begin();
        cnt+=idx1-idx;
    }
    cout<<cnt<<endl;
    return 0;
}
