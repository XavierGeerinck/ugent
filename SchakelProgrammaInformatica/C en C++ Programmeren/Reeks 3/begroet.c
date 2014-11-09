#include <ctype.h>
#include <stdio.h>

int main(int argc, char** argv) {
	int i;
	
	printf("Dag ");
	
	if (argc > 1) {
		for (i = 1; i < argc - 1; i++) {
			if (i >= 2) {
				printf(", ");
			}
			
			argv[i][0] = toupper(argv[i][0]); /* toupper kan ook door char - 'a' + 'A' te doen, gebruik dit en niet + 32! */
			printf("%s", argv[i]);
		}	
		
		if (argc > 2) {
			printf(" en ");
		}
		
		argv[argc - 1][0] = toupper(argv[argc - 1][0]);
		printf("%s!", argv[argc - 1]);
		
	}
	
	return 0;
}
