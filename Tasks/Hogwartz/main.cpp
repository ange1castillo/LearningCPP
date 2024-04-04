#include <array>
#include <iostream>

#include "Random.h"

namespace Potion {
	enum Type {
		healing,
		mana,
		speed,
		invisibility,
		maxPotionTypes,
	};

	constexpr std::array cost {20, 30, 12, 50};
	constexpr std::array types {healing, mana, speed, invisibility};
	constexpr std::array<std::string_view, maxPotionTypes> name {"healing", "mana", "speed", "invisibility"};
}

class Player{
	private:
		const std::string_view m_name {};
		std::array<int, Potion::maxPotionTypes> m_inventory {};
		int m_gold {Random::get(80, 120)}; 
	
	public:
		explicit Player(std::string_view name)
			: m_name {name}
		{

		}

	std::string_view getName() const { return m_name;}
	int getGold() const { return m_gold;}
	void setGold(int price) { m_gold -= price;}
	int getInventory(Potion::Type potion) const { return m_inventory[potion];}
	void setInventory(Potion::Type potion) { m_inventory[potion] += 1;}
};

int charNumToInt(char c) {return c - '0';} 

void updatePlayer(Player& player, Potion::Type type){
	player.setGold(Potion::cost[type]);
	player.setInventory(type);
}

std::string getPlayerName(){
	std::cout << "Enter your name: ";
	std::string name {};
	std::getline(std::cin >> std::ws, name);
	return name;
}

Potion::Type buy(){
	std::cout << "Enter the number of the potion you'd like to purchase or enter 'q' to quit: ";
	while(true){
		char input {};
		std::cin >> input;
		
		if(!std::cin){
			std::cout << "That is an invalid input. Try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if(input == 'q'){
			return Potion::maxPotionTypes;
		}

		int intInput {charNumToInt(input)};
		if(intInput < 0 || intInput > 3){
			std::cout << "That is an invalid input. Try again: ";
			continue;
		}

		return static_cast<Potion::Type>(intInput);
	}
}

void displayInventory(const Player& player){
	std::cout << "Your inventory contains:\n";

	for(const auto& potion: Potion::types){
		if( player.getInventory(potion) == 0){
			continue;
		}
		std::cout << player.getInventory(potion) << "x potion of " << Potion::name[potion] << '\n';
	}

	std::cout << "You escaped with " << player.getGold() << " gold remaining.\n\n";
}

void end(const Player& player){
	displayInventory(player);
	std::cout << "Thanks for shopping ay Roscoe's potion emporium!\n";
}

void shop(Player& player){
	while(true){
		std::cout << "Here is our selection for today: \n";
		for(const auto& type: Potion::types){
			std::cout << type << ") " << Potion::name[type] << " costs " << Potion::cost[type] << '\n';
		}

		Potion::Type userInput {buy()};
		if(userInput == Potion::maxPotionTypes){
			break;
		}

		if(Potion::cost[userInput] > player.getGold()){
			std::cout << "You cannot afford that.\n\n";
			continue;
		}

		updatePlayer(player, userInput);

		std::cout << "You purchased a potion of " << Potion::name[userInput] << ". You have " << player.getGold() << " gold left.\n\n";
	}

	std::cout << std::endl;
}

void play(){
	std::cout << "Welcome to Roscoe's potion emprium!\n";
	Player player {getPlayerName()};
	std::cout << "Hello " << player.getName() << ", " << "you have " << player.getGold() << " gold.\n\n";
	shop(player);
	std::cout << std::endl;
	end(player);
}

void startGame(){
	play();
}

int main(){
	startGame();
	return 0;
}
