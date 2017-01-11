// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_STATE_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_STATE_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Update 'ref' by assigning 'value' to it.
//
// This operation outputs "ref" after the assignment is done.
// This makes it easier to chain operations that need to use the reset value.
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node. May be uninitialized.
// * value: The value to be assigned to the variable.
class Assign {
 public:
  // Optional attribute setters for Assign :
  //
  // ValidateShape(bool): Defaults to true
  //     If true, the operation will validate that the shape
  // of 'value' matches the shape of the Tensor being assigned to.  If false,
  // 'ref' will take on the shape of 'value'.
  // UseLocking(bool): Defaults to true
  //     If True, the assignment will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs ValidateShape(bool x) {
      Attrs ret = *this;
      ret.validate_shape_ = x;
      return ret;
    }

    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool validate_shape_ = true;
    bool use_locking_ = true;
  };
  Assign(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
       ::tensorflow::ops::Input value);
  Assign(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
       ::tensorflow::ops::Input value, const Assign::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output_ref; }
  operator ::tensorflow::ops::Input() const { return output_ref; }
  ::tensorflow::Node* node() const { return output_ref.node(); }

  static Attrs ValidateShape(bool x) {
    return Attrs().ValidateShape(x);
  }
  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output output_ref;
};

// Update 'ref' by adding 'value' to it.
//
// This operation outputs "ref" after the update is done.
// This makes it easier to chain operations that need to use the reset value.
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node.
// * value: The value to be added to the variable.
class AssignAdd {
 public:
  // Optional attribute setters for AssignAdd :
  //
  // UseLocking(bool): Defaults to false
  //     If True, the addition will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  AssignAdd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
          ::tensorflow::ops::Input value);
  AssignAdd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
          ::tensorflow::ops::Input value, const AssignAdd::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output_ref; }
  operator ::tensorflow::ops::Input() const { return output_ref; }
  ::tensorflow::Node* node() const { return output_ref.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output output_ref;
};

// Update 'ref' by subtracting 'value' from it.
//
// This operation outputs "ref" after the update is done.
// This makes it easier to chain operations that need to use the reset value.
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node.
// * value: The value to be subtracted to the variable.
class AssignSub {
 public:
  // Optional attribute setters for AssignSub :
  //
  // UseLocking(bool): Defaults to false
  //     If True, the subtraction will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  AssignSub(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
          ::tensorflow::ops::Input value);
  AssignSub(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
          ::tensorflow::ops::Input value, const AssignSub::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output_ref; }
  operator ::tensorflow::ops::Input() const { return output_ref; }
  ::tensorflow::Node* node() const { return output_ref.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output output_ref;
};

// Increments 'ref' until it reaches 'limit'.
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a scalar `Variable` node.
// * limit:
//     If incrementing ref would bring it above limit, instead generates an
// 'OutOfRange' error.
class CountUpTo {
 public:
  CountUpTo(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref, int64
          limit);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Destroys the temporary variable and returns its final value.
//
// Sets output to the value of the Tensor pointed to by 'ref', then destroys
// the temporary variable called 'var_name'.
// All other uses of 'ref' *must* have executed before this op.
// This is typically achieved by chaining the ref through each assign op, or by
// using control dependencies.
//
// Outputs the final value of the tensor pointed to by 'ref'.
//
// Arguments:
// * scope: A Scope object
// * ref: A reference to the temporary variable tensor.
// * var_name:
//     Name of the temporary variable, usually the name of the matching
// 'TemporaryVariable' op.
class DestroyTemporaryVariable {
 public:
  DestroyTemporaryVariable(const ::tensorflow::Scope& scope,
                         ::tensorflow::ops::Input ref, StringPiece var_name);
  operator ::tensorflow::ops::Output() const { return value; }
  operator ::tensorflow::ops::Input() const { return value; }
  ::tensorflow::Node* node() const { return value.node(); }

  ::tensorflow::ops::Output value;
};

// Checks whether a tensor has been initialized.
//
// Outputs boolean scalar indicating whether the tensor has been initialized.
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node. May be uninitialized.
class IsVariableInitialized {
 public:
  IsVariableInitialized(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input ref);
  operator ::tensorflow::ops::Output() const { return is_initialized; }
  operator ::tensorflow::ops::Input() const { return is_initialized; }
  ::tensorflow::Node* node() const { return is_initialized.node(); }

