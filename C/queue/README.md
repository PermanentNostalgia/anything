# 설명
큐는 먼저 저장된 값이 먼저 나오는 선입선출 형식의 저장방식입니다. 

# 구조체
## QUEUE 
큐를 나타내는 구조체로 6개의 멤버변수로 이루어져있습니다.
큐는 하나의 유닛이 모여있는 형태로 메모리 상에 저장되어있습니다. 
(유닛: 독립적인 데이터 하나를 저장하는 단위입니다. 쉽게 말해 변수 1개가 유닛 1개입니다.)

	+ int | size | QUEUE의 현재 유닛 갯수를 나타냅니다. 
	+ int | u_byte | QUEUE의 유닛 당 바이트 크기를 나타냅니다. 
	+ int | len | QUEUE의 현재 사용 중인 유닛 개수를 나타냅니다. 
	+ void&#42; | memory | 큐의 메모리 상 시작위치를 나타냅니다. 
	+ void&#42; | front | QUEUE의 맨 처음 유닛의 메모리 상 시작 위치를 나타냅니다. 
	+ void&#42; | rear | QUEUE의 맨 마지막 유닛의 메모리 상 시작 위치를 나타냅니다. 

# 함수 

## initQueue
초기화된 새로운 큐의 주소를 반환합니다. 
	+ 반환형: QUEUE&#42; | 초기화된 새로운 QUEUE의 주소. 메모리에 공간이 부족할 경우 NULL을 반환합니다.
	+ 매개변수
		1. int | u_size | QUEUE의 유닛 당 바이트 크기. 설정한 뒤에는 변경 할 수 없습니다. 

## freeQueue
큐를 메모리에서 할당 해제합니다. 
	+ 반환형: void
	+ 매개변수
		1. QUEUE&#42; | queue | 할당 해제할 QUEUE의 주소

## dequeue
큐에서 값을 인출합니다. 
	+ 반환형: int | 실행 결과
		- 1 | 오류가 없을 시
		- -1 | 인출될 값이 없을 시
	+ 매개변수
		1. QUEUE&#42; | queue | 값을 인출할 QUEUE의 주소
		2. void&#42; | out | 인출한 값을 저장할 공간의 주소. 이때 값을 저장할 공간의 크기는 QUEUE의 u_byte보다 크거나 같아야합니다.

## enqueue
큐에 값을 저장합니다. 
	+ 반환형: int | 실행 결과
		- 1 | 오류가 없을 시
		- -2 | 메모리 내 저장공간이 부족할 시
	+ 매개변수
		1. QUEUE&#42; | queue | 값을 저장할 QUEUE의 주소
		2. const void&#42; | in | 저장할 값이 존재하는 공간의 주소. 이때 저장할 값의 크기는 QUEUE의 u_byte보다 작거나 같아야합니다. 

## resize
큐의 유닛 개수를 변경합니다. 
	+ 반환형: int | 실행 결과
		- 1 | 오류가 없을 시
		- -1 | 매개변수 size가 QUEUE의 len보다 작을 시
		- -2 | 메모리 내 저장공간이 부족할 시
	+ 매개변수
		1. QUEUE&#42; | queue | 유닛의 개수를 변경할 QUEUE의 주소
		2. int | size | 변경할 유닛의 개수 
		
# 메크로

## DEF_SIZE
initQueue시 생성되는 큐의 기본 size를 정의합니다. 5로 설정되어있습니다. 