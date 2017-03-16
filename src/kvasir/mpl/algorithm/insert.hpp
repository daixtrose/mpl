//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "rotate.hpp"
#include "../types/int.hpp"
#include "../sequence/push_front.hpp"
#include "../sequence/size.hpp"
#include "../functional/call.hpp"


namespace kvasir {
	namespace mpl {
		namespace c {
			template<typename Index, typename Input, typename C = listify>
			struct insert {
				template<typename...Ts>
				using f = typename rotate<Index, push_front<Input, rotate<uint_<(1 + sizeof...(Ts) - Index::value)>, C>>>::template f<Ts...>;
			};
		}

		template <typename List, unsigned Index, typename Input>
		using insert = c::call<c::insert<uint_<Index>,Input>, List>;
	}
}
