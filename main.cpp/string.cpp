#include "string.h" // ̳� ���� ���������
#include <iostream> // ��� �����/������ � �������
#include <fstream>  // ��� ������ � �������
#include <string>   // ��� ������������ ���� string
#include <vector>   // ��� ������������ �������, ��� ��������� �������
using namespace std; // ��� �� ������ std:: ����� ������ ����������� ���������

// A. �������, �� ������� ������ ��������� ������� S0 � ����� S
string removeLastSubstring(const string& S, const string& S0) {
    size_t pos = S.rfind(S0); // ��������� ������� ���������� ��������� S0 � S
    if (pos != string::npos) { // ���� ��������� ��������
        string result = S; // ��������� ���� ����� S
        result.erase(pos, S0.length()); // ��������� �������, ��������� � pos
        return result; // ��������� ���������
    }
    return S; // ���� ��������� �� �������� � ��������� S ��� ���
}

// B. �������, �� ��������, �� �������� S0 � S
bool hasSubstring(const string& S, const string& S0) {
    return S.find(S0) != string::npos; // ������� true, ���� S0 � � S
}

// C. ������� ��� ������ ����� ����� �� �������
void printFileContent(const string& filename) {
    ifstream file(filename); // ³�������� ���� ��� �������
    if (!file.is_open()) { // ���� ���� �� ��������
        cerr << "�� ������� ������� ����: " << filename << endl; // �������� �������
        return; // �������� � �������
    }

    string line; // ����� ��� ��������� ����� � �����
    cout << "���� ����� " << filename << ":\n\n"; // ����������� ��� �����������
    while (getline(file, line)) { // ������ ���� ����� �� ������
        cout << line << endl; // �������� ����� �����
    }
    file.close(); // ��������� ����
}

// D. ������� ��� ���������� ������� � ������
string readSubstringFromUser() {
    string S0; // ����� ��� ���������� ��������� �����
    cout << "\n������ ������� ��� ���������: "; // ����� �� �����������
    cin.ignore(); // �������� ������ ����� (������ �� ������� ���� cin)
    getline(cin, S0); // ������� ����� ������� (� ��������)
    return S0; // ��������� �������� �����
}

// E. ������� ��� ������� �����: ��������� ���������� ��������� S0
void processStrings(const string& inputFile, const string& outputFile, const string& S0) {
    // ³�������� ������� ���� ��� �������
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        // ���� ���� �� ������� �������, �������� ������� �� ��������
        cerr << "�� ������� ������� ������� ����!" << endl;
        return;
    }

    vector<string> lines;       // ������ ��� ���������� ��� ����� � �����
    bool found = false;         // ���������, �� ������, �� �������� ������� ���� � � ������ �����

    string line;                // ����� ��� ���������� ��������� �����
    while (getline(inFile, line)) {               // ������� ����� ����� � �����
        if (!found && hasSubstring(line, S0)) {   // ���� ������� �� �� ��������, ���������� ��� �����
            found = true;                         // ���� ��������, ������������ ���������
        }
        lines.push_back(line);                    // ������ �������� ����� �� �������
    }
    inFile.close();                               // ��������� ������� ���� ���� ������� ��� �����

    if (!found) { // ���� ������� �� �������� � ������� �����
        cout << "\nϳ������ \"" << S0 << "\" �� �������� � ������� �����. "
            << "���� ��������� ��� ���.\n" << endl; // ����������� �����������
        return; // �������� � �������, �� ��������� �������� ����
    }

    // ³�������� �������� ���� ��� ������
    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        // ���� �� ������� ������� �������� ����, ����������� ��� �������
        cerr << "�� ������� ������� �������� ����!" << endl;
        return;
    }

    // ���������� ����� ���������� �����
    for (const string& l : lines) {
        if (hasSubstring(l, S0)) {
            // ���� ����� ������ ������� � ��������� ������ ���������
            string modified = removeLastSubstring(l, S0);
            outFile << modified << endl; // �������� ������� ����� � �������� ����
        }
        else {
            // ������ �������� ����� ��� ���
            outFile << l << endl;
        }
    }
    outFile.close(); // ��������� �������� ���� ���� ���������� ������
}


// ������� �������, ��� ������ �� �����
void task_2() {
    const string inputFile = "string_in_8.txt"; // ����� �������� �����
    const string outputFile = "string_out_8.txt"; // ����� ��������� �����

    printFileContent(inputFile); // �������� ���� �������� ����� �� �����

    string S0 = readSubstringFromUser(); // ������� �������, ���� ����� ��������

    processStrings(inputFile, outputFile, S0); // ���������� ����� � ��������� �������

    cout << "\n������� ���������. �������� ���� " << outputFile << endl << endl; // �����������

    printFileContent(outputFile); // �������� ��������� ������� �� �����
}