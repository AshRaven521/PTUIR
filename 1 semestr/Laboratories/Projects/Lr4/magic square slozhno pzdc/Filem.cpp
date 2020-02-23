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
int _tmain()
{
		int i,j, n;
		int count = 0;
		int row, colum;
		bool chetno = false;
		cout<<("Input size( > 2): \n");
		scanf("%d",&n);
		int** matrix = new int*[2*n-2];
		for (j = 0; j < 2*n-2; j++)
				{
				matrix[j] = new int[n];
				}
		if(n%4 == 2)          //для построения четно-четного порядка 2k(!!!!не 4k)
				{             //первоначально нужно построить n-2 - которая 4k
				n = n - 2;
				chetno = true;
				}
		if(n%4 == 0)    //построение четно-четного порядка методом квадратных рамок
				{
				 bool po4as = true;              // направление заполнения
				 int sm = 0;
						while (sm + 1 < n)    //пока не пройдем всю матрицу)  +2
								{
								if(po4as == true)
										{
										row = (n/2) - 1 + sm; // стартовые значения для почасовой
										colum = 0;
										while(count%(2*n)!= 1)
												{
												count = 1+n*sm;
												matrix[row][colum] = count++;
												while(count%(n/2) != 1)
														{
														row--;
														colum++;
														matrix[row][colum] = count++;
														}
												matrix[row][++colum] = count++;
												while(count%(n/2) != 1)
														{
														row++;
														colum++;
														matrix[row][colum] = count++;
														}
												matrix[++row][colum]= count++;
												while(count%(n/2) != 1)
														{
														row++;
														colum--;
														matrix[row][colum] = count++;
														}
												matrix[row][--colum] = count++;
												while(count%(n/2) != 1)
														{
														row--;
														colum--;
														matrix[row][colum] = count++;
														}
												po4as = false;
												}
										sm += 2;
										}
								if(po4as == false)
										{
										row =  (n/2) - 1 + sm;       // стартовые значения для непочасовой
										colum = n - 1;
										while(count%(2*n)!= 0)
												{
												//count -= 1;
												matrix[row][colum] = count++;
												while(count%(n/2) != 1)
														{
														row--;
														colum--;
														matrix[row][colum] = count++;
														}
												matrix[row][--colum] = count++;
												while(count%(n/2) != 1)
														{
														row++;
														colum--;
														matrix[row][colum] = count++;
														}
												matrix[++row][colum]= count++;
												while(count%(n/2) != 1)
														{
														row++;
														colum++;
														matrix[row][colum] = count++;
														}
												 matrix[row][++colum] = count++;
												 while(count%(n/2) != 1)
														{
														row--;
														colum++;
														matrix[row][colum] = count++;
														}
												count -= 1;
												po4as = true;
												}
										sm += 2;
										}
								}
		for(i = 0; i < n/2 - 1; i++)
				for(j = 0; j < n; j++)
						{
						if(matrix[i][j]!= 0)
								matrix[i+n][j] = matrix[i][j];
						}
		for(i = n + n/2 - 1; i < 2*n - 2; i++ )
				for(j = 0; j < n; j++)
						{
						if(matrix[i][j]!= 0)
								matrix[i-n][j] = matrix[i][j];

						}
		if (chetno != true)          // не будет выводить и очищать
		{                            // если пригодится дальше
		for(i = n/2 - 1; i < n + n/2 -1; i++)    // вывод
				{
				printf("\n");
				for(j = 0; j < n; j++)
						{
						printf("%d\t",matrix[i][j]);
						}
				printf("\n");
				}
		for (int i = 0; i < 2*n-2;  i++)       //культурно
				delete[] matrix[i];
				delete[] matrix;
				}
		}
				if(n%2 == 1)   //построение нечетно-нечетного порядка методом террас
						{
						count = 1;
						int** matrix1 = new int*[2*n-1];
						for (j = 0; j < 2*n-1; j++)
								{
								matrix1[j] = new int[2*n-1];
								}
						int startrow = n - 1;
						int startcolum = 0;
						while(startrow < 2*n - 1)
								{
								row = startrow;
								colum = startcolum;
								for(i = 0; i < n; i++)
										{
										matrix1[row][colum] = count++;
										row--;
										colum++;
										}
								startrow++;
								startcolum++;
								}
						for(i = 0; i < (n + 1)/2 - 1; i++)        // смещаем 4 пирамидки
								for(j = 0; j < 2*n - 1; j++)
										{
										if(matrix1[i][j]!= 0 && matrix1[i][j] <= n*n)
												matrix1[i+n][j] = matrix1[i][j];
										}
						for(i = n + (n + 1)/2 - 1; i < 2*n - 1; i++)
								for(j = 0; j < 2*n - 1; j++)
										{
										if(matrix1[i][j]!= 0 && matrix1[i][j] <= n*n)
												matrix1[i-n][j] = matrix1[i][j];
										}
						for(i = 0; i < 2*n - 1; i++)
								for(j = 0; j < (n + 1)/2 - 1; j++)
										{
										if(matrix1[i][j]!= 0 && matrix1[i][j] <= n*n)
												matrix1[i][j+n]= matrix1[i][j];
										}
						for(i = 0; i < 2*n - 1; i++)
								for(j = n + (n + 1)/2 - 1; j < 2*n - 1; j++)
										{
										if(matrix1[i][j]!= 0 && matrix1[i][j] <= n*n)
												matrix1[i][j-n]= matrix1[i][j];
										}
		for(i = (n + 1)/2 - 1; i < n + (n + 1)/2 - 1; i++)        // вывод
				{
				printf("\n");
				for(j = (n + 1)/2 - 1; j < n +(n + 1)/2 - 1; j++)
						{
						printf("%d\t",matrix1[i][j]);
						}
				printf("\n");
				}
		for (int i = 0; i < 2*n - 1;  i++)           //культурно
				delete[] matrix1[i];
				delete[] matrix1;
				}
		if(n%4 == 0 && chetno == true)            //вот!
				{
				n = n + 2;
				int** matrix2 = new int*[n];      // нужно скопировать полученную матрицу 4k
				for (j = 0; j < n; j++)           // и по-умному расставить числа
						{
						matrix2[j] = new int[n];
						}
				for(i = 1; i < n - 1; i++)
						{
						for(j = 1; j < n - 1; j++)
								{
								matrix2[i][j] = matrix[i + (n-2)/2 - 2][j-1] + 2*(n - 1);   // add 2*(n-1)
								}
						}
		//удаление matrix
				for (int i = 0; i < 2*n-2;  i++)
						delete[] matrix[i];
						delete[] matrix;

				matrix2[0][0] =  3*(n/2) - 1;
				matrix2[0][n-1] = 1;
				matrix2[n-1][n-1] = n*n + 2 - (3*n)/2;
				matrix2[n-1][0] = n*n;
				i = 1;
				//---------------
				for(j = 1; j < n - 1; j++)                      //дополнение верхней строки
						{
						if (i <= n/2 - 2)
								{
								matrix2[0][j++] = 2*i + 1;
								}
						matrix2[0][j] = n*n + 1 - 2*i;
						i++;
						}
				matrix2[1][0] = n - 1;
				i = 1;
				int q = 1;
				for(j = 2; j < n - 1; j++)                       // левый столбец
						{

						while(i <= n/4)
								{
								matrix2[j++][0] = (3*n)/2 - 1 - i;
								i++;
								}
						i = 1;
						while(i <= n/4 + 1)
								{
								matrix2[j++][0] = n*n + 2 - 2*n + i;
								i++;
								}
						i = 1;
						while (i <= n/4 - 1)
						{
										matrix2[j++][0] = (3*n)/2 - 1 + q;
										matrix2[j][0] = n*n + 1 - n - q++;
								i++;
								j++;
						}
						//i++;
						}
				// добавление чисел в нижнюю строку и правый столбец
				for(j = 1; j < n - 1; j++)
						matrix2[n-1][j] = n*n + 1 - matrix2[0][j];          //комплементарные числа

				for(i = 1; i < n - 1; i++)
						matrix2[i][n-1] = n*n + 1 - matrix2[i][0];

				for(i = 0; i < n; i++)
						{
						printf("\n");
						for(j = 0; j < n; j++)
								{
								printf("%d\t",matrix2[i][j]);
								}
						printf("\n");
						}
				for (int i = 0; i < n;  i++)            //культурно
						delete[] matrix2[i];
						delete[] matrix2;
			 }
		getch();

}
//---------------------------------------------------------------------------
