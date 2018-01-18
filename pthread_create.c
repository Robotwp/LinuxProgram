#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void *helloworld(char *argc)
{
	int i=0;
	for(i=0;i<5;i++)
	{
	printf("the child id is %u\n",pthread_self());
	sleep(2);
}	
	return 0;
}

int main(int argc,int argv[])
{
	int error;
	int *temptr;
	
	pthread_t thread_id;
	
	pthread_create(&thread_id,NULL,helloworld,"helloworld");
int i=0;
 for(i=0;i<5;i++)
        {
        printf("the main id is %u\n",pthread_self());
}

/*	if(error=pthread_join(thread_id,(void **)&temptr))
	{
		perror("pthread_join");
		exit(EXIT_FAILURE);	
	}
/*		int i=0;
	for(i=0;i<5;i++)
	{
	printf("the main id is %u\n",pthread_self());
}*/
	return 0;
}

