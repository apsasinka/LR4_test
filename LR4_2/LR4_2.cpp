#include <iostream>
#include <vector>

// Функция, которая выполняет тест
void runTest(int testNumber, int n, double C, std::vector<double> elements, int expectedCount) {
    std::cout << "Тест " << testNumber << ": " << std::endl;

    if (n <= 0) {
        std::cerr << "Ошибка: Размер массива должен быть положительным числом." << std::endl;
        return;
    }

    // Вывод входных данных
    std::cout << "Размер массива: " << n << std::endl;
    std::cout << "Значение C: " << C << std::endl;
    std::cout << "Элементы массива: ";
    for (int i = 0; i < n; i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;

    // Создаем динамический массив размером n
    double* arr = new double[n];

    // Заполняем массив элементами
    for (int i = 0; i < n; i++) {
        arr[i] = elements[i];
    }

    // Инициализируем вектор для хранения индексов элементов, больших C
    std::vector<int> indices;

    // Перебираем элементы массива и находим те, которые больше C
    for (int i = 0; i < n; i++) {
        if (arr[i] > C) {
            indices.push_back(i);
        }
    }

    // Выводим результаты
    if (indices.empty()) {
        std::cout << "Ожидаемый результат: Нет элементов, больших " << C << std::endl;
    }
    else {
        std::cout << "Ожидаемый результат: Количество элементов, больших " << C << ": " << indices.size() << ", Индексы: ";
        for (int i = 0; i < indices.size(); i++) {
            std::cout << indices[i];
            if (i < indices.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    // Проверка ожидаемого количества элементов
    if (indices.size() != expectedCount) {
        std::cout << "Тест не пройден: Фактическое количество элементов (" << indices.size() << ") не соответствует ожидаемому (" << expectedCount << ")." << std::endl;
    }
    else {
        std::cout << "Тест пройден." << std::endl;
    }

    // Освобождаем выделенную память
    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Запуск первых четырех тестов
    runTest(1, 5, 3.0, { 2.0, 3.0, 4.0, 5.0, 6.0 }, 3);
    runTest(2, 4, 3.0, { 1.0, 2.0, 2.5, 2.8 }, 0);
    runTest(3, 0, 2.0, {}, 0); // Тест с пустым массивом
    runTest(4, -3, 2.0, {}, 0); // Тест с отрицательным размером массива

    return 0;
}
