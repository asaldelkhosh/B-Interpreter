#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

        printf("%c", ch);
    }

	// closing the file
	fclose(ptr);

	return 0;
}
