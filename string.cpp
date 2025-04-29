#include "string.h" // підключення заголовкового файлу
#include <iostream> // підключення бібліотеки для роботи з введенням/виведенням 
#include <fstream> // підключення бібліотеки для роботи з файлами
#include <string> // підключення бібліотеки для роботи з типом string
using namespace std;

// функція видалення останнього входження підрядка S0 з рядка S
string removeLastSubstring(const string& S, const string& S0) { 
    size_t pos = S.rfind(S0); // пошук останнього входження
    if (pos != string::npos) { // якщо знайдено
        string result = S; // копіюємо рядок S у змінну result
        result.erase(pos, S0.length()); // видалення підрядка S0 з позиції pos
        return result; // повернення зміненого рядка
    }
    return S; // якщо не знайдено, повертаємо оригінальний рядок без змін
}

bool hasSubstring(const string& S, const string& S0) { // функція перевірки, чи міститься S0 у S
    return S.find(S0) != string::npos; 
}

void task_2() { // основна функція обробки
    ofstream inputFile("string_in_8.txt"); // створення вхідного файлу
    if (inputFile.is_open()) { // запис текстових рядків у вхідний файл
        inputFile << "Яблуко червоне як серце\n";
        inputFile << "Червоне сонце заходить\n";
        inputFile << "Сонце світить і гріє\n";
        inputFile << "Світить вікно у кімнату\n";
        inputFile << "У кімнаті червона лампа\n";
        inputFile << "Світло лампи червоне і м'яке\n";
        inputFile << "М'яке світло вечора\n";
        inputFile << "Небо червоне на заході\n";
        inputFile << "Море хвилюється червоне\n";
        inputFile << "Малюю червоне коло на папері\n";
        inputFile.close(); // закриття файлу
    }
    cout << endl; // вільна строка для полегшення сприймання

    ifstream inFile("string_in_8.txt"); // відкриття вхідного файлу
    if (!inFile.is_open()) { // якщо не вдалося відкрити файл
        cerr << "Не вдалося відкрити файл!" << endl; // виведення повідомлення про помилку
        return;
    }

    cout << "Вміст файлу string_in_8.txt:\n\n"; // виведення строк, що містяться у вхідному файлі
    string line; // тимчасове збереження кожного рядка, що міститься у вхідному файлі
    while (getline(inFile, line)) { // читання рядків  
        cout << line << endl; // виведення кожного рядка на екран
    }
    inFile.close(); // закриття файлу після виведення на консоль

    string S0; // отримання підрядка для видалення
    cout << "\nВведіть підрядок для видалення: "; // введення підрядка
    cin.ignore(); // ігнорування символа нового рядка після попереднього вводу
    getline(cin, S0); // зчитування підрядка

    ifstream inFile2("string_in_8.txt"); // повторне відкриття вхідного файлу для обробки строк
    ofstream outFile("string_out_8.txt"); // відкриття вихідного файлу для виведення результату

    if (!inFile2.is_open() || !outFile.is_open()) { // якщо при відкритті якогось файлу виникає помилка
        cerr << "Не вдалося відкрити файл!" << endl; // виводиться відповідне повідомлення 
        return;
    }

    while (getline(inFile2, line)) { // обробка кожного рядка:
        if (hasSubstring(line, S0)) { // якщо містить підрядок S0 — видалити останнє входження
            string modified = removeLastSubstring(line, S0); // видалення останнього входження
            outFile << modified << endl; // запис зміненого рядка у вихідний файл
        }
        else { // якщо підрядок не знайдено
            outFile << line << endl; // запис без змін
        }
    }

    inFile2.close(); // закриття вхідного файлу
    outFile.close(); // закриття вихідного файлу

    cout << "Обробку завершено. Перевірте файл string_out_8.txt" << endl; // виведення повідомлення про завершення обробки
}
