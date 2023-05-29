#pragma once

#include <iostream>
#include <string>


class big_integer {
public:
    big_integer(const std::string &number = "0") : m_number(number) {}
    big_integer(const size_t &number) : m_number(std::to_string(number)) {}
    big_integer(const big_integer &other) : big_integer(other.m_number) {}
    big_integer(big_integer &&other) noexcept : m_number(std::move(other.m_number)) {}

    big_integer& operator=(const big_integer &other);
    big_integer& operator=(big_integer &&other) noexcept;
    big_integer operator+(const big_integer &other);
    big_integer operator*(const big_integer &other);
    big_integer operator*(const size_t &num);

private:
    std::string m_number;

    void multiplication(big_integer &result, big_integer &temp_num);

    friend std::ostream& operator<<(std::ostream& os, const big_integer& obj);
};
