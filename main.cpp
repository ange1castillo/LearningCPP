#include <iostream>
#include <utility>
#include <vector>

template<typename T>
std::pair<int, int> getMinMaxIndices(const std::vector<T>& array){

	std::size_t min {0};
	std::size_t max {0};

	for(std::size_t index {1}; index < std::size(array); ++index){
		if(array[index] < array[min]){
			min = index;
		}

		if(array[index] > array[max]){
			max = index;
		}
	}
	return {min, max};
}

template <typename T>
void print(const std::vector<T>& array){
	std::pair minMax {getMinMaxIndices(array)};
	bool comma { false };

    std::cout << "With array ( ";
    for (const auto& element: array)
    {
        if (comma){
			std::cout << ", ";
		}

        std::cout << element;
        comma = true;
    }
    std::cout << " ):\n";
	std::cout << "The min element has index " << minMax.first << " and value " << array[static_cast<std::size_t>(minMax.first)] << '\n';
	std::cout << "The max element has index " << minMax.second << " and value " << array[static_cast<std::size_t>(minMax.second)] << '\n' << '\n';
}


int main(){
	std::vector<int> array {};
	std::cout << "Enter number to add (use -1 to stop): ";
	int input {};

	while(true){
		std::cin >> input;
		if(input == -1){
			break;
		}

		if(!std::cin){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		array.push_back(input);
	}

	print(array);
}
