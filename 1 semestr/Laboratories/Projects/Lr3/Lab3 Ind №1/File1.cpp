//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
  int i=1,p,n,m,f;
  float s=0,y=0,x;
cout<<"������� ���������� ������ ����:";
cin>>n;
   cout<<"������� ���������� �����:";
   cin>>p;
		   while(i<=p)
		{
			cout<<"������� "<<"x"<<i<<":";
			cin>>x;
		  if(x>=0.1 && x<=1)
		{
			i++;
			m=0;
			s=0;
			f=1;
			   while (m<=n-1)
			 {
				 s= s + pow(2*x,m) / f;
				 m++;
				 f*=m;

			 }
				 y=exp(2*x);
				 cout<<"S(x)="<<s<<"\tY(x)="<<y<<endl;
			 }
			   else cout<<"��������� x �� ������ � ������ �������� (0.1 �� 1)\n";
		}
		getch();
	return 0;
}
//---------------------------------------------------------------------------
