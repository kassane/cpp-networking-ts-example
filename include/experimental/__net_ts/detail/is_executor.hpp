//
// detail/is_executor.hpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef NET_TS_DETAIL_IS_EXECUTOR_HPP
#define NET_TS_DETAIL_IS_EXECUTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <experimental/__net_ts/detail/config.hpp>
#include <experimental/__net_ts/detail/type_traits.hpp>

#include <experimental/__net_ts/detail/push_options.hpp>

namespace std {
namespace experimental {
namespace net {
inline namespace v1 {
namespace detail {

struct executor_memfns_base
{
  void context();
  void on_work_started();
  void on_work_finished();
  void dispatch();
  void post();
  void defer();
};

template <typename T>
struct executor_memfns_derived
  : T, executor_memfns_base
{
};

template <typename T, T>
struct executor_memfns_check
{
};

template <typename>
char (&context_memfn_helper(...))[2];

template <typename T>
char context_memfn_helper(
    executor_memfns_check<
      void (executor_memfns_base::*)(),
      &executor_memfns_derived<T>::context>*);

template <typename>
char (&on_work_started_memfn_helper(...))[2];

template <typename T>
char on_work_started_memfn_helper(
    executor_memfns_check<
      void (executor_memfns_base::*)(),
      &executor_memfns_derived<T>::on_work_started>*);

template <typename>
char (&on_work_finished_memfn_helper(...))[2];

template <typename T>
char on_work_finished_memfn_helper(
    executor_memfns_check<
      void (executor_memfns_base::*)(),
      &executor_memfns_derived<T>::on_work_finished>*);

template <typename>
char (&dispatch_memfn_helper(...))[2];

template <typename T>
char dispatch_memfn_helper(
    executor_memfns_check<
      void (executor_memfns_base::*)(),
      &executor_memfns_derived<T>::dispatch>*);

template <typename>
char (&post_memfn_helper(...))[2];

template <typename T>
char post_memfn_helper(
    executor_memfns_check<
      void (executor_memfns_base::*)(),
      &executor_memfns_derived<T>::post>*);

template <typename>
char (&defer_memfn_helper(...))[2];

template <typename T>
char defer_memfn_helper(
    executor_memfns_check<
      void (executor_memfns_base::*)(),
      &executor_memfns_derived<T>::defer>*);

template <typename T>
struct is_executor_class
  : integral_constant<bool,
      sizeof(context_memfn_helper<T>(0)) != 1 &&
      sizeof(on_work_started_memfn_helper<T>(0)) != 1 &&
      sizeof(on_work_finished_memfn_helper<T>(0)) != 1 &&
      sizeof(dispatch_memfn_helper<T>(0)) != 1 &&
      sizeof(post_memfn_helper<T>(0)) != 1 &&
      sizeof(defer_memfn_helper<T>(0)) != 1>
{
};

template <typename T>
struct is_executor
  : conditional<is_class<T>::value,
      is_executor_class<T>,
      false_type>::type
{
};

} // namespace detail
} // inline namespace v1
} // namespace net
} // namespace experimental
} // namespace std

#include <experimental/__net_ts/detail/pop_options.hpp>

#endif // NET_TS_DETAIL_IS_EXECUTOR_HPP
