#include "permutation.h"

#include <math.h>
#include <algorithm>
#include <cstdint>

namespace 
{
	static inline uint64_t factorial(const size_t input)
	{
		uint64_t ans = 1;
		for (int i = 2; i <= input; ++i) {
			ans *= i;
		}

		return ans;
	}
}

template <typename T>
void nextPermutation(std::vector<T>& input)
{
	int i = input.size() - 2;
	for (; i >= 0; --i) {
		if (input[i] < input[i + 1]) {
			break;
		}
	}

	if (i == -1) {
		std::reverse(input.begin(), input.end());
	}
	else {
		for (int j = input.size() - 1; j >= i + 1; --j) {
			if (input[j] > input[i]) {
				std::swap(input[j], input[i]);
				std::reverse(input.begin() + (i + 1), input.end());
				break;
			}
		}
	}
}

template void nextPermutation<size_t>(std::vector<size_t>& input);
template void nextPermutation<char>(std::vector<char>& input);

template <typename T>
void allPermutation(std::vector<T>& input, std::vector<std::vector<T>>& output)
{
	uint64_t limit = factorial(input.size());
	while (limit > 0) {
		std::vector<T> perm = input;
		output.push_back(perm);
		nextPermutation(input);
		limit--;
	}
}

template void allPermutation<size_t>(std::vector<size_t>& input, std::vector<std::vector<size_t>>& output);
template void allPermutation<char>(std::vector<char>& input, std::vector<std::vector<char>>& output);