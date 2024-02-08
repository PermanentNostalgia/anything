#ifndef _QUEUE_H_
#define _QUEUE_H_

#define DEF_SIZE 5
#define FRONT 0
#define REAR 1

typedef struct _queue {
	int size; // 큐의 크기
	int len; // 큐의 길이
	int u_byte; // 요소의 바이트 크기
	void *front; // 첫번째 요소
	void *rear; // 마지막 마지막
	void *memory; // 큐
}QUEUE;

QUEUE *initQueue(int u_size); // u_size: 한 요소당 크기
void freeQueue(QUEUE *queue);
void dequeue(QUEUE *queue, void *out);
int enqueue(QUEUE *queue, void *in);
#endif