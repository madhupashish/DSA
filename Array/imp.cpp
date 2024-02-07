#include<iostream>
#include <bits/stdc++.h>  
using namespace std;

class Array{
    private:
        int size;
        int length;
        int *A;
    public:
        Array(){
            int size=10;
            int length=0;
            A=new int[size];
        }
        Array(){
            delete []A;
        }
void Display();
void Append(int X){
    if(length<size){
        A[length++]=X;
    }
}
void Insert(int index,int X);
void Delete(int index);
void Swap(int *X , int *Y);
int LinearSearch(int key);
int LinearSearch1(int key);
int BinarySearch(int key);
int RBinarySearch(int a[], int l,int h, int key);
int Get(int index);
void Set(int index,int X);
int Min();
int Max();
int Sum();
float Avg();
void Reverse();
void Reverse1();
void InsertSort(int x);
int isSort();
void Rearrange();
void sortedMerge(int a[], int b[], int res[], int n, int m);
Array* Merge(Array arr2);
void printUnion(int arr1[], int arr2[], int m, int n);
Array* Union(Array arr2);
Array* Diff(Array arr2);
void printIntersection(int arr1[], int arr2[], int m, int n);
Array* Inter(Array arr2);
};

void Array::Display(){
    for(int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Array::Append(int X){
    if(length<size){
        A[length++]=X;
    }
}

void Array::Insert(int index, int X){
    if(index>=0 && index<=length){
        for(int i=length-1;i>=index;i--){
            A[i]=A[i+1];
            A[index]=X;
            length++;
        }
    }
}

void Array::Delete(int index){
    int X=0;
    int i;
    if(index>=0 && index<length){
        X=A[index];
        for(i=index; i<length-1;i++){
            A[i]=A[i+1];
            length --;
            return X;
        }
    }
    return 0;
}

void Array::Swap(int *X, int *Y){
    int temp;
    temp=*X;
    *X=*Y;
    *Y=temp;
}

int Array :: LinearSearch(int key){
    for(int i=0;i<length;i++){
        if(key==A[i]){
            return i;
        }
    }
        return -1;
}

int Array :: LinearSearch1(int key){
    for(int i=0;i<length;i++){
        if(key==A[i]){
            Swap(&A[i],&A[0]);
            return i;
        }
    }
    return -1;
}

int Array :: BinarySearch(int key){
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

int Array::Get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
    return -1;
}

void Array::Set(int index,int X){
    if(index>=0 && index<length){
        A[index]=X;
    }
}

int Array ::Max(){
    int Max=A[0];
    for(int i=1;i<length;i++){
        if(A[i]>Max){
            Max=A[i];
        }
    }
    return Max;
}

int Array::Min(){
    int Min=A[0];
    for(int i=1;i<length;i++){
        if(A[i]<Min){
            Min=A[i];
        }
    }
    return Min;
}

int Array::Sum(){
    int sum=0;
    for(int i=0;i<length;i++){
        sum=+A[i];
    }
    return sum;
}

float Array::Avg(){
    return (float)Sum()/length;
}

void Array::Reverse(){
    int *B;
    int i,j;
    B=new int[size];
    for(i=length-1,j=0;i>=0;i++,j--){
        B[j]=A[i];
    }
    for(i=0,i<length;i++){
        A[i]=B[i];
    }
}

void Array::Reverse1(){
    for(int i=0,j=length-1;i<j;i++,j--){
        Swap(&A[i],&A[j]);
    }
}

void Array::InsertSort(int X){
    int i=length-1;
    if(length==size){
        return;
    }
    while(i>=0 && A[i]>X){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=X;
    length++;
}

int Array::isSort(){
    for(int i=0;i<length-1;i++){
        if(A[i]>A[i+1])
            return 0;
    }
    return 1;
}

void Array :: Rearrange(){
    int i,j;
    i=0;
    j=length-1;
    while(i>j){
        while(A[i]<0)i++;
        while(A[j]>=0)j--;
        if(i<j)Swap(&A[i],&A[j]);
    }
}

void Array :: sortedMerge(int a[], int b[], int res[], int n, int m){

/* int n = sizeof(a) / sizeof(a[0]); ---->   find the size of array a  
    int m = sizeof(b) / sizeof(b[0]); -----> find the size of array b  
    int res[n + m]; -----> create res array to Concatenate both the array   */


    // Concatenate two arrays
    int i = 0, j = 0, k = 0;  
    while (i < n) { // iterate in first array  
        res[k] = a[i]; // put each element in res array  
        i += 1;  
        k += 1;  
    }  
    while (j < m) { // iterate in the second array  
        res[k] = b[j]; // put each element in res array  
        j += 1;  
        k += 1;  
    }  
    sort(res, res + n + m); // sort the res array to get the sorted Concatenate  
}  

Array* Array :: Merge(Array arr2){
    int newSize = size + arr2.size;
        Array* mergedArray = new Array[size];

        // Copy elements from the current array
        for (int i = 0; i < size; i++) {
            mergedArray->A[i] = A[i];
        }

        // Copy elements from arr2
        for (int i = 0; i < arr2.size; i++) {
            mergedArray->A[size + i] = arr2.A[i];
        }

        return mergedArray;
}

void Array:: printUnion(int arr1[], int arr2[], int m, int n){
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (arr1[i] < arr2[j])
                cout << arr1[i++] << " ";

            else if (arr2[j] < arr1[i])
                cout << arr2[j++] << " ";

            else {
                cout << arr2[j++] << " ";
                i++;
                }
            }

  /* Print remaining elements of the larger array */
    while (i < m)
        cout << arr1[i++] << " ";

    while (j < n)
        cout << arr2[j++] << " ";
}

Array* Array::Diff(Array arr2) {
    int maxSize = size;  // Maximum possible size of the difference is the size of the current array
    Array* diffArray = new Array(maxSize);  // Create a new Array object with the maximum size

    int index = 0;  // Index to keep track of the current position in the diffArray

    // Iterate over the elements of the current array and check if they exist in arr2
    for (int i = 0; i < size; i++) {
        bool found = false;  // Flag to indicate if the current element is found in arr2

        // Check if the element exists in arr2
        for (int j = 0; j < arr2.size; j++) {
            if (A[i] == arr2.A[j]) {
                found = true;
                break;
            }
        }

        // If the element is not found in arr2, add it to the diffArray
        if (!found) {
            diffArray->A[index] = A[i];
            index++;
        }
    }

    diffArray->size = index;  // Update the size of the diffArray based on the actual number of differing elements
    return diffArray;
}

void Array ::printIntersection(int arr1[], int arr2[], int m, int n){
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
            {
            cout << arr2[j] << " "; 
                i++; 
                j++; 
        } 
    } 
} 

Array* Array:: Inter(Array arr2){
    int maxSize = (size < arr2.size) ? size : arr2.size;  // Determine the maximum possible size of the intersection
    Array* interArray = new Array[size];  // Create a new Array object with the maximum size

    int index = 0;  // Index to keep track of the current position in the interArray

    // Iterate over the elements of the current array and check if they exist in arr2
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arr2.size; j++) {
            if (A[i] == arr2.A[j]) {
                interArray->A[index] = A[i];
                index++;
                break;
            }
        }
    }

    interArray->size = index;  // Update the size of the interArray based on the actual number of intersecting elements
    return interArray;
}