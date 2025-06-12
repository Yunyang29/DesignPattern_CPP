#include "3.builder.h"
using namespace _BuilderPattern;

static int type_weapon = 0;
static int type_body = 0;
static int type_hat = 0;

BuilderPattern::BuilderPattern()
{
}

void BuilderPattern::on_created()
{
	green_chicken_builder.init_weapon();
	green_chicken_builder.init_body();
	green_chicken_builder.init_hat();
	chicken = green_chicken_builder.build();


	custom_chicken_builder.init_weapon();
	custom_chicken_builder.init_body();
	custom_chicken_builder.init_hat();
	chicken = custom_chicken_builder.build();
}

void CustomChickenBuilder::init_weapon()
{
	cout << "Select weapon type (0: sword, 1: bow): ";
	cin >> type_weapon;
	weapon = (type_weapon == 0) ? "sword" : "bow";
}

void CustomChickenBuilder::init_body()
{
	cout << "Select body type (0: green, 1: red): ";
	cin >> type_body;
	body = (type_body == 0) ? "green_body" : "red_body";
}

void CustomChickenBuilder::init_hat()
{
	cout << "Select hat type (0: green, 1: red): ";
	cin >> type_hat;
	hat = (type_hat == 0) ? "green_hat" : "red_hat";
}
