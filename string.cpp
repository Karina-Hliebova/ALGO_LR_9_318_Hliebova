#include "string.h" // Мій файл заголовку
#include <iostream> // Для вводу/виводу в консоль
#include <fstream>  // Для роботи з файлами
#include <string>   // Для використання типу string
#include <vector>   // Для використання векторів, щоб перевіряти підрядок
using namespace std; // Щоб не писати std:: перед кожним стандартним елементом

// A. Функція, що видаляє останнє входження підрядка S0 з рядка S
string removeLastSubstring(const string& S, const string& S0) {
    size_t pos = S.rfind(S0); // Знаходимо позицію останнього входження S0 у S
    if (pos != string::npos) { // Якщо входження знайдено
        string result = S; // Створюємо копію рядка S
        result.erase(pos, S0.length()); // Видаляємо підрядок, починаючи з pos
        return result; // Повертаємо результат
    }
    return S; // Якщо входження не знайдено — повертаємо S без змін
}

// B. Функція, що перевіряє, чи міститься S0 у S
bool hasSubstring(const string& S, const string& S0) {
    return S.find(S0) != string::npos; // Повертає true, якщо S0 є в S
}

// C. Функція для виводу вмісту файлу на консоль
void printFileContent(const string& filename) {
    ifstream file(filename); // Відкриваємо файл для читання
    if (!file.is_open()) { // Якщо файл не відкрився
        cerr << "Не вдалося відкрити файл: " << filename << endl; // Виводимо помилку
        return; // Виходимо з функції
    }

    string line; // Змінна для зберігання рядків з файлу
    cout << "Вміст файлу " << filename << ":\n\n"; // Повідомлення для користувача
    while (getline(file, line)) { // Читаємо файл рядок за рядком
        cout << line << endl; // Виводимо кожен рядок
    }
    file.close(); // Закриваємо файл
}

// D. Функція для зчитування підрядка з консолі
string readSubstringFromUser() {
    string S0; // Змінна для збереження введеного рядка
    cout << "\nВведіть підрядок для видалення: "; // Запит до користувача
    cin.ignore(); // Очищення буфера вводу (захист від залишків після cin)
    getline(cin, S0); // Зчитуємо рядок повністю (з пробілами)
    return S0; // Повертаємо введений рядок
}

// E. Функція для обробки рядків: видалення останнього входження S0
void processStrings(const string& inputFile, const string& outputFile, const string& S0) {
    // Відкриваємо вхідний файл для читання
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        // Якщо файл не вдалося відкрити, виводимо помилку та виходимо
        cerr << "Не вдалося відкрити вхідний файл!" << endl;
        return;
    }

    vector<string> lines;       // Вектор для збереження всіх рядків з файлу
    bool found = false;         // Прапорець, що показує, чи знайдено підрядок хоча б в одному рядку

    string line;                // Змінна для зчитування поточного рядка
    while (getline(inFile, line)) {               // Зчитуємо кожен рядок з файлу
        if (!found && hasSubstring(line, S0)) {   // Якщо підрядок ще не знайдено, перевіряємо цей рядок
            found = true;                         // Якщо знайдено, встановлюємо прапорець
        }
        lines.push_back(line);                    // Додаємо поточний рядок до вектору
    }
    inFile.close();                               // Закриваємо вхідний файл після читання всіх рядків

    if (!found) { // Якщо підрядок не знайдено у жодному рядку
        cout << "\nПідрядок \"" << S0 << "\" не знайдено у жодному рядку. "
            << "Файл залишився без змін.\n" << endl; // Повідомляємо користувача
        return; // Виходимо з функції, не створюючи вихідний файл
    }

    // Відкриваємо вихідний файл для запису
    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        // Якщо не вдалося відкрити вихідний файл, повідомляємо про помилку
        cerr << "Не вдалося відкрити вихідний файл!" << endl;
        return;
    }

    // Обробляємо кожен збережений рядок
    for (const string& l : lines) {
        if (hasSubstring(l, S0)) {
            // Якщо рядок містить підрядок — видаляємо останнє входження
            string modified = removeLastSubstring(l, S0);
            outFile << modified << endl; // Записуємо змінений рядок у вихідний файл
        }
        else {
            // Інакше записуємо рядок без змін
            outFile << l << endl;
        }
    }
    outFile.close(); // Закриваємо вихідний файл після завершення запису
}


// Головна функція, яка виконує всі кроки
void task_2() {
    const string inputFile = "string_in_8.txt"; // Назва вхідного файлу
    const string outputFile = "string_out_8.txt"; // Назва вихідного файлу

    printFileContent(inputFile); // Виводимо вміст вхідного файлу на екран

    string S0 = readSubstringFromUser(); // Зчитуємо підрядок, який треба видалити

    processStrings(inputFile, outputFile, S0); // Обробляємо рядки — видаляємо підрядок

    cout << "\nОбробку завершено. Перевірте файл " << outputFile << endl << endl; // Повідомлення

    printFileContent(outputFile); // Виводимо результат обробки на екран
}