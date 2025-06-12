#include "4.prototype.h"

_PrototypePattern::PrototypePattern::PrototypePattern()
{
	prototype_chicken = new Chicken();
	prototype_chicken->set_weapon("default_weapon");
	prototype_chicken->set_body("default_body");
	prototype_chicken->set_hat("default_hat");
}

_PrototypePattern::PrototypePattern::~PrototypePattern()
{
}

void _PrototypePattern::PrototypePattern::on_created()
{
	// Create a few clones with different attributes
	for (int i = 0; i < 3; ++i) {
		chicken_list.push_back(prototype_chicken->clone());
	}
}
