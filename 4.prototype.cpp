#include "4.prototype.h"

PrototypePattern::PrototypePattern()
{
	prototype_chicken = new _PrototypePattern::Chicken();
	prototype_chicken->set_weapon("default_weapon");
	prototype_chicken->set_body("default_body");
	prototype_chicken->set_hat("default_hat");
}

PrototypePattern::~PrototypePattern()
{
}

void PrototypePattern::on_created()
{
	// Create a few clones with different attributes
	for (int i = 0; i < 3; ++i) {
		chicken_list.push_back(prototype_chicken->clone());
	}
}
