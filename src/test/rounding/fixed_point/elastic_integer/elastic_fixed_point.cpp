
//          Copyright John McFarlane 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cnl/elastic_fixed_point.h>
#include <cnl/rounding.h>
#include <cnl/_impl/type_traits/identical.h>

using cnl::_impl::identical;

namespace {
    namespace test_nearest_round_down {
        static constexpr auto expected = cnl::elastic_fixed_point<4, -1>{0.5};
        static constexpr auto actual = cnl::convert<cnl::nearest_rounding_tag, cnl::elastic_fixed_point<4, -1>>(
                cnl::elastic_fixed_point<8, -4>{0.3125});

        static_assert(
                identical(expected, actual),
                "cnl::convert<cnl::nearest_rounding_tag, cnl::elastic_fixed_point, cnl::elastic_fixed_point>");
    }

    namespace test_nearest_round_up {
        static constexpr auto expected = cnl::elastic_fixed_point<4, -2>{0.25};
        static constexpr auto actual = cnl::convert<cnl::nearest_rounding_tag, cnl::elastic_fixed_point<4, -2>>(
                cnl::elastic_fixed_point<8, -4>{0.3125});

        static_assert(
                identical(expected, actual),
                "cnl::convert<cnl::nearest_rounding_tag, cnl::elastic_fixed_point, cnl::elastic_fixed_point>");
    }
}
