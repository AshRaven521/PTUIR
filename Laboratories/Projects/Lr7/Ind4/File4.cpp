//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
//---------------------------------------------------------------------------

#pragma argsused
char *sum(char*,char*);
char *sub(char*,char*);
int perevodvint(char);
char *sameznach(char*);
char perevodvchar(int);
int sravnenie(char *,char *);
int _tmain(int argc, _TCHAR* argv[])
{
//������� �������� � �������� �� ���� ����� � -;
//��������� ��� �������� ���������;
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
char str1[9];
char str2[9];
char *dec;
char *bec;
char x1[9],x2[9],x3[9],x4[9];
char* sumR;
char* subR;
char y1[9],y2[9];
int bigg;
char z1[9];
char z2[9];
bool bz1=false,bz2=false;
cout<<"������� ������ ����� � ���������������� ������� ��������� :";
cin>>str1;
cout<<"������� ������ ����� � ���������������� ������� ��������� :";
cin>>str2;
int g=0;
int v=0;
	while(str1[g]!='\0')
			{
			  if(str1[0]=='-')
				{
					bz1=true;
					z1[g]=str1[g+1];
				}
			  else
				{
				   z1[g]=str1[g];
				}
				g++;
			}
	z1[g]='\0';
	while(str2[v]!='\0')
			{
			  if(str2[0]=='-')
				{
					bz2=true;
					z2[v]=str2[v+1];
				}
			  else
				{
				   z2[v]=str2[v];
				}
				v++;
			}
	z2[v]='\0';

  bigg=sravnenie(z1,z2);
	if(bigg==0 || bigg==2)
	  {
		int i=0;
		  while(z1[i]!='\0')
			{
			   y1[i]=z1[i];
			   i++;
			}
		y1[i]='\0';
		int j=0;
		  while(z2[j]!='\0')
			{
				y2[j]=z2[j];
				j++;
			}
		y2[j]='\0';
	  }
	if(bigg==1)
	  {
		int i=0;
		  while(z2[i]!='\0')
			{
			   y1[i]=z2[i];
			   i++;
			}
		y1[i]='\0';
		int j=0;
		  while(z1[j]!='\0')
			{
				y2[j]=z1[j];
				j++;
			}
		y2[j]='\0';
	  }
  dec=sameznach(y1);
  for(int f=0;f<9;f++)
	x1[f]=dec[f];
  bec=sameznach(y2);
  for(int f=0;f<9;f++)
	x2[f]=bec[f];



	sumR=sum(x1,x2);
	int k=0;
	for(int f=0;f<9;f++ )
	{
		if(sumR[f]!='0')
		{
			x3[k]=sumR[f];
			k++;
		}
	}

subR=sub(x1,x2);
	int m=0;
	char ss='0';
	for(int e=0;e<9;e++)
	{
		if(subR[e]!=ss)
		{
			x4[m]=subR[e];
			m++;
			ss='q';
		}
	}

	if(!bz1 && !bz2)
	{
		cout<<"\n��������� �������� :"<<x3;
		if(bigg==1)
		  cout<<"\n��������� ��������� :-"<<x4;
		else
		  cout<<"\n��������� ��������� :"<<x4;
	}

	if(bz1 && bz2)
	{
		cout<<"\n��������� �������� :-"<<x3;
		if(bigg==1)
		  cout<<"\n��������� ��������� :"<<x4;
		else
		  cout<<"\n��������� ��������� :-"<<x4;
	}

	if(!bz1 && bz2)
	{
		if(bigg==1)
			cout<<"\n��������� �������� :-"<<x4;
		else
			cout<<"\n��������� �������� :"<<x4;
		//if(bigg==1)
		  cout<<"\n��������� ��������� :"<<x3;
		//else
		//  cout<<"\n��������� ��������� :-"<<x3;
	}

	if(bz1 && !bz2)
	{
		if(bigg==1)
			cout<<"\n��������� �������� :"<<x4;
		else
			cout<<"\n��������� �������� :-"<<x4;
		//if(bigg==1)
		  cout<<"\n��������� ��������� :-"<<x3;
		//else
		//  cout<<"\n��������� ��������� :"<<x3;
	}


	getch();
	return 0;
}
  char *sum(char str1x[9],char str2y[9])
	{
		char result[9]="00000000\0";
		for(int i=7;i>0;i--)
		  {
			  int a=perevodvint(str1x[i]);
			  int b=perevodvint(str2y[i]);
			  int r=a+b;
				if(result[i]=='1')
				  {
					  r=r+1;
				  }
				if(r>=12)
				  {
					r=r-12;
					result[i-1]='1';
				  }
			  result[i]=perevodvchar(r);
		  }
	  return result;
	}
  int perevodvint(char x)
	{
		int a=0;
		switch(x)
		  {
			  case 'A': a=10;break;
			  case 'B': a=11;break;
			  default : a=x-'0';break;
		  }
		return a;
	}

	char *sameznach(char strx[9])
	  {
	   char str1n[9]="00000000\0";
	   int i=0;
		while(strx[i]!='\0')
		  {
			  i++;
		  }
		   int	k=i-1;
		   for(int j=7;j>0;j--)
			 {
			   if(k>=0)
				  {
					str1n[j]=strx[k];
				  }
				k--;
			 }
		 return str1n;
	  }

	  char  perevodvchar(int rR)
	{
		char b;
		switch(rR)
		  {
			  case 10: b='A';break;
			  case 11: b='B';break;
			  default : b=rR+'0';break;
		  }
		return b;
	}

	  char *sub(char str1x[9],char str2y[9])
		{
		   char result[9]="00000000\0";
			 for(int i=7;i>0;i--)
			   {
				 int a=perevodvint(str1x[i]);
				 int b=perevodvint(str2y[i]);
				 int r=a-b;
				   if(result[i]=='9')
					 {
					   r=r-1;
					 }
				   if(r<0)
					 {
					   r=r+12;
					   result[i-1]='9';
					 }
				 result[i]=perevodvchar(r);
			   }
			return result;
		}

		int sravnenie(char *str1x,char *str2y)
		  {
			int i=0;
			int j=0;
			int result=2;
			  while(str1x[i]!='\0')
				{
				  i++;
				}
			  while(str2y[j]!='\0')
				{
				  j++;
				}
			  if(i>j)
				{
					result=0;
				}
			  else
				if(i<j)
				  {
					  result=1;
				  }
			  else
				{
				   for(int p=0;p<i;p++)
					 {
						 if(str1x[p]>str2y[p])
						   {
							   result=0;
						   }
						 if(str1x[p]<str2y[p])
						   {
							   result=1;
						   }
					 }
				}
			  return result;
		  }
//---------------------------------------------------------------------------
