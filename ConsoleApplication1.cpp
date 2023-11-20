#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	Zapros:
	cout << "Введите семизначное число из чисел 0 и 1" << endl;
	string cnt; cin >> cnt;

	if (cnt.length() > 7 || cnt.length() < 7)
	{
		cout << "Число не является семизначным" << endl;
		goto Zapros;
	}

	try
	{
		int count = stoi(cnt);
		int check1 = count / 1000000 % 10;
		int check2 = count / 100000 % 10;
		int check3 = count / 10000 % 10;
		int check4 = count / 1000 % 10;
		int check5 = count / 100 % 10;
		int check6 = count / 10 % 10;
		int check7 = count % 10;
		int arr[7] = { check1, check2, check3, check4, check5, check6, check7 };
		string arr2[7] = { "r1", "r2", "i1", "r3", "i2", "i3", "i4" };

		for (int i = 0; i < 7; i++)
		{
			if (arr[i] > 1 || arr[i] < 0)
			{
				cout << "Ввод не соответствует требованиям" << endl;
				goto Zapros;
			}
		}

		int a1 = check1 + check3 + check5 + check7;
		int a2 = check2 + check3 + check6 + check7;
		int a4 = check4 + check5 + check6 + check7;
		int arr3[3] = { a1, a2, a4 };

		for (int i = 0; i < 3; i++)
		{
			if (arr3[i] % 2 == 0)
			{
				arr3[i] = 0;
			}
			else
			{
				arr3[i] = 1;
			}
		}

		if (a1 % 2 == 0 && a2 % 2 == 0 && a4 % 2 == 0)
		{
			cout << "Ошибок не обнаружено" << endl;
			goto Zapros;
		}

		string res_all = to_string(a4) + to_string(a2) + to_string(a1);

		int dNum = 0;
		int power = 1;

		for (int i = res_all.length() - 1; i >= 0; i--)
		{
			if (res_all[i] == '1')
			{
				dNum += power;
			}
			power *= 2;
		}

		if (dNum == 0)
		{
			dNum = dNum;
		}

		else
		{
			dNum -= 1;
		}

		cout << "Обнаружена ошибка в элементе: " << arr2[dNum] << endl;

		if (arr[dNum] == 0)
		{
			arr[dNum] = 1;
		}

		else
		{
			arr[dNum] = 0;
		}

		cout << "Исправленый код выглядит так: ";

		for (int i = 0; i < 7; i++)
		{
			cout << arr[i] << "";
		}

		cout << "\nИнформационные биты: ";
		cout << arr[2] << arr[4] << arr[5] << arr[6];
	}

	catch (const invalid_argument&)
	{
		cout << "Ошибка! Введены символы, а не число." << endl;
	}
};