
enum { UP, DOWN };


bool check_caught(std::pair<int,int>& X, std::vector<std::tuple<int,int,int>>& Navies){
	int p_x = X.first;
	int p_y = X.second;
	for(auto it = Navies.begin(); it != Navies.end(); ++it){
		int n_x = std::get<0>(*it);
		int n_y = std::get<1>(*it);
		
		int diff_x = p_x - n_x;
		int diff_y = p_y - n_y;
		
		if(abs(diff_x) <= 1 && abs(diff_y) <= 1) return false;
	}
	
	return true;
}

bool check_course(std::vector<std::string> sea_map){

  // Intialize Data Structures and variables
  
  std::pair<int,int> X;
  std::vector<std::tuple<int,int,int>> Navies;
  
  int rows = sea_map.size();
  int columns = sea_map[0].size();
  
  // Find initial coordinates
  
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j< columns; ++j){
      if(sea_map[i][j] == 'X'){
        X.first = i;
        X.second = j;
      }
      if(sea_map[i][j] == 'N'){
		if(i == 0){
				std::tuple<int,int,int> N(i,j,DOWN);
				Navies.push_back(N);
		}
		else{
			std::tuple<int,int,int> N(i,j,UP);
			Navies.push_back(N);
		}
      }
    }
  }
  
  // Play
  
  while(true){
    
	// Check if pirate has been caught
	
    if(!check_caught(X, Navies)) return false;
    
	// Check if pirate has escaped
	
	if(X.second == columns - 1) return true;
	
	// Make a move
	
	X.second += 1;
	for(auto it = Navies.begin(); it != Navies.end(); ++it){
		if(std::get<2>(*it) == DOWN){
			if(std::get<1>(*it) == columns - 1){
				std::get<1>(*it) = columns - 2;
				std::get<2>(*it) = UP;
				continue;
			}
			std::get<1>(*it) = std::get<1>(*it) - 1;
			continue;
		}
		if(std::get<2>(*it) == UP){
			if(std::get<1>(*it) == 0){
				std::get<1>(*it) = 1;
				std::get<2>(*it) = DOWN;
				continue;
			}
			std::get<1>(*it) = std::get<1>(*it) - 1;
		}
	}
  }
}
