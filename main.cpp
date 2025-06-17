#include "1.factory_method.h"
#include "2.abstract_factory.h"
#include "3.builder.h"
#include "4.prototype.h"
#include "5.singleton.h"

int main(int argc, char** argv)
{
	//FactoryMethodPattern factory_method_pattern;
	//factory_method_pattern.on_created();

	//AbstractFactoryPattern abstract_factory_pattern;
	//abstract_factory_pattern.on_created();

	//BuilderPattern builder_pattern;
	//builder_pattern.on_created();

	//PrototypePattern prototype_pattern;
	//prototype_pattern.on_created();

	SingletonPattern singleton_pattern;
	singleton_pattern.on_created();

	return 0;
}