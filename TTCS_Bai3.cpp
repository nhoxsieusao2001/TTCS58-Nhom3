#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
struct BoDe
{
	string cauhoi;
	string A, B, C;
	string DA;
};
vector <BoDe> bd;
struct Nguoichoi
{
	string ten;
	int diem;
};
vector <Nguoichoi> NC;
void Xuat(BoDe bd)
{
	string DapAn;
	cout<<bd.cauhoi<<endl;
	cout<<bd.A<<endl;
	cout<<bd.B<<endl;
	cout<<bd.C<<endl;
	cout<<" nhap dap an tra loi "; cin>>DapAn;
	if (bd.DA==DapAn)
		cout<<"ban da nhap dung"<<endl;
	else cout<<"ban da sai"<<endl;
	
}
void DocDee(){
	for(int i=0;i<bd.size();i++)
		Xuat(bd[i]);	
	
}

void DocDe()
{
	
	int de;
	cout<<"chon de ";
	cin>>de;
	if (de ==1)
		{
			ifstream f("de1.txt");//mo ra de doc
			string s;
			BoDe de1; 
			
			int SL;
			getline(f,s);
			SL=atoi(s.c_str());// doi tu kieu string sang kieu int
			for (int i=0;i<SL;i++)
			{
				getline(f,s);  de1.cauhoi=s;
				getline(f,s);  de1.A=s;
				getline(f,s);  de1.B=s;
				getline(f,s);  de1.C=s;
				getline(f,s);	de1.DA =s;
				bd.push_back(de1);
				
			}
			DocDee();
		}
		if (de ==2)
		{
			ifstream f("de2.txt");//mo ra de doc
			string s; BoDe de2; 
			int SL;
			getline(f,s);
			SL=atoi(s.c_str());// doi tu kieu string sang kieu int
			for (int i=0;i<SL;i++)
			{
				getline(f,s);
				de2.cauhoi =s;
	
				getline(f,s);
				de2.A=s;
				getline(f,s);
				de2.B=s;	
				getline(f,s);
				de2.C=s;
				getline(f,s);
				de2.DA =s;
				bd.push_back(de2);
			}
			DocDee();
		}	
}

int main()
{
DocDe();
}
