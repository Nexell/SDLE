// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_FUNCTIONAL_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_FUNCTIONAL_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Computes the gradient function for function f via backpropagation.
//
// Arguments:
// * scope: A Scope object
// * input: a list of input tensors of size N + M;
// * Tout:
//     the type list for the input list.
// * f:
//     The function we want to compute the gradient for.
//
// The function 'f' must be a numerical function which takes N inputs and
// produces M outputs. Its gradient function 'g', which is computed by
// this SymbolicGradient op is a function taking N + M inputs and
// produces N outputs.
//
// I.e. if we have
//    (y1, y2, ..., y_M) = f(x1, x2, ..., x_N),
// then, g is
//    (dL/dx1, dL/dx2, ..., dL/dx_N) = g(x1, x2, ..., x_N,
//                                      dL/dy1, dL/dy2, ..., dL/dy_M),
//
// where L is a scalar-value function of (x1, x2, ..., xN) (e.g., the
// loss function). dL/dx_i is the partial derivative of L with respect
// to x_i.
//
// (Needs some math expert to say the comment above better.)
class SymbolicGradient {
 public:
  SymbolicGradient(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList
                 input, const DataTypeSlice& Tout, const NameAttrList& f);
  ::tensorflow::ops::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::ops::OutputList output;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_FUNCTIONAL_OPS_H_
