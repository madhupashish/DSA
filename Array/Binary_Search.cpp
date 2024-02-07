#include<iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
    public:
        Array(){
            int size=10;
            int length=0;
            A=new int [size];
        }
        ~Array(){
            delete []A;
        }

    void Display();
    int BinarySearch(int key);
    int RBinarySearch(int a[], int l, int h,int key);
};

void Array :: Display(){
    cout<<"\n Element are \n";
    for(int i=0;i<length;i++){
        cout<<"A[i]"<<" ";
    }
}

int Array :: BinarySearch (int key){
    int l,mid,h;
    l=0;
    mid=(l+h)/2;
    h=length-1;

    while(l<=h){
        if(key==A[mid])
            return mid;
        else if (key<A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int Array :: RBinarySearch(int a[], int l,int h, int key){
    int mid=0;
    if(l<=h){
        mid=(l+h)/2;
            if (key==a[mid])
                return mid;
            else if(key<a[mid])
                return RBinarySearch (a,l,mid-1,key);
            else
                return RBinarySearch (a,mid+1,h,key);
    }
    return -1;
    }


int main(){

    return 0;
}