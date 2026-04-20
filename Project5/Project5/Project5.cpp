#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h> // Обязательная библиотека для починки кодировки в консоли

using namespace std;

// =========================================================================
// ВАРИАНТ 1: КЛАСС СТЕК (Т-образный сортировочный узел)
// =========================================================================

class Stack {
private:
    struct StackNode {
        int wagonType;
        StackNode* next;
    };
    StackNode* topNode;

public:
    Stack() { topNode = nullptr; }
    ~Stack() {
        while (!isEmpty()) pop();
    }

    void push(int val) {
        StackNode* newNode = new StackNode;
        newNode->wagonType = val;
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) return -1;
        int val = topNode->wagonType;
        StackNode* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return val;
    }

    bool isEmpty() { return topNode == nullptr; }
};

void printTrain(const vector<int>& train) {
    if (train.empty()) cout << "[пусто]";
    else for (int w : train) cout << w << " ";
    cout << endl;
}

void runVariant1() {
    vector<int> mainTrain;
    int choice;
    do {
        cout << "\n--- ПРАКТИКА 5 | ВАРИАНТ 1: СОРТИРОВКА ПОЕЗДОВ ---\n";
        cout << "Текущий состав: "; printTrain(mainTrain);
        cout << "1. Сформировать состав с клавиатуры (тип 1 или 2)\n";
        cout << "2. Загрузить состав из файла (train.txt)\n";
        cout << "3. Смоделировать сортировку в тупике\n";
        cout << "0. Вернуться в Главное меню\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            mainTrain.clear();
            int n; cout << "Сколько вагонов? "; cin >> n;
            cout << "Введите типы (1 или 2): ";
            for (int i = 0; i < n; i++) {
                int type; cin >> type;
                if (type == 1 || type == 2) mainTrain.push_back(type);
                else cout << "Пропущен неизвестный вагон: " << type << endl;
            }
            break;
        }
        case 2: {
            mainTrain.clear();
            ifstream in("train.txt");
            if (!in.is_open()) cout << "Ошибка! Создайте файл train.txt рядом с программой.\n";
            else {
                int type;
                while (in >> type) {
                    if (type == 1 || type == 2) mainTrain.push_back(type);
                }
                in.close(); cout << "Состав загружен!\n";
            }
            break;
        }
        case 3: {
            if (mainTrain.empty()) { cout << "Состав пуст!\n"; break; }
            Stack sideTrack;
            vector<int> dir1, dir2;
            cout << "\nХод сортировки:\n";
            for (int w : mainTrain) {
                if (w == 1) {
                    cout << "Вагон [1] едет в Направление 1.\n";
                    dir1.push_back(w);
                }
                else {
                    cout << "Вагон [2] загнан в тупик.\n";
                    sideTrack.push(w);
                }
            }
            cout << "Выводим вагоны из тупика...\n";
            while (!sideTrack.isEmpty()) {
                dir2.push_back(sideTrack.pop());
            }

            cout << "\nИТОГ:\nНаправление 1: "; printTrain(dir1);
            cout << "Направление 2: "; printTrain(dir2);
            break;
        }
        case 0: cout << "Возврат в главное меню...\n"; break;
        default: cout << "Неверный выбор!\n";
        }
    } while (choice != 0);
}


// =========================================================================
// ВАРИАНТ 2: БИНАРНОЕ ДЕРЕВО (Англо-русский словарь)
// =========================================================================

class DictionaryTree {
private:
    struct TreeNode {
        string eng;
        string rus;
        TreeNode* left;
        TreeNode* right;
        TreeNode(string e, string r) : eng(e), rus(r), left(nullptr), right(nullptr) {}
    };
    TreeNode* root;

    TreeNode* insert(TreeNode* node, string eng, string rus) {
        if (!node) return new TreeNode(eng, rus);
        if (eng < node->eng) node->left = insert(node->left, eng, rus);
        else if (eng > node->eng) node->right = insert(node->right, eng, rus);
        return node;
    }

