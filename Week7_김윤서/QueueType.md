# Queue 구조체 정의와 함수
1. 선형 큐
2. 원형 큐
3. 연결리스트 큐
4. 덱
### 함수들
    - init()   
    - error() //생략   
    - is_full()
    - is_empty()
    - enqueue()
    - dequeue()
    - print_queue()

- - - 

## 1. 선형 큐
```
typedef struct {
  element data[MAX];
  int front;
  int rear;
}QueueType;
```
#### • init(QueueType* q)   
```q->front = q->rear = -1;``` *//선형큐는 -1부터 시작*   

#### • is_full(QueueType* q)   
```return (q->rear == MAX-1);``` *//max값에서 1뺀값과 rear가 같으면 full (인덱스이므로 -1)*     

#### • is_empty(QueueType* q)   
```return (q->front == q->rear);``` *//front와 rear가 같은 경우*   

#### • enqueue(QueueType* q, element item)   
*// 스택과 마찬가지로, 증가 먼저하고 이후 값 대입하는 방식*   
```
if(is_full(q)) {error~}   
q->data[++q->rear] = item;
```

#### • dequeue(QueueType* q)
*// 스택과 마찬가지로, 프론트값 리턴 하고 이후 증가*   
```
if(is_empty(q)){error~}   
else return q->data[q->front++];
```

#### • print_queue(QueueType* q)   
```
for (int i=0; i<MAX; i++){   
  if(i < q->front || i> q->rear) { printf("  :"); }   
  else { printf("%3d  :", q->data[i]); }   
}
printf("\n");
```
*// 선형큐는 for문으로 프린트*   
*// 주의- 여기서 i가 프론트보다 작거나 rear보다 클 경우만 공백 처리 해주면 ok*  


## 2. 원형 큐
**(구조체는 선형큐와 동일)**   

#### • init   
```q->front = q->rear = 0;```
*//원형큐는 0부터 시작!!!*   

#### • is_full   
```return ((q->rear +1)%MAX == q->front);```   
*//rear에 1더하고 MAX로 나눈 나머지가 front와 같으면 full*     
*// ex) MAX가 6일 때, rear가 5, front가 0이면 full (6%6 == 0)*     

#### • is_empty   
```return (q->front == q->rear);``` *//front와 rear가 같은 경우. 선형큐와 동일! *   

#### • enqueue   
*// 증가 시키는 방식만 다르고, 선형 큐와 같이 증가 후 값 대입하는 방식*   
```
if(is_full(q)) {error~}   
else {   
  q->rear = (q->rear +1) % MAX; *// rear증가*   
  q->data[q->rear] = item;   
}
```

#### • dequeue
*// 마찬가지로, 프론트값 증가 방식만 다름*   
```
if(is_empty(q)){error~}   
else {
  q->front = (q->front +1) % MAX; //front 증가 (원래 front는 아무 데이터도 안갖고 있으므로 먼저 증가)
  return q->data[q->front++];
}
```
#### • print_queue   
*//do~while문 사용*
```
if(! is_empty(q)){
  int i= q->front;
  do {
    i = (i+1) % MAX; // front+1 부터 출력
    printf("%3d :", q->data[i]);
    if(i == q->rear) { break; } //rear에 다다르면 다 출력한 것이므로 종료
  } while (i != q->front); //front가 아닐 때 계속 반복. 돌아오면 종료
}
printf("\n");
```
#### + 원형 큐 원소 개수 구하기
```return (MAX - front + rear);```

## 3. 연결리스트 큐
```
typedef struct QueueNode {
  element data;
  QueueNode* link;
} QueueNode;

typedef struct QueueType {
  QueueNode *front;
  QueueNode *rear;
} QueueType;
```
#### • init   
#### • is_full   
#### • is_empty   
#### • enqueue   
#### • dequeue   
#### • print_queue   
