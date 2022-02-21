#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    
    int now = input[0],  std = input[0];
    int count = 0;;

    for(int i = 1; i < input.length(); i++){
        if(now != input[i] && input[i] != std){//기준 문자열과 달라진 순간만 카운트
            count+=1;
        }
        now = input[i];
    }

    cout << count << endl;
}