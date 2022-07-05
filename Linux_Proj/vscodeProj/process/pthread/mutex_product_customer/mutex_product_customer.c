#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

#define RUN 1  //线程恢复
#define STOP 0 // 线程挂起

void *producer(void *arg);

void *customer(void *arg);

int common_counter = 0;
pthread_mutex_t mutex;
int running = 1;

int main()
{
    pthread_t proth, custh;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&proth, NULL, producer, NULL);

    pthread_create(&custh, NULL, customer, NULL);

    usleep(1);
    running = 0;

    pthread_join(proth, NULL);
    pthread_join(custh, NULL);

    pthread_mutex_init(&mutex, NULL);

    return 0;
}

void *producer(void *arg)
{
    while (running)
    {
        pthread_mutex_lock(&mutex);
        common_counter++;
        printf("[生产者: %ld] 当前产品的总量为%d\n", pthread_self(), common_counter);
        pthread_mutex_unlock(&mutex);
    }
}

void *customer(void *arg)
{
    while (running)
    {
        pthread_mutex_lock(&mutex);
        common_counter--;
        printf("[消费者: %ld] 当前产品的总量为%d\n", pthread_self(), common_counter);
        pthread_mutex_unlock(&mutex);
    }
}