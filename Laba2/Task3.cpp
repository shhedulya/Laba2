#include <iostream>
#include <clocale>

/*
Задание 3
Ввести код условной категории A/B/C, возраст и стаж. Через switch задать базовую стоимость: 300, 450, 650. 
Затем при возрасте <25 добавить 20%, при стаже <2 — ещё 25%. Проверить согласованность стажа и возраста. 
Вывести категорию и итоговую учебную стоимость.
*/

int main() {
    setlocale(LC_ALL, "Rus");

    char category;
    int age;
    int experience;

    std::cout << "Введите категорию (A/B/C): ";
    std::cin >> category;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    std::cout << "Введите стаж: ";
    std::cin >> experience;

    double cost;

    switch (category) {
    case 'A':
        cost = 300;
        break;
    case 'B':
        cost = 450;
        break;
    case 'C':
        cost = 650;
        break;
    default:
        std::cout << "Ошибка: неизвестная категория\n";
        return -1;
    }

    if (age < 18 || experience < 0 || experience > age - 18) {
        std::cout << "Ошибка: стаж не согласуется с возрастом\n";
        return -1;
    }

    if (age < 25) {
        cost = cost * 1.2;
    }
    if (experience < 2) {
        cost = cost * 1.25;
    }

    std::cout << "Категория: " << category << "\n";
    std::cout << "Итоговая учебная стоимость: " << cost << "\n";

    return 0;
}