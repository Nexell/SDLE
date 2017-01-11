// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CONTROL_FLOW_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CONTROL_FLOW_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Raise a exception to abort the process when called.
//
// Returns nothing but an exception.
//
// Arguments:
// * scope: A Scope object
class Abort {
 public:
  // Optional attribute setters for Abort :
  //
  // ErrorMsg(StringPiece): Defaults to ""
  //     A string which is the message associated with the exception.
  struct Attrs {
    Attrs ErrorMsg(StringPiece x) {
      Attrs ret = *this;
      ret.error_msg_ = x;
      return ret;
    }

    StringPiece error_msg_ = "";
  };
  Abort(const ::tensorflow::Scope& scope);
  Abort(const ::tensorflow::Scope& scope, const Abort::Attrs& attrs);
  operator ::tensorflow::ops::Operation() const { return operation; }

  static Attrs ErrorMsg(StringPiece x) {
    return Attrs().ErrorMsg(x);
  }

  Operation operation;
};

// Does nothing. Serves as a control trigger for scheduling.
//
// Only useful as a placeholder for control edges.
//
// Arguments:
// * scope: A Scope object
class ControlTrigger {
 public:
  ControlTrigger(const ::tensorflow::Scope& scope);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Creates or finds a child frame, and makes `data` available to the child frame.
//
// This op is used together with `Exit` to create loops in the graph.
// The unique `frame_name` is used by the `Executor` to identify frames. If
// `is_constant` is true, `output` is a constant in the child frame; otherwise
// it may be changed in the child frame. At most `parallel_iterations` iterations
// are run in parallel in the child frame.
//
// Arguments:
// * scope: A Scope object
// * data: The tensor to be made available to the child frame.
// * frame_name:
//     The name of the child frame.
class Enter {
 public:
  // Optional attribute setters for Enter :
  //
  // IsConstant(bool): Defaults to false
  //     If true, the output is constant within the child frame.
  // ParallelIterations(int64): Defaults to 10
  //     The number of iterations allowed to run in parallel.
  struct Attrs {
    Attrs IsConstant(bool x) {
      Attrs ret = *this;
      ret.is_constant_ = x;
      return ret;
    }

    Attrs ParallelIterations(int64 x) {
      Attrs ret = *this;
      ret.parallel_iterations_ = x;
      return ret;
    }

