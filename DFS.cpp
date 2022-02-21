#include <iostream>
#include <vector>
#define N 9

using namespace std;



bool visited[N];
vector<int> graph[N];

void dfs(int x){// 방문한 노드 처리구문
    visited[x] = true;// 노드 방문처리
    cout << x << " ";
    for(int i = 0; i < graph[x].size() ; i++){//인접한 노드 크기만큼 탐색
        int y = graph[x][i];
        if(!visited[y])
            dfs(y);//다음 인접하지 않은 노드 탐색
    }

}


int main(){
}