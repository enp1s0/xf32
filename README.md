# A rounding function for X Float 32

XF32 (X Float 32) is a floating point format which has 1-bit sign, 8-bit exponent and X-bit mantissa.
It corresponds to TF32(Tensor Float 32) when X equals to 10.


## Sample program
```cpp
#include <xf32.hpp>

int main() {
	const auto v = static_cast<float>(1.2345566f);

	// X = 10
	const auto xf32 = xf32::rounding<10>(v);
}
```

## Support
- C++ >= 11
- This library also can be used in CUDA device functions
