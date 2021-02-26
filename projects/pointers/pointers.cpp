#include <iostream>
const int totalsize = 11;
int array[totalsize] = {5,8,64,139,1436,53671,3,56,9,81,53671};

void prodd(){
	std::cout << "printing odds" << std::endl;
	for(int i = 1; i < totalsize; i = i + 2){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void preven(){
	std::cout << "printing evens" << std::endl;
	for(int i = 0; i < totalsize; i = i + 2){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int getsum(){
	int sum = 0;
	for(int i = 0; i < totalsize; i++){
		sum = sum + array[i];
	}
	return sum;
}

void find4(int *arrayptr, int size, int *lowptr, int *highptr, double *avgptr, int *sumptr){
	*lowptr = 2147483647;
	*highptr = -2147483647;
	*sumptr = 0;
	*avgptr = 0;
	for(int i = 0; i < size; i ++){
		*sumptr = *sumptr + array[i];
		if(*lowptr > array[i]){
			*lowptr = array[i];
		}
		if(*highptr < array[i]){
			*highptr = array[i];
		}
	}
	*avgptr = *sumptr / size;
}

void proddvalues(){
	std::cout << "printing odd values" << std::endl;
	for(int i = 0; i < totalsize; i++){
		if( (array[i] % 2) == 1){
			std::cout << array[i] << " ";
		}
	}
	std::cout << std::endl;
}

void prevenvalues(){
	std::cout << "printing even values" << std::endl;
	for(int i = 0;i < totalsize; i++){
		if( (array[i] % 2) == 0){
			std::cout << array[i] << " ";
		}
	}
	std::cout << std::endl;
}

int main(){
	int low;
	int high;
	double avg;
	int sum;
	prodd();
	preven();
	proddvalues();
	prevenvalues();
	find4(array, totalsize, &low, &high, &avg, &sum);
	std::cout << "after call" << std::endl;
	std::cout << low << std::endl;
	std::cout << high << std::endl;
	std::cout << avg << std::endl;
	std::cout << sum << std::endl;
}
