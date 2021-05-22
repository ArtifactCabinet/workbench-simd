#SIMD (Single instruction, multiple data)

SIMD is a type of Instruction-level parallelism.

Acronym -> SSE (Streaming SIMD Extensions) and AVX (Advanced Vector Extensions).

# Documents
+ The book <http://const.me/articles/simd/simd.pdf>
+ The Intel Intrinsics Guide <https://software.intel.com/sites/landingpage/IntrinsicsGuide/#techs=MMX,SSE,SSE2,SSE3,SSSE3,SSE4_1,SSE4_2,AVX,AVX2>
+ Cheatsheet <https://www.officedaytime.com/simd512e/?mf=0&mt=8&mc=0>
+ Classes Quick Reference
+ <https://software.intel.com/content/www/us/en/develop/documentation/oneapi-dpcpp-cpp-compiler-dev-guide-and-reference/top/compiler-reference/libraries/intel-c-class-libraries/classes-quick-reference.html>

# Technical Notes

Probably only works with Intel x86_64 on Linux (GCC)

Intel Core i7-9700 CPU (Skylake -> Coffee Lake):

+ Instruction Set Extensions: Intel® SSE4.1, Intel® SSE4.2, Intel® AVX2


## Reality

According to Steam, SSE4.2 & AVX2 means 80%+ modern computers.

https://store.steampowered.com/hwsurvey/

## Review types

* 1 byte -> two hexadecimal digits -> 0x00
* float -> 32 bits/4bytes
* double-> 64 bits/8bytes

128 bits vector -> 16 bytes -> 4x floats or 2x double

256 bits -> 32 bytes -> 8x floats or 4x double

float32 -> Sign bit (1) + Exponent width (8 bits) + Significand precision (23 bits) -> Significant digits	6~7

### SIMD Types:

|Data Types | Description | 
|---------- |:-----------:|
| __m128    | 4 floats   |
| __m128d   | 2 doubles   | 
| __m256    | 8 floats    |
| __m256d   | 4 doubles    |    
|__m128i    | Any integers|
|__m256i    | Any integers|

`__m256i` -> 32 bytes -> 32 int8_t(char) -> 16 int16_t(short) -> 8 int32_t(int) -> 4 int64_t(long)

`__m128` is defined in GCC as 
```C
typedef float __m128 __attribute__ ((__vector_size__ (16), __may_alias__));

```

int32_t -> max 2^(32)-1 = 2,147,483,647 min -2^(32-1) = - 2,147,483,648

#### Different types of values in vectors

+ `si128` – signed 128-bit integer  
+ `epi8`, `epi32`, `epi64` — 16 signed 8-bit integers or 4 signed 32-bit integers or 2 64-bit integers
+ `epu8` — 16 unsigned 8-bit integers (when there is a difference between what an operation would do with signed and unsigned numbers, such as with conversion to a larger integer or multiplication)
+ `epu16`, `epu32` — 8 unsigned 16-bit integers or 4 unsigned 32-bit integers (when the operation would be different from signed)
+ `ps` — “packed single” — 4 single-precision floats
+ `pd` — “packed double” — 2 doubles
+ `ss` — one float (only 32-bits of a 128-bit value are used)
+ `sd` — one double (only 64-bits of a 128-bit value are used)
