#include "Creature.h"
#include "Gameplay.h"
#include "Monster.h"
#include "Player.h"
#include "Potion.h"
#include "Random.h"

#include <iostream>
#include <string>

int main() {
	std::cout << "Enter your name: ";
	std::string name {};
	std::getline(std::cin >> std::ws, name);

	Player player { name };
	std::cout << "Welcome, " << player.getName() << "\n\n";

	while(!player.isDead() && !player.hasWon()) {
		Gameplay::fightMonster(player);
	}

	if(player.isDead()) {
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad, you can't take with you!\n";
	}

	else {
		std::cout << "You have won the game with " << player.getGold() << " gold!\n";
	}

	return 0;
}