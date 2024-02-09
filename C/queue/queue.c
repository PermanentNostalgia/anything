#include <string.h>
#include <stdlib.h>
#include "queue.h"

static void nextPtr(QUEUE *queue, int mode);

QUEUE *initQueue(int u_byte) {
	QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));
	
	if(u_byte<=0 || queue==NULL) {
		return (QUEUE *) NULL;
	}
	
	// 큐 구조체 초기화
	queue -> size = DEF_SIZE;
	queue -> len = 0;
	queue -> u_byte = u_byte;
	queue -> memory = malloc(u_byte * DEF_SIZE);
	queue -> front = queue->memory;
	queue -> rear = (char *)queue->memory - queue->u_byte;
	
	return queue;
}

void freeQueue(QUEUE *queue) {
	free(queue -> memory);
	free(queue);
}

int dequeue(QUEUE *queue, void *out) {
	if(queue -> len == 0) {
		return -1;
	}
	
	memcpy(out, queue->front, queue->u_byte);
	nextPtr(queue, FRONT);
	queue->len--;
	
	return 1;
}

int enqueue(QUEUE *queue, void *in) {
	if(queue -> len == queue -> size) {
		// 큐 메모리 사이즈 증가 
		return -1;
	}
	
	nextPtr(queue, REAR);
	memcpy(queue->rear, in, queue->u_byte);
	queue->len++;

	return 1;
}

static void nextPtr(QUEUE *queue, int mode) {
	void **ptr;
	int index;
	
	if(mode==FRONT) {
		ptr = &queue->front;
	} else if(mode==REAR) {
		ptr = &queue->rear;
	}
	
	// 다음 요소의 인덱스 구하는 식
	index = ((char *)*ptr + queue->u_byte - (char *)queue->memory) / queue->u_byte % queue->size;
	
	*ptr = (char *)queue->memory + index * queue->u_byte;
}