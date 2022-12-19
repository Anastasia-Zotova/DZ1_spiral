// DZ 3 unikalno.cpp: определяет точку входа для приложения.
//
//ЗАДАНИЕ
//Подаются на вход числа
//Нужно создать вектор векторов, где в первом векторе будут уникальные числа, во втором - их количество

#include "DZ 3 unikalno.h"
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;   //Задаем количество элементов
	vector<int> array;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;           //задаем сами элементы в массив
		array.push_back(a);   //добавляем элементы
	}

	vector<int> numbers;     //новый массив для уникальных чисел
	vector<int> count;       // новый массив для количества уникальных чисел

	sort(begin(array), end(array));  //сортируем массив

	numbers.push_back(array[0]); //запоминаем первое значение массива
	count.push_back(1);

	for (int i = 1; i < N; i++) {
		int d = 0;                                 //показатель, отражающий нашлось повторение или нет
		for (int j = 0; j < numbers.size(); j++) { //проверяем, если совпадения чисел в массиве с уникальными числами
			if (array[i] == numbers[j]) {           //если нашлось вопторение
				count[j]++;                         // к количеству добавляем единичку
				d = 1;
			}
		}

		if (d == 0) {                                // если не нашлось повторения
			numbers.push_back(array[i]);            // то записываем новое число
			count.push_back(1);
		}
	}

	for (int i = 0; i < numbers.size(); i++) {        
		cout << numbers[i] << ' ' << count[i] << endl;  //выводим уникальные числа и их количество
	}
	return 0;
}