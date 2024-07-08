#include <iostream>
#include "Date.h"
using namespace std;


int main() {
    vector<Date> dates;

    dates.push_back({ 2023, 10, 5 });
    dates.push_back({ 2024, 2, 12 });
    dates.push_back({ 2022, 8, 1 });
    dates.push_back({ 2024, 5, 3 });
    dates.push_back({ 2021, 12, 24 });

    // 1. Знайти в контейнері заданий елемент (алгоритм find())
    Date targetDate{ 2024, 5, 3 };
    auto it = find(dates.begin(), dates.end(), targetDate);
    if (it != dates.end()) {
        cout << "Знайдено дату: " << it->year << "." << it->month << "." << it->day << endl;
    }
    else {
        cout << "Не знайдено заданої дати" << endl;
    }

    // 2. Знайти мінімальний елемент і видалити його з контейнера (алгоритм min_element() і метод вектора erase())
    auto minIt = min_element(dates.begin(), dates.end(), compareDates);
    if (minIt != dates.end()) {
        cout << "Видалено мінімальну дату: " << minIt->year << "." << minIt->month << "." << minIt->day << endl;
        dates.erase(minIt);
    }

    // 3. знайти елемент із заданим ключем і видалити його з контейнера (алгоритм find() і метод вектора erase())
    Date keyDate{ 2022, 8, 1 };
    it = find(dates.begin(), dates.end(), keyDate);
    if (it != dates.end()) {
        cout << "Видалено дату з ключем: " << it->year << "." << it->month << "." << it->day << endl;
        dates.erase(it);
    }

    // 4. Замінити всі минулі дати на поточну (алгоритм replace_if())
    replace_if(dates.begin(), dates.end(), isPastDate, time(nullptr));
    cout << "Замінено минулі дати на поточну:" << endl;
    for (const Date& d : dates) {
        cout << d.year << "." << d.month << "." << d.day << endl;
    }

    // 5. Відсортувати контейнер за спаданням і за зростанням (алгоритм sort())
    sort(dates.begin(), dates.end(), compareDates);
    cout << "Сортування за спаданням:" << endl;


}