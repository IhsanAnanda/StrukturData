#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstring>
#include <windows.h>

using namespace std;

struct mahasiswa{
	unsigned long int nim;
	string nama;
	char jenis;
	string jurusan;
	int nilai[3];
	int rata;
}mhs[999];
int n;
unsigned long int pointer;

void input()
{
	cout<<endl;
	char a;
	cout<<"Masukkan Jumlah Data Mahasiswa yang ingin diinput : ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Masukkan NIM\t: ";cin>>mhs[i].nim;
		cout<<"Masukkan Nama\t: ";cin>>mhs[i].nama;
		cout<<"Masukkan Jenis(L/P)\t:";cin>>mhs[i].jenis;
		cout<<"Masukkan Jurusan\t:";cin>>mhs[i].jurusan;
		mhs[i].rata=0;
		for(int j=0;j<3;j++){
			cout<<"Masukkan Nilai Harian "<<j+1<<" : ";cin>>mhs[i].nilai[j];
			mhs[i].rata=mhs[i].rata+mhs[i].nilai[j];
			}
		mhs[i].rata=mhs[i].rata/3;
		cout<<endl;
	}
	system ("cls");
	cout<<"================================================================================================================================================"<<endl;
	cout<<"					  	TABEL DATA MAHASISWA UNIVERSITAS ABC YOGYAKARTA"<<endl;
	cout<<"================================================================================================================================================"<<endl;
	cout<<"	NIM		|	Nama	|	L/P	|	JURUSAN 	|	Nilai 1	|	Nilai 2	|	Nilai 3	|	Rata-Rata"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"	"<<mhs[i].nim<<"	"<<"|"
			<<"	"<<mhs[i].nama<<"	"<<"|"
			<<"	"<<mhs[i].jenis<<"	"<<"|"
			<<"	"<<mhs[i].jurusan<<"	"<<"|"
			<<"	"<<mhs[i].nilai[0]<<"	"<<"|"
			<<"	"<<mhs[i].nilai[1]<<"	"<<"|"
			<<"	"<<mhs[i].nilai[2]<<"	"<<"|"
			<<"	"<<mhs[i].rata
			<<endl;
	}
}

void sorting()
{
	mahasiswa swap;
	for(int i=n; i>1; i--){
		for(int j=0; j<i; j++){
			if(mhs[j].rata>mhs[j+1].rata){
				swap=mhs[j+1];
				mhs[j+1]=mhs[j];
				mhs[i]=swap;
			}
		}
	}
	cout<<"================================================================================================================================================"<<endl;
	cout<<"				  	TABEL DATA MAHASISWA UNIVERSITAS ABC YOGYAKARTA BERDASARKAN RATA-RATA"<<endl;
	cout<<"================================================================================================================================================"<<endl;
	cout<<"	NIM		|	Nama	|	L/P	|	JURUSAN 	|	Nilai 1	|	Nilai 2	|	Nilai 3	|	Rata-Rata"<<endl;
	for(int i=n-1; i>-1; i--)
	{
		cout<<"	"<<mhs[i].nim<<"	"<<"|"
			<<"	"<<mhs[i].nama<<"	"<<"|"
			<<"	"<<mhs[i].jenis<<"	"<<"|"
			<<"	"<<mhs[i].jurusan<<"	"<<"|"
			<<"	"<<mhs[i].nilai[0]<<"	"<<"|"
			<<"	"<<mhs[i].nilai[1]<<"	"<<"|"
			<<"	"<<mhs[i].nilai[2]<<"	"<<"|"
			<<"	"<<mhs[i].rata
			<<endl;
	}
}

void search()
{
	bool found;
	cout<<"Masukkan NIM yang ingin dicari :";
	cin>>pointer;
	found =false;
	int i=0;
	while ((i<n)&(!found))
	{
	    if (mhs[i].nim==pointer)
	    found=true;
	    else
	    i=i+1;
	}
	if(found){
	cout<<"NIM "<<pointer<<" Ditemukan  "<<endl;
	cout<<"Nama\t: "<<mhs[i].nama<<endl;
	cout<<"Jenis Kelamin\t: "<<mhs[i].jenis<<endl;
	cout<<"Jurusan\t: "<<mhs[i].jurusan<<endl;
	cout<<"Nilai Harian 1\t: "<<mhs[i].nilai[0]<<endl;
	cout<<"Nilai Harian 2\t: "<<mhs[i].nilai[1]<<endl;
	cout<<"Nilai Harian 3\t: "<<mhs[i].nilai[2]<<endl;
	cout<<"Rata-Rata\t: "<<mhs[i].rata<<endl;
	}
	else{
	cout<<"NIM "<<pointer<<" TIDAK ADA DALAM DATA ";
	}
}

int main()
{
	int pilih=0;
    do {system ("cls");
    	cout<<"======================================================================"<<endl;
		cout<<" PROGRAM SISTEM INFORMASI MAHASISWA UNIVERSITAS ABC YOGYAKARTA "<<endl;
		cout<<"======================================================================"<<endl<<endl;
       	cout<<"Daftar Menu : "<<endl;
	    cout<<"1. Input Data Mahasiswa"<<endl;
	    cout<<"2. Menampilkan Data Sesuai Dengan Urutan Rata-Rata Tertinggi"<<endl;
	    cout<<"3. Mencari Data"<<endl;
	    cout<<"0. Keluar"<<endl;
    cout<<"Masukkan Pilihan Anda : ";cin>>pilih;
    switch(pilih)
        {case 1:{if(n==10){cout<<"Masukkan Data Terlebih Dahulu"<<endl;}else {input();};break;}
         case 2:{if(n==0){cout<<"Masukkan Data Terlebih Dahulu"<<endl;}else{sorting();};break;}
         case 3:{if(n==0){cout<<"Masukkan Data Terlebih Dahulu"<<endl;}else{search();};break;}
         case 0:{cout<<"Program Selesai... "<<endl;system("pause");break;}
         default:cout<<"Pilihan Yang Masukkan Salah "<<endl;}
    system("pause");}
    while(pilih!=0);
}


