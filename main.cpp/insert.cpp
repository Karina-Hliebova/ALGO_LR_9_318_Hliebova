#include <iostream>
#include <string>
#include "insert.h"
using namespace std;

// B. Реалізація власної функції вставки в масив символів (без функцій string.h)
void my_insert(char* dest, int pos, const char* insertStr) {
    int lenDest = 0, lenInsert = 0;

    // Довжина вихідного рядка
    while (dest[lenDest] != '\0') lenDest++;
    // Довжина вставного рядка
    while (insertStr[lenInsert] != '\0') lenInsert++;

    // Зсув елементів вправо
    for (int i = lenDest; i >= pos; --i) {
        dest[i + lenInsert] = dest[i];
    }

    // Вставка символів
    for (int i = 0; i < lenInsert; ++i) {
        dest[pos + i] = insertStr[i];
    }
}

// A + C. Виклик методу insert() з класу string та виклик своєї функції
void task_1() {
    char cstr[256];     // Масив символів
    string sstr;        // Об'єкт класу string

    cout << "Введіть рядок: ";
    cin.ignore();
    cin.getline(cstr, 256); // Зчитування в масив символів
    sstr = cstr;            // Присвоєння в об'єкт string

    string insertText;
    cout << "введіть вставку: ";
    cin.clear();
    cin >> insertText;
    const char* insertCStr = insertText.c_str();

    int position; // позиція для вставки
    cout << "введіть позицію для вставки: ";
    cin.clear();
    cin >> position;

    // Виклик методу insert з класу string
    string stringResult = sstr;
    stringResult.insert(position, insertText);

    // Виклик власної функції вставки
    char customResult[512]; // буфер для результату
    for (int i = 0; i <= strlen(cstr); ++i) {
        customResult[i] = cstr[i];
    }
    my_insert(customResult, position, insertCStr);

    // Вивід результатів
    cout << "\nРезультат (string.insert):        " << stringResult << endl;
    cout << "Результат (my_insert для char[]): " << customResult << endl;
}