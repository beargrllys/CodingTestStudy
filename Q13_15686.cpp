#include<iostream>
#include <vector>

using namespace std;

int cnt, standard;
int result;
vector<int> arr;

void dfs(int i, int sum){
    if(i == cnt) return;
    if(sum+arr[i] ==standard) result++;

    dfs(i+1, sum);
    dfs(i+1, sum+arr[i]);
}

int main(){
    int tmp;

    cin >> cnt >> standard;
    for(int i = 0; i < cnt; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    dfs(0,0);

    cout << result << endl;

}