#include <iostream>
using namespace std;

void tampil(int i){
    if(i==0) return;
    cout<<"*"<<" ";
    tampil(i-1);
}

void deret(int x){
    if(x==0){
        return;
    }else{
        // for(int i=0;i<x;i++)cout<<"*"<<" ";
        deret(x-1);
        tampil(x);
        cout<<endl;
    }
}

int main(){
    int i=1;
    cout<<"input nilai i \t ";cin>>i;
    deret(i);
}