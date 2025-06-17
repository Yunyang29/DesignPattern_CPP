#include "1.adapter.h"
using namespace _AdapterPattern;

void AdapterPattern::on_created()
{
	InputDevice* keyboard = new Keyboard();
	InputAdapter keyboardAdapter(keyboard);

	keyboardAdapter.press();
	keyboardAdapter.release();

	delete keyboard;

	//InputDevice* mouse = new Mouse();
	//InputAdapter mouseAdapter(mouse);
	//mouseAdapter.press();
	//mouseAdapter.release();
	//delete mouse;
}
