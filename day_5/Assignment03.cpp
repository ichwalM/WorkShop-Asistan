#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mahasiswa{
    string stb,name;

    void setStb(string stb){
        this->stb=stb;
    }
    void setName(string name){
        this->name=name;
    }
};

bool compare(Mahasiswa m1, Mahasiswa m2){
	return m1.stb < m2.stb;
}

int main(){
    int data;
    string stb,name;
    cout<<"input jumlah data \t: ";cin>>data;cin.ignore();
    vector<Mahasiswa>vMhs;
    for(int i=0;i<data;i++){
        cout<<"Masukkan stb \t: ";getline(cin,stb);
        cout<<"Masukkan nama \t: ";getline(cin,name);
        Mahasiswa mhs1;
        mhs1.setStb(stb);
        mhs1.setName(name);
        vMhs.push_back(mhs1);
    };
    
    sort(vMhs.begin(), vMhs.end(), compare);

    for(Mahasiswa mhs: vMhs){
        cout<<"Stb \t: "<<mhs.stb<<endl;
        cout<<"Nama \t: "<<mhs.name<<endl;
        cout<<"---------------"<<endl;
    }
}