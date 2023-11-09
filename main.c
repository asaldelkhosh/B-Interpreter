#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


// constant parameters
#define OPERATIONS "+-!*/%^<>=|&"
#define DELIMETERS "()[]{},;:'\""

char keywords[][10] = { "array", "boolean", "char", "else", "false", "for", "function", "if",
                       "integer", "print", "return", "string", "true", "void", "while" };


// check if character is alphabet or not
bool is_alphabet(char ch) {
    return isalpha(ch);
}

// check if character is digit or not
bool is_digital(char ch) {
    return isdigit(ch);
}

// check if character is mathematical operation or not
bool is_operator(char ch) {
    for (int i = 0; i < sizeof(OPERATIONS); i++) {
        if (ch == OPERATIONS[i])
            return true;
    }

    return false;
}

// check if character is delimiter or not
bool is_delimiter(char ch) {
    for (int i = 0; i < sizeof(DELIMETERS); i++) {
        if (ch == DELIMETERS[i])
            return true;
    }

    return false;
}

// check to see if a character is special
bool is_special(char ch) {
    return is_delimiter(ch) || is_operator(ch);
}

// check if string is keyword or not
bool is_keyword(char *token) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return true;
        }
    }

    return false;
}

// check if string is number or not
bool is_number(char *token) {
    for (int i = 0; i < sizeof(token) / sizeof(token[0]); i++) {
        if (!is_digital(token[i]))
            return false;
    }

    return true;
}

// check token type and print its details
void tokenize(char *token) {
    if (strlen(token) > 1) {
        if (is_keyword(token))
            printf("keyword: ");
        else if (is_number(token))
            printf("number: ");
        else
            printf("string: ");
    } else {
        char ch = token[0];

        if (is_alphabet(ch))
            printf("alpabet: ");
        else if (is_operator(ch))
            printf("operator: ");
        else if (is_delimiter(ch))
            printf("delimiter: ");
        else if (is_digital(ch))
            printf("digital: ");
        else
            printf("unknown: ");
    }
    
    printf("\n\t%s\n", token);
}


// global variables
bool in_string = false;


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
                tokenize(buffer);

            memset(buffer, 0, sizeof(buffer));
            index = 0;

            continue;
        }

        if (is_special(ch)) { // check special character, if true, empty the buffer
            int string_length = strlen(buffer);
            if (string_length > 0) {
                if (ch == '"' && string_length > 1)
                    buffer[index++] = ch;
                tokenize(buffer);
            }

            memset(buffer, 0, sizeof(buffer));
            index = 0;
        }
        
        if (ch != ' ') { // no space, it should be in buffer
            if (ch == '"') { // check for string delimeter
                if (!in_string) {
                    in_string = true;
                    buffer[index++] = ch;
                } else {
                    in_string = false;
                }
            } else {
                buffer[index++] = ch;
            }
        } else if (!in_string) {
            // print the buffer
            if (strlen(buffer) > 0)
                tokenize(buffer);

            memset(buffer, 0, sizeof(buffer));
            index = 0;
        } else {
            buffer[index++] = ch;
        }
    }

	// closing the file
	fclose(ptr);

	return 0;
}
