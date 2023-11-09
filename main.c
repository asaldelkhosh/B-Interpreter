#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


// constant parameters
#define OPERATIONS "+-*/%="


// check if character is alphabet or not
bool is_alphabet(char ch) {
    return isalpha(ch);
}

// check if character is digit or not
bool is_digital(char ch) {
    return isdigit(ch);
}

// check if character is mathematical operation
bool is_operator(char ch) {
    for (int i = 0; i < sizeof(OPERATIONS); i++) {
        if (ch == OPERATIONS[i])
            return true;
    }

    return false;
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

        printf("%c -> alp:%d , num:%d , opr:%d\n", ch, is_alphabet(ch), is_digital(ch), is_operator(ch));
    }

	// closing the file
	fclose(ptr);

	return 0;
}
