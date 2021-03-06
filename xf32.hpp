#ifndef __XF32_HPP__
#define __XF32_HPP__
#include <cstdint>

#ifdef __CUDA_ARCH__
#define __XF32_HOST_DEVICE__ __device__ __host__
#else
#define __XF32_HOST_DEVICE__
#endif

namespace xf32 {
union xf_bitstring {
	float value;
	uint32_t bitstring;
};

template <unsigned mantissa_length>
__XF32_HOST_DEVICE__ inline float rounding(const float value) {
	constexpr uint32_t fp32_mantissa_length = 23;
	const uint32_t mantissa_mask = 0b00000000011111111111111111111111u - (1u << (fp32_mantissa_length - mantissa_length)) - 1;
	const uint32_t bitstring = xf_bitstring{value}.bitstring;

	const uint32_t c0 = bitstring & (1u << (fp32_mantissa_length - mantissa_length - 1));
	const uint32_t m =  bitstring & mantissa_mask;
	const uint32_t e =  bitstring & 0b01111111100000000000000000000000u;
	const uint32_t s =  bitstring & 0b10000000000000000000000000000000u;

	const uint32_t m0 = m + (c0 << 1);
	const uint32_t c1 = (m0 & 0b00000000100000000000000000000000u) >> 23;
	const uint32_t m_pre = m0 & mantissa_mask;
	const uint32_t e_pre = e + (c1 << 23);

	const uint32_t out = s | m_pre | e_pre;
	return *reinterpret_cast<const float*>(&out);
}
} // namespace xf32
#endif