    TreeNode* search(TreeNode* node, string eng) {
        if (!node || node->eng == eng) return node;
        if (eng < node->eng) return search(node->left, eng);
        return search(node->right, eng);
    }

    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) node = node->left;
        return node;
    }

    TreeNode* removeNode(TreeNode* node, string eng) {
        if (!node) return node;
        if (eng < node->eng) node->left = removeNode(node->left, eng);
        else if (eng > node->eng) node->right = removeNode(node->right, eng);
        else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMin(node->right);
            node->eng = temp->eng;
            node->rus = temp->rus;
            node->right = removeNode(node->right, temp->eng);
        }
        return node;
    }

    void printInOrder(TreeNode* node) {
        if (!node) return;
        printInOrder(node->left);
        cout << node->eng << " - " << node->rus << endl;
        printInOrder(node->right);
    }

public:
    DictionaryTree() { root = nullptr; }
    void add(string eng, string rus) { root = insert(root, eng, rus); }
    void remove(string eng) { root = removeNode(root, eng); }

    void find(string eng) {
        TreeNode* res = search(root, eng);
        if (res) cout << "Перевод: " << res->rus << endl;
        else cout << "Слово не найдено!" << endl;
    }

    void printAll() {
        if (!root) cout << "Словарь пуст.\n";
        else printInOrder(root);
    }
};

void runVariant2() {
    DictionaryTree dict;
    int choice;
    do {
        cout << "\n--- ПРАКТИКА 5 | ВАРИАНТ 2: АНГЛО-РУССКИЙ СЛОВАРЬ ---\n";
        cout << "1. Добавить слово вручную\n";
        cout << "2. Загрузить из файла (dict.txt)\n";
        cout << "3. Найти перевод слова\n";
        cout << "4. Удалить слово\n";
        cout << "5. Вывести весь словарь\n";
        cout << "0. Вернуться в Главное меню\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string eng, rus;
            cout << "English: "; cin >> eng;
            cout << "Русский: "; cin >> rus;
            dict.add(eng, rus);
            cout << "Добавлено!\n";
            break;
        }
        case 2: {
            ifstream in("dict.txt");
            if (!in.is_open()) cout << "Ошибка! Создайте файл dict.txt (формат: apple яблоко)\n";
            else {
                string eng, rus;
                int count = 0;
                while (in >> eng >> rus) {
                    dict.add(eng, rus);
                    count++;
                }
                in.close(); cout << "Загружено слов: " << count << endl;
            }
            break;
        }
        case 3: {
            string eng;
            cout << "Слово (eng): "; cin >> eng;
            dict.find(eng);
            break;
        }
        case 4: {
            string eng;
            cout << "Слово для удаления (eng): "; cin >> eng;
            dict.remove(eng);
            cout << "Выполнено.\n";
            break;
        }
        case 5:
            cout << "\n--- Содержимое словаря ---\n";
            dict.printAll();
            break;
        case 0: cout << "Возврат в главное меню...\n"; break;
        default: cout << "Неверный выбор!\n";
        }
    } while (choice != 0);
}


// =========================================================================
// ВАРИАНТ 3: ИЕРАРХИЯ КЛАССОВ (Геометрические фигуры)
// =========================================================================

class Shape {
protected:
    double x, y, angle;
public:
    Shape(double x, double y) : x(x), y(y), angle(0) {}
    virtual ~Shape() {}

    void move(double dx, double dy) { x += dx; y += dy; }
    void rotate(double deg) {
        angle += deg;
        if (angle >= 360) angle -= 360;
        if (angle < 0) angle += 360;
    }
    virtual void resize(double factor) = 0;
    virtual void print() const = 0;
};

class Circle : public Shape {
private: double radius;
public:
    Circle(double x, double y, double r) : Shape(x, y), radius(r) {}
    void resize(double factor) override { radius *= factor; }
    void print() const override {
        cout << "[Круг] Центр: (" << x << ", " << y << "), Радиус: " << radius << endl;
    }
};

class Square : public Shape {
private: double side;
public:
    Square(double x, double y, double a) : Shape(x, y), side(a) {}
    void resize(double factor) override { side *= factor; }
    void print() const override {
        cout << "[Квадрат] Центр: (" << x << ", " << y << "), Сторона: " << side << ", Поворот: " << angle << "°\n";
    }
};

