
//          Copyright John McFarlane 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef CNL_IMPL_NUM_TRAITS_ADOPT_WIDTH
#define CNL_IMPL_NUM_TRAITS_ADOPT_WIDTH

#include "width.h"
#include "set_width.h"

namespace cnl {
    namespace _impl {
        template<typename Mimic, typename Source>
        struct adopt_width : set_width<Mimic, width<Source>::value> {
        };

        template<typename Mimic, typename Source>
        using adopt_width_t = typename adopt_width<Mimic, Source>::type;
    }
}

#endif  // CNL_IMPL_NUM_TRAITS_ADOPT_WIDTH
