#include <stdio.h>
#include <string.h>

#define AANTAL_WOORDEN		5
#define MAX_LENGTE_WOORDEN	70
#define MAX_LENGTE_ZIN		AANTAL_WOORDEN * (1 + MAX_LENGTE_WOORDEN)

int main() {
	int i = 0; /* Array counter */
	char t[AANTAL_WOORDEN][MAX_LENGTE_WOORDEN];
	char *pt[AANTAL_WOORDEN]; /* Array of pointers pointing to t */
	
	while (i < AANTAL_WOORDEN) {
		char buffer[255];
		
		scanf("%s", &buffer);
		
		if (strlen(buffer) > MAX_LENGTE_WOORDEN) {
			return 1;
		}
		
		strcpy(t[i], buffer);
		pt[i] = &t[i];
		
		i++;
	}
	
	/* Print this array */
	for (i = 0; i < AANTAL_WOORDEN; i++) {
		printf("%s-", *(pt + i));
	}
}
