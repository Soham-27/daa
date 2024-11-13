#include<iostream>
#include<vector>
using namespace std;
void subsetHelper(vector<int>&arr,int n, vector<int>& elements,int index,int sum,vector<vector<int>>&ans,int targetsum){
    if(index==n){
        if(sum==targetsum){
            ans.push_back(elements);
        }
        return;
    }
    subsetHelper(arr,n,elements,index+1,sum,ans,targetsum);
    sum+=arr[index];
    elements.push_back(arr[index]);
    subsetHelper(arr,n,elements,index+1,sum,ans,targetsum);
    elements.pop_back();
}
vector<vector<int>> solvesubset(vector<int>&arr,int n, int targetsum){
    vector<vector<int>>ans;
    vector<int>elements;
    subsetHelper(arr,n,elements,0,0,ans,targetsum);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the no of elements"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the element that you want to insert :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target sum :"<<endl;
    cin>>target;
    vector<vector<int>>ans=solvesubset(arr,n,target);
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}