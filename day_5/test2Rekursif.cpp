#include <iostream>
using namespace std;

void deret(int x){
    if(x==0){
        return;
    }else{
        deret(x-1);//head recursif
        cout<<x<<" ";
    }
}

void tail(int x){
    if(x==0){
        return;
    }else{
        cout<<x<<" ";//tail recursif
        deret(x-1);
    }
}

int main(){
    deret(4);
}