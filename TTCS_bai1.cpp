#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
fstream fi("input.dat");
fstream fo("output.dat");
typedef struct 
{ 
	char ten[20],sdt[20],diachi[50],gmail[20];
//	char gioitinh;
} contact;
char *fileName="danhba.dat";
vector <contact> db;
void docDBTuFile();
void ghiGBVaoFile();
void ThemMoi(contact c);
void Xoacontact(char* sdt);
void Suacontact(contact contactmoi);
void Incontact(contact c);
void InDB();
int main()
{
	cout<<"Hello"<<"\n";
	docDBTuFile();
	InDB();
	contact c1;
	strcpy(c1.sdt, "0961514115");
	strcpy(c1.ten, "Phan Trong Nghia");
	strcpy(c1.gmail, "ptnghia051098@gmail.com");
//	strcpy(c1.gioitinh, "Nam");
	strcpy(c1.diachi, "Khanh Hoa");
	contact c2;
	strcpy(c2.sdt, "096151411");
	strcpy(c2.ten, "Phan Trong ");
	strcpy(c2.gmail , "ptnghia05@gmail.com");
//	strcpy(c2.gioitinh, "Nam");
	strcpy(c2.diachi, "Khanh Hoa");
	ThemMoi(c1);
	ThemMoi(c2);
	docDBTuFile();
	cout<<"danh ba moi :\n";
	InDB();
	char sdt[11];
	cout<<"nhap SDT can xoa :";
	cin>>sdt;
	Xoacontact(sdt);
	cout<<"Danh Ba moi sau khi xoa :";
	InDB(); 
	
}
void docDBTuFile()
{
	db.clear();
	FILE *f;
	f= fopen(fileName,"rb");
	if (f!= NULL)
	{
		while (!feof(f))
		{
			contact c;
			fread(&c, sizeof(contact),1,f);
			db.push_back(c);	
		}
		fclose(f);
		db.pop_back();
	}
}
void ghiGBVaoFile()
{
	int size = db.size();
	FILE *f;
	f= fopen(fileName,"wb");
	contact c;
	for (int i=0;i<size;i++)	
	{	
		c=db[i];
		fwrite(&c,sizeof(contact), 1, f);
	}
	fclose(f);
}
void ThemMoi(contact c)
{
	db.push_back(c);
	ghiGBVaoFile();
}
void Incontact(contact c)
{
	cout<<"So DT : "<<c.sdt<<"\n";
	cout<<"Ten :"<<c.ten<<"\n";
	cout<<"Dia Chi :"<<c.diachi<<"\n";
	cout<<"Gmail : "<<c.gmail<<"\n";
//	cout<<"Gioi tinh:"<<c.gioitinh<<"\n";
	cout<<"---------------\n";
	
}
void InDB()
{
	int size=db.size();
	for(int i=0;i<size;i++)
	{
		Incontact(db[i]);
	}
}
void Xoacontact( char *sdt){
	int a;
	
	int size=db.size();
	for(int i=0;i<size;i++){
		if(strcmp(db[i].sdt,sdt)==0){
			a=i;
			db.erase(db.begin()+a);
		}
	}
	
}

