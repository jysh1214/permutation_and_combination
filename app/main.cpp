#include <iostream>
#include <vector>

#include "permutation.h"

namespace
{
    template <typename T>
    static void printVec(std::vector<T>& input)
    {
        for (size_t i = 0; i < input.size(); ++i) {
            std::cout << input[i];
            if (i != input.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<size_t> a{1, 2, 3, 4};
    printVec<size_t>(a);
    nextPermutation<size_t>(a);
    printVec<size_t>(a);
    std::cout << std::endl;

    std::vector<size_t> b{ 1, 2, 3, 4 };
    std::vector<std::vector<size_t>> b_perms;
    allPermutation<size_t>(b, b_perms);

    for (auto perm : b_perms) {
        printVec<size_t>(perm);
    }

    return 0;
}