/*
 * 汎用Utility
 */
#include <string>

typedef unsigned int uint;

namespace HsEngine
{
	// 配列のサイズ取得
	template <typename T, std::size_t N>
	std::size_t ArrayLength (const T (&array)[N]);
}
