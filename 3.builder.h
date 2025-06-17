#pragma once
#include <string>
#include <iostream>
#include "example.h"
using namespace std;

namespace _BuilderPattern
{
	class Chicken
	{
	public:
		Chicken() {}

		void set_weapon(string weapon)
		{
			cout << "Weapon is: " << weapon << endl;
		}

		void set_body(string body)
		{
			cout << "Body is: " << body << endl;
		}

		void set_hat(string hat)
		{
			cout << "Hat is: " << hat << endl;
		}
	};

	class Builder
	{
	public:
		virtual void init_weapon() = 0;
		virtual void init_body() = 0;
		virtual void init_hat() = 0;
		virtual Chicken* build() = 0;
	protected:
		string weapon;
		string body;
		string hat;
	};

	class GreenChickenBuilder : public Builder
	{
	public:
		void init_weapon() override
		{
			weapon = "green_weapon";
		}

		void init_body() override
		{
			body = "green_weapon";
		}

		void init_hat() override
		{
			hat = "green_hat";
		}

		Chicken* build() override
		{
			Chicken* chicken = new Chicken();

			chicken->set_weapon(weapon);
			chicken->set_body(body);
			chicken->set_hat(hat);

			cout << "Green chicken created!" << endl;

			return chicken;
		}
	};

	class CustomChickenBuilder : public Builder
	{
	public:
		void init_weapon() override;
		void init_body() override;
		void init_hat() override;
		Chicken* build() override
		{
			Chicken* chicken = new Chicken();

			chicken->set_weapon(weapon);
			chicken->set_body(body);
			chicken->set_hat(hat);

			cout << "Custom chicken created!" << endl;

			return chicken;
		}
	};
}

class BuilderPattern : public Example
{
public:
	BuilderPattern();
	void on_created() override;
private:
	_BuilderPattern::Chicken* chicken = nullptr;
	_BuilderPattern::GreenChickenBuilder green_chicken_builder;
	_BuilderPattern::CustomChickenBuilder custom_chicken_builder;
};