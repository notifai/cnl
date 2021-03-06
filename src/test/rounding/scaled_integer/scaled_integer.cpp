
//          Copyright John McFarlane 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cnl/scaled_integer.h>
#include <cnl/rounding.h>
#include <cnl/_impl/type_traits/identical.h>

using cnl::_impl::identical;

namespace {
    namespace test_nearest_round_down {
        static constexpr auto expected = cnl::scaled_integer<int, cnl::power<-1>>{0.5};
        static constexpr auto actual = cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer<int, cnl::power<-1>>>(
                cnl::scaled_integer<int, cnl::power<-4>>{0.3125});

        static_assert(
                identical(expected, actual),
                "cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer, cnl::scaled_integer>");
    }

    namespace test_nearest_round_up {
        static constexpr auto expected = cnl::scaled_integer<int, cnl::power<-2>>{-0.25};
        static constexpr auto actual = cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer<int, cnl::power<-2>>>(
                cnl::scaled_integer<int, cnl::power<-4>>{-0.3125});

        static_assert(
                identical(expected, actual),
                "cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer, cnl::scaled_integer>");
    }

    namespace test_nearest_round_up_float {
        static constexpr auto expected = cnl::scaled_integer<int, cnl::power<-2>>{-0.25};
        static constexpr auto actual = cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer<int, cnl::power<-2>>>(
                -0.3125f);

        static_assert(
                identical(expected, actual),
                "cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer, cnl::scaled_integer>");
    }

    namespace test_truncate_round_up {
        static constexpr auto expected = cnl::scaled_integer<int, cnl::power<>>{1};
        static constexpr auto actual = cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer<int, cnl::power<>>>(
                cnl::scaled_integer<int, cnl::power<-2>>{0.75});

        static_assert(
                identical(expected, actual),
                "cnl::convert<cnl::nearest_rounding_tag>"); //Fails gives 0.75 as result.
    }

    namespace test_nearest_int {
        static_assert(
                identical(
                        3,
                        cnl::convert<cnl::nearest_rounding_tag, int>(
                                cnl::scaled_integer<int, cnl::power<-2>>{2.5})),
                "cnl::convert<cnl::nearest_rounding_tag, int, cnl::scaled_integer>");
        static_assert(
                identical(
                        2,
                        cnl::convert<cnl::nearest_rounding_tag, int>(
                                cnl::scaled_integer<int, cnl::power<-2>>{2.4375})),
                "cnl::convert<cnl::nearest_rounding_tag, int, cnl::scaled_integer>");
    }

    namespace test_nearest_from_int {
        static_assert(
                identical(
                        cnl::scaled_integer<int, cnl::power<2>>{4},
                        cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer<int, cnl::power<2>>>(5)),
                "cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer, int>");
        static_assert(
                identical(
                        cnl::scaled_integer<int, cnl::power<2>>{8},
                        cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer<int, cnl::power<2>>>(6)),
                "cnl::convert<cnl::nearest_rounding_tag, cnl::scaled_integer, int>");
    }

    namespace test_native_int {
        static_assert(
                identical(
                        2,
                        cnl::_impl::tagged_convert_operator<cnl::native_rounding_tag, int, cnl::scaled_integer<int, cnl::power<-2>>>{}(
                                2.5)),
                "cnl::convert<cnl::native_rounding_tag, int, cnl::scaled_integer>");
        static_assert(
                identical(
                        2,
                        cnl::convert<cnl::native_rounding_tag, int>(
                                cnl::scaled_integer<int, cnl::power<-2>>{2.4375})),
                "cnl::convert<cnl::native_rounding_tag, int, cnl::scaled_integer>");
    }

    namespace test_native_from_int {
        static_assert(
                identical(
                        cnl::scaled_integer<int, cnl::power<2>>{4},
                        cnl::convert<cnl::native_rounding_tag, cnl::scaled_integer<int, cnl::power<2>>>(5)),
                "cnl::convert<cnl::native_rounding_tag, cnl::scaled_integer, int>");
        static_assert(
                identical(
                        cnl::scaled_integer<int, cnl::power<2>>{4},
                        cnl::convert<cnl::native_rounding_tag, cnl::scaled_integer<int, cnl::power<2>>>(6)),
                "cnl::convert<cnl::native_rounding_tag, cnl::scaled_integer, int>");
    }
}
