// 程序目的：线程正常退出，接受线程退出的返回码

#include <stdio.h>  
#include <pthread.h>  
#include <unistd.h>  
  
void *create(void *arg)  
{  
    printf("new thread is created ... \n");  
    return (void *)0;  
}  
  
int main(int argc,char *argv[])  
{  
    pthread_t tid;  
    int error;  
    void *temp;  
  
    error = pthread_create(&tid, NULL, create, NULL);  
  
    if( error )  
    {  
        printf("thread is not created ... \n");  
        return -1;  
    }  
    error = pthread_join(tid, &temp);  
  
    if( error )  
    {  
        printf("thread is not exit ... \n");  
        return -2;  
    }  
  
    printf("thread is exit code %d \n", (int )temp);  
                                          
    return 0;  
}  