#include <immintrin.h>
#include <iostream>

void SIMD_plus_4int_fixed(int32_t *first, int32_t *second)
{
    __m128i vec_first  =  _mm_loadu_si128((__m128i*) &first[0]);
    __m128i vec_second = _mm_loadu_si128((__m128i*) &second[0]);

    vec_first = _mm_add_epi32(vec_first, vec_second);
    _mm_storeu_si128((__m128i*) &first[0], vec_first);
}



int main()
{
    int32_t one[4]{1,2,3,4};
    int32_t two[4]{5,6,7,8};

    SIMD_plus_4int_fixed(one,two);

    for (auto x: one)
        std::cout<<x<<std::endl;

    std::exit(0);
}
