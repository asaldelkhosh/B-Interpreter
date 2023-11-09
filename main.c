#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* ptr;
	char ch;

	// opening file in reading mode
	ptr = fopen("test.txt", "r");
	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

    // reading line by line
	do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF);

	// closing the file
	fclose(ptr);

	return 0;
}
