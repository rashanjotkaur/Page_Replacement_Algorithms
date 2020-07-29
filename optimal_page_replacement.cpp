#include <bits/stdc++.h>
using namespace std;
int predict(int arr[],int n,unordered_set <int> s,int start){
    int farthest=start;
    int res;
    for(auto it=s.begin();it!=s.end();it++){
        int x=(*it);
        int i;
        for(i=start;i<n;i++){
            if(x==arr[i]){
                if(i>farthest){
                    farthest=i;
                    res=x;
                }
                break;
            }
        }
        if(i==n)
            return x;
    }
    return res;
}
int optimal_page(int arr[],int n,int frSize){
    unordered_set <int> s;
    int fault=0;
    for(int i=0;i<n;i++){
        if(s.find(arr[i])==s.end()){
            fault++;
            if(s.size()==frSize){
                int page=predict(arr,n,s,i+1);
                s.erase(page);
            }
            s.insert(arr[i]);
        }
    }
    return fault;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,s;
	    cin>>n>>s;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<optimal_page(arr,n,s)<<endl;
	}
	return 0;
}
2
20 3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
13 4
7 0 1 2 0 3 0 4 2 3 0 3 2
