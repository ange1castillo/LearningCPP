#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Creature.h"

class Monster : public Creature {
	private:
		enum Type {
				dragon,
				orc,
				slime,
				max_types
		};

		inline static Creature MonsterData[] {
			Creature { "Dragon", 'D', 20, 4, 100 },
			Creature { "Orc", 'O', 4, 2, 25 },
			Creature { "Slime", 'S', 1, 1, 10 }
		};

	public:
		Monster(Type type);

		static Type getRandomMonster();
};

#endif