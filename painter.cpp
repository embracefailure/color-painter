#include<iostream>
#define MaxVertex 100
using namespace std;


int main()
{
	int sum;
	int matrix[MaxVertex][MaxVertex];//存储邻接矩阵
	int color[MaxVertex] = { 0 };
	int i, j;
	cout << "输入节点总数：";
	cin >> sum;
	cout << "输入邻接矩阵：(以空格间隔）" << endl;
	for ( i = 0; i < sum; i++)
	{
		for (int j = 0; j < sum; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << "您输入的邻接矩阵为：" << endl;
	for (i = 0; i < sum; i++)
	{
		for (int j = 0; j < sum; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
	for (i = 0; i < sum; i++)
	{
		for ( j = 0; j < i; j++)
		{
			if (matrix[i][j] == 0)
			{
				color[i] = color[j];
				break;
			}
		}
		if (j == i&&i>=1 )
		{
			color[i] = color[i - 1] + 1;
		}
		for (int k = 0; k < j; k++)//回溯比较，如果有不妥的，就给颜色值加1，直到循环结束
		{
			if (matrix[i][k] == 1)
			{
				if (color[i] == color[k])
				{
					color[i]++;
				}
			}
		}
	}
	cout << "颜色方案是：" << endl;
	for (i = 0; i < sum; i++)
	{
		cout << color[i] << " ";
	}
}