#ifndef _POTION_H_
#define _POTION_H_

#include <array>
#include <string>

class Potion {
	public:
		enum Type {
			health,
			strength,
			poison,
			max_types
		};

	private:
		enum Size {
			small,
			medium,
			large,
			max_sizes
		};

		Type m_type {};
		Size m_size {};

		inline static std::array<std::array<int, max_sizes>, max_types> potions {{
			{ 2, 3, 5 },
			{ 1, 2, 3 },
			{ 1, 2, 3 }
		}};

	public:
		Potion(Type type, Size size);

		int getPotion() const;

		Type getType() const;

		Size getSize() const;

		static Potion getRandomPotion();

		static std::string_view getTypeName(Type type);

		static std::string_view getSizeName(Size size);
};

#endif