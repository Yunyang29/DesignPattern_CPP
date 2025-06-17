#pragma once
#include "example.h"

namespace _AbstractFactoryPattern
{
	enum class Size
	{
		Small,
		Medium,
		Large
	};

	enum class Type
	{
		Default,
		Grass,
		Ice,
		Fire
	};

#pragma region size 

	class SizeDef
	{
	public:
		virtual Size get_size() = 0;
	};

	class SmallSizeDef : public SizeDef
	{
	public:
		Size get_size() override {
			return Size::Small;
		}
	};

	class MediumSizeDef : public SizeDef
	{
	public:
		Size get_size() override {
			return Size::Medium;
		}
	};

	class LargeSizeDef : public SizeDef
	{
	public:
		Size get_size() override {
			return Size::Large;
		}
	};

#pragma endregion

#pragma region type

	class TypeDef
	{
	public:
		virtual Type get_type() = 0;
	};


	class GrassTypeDef : public TypeDef
	{
	public:
		Type get_type() override {
			return Type::Grass;
		}
	};

	class IceTypeDef : public TypeDef
	{
	public:
		Type get_type() override {
			return Type::Ice;
		}
	};

	class FireTypeDef : public TypeDef
	{
	public:
		Type get_type() override {
			return Type::Fire;
		}
	};

#pragma endregion


#pragma region  slime

	class SlimeDefFactory
	{
	public:
		virtual SizeDef* get_size_def() = 0;
		virtual TypeDef* get_type_def() = 0;
	};

	class SmallIceSlimeDefFactory : public SlimeDefFactory
	{
	public:
		SizeDef* get_size_def() override {
			return &smallSizeDef;
		}
		TypeDef* get_type_def() override {
			return &iceTypeDef;
		}
	private:
		SmallSizeDef smallSizeDef;
		IceTypeDef iceTypeDef;
	};

	class Slime
	{
	public:
		Slime(SlimeDefFactory* factory);
		~Slime();
		void on_create();

	private:
		Type type;
		Size size;
	};

#pragma endregion

}

class AbstractFactoryPattern : public Example
{
public:
	AbstractFactoryPattern();
	void on_created() override;
private:
	_AbstractFactoryPattern::Slime* slime;
};