#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>
#include <fstream>
#include "splitString.h"
#include "Vector.h"
#include "BankCard.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream inputFile;
    std::ofstream outputFile;

    try {
        std::string inputFileName, outputFileName;
        std::cout << "Введите имя файла с входными данными:\n";
        std::cin >> inputFileName;
        if (std::cin.fail())
            throw std::invalid_argument("Не удалось считать имя файла с входными данными!");
        std::cout << "Введите имя файла с выходными данными:\n";
        std::cin >> outputFileName;
        if (std::cin.fail())
            throw std::invalid_argument("Не удалось считать имя файла с выходными данными!");

        inputFile.open(inputFileName);
        if (!inputFile.is_open())
            throw std::invalid_argument("Не удалось открыть файл с входными данными!");
        outputFile.open(outputFileName);
        if (!outputFile.is_open())
            throw std::invalid_argument("Не удалось открыть файл с выходными данными!");

        int entriesNum;
        inputFile >> entriesNum;
        inputFile.ignore(inputFile.rdbuf()->in_avail(), '\n');
        if (inputFile.fail())
            throw std::invalid_argument("Не удалось считать количество записей!");
        Vector<BankCard> bankCardsList;
        std::string entry;
        for (int i = 0; i < entriesNum; i++) {
            std::getline(inputFile, entry);
            Vector<std::string> entryData = splitString(entry);
            if (entryData.size() != 4)
                throw std::invalid_argument("Строка должна содержать 4 значения!");
            if (entryData[0].length() < 2 || entryData[0].length() > 10)
                throw std::invalid_argument("Имя должно быть от 2 до 10 знаков!");
            if (entryData[1].length() < 3 || entryData[1].length() > 15)
                throw std::invalid_argument("Фамилия должна быть от 3 до 15 знаков!");
            if (entryData[2].length() != 16)
                throw std::invalid_argument("Номер карты должен состоять из 16 знаков!");
            if (entryData[3].length() != 5 && entryData[3][2] != '/')
                throw std::invalid_argument("Срок действия должен быть записан в формате mm/yy!");

            BankCard card(entryData[0], entryData[1], entryData[2], entryData[3].substr(0, 2),
                entryData[3].substr(3));
            bankCardsList.pushBack(card);
        }
        bankCardsList.selectionSort();

        Vector<Vector<std::string>> fullNamesList;
        for (size_t i = 0; i < bankCardsList.size(); i++) {
            Vector<std::string> fullName;
            fullName.pushBack(bankCardsList[i].getHolderSurname());
            fullName.pushBack(bankCardsList[i].getHolderName());
            fullNamesList.pushBack(fullName);
        }

        fullNamesList.selectionSort();
        int variousSurnamesCount = 0, equalFullNamesCount = 0;
        size_t i = 0;
        while (i < fullNamesList.size() - 1) {
            size_t j;
            for (j = i + 1; j < fullNamesList.size(); j++) {
                if (fullNamesList[i][0] == fullNamesList[j][0]) {
                    if (fullNamesList[i][1] == fullNamesList[j][1]) {
                        equalFullNamesCount++;
                        if (j = i + 1)
                            equalFullNamesCount++;
                    }
                }
                else {
                    variousSurnamesCount++;
                    if (i == 0)
                        variousSurnamesCount++;
                    break;
                }
            }
            i = j;
        }

        outputFile << "Количество различных фамилий: " << variousSurnamesCount
            << "\nКоличество одинаковых полных имён: " << equalFullNamesCount
            << "\n\nСписок, отсортированный методом выбора:\n" << bankCardsList;
    }
    catch (std::invalid_argument& e) {
        std::cerr << '\n' << "Ошибка: " << e.what() << '\n';
        inputFile.close();
        outputFile.close();
        return -1;
    }
    std::cout << "\nПрограмма успещно выполнена, результат выведен в файл.";

    inputFile.close();
    outputFile.close();
    return 0;
}