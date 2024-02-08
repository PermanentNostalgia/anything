#include <stdlib.h>
#include "queue.h"

static void nextPtr(QUEUE *queue, int mode);

QUEUE *initQueue(int u_byte) {
	QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));
	
	if(u_size<=0 || queue==NULL) {
		return (QUEUE *) NULL;
	}
	
	// 큐 구조체 초기화
	queue -> size = DEF_SIZE;
	queue -> len = 0;
	queue -> u_byte = u_byte;
	queue -> memory = malloc(u_byte * DEF_SIZE);
	queue -> front = queue -> memory;
	queue -> rear = queue -> memory;
	
	return queue;
}

void freeQueue(QUEUE *queue) {
	free(queue -> memory);
	free(queue);
}

int dequeue(QUEUE *queue, void *out) {
	if(query -> len == 0) {
		return -1;
	}
	
	memcpy(out, query->front, query->ubyte);
	nextPtr(queue, FRONT);
	query->len--;
	
	return 1;
}

int enqueue(QUEUE *queue, void *in) {
	if(queue -> len == queue -> size) {
		// 큐 메모리 사이즈 증가 
		return -1;
	}
	
	nextPtr(queue, REAR);
	memcpy(query->rear, in, query->u_byte);
	query->len++;

	return 1;
}

static void nextPtr(QUEUE *queue, int mode) {
	void **ptr;
	void *oom = (char *)queue->memory + queue->size * queue->u_byte;
	
	if(mode==FRONT) {
		ptr = &queue->front;
	} else if(mode==REAR) {
		ptr = &queue->rear;
	} else {
		return NULL;
	}
	
	if((char *)*ptr + queue->u_byte==oom) {
		*ptr = queue->memory;
	} else {
		(char *)*ptr += query->u_byte;
	}
}