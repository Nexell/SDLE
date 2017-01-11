// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CTC_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CTC_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Performs beam search decoding on the logits given in input.
//
// A note about the attribute merge_repeated: For the beam search decoder,
// this means that if consecutive entries in a beam are the same, only
// the first of these is emitted.  That is, when the top path is "A B B B B",
// "A B" is returned if merge_repeated = True but "A B B B B" is
// returned if merge_repeated = False.
//
// Arguments:
// * scope: A Scope object
// * inputs: 3-D, shape: `(max_time x batch_size x num_classes)`, the logits.
// * sequence_length: A vector containing sequence lengths, size `(batch)`.
// * beam_width:
//     A scalar >= 0 (beam search beam width).
// * top_paths:
//     A scalar >= 0, <= beam_width (controls output size).
class CTCBeamSearchDecoder {
 public:
  // Optional attribute setters for CTCBeamSearchDecoder :
  //
  // MergeRepeated(bool): Defaults to true
  //     If true, merge repeated classes in output.
  struct Attrs {
    Attrs MergeRepeated(bool x) {
      Attrs ret = *this;
      ret.merge_repeated_ = x;
      return ret;
    }

    bool merge_repeated_ = true;
  };
  CTCBeamSearchDecoder(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     inputs, ::tensorflow::ops::Input sequence_length, int64
                     beam_width, int64 top_paths);
  CTCBeamSearchDecoder(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     inputs, ::tensorflow::ops::Input sequence_length, int64
                     beam_width, int64 top_paths, const
                     CTCBeamSearchDecoder::Attrs& attrs);

  static Attrs MergeRepeated(bool x) {
    return Attrs().MergeRepeated(x);
  }

  ::tensorflow::ops::OutputList decoded_indices;
  ::tensorflow::ops::OutputList decoded_values;
  ::tensorflow::ops::OutputList decoded_shape;
  ::tensorflow::ops::Output log_probability;
};

// Performs greedy decoding on the logits given in inputs.
//
// A note about the attribute merge_repeated: if enabled, when
// consecutive logits' maximum indices are the same, only the first of
// these is emitted.  Labeling the blank '*', the sequence "A B B * B B"
// becomes "A B" if merge_repeated = True and "A B B B B" if
// merge_repeated = False.
//
// Regardless of the value of merge_repeated, if the maximum index of a given
// time and batch corresponds to the blank, index `(num_classes - 1)`, no new
// element is emitted.
//
// Arguments:
// * scope: A Scope object
// * inputs: 3-D, shape: `(max_time x batch_size x num_classes)`, the logits.
// * sequence_length: A vector containing sequence lengths, size `(batch_size)`.
class CTCGreedyDecoder {
 public:
  // Optional attribute setters for CTCGreedyDecoder :
  //
  // MergeRepeated(bool): Defaults to false
  //     If True, merge repeated classes in output.
  struct Attrs {
    Attrs MergeRepeated(bool x) {
      Attrs ret = *this;
      ret.merge_repeated_ = x;
      return ret;
    }

    bool merge_repeated_ = false;
  };
  CTCGreedyDecoder(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 inputs, ::tensorflow::ops::Input sequence_length);
  CTCGreedyDecoder(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 inputs, ::tensorflow::ops::Input sequence_length, const
                 CTCGreedyDecoder::Attrs& attrs);

  static Attrs MergeRepeated(bool x) {
    return Attrs().MergeRepeated(x);
  }

  ::tensorflow::ops::Output decoded_indices;
  ::tensorflow::ops::Output decoded_values;
  ::tensorflow::ops::Output decoded_shape;
  ::tensorflow::ops::Output log_probability;
};

// Calculates the CTC Loss (log probability) for each batch entry.  Also calculates
//
// the gradient.  This class performs the softmax operation for you, so inputs
// should be e.g. linear projections of outputs by an LSTM.
//
// Arguments:
// * scope: A Scope object
// * inputs: 3-D, shape: `(max_time x batch_size x num_classes)`, the logits.
// * labels_indices: The indices of a `SparseTensor<int32, 2>`.
// `labels_indices(i, :) == [b, t]` means `labels_values(i)` stores the id for
// `(batch b, time t)`.
// * labels_values: The values (labels) associated with the given batch and time.
// * sequence_length: A vector containing sequence lengths (batch).
class CTCLoss {
 public:
  // Optional attribute setters for CTCLoss :
  //
  // PreprocessCollapseRepeated(bool): Defaults to false
  //     Scalar, if true then repeated labels are
  // collapsed prior to the CTC calculation.
  // CtcMergeRepeated(bool): Defaults to true
  //     Scalar.  If set to false, *during* CTC calculation
  // repeated non-blank labels will not be merged and are interpreted as
  // individual labels.  This is a simplified version of CTC.
  struct Attrs {
    Attrs PreprocessCollapseRepeated(bool x) {
      Attrs ret = *this;
      ret.preprocess_collapse_repeated_ = x;
      return ret;
    }

    Attrs CtcMergeRepeated(bool x) {
      Attrs ret = *this;
      ret.ctc_merge_repeated_ = x;
      return ret;
    }

    bool preprocess_collapse_repeated_ = false;
    bool ctc_merge_repeated_ = true;
  };
  CTCLoss(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input inputs,
        ::tensorflow::ops::Input labels_indices, ::tensorflow::ops::Input
        labels_values, ::tensorflow::ops::Input sequence_length);
  CTCLoss(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input inputs,
        ::tensorflow::ops::Input labels_indices, ::tensorflow::ops::Input
        labels_values, ::tensorflow::ops::Input sequence_length, const
        CTCLoss::Attrs& attrs);

  static Attrs PreprocessCollapseRepeated(bool x) {
    return Attrs().PreprocessCollapseRepeated(x);
  }
  static Attrs CtcMergeRepeated(bool x) {
    return Attrs().CtcMergeRepeated(x);
  }

  ::tensorflow::ops::Output loss;
  ::tensorflow::ops::Output gradient;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CTC_OPS_H_
