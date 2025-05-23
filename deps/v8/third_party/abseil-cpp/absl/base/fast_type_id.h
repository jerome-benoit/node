// Copyright 2020 The Abseil Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef ABSL_BASE_FAST_TYPE_ID_H_
#define ABSL_BASE_FAST_TYPE_ID_H_

#include "absl/base/config.h"

namespace absl {
ABSL_NAMESPACE_BEGIN

namespace base_internal {
template <typename Type>
struct FastTypeTag {
  static constexpr char kDummyVar = 0;
};
}  // namespace base_internal

// The type returned by `absl::FastTypeId<T>()`.
using FastTypeIdType = const void*;

// `absl::FastTypeId<Type>()` evaluates at compile-time to a unique id for the
// passed-in type. These are meant to be good match for keys into maps or
// straight up comparisons.
template <typename Type>
constexpr FastTypeIdType FastTypeId() {
  return &base_internal::FastTypeTag<Type>::kDummyVar;
}

ABSL_NAMESPACE_END
}  // namespace absl

#endif  // ABSL_BASE_FAST_TYPE_ID_H_
