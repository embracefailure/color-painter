#include<iostream>
#define MaxVertex 100
using namespace std;


int main()
{
	int sum;
	int matrix[MaxVertex][MaxVertex];//�洢�ڽӾ���
	int color[MaxVertex] = { 0 };
	int i, j;
	cout << "����ڵ�������";
	cin >> sum;
	cout << "�����ڽӾ���(�Կո�����" << endl;
	for ( i = 0; i < sum; i++)
	{
		for (int j = 0; j < sum; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << "��������ڽӾ���Ϊ��" << endl;
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
		for (int k = 0; k < j; k++)//���ݱȽϣ�����в��׵ģ��͸���ɫֵ��1��ֱ��ѭ������
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
	cout << "��ɫ�����ǣ�" << endl;
	for (i = 0; i < sum; i++)
	{
		cout << color[i] << " ";
	}
}