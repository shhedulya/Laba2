#include <iostream>
#include <clocale>

/*
Задание 4
Ввести категорию A/B/C, возраст 18..80, стаж, количество случаев и признак расширенного покрытия 0/1. 
Через switch задать базу 300/450/650. Проверить, что стаж не превышает age-18. 
Затем последовательно применить: возраст <25 — +20%, стаж <2 — +25%, cases>=2 — +40%. 
Если cases==0 и стаж>=5, после надбавок уменьшить сумму на 10%.
Расширенное покрытие добавляет фиксированные 80. Вывести все применённые правила и итог. 
Это учебная модель, а не реальный страховой расчёт.
*/

int main() {
    setlocale(LC_ALL, "Rus");

    char category;
    int age;
    int experience;
    int cases;
    int extended;

    std::cout << "Введите категорию (A/B/C): ";
    std::cin >> category;
    std::cout << "Введите возраст (18-80): ";
    std::cin >> age;
    std::cout << "Введите стаж: ";
    std::cin >> experience;
    std::cout << "Введите количество страховых случаев: ";
    std::cin >> cases;
    std::cout << "Расширенное покрытие (0 - нет, 1 - да): ";
    std::cin >> extended;

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

    if (age < 18 || age > 80) {
        std::cout << "Ошибка: возраст должен быть от 18 до 80\n";
        return -1;
    }
    else if (experience < 0 || experience > age - 18) {
        std::cout << "Ошибка: стаж обязан быть не менее, чем на 18 лет, меньше возраста\n";
        return -1;
    }
    else if (cases < 0) {
        std::cout << "Ошибка: количество случаев не может быть отрицательным\n";
        return -1;
    }
    else if (extended != 0 && extended != 1) {
        std::cout << "Ошибка: признак покрытия должен быть 0 или 1\n";
        return -1;
    }

    std::cout << "Категория " << category << ", базовая стоимость: " << cost << "\n";

    if (age < 25) {
        cost = cost * 1.2;
        std::cout << "Возраст меньше 25: +20%\n";
    }
    if (experience < 2) {
        cost = cost * 1.25;
        std::cout << "Стаж меньше 2 лет: +25%\n";
    }
    if (cases >= 2) {
        cost = cost * 1.4;
        std::cout << "Два и более страховых случая: +40%\n";
    }
    if (cases == 0 && experience >= 5) {
        cost = cost * 0.9;
        std::cout << "Нет случаев и стаж от 5 лет: -10%\n";
    }
    if (extended == 1) {
        cost = cost + 80;
        std::cout << "Расширенное покрытие: +80\n";
    }

    std::cout << "Итоговая учебная стоимость: " << cost << "\n";

    return 0;
}