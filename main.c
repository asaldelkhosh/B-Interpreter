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

    char buffer[100];
    int index = 0;

    memset(buffer, 0, sizeof(buffer));
    
    // reading character by character
	while (!feof(ptr)) {
        ch = fgetc(ptr);

        // skip enters, null characters, or end of file
        if (ch =='\n' || ch == '\0' || ch == EOF) {
            // before continuing, print the buffer
            if (strlen(buffer) > 0)
                printf("%s\n", buffer);

            memset(buffer, 0, sizeof(buffer));
            index = 0;

            continue;
        }
        
        if (ch != ' ') { // no space, it should be in buffer
            buffer[index++] = ch;
        } else {
            // print the buffer
            if (strlen(buffer) > 0)
                printf("%s\n", buffer);

            memset(buffer, 0, sizeof(buffer));
            index = 0;
        }
    }

	// closing the file
	fclose(ptr);

	return 0;
}
