//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <math.h>
#include <iostream.h>
#include <conio.h>
#include <windows.h>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
	float x,y,z,m;
cout<<"x=";
cin>>x;
cout<<"y=";
cin>>y;
cout<<"z=";
cin>>z;
  m=y+z;
	if(x>=m) cout<<"�������� ����������� ������������(x<y+z) ������  ������������ �� ����������";
	else cout<<"�������� ����������� ������������(x<y+z) ����� �����������  ����������";
	getch();
	return 0;
}
//---------------------------------------------------------------------------
