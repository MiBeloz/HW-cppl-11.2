#include <iostream>

#include "big_integer.h"


int main() {
#if WIN32
    setlocale(LC_ALL, "ru");
#endif
    std::cout << "\t������� �����\n" << std::endl;

    {
        std::cout << "����� �����:" << std::endl;
        auto number1 = big_integer("114575");
        auto number2 = big_integer("78524");
        std::cout << "\t����� 1: " << number1 << std::endl;
        std::cout << "\t����� 2: " << number2 << std::endl;
        std::cout << "\t���������� �����:  " << number1 + number2 << std::endl;
        std::cout << "\t����������� �����: " << 114575 + 78524 << std::endl << std::endl;
    }

    {
        std::cout << "��������� �� �����:" << std::endl;
        size_t num_start = 0;
        size_t num_end = 10000;
        size_t step = 2026;

        size_t num = 563;
        size_t num_step = 862;

        for (size_t i = num_start; i < num_end; i += step, num += 862) {
            auto number = big_integer(num);
            std::cout << "\t����� 1: " << number << std::endl;
            std::cout << "\t����� 2: " << i << std::endl;
            std::cout << "\t���������� �����:  " << number * i << std::endl;
            std::cout << "\t����������� �����: " << num * i << std::endl << std::endl;
        }
    }

    {
        std::cout << "��������� ����� ������� �����:" << std::endl;
        size_t num = 5643269487;
        auto number = big_integer("6459134876312645915375645915243562819842157684951435975462712564565467216417897215674812546818645");
        std::cout << "\t����� 1: " << number << std::endl;
        std::cout << "\t����� 2: " << num << std::endl;
        std::cout << "\t���������� �����:  " << number * num << std::endl;
        // ����������� ����� - ��������� � ��������� :)
        std::cout << "\t����������� �����: " << "36450638759912673766474566736410186234382926619728997717162806521863818556309944797919927759906418251185115" << std::endl;
    }

    std::cin.get();
    return 0;
}