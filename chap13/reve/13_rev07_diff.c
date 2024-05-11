// 7.
// a.What is the difference between saving 8238201 by using fprintf() and
// saving it by using fwrite()?
// Answer: fprintf() saves the number as a string of characters, while fwrite()
// saves the number as a binary value.
// correct: When 8238201 is saved using fprintf(), it’s saved as seven
// characters stored in 7 bytes. When fwrite() is used, it’s saved as a 4-byte
// integer using the binary representation of that numeric value.

// b. What is the difference between saving the character S by using putc() and
// saving it by using fwrite()?
// Answer: putc() saves the character as a character, while fwrite() saves the
// character as a binary value.
// correct: No difference; in each case it’s saved as a 1-byte binary code