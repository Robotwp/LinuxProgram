#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h> 
struct message
{
	int i;
	int j;
};

int value=0;
void *hello(struct message *str)
{
	//printf("child,the tid=%lu,pid=%ld\n",pthread_self(),syscall(SYS_gettid));
	//printf("the arg.i is %d,arg.j is %d\n",str->i,str->j);
  value++;
	printf("new pthread %d\n",value);
	while(1);
	
}

int main(int argc,char *agrv[])
{
	struct message test;
	pthread_t thread_id;
	test.i=10;
	test.j=20;
	
	pthread_create(&thread_id,NULL,(void *)*hello,&test);
	value++;
	printf("%d\n",value);
	//printf("parent,the tid=%lu,pid=%ld\n",pthread_self(),syscall(SYS_gettid));
	pthread_join(thread_id,NULL);
}
