// DZ 2 opredelitel.cpp: определяет точку входа для приложения.
//
// ЗАДАНИЕ
//считаем определитель у матрицы произвольного размера, квадратной, заполнена случайно.

#include "DZ 2 opredelitel.h"
using namespace std;
#include <iostream>
#include <vector>
#include <ctime>


vector<vector<int>> delite_stroke(vector<vector<int>> A, int a, int b){  //функция для удаления ненужных строк и столбцов
	vector<vector<int>> B(size(A) - 1, vector<int>(size(A) - 1)); //создаю новую матрицу на размерность меньше
	for (int i = 0; i < size(A); ++i){
		int x = 0;
		if (i < a) { x = i; }
		if (i > a) { x = i - 1; }
		for (int j = 0; j < size(A); ++j){
			int y = 0;
			if (j < b) { y = j; }
			if (j > b) { y = j - 1; }

			B[x][y] = A[i][j];
		}
	}
	return B;
}

int opredelitel(vector<vector<int>> A){   // считаю определитель матрицы
	if (size(A) == 2){                    // считаю минор
		return A[0][0] * A[1][1] - A[0][1] * A[1][0];
	}

	int sum = 0;
	for (int i = 0; i < size(A); ++i){    
		sum += opredelitel(delite_stroke(A, 0, i)) * A[0][i] * pow(-1, i);  //функция для подсчета определителя любых рангов
	}
	return sum;
}


int main() {
	srand(time(NULL));    //рандомайзер работает от времени
	int n;
	cin >> n; //ввожу размерность матрицы
	vector<vector<int>> A(n, vector<int>(n));  //создаю матрицу размерностью n
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = rand() % 10;         // заполняю матрицу случайными значениями от 0 до 9
		}
	}

	for (auto m : A) {          //вывод матрицы
		for (auto k : m) {
			cout << k << ' ';
		}
		cout << endl;
	}
	cout << opredelitel(A);      //вывод определителя
	return 0;
}


