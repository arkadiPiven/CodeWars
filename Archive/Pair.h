//cons(a,b) constructs a pair, and car(pair) and cdr(pair)
//return the first and last element of that pair. For example,
//car(cons(3,4)) return 3, and cdr(cons(3, 4)) return 4

// Given Implementation

std::pair<int, int> cons(int a, int b){
	return std::pair<int, int> p(a,b);
}

int car(std::pair<int, int> p){
	return p.first;
}

int cdr(std::pair<int, int> p){
	return p.second;
}