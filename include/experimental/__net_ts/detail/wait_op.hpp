//
// detail/wait_op.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef NET_TS_DETAIL_WAIT_OP_HPP
#define NET_TS_DETAIL_WAIT_OP_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <experimental/__net_ts/detail/config.hpp>
#include <experimental/__net_ts/detail/operation.hpp>

#include <experimental/__net_ts/detail/push_options.hpp>

namespace std {
namespace experimental {
namespace net {
inline namespace v1 {
namespace detail {

class wait_op
  : public operation
{
public:
  // The error code to be passed to the completion handler.
  std::error_code ec_;

protected:
  wait_op(func_type func)
    : operation(func)
  {
  }
};

} // namespace detail
} // inline namespace v1
} // namespace net
} // namespace experimental
} // namespace std

#include <experimental/__net_ts/detail/pop_options.hpp>

#endif // NET_TS_DETAIL_WAIT_OP_HPP
