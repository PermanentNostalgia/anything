#ifndef _QUEUE_H_
#define _QUEUE_H_

#define DEF_SIZE 5
#define FRONT 0
#define REAR 1

typedef struct _queue {
	int size;
	int len;
	int u_byte;
	void *front;
	void *rear;
	void *memory;
}QUEUE;

QUEUE *initQueue(int u_byte);
void freeQueue(QUEUE *queue);
int dequeue(QUEUE *queue, void *out);
int enqueue(QUEUE *queue, void *in);
int resize(QUEUE *queue, int size);
#endif