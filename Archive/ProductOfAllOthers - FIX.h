int ProductExceptI(int* array, int size, int i){
	int ArrayProduct = 1;
	for(int j = 0; j < size; ++j){
		ArrayProduct*=array[j];
	}
	return ArrayProduct\array[i];
}