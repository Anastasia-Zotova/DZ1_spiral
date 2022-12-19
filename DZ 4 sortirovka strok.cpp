// DZ 4 sortirovka strok.cpp: определяет точку входа для приложения.
//
// Задание
// На вход подаются строки, требуется их отсортировать


#include "DZ 4 sortirovka strok.h"
#include <vector>
#include <string>
#include <algorithm>
//setlocale(0, "rus");

using namespace std;

int main()
{
	int N;
	cin >> N;   //Задаем количество элементов
	vector<string> array;
	string a;
	for (int i = 0; i < N; i++) {
		cin >> a;           //задаем сами элементы в массив
		array.push_back(a);   //добавляем элементы
	}


	sort(begin(array), end(array)); //сортируем


	cout << endl;

	for (auto n : array){      //выводим
		cout << n << endl;
	}

	return 0;
}