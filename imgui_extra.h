#pragma once

#define M_PI 3.14159265358979323846   // pi

#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

#define IM_VEC2_CLASS_EXTRA                                                     \
        constexpr ImVec2(const glm::vec2& f) : x(f.x), y(f.y) {}                   \
        operator glm::vec2() const { return glm::vec2(x,y); }

#define IM_VEC4_CLASS_EXTRA                                                     \
        constexpr ImVec4(const glm::vec4& f) : x(f.x), y(f.y), z(f.z), w(f.w) {}   \
        operator glm::vec4() const { return glm::vec4(x,y,z,w); }


namespace Easing
{
	template<typename number_t>
	number_t easeInOutCubic(number_t x) {
		return x < 0.5f ? 4.0f * x * x * x : 1.0f - pow(-2.0f * x + 2.0f, 3.0f) / 2.0f;
	}
	template<typename number_t>
	number_t easeOutExpo(number_t x) {
		return x == 1 ? 1 : 1 - pow(2, -10 * x);
	}
	template<typename number_t>
	number_t easeInOutQuart(number_t x) {
		return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
	}
	template<typename number_t>
	number_t easeInCubic(number_t x) {
		return x * x * x;
	}
	template<typename number_t>
	number_t easeOutCubic(number_t x) {
		return 1 - pow(1 - x, 3);
	}
	template<typename number_t>
	number_t easeOutSine(number_t x) {
		return sin((x * M_PI) / 2.0f);
	}
	template<typename number_t>
	number_t easeOutCirc(number_t x) {
		return sqrt(1.0f - pow(x - 1.0f, 2.0f));
	}
	template<typename number_t>
	number_t easeOutElastic(number_t x)
	{
		const number_t c4 = (2.0f * M_PI) / 3.0f;
		return x == 0.0f ? 0.0f : x == 1.0f ? 1.0f : pow(2.0f, -10.0f * x) * sin((x * 10.0f - 0.75f) * c4) + 1.0f;
	}
	template<typename number_t>
	number_t easeInOutElastic(number_t x)
	{
		const number_t c5 = (2.0f * M_PI) / 4.5f;
		return x == 0.0f ? 0.0f : x == 1.0f ? 1.0f : x < 0.5f ? -(pow(2.0f, 20.0f * x - 10.0f) * sin((20.0f * x - 11.125f) * c5)) / 2.0f : (pow(2.0f, -20.0f * x + 10.0f) * sin((20.0f * x - 11.125f) * c5)) / 2.0f + 1.0f;
	}
	template<typename number_t>
	number_t easeInOutQuint(number_t x)
	{
		return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
	}
	template<typename number_t>
	number_t easeOutBack(number_t x)
	{
		constexpr number_t c1 = 1.70158;
		constexpr number_t c3 = c1 + 1;

		return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
	}
	template<typename number_t>
	number_t easeInOutBack(number_t x) {

		constexpr number_t c1 = 1.70158;
		constexpr number_t c2 = c1 * 1.525;

		return x < 0.5
		  ? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		  : (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
	}
	template<typename number_t>
	number_t easeInBack(number_t x) {

		constexpr number_t c1 = 1.70158;
		constexpr number_t c3 = c1 + 1;

		return c3 * x * x * x - c1 * x * x;
	}


}
