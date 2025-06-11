#include "2.abstract_factory.h"
#include <iostream>

using namespace std;
using namespace _AbstractFactoryPattern;

Slime::Slime(SlimeDefFactory* factory)
{
	size = factory->get_size_def()->get_size();
	type = factory->get_type_def()->get_type();
}

void _AbstractFactoryPattern::Slime::on_create()
{
	cout
		<< "A " << (type == Type::Fire ? "Fire" : type == Type::Ice ? "Ice" : type == Type::Grass ? "Grass" : "Normal")
		<< " slime of size "
		<< (size == Size::Small ? "Small" : size == Size::Medium ? "Medium" : "Large")
		<< " created!" << endl;
}

Slime::~Slime() = default;

_AbstractFactoryPattern::AbstractFactoryPattern::AbstractFactoryPattern()
{
	SmallIceSlimeDefFactory small_ice_slime_def_factory;
	slime = new Slime(&small_ice_slime_def_factory);
}

void _AbstractFactoryPattern::AbstractFactoryPattern::on_created()
{
	slime->on_create();
}