    bool is_constant_ = false;
    int64 parallel_iterations_ = 10;
  };
  Enter(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
      StringPiece frame_name);
  Enter(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
      StringPiece frame_name, const Enter::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs IsConstant(bool x) {
    return Attrs().IsConstant(x);
  }
  static Attrs ParallelIterations(int64 x) {
    return Attrs().ParallelIterations(x);
  }

  ::tensorflow::ops::Output output;
};

// Exits the current frame to its parent frame.
//
// Exit makes its input `data` available to the parent frame.
//
// Arguments:
// * scope: A Scope object
// * data: The tensor to be made available to the parent frame.
class Exit {
 public:
  Exit(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Forwards the input to the output.
//
// This operator represents the loop termination condition used by the
// "pivot" switches of a loop.
//
// Arguments:
// * scope: A Scope object
// * input: A boolean scalar, representing the branch predicate of the Switch op.
class LoopCond {
 public:
  LoopCond(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Forwards the value of an available tensor from `inputs` to `output`.
//
// `Merge` waits for at least one of the tensors in `inputs` to become available.
// It is usually combined with `Switch` to implement branching.
//
// `Merge` forwards the first tensor for become available to `output`, and sets
// `value_index` to its index in `inputs`.
//
// Arguments:
// * scope: A Scope object
// * inputs: The input tensors, exactly one of which will become available.
class Merge {
 public:
  Merge(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList inputs);

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output value_index;
};

// Makes its input available to the next iteration.
//
// Arguments:
// * scope: A Scope object
// * data: The tensor to be made available to the next iteration.
class NextIteration {
 public:
  NextIteration(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Creates or finds a child frame, and makes `data` available to the child frame.
//
// The unique `frame_name` is used by the `Executor` to identify frames. If
// `is_constant` is true, `output` is a constant in the child frame; otherwise
// it may be changed in the child frame. At most `parallel_iterations` iterations
// are run in parallel in the child frame.
//
// Arguments:
// * scope: A Scope object
// * data: The tensor to be made available to the child frame.
// * frame_name:
//     The name of the child frame.
class RefEnter {
 public:
  // Optional attribute setters for RefEnter :
  //
  // IsConstant(bool): Defaults to false
  //     If true, the output is constant within the child frame.
  // ParallelIterations(int64): Defaults to 10
  //     The number of iterations allowed to run in parallel.
  struct Attrs {
    Attrs IsConstant(bool x) {
      Attrs ret = *this;
      ret.is_constant_ = x;
      return ret;
    }

    Attrs ParallelIterations(int64 x) {
      Attrs ret = *this;
      ret.parallel_iterations_ = x;
      return ret;
    }

    bool is_constant_ = false;
    int64 parallel_iterations_ = 10;
  };
  RefEnter(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
         StringPiece frame_name);
  RefEnter(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
         StringPiece frame_name, const RefEnter::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs IsConstant(bool x) {
    return Attrs().IsConstant(x);
  }
  static Attrs ParallelIterations(int64 x) {
    return Attrs().ParallelIterations(x);
  }

  ::tensorflow::ops::Output output;
};

// Exits the current frame to its parent frame.
//
// Exit makes its input `data` available to the parent frame.
//
// Arguments:
// * scope: A Scope object
// * data: The tensor to be made available to the parent frame.
class RefExit {
 public:
  RefExit(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Forwards the value of an available tensor from `inputs` to `output`.
//
// `Merge` waits for at least one of the tensors in `inputs` to become available.
// It is usually combined with `Switch` to implement branching.
//
// `Merge` forwards the first tensor for become available to `output`, and sets
// `value_index` to its index in `inputs`.
//
// Arguments:
// * scope: A Scope object
// * inputs: The input tensors, exactly one of which will become available.
class RefMerge {
 public:
  RefMerge(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList inputs);

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output value_index;
};

// Makes its input available to the next iteration.
//
// Arguments:
// * scope: A Scope object
// * data: The tensor to be made available to the next iteration.
class RefNextIteration {
 public:
  RefNextIteration(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 data);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Forwards the `index`th element of `inputs` to `output`.
//
// Arguments:
// * scope: A Scope object
// * index: A scalar that determines the input that gets selected.
// * inputs: A list of ref tensors, one of which will be forwarded to `output`.
class RefSelect {
 public:
  RefSelect(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input index,
          ::tensorflow::ops::InputList inputs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Forwards the ref tensor `data` to the output port determined by `pred`.
//
// If `pred` is true, the `data` input is forwarded to `output_true`. Otherwise,
// the data goes to `output_false`.
//
// See also `Switch` and `Merge`.
//
// Arguments:
// * scope: A Scope object
// * data: The ref tensor to be forwarded to the appropriate output.
// * pred: A scalar that specifies which output port will receive data.
class RefSwitch {
 public:
  RefSwitch(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
          ::tensorflow::ops::Input pred);

  ::tensorflow::ops::Output output_false;
  ::tensorflow::ops::Output output_true;
};

// Forwards `data` to the output port determined by `pred`.
//
// If `pred` is true, the `data` input is forwarded to `output_true`. Otherwise,
// the data goes to `output_false`.
//
// See also `RefSwitch` and `Merge`.
//
// Arguments:
// * scope: A Scope object
// * data: The tensor to be forwarded to the appropriate output.
// * pred: A scalar that specifies which output port will receive data.
class Switch {
 public:
  Switch(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input data,
       ::tensorflow::ops::Input pred);

  ::tensorflow::ops::Output output_false;
  ::tensorflow::ops::Output output_true;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CONTROL_FLOW_OPS_H_
