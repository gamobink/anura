/*
	Copyright (C) 2003-2014 by Kristina Simpson <sweet.kristas@gmail.com>
	
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	   1. The origin of this software must not be misrepresented; you must not
	   claim that you wrote the original software. If you use this software
	   in a product, an acknowledgement in the product documentation would be
	   appreciated but is not required.

	   2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original software.

	   3. This notice may not be removed or altered from any source
	   distribution.
*/

#pragma once

#include <boost/intrusive_ptr.hpp>

#include <memory>
#include "Color.hpp"
#include "variant.hpp"
#include "formula_callable.hpp"
#include "formula_callable_definition.hpp"

namespace KRE
{
	class ColorTransform : public game_logic::FormulaCallable
	{
	public:
		ColorTransform();
		explicit ColorTransform(const variant& node);
		explicit ColorTransform(const Color& color);
		explicit ColorTransform(int ar, int ag, int ab, int aa);
		explicit ColorTransform(float mr, float mg, float mb, float ma, float ar, float ag, float ab, float aa);
		explicit ColorTransform(int mr, int mg, int mb, int ma, int ar, int ag, int ab, int aa);
		~ColorTransform();

		float mulRed() const { return mul_rgba_[0]; }
		float mulGreen() const { return mul_rgba_[1]; }
		float mulBlue() const { return mul_rgba_[2]; }
		float mulAlpha() const { return mul_rgba_[3]; }

		float addRed() const { return add_rgba_[0]; }
		float addGreen() const { return add_rgba_[1]; }
		float addBlue() const { return add_rgba_[2]; }
		float addAlpha() const { return add_rgba_[3]; }

		void setAddRed(int ar);
		void setAddGreen(int ag);
		void setAddBlue(int ab);
		void setAddAlpha(int aa);

		Color applyWhite() const;
		Color applyBlack() const;

		Color apply(const Color& color) const;
		variant write() const;

		// compatibility functions
		bool fits_in_color() const;
		Color toColor() const;
		std::string toString() const;
	private:
		DECLARE_CALLABLE(ColorTransform);
		float mul_rgba_[4];
		float add_rgba_[4];
	};

	ColorTransform operator+(const ColorTransform& a, const ColorTransform& b);
	ColorTransform operator-(const ColorTransform& a, const ColorTransform& b);

	ColorTransform operator-(const ColorTransform& a, const Color& color);

	bool operator==(const ColorTransform& a, const ColorTransform& b);
	bool operator!=(const ColorTransform& a, const ColorTransform& b);

	typedef boost::intrusive_ptr<ColorTransform> ColorTransformPtr;
}
