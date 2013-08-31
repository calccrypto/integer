integer
An Arbitrary Precision Integer Type
by Jason Lee @ calccrypto at gmail.com

Please see LICENSE file for license.

With much help from:
    Auston Sterling - Initial debugging and coding help and FFT multiplication
    Corbin @ Code Review (StackExchange) - wrote a sizeable chunk of code and suggestions
    Keith Nicholas  @ Code Review (StackExchange)
    ROBOKITTY @ Code Review (StackExchange)
    Winston Ewert @ Code Review (StackExchange) - suggested many improvements

This is an implementation of an arbitrary precision integer
container. The actual limit of how large the integers can
be is std::deque <Z>().max_size() * sizeof(Z) * 8 bits, which
should be enormous. Most of the basic operators are implemented,
although their outputs might not necessarily be the same output
as a standard version of that operator. Anything involving
pointers and addresses should be taken care of by C++.

Data is stored in big endian, so value[0] is the most
significant digit, and value[value.size() - 1] is the
least significant digit.

Negative values are stored as their positive value,
with a bool that says the value is negative.

NOTE: Build with the newest compiler. Some functions are only
      supported in the latest versions of C++ compilers and
      standards.

NOTE: Base256 strings are assumed to be postive when read into
      integer. Use operator-() to negate the value.

NOTE: Multiple algorithms for subtraction, multiplication, and
      division have been implemented and commented out. They
      should all work, but are there for educational purposes.
      If one is faster than another on different systems, by
      all means change which algorithm is used. Just make sure
      all related functions are changed as well.

NOTE: All algorithms operate on positive values only. The
      operators deal with the signs.

NOTE: Changing the internal representation to a std::string
      makes integer run slower than using a std::deque <uint8_t>
