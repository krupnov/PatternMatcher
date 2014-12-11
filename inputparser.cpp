#include "inputparser.h"

#include <string>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <iostream>
#include <sstream>

namespace {

    template<typename T>
    T parse(std::wstring token)
    {
        T n;
        std::wstringstream ss(token);
        ss >> n;
        if (ss.fail())
        {
            throw std::invalid_argument("Inalid file format");
        }

        return n;
    }
}

namespace inputparser {

    matrix_type parseInputFile(const std::string& fileName)
    {
        std::wifstream input(fileName.c_str(), std::ifstream::in);
        if (!input.is_open())
        {
            throw std::invalid_argument("File not foud");
        }
        input.imbue(std::locale("en_US.UTF8"));
        std::vector<wchar_t> buffer(1000);
        input.getline(buffer.data(), buffer.size(), L' ');
        size_t n = parse<size_t>(buffer.data());
        input.getline(buffer.data(), buffer.size());
        size_t m = parse<size_t>(buffer.data());
        if (n == 0 || m == 0)
        {
            throw std::invalid_argument("Zero dimensions not allowed");
        }
        buffer.resize(n * m + 2);
        input.getline(buffer.data(), buffer.size());
        std::wstring data(buffer.data());
        if (data.size() != n * m)
        {
            throw std::invalid_argument("Invalid data size");
        }
        matrix_type result;
        for (size_t i = 0 ; i < n ; ++i)
        {
            std::vector<wchar_t> row;
            for (size_t j = 0 ; j < m ; ++j)
            {
                row.push_back(data.at(i * m + j));
            }
            result.push_back(row);
        }
        return result;
    }
}