  ::tensorflow::ops::Output is_initialized;
};

// Adds sparse updates to a variable reference.
//
// This operation computes
//
//     # Scalar indices
//     ref[indices, ...] += updates[...]
//
//     # Vector indices (for each i)
//     ref[indices[i], ...] += updates[i, ...]
//
//     # High rank indices (for each i, ..., j)
//     ref[indices[i, ..., j], ...] += updates[i, ..., j, ...]
//
// This operation outputs `ref` after the update is done.
// This makes it easier to chain operations that need to use the reset value.
//
// Duplicate entries are handled correctly: if multiple `indices` reference
// the same location, their contributions add.
//
// Requires `updates.shape = indices.shape + ref.shape[1:]`.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/ScatterAdd.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node.
// * indices: A tensor of indices into the first dimension of `ref`.
// * updates: A tensor of updated values to add to `ref`.
class ScatterAdd {
 public:
  // Optional attribute setters for ScatterAdd :
  //
  // UseLocking(bool): Defaults to false
  //     If True, the addition will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ScatterAdd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
           ::tensorflow::ops::Input indices, ::tensorflow::ops::Input updates);
  ScatterAdd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
           ::tensorflow::ops::Input indices, ::tensorflow::ops::Input updates,
           const ScatterAdd::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output_ref; }
  operator ::tensorflow::ops::Input() const { return output_ref; }
  ::tensorflow::Node* node() const { return output_ref.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output output_ref;
};

// Divides a variable reference by sparse updates.
//
// This operation computes
//
//     # Scalar indices
//     ref[indices, ...] /= updates[...]
//
//     # Vector indices (for each i)
//     ref[indices[i], ...] /= updates[i, ...]
//
//     # High rank indices (for each i, ..., j)
//     ref[indices[i, ..., j], ...] /= updates[i, ..., j, ...]
//
// This operation outputs `ref` after the update is done.
// This makes it easier to chain operations that need to use the reset value.
//
// Duplicate entries are handled correctly: if multiple `indices` reference
// the same location, their contributions divide.
//
// Requires `updates.shape = indices.shape + ref.shape[1:]`.
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node.
// * indices: A tensor of indices into the first dimension of `ref`.
// * updates: A tensor of values that `ref` is divided by.
class ScatterDiv {
 public:
  // Optional attribute setters for ScatterDiv :
  //
  // UseLocking(bool): Defaults to false
  //     If True, the operation will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ScatterDiv(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
           ::tensorflow::ops::Input indices, ::tensorflow::ops::Input updates);
  ScatterDiv(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
           ::tensorflow::ops::Input indices, ::tensorflow::ops::Input updates,
           const ScatterDiv::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output_ref; }
  operator ::tensorflow::ops::Input() const { return output_ref; }
  ::tensorflow::Node* node() const { return output_ref.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output output_ref;
};

// Multiplies sparse updates into a variable reference.
//
// This operation computes
//
//     # Scalar indices
//     ref[indices, ...] *= updates[...]
//
//     # Vector indices (for each i)
//     ref[indices[i], ...] *= updates[i, ...]
//
//     # High rank indices (for each i, ..., j)
//     ref[indices[i, ..., j], ...] *= updates[i, ..., j, ...]
//
// This operation outputs `ref` after the update is done.
// This makes it easier to chain operations that need to use the reset value.
//
// Duplicate entries are handled correctly: if multiple `indices` reference
// the same location, their contributions multiply.
//
// Requires `updates.shape = indices.shape + ref.shape[1:]`.
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node.
// * indices: A tensor of indices into the first dimension of `ref`.
// * updates: A tensor of updated values to multiply to `ref`.
class ScatterMul {
 public:
  // Optional attribute setters for ScatterMul :
  //
  // UseLocking(bool): Defaults to false
  //     If True, the operation will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ScatterMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
           ::tensorflow::ops::Input indices, ::tensorflow::ops::Input updates);
  ScatterMul(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
           ::tensorflow::ops::Input indices, ::tensorflow::ops::Input updates,
           const ScatterMul::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output_ref; }
  operator ::tensorflow::ops::Input() const { return output_ref; }
  ::tensorflow::Node* node() const { return output_ref.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output output_ref;
};

// Subtracts sparse updates to a variable reference.
//
//     # Scalar indices
//     ref[indices, ...] -= updates[...]
//
//     # Vector indices (for each i)
//     ref[indices[i], ...] -= updates[i, ...]
//
//     # High rank indices (for each i, ..., j)
//     ref[indices[i, ..., j], ...] -= updates[i, ..., j, ...]
//
// This operation outputs `ref` after the update is done.
// This makes it easier to chain operations that need to use the reset value.
//
// Duplicate entries are handled correctly: if multiple `indices` reference
// the same location, their (negated) contributions add.
//
// Requires `updates.shape = indices.shape + ref.shape[1:]`.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/ScatterSub.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node.
// * indices: A tensor of indices into the first dimension of `ref`.
// * updates: A tensor of updated values to subtract from `ref`.
class ScatterSub {
 public:
  // Optional attribute setters for ScatterSub :
  //
  // UseLocking(bool): Defaults to false
  //     If True, the subtraction will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ScatterSub(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
           ::tensorflow::ops::Input indices, ::tensorflow::ops::Input updates);
  ScatterSub(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
           ::tensorflow::ops::Input indices, ::tensorflow::ops::Input updates,
           const ScatterSub::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output_ref; }
  operator ::tensorflow::ops::Input() const { return output_ref; }
  ::tensorflow::Node* node() const { return output_ref.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output output_ref;
};

