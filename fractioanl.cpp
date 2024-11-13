#include<iostream>
#include<vector>
using namespace std;

struct item{
    int w ;
    int p;
    double pw;
};


double fractionalKnap(vector<item>&array,int n,int cap){
    for(int i=0;i<n;i++){
        array[i].pw=(double)array[i].p/(double)array[i].w;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(array[j].pw<array[j+1].pw){
            item temp=array[j+1];
            array[j+1]=array[j];
            array[j]=temp;
            }
        }
    }
    int current=0;
    double profit=0.0;
    for(int j=0;j<n;j++){
        if(current+array[j].w<cap){
            current+=array[j].w;
            profit+=array[j].p;
        }
        else{
            int remain=cap-current;
            profit+=array[j].pw*remain;
            break;
        }
    }
    return profit;
}

int main(){
    int cap,n;
    cout<<"Enter the capacity of KnapSack"<<endl;
    cin>>cap;
    cout<<"Enter the no of elements"<<endl;
    cin>>n;
    vector<item>array(n);
    cout<<"Enter the weights and profits for "<<n<<"item "<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i].w>>array[i].p;
        array[i].pw=0;
    }
    double maxtotal=fractionalKnap(array,n,cap);
    cout<<"total profit is"<<maxtotal<<endl;

}