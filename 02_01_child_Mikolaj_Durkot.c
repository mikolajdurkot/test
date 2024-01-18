#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("PID tego procesu\n%d\n", getpid());
	while (getchar() == '\0');
	pid_t p = fork();
	printf("getpid\n%d\n", getpid());

	if (p == 0) {
		printf("Proces dziecka: %d\n", getpid());
		printf("Proces ojca: %d\n", getppid());
	}

	while (getchar() == '\0');
	
	return 0;
}
