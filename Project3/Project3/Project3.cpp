#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Array {
private:
    int* arr;
    int size;

public:
    Array(int n);
    ~Array();
    void Set();
    void Print();

    // Задания 1-7
    void Run1();
    void Run2();
    void Run3();
    void Run4();
    void Run5();
    void Run6();
    void Run7(int a, int b);
};


Array::Array(int n) {
    size = n;
    arr = new int[size];
}

Array::~Array() {
    delete[] arr;
}

void Array::Set() {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 21 - 10;
    }
}

void Array::Print() {
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array::Run1() {
    int min_idx = 0, max_idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[min_idx]) min_idx = i;
        if (arr[i] > arr[max_idx]) max_idx = i;
    }
    int start = min(min_idx, max_idx);
    int end = max(min_idx, max_idx);

    long long prod = 1;
    bool found = false;
    for (int i = start + 1; i < end; i++) {
        prod *= arr[i];
        found = true;
    }
    if (found) cout << "-> Произведение между min и max: " << prod << endl;
    else cout << "-> Нет элементов между min и max." << endl;
}

void Array::Run2() {
    int min_idx = 0, max_idx = 0;
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) < abs(arr[min_idx])) min_idx = i;
        if (abs(arr[i]) > abs(arr[max_idx])) max_idx = i;
    }
    int start = min(min_idx, max_idx);
    int end = max(min_idx, max_idx);

    long long prod = 1;
    bool found = false;
    for (int i = start + 1; i < end; i++) {
        prod *= arr[i];
        found = true;
    }
    if (found) cout << "-> Произведение между min(abs) и max(abs): " << prod << endl;
    else cout << "-> Нет элементов между min(abs) и max(abs)." << endl;
}

void Array::Run3() {
    int min_idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[min_idx]) min_idx = i;
    }
    int sum = 0;
    for (int i = min_idx + 1; i < size; i++) {
        sum += arr[i];
    }
    cout << "-> Сумма после минимального: " << sum << endl;
}

void Array::Run4() {
    int min_idx = 0;
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) < abs(arr[min_idx])) min_idx = i;
    }
    int sum = 0;
    for (int i = min_idx + 1; i < size; i++) {
        sum += abs(arr[i]);
    }
    cout << "-> Сумма модулей после минимального по модулю: " << sum << endl;
}

void Array::Run5() {
    int min_idx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[min_idx]) min_idx = i;
    }
    int sum = 0;
    for (int i = 0; i < min_idx; i++) {
        sum += arr[i];
    }
    cout << "-> Сумма до минимального: " << sum << endl;
}

void Array::Run6() {
    int first_pos_idx = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            first_pos_idx = i;
            break;
        }
    }
    if (first_pos_idx != -1) {
        int sum = 0;
        for (int i = first_pos_idx + 1; i < size; i++) {
            sum += arr[i];
        }
        cout << "-> Сумма после первого положительного: " << sum << endl;
    }
    else {
        cout << "-> Положительных элементов нет." << endl;
    }
}

void Array::Run7(int a, int b) {
    int* temp = new int[size];
    int idx = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= a && arr[i] <= b) {
            temp[idx++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] < a || arr[i] > b) {
            temp[idx++] = arr[i];
        }
    }
    // Копируем обратно
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
    cout << "-> Массив преобразован (интервал [" << a << ", " << b << "]):\n";
    Print();
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(0));

    Array arr(10);
    arr.Set();

    int choice;
    do {
        cout << "\n================= МЕНЮ =================\n";
        cout << "Текущий ";
        arr.Print();
        cout << "----------------------------------------\n";
        cout << "1. Произведение между min и max\n";
        cout << "2. Произведение между min(abs) и max(abs)\n";
        cout << "3. Сумма после минимального\n";
        cout << "4. Сумма модулей после минимального по модулю\n";
        cout << "5. Сумма до минимального\n";
        cout << "6. Сумма после первого положительного\n";
        cout << "7. Преобразовать массив (сначала элементы из [a, b])\n";
        cout << "8. Перезаполнить массив случайными числами\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        cout << "\n";
        switch (choice) {
        case 1:
            arr.Run1(); break;
        case 2:
            arr.Run2(); break;
        case 3:
            arr.Run3(); break;
        case 4:
            arr.Run4(); break;
        case 5:
            arr.Run5(); break;
        case 6:
            arr.Run6(); break;
        case 7: {
            int a, b;
            cout << "Введите границу a: ";
            cin >> a;
            cout << "Введите границу b: ";
            cin >> b;
            arr.Run7(a, b);
            break;
        }
        case 8:
            arr.Set();
            cout << "Массив успешно обновлен.\n";
            break;
        case 0:
            cout << "Завершение работы программы...\n";
            break;
        default:
            cout << "Ошибка: Неверный пункт меню. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}