// fill array with random
// copy of array
// sort new array
// free after malloc

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main();
void sort_integer_array(int *begin, int *end, int ascending);
int* allocate(int size);
int comparator_asc(const void *p, const void *q);
int comparator_dsc(const void *p, const void *q);
void copy(int *from, int *to, int size);
void print_array(int *ptr, int size);

int main(){
	int size;
	printf("Size of the array: \n");
	scanf("%d", &size);
	srand(time(NULL));
	int unsorted[size];
	for (int i = 0 ; i < size; i++){
		int randint = random();
		while (randint > 99) randint = random();
		unsorted[i] = randint;
	}

	printf("original: ");
	print_array(unsorted, size);
	
	
	int *start_ptr = allocate(size);
	copy(unsorted, start_ptr, size);
	int *end_ptr = start_ptr + size;
	//print_array(start_ptr, size);
	printf("ascending: ");
	sort_integer_array(start_ptr, end_ptr, 1);
	
	int *start_ptr_2 = allocate(size);
	copy(unsorted, start_ptr_2, size);
	int *end_ptr_2 = start_ptr_2 + size;
	printf("descending: ");
	sort_integer_array(start_ptr_2, end_ptr_2, 0);


	free(start_ptr);
	free(start_ptr_2);

}

void sort_integer_array(int *begin, int *end, int ascending){
	int *temp_start = begin;
	int size = 0;

	while( temp_start++ != end) size++;
	
	if (ascending > 0) qsort(begin, size, sizeof(int), comparator_asc);
	else qsort(begin, size, sizeof(int), comparator_dsc);

	print_array(begin, size);

	
}

int comparator_asc(const void *a, const void *b){
	return ( *(int*) a - *(int*)b );
}

int comparator_dsc(const void *a, const void *b){
	return ( *(int*) b - *(int*)a );
}

void copy(int *from, int *to, int size){
	for (int i = 0; i < size; i++){
		//printf("from = %d \n", *from);
		*(to++) = *(from++);
	}
}

// return pointer for the newly allocated empty array
int* allocate(int size){
	int *ptr = malloc(size*sizeof(int));
	if (ptr == NULL) {
		perror("malloc returned NULL");
		exit(1);
	}
		
	return ptr;
}

void print_array(int *ptr, int size){
	for (int i = 0; i < size; i++){
		printf("%d ", *(ptr++));
	}
	printf("\n");
}
