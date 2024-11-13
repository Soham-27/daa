#include<iostream>
#include<vector>
using namespace std;

struct item {
    int index;
    int weight;
    int profit;
};

void knapsack(int n, int maxcap, vector<int>& index, vector<int>& weight, vector<int>& profit) {
    vector<item> items;
    for(int i = 0; i < n; i++) {
        items.push_back({
            index[i],
            weight[i],
            profit[i]
        });
    }
    vector<vector<int>> matrix(n + 1, vector<int>(maxcap + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= maxcap; w++) {
            if(items[i - 1].weight > w) {
                matrix[i][w] = matrix[i - 1][w];
            } else {
                matrix[i][w] = max(matrix[i - 1][w], matrix[i - 1][w - items[i - 1].weight] + items[i - 1].profit);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxcap;j++){
            cout<<matrix[i][j]<<" ,";
        }
        cout<<endl;
    }
    
    cout << "Maximum profit: " << matrix[n][maxcap] << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int maxcap;
    cout << "Enter the maximum capacity: ";
    cin >> maxcap;
    vector<int> index(n);
    vector<int> weight(n);
    vector<int> profit(n);

    for(int i = 0; i < n; i++) {
        index[i] = i + 1;
        cout << "\nEnter profit of element " << (i + 1) << ": ";
        cin >> profit[i];
        cout << "Enter weight of element " << (i + 1) << ": ";
        cin >> weight[i];
    }

    cout << "Index: ";
    for(int i = 0; i < n; i++) {
        cout << index[i] << "\t";
    }
    cout << endl;
    
    cout << "Profit: ";
    for(int i = 0; i < n; i++) {
        cout << profit[i] << "\t";
    }
    cout << endl;
    
    cout << "Weight: ";
    for(int i = 0; i < n; i++) {
        cout << weight[i] << "\t";
    }
    cout << endl;

    knapsack(n, maxcap, index, weight, profit);
    return 0;
}
