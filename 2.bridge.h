#include "example.h"
#include <iostream>
#include <string>

namespace _BridgePattern {
	// 抽象
	class Weapon {
	public:
		virtual ~Weapon() = default;
		virtual void use() const = 0;
		virtual std::string getName() const = 0;
	};

	// 具体武器实现
	class Sword : public Weapon {
	public:
		void use() const override {
			std::cout << "Swinging the sword!" << std::endl;
		}

		std::string getName() const override {
			return "Sword";
		}
	};

	class Bow : public Weapon {
	public:
		void use() const override {
			std::cout << "Shooting an arrow!" << std::endl;
		}

		std::string getName() const override {
			return "Bow";
		}
	};

	class Staff : public Weapon {
	public:
		void use() const override {
			std::cout << "Casting a spell!" << std::endl;
		}

		std::string getName() const override {
			return "Staff";
		}
	};

	class Character {
	protected:
		Weapon* weapon;

	public:
		Character(Weapon* weapon) : weapon(weapon) {}
		~Character() = default;

		void setWeapon(Weapon* weapon) {
			this->weapon = weapon;
			std::cout << "Character is using a " << weapon->getName() << "." << std::endl;
		}

		void attack() const {
			std::cout << "Character attacks with ";
			weapon->use();
		}
	};
}

class BridgePattern : public Example
{
public:
	BridgePattern();
	~BridgePattern() = default;
	void on_created() override;
};