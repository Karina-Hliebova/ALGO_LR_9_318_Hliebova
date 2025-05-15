#include <iostream> // підключення заголовкового файлу
#include <string> // підключення бібліотеки для роботи з введенням/виведенням
#include "insert.h" // підключення бібліотеки для роботи з типом string
using namespace std; 

// В. реалізація власної функції вставки в масив символів 
void my_insert(char* dest, int pos, const char* insertStr) {
    int lenDest = 0, lenInsert = 0; // змінні для збереження довжин вихідного рядка і вставки

    // довжина вихідного рядка
    while (dest[lenDest] != '\0') lenDest++; // підрахунок символів у вхідному рядку до символу завершення '\0'
    while (insertStr[lenInsert] != '\0') lenInsert++; // підрахунок символів у вставці до символу завершення

    for (int i = lenDest; i >= pos; --i) { 
        dest[i + lenInsert] = dest[i]; // переміщення слів вправо, щоб вмістити вставку
    }

    for (int i = 0; i < lenInsert; ++i) {
        dest[pos + i] = insertStr[i]; // вставка символів зі вставного рядка у вибрану позицію на вхідному рядку
    }
}

// A + C. Виклик методу insert() з класу string та виклик своєї функції
void task_1() { // функція виконання завдання 1
    char cstr[256];     // масив символів для зберігання введеного рядка
    string sstr;        // об'єкт класу string

    cout << "Введіть рядок: "; // введення вхідного рядка
    cin.ignore(); // ігнорування символу нового рядка після попереднього вводу
    cin.getline(cstr, 256); // зчитування в масив символів
    sstr = cstr;            // присвоєння в об'єкт string

    string insertText; // змінна для збереження тексту, який потрібно вставити
    cout << "Введіть вставку: "; // введення вставки
    cin.clear(); // очищення буферу
    cin >> insertText; // зчитування вставного рядка
    const char* insertCStr = insertText.c_str(); // змінна для збереження позиції, куди буде вставлено текст

    int position; // позиція для вставки
    cout << "Введіть позицію для вставки: "; // введення позиції для вставки
    cin.clear(); // очищення буферу
    cin >> position; // зчитування позиції вставки

    string stringResult = sstr; // копіювання вхідного рядка у нову змінну для виведення результату
    stringResult.insert(position, insertText); // вставка нового рядка в указану позицію

    char customResult[512]; // буфер для результату
    for (int i = 0; i <= strlen(cstr); ++i) {
        customResult[i] = cstr[i]; // копіювання оригінального рядку у новий буфер
    }
    my_insert(customResult, position, insertCStr); // виклик власної функції вставки

    cout << "\nРезультат (string.insert):        " << stringResult << endl; // виведення результату функції з прикладу
    cout << "Результат (my_insert для char[]): " << customResult << endl; // виведення результату своєї функції
}
