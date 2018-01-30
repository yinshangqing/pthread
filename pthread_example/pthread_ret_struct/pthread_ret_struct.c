// 程序目的：线程结束返回一个复杂的数据结构
#include <stdio.h>  
#include <pthread.h>  
#include <unistd.h>  
  
struct menber  
{  
    int a;  
    char *b;  
}temp={8,"Erric"};  
  
void *create(void *arg)  
{  
    printf("new thread ... \n");  
    return (void *)&temp;  
}  
  
int main(int argc,char *argv[])  
{  
    int error;  
    pthread_t tid;  
    struct menber *c;  
	// 文件名 函数名 行号
	printf("%s %s %d\n",__FILE__,__FUNCTION__ ,__LINE__);
    error = pthread_create(&tid, NULL, create, NULL);  
  
    if( error )  
    {  
        printf("new thread is not created ... \n");  
        return -1;  
    }  
    printf("main ... \n");  
  
    error = pthread_join(tid,(void *)&c);  
  
    if( error )  
    {  
        printf("new thread is not exit ... \n");  
        return -2;  
    }  
    printf("c->a = %d  \n",c->a);  
    printf("c->b = %s  \n",c->b);  
    sleep(1);  
    return 0;  
}  
