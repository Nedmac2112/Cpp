#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

const int COLUMN_WIDTH{30};
int main()
{
     unsigned short int x = 100u;
     cout << "Binary: " << bitset<8>(x) << ", Decimal: " << x << endl; // this will print the binary representation of x, with 16 bits
     cout << "Bitwise left shift (<< 1)" << endl;
     // bitwise left shift
     x = static_cast<unsigned short int>(x << 1); // you have to explicitly cast the result of the bitwise operation, since the data type is smaller than int
     cout << "Binary: " << bitset<8>(x) << ", Decimal: " << x << endl
          << endl;

     unsigned short int y = 100u;
     cout << "Binary: " << bitset<8>(y) << ", Decimal: " << y << endl;
     cout << "Bitwise right shift (>> 1)" << endl;
     // bitwise right shift
     y = static_cast<unsigned short int>(y >> 1);
     cout << "Binary: " << bitset<8>(y) << ", Decimal: " << y << endl
          << endl
          << endl
          << endl;

     unsigned char value1{0x3}; // 0000 0011
     unsigned char value2{0x5}; // 0000 0101

     cout << setw(COLUMN_WIDTH) << "value1 : "
          << setw(COLUMN_WIDTH) << bitset<8>(value1) << endl;

     cout << setw(COLUMN_WIDTH) << "value2 : "
          << setw(COLUMN_WIDTH) << bitset<8>(value2) << endl;

     // AND
     cout << endl;
     cout << "Bitwise AND :  " << endl;
     cout << setw(COLUMN_WIDTH) << "value1 & value2 : "
          << setw(COLUMN_WIDTH) << bitset<8>(value1 & value2) << endl;
     cout << endl;

     // OR
     cout << endl;
     cout << "Bitwise OR :  " << endl;
     cout << setw(COLUMN_WIDTH) << "value1 | value2 : "
          << setw(COLUMN_WIDTH) << bitset<8>(value1 | value2) << endl;
     cout << endl;

     // NOT
     cout << endl;
     cout << "Bitwise NOT " << endl;

     cout << setw(COLUMN_WIDTH) << "~value1 : "
          << setw(COLUMN_WIDTH) << bitset<8>(~value1) << endl;

     cout << setw(COLUMN_WIDTH) << "~value2 : "
          << setw(COLUMN_WIDTH) << bitset<8>(~value2) << endl;

     cout << setw(COLUMN_WIDTH) << "~01011001 : "
          << setw(COLUMN_WIDTH) << bitset<8>(~0b01011001) << endl; // Using bin literal

     cout << setw(COLUMN_WIDTH) << "~01011001 : "
          << setw(COLUMN_WIDTH) << bitset<8>(~0x59) << endl; // Using hex literal
     cout << endl;

     // XOR
     cout << endl;
     cout << "Bitwise XOR :  " << endl;
     cout << setw(COLUMN_WIDTH) << "value1 ^ value2 : "
          << setw(COLUMN_WIDTH) << bitset<8>(value1 ^ value2) << endl;
     cout << endl
          << endl
          << endl;

     // Compound bitwise assignment operators
     cout << "Compound bitwise assignment operators" << endl;

     unsigned char left_shift{0b00110100};
     unsigned char right_shift{0b00110100};
     unsigned char or_operation{0b00110100};
     unsigned char and_operation{0b00110100};
     unsigned char xor_operation{0b00110100};
     unsigned char not_operation{0b00110100};

     unsigned char var_or{0b00001101};
     unsigned char var_and{0b00001101};
     unsigned char var_xor{0b00001101};

     // Print out initial values
     cout << endl;
     cout << "Initial values :  " << endl;
     cout << setw(COLUMN_WIDTH) << "left_shift : "
          << setw(COLUMN_WIDTH) << bitset<8>(left_shift) << endl;
     cout << setw(COLUMN_WIDTH) << "right_shift : "
          << setw(COLUMN_WIDTH) << bitset<8>(right_shift) << endl;
     cout << setw(COLUMN_WIDTH) << "or_operation : "
          << setw(COLUMN_WIDTH) << bitset<8>(or_operation) << endl;
     cout << setw(COLUMN_WIDTH) << "and_operation : "
          << setw(COLUMN_WIDTH) << bitset<8>(and_operation) << endl;
     cout << setw(COLUMN_WIDTH) << "xor_operation : "
          << setw(COLUMN_WIDTH) << bitset<8>(xor_operation) << endl;
     cout << setw(COLUMN_WIDTH) << "not_operation : "
          << setw(COLUMN_WIDTH) << bitset<8>(not_operation) << endl
          << endl;

     cout << setw(COLUMN_WIDTH) << "var_or : "
          << setw(COLUMN_WIDTH) << bitset<8>(var_or) << endl;
     cout << setw(COLUMN_WIDTH) << "var_and : "
          << setw(COLUMN_WIDTH) << bitset<8>(var_and) << endl;
     cout << setw(COLUMN_WIDTH) << "var_xor : "
          << setw(COLUMN_WIDTH) << bitset<8>(var_xor) << endl;
     cout << endl;

     // Compound left shift
     cout << endl;
     cout << "Compound left shift by 2 for left_shift :  " << endl;
     left_shift <<= 2;
     cout << setw(COLUMN_WIDTH) << "left_shift : "
          << setw(COLUMN_WIDTH) << bitset<8>(left_shift) << endl;
     cout << endl;

     // Compound right shift
     cout << endl;
     cout << "Compound right shift by 4 for right_shift :  " << endl;
     right_shift >>= 4;
     cout << setw(COLUMN_WIDTH) << "right_shift : "
          << setw(COLUMN_WIDTH) << bitset<8>(right_shift) << endl;
     cout << endl;

     // Compound OR with var_or
     cout << endl;
     cout << "Compound OR (" << bitset<8>(or_operation) << " |= " << bitset<8>(var_or) << ") :  " << endl;
     or_operation |= var_or;
     cout << setw(COLUMN_WIDTH) << "or_operation : "
          << setw(COLUMN_WIDTH) << bitset<8>(or_operation) << endl;
     cout << endl;

     // Compound AND with var_and
     cout << endl;
     cout << "Compound AND (" << bitset<8>(and_operation) << " &= " << bitset<8>(var_and) << ") :  " << endl;
     and_operation &= var_and;
     cout << setw(COLUMN_WIDTH) << "and_operation : "
          << setw(COLUMN_WIDTH) << bitset<8>(and_operation) << endl;
     cout << endl;

     // Compound XOR with var_xor
     cout << endl;
     cout << "Compound XOR (" << bitset<8>(xor_operation) << " ^= " << bitset<8>(var_xor) << ") :  " << endl;
     xor_operation ^= var_xor;
     cout << setw(COLUMN_WIDTH) << "xor_operation : "
          << setw(COLUMN_WIDTH) << bitset<8>(xor_operation) << endl;
     cout << endl;

     // Compound NOT (bitwise complement)
     cout << endl;
     cout << "Compound NOT (~00110100) :  " << endl;
     not_operation = ~not_operation;
     cout << setw(COLUMN_WIDTH) << "not_operation : "
          << setw(COLUMN_WIDTH) << bitset<8>(not_operation) << endl;
     cout << endl
          << endl
          << endl;

     // Bit Masking
     // Bit masking is a technique used to manipulate individual bits

     const unsigned char mask_bit_0{0b00000001}; // mask to select bit 0
     const unsigned char mask_bit_1{0b00000010}; // mask to select bit 1
     const unsigned char mask_bit_2{0b00000100}; // mask to select bit 2
     const unsigned char mask_bit_3{0b00001000}; // mask to select bit 3
     const unsigned char mask_bit_4{0b00010000}; // mask to select bit 4
     const unsigned char mask_bit_5{0b00100000}; // mask to select bit 5
     const unsigned char mask_bit_6{0b01000000}; // mask to select bit 6
     const unsigned char mask_bit_7{0b10000000}; // mask to select bit 7

     unsigned char value{0b11011010};

     cout << "Initial value: " << bitset<8>(value) << endl;

     // Turn on bit at position 0
     // To turn bit on: value |= (mask)
     // 1101 1010 = (1101 1010 | 0000 0001) --> 1101 1011

     value |= mask_bit_0;
     cout << "After turning on bit at position 0: " << bitset<8>(value) << endl;

     // Turn off bit at position 0
     // To turn bit off: value &= ~(mask)
     // 1101 1011 = (1101 1011 & 1111 1110) --> 1101 1010
     value &= ~mask_bit_0;
     cout << "After turning off bit at position 0: " << bitset<8>(value) << endl;

     return 0;
}
