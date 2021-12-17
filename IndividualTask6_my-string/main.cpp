#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "splitString.h"
#include "Vector.cpp"
#include "BankCard.h"
#include "String.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream inputFile;
    std::ofstream outputFile;

    try {
        std::string inputFileName, outputFileName;
        std::cout << "������� ��� ����� � �������� �������:\n";
        std::cin >> inputFileName;
        if (std::cin.fail())
            throw std::invalid_argument("�� ������� ������� ��� ����� � �������� �������!");
        std::cout << "������� ��� ����� � ��������� �������:\n";
        std::cin >> outputFileName;
        if (std::cin.fail())
            throw std::invalid_argument("�� ������� ������� ��� ����� � ��������� �������!");

        inputFile.open(inputFileName);
        if (!inputFile.is_open())
            throw std::invalid_argument("�� ������� ������� ���� � �������� �������!");
        outputFile.open(outputFileName);
        if (!outputFile.is_open())
            throw std::invalid_argument("�� ������� ������� ���� � ��������� �������!");

        int entriesNum;
        inputFile >> entriesNum;
        inputFile.ignore(inputFile.rdbuf()->in_avail(), '\n');
        if (inputFile.fail())
            throw std::invalid_argument("�� ������� ������� ���������� �������!");
        Vector<BankCard> bankCardsList;
        std::string entry;
        for (int i = 0; i < entriesNum; i++) {
            std::getline(inputFile, entry);
            Vector<std::string> entryData = splitString(entry);
            if (entryData.size() != 4)
                throw std::invalid_argument("������ ������ ��������� 4 ��������!");
            if (entryData[0].length() < 2 || entryData[0].length() > 10)
                throw std::invalid_argument("��� ������ ���� �� 2 �� 10 ������!");
            if (entryData[1].length() < 3 || entryData[1].length() > 15)
                throw std::invalid_argument("������� ������ ���� �� 3 �� 15 ������!");
            if (entryData[2].length() != 16)
                throw std::invalid_argument("����� ����� ������ �������� �� 16 ������!");
            if (entryData[3].length() != 5 && entryData[3][2] != '/')
                throw std::invalid_argument("���� �������� ������ ���� ������� � ������� mm/yy!");

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

        outputFile << "���������� ��������� �������: " << variousSurnamesCount
            << "\n���������� ���������� ������ ���: " << equalFullNamesCount
            << "\n\n������, ��������������� ������� ������:\n" << bankCardsList;
    }
    catch (std::invalid_argument& e) {
        std::cerr << '\n' << "������: " << e.what() << '\n';
        inputFile.close();
        outputFile.close();
        return -1;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}