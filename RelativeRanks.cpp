#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[],int n){
    for(int i = 1;i < n;i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] < key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n;
    cout << "Digite o tamanho do array score\n";
    scanf("%d",&n);
    int score[n];
    string answer[n];
    cout << "Digite os valores de score\n";
    for(int i = 0;i < n;i++){
        scanf("%d",&score[i]);
    }
    insertionSort(score,n);
    cout << "Explanation:" << " ";
    for(int i = 0;i < n;i++){
        cout << score[i] << " ";
    }
    for(int i = 1;i <= n;i++){
        if(i == 1){
            answer[i] = "\nGold Medal";
        }
        else if(i == 2){
            answer[i] = "Silver Medal";
        }
        else if(i == 3){
            answer[i] = "Bronze Medal";
        }
        else{
            answer[i] = to_string(i);
        }
    }
    for(int i = 1;i <= n;i++){
        cout << answer[i] << " ";
    }
}