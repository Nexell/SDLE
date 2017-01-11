// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_MATH_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_MATH_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Computes the absolute value of a tensor.
//
// Given a tensor `x`, this operation returns a tensor containing the absolute
// value of each element in `x`. For example, if x is an input element and y is
// an output element, this operation computes \\(y = |x|\\).
//
// Arguments:
// * scope: A Scope object
class Abs {
 public:
  Abs(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes acos of x element-wise.
//
// Arguments:
// * scope: A Scope object
class Acos {
 public:
  Acos(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns x + y element-wise.
//
// *NOTE*: `Add` supports broadcasting. `AddN` does not. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Add {
 public:
  Add(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
    ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Add all input tensors element wise.
//
// Arguments:
// * scope: A Scope object
// * inputs: Must all be the same size and shape.
class AddN {
 public:
  AddN(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList inputs);
  operator ::tensorflow::ops::Output() const { return sum; }
  operator ::tensorflow::ops::Input() const { return sum; }
  ::tensorflow::Node* node() const { return sum.node(); }

  ::tensorflow::ops::Output sum;
};

// Computes the "logical and" of elements across dimensions of a tensor.
//
// Reduces `input` along the dimensions given in `reduction_indices`. Unless
// `keep_dims` is true, the rank of the tensor is reduced by 1 for each entry in
// `reduction_indices`. If `keep_dims` is true, the reduced dimensions are
// retained with length 1.
//
// Arguments:
// * scope: A Scope object
// * input: The tensor to reduce.
// * reduction_indices: The dimensions to reduce.
class All {
 public:
  // Optional attribute setters for All :
  //
  // KeepDims(bool): Defaults to false
  //     If true, retain reduced dimensions with length 1.
  struct Attrs {
    Attrs KeepDims(bool x) {
      Attrs ret = *this;
      ret.keep_dims_ = x;
      return ret;
    }

    bool keep_dims_ = false;
  };
  All(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices);
  All(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices, const All::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs KeepDims(bool x) {
    return Attrs().KeepDims(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes the "logical or" of elements across dimensions of a tensor.
//
// Reduces `input` along the dimensions given in `reduction_indices`. Unless
// `keep_dims` is true, the rank of the tensor is reduced by 1 for each entry in
// `reduction_indices`. If `keep_dims` is true, the reduced dimensions are
// retained with length 1.
//
// Arguments:
// * scope: A Scope object
// * input: The tensor to reduce.
// * reduction_indices: The dimensions to reduce.
class Any {
 public:
  // Optional attribute setters for Any :
  //
  // KeepDims(bool): Defaults to false
  //     If true, retain reduced dimensions with length 1.
  struct Attrs {
    Attrs KeepDims(bool x) {
      Attrs ret = *this;
      ret.keep_dims_ = x;
      return ret;
    }

    bool keep_dims_ = false;
  };
  Any(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices);
  Any(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices, const Any::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs KeepDims(bool x) {
    return Attrs().KeepDims(x);
  }

  ::tensorflow::ops::Output output;
};

// Returns the index with the largest value across dimensions of a tensor.
//
// Arguments:
// * scope: A Scope object
// * dimension: int32, 0 <= dimension < rank(input).  Describes which dimension
// of the input Tensor to reduce across. For vectors, use dimension = 0.
class ArgMax {
 public:
  ArgMax(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
       ::tensorflow::ops::Input dimension);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Returns the index with the smallest value across dimensions of a tensor.
//
// Arguments:
// * scope: A Scope object
// * dimension: int32, 0 <= dimension < rank(input).  Describes which dimension
// of the input Tensor to reduce across. For vectors, use dimension = 0.
class ArgMin {
 public:
  ArgMin(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
       ::tensorflow::ops::Input dimension);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes asin of x element-wise.
//
// Arguments:
// * scope: A Scope object
class Asin {
 public:
  Asin(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes atan of x element-wise.
//
// Arguments:
// * scope: A Scope object
class Atan {
 public:
  Atan(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchFFT {
 public:
  BatchFFT(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchFFT2D {
 public:
  BatchFFT2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchFFT3D {
 public:
  BatchFFT3D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchIFFT {
 public:
  BatchIFFT(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchIFFT2D {
 public:
  BatchIFFT2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchIFFT3D {
 public:
  BatchIFFT3D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Multiplies slices of two tensors in batches.
//
// Multiplies all slices of `Tensor` `x` and `y` (each slice can be
// viewed as an element of a batch), and arranges the individual results
// in a single output tensor of the same batch size. Each of the
// individual slices can optionally be adjointed (to adjoint a matrix
// means to transpose and conjugate it) before multiplication by setting
// the `adj_x` or `adj_y` flag to `True`, which are by default `False`.
//
// The input tensors `x` and `y` are 3-D or higher with shape `[..., r_x, c_x]`
// and `[..., r_y, c_y]`.
//
// The output tensor is 3-D or higher with shape `[..., r_o, c_o]`, where:
//
//     r_o = c_x if adj_x else r_x
//     c_o = r_y if adj_y else c_y
//
// It is computed as:
//
//     output[..., :, :] = matrix(x[..., :, :]) * matrix(y[..., :, :])
//
// Arguments:
// * scope: A Scope object
// * x: 3-D or higher with shape `[..., r_x, c_x]`.
// * y: 3-D or higher with shape `[..., r_y, c_y]`.
class BatchMatMul {
 public:
  // Optional attribute setters for BatchMatMul :
  //
  // AdjX(bool): Defaults to false
  //     If `True`, adjoint the slices of `x`. Defaults to `False`.
  // AdjY(bool): Defaults to false
  //     If `True`, adjoint the slices of `y`. Defaults to `False`.
  struct Attrs {
    Attrs AdjX(bool x) {
      Attrs ret = *this;
      ret.adj_x_ = x;
      return ret;
    }

    Attrs AdjY(bool x) {
      Attrs ret = *this;
      ret.adj_y_ = x;
      return ret;
    }

    bool adj_x_ = false;
    bool adj_y_ = false;
  };
  BatchMatMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
            ::tensorflow::ops::Input y);
  BatchMatMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
            ::tensorflow::ops::Input y, const BatchMatMul::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs AdjX(bool x) {
    return Attrs().AdjX(x);
  }
  static Attrs AdjY(bool x) {
    return Attrs().AdjY(x);
  }

  ::tensorflow::ops::Output output;
};

// Compute the regularized incomplete beta integral \\(I_x(a, b)\\).
//
// The regularized incomplete beta integral is defined as:
//
// ```
// I_x(a, b) = \frac{B(x; a, b)}{B(a, b)}
// ```
// where
//
// ```
// B(x; a, b) = \int_0^x t^{a-1} (1 - t)^{b-1} dt
// ```
//
// is the incomplete beta function and \\(B(a, b)\\) is the *complete*
// beta function.
//
// Arguments:
// * scope: A Scope object
class Betainc {
 public:
  Betainc(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
        ::tensorflow::ops::Input b, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Cast x of type SrcT to y of DstT.
//
// Arguments:
// * scope: A Scope object
class Cast {
 public:
  Cast(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x, DataType
     DstT);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns element-wise smallest integer in not less than x.
//
// Arguments:
// * scope: A Scope object
class Ceil {
 public:
  Ceil(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Converts two real numbers to a complex number.
//
// Given a tensor `real` representing the real part of a complex number, and a
// tensor `imag` representing the imaginary part of a complex number, this
// operation returns complex numbers elementwise of the form \\(a + bj\\), where
// *a* represents the `real` part and *b* represents the `imag` part.
//
// The input tensors `real` and `imag` must have the same shape.
//
// For example:
//
// ```
// # tensor 'real' is [2.25, 3.25]
// # tensor `imag` is [4.75, 5.75]
// tf.complex(real, imag) ==> [[2.25 + 4.75j], [3.25 + 5.75j]]
// ```
//
// Arguments:
// * scope: A Scope object
class Complex {
 public:
  // Optional attribute setters for Complex :
  //
  // Tout(DataType): Defaults to DT_COMPLEX64
  struct Attrs {
    Attrs Tout(DataType x) {
      Attrs ret = *this;
      ret.Tout_ = x;
      return ret;
    }

    DataType Tout_ = DT_COMPLEX64;
  };
  Complex(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input real,
        ::tensorflow::ops::Input imag);
  Complex(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input real,
        ::tensorflow::ops::Input imag, const Complex::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs Tout(DataType x) {
    return Attrs().Tout(x);
  }

  ::tensorflow::ops::Output out;
};

// Computes the complex absolute value of a tensor.
//
// Given a tensor `x` of complex numbers, this operation returns a tensor of type
// `float` or `double` that is the absolute value of each element in `x`. All
// elements in `x` must be complex numbers of the form \\(a + bj\\). The absolute
// value is computed as \\( \sqrt{a^2 + b^2}\\).
//
// For example:
//
// ```
// # tensor 'x' is [[-2.25 + 4.75j], [-3.25 + 5.75j]]
// tf.complex_abs(x) ==> [5.25594902, 6.60492229]
// ```
//
// Arguments:
// * scope: A Scope object
class ComplexAbs {
 public:
  // Optional attribute setters for ComplexAbs :
  //
  // Tout(DataType): Defaults to DT_FLOAT
  struct Attrs {
    Attrs Tout(DataType x) {
      Attrs ret = *this;
      ret.Tout_ = x;
      return ret;
    }

    DataType Tout_ = DT_FLOAT;
  };
  ComplexAbs(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  ComplexAbs(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x, const
           ComplexAbs::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  static Attrs Tout(DataType x) {
    return Attrs().Tout(x);
  }

  ::tensorflow::ops::Output y;
};

// Returns the complex conjugate of a complex number.
//
// Given a tensor `input` of complex numbers, this operation returns a tensor of
// complex numbers that are the complex conjugate of each element in `input`. The
// complex numbers in `input` must be of the form \\(a + bj\\), where *a* is the
// real part and *b* is the imaginary part.
//
// The complex conjugate returned by this operation is of the form \\(a - bj\\).
//
// For example:
//
// ```
// # tensor 'input' is [-2.25 + 4.75j, 3.25 + 5.75j]
// tf.conj(input) ==> [-2.25 - 4.75j, 3.25 - 5.75j]
// ```
//
// Arguments:
// * scope: A Scope object
class Conj {
 public:
  Conj(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes cos of x element-wise.
//
// Arguments:
// * scope: A Scope object
class Cos {
 public:
  Cos(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Compute the pairwise cross product.
//
// `a` and `b` must be the same shape; they can either be simple 3-element vectors,
// or any shape where the innermost dimension is 3. In the latter case, each pair
// of corresponding 3-element vectors is cross-multiplied independently.
//
// Arguments:
// * scope: A Scope object
// * a: A tensor containing 3-element vectors.
// * b: Another tensor, of same type and shape as `a`.
class Cross {
 public:
  Cross(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
      ::tensorflow::ops::Input b);
  operator ::tensorflow::ops::Output() const { return product; }
  operator ::tensorflow::ops::Input() const { return product; }
  ::tensorflow::Node* node() const { return product.node(); }

  ::tensorflow::ops::Output product;
};

// Compute the cumulative product of the tensor `x` along `axis`.
//
// By default, this op performs an inclusive cumprod, which means that the first
// element of the input is identical to the first element of the output:
// ```prettyprint
// tf.cumprod([a, b, c]) ==> [a, a * b, a * b * c]
// ```
//
// By setting the `exclusive` kwarg to `True`, an exclusive cumprod is
// performed instead:
// ```prettyprint
// tf.cumprod([a, b, c], exclusive=True) ==> [0, a, a * b]
// ```
//
// By setting the `reverse` kwarg to `True`, the cumprod is performed in the
// opposite direction:
// ```prettyprint
// tf.cumprod([a, b, c], reverse=True) ==> [a * b * c, b * c, c]
// ```
// This is more efficient than using separate `tf.reverse` ops.
//
// The `reverse` and `exclusive` kwargs can also be combined:
// ```prettyprint
// tf.cumprod([a, b, c], exclusive=True, reverse=True) ==> [b * c, c, 0]
// ```
//
// Arguments:
// * scope: A Scope object
class Cumprod {
 public:
  // Optional attribute setters for Cumprod :
  //
  // Exclusive(bool): Defaults to false
  // Reverse(bool): Defaults to false
  struct Attrs {
    Attrs Exclusive(bool x) {
      Attrs ret = *this;
      ret.exclusive_ = x;
      return ret;
    }

    Attrs Reverse(bool x) {
      Attrs ret = *this;
      ret.reverse_ = x;
      return ret;
    }

    bool exclusive_ = false;
    bool reverse_ = false;
  };
  Cumprod(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
        ::tensorflow::ops::Input axis);
  Cumprod(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
        ::tensorflow::ops::Input axis, const Cumprod::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs Exclusive(bool x) {
    return Attrs().Exclusive(x);
  }
  static Attrs Reverse(bool x) {
    return Attrs().Reverse(x);
  }

  ::tensorflow::ops::Output out;
};

// Compute the cumulative sum of the tensor `x` along `axis`.
//
// By default, this op performs an inclusive cumsum, which means that the first
// element of the input is identical to the first element of the output:
// ```prettyprint
// tf.cumsum([a, b, c]) ==> [a, a + b, a + b + c]
// ```
//
// By setting the `exclusive` kwarg to `True`, an exclusive cumsum is
// performed instead:
// ```prettyprint
// tf.cumsum([a, b, c], exclusive=True) ==> [0, a, a + b]
// ```
//
// By setting the `reverse` kwarg to `True`, the cumsum is performed in the
// opposite direction:
// ```prettyprint
// tf.cumsum([a, b, c], reverse=True) ==> [a + b + c, b + c, c]
// ```
// This is more efficient than using separate `tf.reverse` ops.
//
// The `reverse` and `exclusive` kwargs can also be combined:
// ```prettyprint
// tf.cumsum([a, b, c], exclusive=True, reverse=True) ==> [b + c, c, 0]
// ```
//
// Arguments:
// * scope: A Scope object
class Cumsum {
 public:
  // Optional attribute setters for Cumsum :
  //
  // Exclusive(bool): Defaults to false
  // Reverse(bool): Defaults to false
  struct Attrs {
    Attrs Exclusive(bool x) {
      Attrs ret = *this;
      ret.exclusive_ = x;
      return ret;
    }

    Attrs Reverse(bool x) {
      Attrs ret = *this;
      ret.reverse_ = x;
      return ret;
    }

    bool exclusive_ = false;
    bool reverse_ = false;
  };
  Cumsum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
       ::tensorflow::ops::Input axis);
  Cumsum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
       ::tensorflow::ops::Input axis, const Cumsum::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs Exclusive(bool x) {
    return Attrs().Exclusive(x);
  }
  static Attrs Reverse(bool x) {
    return Attrs().Reverse(x);
  }

  ::tensorflow::ops::Output out;
};

// Computes Psi, the derivative of Lgamma (the log of the absolute value of
//
// `Gamma(x)`), element-wise.
//
// Arguments:
// * scope: A Scope object
class Digamma {
 public:
  Digamma(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns x / y element-wise.
//
// *NOTE*: `Div` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Div {
 public:
  Div(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
    ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns the truth value of (x == y) element-wise.
//
// *NOTE*: `Equal` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Equal {
 public:
  Equal(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
      ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the Gauss error function of `x` element-wise.
//
// Arguments:
// * scope: A Scope object
class Erf {
 public:
  Erf(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes the complementary error function of `x` element-wise.
//
// Arguments:
// * scope: A Scope object
class Erfc {
 public:
  Erfc(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes exponential of x element-wise.  \\(y = e^x\\).
//
// Arguments:
// * scope: A Scope object
class Exp {
 public:
  Exp(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Compute the 1-dimensional discrete Fourier Transform over the inner-most
//
// dimension of `input`.
//
// Arguments:
// * scope: A Scope object
// * input: A complex64 tensor.
class FFT {
 public:
  FFT(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Compute the 2-dimensional discrete Fourier Transform over the inner-most
//
// 2 dimensions of `input`.
//
// Arguments:
// * scope: A Scope object
// * input: A complex64 tensor.
class FFT2D {
 public:
  FFT2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Compute the 3-dimensional discrete Fourier Transform over the inner-most 3
//
// dimensions of `input`.
//
// Arguments:
// * scope: A Scope object
// * input: A complex64 tensor.
class FFT3D {
 public:
  FFT3D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Returns element-wise largest integer not greater than x.
//
// Arguments:
// * scope: A Scope object
class Floor {
 public:
  Floor(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns x // y element-wise.
//
// *NOTE*: `FloorDiv` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class FloorDiv {
 public:
  FloorDiv(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
         ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns element-wise remainder of division. When `x < 0` xor `y < 0` is
//
// true, this follows Python semantics in that the result here is consistent
// with a flooring divide. E.g. `floor(x / y) * y + mod(x, y) = x`.
//
// *NOTE*: `FloorMod` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class FloorMod {
 public:
  FloorMod(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
         ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns the truth value of (x > y) element-wise.
//
// *NOTE*: `Greater` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Greater {
 public:
  Greater(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
        ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns the truth value of (x >= y) element-wise.
//
// *NOTE*: `GreaterEqual` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class GreaterEqual {
 public:
  GreaterEqual(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
             ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Compute the inverse 1-dimensional discrete Fourier Transform over the inner-most
//
// dimension of `input`.
//
// Arguments:
// * scope: A Scope object
// * input: A complex64 tensor.
class IFFT {
 public:
  IFFT(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Compute the inverse 2-dimensional discrete Fourier Transform over the inner-most
//
// 2 dimensions of `input`.
//
// Arguments:
// * scope: A Scope object
// * input: A complex64 tensor.
class IFFT2D {
 public:
  IFFT2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Compute the inverse 3-dimensional discrete Fourier Transform over the inner-most
//
// 3 dimensions of `input`.
//
// Arguments:
// * scope: A Scope object
// * input: A complex64 tensor.
class IFFT3D {
 public:
  IFFT3D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Compute the lower regularized incomplete Gamma function `Q(a, x)`.
//
// The lower regularized incomplete Gamma function is defined as:
//
// ```
// P(a, x) = gamma(a, x) / Gamma(a) = 1 - Q(a, x)
// ```
// where
// ```
// gamma(a, x) = int_{0}^{x} t^{a-1} exp(-t) dt
// ```
// is the lower incomplete Gamma function.
//
// Note, above `Q(a, x)` (`Igammac`) is the upper regularized complete
// Gamma function.
//
// Arguments:
// * scope: A Scope object
class Igamma {
 public:
  Igamma(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
       ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Compute the upper regularized incomplete Gamma function `Q(a, x)`.
//
// The upper regularized incomplete Gamma function is defined as:
//
// ```
// Q(a, x) = Gamma(a, x) / Gamma(a) = 1 - P(a, x)
// ```
// where
// ```
// Gamma(a, x) = int_{x}^{\infty} t^{a-1} exp(-t) dt
// ```
// is the upper incomplete Gama function.
//
// Note, above `P(a, x)` (`Igamma`) is the lower regularized complete
// Gamma function.
//
// Arguments:
// * scope: A Scope object
class Igammac {
 public:
  Igammac(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
        ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns the imaginary part of a complex number.
//
// Given a tensor `input` of complex numbers, this operation returns a tensor of
// type `float` that is the imaginary part of each element in `input`. All
// elements in `input` must be complex numbers of the form \\(a + bj\\), where *a*
// is the real part and *b* is the imaginary part returned by this operation.
//
// For example:
//
// ```
// # tensor 'input' is [-2.25 + 4.75j, 3.25 + 5.75j]
// tf.imag(input) ==> [4.75, 5.75]
// ```
//
// Arguments:
// * scope: A Scope object
class Imag {
 public:
  // Optional attribute setters for Imag :
  //
  // Tout(DataType): Defaults to DT_FLOAT
  struct Attrs {
    Attrs Tout(DataType x) {
      Attrs ret = *this;
      ret.Tout_ = x;
      return ret;
    }

    DataType Tout_ = DT_FLOAT;
  };
  Imag(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  Imag(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input, const
     Imag::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Tout(DataType x) {
    return Attrs().Tout(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes the reciprocal of x element-wise.
//
// I.e., \\(y = 1 / x\\).
//
// Arguments:
// * scope: A Scope object
class Inv {
 public:
  Inv(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes the gradient for the inverse of `x` wrt its input.
//
// Specifically, `grad = -dy * y*y`, where `y = 1/x`, and `dy`
// is the corresponding input gradient.
//
// Arguments:
// * scope: A Scope object
class InvGrad {
 public:
  InvGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
        ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns which elements of x are finite.
//
// Arguments:
// * scope: A Scope object
class IsFinite {
 public:
  IsFinite(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns which elements of x are Inf.
//
// Arguments:
// * scope: A Scope object
class IsInf {
 public:
  IsInf(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns which elements of x are NaN.
//
// Arguments:
// * scope: A Scope object
class IsNan {
 public:
  IsNan(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns the truth value of (x < y) element-wise.
//
// *NOTE*: `Less` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Less {
 public:
  Less(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
     ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns the truth value of (x <= y) element-wise.
//
// *NOTE*: `LessEqual` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class LessEqual {
 public:
  LessEqual(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
          ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the log of the absolute value of `Gamma(x)` element-wise.
//
// Arguments:
// * scope: A Scope object
class Lgamma {
 public:
  Lgamma(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Generates values in an interval.
//
// A sequence of `num` evenly-spaced values are generated beginning at `start`.
// If `num > 1`, the values in the sequence increase by `stop - start / num - 1`,
// so that the last one is exactly `stop`.
//
// For example:
//
// ```
// tf.linspace(10.0, 12.0, 3, name="linspace") => [ 10.0  11.0  12.0]
// ```
//
// Arguments:
// * scope: A Scope object
// * start: First entry in the range.
// * stop: Last entry in the range.
// * num: Number of values to generate.
class LinSpace {
 public:
  LinSpace(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input start,
         ::tensorflow::ops::Input stop, ::tensorflow::ops::Input num);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes natural logarithm of x element-wise.
//
// I.e., \\(y = \log_e x\\).
//
// Arguments:
// * scope: A Scope object
class Log {
 public:
  Log(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns the truth value of x AND y element-wise.
//
// *NOTE*: `LogicalAnd` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class LogicalAnd {
 public:
  LogicalAnd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
           ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns the truth value of NOT x element-wise.
//
// Arguments:
// * scope: A Scope object
class LogicalNot {
 public:
  LogicalNot(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns the truth value of x OR y element-wise.
//
// *NOTE*: `LogicalOr` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class LogicalOr {
 public:
  LogicalOr(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
          ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Multiply the matrix "a" by the matrix "b".
//
// The inputs must be two-dimensional matrices and the inner dimension of
// "a" (after being transposed if transpose_a is true) must match the
// outer dimension of "b" (after being transposed if transposed_b is
// true).
//
// *Note*: The default kernel implementation for MatMul on GPUs uses
// cublas.
//
// Arguments:
// * scope: A Scope object
class MatMul {
 public:
  // Optional attribute setters for MatMul :
  //
  // TransposeA(bool): Defaults to false
  //     If true, "a" is transposed before multiplication.
  // TransposeB(bool): Defaults to false
  //     If true, "b" is transposed before multiplication.
  struct Attrs {
    Attrs TransposeA(bool x) {
      Attrs ret = *this;
      ret.transpose_a_ = x;
      return ret;
    }

    Attrs TransposeB(bool x) {
      Attrs ret = *this;
      ret.transpose_b_ = x;
      return ret;
    }

    bool transpose_a_ = false;
    bool transpose_b_ = false;
  };
  MatMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
       ::tensorflow::ops::Input b);
  MatMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
       ::tensorflow::ops::Input b, const MatMul::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return product; }
  operator ::tensorflow::ops::Input() const { return product; }
  ::tensorflow::Node* node() const { return product.node(); }

  static Attrs TransposeA(bool x) {
    return Attrs().TransposeA(x);
  }
  static Attrs TransposeB(bool x) {
    return Attrs().TransposeB(x);
  }

  ::tensorflow::ops::Output product;
};

// Computes the maximum of elements across dimensions of a tensor.
//
// Reduces `input` along the dimensions given in `reduction_indices`. Unless
// `keep_dims` is true, the rank of the tensor is reduced by 1 for each entry in
// `reduction_indices`. If `keep_dims` is true, the reduced dimensions are
// retained with length 1.
//
// Arguments:
// * scope: A Scope object
// * input: The tensor to reduce.
// * reduction_indices: The dimensions to reduce.
class Max {
 public:
  // Optional attribute setters for Max :
  //
  // KeepDims(bool): Defaults to false
  //     If true, retain reduced dimensions with length 1.
  struct Attrs {
    Attrs KeepDims(bool x) {
      Attrs ret = *this;
      ret.keep_dims_ = x;
      return ret;
    }

    bool keep_dims_ = false;
  };
  Max(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices);
  Max(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices, const Max::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs KeepDims(bool x) {
    return Attrs().KeepDims(x);
  }

  ::tensorflow::ops::Output output;
};

// Returns the max of x and y (i.e. x > y ? x : y) element-wise.
//
// *NOTE*: `Maximum` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Maximum {
 public:
  Maximum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
        ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the mean of elements across dimensions of a tensor.
//
// Reduces `input` along the dimensions given in `reduction_indices`. Unless
// `keep_dims` is true, the rank of the tensor is reduced by 1 for each entry in
// `reduction_indices`. If `keep_dims` is true, the reduced dimensions are
// retained with length 1.
//
// Arguments:
// * scope: A Scope object
// * input: The tensor to reduce.
// * reduction_indices: The dimensions to reduce.
class Mean {
 public:
  // Optional attribute setters for Mean :
  //
  // KeepDims(bool): Defaults to false
  //     If true, retain reduced dimensions with length 1.
  struct Attrs {
    Attrs KeepDims(bool x) {
      Attrs ret = *this;
      ret.keep_dims_ = x;
      return ret;
    }

    bool keep_dims_ = false;
  };
  Mean(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
     ::tensorflow::ops::Input reduction_indices);
  Mean(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
     ::tensorflow::ops::Input reduction_indices, const Mean::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs KeepDims(bool x) {
    return Attrs().KeepDims(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes the minimum of elements across dimensions of a tensor.
//
// Reduces `input` along the dimensions given in `reduction_indices`. Unless
// `keep_dims` is true, the rank of the tensor is reduced by 1 for each entry in
// `reduction_indices`. If `keep_dims` is true, the reduced dimensions are
// retained with length 1.
//
// Arguments:
// * scope: A Scope object
// * input: The tensor to reduce.
// * reduction_indices: The dimensions to reduce.
class Min {
 public:
  // Optional attribute setters for Min :
  //
  // KeepDims(bool): Defaults to false
  //     If true, retain reduced dimensions with length 1.
  struct Attrs {
    Attrs KeepDims(bool x) {
      Attrs ret = *this;
      ret.keep_dims_ = x;
      return ret;
    }

    bool keep_dims_ = false;
  };
  Min(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices);
  Min(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices, const Min::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs KeepDims(bool x) {
    return Attrs().KeepDims(x);
  }

  ::tensorflow::ops::Output output;
};

// Returns the min of x and y (i.e. x < y ? x : y) element-wise.
//
// *NOTE*: `Minimum` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Minimum {
 public:
  Minimum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
        ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns element-wise remainder of division.
//
// *NOTE*: `Mod` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Mod {
 public:
  Mod(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
    ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns x * y element-wise.
//
// *NOTE*: `Mul` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Mul {
 public:
  Mul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
    ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes numerical negative value element-wise.
//
// I.e., \\(y = -x\\).
//
// Arguments:
// * scope: A Scope object
class Neg {
 public:
  Neg(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns the truth value of (x != y) element-wise.
//
// *NOTE*: `NotEqual` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class NotEqual {
 public:
  NotEqual(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
         ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Compute the polygamma function \\(\psi^{(n)}(x)\\).
//
// The polygamma function is defined as:
//
// ```
// \psi^{(n)}(x) = \frac{d^n}{dx^n} \psi(x)
// ```
// where \\(\psi(x)\\) is the digamma function.
//
// Arguments:
// * scope: A Scope object
class Polygamma {
 public:
  Polygamma(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
          ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the power of one value to another.
//
// Given a tensor `x` and a tensor `y`, this operation computes \\(x^y\\) for
// corresponding elements in `x` and `y`. For example:
//
// ```
// # tensor 'x' is [[2, 2]], [3, 3]]
// # tensor 'y' is [[8, 16], [2, 3]]
// tf.pow(x, y) ==> [[256, 65536], [9, 27]]
// ```
//
// Arguments:
// * scope: A Scope object
class Pow {
 public:
  Pow(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
    ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the product of elements across dimensions of a tensor.
//
// Reduces `input` along the dimensions given in `reduction_indices`. Unless
// `keep_dims` is true, the rank of the tensor is reduced by 1 for each entry in
// `reduction_indices`. If `keep_dims` is true, the reduced dimensions are
// retained with length 1.
//
// Arguments:
// * scope: A Scope object
// * input: The tensor to reduce.
// * reduction_indices: The dimensions to reduce.
class Prod {
 public:
  // Optional attribute setters for Prod :
  //
  // KeepDims(bool): Defaults to false
  //     If true, retain reduced dimensions with length 1.
  struct Attrs {
    Attrs KeepDims(bool x) {
      Attrs ret = *this;
      ret.keep_dims_ = x;
      return ret;
    }

    bool keep_dims_ = false;
  };
  Prod(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
     ::tensorflow::ops::Input reduction_indices);
  Prod(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
     ::tensorflow::ops::Input reduction_indices, const Prod::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs KeepDims(bool x) {
    return Attrs().KeepDims(x);
  }

  ::tensorflow::ops::Output output;
};

// Convert the quantized 'input' tensor into a lower-precision 'output', using the
//
// actual distribution of the values to maximize the usage of the lower bit depth
// and adjusting the output min and max ranges accordingly.
//
// [input_min, input_max] are scalar floats that specify the range for the float
// interpretation of the 'input' data. For example, if input_min is -1.0f and
// input_max is 1.0f, and we are dealing with quint16 quantized data, then a 0
// value in the 16-bit data should be interpreted as -1.0f, and a 65535 means 1.0f.
//
// This operator tries to squeeze as much precision as possible into an output with
// a lower bit depth by calculating the actual min and max values found in the
// data. For example, maybe that quint16 input has no values lower than 16,384 and
// none higher than 49,152. That means only half the range is actually needed, all
// the float interpretations are between -0.5f and 0.5f, so if we want to compress
// the data into a quint8 output, we can use that range rather than the theoretical
// -1.0f to 1.0f that is suggested by the input min and max.
//
// In practice, this is most useful for taking output from operations like
// QuantizedMatMul that can produce higher bit-depth outputs than their inputs and
// may have large potential output ranges, but in practice have a distribution of
// input values that only uses a small fraction of the possible range. By feeding
// that output into this operator, we can reduce it from 32 bits down to 8 with
// minimal loss of accuracy.
//
// Arguments:
// * scope: A Scope object
// * input_min: The float value that the minimum quantized input value represents.
// * input_max: The float value that the maximum quantized input value represents.
// * out_type:
//     The type of the output. Should be a lower bit depth than Tinput.
class QuantizeDownAndShrinkRange {
 public:
  QuantizeDownAndShrinkRange(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input input,
                           ::tensorflow::ops::Input input_min,
                           ::tensorflow::ops::Input input_max, DataType
                           out_type);

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output output_min;
  ::tensorflow::ops::Output output_max;
};

// Perform a quantized matrix multiplication of  `a` by the matrix `b`.
//
// The inputs must be two-dimensional matrices and the inner dimension of
// `a` (after being transposed if `transpose_a` is non-zero) must match the
// outer dimension of `b` (after being transposed if `transposed_b` is
// non-zero).
//
// Arguments:
// * scope: A Scope object
// * a: Must be a two-dimensional tensor.
// * b: Must be a two-dimensional tensor.
// * min_a: The float value that the lowest quantized `a` value represents.
// * max_a: The float value that the highest quantized `a` value represents.
// * min_b: The float value that the lowest quantized `b` value represents.
// * max_b: The float value that the highest quantized `b` value represents.
class QuantizedMatMul {
 public:
  // Optional attribute setters for QuantizedMatMul :
  //
  // Toutput(DataType): Defaults to DT_QINT32
  // TransposeA(bool): Defaults to false
  //     If true, `a` is transposed before multiplication.
  // TransposeB(bool): Defaults to false
  //     If true, `b` is transposed before multiplication.
  struct Attrs {
    Attrs Toutput(DataType x) {
      Attrs ret = *this;
      ret.Toutput_ = x;
      return ret;
    }

    Attrs TransposeA(bool x) {
      Attrs ret = *this;
      ret.transpose_a_ = x;
      return ret;
    }

    Attrs TransposeB(bool x) {
      Attrs ret = *this;
      ret.transpose_b_ = x;
      return ret;
    }

    DataType Toutput_ = DT_QINT32;
    bool transpose_a_ = false;
    bool transpose_b_ = false;
  };
  QuantizedMatMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
                ::tensorflow::ops::Input b, ::tensorflow::ops::Input min_a,
                ::tensorflow::ops::Input max_a, ::tensorflow::ops::Input min_b,
                ::tensorflow::ops::Input max_b);
  QuantizedMatMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
                ::tensorflow::ops::Input b, ::tensorflow::ops::Input min_a,
                ::tensorflow::ops::Input max_a, ::tensorflow::ops::Input min_b,
                ::tensorflow::ops::Input max_b, const QuantizedMatMul::Attrs&
                attrs);

  static Attrs Toutput(DataType x) {
    return Attrs().Toutput(x);
  }
  static Attrs TransposeA(bool x) {
    return Attrs().TransposeA(x);
  }
  static Attrs TransposeB(bool x) {
    return Attrs().TransposeB(x);
  }

  ::tensorflow::ops::Output out;
  ::tensorflow::ops::Output min_out;
  ::tensorflow::ops::Output max_out;
};

// Creates a sequence of numbers.
//
// This operation creates a sequence of numbers that begins at `start` and
// extends by increments of `delta` up to but not including `limit`.
//
// For example:
//
// ```
// # 'start' is 3
// # 'limit' is 18
// # 'delta' is 3
// tf.range(start, limit, delta) ==> [3, 6, 9, 12, 15]
// ```
//
// Arguments:
// * scope: A Scope object
// * start: 0-D (scalar). First entry in the sequence.
// * limit: 0-D (scalar). Upper limit of sequence, exclusive.
// * delta: 0-D (scalar). Optional. Default is 1. Number that increments `start`.
class Range {
 public:
  Range(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input start,
      ::tensorflow::ops::Input limit, ::tensorflow::ops::Input delta);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Returns the real part of a complex number.
//
// Given a tensor `input` of complex numbers, this operation returns a tensor of
// type `float` that is the real part of each element in `input`. All elements in
// `input` must be complex numbers of the form \\(a + bj\\), where *a* is the real
//  part returned by this operation and *b* is the imaginary part.
//
// For example:
//
// ```
// # tensor 'input' is [-2.25 + 4.75j, 3.25 + 5.75j]
// tf.real(input) ==> [-2.25, 3.25]
// ```
//
// Arguments:
// * scope: A Scope object
class Real {
 public:
  // Optional attribute setters for Real :
  //
  // Tout(DataType): Defaults to DT_FLOAT
  struct Attrs {
    Attrs Tout(DataType x) {
      Attrs ret = *this;
      ret.Tout_ = x;
      return ret;
    }

    DataType Tout_ = DT_FLOAT;
  };
  Real(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  Real(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input, const
     Real::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Tout(DataType x) {
    return Attrs().Tout(x);
  }

  ::tensorflow::ops::Output output;
};

// Returns x / y element-wise for real types.
//
// If `x` and `y` are reals, this will return the floating-point division.
//
// *NOTE*: `Div` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class RealDiv {
 public:
  RealDiv(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
        ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the reciprocal of x element-wise.
//
// I.e., \\(y = 1 / x\\).
//
// Arguments:
// * scope: A Scope object
class Reciprocal {
 public:
  Reciprocal(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes the gradient for the inverse of `x` wrt its input.
//
// Specifically, `grad = -dy * y*y`, where `y = 1/x`, and `dy`
// is the corresponding input gradient.
//
// Arguments:
// * scope: A Scope object
class ReciprocalGrad {
 public:
  ReciprocalGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
               ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Convert the quantized 'input' tensor into a lower-precision 'output', using the
//
// output range specified with 'requested_output_min' and 'requested_output_max'.
//
// [input_min, input_max] are scalar floats that specify the range for the float
// interpretation of the 'input' data. For example, if input_min is -1.0f and
// input_max is 1.0f, and we are dealing with quint16 quantized data, then a 0
// value in the 16-bit data should be interpreted as -1.0f, and a 65535 means 1.0f.
//
// Arguments:
// * scope: A Scope object
// * input_min: The float value that the minimum quantized input value represents.
// * input_max: The float value that the maximum quantized input value represents.
// * requested_output_min: The float value that the minimum quantized output value represents.
// * requested_output_max: The float value that the maximum quantized output value represents.
// * out_type:
//     The type of the output. Should be a lower bit depth than Tinput.
class Requantize {
 public:
  Requantize(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
           ::tensorflow::ops::Input input_min, ::tensorflow::ops::Input
           input_max, ::tensorflow::ops::Input requested_output_min,
           ::tensorflow::ops::Input requested_output_max, DataType out_type);

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output output_min;
  ::tensorflow::ops::Output output_max;
};

// Rounds the values of a tensor to the nearest integer, element-wise.
//
// Rounds half to even.  Also known as bankers rounding. If you want to round
// according to the current system rounding mode use std::cint.
//
// Arguments:
// * scope: A Scope object
class Round {
 public:
  Round(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes reciprocal of square root of x element-wise.
//
// I.e., \\(y = 1 / \sqrt{x}\\).
//
// Arguments:
// * scope: A Scope object
class Rsqrt {
 public:
  Rsqrt(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes the gradient for the rsqrt of `x` wrt its input.
//
// Specifically, `grad = dy * -0.5 * y^3`, where `y = rsqrt(x)`, and `dy`
// is the corresponding input gradient.
//
// Arguments:
// * scope: A Scope object
class RsqrtGrad {
 public:
  RsqrtGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
          ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the maximum along segments of a tensor.
//
// Read [the section on Segmentation](../../api_docs/python/math_ops.md#segmentation)
// for an explanation of segments.
//
// Computes a tensor such that
// \\(output_i = \max_j(data_j)\\) where `max` is over `j` such
// that `segment_ids[j] == i`.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/SegmentMax.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * segment_ids: A 1-D tensor whose rank is equal to the rank of `data`'s
// first dimension.  Values should be sorted and can be repeated.
class SegmentMax {
 public:
  SegmentMax(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
           ::tensorflow::ops::Input segment_ids);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the mean along segments of a tensor.
//
// Read [the section on
// Segmentation](../../api_docs/python/math_ops.md#segmentation) for an explanation
// of segments.
//
// Computes a tensor such that
// \\(output_i = \frac{\sum_j data_j}{N}\\) where `mean` is
// over `j` such that `segment_ids[j] == i` and `N` is the total number of
// values summed.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/SegmentMean.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * segment_ids: A 1-D tensor whose rank is equal to the rank of `data`'s
// first dimension.  Values should be sorted and can be repeated.
class SegmentMean {
 public:
  SegmentMean(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
            ::tensorflow::ops::Input segment_ids);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the minimum along segments of a tensor.
//
// Read [the section on
// Segmentation](../../api_docs/python/math_ops.md#segmentation) for an explanation
// of segments.
//
// Computes a tensor such that
// \\(output_i = \min_j(data_j)\\) where `min` is over `j` such
// that `segment_ids[j] == i`.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/SegmentMin.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * segment_ids: A 1-D tensor whose rank is equal to the rank of `data`'s
// first dimension.  Values should be sorted and can be repeated.
class SegmentMin {
 public:
  SegmentMin(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
           ::tensorflow::ops::Input segment_ids);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the product along segments of a tensor.
//
// Read [the section on
// Segmentation](../../api_docs/python/math_ops.md#segmentation) for an explanation
// of segments.
//
// Computes a tensor such that
// \\(output_i = \prod_j data_j\\) where the product is over `j` such
// that `segment_ids[j] == i`.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/SegmentProd.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * segment_ids: A 1-D tensor whose rank is equal to the rank of `data`'s
// first dimension.  Values should be sorted and can be repeated.
class SegmentProd {
 public:
  SegmentProd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
            ::tensorflow::ops::Input segment_ids);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the sum along segments of a tensor.
//
// Read [the section on Segmentation](../../api_docs/python/math_ops.md#segmentation)
// for an explanation of segments.
//
// Computes a tensor such that
// \\(output_i = \sum_j data_j\\) where sum is over `j` such
// that `segment_ids[j] == i`.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/SegmentSum.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * segment_ids: A 1-D tensor whose rank is equal to the rank of `data`'s
// first dimension.  Values should be sorted and can be repeated.
class SegmentSum {
 public:
  SegmentSum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
           ::tensorflow::ops::Input segment_ids);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Selects elements from `t` or `e`, depending on `condition`.
//
// The `t`, and `e` tensors must all have the same shape, and the
// output will also have that shape.
//
// The `condition` tensor must be a scalar if `t` and `e` are scalars.
// If `t` and `e` are vectors or higher rank, then `condition` must be either a
// scalar, a vector with size matching the first dimension of `t`, or must have
// the same shape as `t`.
//
// The `condition` tensor acts as a mask that chooses, based on the value at each
// element, whether the corresponding element / row in the output should be
// taken from `t` (if true) or `e` (if false).
//
// If `condition` is a vector and `t` and `e` are higher rank matrices, then
// it chooses which row (outer dimension) to copy from `t` and `e`.
// If `condition` has the same shape as `t` and `e`, then it chooses which
// element to copy from `t` and `e`.
//
// For example:
//
// ```prettyprint
// # 'condition' tensor is [[True,  False]
// #                        [False, True]]
// # 't' is [[1, 2],
// #         [3, 4]]
// # 'e' is [[5, 6],
// #         [7, 8]]
// select(condition, t, e) ==> [[1, 6],
//                              [7, 4]]
//
//
// # 'condition' tensor is [True, False]
// # 't' is [[1, 2],
// #         [3, 4]]
// # 'e' is [[5, 6],
// #         [7, 8]]
// select(condition, t, e) ==> [[1, 2],
//                              [7, 8]]
//
// ```
//
// Arguments:
// * scope: A Scope object
// * t: = A `Tensor` which may have the same shape as `condition`.
// If `condition` is rank 1, `t` may have higher rank,
// but its first dimension must match the size of `condition`.
// * e: = A `Tensor` with the same type and shape as `t`.
class Select {
 public:
  Select(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input condition,
       ::tensorflow::ops::Input t, ::tensorflow::ops::Input e);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes sigmoid of `x` element-wise.
//
// Specifically, `y = 1 / (1 + exp(-x))`.
//
// Arguments:
// * scope: A Scope object
class Sigmoid {
 public:
  Sigmoid(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes the gradient of the sigmoid of `x` wrt its input.
//
// Specifically, `grad = dy * y * (1 - y)`, where `y = sigmoid(x)`, and
// `dy` is the corresponding input gradient.
//
// Arguments:
// * scope: A Scope object
class SigmoidGrad {
 public:
  SigmoidGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
            ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns an element-wise indication of the sign of a number.
//
// `y = sign(x) = -1` if `x < 0`; 0 if `x == 0`; 1 if `x > 0`.
//
// For complex numbers, `y = sign(x) = x / |x|` if `x != 0`, otherwise `y = 0`.
//
// Arguments:
// * scope: A Scope object
class Sign {
 public:
  Sign(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes sin of x element-wise.
//
// Arguments:
// * scope: A Scope object
class Sin {
 public:
  Sin(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Multiply matrix "a" by matrix "b".
//
// The inputs must be two-dimensional matrices and the inner dimension of "a" must
// match the outer dimension of "b". This op is optimized for the case where at
// least one of "a" or "b" is sparse. The breakeven for using this versus a dense
// matrix multiply on one platform was 30% zero values in the sparse matrix.
//
// Arguments:
// * scope: A Scope object
class SparseMatMul {
 public:
  // Optional attribute setters for SparseMatMul :
  //
  // TransposeA(bool): Defaults to false
  // TransposeB(bool): Defaults to false
  // AIsSparse(bool): Defaults to false
  // BIsSparse(bool): Defaults to false
  struct Attrs {
    Attrs TransposeA(bool x) {
      Attrs ret = *this;
      ret.transpose_a_ = x;
      return ret;
    }

    Attrs TransposeB(bool x) {
      Attrs ret = *this;
      ret.transpose_b_ = x;
      return ret;
    }

    Attrs AIsSparse(bool x) {
      Attrs ret = *this;
      ret.a_is_sparse_ = x;
      return ret;
    }

    Attrs BIsSparse(bool x) {
      Attrs ret = *this;
      ret.b_is_sparse_ = x;
      return ret;
    }

    bool transpose_a_ = false;
    bool transpose_b_ = false;
    bool a_is_sparse_ = false;
    bool b_is_sparse_ = false;
  };
  SparseMatMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
             ::tensorflow::ops::Input b);
  SparseMatMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input a,
             ::tensorflow::ops::Input b, const SparseMatMul::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return product; }
  operator ::tensorflow::ops::Input() const { return product; }
  ::tensorflow::Node* node() const { return product.node(); }

  static Attrs TransposeA(bool x) {
    return Attrs().TransposeA(x);
  }
  static Attrs TransposeB(bool x) {
    return Attrs().TransposeB(x);
  }
  static Attrs AIsSparse(bool x) {
    return Attrs().AIsSparse(x);
  }
  static Attrs BIsSparse(bool x) {
    return Attrs().BIsSparse(x);
  }

  ::tensorflow::ops::Output product;
};

// Computes the mean along sparse segments of a tensor.
//
// Read [the section on
// Segmentation](../../api_docs/python/math_ops.md#segmentation) for an explanation
// of segments.
//
// Like `SegmentMean`, but `segment_ids` can have rank less than `data`'s first
// dimension, selecting a subset of dimension 0, specified by `indices`.
//
// Arguments:
// * scope: A Scope object
// * indices: A 1-D tensor. Has same rank as `segment_ids`.
// * segment_ids: A 1-D tensor. Values should be sorted and can be repeated.
class SparseSegmentMean {
 public:
  SparseSegmentMean(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  data, ::tensorflow::ops::Input indices,
                  ::tensorflow::ops::Input segment_ids);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes gradients for SparseSegmentMean.
//
// Returns tensor "output" with same shape as grad, except for dimension 0 whose
// value is output_dim0.
//
// Arguments:
// * scope: A Scope object
// * grad: gradient propagated to the SparseSegmentMean op.
// * indices: indices passed to the corresponding SparseSegmentMean op.
// * segment_ids: segment_ids passed to the corresponding SparseSegmentMean op.
// * output_dim0: dimension 0 of "data" passed to SparseSegmentMean op.
class SparseSegmentMeanGrad {
 public:
  SparseSegmentMeanGrad(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input grad, ::tensorflow::ops::Input
                      indices, ::tensorflow::ops::Input segment_ids,
                      ::tensorflow::ops::Input output_dim0);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the sum along sparse segments of a tensor divided by the sqrt of N.
//
// N is the size of the segment being reduced.
//
// Read [the section on
// Segmentation](../../api_docs/python/math_ops.md#segmentation) for an explanation
// of segments.
//
// Arguments:
// * scope: A Scope object
// * indices: A 1-D tensor. Has same rank as `segment_ids`.
// * segment_ids: A 1-D tensor. Values should be sorted and can be repeated.
class SparseSegmentSqrtN {
 public:
  SparseSegmentSqrtN(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   data, ::tensorflow::ops::Input indices,
                   ::tensorflow::ops::Input segment_ids);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes gradients for SparseSegmentSqrtN.
//
// Returns tensor "output" with same shape as grad, except for dimension 0 whose
// value is output_dim0.
//
// Arguments:
// * scope: A Scope object
// * grad: gradient propagated to the SparseSegmentSqrtN op.
// * indices: indices passed to the corresponding SparseSegmentSqrtN op.
// * segment_ids: segment_ids passed to the corresponding SparseSegmentSqrtN op.
// * output_dim0: dimension 0 of "data" passed to SparseSegmentSqrtN op.
class SparseSegmentSqrtNGrad {
 public:
  SparseSegmentSqrtNGrad(const ::tensorflow::Scope& scope,
                       ::tensorflow::ops::Input grad, ::tensorflow::ops::Input
                       indices, ::tensorflow::ops::Input segment_ids,
                       ::tensorflow::ops::Input output_dim0);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the sum along sparse segments of a tensor.
//
// Read [the section on
// Segmentation](../../api_docs/python/math_ops.md#segmentation) for an explanation
// of segments.
//
// Like `SegmentSum`, but `segment_ids` can have rank less than `data`'s first
// dimension, selecting a subset of dimension 0, specified by `indices`.
//
// For example:
//
// ```prettyprint
// c = tf.constant([[1,2,3,4], [-1,-2,-3,-4], [5,6,7,8]])
//
// # Select two rows, one segment.
// tf.sparse_segment_sum(c, tf.constant([0, 1]), tf.constant([0, 0]))
//   ==> [[0 0 0 0]]
//
// # Select two rows, two segment.
// tf.sparse_segment_sum(c, tf.constant([0, 1]), tf.constant([0, 1]))
//   ==> [[ 1  2  3  4]
//        [-1 -2 -3 -4]]
//
// # Select all rows, two segments.
// tf.sparse_segment_sum(c, tf.constant([0, 1, 2]), tf.constant([0, 0, 1]))
//   ==> [[0 0 0 0]
//        [5 6 7 8]]
//
// # Which is equivalent to:
// tf.segment_sum(c, tf.constant([0, 0, 1]))
// ```
//
// Arguments:
// * scope: A Scope object
// * indices: A 1-D tensor. Has same rank as `segment_ids`.
// * segment_ids: A 1-D tensor. Values should be sorted and can be repeated.
class SparseSegmentSum {
 public:
  SparseSegmentSum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 data, ::tensorflow::ops::Input indices,
                 ::tensorflow::ops::Input segment_ids);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes square root of x element-wise.
//
// I.e., \\(y = \sqrt{x} = x^{1/2}\\).
//
// Arguments:
// * scope: A Scope object
class Sqrt {
 public:
  Sqrt(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes the gradient for the sqrt of `x` wrt its input.
//
// Specifically, `grad = dy * 0.5 / y`, where `y = sqrt(x)`, and `dy`
// is the corresponding input gradient.
//
// Arguments:
// * scope: A Scope object
class SqrtGrad {
 public:
  SqrtGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
         ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes square of x element-wise.
//
// I.e., \\(y = x * x = x^2\\).
//
// Arguments:
// * scope: A Scope object
class Square {
 public:
  Square(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Returns (x - y)(x - y) element-wise.
//
// *NOTE*: `SquaredDifference` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class SquaredDifference {
 public:
  SquaredDifference(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
                  ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns x - y element-wise.
//
// *NOTE*: `Sub` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class Sub {
 public:
  Sub(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
    ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the sum of elements across dimensions of a tensor.
//
// Reduces `input` along the dimensions given in `reduction_indices`. Unless
// `keep_dims` is true, the rank of the tensor is reduced by 1 for each entry in
// `reduction_indices`. If `keep_dims` is true, the reduced dimensions are
// retained with length 1.
//
// Arguments:
// * scope: A Scope object
// * input: The tensor to reduce.
// * reduction_indices: The dimensions to reduce.
class Sum {
 public:
  // Optional attribute setters for Sum :
  //
  // KeepDims(bool): Defaults to false
  //     If true, retain reduced dimensions with length 1.
  struct Attrs {
    Attrs KeepDims(bool x) {
      Attrs ret = *this;
      ret.keep_dims_ = x;
      return ret;
    }

    bool keep_dims_ = false;
  };
  Sum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices);
  Sum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
    ::tensorflow::ops::Input reduction_indices, const Sum::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs KeepDims(bool x) {
    return Attrs().KeepDims(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes tan of x element-wise.
//
// Arguments:
// * scope: A Scope object
class Tan {
 public:
  Tan(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes hyperbolic tangent of `x` element-wise.
//
// Arguments:
// * scope: A Scope object
class Tanh {
 public:
  Tanh(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x);
  operator ::tensorflow::ops::Output() const { return y; }
  operator ::tensorflow::ops::Input() const { return y; }
  ::tensorflow::Node* node() const { return y.node(); }

  ::tensorflow::ops::Output y;
};

// Computes the gradient for the tanh of `x` wrt its input.
//
// Specifically, `grad = dy * (1 - y*y)`, where `y = tanh(x)`, and `dy`
// is the corresponding input gradient.
//
// Arguments:
// * scope: A Scope object
class TanhGrad {
 public:
  TanhGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
         ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns x / y element-wise for integer types.
//
// Truncation designates that negative numbers will round fractional quantities
// toward zero. I.e. -7 / 5 = 1. This matches C semantics but it is different
// than Python semantics. See `FloorDiv` for a division function that matches
// Python Semantics.
//
// *NOTE*: `TruncateDiv` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class TruncateDiv {
 public:
  TruncateDiv(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
            ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Returns element-wise remainder of division. This emulates C semantics where
//
// true, this follows C semantics in that the result here is consistent
// with a flooring divide. E.g. `floor(x / y) * y + mod(x, y) = x`.
//
// *NOTE*: `Mod` supports broadcasting. More about broadcasting
// [here](http://docs.scipy.org/doc/numpy/user/basics.broadcasting.html)
//
// Arguments:
// * scope: A Scope object
class TruncateMod {
 public:
  TruncateMod(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
            ::tensorflow::ops::Input y);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

// Computes the sum along segments of a tensor.
//
// Read [the section on
// Segmentation](../../api_docs/python/math_ops.md#segmentation) for an explanation
// of segments.
//
// Computes a tensor such that
// `(output[i] = sum_{j...} data[j...]` where the sum is over tuples `j...` such
// that `segment_ids[j...] == i`.  Unlike `SegmentSum`, `segment_ids`
// need not be sorted and need not cover all values in the full
// range of valid values.
//
// If the sum is empty for a given segment ID `i`, `output[i] = 0`.
//
// `num_segments` should equal the number of distinct segment IDs.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/UnsortedSegmentSum.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * segment_ids: A tensor whose shape is a prefix of `data.shape`.
class UnsortedSegmentSum {
 public:
  UnsortedSegmentSum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   data, ::tensorflow::ops::Input segment_ids,
                   ::tensorflow::ops::Input num_segments);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Compute the Hurwitz zeta function \\(\zeta(x, q)\\).
//
// The Hurwitz zeta function is defined as:
//
// ```
// \zeta(x, q) = \sum_{n=0}^{\infty} (q + n)^{-x}
// ```
//
// Arguments:
// * scope: A Scope object
class Zeta {
 public:
  Zeta(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
     ::tensorflow::ops::Input q);
  operator ::tensorflow::ops::Output() const { return z; }
  operator ::tensorflow::ops::Input() const { return z; }
  ::tensorflow::Node* node() const { return z.node(); }

  ::tensorflow::ops::Output z;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_MATH_OPS_H_
