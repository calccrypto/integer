#include <gtest/gtest.h>

#include "integer.h"

TEST(Constructor, standard){
    integer(123);

    integer value("0123456789abcdef", 16);
    const integer original = value;

    EXPECT_EQ(integer(), 0);
    EXPECT_EQ(value, original);
    EXPECT_EQ(integer(std::move(value)), original);
    EXPECT_EQ(value, 0);
}

TEST(Constructor, bool){
    EXPECT_EQ(integer(true).str(10),  "1");
    EXPECT_EQ(integer(false).str(10), "0");
}

TEST(Constructor, uint8_t){
    // decimal string
    EXPECT_EQ(integer((uint8_t) 0x01).str(10),   "1");
    EXPECT_EQ(integer((uint8_t) 0x23).str(10),  "35");
    EXPECT_EQ(integer((uint8_t) 0x45).str(10),  "69");
    EXPECT_EQ(integer((uint8_t) 0x67).str(10), "103");
    EXPECT_EQ(integer((uint8_t) 0x89).str(10), "137");
    EXPECT_EQ(integer((uint8_t) 0xab).str(10), "171");
    EXPECT_EQ(integer((uint8_t) 0xcd).str(10), "205");
    EXPECT_EQ(integer((uint8_t) 0xef).str(10), "239");
    EXPECT_EQ(integer((uint8_t) 0xfe).str(10), "254");
    EXPECT_EQ(integer((uint8_t) 0xdc).str(10), "220");
    EXPECT_EQ(integer((uint8_t) 0xba).str(10), "186");
    EXPECT_EQ(integer((uint8_t) 0x98).str(10), "152");
    EXPECT_EQ(integer((uint8_t) 0x76).str(10), "118");
    EXPECT_EQ(integer((uint8_t) 0x54).str(10),  "84");
    EXPECT_EQ(integer((uint8_t) 0x32).str(10),  "50");
    EXPECT_EQ(integer((uint8_t) 0x10).str(10),  "16");

    // hex string
    EXPECT_EQ(integer((uint8_t) 0x01).str(16),  "1");
    EXPECT_EQ(integer((uint8_t) 0x23).str(16), "23");
    EXPECT_EQ(integer((uint8_t) 0x45).str(16), "45");
    EXPECT_EQ(integer((uint8_t) 0x67).str(16), "67");
    EXPECT_EQ(integer((uint8_t) 0x89).str(16), "89");
    EXPECT_EQ(integer((uint8_t) 0xab).str(16), "ab");
    EXPECT_EQ(integer((uint8_t) 0xcd).str(16), "cd");
    EXPECT_EQ(integer((uint8_t) 0xef).str(16), "ef");
    EXPECT_EQ(integer((uint8_t) 0xfe).str(16), "fe");
    EXPECT_EQ(integer((uint8_t) 0xdc).str(16), "dc");
    EXPECT_EQ(integer((uint8_t) 0xba).str(16), "ba");
    EXPECT_EQ(integer((uint8_t) 0x98).str(16), "98");
    EXPECT_EQ(integer((uint8_t) 0x76).str(16), "76");
    EXPECT_EQ(integer((uint8_t) 0x54).str(16), "54");
    EXPECT_EQ(integer((uint8_t) 0x32).str(16), "32");
    EXPECT_EQ(integer((uint8_t) 0x10).str(16), "10");
}

TEST(Constructor, uint16_t){
    // decimal string
    EXPECT_EQ(integer((uint16_t) 0x0123).str(10),   "291");
    EXPECT_EQ(integer((uint16_t) 0x4567).str(10), "17767");
    EXPECT_EQ(integer((uint16_t) 0x89ab).str(10), "35243");
    EXPECT_EQ(integer((uint16_t) 0xcdef).str(10), "52719");
    EXPECT_EQ(integer((uint16_t) 0xfedc).str(10), "65244");
    EXPECT_EQ(integer((uint16_t) 0xba98).str(10), "47768");
    EXPECT_EQ(integer((uint16_t) 0x7654).str(10), "30292");
    EXPECT_EQ(integer((uint16_t) 0x3210).str(10), "12816");

    // hex string
    EXPECT_EQ(integer((uint16_t) 0x0123).str(16),  "123");
    EXPECT_EQ(integer((uint16_t) 0x4567).str(16), "4567");
    EXPECT_EQ(integer((uint16_t) 0x89ab).str(16), "89ab");
    EXPECT_EQ(integer((uint16_t) 0xcdef).str(16), "cdef");
    EXPECT_EQ(integer((uint16_t) 0xfedc).str(16), "fedc");
    EXPECT_EQ(integer((uint16_t) 0xba98).str(16), "ba98");
    EXPECT_EQ(integer((uint16_t) 0x7654).str(16), "7654");
    EXPECT_EQ(integer((uint16_t) 0x3210).str(16), "3210");
}

