#ifndef STRING_H 
#define STRING_H 
#include <string> // підключення бібліотеки для роботи з типом string
using namespace std;  

//String34.Дано рядки S і S0.Видалити з рядка S останню підстроку, що збігається з S0.Якщо таких підстрок немає, то вивести рядок S без змін.

void task_2(); // основна функція завдання 2

// допоміжні функції
string removeLastSubstring(const string& S, const string& S0); // функція видалення останнього входження підрядка S0 з рядка S
bool hasSubstring(const string& S, const string& S0); // функція перевірки, чи міститься S0 у S

#endif // STRING_H
