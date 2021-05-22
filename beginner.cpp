#include <immintrin.h>

void simd_mul4(float* ptr1,float* ptr2)
{
    __m128 x = _mm_loadu_ps(ptr1);
    __m128 y = _mm_loadu_ps(ptr2);

}
