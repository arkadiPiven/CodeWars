// Daily Coding Problem
// Given a list of numbers and a number k, return whether any two numbers
// from the list add up to k.

// Example: given [10,15,3,7] and k = 17, return true since 10 + 7 = 17

bool kSum(int* array, int size, int k){
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			if(i == j) continue;
			if(array[i] + array[j] == k) return true;
		}
	}
	return false;
}

// Runs with O(n^2)

bool kSum(int* array, int size, int k){
	std::unordered_map m;
	for(int i = 0; i < size; ++i){
		auto it = m.find(k - array[i]);
		if(it != m.end()) return true;
		m.insert(array[i]);
	}
	return false;
}

// Runs with O(n) on average