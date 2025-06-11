#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "example.h"
using namespace std;

namespace _FactoryMethodPattern
{
	enum class Type
	{
		Default,
		Grass,
		Ice,
		Fire
	};

	const unordered_map<Type, std::string> TypeToString = {
		{Type::Default, "Default"},
		{Type::Grass, "Grass"},
		{Type::Ice, "Ice"},
		{Type::Fire, "Fire"}
	};

	class GameObject
	{
	public:
		GameObject(const Type& type) { this->type = type; }
		virtual ~GameObject() = default;
		virtual void on_created() = 0;
	protected:
		Type type;
	};

	class Sword : public GameObject {
	public:
		Sword(const Type& swordType = Type::Default) : GameObject(swordType) {}

		void on_created() override {
			cout << "A " << TypeToString.at(type) << " sword created!" << endl;
		}
	};

	class Slime : public GameObject
	{
	public:
		Slime(const Type& slimeType = Type::Default) : GameObject(slimeType) {}

		void on_created() override {
			cout << "A " << TypeToString.at(type) << " sword created!" << endl;
		}
	};

	class IceSword : public Sword
	{
	public:
		IceSword() : Sword(Type::Ice) {}
	};

	class FireSword :public  Sword
	{
	public:
		FireSword() : Sword(Type::Fire) {}
	};

	class GrassSword : public Sword
	{
	public:
		GrassSword() : Sword(Type::Grass) {}
	};

	class IceSlime : public Slime
	{
	public:
		IceSlime() : Slime(Type::Ice) {}
	};

	class FireSlime : public Slime
	{
	public:
		FireSlime() : Slime(Type::Fire) {}
	};

	class GrassSlime : public Slime
	{
	public:
		GrassSlime() : Slime(Type::Grass) {}
	};

	class SwordFactory
	{
	public:
		Sword* create(Type type)
		{
			switch (type)
			{
			case Type::Ice:
				return new IceSword();
				break;
			case Type::Fire:
				return new FireSword();
				break;
			case Type::Grass:
				return new GrassSword();
				break;
			default:
				break;
			}
		}
	};


	class SlimeFactory
	{
	public:
		Slime* create(Type type)
		{
			switch (type)
			{
			case Type::Ice:
				return new IceSlime();
				break;
			case Type::Fire:
				return new FireSlime();
				break;
			case Type::Grass:
				return new GrassSlime();
				break;
			default:
				break;
			}
		}
	};

	class FactoryMethodPattern : public Example
	{
	public:
		FactoryMethodPattern();

		void on_created() override;

	private:
		vector<_FactoryMethodPattern::GameObject*> game_obj_list;
	};
}