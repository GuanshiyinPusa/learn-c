// What’s wrong with this program ?
#include <stdio.h> // not included

int main(void) {
	// int *fp;
	FILE *fp;
	int k;
	// fp = fopen("gelatin");
	fp = fopen("gelatin", "w"); // mode w for fputs later
	for (k = 0; k < 30; k++)
		// fputs(fp, "Nanette eats gelatin.");
		fputs("Nanette eats gelatin.\n", fp);
	// fclose("gelatin");
	fclose(fp);
	return 0;
}

// Mode StringMeaning
// "r"  Open a text file for reading.
// "w"  Open a text file for writing, truncating an existing file to zero
// length, or creating the file if it does not exist.
// "a"  Open a text file for writing, appending to the end of an existing file,
// or creating the file if it does not exist.
// "r+" Open a text file for update (that is, for both reading and writing).
// "w+" Open a text file for update (reading and writing), first truncating the
// file to zero length if it exists or creating the file if it does not exist.
// "a+" Open a text file for update (reading and writing), appending to the end
// of an existing file, or creating the file if it does not yet exist; the whole
// file can be read, but writing can only be appended.
// "rb", "wb", "ab", "ab+", "a+b", "wb+", "w+b", "ab+","a+b"
// Like the preceding modes, except they use binary mode instead of text mode.
// "wx", "wbx", "w+x", "wb+x" or "w+bx"
// (C11) Like the non-x modes, except they fail if the file already exists and
// they open a file in exclusive mode, if possible.