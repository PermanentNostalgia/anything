#include <stdio.h>
#include "queue.h"

void info_queue(QUEUE *queue);

int main(void) {
	int u_byte = sizeof(int);
	QUEUE *queue = initQueue(u_byte);
	
	info_queue(queue);
	
	int i, temp;
	printf("Enqueue Process\n");
	for(i=0; i<100; i++) {
		enqueue(queue, &i);
		//info_queue(queue);
	}
	
	printf("Dequeue Process\n");
	printf("0~99\n");
	for(i=0; i<100; i++) {
		dequeue(queue, &temp);
		printf("i: %d | value: %d\n", i, temp);
		//info_queue(queue);
	}
	
	return 0;
}

void info_queue(QUEUE *queue) {
	// 큐 초기화시 최적화를 위해 큐의 끝 위치가 큐의 시작 위치보다 한 유닛 앞으로 설정되어 있음
	// 큐의 초기 size는 메크로 DEF_SIZE로 정의되어 있으며 그 값은 5임
	
	printf("Queue's\n");
	printf("size: %d | unit's byte: %d | ", queue->size, queue->u_byte);
	printf("len: %d\n", queue->len);
	printf("memory: %p | front: %p | rear: %p\n", queue->memory, queue->front, queue->rear);
}