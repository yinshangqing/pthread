// 功能：创建一个简单的线程
#include <stdio.h>  
#include <pthread.h>  

#define LEN 20 

void *mythread1(void)  
{  
    int i;  
    for(i = 0; i < LEN; i++)  
    {  
        printf("This is the 1st pthread,created by Erric!\n");  
        sleep(1);  
    }  
}  
  
void *mythread2(void)  
{  
    int i;  
    for(i = 0; i < LEN; i++)  
    {  
        printf("This is the 2st pthread,created by Erric!\n");  
        sleep(1);  
    }  
}  
  
int main(int argc, const char *argv[])  
{  
    int i = 0;  
    int ret = 0;  
    pthread_t id1,id2;  
  
    ret = pthread_create(&id1, NULL, (void *)mythread1,NULL);  
    if(ret)  
    {  
        printf("Create pthread 1 error!\n");  
        return 1;  
    }  
  
    ret = pthread_create(&id2, NULL, (void *)mythread2,NULL);  
    if(ret)  
    {  
        printf("Create pthread 2 error!\n");  
        return 1;  
    }  
      
    pthread_join(id1,NULL);  
    pthread_join(id2,NULL);  
  
    return 0;  
}  