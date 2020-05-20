#include <iostream>
using namespace std;
typedef struct
{
	float benefit;
	int A, B, C;
}Allot;
void AddChoice(Allot *Fx, float **temp, int stage, int n, float *fx[4])   //stage��ʾ��ǰΪ�ڼ��׶�
{
	int i, j;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= i; j++)
			temp[i][j] = fx[stage][j] + Fx[i - j].benefit;
}
void Updata(Allot *Fx, Allot *fore, int stage, int i, int j, int n)  //���¸�����Ŀ���ʽ�������
{
	int t;
	if (stage == 2)
	{
		Fx[i].B = j; Fx[i].A = i - j; Fx[i].C = 0;
	}
	else if (stage == 3)
	{
		Fx[i].C = j;
		t = i - j;
		Fx[i].A = fore[t].A; Fx[i].B = fore[t].B;
	}
}
void Findmax(Allot *Fx, float **temp, int stage, int n)       //���µ�ǰ�������
{
	int i, j, pos, t;
	Allot fore[10000];
	for (t = 0; t <= n; t++)
		fore[t] = Fx[t];     //��¼��һ�׶θ�����Ŀ�ķ������
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (temp[i][j] >= Fx[i].benefit)
			{
				Fx[i].benefit = temp[i][j];
				pos = j;
			}
		}
		Updata(Fx, fore, stage, i, pos, n);
	}
}
int main()
{
	Allot *Fx;
	char project = 'A';
	float *fx[4], **temp;
	int n, i, j, fund;            //һ����Ŀ���ֶ���
	cout << "������������ʽ�:";
	cin >> n;
	for (i = 0; i <= 3; i++)      //��Ÿ������������
		fx[i] = new float[n + 1];
	cout << "��������ĿA��B��C������Ŀ�ķ�������(��������0ʱ):" << endl;
	for (i = 1; i <= 3; i++)
	{
		cout << "��Ŀ" << char(project + i - 1) << ":";
		for (j = 0; j <= n; j++)
			cin >> fx[i][j];
	}
	Fx = new Allot[n + 1];      //��ŵ�ǰ�������ķ��䷽��
	for (i = 0; i <= n; i++)      //��һ�׶Σ������е���Դ�������A��Ŀ��
	{
		Fx[i].benefit = fx[1][i]; Fx[i].A = i; Fx[i].B = Fx[i].C = 0;
	}
	temp = new float *[n + 1];
	for (i = 0; i <= n; i++)
		temp[i] = new float[n + 1];
	for (i = 2; i <= 3; i++)             //�׶ζ�����
	{
		AddChoice(Fx, temp, i, n, fx);
		Findmax(Fx, temp, i, n);
	}
	cout << "\n������Ͷ�ʵĽ��:";
	cin >> fund;
	cout << "�ɻ���������:" << Fx[fund].benefit << "\n������Ŀ�ʽ����:   A:" << Fx[fund].A << "   B:" << Fx[fund].B << "   C:" << Fx[fund].C << endl;
	return 0;
}