#include <stdio.h>

int head = -1, end = -1;

// Check if the queue is full
int isFull(int size){
  	if((head == end + 1) || (head == 0 && end == size - 1)) 
		return 1;
  	return 0;
}

// Check if the queue is empty
int isEmpty(void){
  	if(head == -1) 
		return 1;
  	return 0;
}

// Add an element
void enQueue(int queue[], int size){
  	if(isFull(size))
   	 	printf("\n Queue is full!! \n");
  	else{
		int element;
    	if (head == -1) 
			head = 0;
		// this will always keep the end within the size range
    	end = (end + 1) % size;
		printf("\nEnter the element: ");
		scanf("%d", &element);
    	queue[end] = element;
    	printf("Inserted: %d\n", element);
  	}
}

// function to Remove an element
void deQueue(int queue[], int size){
  	int element;
  	if(isEmpty()){
    	printf("\nQueue is empty!!\n");
  	} 
	else{
    	element = queue[head];
    	if(head == end){
      		head = -1;
      		end = -1;
    	} 
   		// Q has only one element, so we reset the 
    	// queue after dequeing it. ?
    	else{
      		head = (head + 1) % size;
    	}
    	printf("\nDeleted element -> %d \n", element);
  }
}

// function to Display the queue
void displayQueue(int queue[], int size){
  	int i;
  	if(isEmpty())
    	printf(" \nEmpty Queue!!!\n");
  	else{
    	/*printf("\nHead -> %d ", head);*/
    	printf("\nItems -> ");
    	for(i = head; i != end; i = (i + 1) % size){
      		printf("%d ", queue[i]);
    	}
    	printf("%d", queue[i]);
    	/*printf("\nEnd -> %d \n", end);*/
  	}
}

// function to print head element of the queue
void displayQueueHead(int queue[]){
	if(isEmpty())
    	printf(" \nEmpty Queue!!!\n");
  	else{
    	printf("\nQueue Head -> %d\n", queue[head]);
  	}
}

// display the last element of the queue
void displayQueueEnd(int queue[]){
	if(isEmpty())
    	printf(" \nEmpty Queue!!!\n");
  	else{
    	printf("\nQueue End -> %d\n", queue[end]);
  	}
}

// displaying the size element of the queue
void displayQueueSize(int size){
	if(isEmpty())
    	printf(" \nEmpty Queue!!!\n");
  	else{
		int Size;
		if(head > end)
			Size = size - ((head - end) - 1);
		if(end > head)
			Size = (end - head) + 1;
    	printf("\nQueue Size -> %d\n",  Size);
  	}
}

int main(void) {
  // Introduction
	printf("Queue using Circular Array\n");
	printf("---------------------------\n");

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
	            enQueue(queue, size);
	            break;
	        case 2:
	             deQueue(queue, size);
	            break;
	        case 3:
	            displayQueue(queue, size);
				break;
			case 4:
				displayQueueHead(queue);
				break;
			case 5:
				displayQueueEnd(queue);
				break;
			case 6:
				displayQueueSize(size);
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
