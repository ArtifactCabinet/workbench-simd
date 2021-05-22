#include <immintrin.h>
#include <iostream>

// ./cpt.py -s ./simd_vect.cpp -c ./build/simd_vect

void SIMD_plus_4int_fixed(int32_t *first, int32_t *second)
{
    __m128i vec_first  =  _mm_loadu_si128((__m128i*) &first[0]);
    __m128i vec_second = _mm_loadu_si128((__m128i*) &second[0]);

    vec_first = _mm_add_epi32(vec_first, vec_second);
    _mm_storeu_si128((__m128i*) &first[0], vec_first);
}


void SIMD_check_sorted_dynamic(int32_t* a, size_t n) {

    size_t i = 0;
    if (n > 4) {
        for (; i < n - 4; i += 4) {
            const __m128i a1 = _mm_loadu_si128((__m128i*)(a + i));
            const __m128i a2 = _mm_loadu_si128((__m128i*)(a + i + 1));

            const __m128i compared = _mm_cmpgt_epi32(a1, a2);
            if (!_mm_test_all_zeros(compared, compared)) {
                std::cout<< "false" << std::endl;
                return;
            }
        }
    }

    for (; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) {
            std::cout << "false" << std::endl;
            return;
        }
    }

    std::cout<< "true" << std::endl;
}

template<typename T, int size>
int len(T(&)[size]){return size;}

int main()
{
    int32_t one[4]{1,2,3,4};
    int32_t two[4]{5,6,7,8};

    SIMD_plus_4int_fixed(one,two);

    //[[ 681012 ]]
    for (auto x: one) { std::cout << x;}
    std::cout<<std::endl;

    int32_t even_unsorted[8]{3, 2, 1, 4, 5, 6, 7, 8};
    int32_t even_sorted[8]{1,2,3,4,5,6,7,8};
    int32_t odd_sorted[9]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int32_t odd_unsorted[9]{10, 2, 3, 4, 5, 6, 7, 8, 9};


    //[[ false ]]
    SIMD_check_sorted_dynamic(even_unsorted, len(even_unsorted));
    //[[ true ]]
    SIMD_check_sorted_dynamic(even_sorted, len(even_sorted));
    //[[ true ]]
    SIMD_check_sorted_dynamic(odd_sorted, len(odd_sorted));
    //[[ false ]]
    SIMD_check_sorted_dynamic(odd_unsorted, len(odd_unsorted));

    std::exit(0);
}
