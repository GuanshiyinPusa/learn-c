/* 1. a. 00000011
 b. 00001101
 c. 00111011
 d. 01110111

 2. a. 21, 025, 0x15
 b. 85, 0125, 0x55
 c. 76, 0114, 0x4C
 d. 157, 0235, 0x9D

 3. a. 252
 b. 2
 c. 7
 d. 7
 e. 5
 f. 3
 g. 28

 4. a. 255
 b. 1 (not false is true)
 c. 0
 d. 1 (true and true is true)
 e. 6
 f. 1 (true or true is true)
 g. 40

 5. In binary, the mask is 1111111. In decimal, it’s 127. In octal, it’s 0177.
In hexadecimal, it’s 0x7F .

 6. Both bitvbal *= 2 and bitval << 1 double the current value of bitval, so
they are equivalent. However, mask += bitval and mask |= bitval have the same
effect only if bitval and mask have no bits set to “on” in common. For example,
2 | 4 is 6, but so is 3 | 6 .

 7. a. */
struct tb_drives {
	unsigned int diskdrives : 2;
	unsigned int : 1;
	unsigned int cdromdrives : 2;
	unsigned int : 1;
	unsigned int harddrives : 2;
};

// b.
struct kb_drives {
	unsigned int harddrives : 2;
	unsigned int : 1;
	unsigned int cdromdrives : 2;
	unsigned int : 1;
	unsigned int diskdrives : 2;
};