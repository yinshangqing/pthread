// 程序功能：向新建的线程传递字符串
#include <stdio.h>  
#include <pthread.h>  
  
void *create(void *arg)  
{  
    char *str;  
    str = (char *)arg;  
    printf("The parameter passed from main is %s\n",str);  
  
    return (void *)0;  
}  
  
int main()  
{  
    int error;  
    pthread_t id1;  
    char *str1 = "Hello ,Erric !!!";  
    char *attr = str1;  
    error = pthread_create(&id1, NULL, create, (void *)attr);  
  
    if(error != 0)  
    {  
        printf("This pthread is created fail!!!\n");  
        return -1;  
    }  
    sleep(1);  
  
    printf("pthread is created..\n");  
    return 0;  
}  