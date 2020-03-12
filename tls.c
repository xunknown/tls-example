/**
 * @author      : alpha (alpha@mascot)
 * @created     : Thursday Feb 20, 2020 01:17:33 HKT
 */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

__thread int tls_var = 0;
int normal_var = 0;

void *thread_entry(void *arg)
{
	for (int i = 0; i < *(int *)arg; i++) {
		tls_var++;
		normal_var++;
	}

	printf("tls_var=%p:%d, normal_var=%p:%d\n",
		&tls_var, tls_var, &normal_var, normal_var);

	return NULL;
}

int main(int argc, char * argv[])
{
	pthread_t threads[3];
	int loop = 3;

	for (int i = 0; i < 3; i++) {
		pthread_create(&threads[i], NULL, thread_entry, &loop);
	}

	for (int i = 0; i < 3; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("tls_var=%p:%d, normal_var=%p:%d\n",
		&tls_var, tls_var, &normal_var, normal_var);

	return 0;
}