TEST(Constructor, uint32_t){
    // decimal string
    EXPECT_EQ(integer((uint32_t) 0x01234567).str(10),   "19088743");
    EXPECT_EQ(integer((uint32_t) 0x89abcdef).str(10), "2309737967");
    EXPECT_EQ(integer((uint32_t) 0xfedcba98).str(10), "4275878552");
    EXPECT_EQ(integer((uint32_t) 0x76543210).str(10), "1985229328");

    // hex string
    EXPECT_EQ(integer((uint32_t) 0x01234567).str(16),  "1234567");
    EXPECT_EQ(integer((uint32_t) 0x89abcdef).str(16), "89abcdef");
    EXPECT_EQ(integer((uint32_t) 0xfedcba98).str(16), "fedcba98");
    EXPECT_EQ(integer((uint32_t) 0x76543210).str(16), "76543210");
}

TEST(Constructor, uint64_t){
    // decimal string
    EXPECT_EQ(integer((uint64_t) 0x0123456789abcdef).str(10),    "81985529216486895");
    EXPECT_EQ(integer((uint64_t) 0xfedcba9876543210).str(10), "18364758544493064720");

    // hex string
    EXPECT_EQ(integer((uint64_t) 0x0123456789abcdef).str(16),  "123456789abcdef");
    EXPECT_EQ(integer((uint64_t) 0xfedcba9876543210).str(16), "fedcba9876543210");
}

TEST(Constructor, int8_t){
    // decimal string
    EXPECT_EQ(integer((int8_t) 0x01).str(10),    "1");
    EXPECT_EQ(integer((int8_t) 0x23).str(10),   "35");
    EXPECT_EQ(integer((int8_t) 0x45).str(10),   "69");
    EXPECT_EQ(integer((int8_t) 0x67).str(10),  "103");
    EXPECT_EQ(integer((int8_t) 0x89).str(10), "-119");
    EXPECT_EQ(integer((int8_t) 0xab).str(10),  "-85");
    EXPECT_EQ(integer((int8_t) 0xcd).str(10),  "-51");
    EXPECT_EQ(integer((int8_t) 0xef).str(10),  "-17");
    EXPECT_EQ(integer((int8_t) 0xfe).str(10),   "-2");
    EXPECT_EQ(integer((int8_t) 0xdc).str(10),  "-36");
    EXPECT_EQ(integer((int8_t) 0xba).str(10),  "-70");
    EXPECT_EQ(integer((int8_t) 0x98).str(10), "-104");
    EXPECT_EQ(integer((int8_t) 0x76).str(10),  "118");
    EXPECT_EQ(integer((int8_t) 0x54).str(10),   "84");
    EXPECT_EQ(integer((int8_t) 0x32).str(10),   "50");
    EXPECT_EQ(integer((int8_t) 0x10).str(10),   "16");

    // hex string
    EXPECT_EQ(integer((int8_t) 0x01).str(16),   "1");
    EXPECT_EQ(integer((int8_t) 0x23).str(16),  "23");
    EXPECT_EQ(integer((int8_t) 0x45).str(16),  "45");
    EXPECT_EQ(integer((int8_t) 0x67).str(16),  "67");
    EXPECT_EQ(integer((int8_t) 0x89).str(16), "-77");
    EXPECT_EQ(integer((int8_t) 0xab).str(16), "-55");
    EXPECT_EQ(integer((int8_t) 0xcd).str(16), "-33");
    EXPECT_EQ(integer((int8_t) 0xef).str(16), "-11");
    EXPECT_EQ(integer((int8_t) 0xfe).str(16),  "-2");
    EXPECT_EQ(integer((int8_t) 0xdc).str(16), "-24");
    EXPECT_EQ(integer((int8_t) 0xba).str(16), "-46");
    EXPECT_EQ(integer((int8_t) 0x98).str(16), "-68");
    EXPECT_EQ(integer((int8_t) 0x76).str(16),  "76");
    EXPECT_EQ(integer((int8_t) 0x54).str(16),  "54");
    EXPECT_EQ(integer((int8_t) 0x32).str(16),  "32");
    EXPECT_EQ(integer((int8_t) 0x10).str(16),  "10");
}

