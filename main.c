#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


// check if character is alphabet or not
bool is_alphabet(char ch) {
    return isalpha(ch);
}


int main()
{
	FILE* ptr;
	char ch;

	// opening file in reading mode
	ptr = fopen("test.b", "r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

    // reading character by character
	while (!feof(ptr)) {
        ch = fgetc(ptr);

        // skip enters, null characters, or end of file
        if (ch =='\n' || ch == '\0' || ch == EOF)
            continue;

        printf("%c -> %d\n", ch, is_alphabet(ch));
    }

	// closing the file
	fclose(ptr);

	return 0;
}
