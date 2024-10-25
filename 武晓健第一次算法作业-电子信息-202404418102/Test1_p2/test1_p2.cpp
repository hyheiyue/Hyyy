#include<stdio.h>
const int ROW = 3;
const int LINE = 5;
void print_num(int* a)
{       for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(a + j));
		}printf("\n");
		for(int j=5;j<10;j++) 
		{
			printf("%d ", *(a + j));
		}printf("\n");
		for(int j=10;j<15;j++) {
			printf("%d ", *(a + j));
		}printf("\n");
}
void find_max(int* a) 
{
	int max = *a;
	for (int j = 0; j < 15; j++)
	{
		if (*(a + j) > max) 
		{
			max = *(a + j);
		}
	}printf("最大值为%d\n", max);
}
void sort(int* a)
{
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 4; i++)
		{
			int tem = *a;
			if (*(a + i) > *(a + i + 1))
			{
				tem = *(a + i);
				*(a + i) = *(a + i + 1);
				*(a + i + 1) = tem;
			}
		}for (int i = 5; i < 9; i++)
		{
			int tem = *a;
			if (*(a + i) > *(a + i + 1))
			{
				tem = *(a + i);
				*(a + i) = *(a + i + 1);
				*(a + i + 1) = tem;
			}for (int i = 10; i < 14; i++)
			{
				int tem = *a;
				if (*(a + i) > *(a + i + 1))
				{
					tem = *(a + i);
					*(a + i) = *(a + i + 1);
					*(a + i + 1) = tem;
				}
			}
		}


	}
	printf("每行排序后的数组为:\n");
	print_num(a);
}
void search_row(int a[][5],  int m, int n)
{printf("输入一个数字以查找，输入不在数列的数可退出系统\n");
	int key;
	scanf("%d", &key);
	int p = 0;
	int key2=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[i][j] == key)
			{
				key2 = a[i][j];
				m = i+1;
				n = j+1;
				p = 1;
			
			}
		}
	}if (p == 0) {
		printf("未找到该数结束系统\n");
	}
	else
	{
		printf("找到%d了,在第%d行,第%d列\n", key2, m, n);
		search_row(a,m,n);
	}
	
	
}

	int main()
{
	int num[ROW][LINE] = { 2,4,3,5,1,6,8,9,7,10,14,15,12,11,13 };
	int* c = &num[0][0];
	printf("原数组为\n");
	print_num(c);
	find_max(c);
	sort(c);
	
	int m = 0;
	int n = 0;
	search_row(num, m, n);
	
}
	
