//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream.h>
#include <windows.h>
#include <conio.h>
#include <cstring>
//---------------------------------------------------------------------------

#pragma argsused

int _tmain(int argc, _TCHAR* argv[])
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
   int a;
   int strlength;
   char text[]= "1. ���������� ��������� �� ������ �� ����������, ���� �������� ��������� ������ �����. 2. � ������ ����� �������� ����� �������� ��������� ����������,";
   // ����� ������� ����� �� ��������� � ������ �����. 3. � ������ ������ ����� �������� �� ������� � ��������. 4. � ������ ����� ���������� ������� �������� ���������. 5. ����� ������� ����� ������, ��������������� �������� ����������, �������� ��������� ������.";
		 cout<<"�������� �����: "<<text;
		   cout<<"\n������� ����� �����: ";
		   cin>>a;

			char *strText=new char[strlen(text)+1];
			strcpy(strText,text);
			char * pch = strtok (text," ,.-");
			char * strx;
			char *symbol=new char[2];
			char *sFind;
			while (pch != NULL)
			{
			  strlength=strlen(pch);
			  if(strlength==a)
			  {
				  symbol[0]=pch[0];
				  symbol[1]='\0';
				  strx=strpbrk(symbol,"����������������������������������������");
				  if(strx!=NULL)
				  {
					  cout<<"��������� �����: "<<pch<<endl;
					  sFind=strstr(strText,pch);
					  if(sFind!=NULL)
					  {
						int aS=sFind-strText;
						memmove(&strText[aS],&sFind[strlen(pch)+1],strlen(sFind));
					  }

				  }
			  }
			  pch = strtok (NULL, " ,.-");
			}

	cout<<"��������� �������: "<<strText;
	getch();
	return 0;
}


//---------------------------------------------------------------------------
