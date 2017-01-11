// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_DATA_FLOW_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_DATA_FLOW_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Applies a gradient to a given accumulator. Does not add if local_step is lesser
//
// than the accumulator's global_step.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a accumulator.
// * local_step: The local_step value at which the gradient was computed.
// * gradient: A tensor of the gradient to be accumulated.
class AccumulatorApplyGradient {
 public:
  AccumulatorApplyGradient(const ::tensorflow::Scope& scope,
                         ::tensorflow::ops::Input handle,
                         ::tensorflow::ops::Input local_step,
                         ::tensorflow::ops::Input gradient);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Returns the number of gradients aggregated in the given accumulators.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to an accumulator.
class AccumulatorNumAccumulated {
 public:
  AccumulatorNumAccumulated(const ::tensorflow::Scope& scope,
                          ::tensorflow::ops::Input handle);
  operator ::tensorflow::ops::Output() const { return num_accumulated; }
  operator ::tensorflow::ops::Input() const { return num_accumulated; }
  ::tensorflow::Node* node() const { return num_accumulated.node(); }

  ::tensorflow::ops::Output num_accumulated;
};

// Updates the accumulator with a new value for global_step. Logs warning if the
//
// accumulator's value is already higher than new_global_step.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to an accumulator.
// * new_global_step: The new global_step value to set.
class AccumulatorSetGlobalStep {
 public:
  AccumulatorSetGlobalStep(const ::tensorflow::Scope& scope,
                         ::tensorflow::ops::Input handle,
                         ::tensorflow::ops::Input new_global_step);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Extracts the average gradient in the given ConditionalAccumulator, provided
//
// that sufficient (i.e., more than num_required) gradients have been accumulated.
// The op blocks until sufficient gradients have been accumulated.
// If the accumulator has already aggregated more than num_required gradients, it
// returns the average of the accumulated gradients.
// Also automatically increments the recorded global_step in the accumulator by 1,
// and resets the aggregate to 0.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to an accumulator.
// * num_required: Number of gradients required before we return an aggregate.
// * dtype:
//     The data type of accumulated gradients. Needs to correspond to the type
// of the accumulator.
class AccumulatorTakeGradient {
 public:
  AccumulatorTakeGradient(const ::tensorflow::Scope& scope,
                        ::tensorflow::ops::Input handle,
                        ::tensorflow::ops::Input num_required, DataType dtype);
  operator ::tensorflow::ops::Output() const { return average; }
  operator ::tensorflow::ops::Input() const { return average; }
  ::tensorflow::Node* node() const { return average.node(); }

  ::tensorflow::ops::Output average;
};

// Defines a barrier that persists across different graph executions.
//
// A barrier represents a key-value map, where each key is a string, and
// each value is a tuple of tensors.
//
// At runtime, the barrier contains 'complete' and 'incomplete'
// elements. A complete element has defined tensors for all components of
// its value tuple, and may be accessed using BarrierTakeMany. An
// incomplete element has some undefined components in its value tuple,
// and may be updated using BarrierInsertMany.
//
// Arguments:
// * scope: A Scope object
// * component_types:
//     The type of each component in a value.
class Barrier {
 public:
  // Optional attribute setters for Barrier :
  //
  // Shapes(const gtl::ArraySlice<TensorShape>&): Defaults to []
  //     The shape of each component in a value. Each shape must be 1 in the
  // first dimension. The length of this attr must be the same as the length of
  // component_types.
  // Capacity(int64): Defaults to -1
  //     The capacity of the barrier.  The default capacity is MAX_INT32,
  // which is the largest capacity of the underlying queue.
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this barrier is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this barrier will be shared under the given name
  // across multiple sessions.
  struct Attrs {
    Attrs Shapes(const gtl::ArraySlice<TensorShape>& x) {
      Attrs ret = *this;
      ret.shapes_ = x;
      return ret;
    }

    Attrs Capacity(int64 x) {
      Attrs ret = *this;
      ret.capacity_ = x;
      return ret;
    }

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

