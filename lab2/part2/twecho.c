/*
 * twecho
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char** allocate(int size);
char* allocateStr(int size);
char** copyArr(char **from, char **to, int size);
char* copyStr(char *from, char *to, int size);
void print(char **p);
void printArr(char *p);
void printAll(char **p);
int len(char **ptr);
static char **duplicateArgs(int argc, char **argv)
{

	char **ptr = allocate(argc);
	char **unchanged_ptr = ptr;
	char **unchanged_argv = argv;

	for (int i = 0; i < argc; i++){
		*ptr++ = *argv++;

	}

	ptr = unchanged_ptr;
	argv = unchanged_argv;
/*	
	printf("In argv:\n");
	int str_size = strlen(*unchanged_argv);
	printf("length=%d\n", str_size);
	printf("string= %s\n", *argv);
		
	printf("\nIn ptr:\n");

	int ptr_str_size = strlen(*ptr);
	printf("length=%d\n", ptr_str_size);
	printf("string= %s\n", *ptr);

	ptr++;

	ptr_str_size = strlen(*ptr);
	printf("length=%d\n", ptr_str_size);
	printf("string= %s\n\n", *ptr);
*/
	int str_size;
	char *unchanged_pointer;
	
	for (int i = 0; i < argc; i++){
		str_size = strlen(*argv);
		*ptr = allocateStr(str_size);
		if(i==0) unchanged_pointer = *ptr; // save original pointer for reset later
		strcpy(*ptr,*argv);
		char *temp_pointer = *ptr;
		while(**ptr!='\0'){
			//printf("**ptr = %c\n", **ptr);
			**ptr = toupper(**ptr);
			//printf("**ptr uppered = %c\n", **ptr);

			
			(*ptr)++;
		}
		*ptr = temp_pointer;
		argv++;
		ptr++;
	}
	*ptr = unchanged_pointer;
	ptr = unchanged_ptr;
	return ptr;	
}

static void freeDuplicatedArgs(char **copy)
{
	char **temp = copy;
	char *first = *temp;
	free(*temp++);
	while(*temp!=first){
		free(*temp++);
	}
	
	free(copy); 
}

char** allocate(int size){
	int alSize = sizeof(char*)*(size+1);
	char **p = malloc(alSize);
	//printf("Allocated space: %d\n", alSize); 
	if (p == NULL){
		perror("melloc returned null");
		exit(1);
	}
	return p;

}

char* allocateStr(int size){
	
	int alSize = sizeof(char)*(size+1);
	char *p = malloc(alSize);
	//printf("Allocated space for string: %d\n", alSize); 
	if (p == NULL){
		perror("melloc returned null");
		exit(1);
	}
	return p;
}

/*
 * DO NOT MODIFY main().
 */
int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;

    char **copy = duplicateArgs(argc, argv);
    char **p = copy;

    argv++;
    p++;
    while (*argv) {
        printf("%s %s\n", *argv++, *p++);
    }

    freeDuplicatedArgs(copy);


    return 0;
   
}
