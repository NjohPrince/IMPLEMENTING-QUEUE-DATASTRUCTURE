#include<stdio.h>

// initializing head and end of Queue
int head = 0;
int end = 0;

// function to check if queue is full
int isQueueFull(int queue[], int size){
	if(end == size)
		return 1;
	return 0;
}

// function to check if queue is empty
int isQueueEmpty(void){
	if(head == end)
		return 1;
	return 0;
}

// function to add items into the queue
int enQueue(int queue[], int size){

	if(isQueueFull(queue, size))
	     printf("\nQueue is Full\n");
	else
	{
	    printf("\nEnter number to be queued: ");
	    scanf("%d", &queue[end]);
		printf("Successfully added!\n");
		return 1;
	}
	return 0;
}

// function to remove items from queue
int deQueue(int queue[]){
	if(isQueueEmpty())
	    printf("\nSorry... Queue is empty\nTry adding elements\n");
	else
	{
		printf("\nElement dequeued");
	    printf("\nDeleted Element is %d\n",queue[head]);
		return 1;
	}
	return 0;
}

// function to display queue
void displayQueue(int queue[]){
	if(isQueueEmpty())
	    printf("\nSorry... Queue is empty\nTry adding elements\n");
	else
	{
		int i;
		printf("\nElement in Queue are: ");
		for(i = head; i < end; i++)
	    {
	        printf("%d ", queue[i]);
	    }
		printf("\n");
	}
}

// function to display head of queue
void displayQueueHead(int queue[]){
	if(isQueueEmpty())
	    printf("\nSorry... Queue is empty\nNo element at Queue head\n");
	else
	    printf("\nElement at Head of Queue is %d\n", queue[head]);
}

// function to display end of queue
void displayQueueEnd(int queue[]){
	if(isQueueEmpty())
	    printf("\nSorry... Queue is empty\nNo element at Queue End\n");
	else
	    printf("\nElement at End of Queue is %d\n", queue[end-1]);
}

// function to display size of queue
void displayQueueSize(int size){
	if(isQueueEmpty())
	    printf("\nQueue has no elements\n");
	else
	    printf("\nSize of Queue is %d\n", size);
}

int main(void)
{
	// Introduction
	printf("Queue using Array\n");
	printf("-----------------\n");

	// getting size of the queue array
	int size;

	do{
		printf("\nEnter size of Queue: ");
		scanf("%d", &size);
	}while(size < 0);

	// creating a queue array capable of holding size-elements
	int queue[size];

	int choice = 1;
    while(choice)
    {
		// displaying Various Operations
		printf("\n1. Insertion(Enqueue) \n2. Deletion(dequeue) \n3. Display Queue");
		printf("\n4. Display element at Queue head \n5. Display element at Queue end \n6. Display Queue Size \n7. Exit\n");

		// enabling user choose operation
        printf("\nChoose operation from the list above: ");
        scanf("%d", &choice);

        switch(choice)
        {
	        case 1:
	            if(enQueue(queue, size))
					end++;
	            break;
	        case 2:
	             if(deQueue(queue)){
					head++;
					// adjusting the size to fit size-elements
					size++;
				 }
	            break;
	        case 3:
	            displayQueue(queue);
				break;
			case 4:
				displayQueueHead(queue);
				break;
			case 5:
				displayQueueEnd(queue);
				break;
			case 6:
				displayQueueSize(end - head);
				break;
			case 7:
				printf("\n");
	            return 0;
	        default:
	            printf("\nInvalid Operation: Please see the options\n");
        }
    }
    return 0;
}