TEST(Constructor, int16_t){
    // decimal string
    EXPECT_EQ(integer((int16_t) 0x0123).str(10),    "291");
    EXPECT_EQ(integer((int16_t) 0x4567).str(10),  "17767");
    EXPECT_EQ(integer((int16_t) 0x89ab).str(10), "-30293");
    EXPECT_EQ(integer((int16_t) 0xcdef).str(10), "-12817");
    EXPECT_EQ(integer((int16_t) 0xfedc).str(10),   "-292");
    EXPECT_EQ(integer((int16_t) 0xba98).str(10), "-17768");
    EXPECT_EQ(integer((int16_t) 0x7654).str(10),  "30292");
    EXPECT_EQ(integer((int16_t) 0x3210).str(10),  "12816");

    // hex string
    EXPECT_EQ(integer((int16_t) 0x0123).str(16),   "123");
    EXPECT_EQ(integer((int16_t) 0x4567).str(16),  "4567");
    EXPECT_EQ(integer((int16_t) 0x89ab).str(16), "-7655");
    EXPECT_EQ(integer((int16_t) 0xcdef).str(16), "-3211");
    EXPECT_EQ(integer((int16_t) 0xfedc).str(16),  "-124");
    EXPECT_EQ(integer((int16_t) 0xba98).str(16), "-4568");
    EXPECT_EQ(integer((int16_t) 0x7654).str(16),  "7654");
    EXPECT_EQ(integer((int16_t) 0x3210).str(16),  "3210");
}

TEST(Constructor, int32_t){
    // decimal string
    EXPECT_EQ(integer((int32_t) 0x01234567).str(10),    "19088743");
    EXPECT_EQ(integer((int32_t) 0x89abcdef).str(10), "-1985229329");
    EXPECT_EQ(integer((int32_t) 0xfedcba98).str(10),   "-19088744");
    EXPECT_EQ(integer((int32_t) 0x76543210).str(10),  "1985229328");

    // hex string
    EXPECT_EQ(integer((int32_t) 0x01234567).str(16),   "1234567");
    EXPECT_EQ(integer((int32_t) 0x89abcdef).str(16), "-76543211");
    EXPECT_EQ(integer((int32_t) 0xfedcba98).str(16),  "-1234568");
    EXPECT_EQ(integer((int32_t) 0x76543210).str(16),  "76543210");
}

TEST(Constructor, int64_t){
    // decimal string
    EXPECT_EQ(integer((int64_t) 0x0123456789abcdef).str(10),  "81985529216486895");
    EXPECT_EQ(integer((int64_t) 0xfedcba9876543210).str(10), "-81985529216486896");

    // hex string
    EXPECT_EQ(integer((int64_t) 0x0123456789abcdef).str(16),  "123456789abcdef");
    EXPECT_EQ(integer((int64_t) 0xfedcba9876543210).str(16), "-123456789abcdf0");
}

TEST(Constructor, string){
    const std::pair <uint32_t, std::string> tests[] = {
        std::make_pair(2,  "101010001101000011010010111001100100000011010010111001100100000011000010010000001110011011101000111001001101001011011100110011100101110"),
        std::make_pair(8,  "521503227144032271440302201633507115133463456"),
        std::make_pair(10, "28722506059135649064412913099795503933230"),
        std::make_pair(16, "54686973206973206120737472696e672e"),
    };

    const integer expected("This is a string.", 256);

    for(auto t : tests){
        EXPECT_EQ(integer(t.second, t.first), expected);
    }

    // bad character
    EXPECT_THROW(integer("0x0123456789abcdef", 16), std::runtime_error);

    // bad base with contents
    EXPECT_THROW(integer("0123456789abcdef",   33), std::runtime_error);

    // bad base, no contents
    EXPECT_THROW(integer("",                   33), std::runtime_error);
}
