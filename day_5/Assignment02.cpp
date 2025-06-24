#include <iostream>
using namespace std;

void tampilBintang(int ukuran) {
    if (ukuran == 0) {
        return;
    }
    cout << "*"<<" ";
    tampilBintang(ukuran - 1);
}

void mainRekursif(int i, int j){
    if(i>j) return;
    else{
        tampilBintang(i);
        cout<<endl;
        mainRekursif(i+1, j);
    }
}
int main(){
    int i=1,j;
    cout<<"Masukkan Ukuran:";cin>>j;
    mainRekursif(i,j);
}