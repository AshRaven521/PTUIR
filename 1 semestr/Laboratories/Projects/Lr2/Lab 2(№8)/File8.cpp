 //---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

  int N,k,m,f;
cout<<"N=";
cin>>N;
cout<<"k=";
cin>>k;
m=N+k;
f=m%10;
switch(f)
 {
	 case 1: cout<<m<<" �����";break;
	 case 2: cout<<m<<" �����";break;
	 case 3: cout<<m<<" �����";break;
	 case 4: cout<<m<<" �����";break;
	 case 5: cout<<m<<" ������";break;
	 case 6: cout<<m<<" ������";break;
	 case 7: cout<<m<<" ������";break;
	 case 8: cout<<m<<" ������";break;
	 case 9: cout<<m<<" ������";break;
	 case 0: cout<<m<<" ������";break;

 }

 getch();
	return 0;
}
//---------------------------------------------------------------------------
