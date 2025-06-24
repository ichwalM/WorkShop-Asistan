#include <iostream>
using namespace std;

void tampil(int ary[],int lenght){
    cout<<"Hasil \t\t: ";
    for(int i=0;i<lenght;i++)cout<<ary[i]<< " ";
}

int terkecil(int ary[],int lenght){
    int tmp = ary[0];
    for(int i=0;i<lenght;i++){
        if(tmp>ary[i]) tmp=ary[i];
    }
    return tmp;
}


int terbesar(int ary[],int lenght){
    int tmp = ary[0];
    for(int i=0;i<lenght;i++){
        if(tmp<ary[i]) tmp=ary[i];
    }
    return tmp;
}

float rataRata(int ary[], int lenght){
    float tmp=0;
    for(int i=0;i<lenght;i++)tmp+=ary[i];
    return tmp/lenght;
}

int diAtasRata(int ary[],int lenght,float rata){
    int tmp = 0;
    for(int i=0;i<lenght;i++){
        if(rata<ary[i]) tmp++;
    }
    return tmp;
}

int main(){
    int lenght=5;
    int ary[lenght];
    cout<<"Input Nilai \t: ";
    for(int i=0;i<lenght;i++)cin>>ary[i];
    float rata;
    rata=(float)rataRata(ary,lenght);
    tampil(ary,lenght);
    cout<<endl;
    cout<<"Nilai Terbesar \t: "<< terbesar(ary,lenght)<<endl;
    cout<<"Nilai Terkecil \t: "<< terkecil(ary,lenght)<<endl;
    cout<<"Rata-rata \t: "<<rata<<endl;
    cout<<"Bilangan Di atas Rata-rata : "<< diAtasRata(ary,lenght,rata);

    return 0;
}