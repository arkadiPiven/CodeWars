std::vector <int>& opt;

int max(int x, int y){
	if (x >= y) return x;
	return y;
}

int b(int i, std::vector<int>& arr){
	if(i == 0) return 0;
	return max(arr[i] + b(i-1, arr), b(i-1,arr));
}

int maxSequence(const std::vector<int>& arr){
	// Initialize optimal array
	for(int i = 0; i < arr.size()+1; i++){
		opt.push_back(0);
	}
	for (int i = 0; i < arr.size() + 1; i++){
		opt[i] = b(i, arr);
	}
	return b(arr.size);
		
}
