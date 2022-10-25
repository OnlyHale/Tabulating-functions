/*******************************************************************************************                                                                                                   *Project Name : Laba1                                                                                  *
*Project Name : Laba2                                                                      *
File Name     : LabaTabulirovanie.cpp                                                      *
*Language     : CPP,MSVS ver 2015 and above                                                *
*Programmers  : Ратников Роман Олегович,Фицайло Александр Александрович, группа:М3О-110Б-20*
*Modified By  :                                                                            *
*Created      : 29/10/2020                                                                 *
*Last Revision: 12/11/2020                                                                 *
*Comment      : Табулирование функций                                                      *
********************************************************************************************/
#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>
int main()
{
	setlocale(LC_ALL, "Russian");// Русский язык в консоли
	system (" color F0");        // Изменение фона консоли
	double x;                    // Аргумент
	double A;                    // Начало отрезка
	double B;                    // Конец отрезка
	double Bufer;                // Переменная для сохранения данных
	double N;                    // Число интервалов 
	int i;                       // Параметр цикла
	double h;                    // Шаг
	double FX;                   // Функция F(x)
	double GX;                   // Функция G(x)
	string Line;
	string BigLine;
	cout << "Введите,пожалуйста,A и B " << endl;     
	cin >> A >> B;                                 //Ввод значений
	cout <<"A = "<< A<<" "<< "B = "<< B << endl;   //Эхо-печать
	if (A > B)
	{   // Изменение вводных данных
		cout << "Ошибка.Поменяем значения между собой."<<endl;
			Bufer = A;   // Сохранилось А
		    A = B;       // Изменилось A		
			B = Bufer;   // "B" присвоено сохранённое значение A
    }
	if (A == B)   // Проверка на совпадение точек
	{ 
		N = 0;
		h = 0;
	}
	else
	{   // Если не совпало, то принимаем ввод N
		cout << "Введите N" << endl;
		cin >> N;
		cout <<"N = "<< N <<endl;           // Эхо-печать
		if (N >= 1 and N- int(N)== 0)       // Проверка на целое и натуральное значение N
			h = (B - A) / N;                // Вычисление шага
		else
		{
			cout << "Ошибка.N должно быть целым и не меньше 1 ";
			return 0;
		}
	}
	setlocale(0,"C");//Отключение русского языка в консоли 

	
	Line = char(196);     // 1 линия
	BigLine = Line+Line+Line;  // 3 линии
	BigLine = BigLine + BigLine + BigLine + Line;  //10 линий
	cout <<"\t"<< char(218) << BigLine << char(194) << BigLine << char(194)<<BigLine<<char(191)<<endl;
	cout << "\t" << char(179) << "    X     " << char(179) << "   F(X)   " << char(179) << "   G(X)   " << char(179)<<endl;   //Шапка таблицы
	cout << "\t" << char(195) << BigLine << char(197) << BigLine << char(197) << BigLine << char(180) << endl;                //Конец шапки таблицы
	
	
	for (int i = 0;i <= N;i++)
	{
		x = A + i * h;                               // Приращение аргумента
		FX = sqrt(x * x + 4);                        // Вычисление FX
		GX = pow(x + 5, 3) / (1 + pow(sin(x), 2));   // Вычисление GX
		cout.precision(5);                           // Ограничение по знакам после запятой
		cout << "\t" << char(179) << setw(10) << x << char(179) << setw(10) << FX << char(179) << setw(10) << GX << char(179) << endl;
		if ((i + 1) <= N)  //Проверка,нужна ли ещё строка
		{
			cout << "\t" << char(195) << BigLine << char(197) << BigLine << char(197)<<BigLine<<char(180)<<endl;
		}
		
	
	}   
	cout << "\t" << char(192) << BigLine << char(193) << BigLine << char(193) << BigLine << char(217) << endl; //Печать конца таблицы

	return 0;
}



