#ifndef _GAMEPLAY_H_
#define _GAMEPLAY_H_

#include "Monster.h"
#include "Player.h"
#include "Potion.h"
#include "Random.h"

#include <iostream>

namespace Gameplay {
	void attackPlayer(Player& player, const Monster& monster) {
		std::cout << "The " << monster.getName() << " hit you for " << monster.getAttackDmg() << "\n\n";
		player.reduceHealth(monster.getAttackDmg());
	}

	void attackMonster(Player& player, Monster& monster) {
		std::cout << "\nYou hit the " << monster.getName() << " for " << player.getAttackDmg() << "\n";
		monster.reduceHealth(player.getAttackDmg());
	}

	void displayStatus(const Player& player, const Monster& monster) {
		std::cout << player.getName() << "              " << monster.getName() << '\n';
		std::cout << " Health: " << player.getHealth() << "         " <<  "Health: " << monster.getHealth() << '\n';
		std::cout << " Attack DMG: " << player.getAttackDmg() << "      " << "Attack DMG: " << monster.getAttackDmg() << "\n";
		std::cout << " Gold: " << player.getGold() << "            " << "Gold: " << monster.getGold() << "\n\n";
	}

	void monsterKilled(Player& player, const Monster& monster) {
		std::cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << '\n';
		player.addGold(monster.getGold());
		std::cout << "You found " << monster.getGold() << " gold.\n\n";

		if(Random::get(0, 3)) {
			Potion potion { Potion::getRandomPotion() };
			std::cout << "You found a mythical potion! Do you want to drink it? (y/n): ";
			char input {};
			std::cin >> input;

			if(input == 'Y' || input == 'y'){
				player.drinkPotion(potion);
				std::cout << "You drank a " << potion.getSizeName(potion.getSize()) << " potion of " << potion.getTypeName(potion.getType()) << "\n\n";
			}
		}
	}

	void fightMonster(Player& player) {
		Monster monster { Monster::getRandomMonster() };

		std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")\n\n";

		while(!player.isDead()) {
			displayStatus(player, monster);
			
			std::cout << "(R)un or (F)ight: ";
			char input {};
			std::cin >> input;

			if(input == 'F' || input == 'f') {
				attackMonster(player, monster);

				if(monster.isDead()) {
					monsterKilled(player, monster);
					return;
				}

				attackPlayer(player, monster);
			}

			else if (input == 'R' || input == 'r') {
				if(Random::get(0, 1)) {
					std::cout << "\nYou successfuly fleed!\n\n";
					return;
				}

				std::cout << "\nYou failed to flee.\n";
				attackPlayer(player, monster);
			}
		}
	}
};

#endif