#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Creature.h"
#include <string>

class Potion;

class Player : public Creature {
	private:
		int m_level { 1 };

	public:
		Player(std::string_view name);

		void levelUp();

		bool hasWon() const;

		int getLevel() const;

		void drinkPotion(const Potion& potion);
};

 #endif