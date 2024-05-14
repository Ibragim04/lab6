#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Функция для чтения вектора из файла
std::vector<int> ReadVectorFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return {};
    }

    std::vector<int> vec;
    int num;
    while (file >> num) {
        vec.push_back(num);
    }

    file.close();
    return vec;
}

// Функция для реверсирования вектора
void ReverseVector(std::vector<int>& vec) {
    std::reverse(vec.begin(), vec.end());
}

// Функция для поиска минимального элемента в векторе
int FindMinElement(const std::vector<int>& vec) {
    return *std::min_element(vec.begin(), vec.end());
}

// Функция для удаления четных элементов из вектора
void RemoveEvenElements(std::vector<int>& vec) {
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int num) { return num % 2 == 0; }), vec.end());
}

// Функция для сортировки вектора
void SortVector(std::vector<int>& vec, bool ascending = true) {
    if (ascending) {
        std::sort(vec.begin(), vec.end());
    } else {
        std::sort(vec.begin(), vec.end(), std::greater<int>());
    }
}

// Функция для вставки элемента в отсортированный вектор
void InsertElement(std::vector<int>& vec, int element) {
    vec.insert(std::upper_bound(vec.begin(), vec.end(), element), element);
}

// Функция для определения индекса заданного элемента
int FindIndex(const std::vector<int>& vec, int element) {
    auto it = std::find(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    } else {
        return -1; // Возвращаем -1, если элемент не найден
    }
}

// Функция для удаления дублированных элементов из вектора
void RemoveDuplicates(std::vector<int>& vec) {
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

int main() {
    // Чтение вектора из файла
    std::vector<int> vec = ReadVectorFromFile("vector.txt");

    // Вывод исходного вектора
    std::cout << "Original vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Реверсирование вектора
    ReverseVector(vec);
    std::cout << "Reversed vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Поиск минимального элемента
    int minElement = FindMinElement(vec);
    std::cout << "Min element: " << minElement << std::endl;

    // Удаление четных элементов
    RemoveEvenElements(vec);
    std::cout << "Vector after removing even elements: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Сортировка вектора
    SortVector(vec);
    std::cout << "Sorted vector in ascending order: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Вставка элемента в отсортированный вектор
    InsertElement(vec, 3);
    std::cout << "Vector after inserting element 3: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Определение индекса заданного элемента
    int index = FindIndex(vec, 5);
    if (index != -1) {
        std::cout << "Index of element 5: " << index << std::endl;
    } else {
        std::cout << "Element 5 not found in the vector." << std::endl;
    }

    // Удаление дублированных элементов
    RemoveDuplicates(vec);
    std::cout << "Vector after removing duplicates: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
