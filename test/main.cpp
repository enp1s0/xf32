#include <iostream>
#include <random>
#include <cmath>
#include <xf32.hpp>

void evaluate(const float a, const float base) {
	const auto error = std::abs((a - base) / base);
	std::printf("%e\n", error);
}

int main() {
	std::mt19937 mt(std::random_device{}());
	const auto v = std::uniform_real_distribution<float>{-1e7, 1e7}(mt);

	evaluate(xf32::rounding< 1>(v), v);
	evaluate(xf32::rounding< 2>(v), v);
	evaluate(xf32::rounding< 3>(v), v);
	evaluate(xf32::rounding< 4>(v), v);
	evaluate(xf32::rounding< 5>(v), v);
	evaluate(xf32::rounding< 6>(v), v);
	evaluate(xf32::rounding< 7>(v), v);
	evaluate(xf32::rounding< 8>(v), v);
	evaluate(xf32::rounding< 9>(v), v);
	evaluate(xf32::rounding<10>(v), v);
	evaluate(xf32::rounding<11>(v), v);
	evaluate(xf32::rounding<12>(v), v);
	evaluate(xf32::rounding<13>(v), v);
	evaluate(xf32::rounding<14>(v), v);
	evaluate(xf32::rounding<15>(v), v);
	evaluate(xf32::rounding<16>(v), v);
	evaluate(xf32::rounding<17>(v), v);
	evaluate(xf32::rounding<18>(v), v);
	evaluate(xf32::rounding<19>(v), v);
	evaluate(xf32::rounding<20>(v), v);
	evaluate(xf32::rounding<21>(v), v);
	evaluate(xf32::rounding<22>(v), v);
}
