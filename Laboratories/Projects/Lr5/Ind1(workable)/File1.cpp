//---------------------------------------------------------------------------

//#pragma hdrstop

//#include <tchar.h>
//#include <math.h>
#include <iostream.h>
#include <conio.h>
#include <windows.h>
#include "jopa.h"
//---------------------------------------------------------------------------

//#pragma argsused
   //int sum(int **array,int,int);
   //void c(int,int);
int _tmain(int argc, _TCHAR* argv[])
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
	 int n,m,i,j,min=1000000;

   cout<<"������� ����������� ������� n=";
   cin>>n;
   cout<<"������� ����������� ������� m=";
   cin>>m;
	 int **mas = new int *[n];
			for (i=0; i < m; i++)
			{
			   mas[i]=new int [m];
			}
	 int *S = new int [m];

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			 {
			   cout<<"������� ������� a["<<i<<"]""["<<j<<"]=";
			   cin>>mas[i][j];
			 }
		}

		 cout<<"\n�������� �������:";
		 cout<<"\n";

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			 {

				 cout<<mas[i][j]<<" ";
			 }
				 cout<<"\n";
		}
			   cout<<"\n";
				for(j=0;j<m;j++)
				 {
					S[j]=0;
					S[j]=sum( mas,n,j);
					cout<<"S["<<j<<"]""="<<S[j]<<" ";
				 }
		min=cMin(S,m);
			  cout<<"\nmin="<<min;




 for (int i = 0; i < m; i++)
{
  delete []mas[i];
}
delete []mas;
delete []S;
	getch();
	return 0;
}
//---------------------------------------------------------------------------
