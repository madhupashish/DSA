#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout<<N<<endl;
    for(int i=0;i<N;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}