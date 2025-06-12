#pragma once
#include <string>
#include <vector>
#include "example.h"
using namespace std;

namespace _PrototypePattern
{
	class Prototype
	{
	public:
		virtual Prototype* clone() const = 0;
	};

	class Chicken : public Prototype
	{
	public:
		Chicken() {}
		Chicken(const Chicken& other) : weapon(other.weapon), body(other.body), hat(other.hat) {}

		Chicken* clone() const override
		{
			Chicken* chicken = new Chicken();

			chicken->set_weapon(weapon);
			chicken->set_body(body);
			chicken->set_hat(hat);

			return chicken;
		}

		void set_weapon(const string& w) { weapon = w; }
		void set_body(const string& b) { body = b; }
		void set_hat(const string& h) { hat = h; }
	private:
		string weapon;
		string body;
		string hat;
	};


	class PrototypePattern : public Example
	{
	public:
		PrototypePattern();
		~PrototypePattern();

		void on_created() override;

	private:
		vector<_PrototypePattern::Chicken*> chicken_list;
		_PrototypePattern::Chicken* prototype_chicken = nullptr;
	};

}
