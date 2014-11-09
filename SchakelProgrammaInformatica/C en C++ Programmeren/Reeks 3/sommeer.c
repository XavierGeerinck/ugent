#include <stdio.h>

int string_to_number(char* s);

int main(int argc, char **argv) {
	int som = 0, i;
	
	if (argc < 2) {
		return 1;
	}
	
	for (i = 1; i < argc; i++) {
		som += string_to_number(argv[i]);
	}
	
	printf("%d", som);
	
	return 0;
}

int string_to_number(char* s) {
	int number = 0;
	
	while(*s) {
		number *= 10;
		number += *s - '0';
		s++;
	}
	
	return number;
}
