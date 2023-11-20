#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    setlocale(0, "ru");
    cout << "Введите число: ";

    int count, ostatok;
    string res = " ";
    cin >> count;

    while (count != 0)
    {
        ostatok = count % -10;
        count = count / -10;

        if (ostatok < 0)
        {
            ostatok += 10;
            count++;
        }

        res = to_string(ostatok) + res;
    }

    if (count == 0)
    {
        cout << "Введите другое число" << endl;
    }

    cout << "Ваш результат = " << res << endl;

    return 0;
}
