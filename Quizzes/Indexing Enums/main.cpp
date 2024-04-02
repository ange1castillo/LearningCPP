#include <array>
#include <iostream>

namespace Animal{
	enum Type{
		chicken,
		dog,
		elephant,
		duck,
		snake,
		max_types,
	};

	struct Data{
		std::string_view name {};
		int numOfLegs {};
		std::string_view sound {};
	};

	constexpr std::array<Type, max_types> types {chicken, dog, elephant, duck, snake};
	constexpr std::array<Data, max_types> animals {{
		{"chicken", 2, "cluck"},
		{"dog", 4, "woof"},
		{"elephant", 4, "pawoo"},
		{"duck", 2, "quack"},
		{"snake", 0, "hisss"}
	}};
}

std::istream& operator>> (std::istream& in, Animal::Type& animal)
{
    std::string input {};
    std::getline(in >> std::ws, input);

    for (std::size_t index=0; index < Animal::animals.size(); ++index)
    {
        if (input == Animal::animals[index].name)
        {
            animal = static_cast<Animal::Type>(index);
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);
    return in;
}

void printAnimalData(Animal::Type name){
	const Animal::Data& animal {Animal::animals[name]};
	std::cout << "A " << animal.name << " has " << animal.numOfLegs << " legs and says " << animal.sound << ".\n";
}

int main(){
	std::cout << "Enter an animal name: ";
	Animal::Type name {};
	std::cin >> name;

	if(!std::cin){
		std::cin.clear();
		std::cout << "That animals couldn't be found!\n";
	}

	else{
		printAnimalData(name);
	}

	std::cout << "Here is the data for the rest of the animals.\n";
	for(const auto& name: Animal::types){
		printAnimalData(name);
	}
}
