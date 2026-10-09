#include <iostream>
#include <clocale>
/*
Задание 1
Ввести возраст водителя и стаж. Возраст должен быть от 18 до 80, стаж неотрицательный и не может превышать age - 18. 
Базовая учебная стоимость 300. Если возраст меньше 25, увеличить её на 20%; если стаж меньше 2 лет, после этого увеличить ещё на 25%. 
Вывести итог или сообщение о нелогичных данных.
*/
int main() {
    setlocale(LC_ALL, "Rus");

    int age;
    int experience;

    std::cout << "Введите возраст водителя: ";
    std::cin >> age;
    std::cout << "Введите стаж: ";
    std::cin >> experience;

    if (age < 18 || age > 80) {
        std::cout << "Ошибка: возраст должен быть от 18 до 80\n";
        return -1;
    }
    else if (experience < 0 || experience > age - 18) {
        std::cout << "Ошибка: нелогичный стаж для такого возраста\n";
        return -1;
    }
    else {
        double cost = 300;

        if (age < 25) {
            cost = cost * 1.2;
        }
        if (experience < 2) {
            cost = cost * 1.25;
        }

        std::cout << "Итоговая стоимость: " << cost << "\n";
    }

    return 0;
}