// ИЗМЕНЕНИЕ ЗДЕСЬ: класс Rectangle переименован в MyRectangle для избежания конфликта с windows.h
class MyRectangle : public Shape {
private: double width, height;
public:
    MyRectangle(double x, double y, double w, double h) : Shape(x, y), width(w), height(h) {}
    void resize(double factor) override { width *= factor; height *= factor; }
    void print() const override {
        cout << "[Прямоугольник] Центр: (" << x << ", " << y << "), ШxВ: " << width << "x" << height << ", Поворот: " << angle << "°\n";
    }
};

void runVariant3() {
    Shape* currentShape = nullptr;
    int choice;
    do {
        cout << "\n--- ПРАКТИКА 5 | ВАРИАНТ 3: ГЕОМЕТРИЧЕСКИЕ ФИГУРЫ ---\n";
        if (currentShape) { cout << "Текущая: "; currentShape->print(); }
        else cout << "Текущая фигура: НЕ СОЗДАНА\n";

        cout << "1. Создать Круг\n2. Создать Квадрат\n3. Создать Прямоугольник\n";
        cout << "4. Переместить (Move)\n5. Изменить размер (Resize)\n6. Повернуть (Rotate)\n";
        cout << "0. Вернуться в Главное меню\nВыбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double x, y, r; cout << "X Y Радиус: "; cin >> x >> y >> r;
            if (currentShape) delete currentShape;
            currentShape = new Circle(x, y, r); break;
        }
        case 2: {
            double x, y, a; cout << "X Y Сторона: "; cin >> x >> y >> a;
            if (currentShape) delete currentShape;
            currentShape = new Square(x, y, a); break;
        }
        case 3: {
            double x, y, w, h; cout << "X Y Ширина Высота: "; cin >> x >> y >> w >> h;
            if (currentShape) delete currentShape;
            // ИЗМЕНЕНИЕ ЗДЕСЬ: используем MyRectangle
            currentShape = new MyRectangle(x, y, w, h); break;
        }
        case 4: {
            if (!currentShape) { cout << "Создайте фигуру!\n"; break; }
            double dx, dy; cout << "Смещение dx dy: "; cin >> dx >> dy;
            currentShape->move(dx, dy); break;
        }
        case 5: {
            if (!currentShape) { cout << "Создайте фигуру!\n"; break; }
            double k; cout << "Коэффициент масштаба (напр. 2): "; cin >> k;
            currentShape->resize(k); break;
        }
        case 6: {
            if (!currentShape) { cout << "Создайте фигуру!\n"; break; }
            double ang; cout << "Угол поворота: "; cin >> ang;
            currentShape->rotate(ang); break;
        }
        case 0: cout << "Возврат в главное меню...\n"; break;
        default: cout << "Неверный выбор!\n";
        }
    } while (choice != 0);
    if (currentShape) delete currentShape;
}


// =========================================================================
// ОСНОВНАЯ ПРОГРАММА (ГЛАВНОЕ МЕНЮ)
// =========================================================================
int main() {
    // Включаем поддержку кириллицы (Windows-1251) для корректного ввода/вывода
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Инициализация генератора случайных чисел
    srand((unsigned int)time(0));

    int mainChoice;

    do {
        cout << "\n=================== ГЛАВНОЕ МЕНЮ ===================\n";
        cout << "Практическая работа №5 (Классы и структуры данных)\n";
        cout << "1. Запустить Вариант №1 (Стек - Сортировка поездов)\n";
        cout << "2. Запустить Вариант №2 (Бинарное дерево - Словарь)\n";
        cout << "3. Запустить Вариант №3 (Иерархия классов - Фигуры)\n";
        cout << "0. Выход из программы\n";
        cout << "Выберите задание: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1: runVariant1(); break;
        case 2: runVariant2(); break;
        case 3: runVariant3(); break;
        case 0: cout << "Завершение работы программы...\n"; break;
        default: cout << "Ошибка ввода! Попробуйте снова.\n";
        }
    } while (mainChoice != 0);

    return 0;
}