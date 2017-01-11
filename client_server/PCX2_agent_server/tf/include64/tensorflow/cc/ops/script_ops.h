// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_SCRIPT_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_SCRIPT_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Invokes a python function to compute func(input)->output.
//
// This operation is considered stateful. For a stateless version, see
// PyFuncStateless.
//
// Arguments:
// * scope: A Scope object
// * input: List of Tensors that will provide input to the Op.
// * token:
//     A token representing a registered python function in this address space.
// * Tout:
//     Data types of the outputs from the op.
// The length of the list specifies the number of outputs.
class PyFunc {
 public:
  PyFunc(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList input,
       StringPiece token, const DataTypeSlice& Tout);
  ::tensorflow::ops::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::ops::OutputList output;
};

// A stateless version of PyFunc.
//
// Arguments:
// * scope: A Scope object
class PyFuncStateless {
 public:
  PyFuncStateless(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList
                input, StringPiece token, const DataTypeSlice& Tout);
  ::tensorflow::ops::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::ops::OutputList output;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_SCRIPT_OPS_H_
