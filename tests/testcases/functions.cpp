#include <random>

#include <gtest/gtest.h>

#include "integer.h"

TEST(Function, negate){
    EXPECT_EQ(integer("-1", 16).negate(), integer("1", 16));    // negative
    EXPECT_EQ(integer().negate(), integer());                   // zero
    EXPECT_EQ(integer("1", 16).negate(), integer("-1", 16));    // positive
}

TEST(Function, twos_complement){
    EXPECT_EQ(integer("0",    2).twos_complement(3), 0);
    EXPECT_EQ(integer("111",  2).twos_complement(3), -1);
    EXPECT_EQ(integer("111",  2).twos_complement(8), -249);

    EXPECT_EQ(integer("255", 10).twos_complement(8), -1);
    EXPECT_EQ(integer("254", 10).twos_complement(8), -2);
    EXPECT_EQ(integer("128", 10).twos_complement(8), -128);
    EXPECT_EQ(integer("127", 10).twos_complement(8), -129);
    EXPECT_EQ(integer("126", 10).twos_complement(8), -130);

    EXPECT_EQ(-integer("1",  10).twos_complement(8),  integer("-1",  10).twos_complement(8));
    EXPECT_EQ(-integer("1",  10).twos_complement(16), integer("-1",  10).twos_complement(16));
    EXPECT_EQ(-integer("1",  10).twos_complement(32), integer("-1",  10).twos_complement(32));
    EXPECT_EQ(-integer("1",  10).twos_complement(64), integer("-1",  10).twos_complement(64));
}

TEST(Function, fill){
    integer value;
    for(uint32_t i = 0; i < 64; i++){
        value.fill(i);
        EXPECT_EQ(value, (((uint64_t) 1) << i) - 1);
    }
}

TEST(Function, index){
    integer value("10", 2); // 1...0
    for(uint32_t i = 0; i < 256; i++){
        EXPECT_EQ(value[0], 0);
        EXPECT_EQ(value[i + 1], 1);
        value <<= 1;
    }
}

TEST(Function, str){
    const std::pair <uint32_t, std::string> tests[] = {
        std::make_pair(2,  "101010001101000011010010111001100100000011010010111001100100000011000010010000001110011011101000111001001101001011011100110011100101110"),
        std::make_pair(8,  "521503227144032271440302201633507115133463456"),
        std::make_pair(10, "28722506059135649064412913099795503933230"),
        std::make_pair(16, "54686973206973206120737472696e672e"),
    };

    // make sure all of the test strings create the ASCII version of the string
    const integer original("This is a string.", 256);
    for(auto t : tests){
        EXPECT_EQ(original.str(t.first), t.second);
    }

    // negative sign shows up with 0
    const integer neg_zero("-0", 10);
    for(auto t : tests){
        EXPECT_EQ(neg_zero.str(t.first), "0");
    }

    // leading zeros show up
    for(auto t : tests){
        EXPECT_EQ(neg_zero.str(t.first, 5), "00000");
    }
}

TEST(External, ostream){
    const integer value("fedcba9876543210", 16);

    // write out octal integer
    std::stringstream oct; oct << std::oct << value;
    EXPECT_EQ(oct.str(), "1773345651416625031020");

    // write out decimal integer
    std::stringstream dec; dec << std::dec << value;
    EXPECT_EQ(dec.str(), "18364758544493064720");

    // write out hexadecimal integer
    std::stringstream hex; hex << std::hex << value;
    EXPECT_EQ(hex.str(), "fedcba9876543210");

    // zero
    std::stringstream zero; zero << integer();
    EXPECT_EQ(zero.str(), "0");
}

TEST(External, istream){
    const integer pos( "fedcba9876543210", 16);
    const integer neg = -pos;
    integer value;

    // read in positive octal integer
    std::stringstream pos_oct("1773345651416625031020");
    pos_oct >> std::oct >> value;
    EXPECT_EQ(value, pos);

    // read in positive decimal integer
    std::stringstream pos_dec("18364758544493064720");
    pos_dec >> std::dec >> value;
    EXPECT_EQ(value, pos);

    // read in positive hexadecimal integer
    std::stringstream pos_hex("fedcba9876543210");
    pos_hex >> std::hex >> value;
    EXPECT_EQ(value, pos);

    // read in negative octal integer
    std::stringstream neg_oct("-1773345651416625031020");
    neg_oct >> std::oct >> value;
    EXPECT_EQ(value, neg);

    // read in negative decimal integer
    std::stringstream neg_dec("-18364758544493064720");
    neg_dec >> std::dec >> value;
    EXPECT_EQ(value, neg);

    // read in negative hexadecimal integer
    std::stringstream neg_hex("-fedcba9876543210");
    neg_hex >> std::hex >> value;
    EXPECT_EQ(value, neg);

    // try a floating point number
    std::stringstream floating("1234.5678");
    EXPECT_THROW(floating >> value, std::runtime_error);

    // try bad characters
    std::stringstream bad("~!@#$%^&*()_+");
    EXPECT_THROW(bad >> value, std::runtime_error);
}

