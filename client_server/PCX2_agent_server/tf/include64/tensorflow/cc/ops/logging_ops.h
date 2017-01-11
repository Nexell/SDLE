// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_LOGGING_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_LOGGING_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Asserts that the given condition is true.
//
// If `condition` evaluates to false, print the list of tensors in `data`.
// `summarize` determines how many entries of the tensors to print.
//
// Arguments:
// * scope: A Scope object
// * condition: The condition to evaluate.
// * data: The tensors to print out when condition is false.
class Assert {
 public:
  // Optional attribute setters for Assert :
  //
  // Summarize(int64): Defaults to 3
  //     Print this many entries of each tensor.
  struct Attrs {
    Attrs Summarize(int64 x) {
      Attrs ret = *this;
      ret.summarize_ = x;
      return ret;
    }

    int64 summarize_ = 3;
  };
  Assert(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input condition,
       ::tensorflow::ops::InputList data);
  Assert(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input condition,
       ::tensorflow::ops::InputList data, const Assert::Attrs& attrs);
  operator ::tensorflow::ops::Operation() const { return operation; }

  static Attrs Summarize(int64 x) {
    return Attrs().Summarize(x);
  }

  Operation operation;
};

// Outputs a `Summary` protocol buffer with audio.
//
// DEPRECATED at GraphDef version 15:
// Use AudioSummaryV2..
//
// The summary has up to `max_outputs` summary values containing audio. The
// audio is built from `tensor` which must be 3-D with shape `[batch_size,
// frames, channels]` or 2-D with shape `[batch_size, frames]`. The values are
// assumed to be in the range of `[-1.0, 1.0]` with a sample rate of `sample_rate`.
//
// The `tag` argument is a scalar `Tensor` of type `string`.  It is used to
// build the `tag` of the summary values:
//
// *  If `max_outputs` is 1, the summary value tag is '*tag*/audio'.
// *  If `max_outputs` is greater than 1, the summary value tags are
//    generated sequentially as '*tag*/audio/0', '*tag*/audio/1', etc.
//
// Arguments:
// * scope: A Scope object
// * tag: Scalar. Used to build the `tag` attribute of the summary values.
// * tensor: 2-D of shape `[batch_size, frames]`.
// * sample_rate:
//     The sample rate of the signal in hertz.
class AudioSummary {
 public:
  // Optional attribute setters for AudioSummary :
  //
  // MaxOutputs(int64): Defaults to 3
  //     Max number of batch elements to generate audio for.
  struct Attrs {
    Attrs MaxOutputs(int64 x) {
      Attrs ret = *this;
      ret.max_outputs_ = x;
      return ret;
    }

    int64 max_outputs_ = 3;
  };
  AudioSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input tag,
             ::tensorflow::ops::Input tensor, float sample_rate);
  AudioSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input tag,
             ::tensorflow::ops::Input tensor, float sample_rate, const
             AudioSummary::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return summary; }
  operator ::tensorflow::ops::Input() const { return summary; }
  ::tensorflow::Node* node() const { return summary.node(); }

  static Attrs MaxOutputs(int64 x) {
    return Attrs().MaxOutputs(x);
  }

  ::tensorflow::ops::Output summary;
};

// Outputs a `Summary` protocol buffer with audio.
//
// The summary has up to `max_outputs` summary values containing audio. The
// audio is built from `tensor` which must be 3-D with shape `[batch_size,
// frames, channels]` or 2-D with shape `[batch_size, frames]`. The values are
// assumed to be in the range of `[-1.0, 1.0]` with a sample rate of `sample_rate`.
//
// The `tag` argument is a scalar `Tensor` of type `string`.  It is used to
// build the `tag` of the summary values:
//
// *  If `max_outputs` is 1, the summary value tag is '*tag*/audio'.
// *  If `max_outputs` is greater than 1, the summary value tags are
//    generated sequentially as '*tag*/audio/0', '*tag*/audio/1', etc.
//
// Arguments:
// * scope: A Scope object
// * tag: Scalar. Used to build the `tag` attribute of the summary values.
// * tensor: 2-D of shape `[batch_size, frames]`.
// * sample_rate: The sample rate of the signal in hertz.
class AudioSummaryV2 {
 public:
  // Optional attribute setters for AudioSummaryV2 :
  //
  // MaxOutputs(int64): Defaults to 3
  //     Max number of batch elements to generate audio for.
  struct Attrs {
    Attrs MaxOutputs(int64 x) {
      Attrs ret = *this;
      ret.max_outputs_ = x;
      return ret;
    }

