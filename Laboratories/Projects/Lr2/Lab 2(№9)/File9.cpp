//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <math.h>
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
int G,p,f,n;
cout<<"G=";
cin>>G;
cout<<"p=";
cin>>p;
 f=p-G;
 n=f%10;
 switch(n)
 {
	 case 1: cout<<f<<" ���";break;
	 case 2: cout<<f<<" ����";break;
	 case 3: cout<<f<<" ����";break;
	 case 4: cout<<f<<" ����";break;
	 case 5: cout<<f<<" ���";break;
	 case 6: cout<<f<<" ���";break;
	 case 7: cout<<f<<" ���";break;
	 case 8: cout<<f<<" ���";break;
	 case 9: cout<<f<<" ���";break;
	 case 0: cout<<f<<" ���";break;
 }
 getch();
	return 0;
}
//---------------------------------------------------------------------------
