#include <stdlib.h>
#include "queue.h"

static void *getNextPtr(void *queue, int q_size, void *current);

QUEUE *initQueue(int u_byte) {
	QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));
	
	if(u_size<=0 || queue==NULL) {
		return (QUEUE *) NULL;
	}
	
	// 큐 구조체 초기화
	queue -> size = DEF_SIZE;
	queue -> len = 0;
	queue -> u_byte = u_byte;
	queue -> queue = malloc(u_byte * DEF_SIZE);
	queue -> front = queue -> queue;
	queue -> rear = queue -> queue;
	
	return queue;
}

void freeQueue(QUEUE *queue) {
	free(queue -> queue);
	free(queue);
}

void dequeue(QUEUE *queue, void *out) {
	
}

int enqueue(QUEUE *queue, void *in) {
	
}