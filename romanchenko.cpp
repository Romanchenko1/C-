#include<iostream>
#include<locale.h>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
void filling()
{
	ifstream fin("text.txt");
	ofstream fout1("text1.txt");
	ofstream fout("text.txt");
	char array[100];
	for (int i = 0; i < 10; i++)
	{
		cin.getline(array, 100);
		fout << array << endl;
	}
	while (fin >> array)
	{
		if (strlen(array) >= 10)
			fout1 << array << " ";
	}
}

//1.��� ��������� ����. ���������� ������� ����� ���� � �������� � ���� ��������� ���������� �� ��������� �����:
//	���������� ��������
//	���������� �����
//	���������� ������� ����
//	���������� ��������� ����
//	���������� ����.

void task1()
{
	ifstream fin("text.txt");
	ofstream fout("text.txt");
	char array[100];
	int e = 0;
	int simvol = 0;
	int strok;
	filling();
	for (int i = 0; i < 10; i++)
	{
		fin >> array;
		e = strlen(array);
			simvol = e;
			strok = i;
	}
	char glas[] = "aeiouy";
	char ch;
	int glasnoe = 0;
	int soglasnoe = 0;
	for (int i = 0; i <= strlen(array); i++)
	{
		for (int j = 0; j <= strlen(glas); j++)
		{
			if (array[i] == glas[j])
			{
				glasnoe++;
			}
			else
			{
				soglasnoe++;
			}

		}

	}
	char c[] = "123456789";
	int cif = 0;
	for (int i = 0; i <= strlen(array); i++)
	{
		for (int j = 0; j <= strlen(c); j++)
		{
			if (array[i]==c[j])
			{
				cif++;
			}
		}
	}
	fout << "��������:" << simvol << endl;
	fout << "�����:" << strok << endl;
	fout << "�������:" << glasnoe << endl;
	fout << "���������:" << soglasnoe << endl;
	fout << "����:" << cif << endl;
	fin.close();
	fout.close();
}

//2.���� ������ � ���� �� ���������� ������.
//��� ���������� ������ ������ ���������� ������, ��������� �� ���� � �������� �� ������������� ����� �������.
//������
//���������� � �������������� ����� : 3
//������������ ����� : ����� �� ��� ���� ������ ����������� �����, �� ����� ���.
//����������� ����� : ����� �� ��� ���� ����� ����������� �����, �� ����� ���.
//��� ��������� ����.����������� ���, ��������� ���� ������.��������� �������� � ������ ����
void task2()
{
	ifstream fin("text.txt");
	ofstream fout("text.txt");
	int k = 3;
	char array[100];
	cin >> array;
	char final = 'z' - k + 1;

	for (int i = 0; i < strlen(array); i++)
	{
		if (array[i] < final)
		{
			array[i] += k;
		}
		else 
		{
			array[i] = 'a' + array[i] - final;
		}
	}
	fout << "����:" << array << endl;
	char s = 'a' + k - 1;
	for (int i = 0; i < strlen(array); i++)
	{
		if (array[i] > s)
		{
			array[i] -= k;
		}
		else
		{
			array[i] = 'z' - array[i] + s;
		}
	}
	fout <<"�����������:"<< array << endl;
	
}
int main()
{
	setlocale(LC_ALL, "");
	int task;
	int flag;
	do
	{
		cout << "������� ����� �������";
		cin >> task;
		switch (task)
		{
		case 1: task1(); break;
		case 2: task2(); break;

		default:
			break;
		}
		cout << "����� ���������� ������� 1" << " ";
		cin >> flag;
	} while (flag == 1);
	system("pause");
}