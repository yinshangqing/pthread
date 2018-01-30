// 程序目的：验证新建立的线程可以共享进程中的数据
#include <stdio.h>  
#include <pthread.h>  
  
static int a = 5;  
  
void *create(void *arg)  
{  
    printf("New pthread...\n");  
    printf("a = %d\n",a);  
  
    return (void *)0;  
}  
  
int main(int argc, const char *argv[])  
{  
    int error;  
    pthread_t id1;  
  
    error = pthread_create(&id1, NULL, create, NULL);  
    if(error != 0)  
    {  
        printf("new thread is not created!\n");  
        return -1;  
    }  
    sleep(1);  
    printf("New thread is created...\n");  
  
    return 0;  
}  