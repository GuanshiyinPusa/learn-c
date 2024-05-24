// Bitwise Operators:
// Bitwise negation ~: flip 0 to 1, 1 to 0
// Bitwise AND & : two 1 makes 1, otherwise 0
// Bitwise OR | : two 0 makes 0, otherwise 1
// Bitwise XOR ^ : two different bits makes 1, otherwise 0
// Bitwise left shift << : shift left by n bits
// Bitwise right shift >> : shift right by n bits
//
// Bitwise negation Example:
// ~(00001111) is 11110000

// Bitwise And Example:
// (10010011) & (00111101) is 00010001
// 10010011
// 00111101
// 00010001

// Bitwise Or Example
// (10010011) & (00111101) is 10111111
// 10010011
// 00111101
// 10111111

// Bitwise XOR Example
// (10010011) | (00111101) is 10101110
// 10010011
// 00111101
// 10101110

// Masks
// A mask is a bit pattern for isolating a specific bit or bits within a byte or
// word. For example, a symbolic constant is defined MASK as 2, which is
// 00000010 in binary.
// And this statement: flags = flags & MASK;
// will cause all the bits in flags to be zeroed except the second bit from the
// right. -- in this analogy, we think 0 as opaque and 1 as transparent.
// Common usage:
// ch &= 0x7F; or ch &= 0377;
// because 0x7F is 01111111 in binary, and 0377 is 11111111 in binary, so it
// will leave the final 8 bits of ch alone and set the rest to zero.

// Setting bits(Turning bits on)
// To set a bit, we use the bitwise OR operator |.
// For example, if I want to turn the 1 bit while leaving others unchanged.
// flags = flags | MASK;
// This sets bit 1 in flags to 1, while leaving the other bits unchanged.

// Clearing bits(Turning bits off)
// if you want to turn off bit 1 in flags, you can use the bitwise AND operator
// flags = flags & ~MASK;
// because MASK is all 0s except bit 1, and ~MASK is all 1s except bit 1.
// 1 combined with any bit is that bit, and 0 combined with any bit is 0.
// so it leaves all the bits in flags unchanged except bit 1.

// Toggling bits(Turn off if its on, turn on if its off)
// flags = flags ^ MASK;
// For example, flags is 00001111, and MASK is 00001000, then flags will be
// 00000111 after the operation. So all the bits set to 1 in MASK will make
// flags to toggle.

// Checking bits
// To check if a bit is on or off, we use the bitwise AND operator.
// we can't use:
// if (flags = MASK) because it will set flags to MASK, not compare them.
// Instead, we use:
// if ((flags & MASK) == MASK)

// Bitwise Shift Operators
// Left shift: <<
// (10001010) << 2 is 00101000, so it is kinda mutiplying by the n power of 2
// Right shift: >>
// for unsigned value:
// (10001010) >> 2 is 00100010, so it is kinda dividing by the n power of 2
// for signed value:
// Arithmetic right shift -- replicating the sign bit in the leftmost bits
// (10001010) >> 2 is 11100010
// Logical right shift -- fill the leftmost bits with 0
// (10001010) >> 2 is 00100010
// The difference between the two is that the logical right shift is used for
// unsigned values, and the arithmetic right shift is used for signed values.
// In my machine -- linux C, the bitwise right shift is arithmetic right shift
// for signed and unsigned values.
