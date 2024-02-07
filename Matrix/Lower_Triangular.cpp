#include<iostream>
using namespace std;

class LTMatrix{
    private:
        int n;
        int *A;
    public:
        LTMatrix(int n){
            this->n=n;
            A=new int[n*(n+1)/2];
        }
        ~LTMatrix(){delete []A;}
        void Display(bool row=true);
        void SetRowMajor(int i,int j,int x);
        void SetColMajor(int i,int j,int x);
        int GetRowMajor(int i,int j);
        int GetColMajor(int i,int j);
        void Display1();
};

void LTMatrix::SetRowMajor(int i,int j,int x){
    if(i>=j){
        int index=((i*(i-1))/2) + j-1 ;
        A[index]=x;
    }
}

void LTMatrix::SetColMajor(int i,int j,int x){
    if(i>=j){
        int index=(n*(j-1)-(((j-2)*(j-1))/2)) + i-j ;
        A[index]=x;
    }
}

int LTMatrix::GetRowMajor(int i, int j){
    if(i>=j){
        int index=(i*(i-1))/2 + j-1;
        return A[index];
    }
    else{return 0;}
}

int LTMatrix::GetColMajor(int i,int j){
    if(i>=j){
        int index=(n*(j-1)-(((j-2)*(j-1))/2)) + i-j ;
        return A[index];
    }
    else{
        return 0;
    }
}

void LTMatrix::Display(bool row){
    for(int i=1; i<=n ;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){
                if(row){
                    cout<< GetRowMajor(i,j) <<" ";
                }
                else{
                    cout<< GetColMajor(i,j) <<" "; 
                }
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

void LTMatrix::Display1(){
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                cout<<A[(i*(i-1))/2 + j-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    LTMatrix rm(4);
    rm.SetRowMajor(1,1,1);
    rm.SetRowMajor(2,1,2);
    rm.SetRowMajor(2,2,3);
    rm.SetRowMajor(3,1,4);
    rm.SetRowMajor(3,2,5);
    rm.SetRowMajor(3,3,6);
    rm.SetRowMajor(4,1,7);
    rm.SetRowMajor(4,2,8);
    rm.SetRowMajor(4,3,9);
    rm.SetRowMajor(4,4,10);

    rm.Display();
    cout<<endl;

    LTMatrix cm(4);
    cm.SetColMajor(1,1,1);
    cm.SetColMajor(2,1,2);
    cm.SetColMajor(2,2,3);
    cm.SetColMajor(3,1,4);
    cm.SetColMajor(3,2,5);
    cm.SetColMajor(3,3,6);
    cm.SetColMajor(4,1,7);
    cm.SetColMajor(4,2,8);
    cm.SetColMajor(4,3,9);
    cm.SetColMajor(4,4,10);

    cm.Display(false);
    return 0;
}