// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_SDCA_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_SDCA_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Computes fingerprints of the input strings.
//
// Arguments:
// * scope: A Scope object
// * input: vector of strings to compute fingerprints on.
class SdcaFprint {
 public:
  SdcaFprint(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Distributed version of Stochastic Dual Coordinate Ascent (SDCA) optimizer for
//
// linear models with L1 + L2 regularization. As global optimization objective is
// strongly-convex, the optimizer optimizes the dual objective at each step. The
// optimizer applies each update one example at a time. Examples are sampled
// uniformly, and the optimizer is learning rate free and enjoys linear convergence
// rate.
//
// Proximal Stochastic Dual Coordinate Ascent, Shalev-Shwartz, Shai; Zhang, Tong.
// 2012 arXiv1211.2717S: http://arxiv.org/pdf/1211.2717v1.pdf
//
//   Loss objective = \sum f_{i}(wx_{i}) + (l2 / 2) * |w|^2 + l1 * |w|
//
// Adding vs. Averaging in Distributed Primal-Dual Optimization.
// Chenxin Ma, Virginia Smith, Martin Jaggi, Michael I. Jordan, Peter Richtarik,
// Martin Takac http://arxiv.org/abs/1502.03508
//
// Stochastic Dual Coordinate Ascent with Adaptive Probabilities
// Dominik Csiba, Zheng Qu, Peter Richtarik https://arxiv.org/abs/1502.08053
//
// Arguments:
// * scope: A Scope object
// * sparse_example_indices: a list of vectors which contain example indices.
// * sparse_feature_indices: a list of vectors which contain feature indices.
// * sparse_feature_values: a list of vectors which contains feature value
// associated with each feature group.
// * dense_features: a list of matrices which contains the dense feature values.
// * example_weights: a vector which contains the weight associated with each
// example.
// * example_labels: a vector which contains the label/target associated with each
// example.
// * sparse_indices: a list of vectors where each value is the indices which has
// corresponding weights in sparse_weights. This field maybe ommitted for the
// dense approach.
// * sparse_weights: a list of vectors where each value is the weight associated with
// a sparse feature group.
// * dense_weights: a list of vectors where the values are the weights associated
// with a dense feature group.
// * example_state_data: a list of vectors containing the example state data.
// * loss_type:
//     Type of the primal loss. Currently SdcaSolver supports logistic,
// squared and hinge losses.
// * l1:
//     Symmetric l1 regularization strength.
// * l2:
//     Symmetric l2 regularization strength.
// * num_loss_partitions:
//     Number of partitions of the global loss function.
// * num_inner_iterations:
//     Number of iterations per mini-batch.
class SdcaOptimizer {
 public:
  // Optional attribute setters for SdcaOptimizer :
  //
  // Adaptative(bool): Defaults to false
  //     Whether to use Adapative SDCA for the inner loop.
  struct Attrs {
    Attrs Adaptative(bool x) {
      Attrs ret = *this;
      ret.adaptative_ = x;
      return ret;
    }

    bool adaptative_ = false;
  };
  SdcaOptimizer(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList
              sparse_example_indices, ::tensorflow::ops::InputList
              sparse_feature_indices, ::tensorflow::ops::InputList
              sparse_feature_values, ::tensorflow::ops::InputList
              dense_features, ::tensorflow::ops::Input example_weights,
              ::tensorflow::ops::Input example_labels,
              ::tensorflow::ops::InputList sparse_indices,
              ::tensorflow::ops::InputList sparse_weights,
              ::tensorflow::ops::InputList dense_weights,
              ::tensorflow::ops::Input example_state_data, StringPiece
              loss_type, float l1, float l2, int64 num_loss_partitions, int64
              num_inner_iterations);
  SdcaOptimizer(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList
              sparse_example_indices, ::tensorflow::ops::InputList
              sparse_feature_indices, ::tensorflow::ops::InputList
              sparse_feature_values, ::tensorflow::ops::InputList
              dense_features, ::tensorflow::ops::Input example_weights,
              ::tensorflow::ops::Input example_labels,
              ::tensorflow::ops::InputList sparse_indices,
              ::tensorflow::ops::InputList sparse_weights,
              ::tensorflow::ops::InputList dense_weights,
              ::tensorflow::ops::Input example_state_data, StringPiece
              loss_type, float l1, float l2, int64 num_loss_partitions, int64
              num_inner_iterations, const SdcaOptimizer::Attrs& attrs);

  static Attrs Adaptative(bool x) {
    return Attrs().Adaptative(x);
  }

  ::tensorflow::ops::Output out_example_state_data;
  ::tensorflow::ops::OutputList out_delta_sparse_weights;
  ::tensorflow::ops::OutputList out_delta_dense_weights;
};

// Applies L1 regularization shrink step on the parameters.
//
// Arguments:
// * scope: A Scope object
// * weights: a list of vectors where each value is the weight associated with a
// feature group.
// * l1:
//     Symmetric l1 regularization strength.
// * l2:
//     Symmetric l2 regularization strength. Should be a positive float.
class SdcaShrinkL1 {
 public:
  SdcaShrinkL1(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList
             weights, float l1, float l2);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_SDCA_OPS_H_
