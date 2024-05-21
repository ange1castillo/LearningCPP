#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <string>

class Creature {
	protected:
		std::string m_name {};
		char m_symbol {};
		int m_health {};
		int m_attackDmg {};
		int m_gold {};

	public:
		Creature(std::string_view name, char symbol, int health, int attackDmg, int gold);

		void addGold(int gold);

		void reduceHealth(int reduceBy);

        bool isDead() const;

		const std::string_view getName() const;

		char getSymbol() const;

		int getHealth() const;

		int getAttackDmg() const;

		int getGold() const;
};

#endif