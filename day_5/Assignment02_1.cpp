#include <iostream>
using namespace std;

void deret(int x){
    if(x==0){
        return;
    }else{
        deret(x-1);
        for(int i=0;i<x;i++)cout<<"*"<<" ";
        cout<<endl;
    }
}

int main(){
    int i=1;
    cout<<"input nilai i \t ";cin>>i;
    deret(i);
}