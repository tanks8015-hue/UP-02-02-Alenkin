#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Array2D {
private:
    int** arr;
    int rows;
    int cols;

public:
    Array2D(int r, int c);
    ~Array2D();
    void Set();
    void Print();
    friend void Run1(Array2D& obj);
    friend void Run2(Array2D& obj);
    friend void Run3(Array2D& obj);
    friend void Run4(Array2D& obj);
    friend void Run5(Array2D& obj);
    friend void Run6(Array2D& obj);
    friend void Run7(Array2D& obj, double val);
};

Array2D::Array2D(int r, int c) {
    rows = r;
    cols = c;
    arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
}

Array2D::~Array2D() {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void Array2D::Set() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 21 - 5;
        }
    }
}

void Array2D::Print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void Run1(Array2D& obj) {
    int total_sum = 0;
    bool found_any_row = false;

    for (int i = 0; i < obj.rows; i++) {
        bool has_negative = false;
        int row_sum = 0;
        for (int j = 0; j < obj.cols; j++) {
            if (obj.arr[i][j] < 0) has_negative = true;
            row_sum += obj.arr[i][j];
        }
        if (!has_negative) {
            total_sum += row_sum;
            found_any_row = true;
        }
    }
    if (found_any_row) cout << "-> Сумма в строках без отрицательных: " << total_sum << endl;
    else cout << "-> Нет строк без отрицательных элементов." << endl;
}

void Run2(Array2D& obj) {
    int count = 0;
    for (int i = 0; i < obj.rows; i++) {
        for (int j = 0; j < obj.cols; j++) {
            if (obj.arr[i][j] == 0) {
                count++;
                break;
            }
        }
    }
    cout << "-> Строк с хотя бы одним нулем: " << count << endl;
}

void Run3(Array2D& obj) {
    int target_row = -1;
    for (int i = 0; i < obj.rows; i++) {
        bool has_pos = false;
        for (int j = 0; j < obj.cols; j++) {
            if (obj.arr[i][j] > 0) {
                has_pos = true;
                break;
            }
        }
        if (!has_pos) {
            target_row = i;
            break;
        }
    }
    if (target_row != -1) cout << "-> Первая строка без положительных (индекс): " << target_row << endl;
    else cout << "-> Нет строк без положительных элементов." << endl;
}

void Run4(Array2D& obj) {
    int target_col = -1;
    for (int j = 0; j < obj.cols; j++) {
        bool has_neg = false;
        for (int i = 0; i < obj.rows; i++) {
            if (obj.arr[i][j] < 0) {
                has_neg = true;
                break;
            }
        }
        if (!has_neg) {
            target_col = j;
            break;
        }
    }
    if (target_col != -1) cout << "-> Первый столбец без отрицательных (индекс): " << target_col << endl;
    else cout << "-> Нет столбцов без отрицательных элементов." << endl;
}

void Run5(Array2D& obj) {
    int target_col = -1;
    for (int j = 0; j < obj.cols; j++) {
        for (int i = 0; i < obj.rows; i++) {
            if (obj.arr[i][j] == 0) {
                target_col = j;
                break;
            }
        }
        if (target_col != -1) break;
    }
    if (target_col != -1) cout << "-> Первый столбец с нулем (индекс): " << target_col << endl;
    else cout << "-> Нет столбцов с нулем." << endl;
}

void Run6(Array2D& obj) {
    int target_row = -1;
    for (int i = 0; i < obj.rows; i++) {
        for (int j = 0; j < obj.cols; j++) {
            if (obj.arr[i][j] > 0) {
                target_row = i;
                break;
            }
        }
        if (target_row != -1) break;
    }
    if (target_row != -1) cout << "-> Первая строка с положительным (индекс): " << target_row << endl;
    else cout << "-> Нет строк с положительными элементами." << endl;
}

void Run7(Array2D& obj, double val) {
    int count = 0;
    for (int i = 0; i < obj.rows; i++) {
        double sum = 0;
        for (int j = 0; j < obj.cols; j++) {
            sum += obj.arr[i][j];
        }
        if ((sum / obj.cols) < val) count++;
    }
    cout << "-> Строк со средним арифм. меньше " << val << ": " << count << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(0));
    Array2D mat(4, 5);
    mat.Set();

    int choice;
    do {
        cout << "\n=================== МЕНЮ ===================\n";
        cout << "Текущая матрица:\n";
        mat.Print();
        cout << "--------------------------------------------\n";
        cout << "1. Сумма в строках без отрицательных элементов\n";
        cout << "2. Количество строк с хотя бы одним нулем\n";
        cout << "3. Номер первой строки без положительных элементов\n";
        cout << "4. Номер первого столбца без отрицательных элементов\n";
        cout << "5. Номер первого столбца с хотя бы одним нулем\n";
        cout << "6. Номер первой строки с хотя бы одним положительным\n";
        cout << "7. Кол-во строк, среднее арифм. которых меньше заданной величины\n";
        cout << "8. Перезаполнить матрицу случайными числами\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        cout << "\n";
        switch (choice) {
        case 1:
            Run1(mat); break;
        case 2:
            Run2(mat); break;
        case 3:
            Run3(mat); break;
        case 4:
            Run4(mat); break;
        case 5:
            Run5(mat); break;
        case 6:
            Run6(mat); break;
        case 7: {
            double val;
            cout << "Введите заданную величину для сравнения: ";
            cin >> val;
            Run7(mat, val);
            break;
        }
        case 8:
            mat.Set();
            cout << "Матрица успешно обновлена.\n";
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