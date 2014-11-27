/*
Simple test program for integer

The MIT License (MIT)

Copyright (c) 2013, 2014 Jason Lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <iostream>
#include <sstream>

#include "integer.h"

// quick and dirty type-to-string converter
// because cygwin/mingw g++ std::to_string doesn't work
template <typename T> std::string to_str(const T & value, const uint8_t & base = 10){
    std::stringstream s;
    if (base == 8){
        s << std::oct;
    }
    else if (base == 16){
        s << std::hex;
    }
    else{
        s << std::dec;
    }
    if (value < 0){
        s << (int64_t) value;
    }
    else if (value >= 0){
        s << (uint64_t) value;
    }
    return s.str();
}

int main(){
    // positive
    bool        b       = true;
    uint8_t     u8      = 0xfe;
    uint16_t    u16     = 0xfedcU;
    uint32_t    u32     = 0xfedcba98UL;
    uint64_t    u64     = 0xfedcba9876543210ULL;

    // negative
    int8_t      i8      = 0xfe;
    int16_t     i16     = 0xfedc;
    int32_t     i32     = 0xfedbca98L;
    int64_t     i64     = 0xfedcba9876543210LL;

    std::string str_8   = "37667135230";                                // base 8
    std::string str_10  = "4275878552";                                 // base 10
    std::string str_16  = "fedcba98";                                   // base 16
    std::string str_256 = "This is a string.";                          // base 256
    std::string str_val = "28722506059135649064412913099795503933230";  // decimal representation of str_256

    // convert everything to integers
    integer integer_bool(b);
    integer integer_uint8_t(u8);
    integer integer_uint16_t(u16);
    integer integer_uint32_t(u32);
    integer integer_uint64_t(u64);
    integer integer_int8_t(i8);
    integer integer_int16_t(i16);
    integer integer_int32_t(i32);
    integer integer_int64_t(i64);
    integer integer_str_8(str_8, 8);
    integer integer_str_10(str_10, 10);
    integer integer_str_16(str_16, 16);
    integer integer_str_256(str_256, 256);

    std::cout << "Constructors and str function" << std::endl
              << "    bool               " << ((integer_bool.str(10) == to_str(b))?"Good":"Bad")       << std::endl
              << "    uint8_t            " << ((integer_uint8_t.str(10) == to_str(u8))?"Good":"Bad")   << std::endl
              << "    uint16_t           " << ((integer_uint16_t.str(10) == to_str(u16))?"Good":"Bad") << std::endl
              << "    uint32_t           " << ((integer_uint32_t.str(10) == to_str(u32))?"Good":"Bad") << std::endl
              << "    uint64_t           " << ((integer_uint64_t.str(10) == to_str(u64))?"Good":"Bad") << std::endl
              << "    int8_t             " << ((integer_int8_t.str(10) == to_str(i8))?"Good":"Bad")    << std::endl
              << "    int16_t            " << ((integer_int16_t.str(10) == to_str(i16))?"Good":"Bad")  << std::endl
              << "    int32_t            " << ((integer_int32_t.str(10) == to_str(i32))?"Good":"Bad")  << std::endl
              << "    int64_t            " << ((integer_int64_t.str(10) == to_str(i64))?"Good":"Bad")  << std::endl
              << "    base 8             " << ((integer_str_8.str(8) == str_8)?"Good":"Bad")           << std::endl
              << "    base 10            " << ((integer_str_10.str(10) == str_10)?"Good":"Bad")        << std::endl
              << "    base 16            " << ((integer_str_16.str(16) == str_16)?"Good":"Bad")        << std::endl
              << "    base 256           " << ((integer_str_256.str(10) == str_val)?"Good":"Bad")      << std::endl
              << std::endl

              << "Typecast operators" << std::endl
              << "    bool               " << ((static_cast <bool> (integer_bool) == b)?"Good":"Bad")           << std::endl
              << "    uint8_t            " << ((static_cast <uint8_t> (integer_uint8_t) == u8)?"Good":"Bad")    << std::endl
              << "    uint16_t           " << ((static_cast <uint16_t> (integer_uint16_t) == u16)?"Good":"Bad") << std::endl
              << "    uint32_t           " << ((static_cast <uint32_t> (integer_uint32_t) == u32)?"Good":"Bad") << std::endl
              << "    uint64_t           " << ((static_cast <uint64_t> (integer_uint64_t) == u64)?"Good":"Bad") << std::endl
              << "    int8_t             " << ((static_cast <int8_t> (integer_int8_t) == i8)?"Good":"Bad")      << std::endl
              << "    int16_t            " << ((static_cast <int16_t> (integer_int16_t) == i16)?"Good":"Bad")   << std::endl
              << "    int32_t            " << ((static_cast <int32_t> (integer_int32_t) == i32)?"Good":"Bad")   << std::endl
              << "    int64_t            " << ((static_cast <int64_t> (integer_int64_t) == i64)?"Good":"Bad")   << std::endl
              << std::endl

              << "Bitwise operators" << std::endl
              << "    A & A              " << (((integer_uint32_t & integer_uint32_t) == u32)?"Good":"Bad")         << std::endl
              << "    A & B              " << (((integer_uint32_t & integer_uint64_t) == (u32 & u64))?"Good":"Bad") << std::endl
              << "    A | A              " << (((integer_uint32_t | integer_uint32_t) == (u32))?"Good":"Bad")       << std::endl
              << "    A | B              " << (((integer_uint32_t | integer_uint64_t) == (u32 | u64))?"Good":"Bad") << std::endl
              << "    A ^ A              " << (((integer_uint32_t ^ integer_uint32_t) == 0)?"Good":"Bad")           << std::endl
              << "    A ^ B              " << (((integer_uint32_t ^ integer_uint64_t) == (u32 ^ u64))?"Good":"Bad") << std::endl
              << std::endl

              << "Bitshift operators" << std::endl
              << "    A << B             " << (((integer_uint16_t << 9) == (u16 << 9))?"Good":"Bad") << std::endl
              << "    A >> B             " << (((integer_uint64_t >> 32) == u32)?"Good":"Bad")       << std::endl

              << std::endl
              << "Comparison operators" << std::endl
              << "    A == A             " << ((integer_uint32_t == integer_uint32_t)?"Good":"Bad") << std::endl
              << "    A == B             " << ((integer_uint32_t == integer_uint64_t)?"Bad":"Good") << std::endl
              << "    A != A             " << ((integer_uint32_t != integer_uint32_t)?"Bad":"Good") << std::endl
              << "    A != B             " << ((integer_uint32_t != integer_uint64_t)?"Good":"Bad") << std::endl
              << std::endl

              << "    -big   <  -small   " << ((integer_int64_t < integer_int8_t)?"Good":"Bad")     << std::endl
              << "    -small <  -big     " << ((integer_int8_t < integer_int64_t)?"Bad":"Good")     << std::endl
              << "    small  <  big      " << ((integer_uint8_t < integer_uint64_t)?"Good":"Bad")   << std::endl
              << "    big    <  small    " << ((integer_uint64_t < integer_uint8_t)?"Bad":"Good")   << std::endl
              << "    -big   <= -small   " << ((integer_int64_t <= integer_int8_t)?"Good":"Bad")    << std::endl
              << "    -small <= -big     " << ((integer_int8_t <= integer_int64_t)?"Bad":"Good")    << std::endl
              << "    small  <= big      " << ((integer_uint8_t <= integer_uint64_t)?"Good":"Bad")  << std::endl
              << "    big    <= small    " << ((integer_uint64_t <= integer_uint8_t)?"Bad":"Good")  << std::endl
              << std::endl

              << "    -big   >  -small   " << ((integer_int64_t > integer_int16_t)?"Bad":"Good")    << std::endl
              << "    -small >  -big     " << ((integer_int16_t > integer_int64_t)?"Good":"Bad")    << std::endl
              << "    small  >  big      " << ((integer_uint16_t > integer_uint64_t)?"Bad":"Good")  << std::endl
              << "    big    >  small    " << ((integer_uint64_t > integer_int64_t)?"Good":"Bad")   << std::endl
              << "    -big   >= -small   " << ((integer_int64_t >= integer_int16_t)?"Bad":"Good")   << std::endl
              << "    -small >= -big     " << ((integer_int16_t >= integer_int64_t)?"Good":"Bad")   << std::endl
              << "    small  >= big      " << ((integer_uint16_t >= integer_uint64_t)?"Bad":"Good") << std::endl
              << "    big    >= small    " << ((integer_uint64_t >= integer_int64_t)?"Good":"Bad")  << std::endl
              << std::endl

              << "Arithmetic operators" << std::endl
              << "    A + B              " << (((integer_uint64_t + integer_uint32_t) == (u64 + u32))?"Good":"Bad") << std::endl
              << "    A - B              " << (((integer_uint64_t - integer_uint32_t) == (u64 - u32))?"Good":"Bad") << std::endl
              << "    A * B              " << (((integer_uint16_t * integer_uint8_t) == (u16 * u8))?"Good":"Bad")   << std::endl
              << "    A / B              " << (((integer_uint64_t / integer_uint32_t) == (u64 / u32))?"Good":"Bad") << std::endl
              << "    A % B              " << (((integer_uint64_t % integer_uint32_t) == (u64 % u32))?"Good":"Bad") << std::endl

              << std::endl;

    return 0;
}