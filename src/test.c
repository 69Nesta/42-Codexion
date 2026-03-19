#include <pthread.h>
#include <stdio.h>


int	main(void)
{
	pthread_mutex_t	mutex;

	// pthread_mutex_init(&mutex, NULL);
	printf("%ld\n", mutex.__align);
	printf("'%s'\n", mutex.__size);
	printf("%d\n", pthread_mutex_destroy(&mutex));

	return (0);
}
