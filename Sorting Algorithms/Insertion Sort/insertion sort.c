#include<stdio.h>

void insertionSort(int array[]){
	int i,j,key;
	int n=(int)(sizeof(array)/sizeof(int));									
	for(j=1;j<5;j++){								
		i=j-1;
		key=array[j];
		while(i>=0&&array[i]>key){
			array[i+1]=array[i];
			i--;
		}
			array[i+1]=key;
	}
	
}

int main(){
	int array[5]={50,20,10,40,30}; 
	int i;
	insertionSort(&array);
	for( i=0;i<5;i++){
			printf("%d ",array[i]);
	}
	return 0;
}