    gtl::ArraySlice<TensorShape> shapes_ = {};
    int64 capacity_ = -1;
    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  Barrier(const ::tensorflow::Scope& scope, const DataTypeSlice& component_types);
  Barrier(const ::tensorflow::Scope& scope, const DataTypeSlice& component_types,
        const Barrier::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs Shapes(const gtl::ArraySlice<TensorShape>& x) {
    return Attrs().Shapes(x);
  }
  static Attrs Capacity(int64 x) {
    return Attrs().Capacity(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output handle;
};

// Closes the given barrier.
//
// This operation signals that no more new elements will be inserted in the
// given barrier. Subsequent InsertMany that try to introduce a new key will fail.
// Subsequent InsertMany operations that just add missing components to already
// existing elements will continue to succeed. Subsequent TakeMany operations will
// continue to succeed if sufficient completed elements remain in the barrier.
// Subsequent TakeMany operations that would block will fail immediately.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a barrier.
class BarrierClose {
 public:
  // Optional attribute setters for BarrierClose :
  //
  // CancelPendingEnqueues(bool): Defaults to false
  //     If true, all pending enqueue requests that are
  // blocked on the barrier's queue will be cancelled. InsertMany will fail, even
  // if no new key is introduced.
  struct Attrs {
    Attrs CancelPendingEnqueues(bool x) {
      Attrs ret = *this;
      ret.cancel_pending_enqueues_ = x;
      return ret;
    }

    bool cancel_pending_enqueues_ = false;
  };
  BarrierClose(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle);
  BarrierClose(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
             const BarrierClose::Attrs& attrs);
  operator ::tensorflow::ops::Operation() const { return operation; }

  static Attrs CancelPendingEnqueues(bool x) {
    return Attrs().CancelPendingEnqueues(x);
  }

  Operation operation;
};

// Computes the number of incomplete elements in the given barrier.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a barrier.
class BarrierIncompleteSize {
 public:
  BarrierIncompleteSize(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input handle);
  operator ::tensorflow::ops::Output() const { return size; }
  operator ::tensorflow::ops::Input() const { return size; }
  ::tensorflow::Node* node() const { return size.node(); }

  ::tensorflow::ops::Output size;
};

// For each key, assigns the respective value to the specified component.
//
// If a key is not found in the barrier, this operation will create a new
// incomplete element. If a key is found in the barrier, and the element
// already has a value at component_index, this operation will fail with
// INVALID_ARGUMENT, and leave the barrier in an undefined state.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a barrier.
// * keys: A one-dimensional tensor of keys, with length n.
// * values: An any-dimensional tensor of values, which are associated with the
// respective keys. The 0th dimension must have length n.
// * component_index:
//     The component of the barrier elements that is being assigned.
class BarrierInsertMany {
 public:
  BarrierInsertMany(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  handle, ::tensorflow::ops::Input keys,
                  ::tensorflow::ops::Input values, int64 component_index);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Computes the number of complete elements in the given barrier.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a barrier.
class BarrierReadySize {
 public:
  BarrierReadySize(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle);
  operator ::tensorflow::ops::Output() const { return size; }
  operator ::tensorflow::ops::Input() const { return size; }
  ::tensorflow::Node* node() const { return size.node(); }

  ::tensorflow::ops::Output size;
};

// Takes the given number of completed elements from a barrier.
//
// This operation concatenates completed-element component tensors along
// the 0th dimension to make a single component tensor.
//
// Elements come out of the barrier when they are complete, and in the order
// in which they were placed into the barrier.  The indices output provides
// information about the batch in which each element was originally inserted
// into the barrier.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a barrier.
// * num_elements: A single-element tensor containing the number of elements to
// take.
// * component_types:
//     The type of each component in a value.
class BarrierTakeMany {
 public:
  // Optional attribute setters for BarrierTakeMany :
  //
  // AllowSmallBatch(bool): Defaults to false
  //     Allow to return less than num_elements items if barrier is
  // already closed.
  // WaitForIncomplete(bool): Defaults to false
  // TimeoutMs(int64): Defaults to -1
  //     If the queue is empty, this operation will block for up to
  // timeout_ms milliseconds.
  // Note: This option is not supported yet.
  struct Attrs {
    Attrs AllowSmallBatch(bool x) {
      Attrs ret = *this;
      ret.allow_small_batch_ = x;
      return ret;
    }

    Attrs WaitForIncomplete(bool x) {
      Attrs ret = *this;
      ret.wait_for_incomplete_ = x;
      return ret;
    }

    Attrs TimeoutMs(int64 x) {
      Attrs ret = *this;
      ret.timeout_ms_ = x;
      return ret;
    }

    bool allow_small_batch_ = false;
    bool wait_for_incomplete_ = false;
    int64 timeout_ms_ = -1;
  };
  BarrierTakeMany(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                handle, ::tensorflow::ops::Input num_elements, const
                DataTypeSlice& component_types);
  BarrierTakeMany(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                handle, ::tensorflow::ops::Input num_elements, const
                DataTypeSlice& component_types, const BarrierTakeMany::Attrs&
                attrs);

  static Attrs AllowSmallBatch(bool x) {
    return Attrs().AllowSmallBatch(x);
  }
  static Attrs WaitForIncomplete(bool x) {
    return Attrs().WaitForIncomplete(x);
  }
  static Attrs TimeoutMs(int64 x) {
    return Attrs().TimeoutMs(x);
  }

  ::tensorflow::ops::Output indices;
  ::tensorflow::ops::Output keys;
  ::tensorflow::ops::OutputList values;
};

// A conditional accumulator for aggregating gradients. The accumulator accepts
//
// gradients marked with local_step greater or equal to the most recent global_step
// known to the accumulator. The average can be extracted from the accumulator,
// provided sufficient gradients have been accumulated. Extracting the average
// automatically resets the aggregate to 0, and increments the global_step recorded
// by the accumulator.
//
// Arguments:
// * scope: A Scope object
// * dtype:
//     The type of the value being accumulated.
// * shape:
//     The shape of the values, can be [], in which case shape is unknown.
class ConditionalAccumulator {
 public:
  // Optional attribute setters for ConditionalAccumulator :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this accumulator is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this accumulator will be shared under the given name
  // across multiple sessions.
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
  ConditionalAccumulator(const ::tensorflow::Scope& scope, DataType dtype,
                       TensorShape shape);
  ConditionalAccumulator(const ::tensorflow::Scope& scope, DataType dtype,
                       TensorShape shape, const ConditionalAccumulator::Attrs&
                       attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output handle;
};

// Delete the tensor specified by its handle in the session.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle for a tensor stored in the session state.
class DeleteSessionTensor {
 public:
  DeleteSessionTensor(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    handle);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Partitions `data` into `num_partitions` tensors using indices from `partitions`.
//
// For each index tuple `js` of size `partitions.ndim`, the slice `data[js, ...]`
// becomes part of `outputs[partitions[js]]`.  The slices with `partitions[js] = i`
// are placed in `outputs[i]` in lexicographic order of `js`, and the first
// dimension of `outputs[i]` is the number of entries in `partitions` equal to `i`.
// In detail,
//
// ```python
//     outputs[i].shape = [sum(partitions == i)] + data.shape[partitions.ndim:]
//
//     outputs[i] = pack([data[js, ...] for js if partitions[js] == i])
// ```
//
// `data.shape` must start with `partitions.shape`.
//
// For example:
//
// ```python
//     # Scalar partitions.
//     partitions = 1
//     num_partitions = 2
//     data = [10, 20]
//     outputs[0] = []  # Empty with shape [0, 2]
//     outputs[1] = [[10, 20]]
//
//     # Vector partitions.
//     partitions = [0, 0, 1, 1, 0]
//     num_partitions = 2
//     data = [10, 20, 30, 40, 50]
//     outputs[0] = [10, 20, 50]
//     outputs[1] = [30, 40]
// ```
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/DynamicPartition.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
// * partitions: Any shape.  Indices in the range `[0, num_partitions)`.
// * num_partitions:
//     The number of partitions to output.
class DynamicPartition {
 public:
  DynamicPartition(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 data, ::tensorflow::ops::Input partitions, int64
                 num_partitions);
  ::tensorflow::ops::Output operator[](size_t index) const { return outputs[index]; }


  ::tensorflow::ops::OutputList outputs;
};

// Interleave the values from the `data` tensors into a single tensor.
//
// Builds a merged tensor such that
//
// ```python
//     merged[indices[m][i, ..., j], ...] = data[m][i, ..., j, ...]
// ```
//
// For example, if each `indices[m]` is scalar or vector, we have
//
// ```python
//     # Scalar indices:
//     merged[indices[m], ...] = data[m][...]
//
//     # Vector indices:
//     merged[indices[m][i], ...] = data[m][i, ...]
// ```
//
// Each `data[i].shape` must start with the corresponding `indices[i].shape`,
// and the rest of `data[i].shape` must be constant w.r.t. `i`.  That is, we
// must have `data[i].shape = indices[i].shape + constant`.  In terms of this
// `constant`, the output shape is
//
//     merged.shape = [max(indices)] + constant
//
// Values are merged in order, so if an index appears in both `indices[m][i]` and
// `indices[n][j]` for `(m,i) < (n,j)` the slice `data[n][j]` will appear in the
// merged result.
//
// For example:
//
// ```python
//     indices[0] = 6
//     indices[1] = [4, 1]
//     indices[2] = [[5, 2], [0, 3]]
//     data[0] = [61, 62]
//     data[1] = [[41, 42], [11, 12]]
//     data[2] = [[[51, 52], [21, 22]], [[1, 2], [31, 32]]]
//     merged = [[1, 2], [11, 12], [21, 22], [31, 32], [41, 42],
//               [51, 52], [61, 62]]
// ```
//
// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
// <img style="width:100%" src="../../images/DynamicStitch.png" alt>
// </div>
//
// Arguments:
// * scope: A Scope object
class DynamicStitch {
 public:
  DynamicStitch(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList
              indices, ::tensorflow::ops::InputList data);
  operator ::tensorflow::ops::Output() const { return merged; }
  operator ::tensorflow::ops::Input() const { return merged; }
  ::tensorflow::Node* node() const { return merged.node(); }

  ::tensorflow::ops::Output merged;
};

// A queue that produces elements in first-in first-out order.
//
// Arguments:
// * scope: A Scope object
// * component_types:
//     The type of each component in a value.
class FIFOQueue {
 public:
  // Optional attribute setters for FIFOQueue :
  //
  // Shapes(const gtl::ArraySlice<TensorShape>&): Defaults to []
  //     The shape of each component in a value. The length of this attr must
  // be either 0 or the same as the length of component_types. If the length of
  // this attr is 0, the shapes of queue elements are not constrained, and
  // only one element may be dequeued at a time.
  // Capacity(int64): Defaults to -1
  //     The upper bound on the number of elements in this queue.
  // Negative numbers mean no limit.
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this queue is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this queue will be shared under the given name
  // across multiple sessions.
  struct Attrs {
    Attrs Shapes(const gtl::ArraySlice<TensorShape>& x) {
      Attrs ret = *this;
      ret.shapes_ = x;
      return ret;
    }

    Attrs Capacity(int64 x) {
      Attrs ret = *this;
      ret.capacity_ = x;
      return ret;
    }

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

    gtl::ArraySlice<TensorShape> shapes_ = {};
    int64 capacity_ = -1;
    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  FIFOQueue(const ::tensorflow::Scope& scope, const DataTypeSlice&
          component_types);
  FIFOQueue(const ::tensorflow::Scope& scope, const DataTypeSlice&
          component_types, const FIFOQueue::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs Shapes(const gtl::ArraySlice<TensorShape>& x) {
    return Attrs().Shapes(x);
  }
  static Attrs Capacity(int64 x) {
    return Attrs().Capacity(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output handle;
};

// Store the input tensor in the state of the current session.
//
// Arguments:
// * scope: A Scope object
// * value: The tensor to be stored.
class GetSessionHandle {
 public:
  GetSessionHandle(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 value);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  ::tensorflow::ops::Output handle;
};

// Get the value of the tensor specified by its handle.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle for a tensor stored in the session state.
// * dtype:
//     The type of the output value.
class GetSessionTensor {
 public:
  GetSessionTensor(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, DataType dtype);
  operator ::tensorflow::ops::Output() const { return value; }
  operator ::tensorflow::ops::Input() const { return value; }
  ::tensorflow::Node* node() const { return value.node(); }

  ::tensorflow::ops::Output value;
};

// Creates a non-initialized hash table.
//
// This op creates a hash table, specifying the type of its keys and values.
// Before using the table you will have to initialize it.  After initialization the
// table will be immutable.
//
// Arguments:
// * scope: A Scope object
// * key_dtype:
//     Type of the table keys.
// * value_dtype:
//     Type of the table values.
class HashTable {
 public:
  // Optional attribute setters for HashTable :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this table is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this table is shared under the given name across
  // multiple sessions.
  // UseNodeNameSharing(bool): Defaults to false
  //     If true and shared_name is empty, the table is shared
  // using the node name.
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

    Attrs UseNodeNameSharing(bool x) {
      Attrs ret = *this;
      ret.use_node_name_sharing_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
    bool use_node_name_sharing_ = false;
  };
  HashTable(const ::tensorflow::Scope& scope, DataType key_dtype, DataType
          value_dtype);
  HashTable(const ::tensorflow::Scope& scope, DataType key_dtype, DataType
          value_dtype, const HashTable::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return table_handle; }
  operator ::tensorflow::ops::Input() const { return table_handle; }
  ::tensorflow::Node* node() const { return table_handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }
  static Attrs UseNodeNameSharing(bool x) {
    return Attrs().UseNodeNameSharing(x);
  }

  ::tensorflow::ops::Output table_handle;
};

// Table initializer that takes two tensors for keys and values respectively.
//
// Arguments:
// * scope: A Scope object
// * table_handle: Handle to a table which will be initialized.
// * keys: Keys of type Tkey.
// * values: Values of type Tval.
class InitializeTable {
 public:
  InitializeTable(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                table_handle, ::tensorflow::ops::Input keys,
                ::tensorflow::ops::Input values);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Initializes a table from a text file.
//
// It inserts one key-value pair into the table for each line of the file.
// The key and value is extracted from the whole line content, elements from the
// split line based on `delimiter` or the line number (starting from zero).
// Where to extract the key and value from a line is specified by `key_index` and
// `value_index`.
//
// - A value of -1 means use the line number(starting from zero), expects `int64`.
// - A value of -2 means use the whole line content, expects `string`.
// - A value >= 0 means use the index (starting at zero) of the split line based
//   on `delimiter`.
//
// Arguments:
// * scope: A Scope object
// * table_handle: Handle to a table which will be initialized.
// * filename: Filename of a vocabulary text file.
// * key_index:
//     Column index in a line to get the table `key` values from.
// * value_index:
//     Column index that represents information of a line to get the table
// `value` values from.
class InitializeTableFromTextFile {
 public:
  // Optional attribute setters for InitializeTableFromTextFile :
  //
  // VocabSize(int64): Defaults to -1
  //     Number of elements of the file, use -1 if unknown.
  // Delimiter(StringPiece): Defaults to "\t"
  //     Delimiter to separate fields in a line.
  struct Attrs {
    Attrs VocabSize(int64 x) {
      Attrs ret = *this;
      ret.vocab_size_ = x;
      return ret;
    }

    Attrs Delimiter(StringPiece x) {
      Attrs ret = *this;
      ret.delimiter_ = x;
      return ret;
    }

    int64 vocab_size_ = -1;
    StringPiece delimiter_ = "\t";
  };
  InitializeTableFromTextFile(const ::tensorflow::Scope& scope,
                            ::tensorflow::ops::Input table_handle,
                            ::tensorflow::ops::Input filename, int64 key_index,
                            int64 value_index);
  InitializeTableFromTextFile(const ::tensorflow::Scope& scope,
                            ::tensorflow::ops::Input table_handle,
                            ::tensorflow::ops::Input filename, int64 key_index,
                            int64 value_index, const
                            InitializeTableFromTextFile::Attrs& attrs);
  operator ::tensorflow::ops::Operation() const { return operation; }

  static Attrs VocabSize(int64 x) {
    return Attrs().VocabSize(x);
  }
  static Attrs Delimiter(StringPiece x) {
    return Attrs().Delimiter(x);
  }

  Operation operation;
};

// Outputs all keys and values in the table.
//
// Arguments:
// * scope: A Scope object
// * table_handle: Handle to the table.
class LookupTableExport {
 public:
  LookupTableExport(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  table_handle, DataType Tkeys, DataType Tvalues);

  ::tensorflow::ops::Output keys;
  ::tensorflow::ops::Output values;
};

// Looks up keys in a table, outputs the corresponding values.
//
// The tensor `keys` must of the same type as the keys of the table.
// The output `values` is of the type of the table values.
//
// The scalar `default_value` is the value output for keys not present in the
// table. It must also be of the same type as the table values.
//
// Arguments:
// * scope: A Scope object
// * table_handle: Handle to the table.
// * keys: Any shape.  Keys to look up.
class LookupTableFind {
 public:
  LookupTableFind(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                table_handle, ::tensorflow::ops::Input keys,
                ::tensorflow::ops::Input default_value);
  operator ::tensorflow::ops::Output() const { return values; }
  operator ::tensorflow::ops::Input() const { return values; }
  ::tensorflow::Node* node() const { return values.node(); }

  ::tensorflow::ops::Output values;
};

// Replaces the contents of the table with the specified keys and values.
//
// The tensor `keys` must be of the same type as the keys of the table.
// The tensor `values` must be of the type of the table values.
//
// Arguments:
// * scope: A Scope object
// * table_handle: Handle to the table.
// * keys: Any shape.  Keys to look up.
// * values: Values to associate with keys.
class LookupTableImport {
 public:
  LookupTableImport(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  table_handle, ::tensorflow::ops::Input keys,
                  ::tensorflow::ops::Input values);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Updates the table to associates keys with values.
//
// The tensor `keys` must be of the same type as the keys of the table.
// The tensor `values` must be of the type of the table values.
//
// Arguments:
// * scope: A Scope object
// * table_handle: Handle to the table.
// * keys: Any shape.  Keys to look up.
// * values: Values to associate with keys.
class LookupTableInsert {
 public:
  LookupTableInsert(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  table_handle, ::tensorflow::ops::Input keys,
                  ::tensorflow::ops::Input values);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Computes the number of elements in the given table.
//
// Arguments:
// * scope: A Scope object
// * table_handle: Handle to the table.
class LookupTableSize {
 public:
  LookupTableSize(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                table_handle);
  operator ::tensorflow::ops::Output() const { return size; }
  operator ::tensorflow::ops::Input() const { return size; }
  ::tensorflow::Node* node() const { return size.node(); }

  ::tensorflow::ops::Output size;
};

// Creates an empty hash table that uses tensors as the backing store. It uses
//
// "open addressing" with quadratic reprobing to resolve collisions.
//
// This op creates a mutable hash table, specifying the type of its keys and
// values. Each value must be a scalar. Data can be inserted into the table using
// the insert operations. It does not support the initialization operation.
//
// Arguments:
// * scope: A Scope object
// * empty_key: The key used to represent empty key buckets internally. Must not
// be used in insert or lookup operations.
// * value_dtype:
//     Type of the table values.
class MutableDenseHashTable {
 public:
  // Optional attribute setters for MutableDenseHashTable :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this table is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this table is shared under the given name across
  // multiple sessions.
  // UseNodeNameSharing(bool): Defaults to false
  // ValueShape(TensorShape): Defaults to []
  //     The shape of each value.
  // InitialNumBuckets(int64): Defaults to 131072
  //     The initial number of hash table buckets. Must be a power
  // to 2.
  // MaxLoadFactor(float): Defaults to 0.8
  //     The maximum ratio between number of entries and number of
  // buckets before growing the table. Must be between 0 and 1.
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

    Attrs UseNodeNameSharing(bool x) {
      Attrs ret = *this;
      ret.use_node_name_sharing_ = x;
      return ret;
    }

    Attrs ValueShape(TensorShape x) {
      Attrs ret = *this;
      ret.value_shape_ = x;
      return ret;
    }

    Attrs InitialNumBuckets(int64 x) {
      Attrs ret = *this;
      ret.initial_num_buckets_ = x;
      return ret;
    }

    Attrs MaxLoadFactor(float x) {
      Attrs ret = *this;
      ret.max_load_factor_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
    bool use_node_name_sharing_ = false;
    TensorShape value_shape_ = {};
    int64 initial_num_buckets_ = 131072;
    float max_load_factor_ = 0.8f;
  };
  MutableDenseHashTable(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input empty_key, DataType value_dtype);
  MutableDenseHashTable(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input empty_key, DataType value_dtype,
                      const MutableDenseHashTable::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return table_handle; }
  operator ::tensorflow::ops::Input() const { return table_handle; }
  ::tensorflow::Node* node() const { return table_handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }
  static Attrs UseNodeNameSharing(bool x) {
    return Attrs().UseNodeNameSharing(x);
  }
  static Attrs ValueShape(TensorShape x) {
    return Attrs().ValueShape(x);
  }
  static Attrs InitialNumBuckets(int64 x) {
    return Attrs().InitialNumBuckets(x);
  }
  static Attrs MaxLoadFactor(float x) {
    return Attrs().MaxLoadFactor(x);
  }

  ::tensorflow::ops::Output table_handle;
};

// Creates an empty hash table.
//
// This op creates a mutable hash table, specifying the type of its keys and
// values. Each value must be a scalar. Data can be inserted into the table using
// the insert operations. It does not support the initialization operation.
//
// Arguments:
// * scope: A Scope object
// * key_dtype:
//     Type of the table keys.
// * value_dtype:
//     Type of the table values.
class MutableHashTable {
 public:
  // Optional attribute setters for MutableHashTable :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this table is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this table is shared under the given name across
  // multiple sessions.
  // UseNodeNameSharing(bool): Defaults to false
  //     If true and shared_name is empty, the table is shared
  // using the node name.
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

    Attrs UseNodeNameSharing(bool x) {
      Attrs ret = *this;
      ret.use_node_name_sharing_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
    bool use_node_name_sharing_ = false;
  };
  MutableHashTable(const ::tensorflow::Scope& scope, DataType key_dtype, DataType
                 value_dtype);
  MutableHashTable(const ::tensorflow::Scope& scope, DataType key_dtype, DataType
                 value_dtype, const MutableHashTable::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return table_handle; }
  operator ::tensorflow::ops::Input() const { return table_handle; }
  ::tensorflow::Node* node() const { return table_handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }
  static Attrs UseNodeNameSharing(bool x) {
    return Attrs().UseNodeNameSharing(x);
  }

  ::tensorflow::ops::Output table_handle;
};

// Creates an empty hash table.
//
// This op creates a mutable hash table, specifying the type of its keys and
// values. Each value must be a vector. Data can be inserted into the table using
// the insert operations. It does not support the initialization operation.
//
// Arguments:
// * scope: A Scope object
// * key_dtype:
//     Type of the table keys.
// * value_dtype:
//     Type of the table values.
class MutableHashTableOfTensors {
 public:
  // Optional attribute setters for MutableHashTableOfTensors :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this table is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this table is shared under the given name across
  // multiple sessions.
  // UseNodeNameSharing(bool): Defaults to false
  // ValueShape(TensorShape): Defaults to []
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

    Attrs UseNodeNameSharing(bool x) {
      Attrs ret = *this;
      ret.use_node_name_sharing_ = x;
      return ret;
    }

    Attrs ValueShape(TensorShape x) {
      Attrs ret = *this;
      ret.value_shape_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
    bool use_node_name_sharing_ = false;
    TensorShape value_shape_ = {};
  };
  MutableHashTableOfTensors(const ::tensorflow::Scope& scope, DataType key_dtype,
                          DataType value_dtype);
  MutableHashTableOfTensors(const ::tensorflow::Scope& scope, DataType key_dtype,
                          DataType value_dtype, const
                          MutableHashTableOfTensors::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return table_handle; }
  operator ::tensorflow::ops::Input() const { return table_handle; }
  ::tensorflow::Node* node() const { return table_handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }
  static Attrs UseNodeNameSharing(bool x) {
    return Attrs().UseNodeNameSharing(x);
  }
  static Attrs ValueShape(TensorShape x) {
    return Attrs().ValueShape(x);
  }

  ::tensorflow::ops::Output table_handle;
};

// A queue that produces elements in first-in first-out order.
//
// Variable-size shapes are allowed by setting the corresponding shape dimensions
// to 0 in the shape attr.  In this case DequeueMany will pad up to the maximum
// size of any given element in the minibatch.  See below for details.
//
// Arguments:
// * scope: A Scope object
// * component_types:
//     The type of each component in a value.
class PaddingFIFOQueue {
 public:
  // Optional attribute setters for PaddingFIFOQueue :
  //
  // Shapes(const gtl::ArraySlice<TensorShape>&): Defaults to []
  //     The shape of each component in a value. The length of this attr must
  // be either 0 or the same as the length of component_types.
  // Shapes of fixed rank but variable size are allowed by setting
  // any shape dimension to -1.  In this case, the inputs' shape may vary along
  // the given dimension, and DequeueMany will pad the given dimension with
  // zeros up to the maximum shape of all elements in the given batch.
  // If the length of this attr is 0, different queue elements may have
  // different ranks and shapes, but only one element may be dequeued at a time.
  // Capacity(int64): Defaults to -1
  //     The upper bound on the number of elements in this queue.
  // Negative numbers mean no limit.
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this queue is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this queue will be shared under the given name
  // across multiple sessions.
  struct Attrs {
    Attrs Shapes(const gtl::ArraySlice<TensorShape>& x) {
      Attrs ret = *this;
      ret.shapes_ = x;
      return ret;
    }

    Attrs Capacity(int64 x) {
      Attrs ret = *this;
      ret.capacity_ = x;
      return ret;
    }

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

    gtl::ArraySlice<TensorShape> shapes_ = {};
    int64 capacity_ = -1;
    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  PaddingFIFOQueue(const ::tensorflow::Scope& scope, const DataTypeSlice&
                 component_types);
  PaddingFIFOQueue(const ::tensorflow::Scope& scope, const DataTypeSlice&
                 component_types, const PaddingFIFOQueue::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs Shapes(const gtl::ArraySlice<TensorShape>& x) {
    return Attrs().Shapes(x);
  }
  static Attrs Capacity(int64 x) {
    return Attrs().Capacity(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output handle;
};

// A queue that produces elements sorted by the first component value.
//
// Note that the PriorityQueue requires the first component of any element
// to be a scalar int64, in addition to the other elements declared by
// component_types.  Therefore calls to Enqueue and EnqueueMany (resp. Dequeue
// and DequeueMany) on a PriorityQueue will all require (resp. output) one extra
// entry in their input (resp. output) lists.
//
// Arguments:
// * scope: A Scope object
// * shapes:
//     The shape of each component in a value. The length of this attr must
// be either 0 or the same as the length of component_types. If the length of
// this attr is 0, the shapes of queue elements are not constrained, and
// only one element may be dequeued at a time.
class PriorityQueue {
 public:
  // Optional attribute setters for PriorityQueue :
  //
  // ComponentTypes(const DataTypeSlice&): Defaults to []
  //     The type of each component in a value.
  // Capacity(int64): Defaults to -1
  //     The upper bound on the number of elements in this queue.
  // Negative numbers mean no limit.
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this queue is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this queue will be shared under the given name
  // across multiple sessions.
  struct Attrs {
    Attrs ComponentTypes(const DataTypeSlice& x) {
      Attrs ret = *this;
      ret.component_types_ = x;
      return ret;
    }

    Attrs Capacity(int64 x) {
      Attrs ret = *this;
      ret.capacity_ = x;
      return ret;
    }

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

    DataTypeSlice component_types_ = {};
    int64 capacity_ = -1;
    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  PriorityQueue(const ::tensorflow::Scope& scope, const
              gtl::ArraySlice<TensorShape>& shapes);
  PriorityQueue(const ::tensorflow::Scope& scope, const
              gtl::ArraySlice<TensorShape>& shapes, const PriorityQueue::Attrs&
              attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs ComponentTypes(const DataTypeSlice& x) {
    return Attrs().ComponentTypes(x);
  }
  static Attrs Capacity(int64 x) {
    return Attrs().Capacity(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output handle;
};

// Closes the given queue.
//
// This operation signals that no more elements will be enqueued in the
// given queue. Subsequent Enqueue(Many) operations will fail.
// Subsequent Dequeue(Many) operations will continue to succeed if
// sufficient elements remain in the queue. Subsequent Dequeue(Many)
// operations that would block will fail immediately.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a queue.
class QueueClose {
 public:
  // Optional attribute setters for QueueClose :
  //
  // CancelPendingEnqueues(bool): Defaults to false
  //     If true, all pending enqueue requests that are
  // blocked on the given queue will be cancelled.
  struct Attrs {
    Attrs CancelPendingEnqueues(bool x) {
      Attrs ret = *this;
      ret.cancel_pending_enqueues_ = x;
      return ret;
    }

    bool cancel_pending_enqueues_ = false;
  };
  QueueClose(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle);
  QueueClose(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
           const QueueClose::Attrs& attrs);
  operator ::tensorflow::ops::Operation() const { return operation; }

  static Attrs CancelPendingEnqueues(bool x) {
    return Attrs().CancelPendingEnqueues(x);
  }

  Operation operation;
};

// Dequeues a tuple of one or more tensors from the given queue.
//
// This operation has k outputs, where k is the number of components
// in the tuples stored in the given queue, and output i is the ith
// component of the dequeued tuple.
//
// N.B. If the queue is empty, this operation will block until an element
// has been dequeued (or 'timeout_ms' elapses, if specified).
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a queue.
// * component_types:
//     The type of each component in a tuple.
class QueueDequeue {
 public:
  // Optional attribute setters for QueueDequeue :
  //
  // TimeoutMs(int64): Defaults to -1
  //     If the queue is empty, this operation will block for up to
  // timeout_ms milliseconds.
  // Note: This option is not supported yet.
  struct Attrs {
    Attrs TimeoutMs(int64 x) {
      Attrs ret = *this;
      ret.timeout_ms_ = x;
      return ret;
    }

    int64 timeout_ms_ = -1;
  };
  QueueDequeue(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
             const DataTypeSlice& component_types);
  QueueDequeue(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
             const DataTypeSlice& component_types, const QueueDequeue::Attrs&
             attrs);
  ::tensorflow::ops::Output operator[](size_t index) const { return components[index]; }


  static Attrs TimeoutMs(int64 x) {
    return Attrs().TimeoutMs(x);
  }

  ::tensorflow::ops::OutputList components;
};

// Dequeues n tuples of one or more tensors from the given queue.
//
// If the queue is closed and there are fewer than n elements, then an
// OutOfRange error is returned.
//
// This operation concatenates queue-element component tensors along the
// 0th dimension to make a single component tensor.  All of the components
// in the dequeued tuple will have size n in the 0th dimension.
//
// This operation has k outputs, where k is the number of components in
// the tuples stored in the given queue, and output i is the ith
// component of the dequeued tuple.
//
// N.B. If the queue is empty, this operation will block until n elements
// have been dequeued (or 'timeout_ms' elapses, if specified).
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a queue.
// * n: The number of tuples to dequeue.
// * component_types:
//     The type of each component in a tuple.
class QueueDequeueMany {
 public:
  // Optional attribute setters for QueueDequeueMany :
  //
  // TimeoutMs(int64): Defaults to -1
  //     If the queue has fewer than n elements, this operation
  // will block for up to timeout_ms milliseconds.
  // Note: This option is not supported yet.
  struct Attrs {
    Attrs TimeoutMs(int64 x) {
      Attrs ret = *this;
      ret.timeout_ms_ = x;
      return ret;
    }

    int64 timeout_ms_ = -1;
  };
  QueueDequeueMany(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, ::tensorflow::ops::Input n, const DataTypeSlice&
                 component_types);
  QueueDequeueMany(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, ::tensorflow::ops::Input n, const DataTypeSlice&
                 component_types, const QueueDequeueMany::Attrs& attrs);
  ::tensorflow::ops::Output operator[](size_t index) const { return components[index]; }


  static Attrs TimeoutMs(int64 x) {
    return Attrs().TimeoutMs(x);
  }

  ::tensorflow::ops::OutputList components;
};

// Dequeues n tuples of one or more tensors from the given queue.
//
// This operation is not supported by all queues.  If a queue does not support
// DequeueUpTo, then an Unimplemented error is returned.
//
// If the queue is closed and there are more than 0 but less than n elements
// remaining, then instead of returning an OutOfRange error like
// QueueDequeueMany, less than `n` elements are returned immediately.  If the queue
// is closed and there are 0 elements left in the queue, then an OutOfRange
// error is returned just like in QueueDequeueMany.  Otherwise the behavior
// is identical to QueueDequeueMany:
//
// This operation concatenates queue-element component tensors along the
// 0th dimension to make a single component tensor.  All of the components
// in the dequeued tuple will have size n in the 0th dimension.
//
// This operation has k outputs, where k is the number of components in
// the tuples stored in the given queue, and output i is the ith
// component of the dequeued tuple.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a queue.
// * n: The number of tuples to dequeue.
// * component_types:
//     The type of each component in a tuple.
class QueueDequeueUpTo {
 public:
  // Optional attribute setters for QueueDequeueUpTo :
  //
  // TimeoutMs(int64): Defaults to -1
  //     If the queue has fewer than n elements, this operation
  // will block for up to timeout_ms milliseconds.
  // Note: This option is not supported yet.
  struct Attrs {
    Attrs TimeoutMs(int64 x) {
      Attrs ret = *this;
      ret.timeout_ms_ = x;
      return ret;
    }

    int64 timeout_ms_ = -1;
  };
  QueueDequeueUpTo(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, ::tensorflow::ops::Input n, const DataTypeSlice&
                 component_types);
  QueueDequeueUpTo(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, ::tensorflow::ops::Input n, const DataTypeSlice&
                 component_types, const QueueDequeueUpTo::Attrs& attrs);
  ::tensorflow::ops::Output operator[](size_t index) const { return components[index]; }


  static Attrs TimeoutMs(int64 x) {
    return Attrs().TimeoutMs(x);
  }

  ::tensorflow::ops::OutputList components;
};

// Enqueues a tuple of one or more tensors in the given queue.
//
// The components input has k elements, which correspond to the components of
// tuples stored in the given queue.
//
// N.B. If the queue is full, this operation will block until the given
// element has been enqueued (or 'timeout_ms' elapses, if specified).
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a queue.
// * components: One or more tensors from which the enqueued tensors should be taken.
class QueueEnqueue {
 public:
  // Optional attribute setters for QueueEnqueue :
  //
  // TimeoutMs(int64): Defaults to -1
  //     If the queue is full, this operation will block for up to
  // timeout_ms milliseconds.
  // Note: This option is not supported yet.
  struct Attrs {
    Attrs TimeoutMs(int64 x) {
      Attrs ret = *this;
      ret.timeout_ms_ = x;
      return ret;
    }

    int64 timeout_ms_ = -1;
  };
  QueueEnqueue(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
             ::tensorflow::ops::InputList components);
  QueueEnqueue(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
             ::tensorflow::ops::InputList components, const
             QueueEnqueue::Attrs& attrs);
  operator ::tensorflow::ops::Operation() const { return operation; }

  static Attrs TimeoutMs(int64 x) {
    return Attrs().TimeoutMs(x);
  }

  Operation operation;
};

// Enqueues zero or more tuples of one or more tensors in the given queue.
//
// This operation slices each component tensor along the 0th dimension to
// make multiple queue elements. All of the tuple components must have the
// same size in the 0th dimension.
//
// The components input has k elements, which correspond to the components of
// tuples stored in the given queue.
//
// N.B. If the queue is full, this operation will block until the given
// elements have been enqueued (or 'timeout_ms' elapses, if specified).
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a queue.
// * components: One or more tensors from which the enqueued tensors should
// be taken.
class QueueEnqueueMany {
 public:
  // Optional attribute setters for QueueEnqueueMany :
  //
  // TimeoutMs(int64): Defaults to -1
  //     If the queue is too full, this operation will block for up
  // to timeout_ms milliseconds.
  // Note: This option is not supported yet.
  struct Attrs {
    Attrs TimeoutMs(int64 x) {
      Attrs ret = *this;
      ret.timeout_ms_ = x;
      return ret;
    }

    int64 timeout_ms_ = -1;
  };
  QueueEnqueueMany(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, ::tensorflow::ops::InputList components);
  QueueEnqueueMany(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, ::tensorflow::ops::InputList components, const
                 QueueEnqueueMany::Attrs& attrs);
  operator ::tensorflow::ops::Operation() const { return operation; }

  static Attrs TimeoutMs(int64 x) {
    return Attrs().TimeoutMs(x);
  }

  Operation operation;
};

// Computes the number of elements in the given queue.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a queue.
class QueueSize {
 public:
  QueueSize(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle);
  operator ::tensorflow::ops::Output() const { return size; }
  operator ::tensorflow::ops::Input() const { return size; }
  ::tensorflow::Node* node() const { return size.node(); }

  ::tensorflow::ops::Output size;
};

// A queue that randomizes the order of elements.
//
// Arguments:
// * scope: A Scope object
// * component_types:
//     The type of each component in a value.
class RandomShuffleQueue {
 public:
  // Optional attribute setters for RandomShuffleQueue :
  //
  // Shapes(const gtl::ArraySlice<TensorShape>&): Defaults to []
  //     The shape of each component in a value. The length of this attr must
  // be either 0 or the same as the length of component_types. If the length of
  // this attr is 0, the shapes of queue elements are not constrained, and
  // only one element may be dequeued at a time.
  // Capacity(int64): Defaults to -1
  //     The upper bound on the number of elements in this queue.
  // Negative numbers mean no limit.
  // MinAfterDequeue(int64): Defaults to 0
  //     Dequeue will block unless there would be this
  // many elements after the dequeue or the queue is closed. This
  // ensures a minimum level of mixing of elements.
  // Seed(int64): Defaults to 0
  //     If either seed or seed2 is set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, a random seed is used.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this queue is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this queue will be shared under the given name
  // across multiple sessions.
  struct Attrs {
    Attrs Shapes(const gtl::ArraySlice<TensorShape>& x) {
      Attrs ret = *this;
      ret.shapes_ = x;
      return ret;
    }

    Attrs Capacity(int64 x) {
      Attrs ret = *this;
      ret.capacity_ = x;
      return ret;
    }

    Attrs MinAfterDequeue(int64 x) {
      Attrs ret = *this;
      ret.min_after_dequeue_ = x;
      return ret;
    }

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

    gtl::ArraySlice<TensorShape> shapes_ = {};
    int64 capacity_ = -1;
    int64 min_after_dequeue_ = 0;
    int64 seed_ = 0;
    int64 seed2_ = 0;
    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  RandomShuffleQueue(const ::tensorflow::Scope& scope, const DataTypeSlice&
                   component_types);
  RandomShuffleQueue(const ::tensorflow::Scope& scope, const DataTypeSlice&
                   component_types, const RandomShuffleQueue::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs Shapes(const gtl::ArraySlice<TensorShape>& x) {
    return Attrs().Shapes(x);
  }
  static Attrs Capacity(int64 x) {
    return Attrs().Capacity(x);
  }
  static Attrs MinAfterDequeue(int64 x) {
    return Attrs().MinAfterDequeue(x);
  }
  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output handle;
};

// Applies a sparse gradient to a given accumulator. Does not add if local_step is
//
// lesser than the accumulator's global_step.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a accumulator.
// * local_step: The local_step value at which the sparse gradient was computed.
// * gradient_indices: Indices of the sparse gradient to be accumulated. Must be a
// vector.
// * gradient_values: Values are the non-zero slices of the gradient, and must have
// the same first dimension as indices, i.e., the nnz represented by indices and
// values must be consistent.
// * gradient_shape: Shape of the sparse gradient to be accumulated.
// * has_known_shape:
//     Boolean indicating whether gradient_shape is unknown, in which
// case the input is ignored during validation.
class SparseAccumulatorApplyGradient {
 public:
  SparseAccumulatorApplyGradient(const ::tensorflow::Scope& scope,
                               ::tensorflow::ops::Input handle,
                               ::tensorflow::ops::Input local_step,
                               ::tensorflow::ops::Input gradient_indices,
                               ::tensorflow::ops::Input gradient_values,
                               ::tensorflow::ops::Input gradient_shape, bool
                               has_known_shape);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Extracts the average sparse gradient in the given SparseConditionalAccumulator,
//
// provided that sufficient (i.e., more than num_required) gradients have been
// accumulated. The op will blocks until sufficient gradients have been
// accumulated. If the accumulator has already aggregated more than num_required
// gradients, it will return its average of the accumulated gradients.
// Also automatically increments the recorded global_step in the accumulator by 1,
// and resets the aggregate to 0.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a SparseConditionalAccumulator.
// * num_required: Number of gradients required before we return an aggregate.
// * dtype:
//     The data type of accumulated gradients. Needs to correspond to the type
// of the accumulator.
class SparseAccumulatorTakeGradient {
 public:
  SparseAccumulatorTakeGradient(const ::tensorflow::Scope& scope,
                              ::tensorflow::ops::Input handle,
                              ::tensorflow::ops::Input num_required, DataType
                              dtype);

  ::tensorflow::ops::Output indices;
  ::tensorflow::ops::Output values;
  ::tensorflow::ops::Output shape;
};

// A conditional accumulator for aggregating sparse gradients. The accumulator
//
// accepts gradients marked with local_step greater or equal to the most recent
// global_step known to the accumulator. The average can be extracted from the
// accumulator, provided sufficient gradients have been accumulated. Extracting the
// average automatically resets the aggregate to 0, and increments the global_step
// recorded by the accumulator.
//
// Arguments:
// * scope: A Scope object
// * dtype:
//     The type of the value being accumulated.
// * shape:
//     The shape of the values.
class SparseConditionalAccumulator {
 public:
  // Optional attribute setters for SparseConditionalAccumulator :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this accumulator is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this accumulator will be shared under the given name
  // across multiple sessions.
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
  SparseConditionalAccumulator(const ::tensorflow::Scope& scope, DataType dtype,
                             TensorShape shape);
  SparseConditionalAccumulator(const ::tensorflow::Scope& scope, DataType dtype,
                             TensorShape shape, const
                             SparseConditionalAccumulator::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output handle;
};

// A stack that produces elements in first-in last-out order.
//
// Arguments:
// * scope: A Scope object
// * elem_type:
//     The type of the elements on the stack.
class Stack {
 public:
  // Optional attribute setters for Stack :
  //
  // StackName(StringPiece): Defaults to ""
  //     Overrides the name used for the temporary stack resource. Default
  // value is the name of the 'Stack' op (which is guaranteed unique).
  struct Attrs {
    Attrs StackName(StringPiece x) {
      Attrs ret = *this;
      ret.stack_name_ = x;
      return ret;
    }

    StringPiece stack_name_ = "";
  };
  Stack(const ::tensorflow::Scope& scope, DataType elem_type);
  Stack(const ::tensorflow::Scope& scope, DataType elem_type, const Stack::Attrs&
      attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs StackName(StringPiece x) {
    return Attrs().StackName(x);
  }

  ::tensorflow::ops::Output handle;
};

// Delete the stack from its resource container.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a stack.
class StackClose {
 public:
  StackClose(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Pop the element at the top of the stack.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a stack.
// * elem_type:
//     The type of the elem that is popped.
class StackPop {
 public:
  StackPop(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
         DataType elem_type);
  operator ::tensorflow::ops::Output() const { return elem; }
  operator ::tensorflow::ops::Input() const { return elem; }
  ::tensorflow::Node* node() const { return elem.node(); }

  ::tensorflow::ops::Output elem;
};

// Push an element onto the stack.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a stack.
// * elem: The tensor to be pushed onto the stack.
class StackPush {
 public:
  // Optional attribute setters for StackPush :
  //
  // SwapMemory(bool): Defaults to false
  //     Swap `elem` to CPU. Default to false.
  struct Attrs {
    Attrs SwapMemory(bool x) {
      Attrs ret = *this;
      ret.swap_memory_ = x;
      return ret;
    }

    bool swap_memory_ = false;
  };
  StackPush(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
          ::tensorflow::ops::Input elem);
  StackPush(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input handle,
          ::tensorflow::ops::Input elem, const StackPush::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs SwapMemory(bool x) {
    return Attrs().SwapMemory(x);
  }

  ::tensorflow::ops::Output output;
};

// An array of Tensors of given size, with data written via Write and read
//
// via Read or Pack.
//
// Arguments:
// * scope: A Scope object
// * size: The size of the array.
// * dtype:
//     The type of the elements on the tensor_array.
class TensorArray {
 public:
  // Optional attribute setters for TensorArray :
  //
  // DynamicSize(bool): Defaults to false
  //     A boolean that determines whether writes to the TensorArray
  // are allowed to grow the size.  By default, this is not allowed.
  // ClearAfterRead(bool): Defaults to true
  //     If true (default), Tensors in the TensorArray are cleared
  // after being read.  This disables multiple read semantics but allows early
  // release of memory.
  // TensorArrayName(StringPiece): Defaults to ""
  //     Overrides the name used for the temporary tensor_array
  // resource. Default value is the name of the 'TensorArray' op (which
  // is guaranteed unique).
  struct Attrs {
    Attrs DynamicSize(bool x) {
      Attrs ret = *this;
      ret.dynamic_size_ = x;
      return ret;
    }

    Attrs ClearAfterRead(bool x) {
      Attrs ret = *this;
      ret.clear_after_read_ = x;
      return ret;
    }

    Attrs TensorArrayName(StringPiece x) {
      Attrs ret = *this;
      ret.tensor_array_name_ = x;
      return ret;
    }

    bool dynamic_size_ = false;
    bool clear_after_read_ = true;
    StringPiece tensor_array_name_ = "";
  };
  TensorArray(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input size,
            DataType dtype);
  TensorArray(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input size,
            DataType dtype, const TensorArray::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return handle; }
  operator ::tensorflow::ops::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  static Attrs DynamicSize(bool x) {
    return Attrs().DynamicSize(x);
  }
  static Attrs ClearAfterRead(bool x) {
    return Attrs().ClearAfterRead(x);
  }
  static Attrs TensorArrayName(StringPiece x) {
    return Attrs().TensorArrayName(x);
  }

  ::tensorflow::ops::Output handle;
};

// Delete the TensorArray from its resource container.  This enables
//
// the user to close and release the resource in the middle of a step/run.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray (output of TensorArray or TensorArrayGrad).
class TensorArrayClose {
 public:
  TensorArrayClose(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Concat the elements from the TensorArray into value `value`.
//
// Takes `T` elements of shapes
//
//   ```
//   (n0 x d0 x d1 x ...), (n1 x d0 x d1 x ...), ..., (n(T-1) x d0 x d1 x ...)
//   ```
//
// and concatenates them into a Tensor of shape:
//
//   ```(n0 + n1 + ... + n(T-1) x d0 x d1 x ...)```
//
// All elements must have the same shape (excepting the first dimension).
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray.
// * flow_in: A float scalar that enforces proper chaining of operations.
// * dtype:
//     The type of the elem that is returned.
class TensorArrayConcat {
 public:
  // Optional attribute setters for TensorArrayConcat :
  //
  // ElementShapeExcept0(TensorShape): Defaults to <unknown>
  //     The expected shape of an element, if known,
  // excluding the first dimension. Used to validate the shapes of
  // TensorArray elements. If this shape is not fully specified, concatenating
  // zero-size TensorArrays is an error.
  struct Attrs {
    Attrs ElementShapeExcept0(TensorShape x) {
      Attrs ret = *this;
      ret.element_shape_except0_ = x;
      return ret;
    }

    TensorShape element_shape_except0_ = {};
  };
  TensorArrayConcat(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  handle, ::tensorflow::ops::Input flow_in, DataType dtype);
  TensorArrayConcat(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  handle, ::tensorflow::ops::Input flow_in, DataType dtype,
                  const TensorArrayConcat::Attrs& attrs);

  static Attrs ElementShapeExcept0(TensorShape x) {
    return Attrs().ElementShapeExcept0(x);
  }

  ::tensorflow::ops::Output value;
  ::tensorflow::ops::Output lengths;
};

// Gather specific elements from the TensorArray into output `value`.
//
// All elements selected by `indices` must have the same shape.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray.
// * indices: The locations in the TensorArray from which to read tensor elements.
// * flow_in: A float scalar that enforces proper chaining of operations.
// * dtype:
//     The type of the elem that is returned.
class TensorArrayGather {
 public:
  // Optional attribute setters for TensorArrayGather :
  //
  // ElementShape(TensorShape): Defaults to <unknown>
  //     The expected shape of an element, if known. Used to
  // validate the shapes of TensorArray elements. If this shape is not
  // fully specified, gathering zero-size TensorArrays is an error.
  struct Attrs {
    Attrs ElementShape(TensorShape x) {
      Attrs ret = *this;
      ret.element_shape_ = x;
      return ret;
    }

    TensorShape element_shape_ = {};
  };
  TensorArrayGather(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  handle, ::tensorflow::ops::Input indices,
                  ::tensorflow::ops::Input flow_in, DataType dtype);
  TensorArrayGather(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  handle, ::tensorflow::ops::Input indices,
                  ::tensorflow::ops::Input flow_in, DataType dtype, const
                  TensorArrayGather::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return value; }
  operator ::tensorflow::ops::Input() const { return value; }
  ::tensorflow::Node* node() const { return value.node(); }

  static Attrs ElementShape(TensorShape x) {
    return Attrs().ElementShape(x);
  }

  ::tensorflow::ops::Output value;
};

// Creates a TensorArray for storing the gradients of values in the given handle.
//
// If the given TensorArray gradient already exists, returns a reference to it.
//
// Locks the size of the original TensorArray by disabling its dynamic size flag.
//
// **A note about the input flow_in:**
//
// The handle flow_in forces the execution of the gradient lookup to occur
// only after certain other operations have occurred.  For example, when
// the forward TensorArray is dynamically sized, writes to this TensorArray
// may resize the object.  The gradient TensorArray is statically sized based
// on the size of the forward TensorArray when this operation executes.
// Furthermore, the size of the forward TensorArray is frozen by this call.
// As a result, the flow is used to ensure that the call to generate the gradient
// TensorArray only happens after all writes are executed.
//
// In the case of dynamically sized TensorArrays, gradient computation should
// only be performed on read operations that have themselves been chained via
// flow to occur only after all writes have executed. That way the final size
// of the forward TensorArray is known when this operation is called.
//
// **A note about the source attribute:**
//
// TensorArray gradient calls use an accumulator TensorArray object.  If
// multiple gradients are calculated and run in the same session, the multiple
// gradient nodes may accidentally flow throuth the same accumulator TensorArray.
// This double counts and generally breaks the TensorArray gradient flow.
//
// The solution is to identify which gradient call this particular
// TensorArray gradient is being called in.  This is performed by identifying
// a unique string (e.g. "gradients", "gradients_1", ...) from the input
// gradient Tensor's name.  This string is used as a suffix when creating
// the TensorArray gradient object here (the attribute `source`).
//
// The attribute `source` is added as a suffix to the forward TensorArray's
// name when performing the creation / lookup, so that each separate gradient
// calculation gets its own TensorArray accumulator.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to the forward TensorArray.
// * flow_in: A float scalar that enforces proper chaining of operations.
// * source:
//     The gradient source string, used to decide which gradient TensorArray
// to return.
class TensorArrayGrad {
 public:
  TensorArrayGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                handle, ::tensorflow::ops::Input flow_in, StringPiece source);
  operator ::tensorflow::ops::Output() const { return grad_handle; }
  operator ::tensorflow::ops::Input() const { return grad_handle; }
  ::tensorflow::Node* node() const { return grad_handle.node(); }

  ::tensorflow::ops::Output grad_handle;
};

// Pack the elements from the TensorArray into output `value`.
//
// **WARNING: This op is deprecated.**
//
// Instead of this op, use `TensorArrayGather` with
// `indices = RangeOp(0, TensorArraySizeOp)`.
//
// All elements must have the same shape.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray.
// * flow_in: A float scalar that enforces proper chaining of operations.
// * dtype:
//     The type of the elem that is returned.
class TensorArrayPack {
 public:
  // Optional attribute setters for TensorArrayPack :
  //
  // ElementShape(TensorShape): Defaults to <unknown>
  //     The expected shape of an element, if known. Used to
  // validate the shapes of TensorArray elements. If this shape is not
  // fully specified, packing zero-size TensorArrays is an error.
  struct Attrs {
    Attrs ElementShape(TensorShape x) {
      Attrs ret = *this;
      ret.element_shape_ = x;
      return ret;
    }

    TensorShape element_shape_ = {};
  };
  TensorArrayPack(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                handle, ::tensorflow::ops::Input flow_in, DataType dtype);
  TensorArrayPack(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                handle, ::tensorflow::ops::Input flow_in, DataType dtype, const
                TensorArrayPack::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return value; }
  operator ::tensorflow::ops::Input() const { return value; }
  ::tensorflow::Node* node() const { return value.node(); }

  static Attrs ElementShape(TensorShape x) {
    return Attrs().ElementShape(x);
  }

  ::tensorflow::ops::Output value;
};

// Read an element from the TensorArray into output `value`.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray.
// * flow_in: A float scalar that enforces proper chaining of operations.
// * dtype:
//     The type of the elem that is returned.
class TensorArrayRead {
 public:
  TensorArrayRead(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                handle, ::tensorflow::ops::Input index,
                ::tensorflow::ops::Input flow_in, DataType dtype);
  operator ::tensorflow::ops::Output() const { return value; }
  operator ::tensorflow::ops::Input() const { return value; }
  ::tensorflow::Node* node() const { return value.node(); }

  ::tensorflow::ops::Output value;
};

// Scatter the data from the input value into specific TensorArray elements.
//
// `indices` must be a vector, its length must match the first dim of `value`.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray.
// * indices: The locations at which to write the tensor elements.
// * value: The concatenated tensor to write to the TensorArray.
// * flow_in: A float scalar that enforces proper chaining of operations.
class TensorArrayScatter {
 public:
  TensorArrayScatter(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   handle, ::tensorflow::ops::Input indices,
                   ::tensorflow::ops::Input value, ::tensorflow::ops::Input
                   flow_in);
  operator ::tensorflow::ops::Output() const { return flow_out; }
  operator ::tensorflow::ops::Input() const { return flow_out; }
  ::tensorflow::Node* node() const { return flow_out.node(); }

  ::tensorflow::ops::Output flow_out;
};

// Get the current size of the TensorArray.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray (output of TensorArray or TensorArrayGrad).
// * flow_in: A float scalar that enforces proper chaining of operations.
class TensorArraySize {
 public:
  TensorArraySize(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                handle, ::tensorflow::ops::Input flow_in);
  operator ::tensorflow::ops::Output() const { return size; }
  operator ::tensorflow::ops::Input() const { return size; }
  ::tensorflow::Node* node() const { return size.node(); }

  ::tensorflow::ops::Output size;
};

// Split the data from the input value into TensorArray elements.
//
// Assuming that `lengths` takes on values
//
//   ```(n0, n1, ..., n(T-1))```
//
// and that `value` has shape
//
//   ```(n0 + n1 + ... + n(T-1) x d0 x d1 x ...)```,
//
// this splits values into a TensorArray with T tensors.
//
// TensorArray index t will be the subtensor of values with starting position
//
//   ```(n0 + n1 + ... + n(t-1), 0, 0, ...)```
//
// and having size
//
//   ```nt x d0 x d1 x ...```
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray.
// * value: The concatenated tensor to write to the TensorArray.
// * lengths: The vector of lengths, how to split the rows of value into the
// TensorArray.
// * flow_in: A float scalar that enforces proper chaining of operations.
class TensorArraySplit {
 public:
  TensorArraySplit(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, ::tensorflow::ops::Input value,
                 ::tensorflow::ops::Input lengths, ::tensorflow::ops::Input
                 flow_in);
  operator ::tensorflow::ops::Output() const { return flow_out; }
  operator ::tensorflow::ops::Input() const { return flow_out; }
  ::tensorflow::Node* node() const { return flow_out.node(); }

  ::tensorflow::ops::Output flow_out;
};

// Unpack the data from the input value into TensorArray elements.
//
// **WARNING: This op is deprecated.**
//
// Instead of this op, use `TensorArrayScatter` with
// `indices = RangeOp(0, SizeOp(value)[0])`.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray.
// * value: The concatenated tensor to write to the TensorArray.
// * flow_in: A float scalar that enforces proper chaining of operations.
class TensorArrayUnpack {
 public:
  TensorArrayUnpack(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  handle, ::tensorflow::ops::Input value,
                  ::tensorflow::ops::Input flow_in);
  operator ::tensorflow::ops::Output() const { return flow_out; }
  operator ::tensorflow::ops::Input() const { return flow_out; }
  ::tensorflow::Node* node() const { return flow_out.node(); }

  ::tensorflow::ops::Output flow_out;
};

// Push an element onto the tensor_array.
//
// Arguments:
// * scope: A Scope object
// * handle: The handle to a TensorArray.
// * index: The position to write to inside the TensorArray.
// * value: The tensor to write to the TensorArray.
// * flow_in: A float scalar that enforces proper chaining of operations.
class TensorArrayWrite {
 public:
  TensorArrayWrite(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 handle, ::tensorflow::ops::Input index,
                 ::tensorflow::ops::Input value, ::tensorflow::ops::Input
                 flow_in);
  operator ::tensorflow::ops::Output() const { return flow_out; }
  operator ::tensorflow::ops::Input() const { return flow_out; }
  ::tensorflow::Node* node() const { return flow_out.node(); }

  ::tensorflow::ops::Output flow_out;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_DATA_FLOW_OPS_H_
