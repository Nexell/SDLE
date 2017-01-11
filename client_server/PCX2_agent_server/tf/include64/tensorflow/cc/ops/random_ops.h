// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_RANDOM_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_RANDOM_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Draws samples from a multinomial distribution.
//
// Arguments:
// * scope: A Scope object
// * logits: 2-D Tensor with shape `[batch_size, num_classes]`.  Each slice `[i, :]`
// represents the unnormalized log probabilities for all classes.
// * num_samples: 0-D.  Number of independent samples to draw for each row slice.
class Multinomial {
 public:
  // Optional attribute setters for Multinomial :
  //
  // Seed(int64): Defaults to 0
  //     If either seed or seed2 is set to be non-zero, the internal random number
  // generator is seeded by the given seed.  Otherwise, a random seed is used.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  struct Attrs {
    Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  Multinomial(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input logits,
            ::tensorflow::ops::Input num_samples);
  Multinomial(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input logits,
            ::tensorflow::ops::Input num_samples, const Multinomial::Attrs&
            attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

// Outputs random values from a normal distribution. The parameters may each be a
//
// scalar which applies to the entire output, or a vector of length shape[0] which
// stores the parameters for each batch.
//
// Arguments:
// * scope: A Scope object
// * shape: The shape of the output tensor. Batches are indexed by the 0th dimension.
// * means: The mean parameter of each batch.
// * stdevs: The standard deviation parameter of each batch. Must be greater than 0.
// * minvals: The minimum cutoff. May be -infinity.
// * maxvals: The maximum cutoff. May be +infinity, and must be more than the minval
// for each batch.
class ParameterizedTruncatedNormal {
 public:
  // Optional attribute setters for ParameterizedTruncatedNormal :
  //
  // Seed(int64): Defaults to 0
  //     If either `seed` or `seed2` are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  struct Attrs {
    Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  ParameterizedTruncatedNormal(const ::tensorflow::Scope& scope,
                             ::tensorflow::ops::Input shape,
                             ::tensorflow::ops::Input means,
                             ::tensorflow::ops::Input stdevs,
                             ::tensorflow::ops::Input minvals,
                             ::tensorflow::ops::Input maxvals);
  ParameterizedTruncatedNormal(const ::tensorflow::Scope& scope,
                             ::tensorflow::ops::Input shape,
                             ::tensorflow::ops::Input means,
                             ::tensorflow::ops::Input stdevs,
                             ::tensorflow::ops::Input minvals,
                             ::tensorflow::ops::Input maxvals, const
                             ParameterizedTruncatedNormal::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

// Outputs random values from the Gamma distribution(s) described by alpha.
//
// This op uses the algorithm by Marsaglia et al. to acquire samples via
// transformation-rejection from pairs of uniform and normal random variables.
// See http://dl.acm.org/citation.cfm?id=358414
//
// Arguments:
// * scope: A Scope object
// * shape: 1-D integer tensor. Shape of independent samples to draw from each
// distribution described by the shape parameters given in alpha.
// * alpha: A tensor in which each scalar is a "shape" parameter describing the
// associated gamma distribution.
class RandomGamma {
 public:
  // Optional attribute setters for RandomGamma :
  //
  // Seed(int64): Defaults to 0
  //     If either `seed` or `seed2` are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  struct Attrs {
    Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  RandomGamma(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input shape,
            ::tensorflow::ops::Input alpha);
  RandomGamma(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input shape,
            ::tensorflow::ops::Input alpha, const RandomGamma::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

// Randomly shuffles a tensor along its first dimension.
//
//   The tensor is shuffled along dimension 0, such that each `value[j]` is mapped
//   to one and only one `output[i]`. For example, a mapping that might occur for a
//   3x2 tensor is:
//
// ```prettyprint
// [[1, 2],       [[5, 6],
//  [3, 4],  ==>   [1, 2],
//  [5, 6]]        [3, 4]]
// ```
//
// Arguments:
// * scope: A Scope object
// * value: The tensor to be shuffled.
class RandomShuffle {
 public:
  // Optional attribute setters for RandomShuffle :
  //
  // Seed(int64): Defaults to 0
  //     If either `seed` or `seed2` are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  struct Attrs {
    Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  RandomShuffle(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input value);
  RandomShuffle(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input value,
              const RandomShuffle::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

// Outputs random values from a normal distribution.
//
// The generated values will have mean 0 and standard deviation 1.
//
// Arguments:
// * scope: A Scope object
// * shape: The shape of the output tensor.
// * dtype:
//     The type of the output.
class RandomStandardNormal {
 public:
  // Optional attribute setters for RandomStandardNormal :
  //
  // Seed(int64): Defaults to 0
  //     If either `seed` or `seed2` are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  struct Attrs {
    Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  RandomStandardNormal(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     shape, DataType dtype);
  RandomStandardNormal(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     shape, DataType dtype, const RandomStandardNormal::Attrs&
                     attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

// Outputs random values from a uniform distribution.
//
// The generated values follow a uniform distribution in the range `[0, 1)`. The
// lower bound 0 is included in the range, while the upper bound 1 is excluded.
//
// Arguments:
// * scope: A Scope object
// * shape: The shape of the output tensor.
// * dtype:
//     The type of the output.
class RandomUniform {
 public:
  // Optional attribute setters for RandomUniform :
  //
  // Seed(int64): Defaults to 0
  //     If either `seed` or `seed2` are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  struct Attrs {
    Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  RandomUniform(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input shape,
              DataType dtype);
  RandomUniform(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input shape,
              DataType dtype, const RandomUniform::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

// Outputs random integers from a uniform distribution.
//
// The generated values are uniform integers in the range `[minval, maxval)`.
// The lower bound `minval` is included in the range, while the upper bound
// `maxval` is excluded.
//
// The random integers are slightly biased unless `maxval - minval` is an exact
// power of two.  The bias is small for values of `maxval - minval` significantly
// smaller than the range of the output (either `2^32` or `2^64`).
//
// Arguments:
// * scope: A Scope object
// * shape: The shape of the output tensor.
// * minval: 0-D.  Inclusive lower bound on the generated integers.
// * maxval: 0-D.  Exclusive upper bound on the generated integers.
class RandomUniformInt {
 public:
  // Optional attribute setters for RandomUniformInt :
  //
  // Seed(int64): Defaults to 0
  //     If either `seed` or `seed2` are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  struct Attrs {
    Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  RandomUniformInt(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 shape, ::tensorflow::ops::Input minval,
                 ::tensorflow::ops::Input maxval);
  RandomUniformInt(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 shape, ::tensorflow::ops::Input minval,
                 ::tensorflow::ops::Input maxval, const
                 RandomUniformInt::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

// Outputs random values from a truncated normal distribution.
//
// The generated values follow a normal distribution with mean 0 and standard
// deviation 1, except that values whose magnitude is more than 2 standard
// deviations from the mean are dropped and re-picked.
//
// Arguments:
// * scope: A Scope object
// * shape: The shape of the output tensor.
// * dtype:
//     The type of the output.
class TruncatedNormal {
 public:
  // Optional attribute setters for TruncatedNormal :
  //
  // Seed(int64): Defaults to 0
  //     If either `seed` or `seed2` are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  struct Attrs {
    Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  TruncatedNormal(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                shape, DataType dtype);
  TruncatedNormal(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                shape, DataType dtype, const TruncatedNormal::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_RANDOM_OPS_H_
