 #include<iostream>
 #include<stdio.h>
 #include<stdlib.h>
 using namespace std;
 struct NgayThang
 {
 	int ngay;
 	int thang;
 	int nam;	
 };

 int KiemTra(int nam)
 {
 	if((nam%400 == 0)||(nam%4==0 && nam%100 != 0))
 		return 1;
 	return 0;
 		
 }
 int STT(NgayThang n)
 {
 	int thang[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 	int stt = 0;
 	for (int i=1;i<n.thang;i++)
 		stt += thang[i];
 	stt += n.ngay;
 	if (n.thang>2)
 	if (KiemTra (n.nam)) stt+=1;
 	return stt;	
 }
 NgayThang ngayTUSTT(int stt,int nam)
 {
 	int m=1;
 	int ngay=stt;
 	while (stt>0)
 	{
 		if(KiemTra(nam)==1)&&(m==2)
 			stt = stt-29;
 		else 
 			stt = stt-thang[m];
 		if (stt >0)
 		{
 			day =stt;
 			m++;
		 }
	 }
 }
 NgayThang Cong(NgayThang n, int x);
 {
 	int kq = x+STT(n);
 	int nam=n.nam;
 	if (kq<=365)
 		return ngayTUSTT(kq,nam);
 	else 
	 	if(KiemTra(n.nam)==1)
		 	if (kq==366)
			 	return ngayTUSTT(kq,n.nam);
			else
				return ngayTUSTT(kq-366,n.nam+1);
		else
			return ngayTUSTT(kq-365,n.nam+1);	
 }
// void PrintRs(int n, int sum)
// {
// 	int i=0;
// 	while (sum>thang[i])
// 	{
// 		sum= sum-thang[i];
// 		i++;
//	 }
//	 cout<<sum<<"ngay"<<i<<"thang"<<n<<"nam"<<endl;
// }
// void Add(NgayThang n, int t)
// {
// 	int sum=0;
// 	sum=STT(NgayThang n)+t;
// 	if (KiemTra(n.nam))
// 		{
// 			if (sum<=366)
// 			{
// 				thang[2]=29;
// 				PrintRs(n.nam,sum);
// 				thang[2]=28;
//			 }
//			else 
//				PrintRs(n.nam+1,sum-366);
//		 }
//	else 
//		{
//			if (sum<=365)
//				PrintRs(n.nam,sum);
//			else 
//			{
//				n.nam++;
//				if (KiemTra(n))
//					{
//						thang[2]=29;
//						PrintRs(n.nam,sum-365);
//						thang[2]=28;
//					}
//				else {
//					PrintRs(n.nam,sum-365);
//				}
//			}
//			
//			
//		}
// }
 int main()
 {
 	
 	fflush(stdin);
 	NgayThang n;
 	string st;
 	cout<<endl;
 	Create(x,st);
	if(KiemTra(n.nam)) cout<<"nam nhuan "<<endl;
	else	
		cout<<"nam khong nhuan "<<endl;
	cout<<STT(n)<<endl;
	Add(n,2);
 	string date;
 	cout<<"nhap du lieu ";
 	getline(cin,date);
 	NgayThang n;
 	char t[4];
 	t[0]=date[0];
 	t[1]=date[1];
 	n.ngay = atoi(t);
 	t[0]=date[3];
 	t[1]=date[4];
 	n.thang	=atoi(t);
 	t[0]=date[6];
 	t[1]=date[7];
	t[2]=date[8];
	t[3]=date[9];
	n.nam = atoi(t);
		cout<< n.ngay<<"/" << n.thang<<"/" << n.nam<<endl ;
	if(KiemTra(n.nam)==1)
		cout<<"nam nhuan :";
	else
		cout<<"nam khong nhuan :";
		
	cout<< "la ngay thu "<< STT(n) <<" trong nam\n";
	

}
