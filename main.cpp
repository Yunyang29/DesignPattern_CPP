#include "1.factory_method.h"
#include "2.abstract_factory.h"
#include "3.builder.h"

int main(int argc, char** argv)
{
	//_FactoryMethodPattern::FactoryMethodPattern factoryMethodPattern;
	//factoryMethodPattern.on_created();

	//_AbstractFactoryPattern::AbstractFactoryPattern abstractFactoryPattern;
	//abstractFactoryPattern.on_created();

	_BuilderPattern::BuilderPattern builderPattern;
	builderPattern.on_created();

	return 0;
}