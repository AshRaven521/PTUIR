
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <iostream.h>
#include <math.h>
#include <conio.h>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
  float x,y,a,z,c,fi;
  int s;
cout<<"a=";
cin>>a;
cout<<"z=";
cin>>z;
  cout<<"c=";
cin>>c;
  cout<<" �������� �������� ������� fi (1- 2*x; 2- x2; 3- x/3): ";
  cin>>s;
  if(s!=1&& s!=2 && s!=3) cout<<"������� �����,�� ��������������� �������";
	 else {
  switch(s)
 {
  case 1: {
  cout<<" ������� �������� ������� fi=2x";
   if(z>=0) x=(2*z)+1;
   else x=log(powf(z,2)-z);
   fi=2*x; break;
  }
   case 2: {
   cout<<" ������� �������� ������� fi=x2";
   if(z>=0) x=(2*z)+1;
   else x=log(powf(z,2)-z);
  fi=powf(x,2); break;
   }
   case 3: {
   cout<<" ������� �������� ������� fi=x/3";
   if(z>=0) x=(2*z)+1;
   else x=log(powf(z,2)-z);
   fi=x/3;break;
   }

 }
 y=powf(sin(fi),2) + a*powf(cos(powf(x,3)),5) + c*log(powf(x,0.4));
 cout<<"\nx="<<x;
 cout<<"\ny="<<y;
 }
 getch();




	return 0;
}
//---------------------------------------------------------------------------
