#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <string.h>
#include <time.h>
#define SIZE 10000

const int HASH_CONST=0x55555555;

unsigned hashNum(int num){
	unsigned i=num*7;
	return i%SIZE;
}

int insert(int hash[], int element){
	unsigned hashValue = hashNum(element);
	if(hash[hashValue]==INT_MIN){
		hash[hashValue]=element;
		return hashValue;
	}
	unsigned pos=(hashValue+1)%SIZE;
	while(pos!=hashValue){
		if(hash[pos]==INT_MIN||hash[pos]==-1){
			hash[pos]=element;
			return pos;
		}
		pos=(pos+1)%SIZE;
	}
	return -1;
}

int search(int hash[], int element){
	unsigned hashValue = hashNum(element);
	if(hash[hashValue]==element){
		return hashValue;
	}
	unsigned pos=(hashValue+1)%SIZE;
	while(pos!=hashValue&&hash[pos]!=INT_MIN){
		if(hash[pos]==element){
			return pos;
		}
		pos = (pos+1)%SIZE;
	}
	return -1;
}

int delete(int hash[], int element){
	unsigned pos = search(hash,element);
	if(pos==-1){
		return -1;
	}else{
		hash[pos]=-1;
		return pos;
	}
}

void print(int hash[]){
	int i;
	for(i=0; i<SIZE; ++i)
		printf("%d ",hash[i]);
	printf("\n");
}

void init(int hash[]){
	int i;
	for(i=0; i<SIZE; ++i)
		hash[i]=INT_MIN;
}

void add_rand(int hash[]){
	int i;
	for(i=0; i<11	; i++){
		printf("%d\n", insert(hash,i));
		print(hash);
	}
}

int main(int argc, char const *argv[]){
	srand(time(0));
	int hash[SIZE];
	init(hash);
	add_rand(hash);
	delete(hash,2);
	print(hash);
	insert(hash,10);
	print(hash);
	return 0;
}	