// mask
// if i want to hide sth and only expose what i want, i can use masking
// say flag is the one i want to mask
// I would:
// int mask = 2 ---- which is 000000010
// flag = flag & mask or flag &= mask
// this will make flag[1] unchange, but the rest all to zero
// because & 0 is always 0, no matter 0 or 1 & 1 is itself.

// A classic way:
// char &= 0xff because 0xff is 11111111 in binary, 255 in decimal, 0377 in
// octal

// Turning bits on:
// flags = flags | MASK;
// say flags is 00001111 and MASK is 10110110.
// flags | MASK is(10111111)
// All the bits that are set to 1 in MASK are also set to
// 1 in the result. All the bits in flags that corresponded to 0 bits in MASK
// are left unchanged.

// Turning bits off:
// flags = flags & ~MASK;
// becomes(00001111) & ^(10110110)
// is (00001001)
