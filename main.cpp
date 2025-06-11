#include "1.factory_method.h"
#include "2.abstract_factory.h"

int main(int argc, char** argv)
{
	//_FactoryMethodPattern::FactoryMethodPattern factoryMethodPattern;
	//factoryMethodPattern.on_created();

	_AbstractFactoryPattern::AbstractFactoryPattern abstractFactoryPattern;
	abstractFactoryPattern.on_created();

	return 0;
}