    int64 max_outputs_ = 3;
  };
  AudioSummaryV2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input tag,
               ::tensorflow::ops::Input tensor, ::tensorflow::ops::Input
               sample_rate);
  AudioSummaryV2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input tag,
               ::tensorflow::ops::Input tensor, ::tensorflow::ops::Input
               sample_rate, const AudioSummaryV2::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return summary; }
  operator ::tensorflow::ops::Input() const { return summary; }
  ::tensorflow::Node* node() const { return summary.node(); }

  static Attrs MaxOutputs(int64 x) {
    return Attrs().MaxOutputs(x);
  }

  ::tensorflow::ops::Output summary;
};

// Outputs a `Summary` protocol buffer with a histogram.
//
// The generated
// [`Summary`](https://www.tensorflow.org/code/tensorflow/core/framework/summary.proto)
// has one summary value containing a histogram for `values`.
//
// This op reports an `InvalidArgument` error if any value is not finite.
//
// Arguments:
// * scope: A Scope object
// * tag: Scalar.  Tag to use for the `Summary.Value`.
// * values: Any shape. Values to use to build the histogram.
class HistogramSummary {
 public:
  HistogramSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 tag, ::tensorflow::ops::Input values);
  operator ::tensorflow::ops::Output() const { return summary; }
  operator ::tensorflow::ops::Input() const { return summary; }
  ::tensorflow::Node* node() const { return summary.node(); }

  ::tensorflow::ops::Output summary;
};

// Outputs a `Summary` protocol buffer with images.
//
// The summary has up to `max_images` summary values containing images. The
// images are built from `tensor` which must be 4-D with shape `[batch_size,
// height, width, channels]` and where `channels` can be:
//
// *  1: `tensor` is interpreted as Grayscale.
// *  3: `tensor` is interpreted as RGB.
// *  4: `tensor` is interpreted as RGBA.
//
// The images have the same number of channels as the input tensor. For float
// input, the values are normalized one image at a time to fit in the range
// `[0, 255]`.  `uint8` values are unchanged.  The op uses two different
// normalization algorithms:
//
// *  If the input values are all positive, they are rescaled so the largest one
//    is 255.
//
// *  If any input value is negative, the values are shifted so input value 0.0
//    is at 127.  They are then rescaled so that either the smallest value is 0,
//    or the largest one is 255.
//
// The `tag` argument is a scalar `Tensor` of type `string`.  It is used to
// build the `tag` of the summary values:
//
// *  If `max_images` is 1, the summary value tag is '*tag*/image'.
// *  If `max_images` is greater than 1, the summary value tags are
//    generated sequentially as '*tag*/image/0', '*tag*/image/1', etc.
//
// The `bad_color` argument is the color to use in the generated images for
// non-finite input values.  It is a `unit8` 1-D tensor of length `channels`.
// Each element must be in the range `[0, 255]` (It represents the value of a
// pixel in the output image).  Non-finite values in the input tensor are
// replaced by this tensor in the output image.  The default value is the color
// red.
//
// Arguments:
// * scope: A Scope object
// * tag: Scalar. Used to build the `tag` attribute of the summary values.
// * tensor: 4-D of shape `[batch_size, height, width, channels]` where
// `channels` is 1, 3, or 4.
class ImageSummary {
 public:
  // Optional attribute setters for ImageSummary :
  //
  // MaxImages(int64): Defaults to 3
  //     Max number of batch elements to generate images for.
  // BadColor(const TensorProto&): Defaults to Tensor<type: uint8 shape: [4] values: 255 0 0...>
  //     Color to use for pixels with non-finite values.
  struct Attrs {
    Attrs MaxImages(int64 x) {
      Attrs ret = *this;
      ret.max_images_ = x;
      return ret;
    }

    Attrs BadColor(const TensorProto& x) {
      Attrs ret = *this;
      ret.bad_color_ = x;
      return ret;
    }

    int64 max_images_ = 3;
    TensorProto bad_color_ = Input::Initializer({255, 0, 0, 255}, {4}).AsTensorProto();
  };
  ImageSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input tag,
             ::tensorflow::ops::Input tensor);
  ImageSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input tag,
             ::tensorflow::ops::Input tensor, const ImageSummary::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return summary; }
  operator ::tensorflow::ops::Input() const { return summary; }
  ::tensorflow::Node* node() const { return summary.node(); }

  static Attrs MaxImages(int64 x) {
    return Attrs().MaxImages(x);
  }
  static Attrs BadColor(const TensorProto& x) {
    return Attrs().BadColor(x);
  }

  ::tensorflow::ops::Output summary;
};

