#include "5.singleton.h"
using namespace _SingletonPattern;

SceneManager* SceneManager::manager = nullptr;

SingletonPattern::SingletonPattern()
{
	// Initialize the singleton instance
	SceneManager::instance()->add("level1", new Level_1());
	SceneManager::instance()->add("level2", new Level_2());
	SceneManager::instance()->add("level3", new Level_3());
}

void SingletonPattern::on_created()
{
	// Switch to a specific scene
	SceneManager::instance()->switch_to("level1");
}
