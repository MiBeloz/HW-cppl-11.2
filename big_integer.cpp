#include "big_integer.h"


big_integer& big_integer::operator=(const big_integer &other) {
    return *this = big_integer(other);
}

big_integer& big_integer::operator=(big_integer &&other) noexcept {
    std::swap(m_number, other.m_number);
    return *this;
}

big_integer big_integer::operator+(const big_integer &other) {
    if (other.m_number == "0") {
        return big_integer(*this);
    }

    big_integer temp(*this);
    big_integer temp_other(other);

    if (temp.m_number.size() < temp_other.m_number.size()) {
        size_t different_size = temp_other.m_number.size() - temp.m_number.size();
        for (size_t i = 0; i < different_size; ++i) {
            temp.m_number = "0" + temp.m_number;
        }
        
    }
    else if (temp.m_number.size() > temp_other.m_number.size()) {
        size_t different_size = temp.m_number.size() - temp_other.m_number.size();
        for (size_t i = 0; i < different_size; ++i) {
            temp_other.m_number = "0" + temp_other.m_number;
        }
    }

    bool decade = false;
    for (size_t i = temp.m_number.size(); i > 0; --i) {
        int value = std::stoi(temp.m_number.substr(i - 1, 1)) + std::stoi(temp_other.m_number.substr(i - 1, 1));
        
        if (decade) {
            value++;
        }

        if (value > 9) {
            decade = true;
            value -= 10;
        }
        else {
            decade = false;
        }

        temp.m_number[i - 1] = value + '0';
    }

    if (decade) {
        temp.m_number = "1" + temp.m_number;
    }

    return temp;
}

big_integer big_integer::operator*(const size_t &num) {
    if (num == 0) {
        return big_integer();
    }
    else if (num == 1) {
        return big_integer(*this);
    }

    big_integer result;
    big_integer temp_num(num);

    for (size_t i = 0; i < temp_num.m_number.size(); ++i) {
        big_integer temp(*this);
        int value = 0;
        int rem = 0;
        bool decade = false;

        for (size_t j = temp.m_number.size(); j != 0; --j) {
            value = std::stoi(temp.m_number.substr(j - 1, 1)) * std::stoi(temp_num.m_number.substr(temp_num.m_number.size() - 1 - i, 1)) + rem;

            if (value > 9) {
                decade = true;
                rem = value / 10;
                value %= 10;
            }
            else {
                decade = false;
                rem = 0;
            }

            temp.m_number[j - 1] = value + '0';

            if (j == 1) {
                if (decade) {
                    temp.m_number = std::to_string(rem) + temp.m_number;
                }

                for (size_t k = 0; k < i; ++k) {
                    temp.m_number = temp.m_number + "0";
                }
            }
        }

        result = result + temp;
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const big_integer& obj) {
    return os << obj.m_number;
}