// Merges summaries.
//
// This op creates a
// [`Summary`](https://www.tensorflow.org/code/tensorflow/core/framework/summary.proto)
// protocol buffer that contains the union of all the values in the input
// summaries.
//
// When the Op is run, it reports an `InvalidArgument` error if multiple values
// in the summaries to merge use the same tag.
//
// Arguments:
// * scope: A Scope object
// * inputs: Can be of any shape.  Each must contain serialized `Summary` protocol
// buffers.
class MergeSummary {
 public:
  MergeSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::InputList
             inputs);
  operator ::tensorflow::ops::Output() const { return summary; }
  operator ::tensorflow::ops::Input() const { return summary; }
  ::tensorflow::Node* node() const { return summary.node(); }

  ::tensorflow::ops::Output summary;
};

// Prints a list of tensors.
//
// Passes `input` through to `output` and prints `data` when evaluating.
//
// Arguments:
// * scope: A Scope object
// * input: The tensor passed to `output`
// * data: A list of tensors to print out when op is evaluated.
class Print {
 public:
  // Optional attribute setters for Print :
  //
  // Message(StringPiece): Defaults to ""
  //     A string, prefix of the error message.
  // FirstN(int64): Defaults to -1
  //     Only log `first_n` number of times. -1 disables logging.
  // Summarize(int64): Defaults to 3
  //     Only print this many entries of each tensor.
  struct Attrs {
    Attrs Message(StringPiece x) {
      Attrs ret = *this;
      ret.message_ = x;
      return ret;
    }

    Attrs FirstN(int64 x) {
      Attrs ret = *this;
      ret.first_n_ = x;
      return ret;
    }

    Attrs Summarize(int64 x) {
      Attrs ret = *this;
      ret.summarize_ = x;
      return ret;
    }

    StringPiece message_ = "";
    int64 first_n_ = -1;
    int64 summarize_ = 3;
  };
  Print(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
      ::tensorflow::ops::InputList data);
  Print(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
      ::tensorflow::ops::InputList data, const Print::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Message(StringPiece x) {
    return Attrs().Message(x);
  }
  static Attrs FirstN(int64 x) {
    return Attrs().FirstN(x);
  }
  static Attrs Summarize(int64 x) {
    return Attrs().Summarize(x);
  }

  ::tensorflow::ops::Output output;
};

// Outputs a `Summary` protocol buffer with scalar values.
//
// The input `tags` and `values` must have the same shape.  The generated summary
// has a summary value for each tag-value pair in `tags` and `values`.
//
// Arguments:
// * scope: A Scope object
// * tags: Tags for the summary.
// * values: Same shape as `tags.  Values for the summary.
class ScalarSummary {
 public:
  ScalarSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input tags,
              ::tensorflow::ops::Input values);
  operator ::tensorflow::ops::Output() const { return summary; }
  operator ::tensorflow::ops::Input() const { return summary; }
  ::tensorflow::Node* node() const { return summary.node(); }

  ::tensorflow::ops::Output summary;
};

// Outputs a `Summary` protocol buffer with a tensor.
//
// Arguments:
// * scope: A Scope object
// * tensor: A tensor to serialize.
class TensorSummary {
 public:
  // Optional attribute setters for TensorSummary :
  //
  // Description(StringPiece): Defaults to ""
  //     A json-encoded SummaryDescription proto.
  // Labels(const gtl::ArraySlice<string>&): Defaults to []
  //     An unused list of strings.
  // DisplayName(StringPiece): Defaults to ""
  //     An unused string.
  struct Attrs {
    Attrs Description(StringPiece x) {
      Attrs ret = *this;
      ret.description_ = x;
      return ret;
    }

    Attrs Labels(const gtl::ArraySlice<string>& x) {
      Attrs ret = *this;
      ret.labels_ = x;
      return ret;
    }

    Attrs DisplayName(StringPiece x) {
      Attrs ret = *this;
      ret.display_name_ = x;
      return ret;
    }

    StringPiece description_ = "";
    gtl::ArraySlice<string> labels_ = {};
    StringPiece display_name_ = "";
  };
  TensorSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              tensor);
  TensorSummary(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              tensor, const TensorSummary::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return summary; }
  operator ::tensorflow::ops::Input() const { return summary; }
  ::tensorflow::Node* node() const { return summary.node(); }

  static Attrs Description(StringPiece x) {
    return Attrs().Description(x);
  }
  static Attrs Labels(const gtl::ArraySlice<string>& x) {
    return Attrs().Labels(x);
  }
  static Attrs DisplayName(StringPiece x) {
    return Attrs().DisplayName(x);
  }

  ::tensorflow::ops::Output summary;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_LOGGING_OPS_H_