// Applies sparse updates to a variable reference.
//
// This operation computes
//
//     # Scalar indices
//     ref[indices, ...] = updates[...]
//
//     # Vector indices (for each i)
//     ref[indices[i], ...] = updates[i, ...]
//
//     # High rank indices (for each i, ..., j)
//     ref[indices[i, ..., j], ...] = updates[i, ..., j, ...]
//
// This operation outputs `ref` after the update is done.
// This makes it easier to chain operations that need to use the reset value.
//
// If values in `ref` is to be updated more than once, because there are
// duplicate entires in `indices`, the order at which the updates happen
// for each value is undefined.
//
// Requires `updates.shape = indices.shape + ref.shape[1:]`.
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/ScatterUpdate.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * ref: Should be from a `Variable` node.
// * indices: A tensor of indices into the first dimension of `ref`.
// * updates: A tensor of updated values to store in `ref`.
class ScatterUpdate {
 public:
  // Optional attribute setters for ScatterUpdate :
  //
  // UseLocking(bool): Defaults to true
  //     If True, the assignment will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = true;
  };
  ScatterUpdate(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
              ::tensorflow::ops::Input indices, ::tensorflow::ops::Input
              updates);
  ScatterUpdate(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input ref,
              ::tensorflow::ops::Input indices, ::tensorflow::ops::Input
              updates, const ScatterUpdate::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output_ref; }
  operator ::tensorflow::ops::Input() const { return output_ref; }
  ::tensorflow::Node* node() const { return output_ref.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output output_ref;
};

// Returns a tensor that may be mutated, but only persists within a single step.
//
// This is an experimental op for internal use only and it is possible to use this
// op in unsafe ways.  DO NOT USE unless you fully understand the risks.
//
// It is the caller's responsibility to ensure that 'ref' is eventually passed to a
// matching 'DestroyTemporaryVariable' op after all other uses have completed.
//
// Outputs a ref to the tensor state so it may be read or modified.
//
//   E.g.
//       var = state_ops._temporary_variable([1, 2], types.float_)
//       var_name = var.op.name
//       var = state_ops.assign(var, [[4.0, 5.0]])
//       var = state_ops.assign_add(var, [[6.0, 7.0]])
//       final = state_ops._destroy_temporary_variable(var, var_name=var_name)
//
// Arguments:
// * scope: A Scope object
// * shape:
//     The shape of the variable tensor.
// * dtype:
//     The type of elements in the variable tensor.
class TemporaryVariable {
 public:
  // Optional attribute setters for TemporaryVariable :
  //
  // VarName(StringPiece): Defaults to ""
  //     Overrides the name used for the temporary variable resource. Default
  // value is the name of the 'TemporaryVariable' op (which is guaranteed unique).
  struct Attrs {
    Attrs VarName(StringPiece x) {
      Attrs ret = *this;
      ret.var_name_ = x;
      return ret;
    }

    StringPiece var_name_ = "";
  };
  TemporaryVariable(const ::tensorflow::Scope& scope, TensorShape shape, DataType
                  dtype);
  TemporaryVariable(const ::tensorflow::Scope& scope, TensorShape shape, DataType
                  dtype, const TemporaryVariable::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return ref; }
  operator ::tensorflow::ops::Input() const { return ref; }
  ::tensorflow::Node* node() const { return ref.node(); }

  static Attrs VarName(StringPiece x) {
    return Attrs().VarName(x);
  }

  ::tensorflow::ops::Output ref;
};

// Holds state in the form of a tensor that persists across steps.
//
// Outputs a ref to the tensor state so it may be read or modified.
// TODO(zhifengc/mrry): Adds a pointer to a more detail document
// about sharing states in tensorflow.
//
// Arguments:
// * scope: A Scope object
// * shape:
//     The shape of the variable tensor.
// * dtype:
//     The type of elements in the variable tensor.
class Variable {
 public:
  // Optional attribute setters for Variable :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this variable is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this variable is named in the given bucket
  // with this shared_name. Otherwise, the node name is used instead.
  struct Attrs {
    Attrs Container(StringPiece x) {
      Attrs ret = *this;
      ret.container_ = x;
      return ret;
    }

    Attrs SharedName(StringPiece x) {
      Attrs ret = *this;
      ret.shared_name_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  Variable(const ::tensorflow::Scope& scope, TensorShape shape, DataType dtype);
  Variable(const ::tensorflow::Scope& scope, TensorShape shape, DataType dtype,
         const Variable::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return ref; }
  operator ::tensorflow::ops::Input() const { return ref; }
  ::tensorflow::Node* node() const { return ref.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output ref;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_STATE_OPS_H_
