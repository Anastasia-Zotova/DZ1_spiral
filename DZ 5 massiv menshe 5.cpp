// DZ 5 massiv menshe 5.cpp: определяет точку входа для приложения.
//Задача на тему new, delete. 
// Нужно отформатировать список, в который мы вводим с клавиатуры, 
// в созданном новом массиве удалить числа меньше 5. 
//ГЛАВНОЕ: задача должна быть решена без использования вектора.

#include "DZ 5 massiv menshe 5.h"

using namespace std;

#include <iostream>


pair<int*, int> full_array(int numb){ //заполняем массив
    int* p_arr = new int[numb];
    int size = 0;
    int a;
    cin >> a;
    while (a != 0 && size < numb){
        *(p_arr + size) = a;
        cin >> a;
        ++size;
    }
    return make_pair(p_arr, size);
}

pair<int*, int> delite_five(int* p_arr, int size){ //записываем значения в новый массив
    int* p_arr2 = new int[size];
    auto size2 = 0;
    for (auto i = 0; i < size; ++i){
        if (*(p_arr + i) > 4){
            *(p_arr2 + size2) = *(p_arr + i);
            ++size2;
        }
    }
    return make_pair(p_arr2, size2);
}

int main(){
    auto numb = 100000;
    auto arr = full_array(numb);
    for (auto i = 0; i < arr.second; ++i){
        cout << *(arr.first + i) << " ";
    }

    auto p_arr2 = delite_five(arr.first, arr.second);
    cout << endl;
    for (auto i = 0; i < p_arr2.second; ++i){
        cout << *(p_arr2.first + i) << " ";
    }

    delete[] arr.first;
    delete[] p_arr2.first;
    return 0;
}