TEST(External, makebin){
    const std::pair <uint32_t, std::string> tests[] = {
        std::make_pair(2,   "101010001101000011010010111001100100000011010010111001100100000011000010010000001110011011101000111001001101001011011100110011100101110"),
        std::make_pair(8,   "521503227144032271440302201633507115133463456"),
        std::make_pair(10,  "28722506059135649064412913099795503933230"),
        std::make_pair(16,  "54686973206973206120737472696e672e"),
        std::make_pair(256, "This is a string."),
    };

    for(auto t : tests){
        EXPECT_EQ(makebin(integer(t.second, t.first)), tests[0].second);
    }

    // negative sign shows up with 0
    const integer neg_zero("-0", 10);
    EXPECT_EQ(makebin(neg_zero), "0");


    // leading zeros show up
    EXPECT_EQ(makebin(neg_zero, 5), "00000");
}

TEST(External, makehex){
    const std::pair <uint32_t, std::string> tests[] = {
        std::make_pair(2,   "101010001101000011010010111001100100000011010010111001100100000011000010010000001110011011101000111001001101001011011100110011100101110"),
        std::make_pair(8,   "521503227144032271440302201633507115133463456"),
        std::make_pair(10,  "28722506059135649064412913099795503933230"),
        std::make_pair(16,  "54686973206973206120737472696e672e"),
        std::make_pair(256, "This is a string."),
    };

    for(auto t : tests){
        EXPECT_EQ(makehex(integer(t.second, t.first)), tests[3].second);
    }

    // negative sign shows up with 0
    const integer neg_zero("-0", 10);
    EXPECT_EQ(makehex(neg_zero), "0");

    // leading zeros show up
    EXPECT_EQ(makehex(neg_zero, 5), "00000");
}

TEST(External, makeascii){
    const std::pair <uint32_t, std::string> tests[] = {
        std::make_pair(2,   "101010001101000011010010111001100100000011010010111001100100000011000010010000001110011011101000111001001101001011011100110011100101110"),
        std::make_pair(8,   "521503227144032271440302201633507115133463456"),
        std::make_pair(10,  "28722506059135649064412913099795503933230"),
        std::make_pair(16,  "54686973206973206120737472696e672e"),
        std::make_pair(256, "This is a string."),
    };

    for(auto t : tests){
        EXPECT_EQ(makeascii(integer(t.second, t.first)), tests[4].second);
    }

    // negative sign shows up with 0
    const integer neg_zero("-0", 10);
    EXPECT_EQ(makeascii(neg_zero), std::string(1, '\x00'));

    // leading zeros show up
    EXPECT_EQ(makeascii(neg_zero, 5), std::string(5, '\x00'));
}

TEST(Miscellaneous, abs){
    const integer pos("12345", 16);
    const integer neg = -pos;

    EXPECT_EQ(abs(pos), pos);
    EXPECT_EQ(abs(neg), pos);
}

TEST(Miscellaneous, log){
    std::default_random_engine gen;
    std::uniform_int_distribution <uint64_t> dst(0, 63);

    for(uint8_t i = 0; i < 10; i++){
        uint64_t shift = dst(gen);
        EXPECT_EQ(log(integer(1) << shift, 2), shift + 1);
    }

    // invalid base
    EXPECT_THROW(log(integer(1), -1), std::domain_error);

    // invalid value
    EXPECT_THROW(log(integer(-1), 1), std::domain_error);

    // invalid base and value
    EXPECT_THROW(log(integer(-1), -1), std::domain_error);
}

TEST(Miscellaneous, pow){
    const integer base  ("3",    10);
    const integer exp   ("1001", 10);
    const integer result("5d8970339fa3ca286c2457af9c3462c73749db289a4a25a6f1d7e60e49d314bde6f1f456c24e123e435a4545469f68f9883ce97aacc052e253cabeade2f8b313bcc748e361f779d8a0af649f9aa256ae0e2d2fa6fa62c9f05ab32741d0a828632eb5c6ce44184a5b1cfe4689badb01585e3912019c12444a086e75221e6b430196faf154fc12b0999a06ce01b9d0455cbfb849dcb2e1361b1d9a58b191e40f214bd446fab70246a131377e0dad97bad94c8c4189d894a4dbc2504e693793b0243ba737b291163", 16);

    EXPECT_EQ(pow( base, exp),  result);
    EXPECT_EQ(pow(-base, exp), -result);
    EXPECT_EQ(pow( base,   0),       1);
    EXPECT_EQ(pow( base,  -1),       0);
}

