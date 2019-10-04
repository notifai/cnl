
//          Copyright John McFarlane 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file ../../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <cnl/scaled_integer.h>
#include <cnl/overflow_integer.h>

#define TEST_NATIVE_INTEGER
#define TEST_LABEL native_integer_  // NOLINT(cppcoreguidelines-macro-usage)

////////////////////////////////////////////////////////////////////////////////
// integer types used as scaled_integer Rep type

using test_int = cnl::overflow_integer<int, cnl::native_overflow_tag>;

////////////////////////////////////////////////////////////////////////////////
// perform scaled_integer tests with this type of scaled_integer specialization

#include "../scaled_integer_common.h"