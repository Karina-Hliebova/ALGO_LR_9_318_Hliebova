#include <iostream>
#include <string>
#include "windows.h"
#include "insert.h"
#include "string.h"

using namespace std;


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int menu; // Зміна для номеру завдання
    do
    { // початок циклу
        cout << "Номер завдання: "; //введення номеру завдання
        cin >> menu; // обирання номеру завдання
        cout << endl; //вільна строка
        switch (menu) {
        case 1: task_1(); break; // 1 - завдання 1
        case 2: task_2(); break; // 2 - завдання 2
       // case 3: task_3(); break; // 3 - завдання 3
        case -1: cout << "Вихід..." << endl; break; // -1 - вихід
        default: cout << "Помилка! Лише 1, 2!" << endl; // інший номер - повторити
        }
        cout << endl; // вільна строка
        cout << "+---------------------+" << endl; // строка задля полегшення візуального сприймання тексту
        cout << endl; // вільна строка
    } // кінець циклу
    while (menu != -1); // умова виконання циклу
    return 0;
}