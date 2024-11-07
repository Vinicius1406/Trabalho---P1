#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[],int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n - i - 1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



int main(){
    int m,n;
    cout << "Digite o tamanho dos arrays\n";
    scanf("%d %d",&m,&n);
    int nums1[m];
    int nums2[n];
    int nums3[m+n];
    cout << "Digite os valores do array 1\n";
    for(int i = 0;i < m;i++){
        scanf("%d",&nums1[i]);
    }
    cout << "Digite os valores do array 2\n";
    for(int j = 0;j < n;j++){
        scanf("%d",&nums2[j]);
    }
    for(int k = 0;k < m + n;k++){
        nums3[k] = 0;
    }
    for(int i = 0;i < m;i++){
        nums3[i] = nums1[i];
    }
    for(int u = m;u < m + n;u++){
        nums3[u] = nums2[u-m];
    }
    //cout << "oi2\n";
    bubbleSort(nums3,m+n);
    for(int y = 0;y < m+n;y++){
        printf("%d",nums3[y]);
    }
    //cout << nums3 << endl;
    return 0;
}