#include "2.bridge.h"
using namespace _BridgePattern;

BridgePattern::BridgePattern()
{

}

void BridgePattern::on_created()
{
	Sword* sword = new Sword();
	Bow* bow = new Bow();
	Staff* staff = new Staff();
	Character* warrior = new Character(sword);
	warrior->attack(); // Warrior attacks with Sword
	warrior->setWeapon(bow);
	warrior->attack(); // Warrior attacks with Bow
}
