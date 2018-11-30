#include<stdio.h>
#define SIZE 25000  //define 25000 byte size

			
		/*create a char array to use as the byte array for memory allocation.
		and initialize with null value at the beginning */
			 
char memory_array[SIZE]={'\0'};

	
			//BestFit Algorithm for search best block for allocation
char* BestFitAlgo(int size){
	
	int Dvalue=0; 
	char* temp=&Dvalue; 
	
	int i=0;
	while(i<SIZE){	
		if(memory_array[i]=='f' && *(int*)(&memory_array[i+1])>=size){
			if(*temp==0){
				temp=&memory_array[i];
			}
			if(*(int*)(temp+1)>*(int*)(&memory_array[i+1])){
				temp=&memory_array[i];	
			}		
		}
	
		i+=*(int*)(&memory_array[i+1])+5; //increamenting to next block	
	}	
	return temp;
}

			//malloc() function for allocate memory blocks 
			// 'f' is for 'free' and 'p' is for 'process' 
void* MyMalloc(int size){
	
//Check whether	the first index of the memory is null or not and initialize the memory with starting values
	if(memory_array[0]=='\0'){
		memory_array[0]='f'; 
		*(int*)(&memory_array[1])=SIZE-5;
	}
	char* Bestblock=BestFitAlgo(size); 
	
	if(*Bestblock!=0){
		*Bestblock='p';
		int free=*(int*)(Bestblock+1)-(size+5);
		if(free>5){
			char* freeblock=Bestblock+size+5; 
			*(int*)(Bestblock+1)=size;
			*freeblock='f';
			*(int*)(freeblock+1)=free;
			return (void*)(Bestblock+5);	
		}
		else{
			return (void*)(Bestblock+5);		
		}				
	}
	else{
		printf("Not enough space. free some space and try again!\n");
		return NULL;
	}
}

				//function for free up the allocated memory
void MyFree(void* memo){
	int j=0,next=0,previous=0;	
	
	while(j<25000){
		
		if((void*)(&memory_array[j+5])==memo){
			
			if(memory_array[previous]=='f' && memory_array[next]=='f'){
				
				*(int*)(&memory_array[previous+1])+=*(int*)(&memory_array[j+1])+5+*(int*)(&memory_array[next+1])+5;
			}
			
			else if(memory_array[previous]=='p' && memory_array[next]=='f'){
				
				*(int*)(&memory_array[j+1])+=*(int*)(&memory_array[next+1])+5;
				memory_array[j]='f';
				
			}
			else if(memory_array[previous]=='f' && memory_array[next]=='p'){
				
				*(int*)(&memory_array[previous+1])+=*(int*)(&memory_array[j+1])+5;
			}
		
			else{
				memory_array[j]='f';
			}
			return;
		}
		else{
			
			previous=j;
			j+=*(int*)(&memory_array[j+1])+5;
			next=j+*(int*)(&memory_array[j+1])+5;
		}
	}
}

				//function to display the results
void display(){
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMORY STATUS~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	if(memory_array[0]!='\0'){
		
		printf("\t\tState\t\t\t\t\tSize\t\t\n\n");
	
		int i=0;
		while(i<25000){
			if(memory_array[i]=='p'){
			
			printf("\t\t process \t\t\t\t");
		}
			if(memory_array[i]=='f'){
			
			printf("\t\tavailable\t\t\t\t");
			
		}
		printf("%d\t\t\n",*(int*)(&memory_array[i+1]));
			i+=*(int*)(&memory_array[i+1])+5;
		
		}
		
		printf("\n\n");
	}
	
	
	else{
		printf("Memory is Empty\n");
}
}

//2016CS132
	
