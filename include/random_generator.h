#pragma once

#include <iostream>
#include <random>
#include <set>
#include <chrono>

using namespace std;


std::vector<int> generateUniqueRandomNumbers(int lowerBound, int upperBound, int count) {
    if (upperBound - lowerBound + 1 < count) {
        std::cerr << "Error: Requested more numbers than available in the range.\n";
        return {};
    }

    std::vector<int> numbers;
    for (int i = lowerBound; i <= upperBound; ++i) {
        numbers.push_back(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers.begin(), numbers.end(), gen);

    numbers.resize(count);
    return numbers;
}
