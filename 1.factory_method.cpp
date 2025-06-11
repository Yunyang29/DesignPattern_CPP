#include "1.factory_method.h"
using namespace _FactoryMethodPattern;

FactoryMethodPattern::FactoryMethodPattern()
{
	SwordFactory swordFactory;
	SlimeFactory slimeFactory;

	game_obj_list.push_back(swordFactory.create(Type::Ice));
	game_obj_list.push_back(swordFactory.create(Type::Fire));
	game_obj_list.push_back(swordFactory.create(Type::Grass));
	game_obj_list.push_back(swordFactory.create(Type::Ice));
	game_obj_list.push_back(swordFactory.create(Type::Fire));
	game_obj_list.push_back(swordFactory.create(Type::Grass));
}

void FactoryMethodPattern::on_created()
{
	for (GameObject* game_obj : game_obj_list)
		game_obj->on_created();
}