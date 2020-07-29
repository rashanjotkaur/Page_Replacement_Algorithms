// Method 1-TLE
#include<bits/stdc++.h>
using namespace std;
int lru_util(int pg[],int n,int stop,unordered_set <int> s){
    int res;
    int closest=stop;
    for(auto it=s.begin();it!=s.end();it++){
        int x=(*it);
        for(int i=0;i<=stop;i++){
            if(x==pg[i]){
                if(i<closest){
                    closest=i;
                    res=x;
                }
                break;
            }
        }
    }
    return res;
}

int lru(int pg[],int n,int frames){
    unordered_set <int> s;
    int fault=0;
    for(int i=0;i<n;i++){
        if(s.find(pg[i])==s.end()){
            fault++;
            if(s.size()==frames){
                int page=lru_util(pg,n,i-1,s);
                s.erase(page);
            }
            s.insert(pg[i]);
        }
    }
    return fault;
} 
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int pg[n];
	    for(int i=0;i<n;i++)
	        cin>>pg[i];
	    int frames;
	    cin>>frames;
	    cout<<lru(pg,n,frames)<<endl;
	}
	return 0;
}
