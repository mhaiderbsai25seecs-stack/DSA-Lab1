#include <iostream>
#include< vector>


std::vector<int> allIndices(std::vector <int> array, int key ){
	std::vector <int> output;
	for (int i = 0; i < array.size(); i++){
		if (array[i] == key){
			output.push_back(i);
		}
	}
	return output;
}

int main(){
	int key = 0;
	std::vector<int> input = {};

	std::cout << "key :" << key <<std::endl;
	std::cout << "input :";
	for (int i = 0; i < input.size(); i++){
		std::cout << input[i] << ",";
	}
	std::cout << std::endl;
	
	std::cout << "indices :";
	std::vector <int> output = allIndices(input,key);
	for (int i = 0; i < output.size(); i++){
		std::cout << output[i] <<" ";
	}

	int x;
	std::cin >> x;

	return 0;
}