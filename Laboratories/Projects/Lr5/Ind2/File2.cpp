//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
//---------------------------------------------------------------------------

#pragma argsused

int _tmain(int argc, _TCHAR* argv[])
{
	bool h=true;

 //����� DLL ����������
  HINSTANCE load;
  load=LoadLibrary("MyDLL.dll");
 //��������� ��������� �� �������
 //pfspectr-������������ ���
  typedef bool (_stdcall *pfspectr) (int,int,int *);
  pfspectr calculate;
  calculate=(pfspectr)GetProcAddress(load,"calculate");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
  const int N=6;

	   int X[N]={2,-7,12,94,-71,9};
			h=calculate(1,0,X);
			h=calculate(5,2,X);
	  if(h)
		 cout<<"��� ���� ��������� ������� ������� ������ ����";
	  else
		 cout<<"�� ��� ���� ��������� ������� ������� ������ ����";
	 //������������ DLL
	   FreeLibrary(load);
	getch();
	return 0;
}
//---------------------------------------------------------------------------
