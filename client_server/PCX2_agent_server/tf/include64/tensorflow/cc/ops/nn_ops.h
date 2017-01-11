// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_NN_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_NN_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Performs average pooling on the input.
//
// Each entry in `output` is the mean of the corresponding size `ksize`
// window in `value`.
//
// Arguments:
// * scope: A Scope object
// * value: 4-D with shape `[batch, height, width, channels]`.
// * ksize:
//     The size of the sliding window for each dimension of `value`.
// * strides:
//     The stride of the sliding window for each dimension of `value`.
// * padding:
//     The type of padding algorithm to use.
class AvgPool {
 public:
  // Optional attribute setters for AvgPool :
  //
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the data is stored in the order of:
  //     [batch, in_height, in_width, in_channels].
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  struct Attrs {
    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    StringPiece data_format_ = "NHWC";
  };
  AvgPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input value, const
        gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>& strides,
        StringPiece padding);
  AvgPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input value, const
        gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>& strides,
        StringPiece padding, const AvgPool::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// Performs 3D average pooling on the input.
//
// Arguments:
// * scope: A Scope object
// * input: Shape `[batch, depth, rows, cols, channels]` tensor to pool over.
// * ksize:
//     1-D tensor of length 5. The size of the window for each dimension of
// the input tensor. Must have `ksize[0] = ksize[4] = 1`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class AvgPool3D {
 public:
  AvgPool3D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
          const gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>&
          strides, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes gradients of average pooling function.
//
// Arguments:
// * scope: A Scope object
// * orig_input_shape: The original input dimensions.
// * grad: Output backprop of shape `[batch, depth, rows, cols, channels]`.
// * ksize:
//     1-D tensor of length 5. The size of the window for each dimension of
// the input tensor. Must have `ksize[0] = ksize[4] = 1`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class AvgPool3DGrad {
 public:
  AvgPool3DGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              orig_input_shape, ::tensorflow::ops::Input grad, const
              gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>& strides,
              StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes gradients of the average pooling function.
//
// Arguments:
// * scope: A Scope object
// * orig_input_shape: 1-D.  Shape of the original input to `avg_pool`.
// * grad: 4-D with shape `[batch, height, width, channels]`.  Gradients w.r.t.
// the output of `avg_pool`.
// * ksize:
//     The size of the sliding window for each dimension of the input.
// * strides:
//     The stride of the sliding window for each dimension of the input.
// * padding:
//     The type of padding algorithm to use.
class AvgPoolGrad {
 public:
  // Optional attribute setters for AvgPoolGrad :
  //
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the data is stored in the order of:
  //     [batch, in_height, in_width, in_channels].
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  struct Attrs {
    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    StringPiece data_format_ = "NHWC";
  };
  AvgPoolGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
            orig_input_shape, ::tensorflow::ops::Input grad, const
            gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>& strides,
            StringPiece padding);
  AvgPoolGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
            orig_input_shape, ::tensorflow::ops::Input grad, const
            gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>& strides,
            StringPiece padding, const AvgPoolGrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// Batch normalization.
//
// DEPRECATED at GraphDef version 9:
// Use tf.nn.batch_normalization().
//
// This op is deprecated. Prefer `tf.nn.batch_normalization`.
//
// Arguments:
// * scope: A Scope object
// * t: A 4D input Tensor.
// * m: A 1D mean Tensor with size matching the last dimension of t.
// This is the first output from tf.nn.moments,
// or a saved moving average thereof.
// * v: A 1D variance Tensor with size matching the last dimension of t.
// This is the second output from tf.nn.moments,
// or a saved moving average thereof.
// * beta: A 1D beta Tensor with size matching the last dimension of t.
// An offset to be added to the normalized tensor.
// * gamma: A 1D gamma Tensor with size matching the last dimension of t.
// If "scale_after_normalization" is true, this tensor will be multiplied
// with the normalized tensor.
// * variance_epsilon:
//     A small float number to avoid dividing by 0.
// * scale_after_normalization:
//     A bool indicating whether the resulted tensor
// needs to be multiplied with gamma.
class BatchNormWithGlobalNormalization {
 public:
  BatchNormWithGlobalNormalization(const ::tensorflow::Scope& scope,
                                 ::tensorflow::ops::Input t,
                                 ::tensorflow::ops::Input m,
                                 ::tensorflow::ops::Input v,
                                 ::tensorflow::ops::Input beta,
                                 ::tensorflow::ops::Input gamma, float
                                 variance_epsilon, bool
                                 scale_after_normalization);
  operator ::tensorflow::ops::Output() const { return result; }
  operator ::tensorflow::ops::Input() const { return result; }
  ::tensorflow::Node* node() const { return result.node(); }

  ::tensorflow::ops::Output result;
};

// Gradients for batch normalization.
//
// DEPRECATED at GraphDef version 9:
// Use tf.nn.batch_normalization().
//
// This op is deprecated. See `tf.nn.batch_normalization`.
//
// Arguments:
// * scope: A Scope object
// * t: A 4D input Tensor.
// * m: A 1D mean Tensor with size matching the last dimension of t.
// This is the first output from tf.nn.moments,
// or a saved moving average thereof.
// * v: A 1D variance Tensor with size matching the last dimension of t.
// This is the second output from tf.nn.moments,
// or a saved moving average thereof.
// * gamma: A 1D gamma Tensor with size matching the last dimension of t.
// If "scale_after_normalization" is true, this Tensor will be multiplied
// with the normalized Tensor.
// * backprop: 4D backprop Tensor.
// * variance_epsilon:
//     A small float number to avoid dividing by 0.
// * scale_after_normalization:
//     A bool indicating whether the resulted tensor
// needs to be multiplied with gamma.
class BatchNormWithGlobalNormalizationGrad {
 public:
  BatchNormWithGlobalNormalizationGrad(const ::tensorflow::Scope& scope,
                                     ::tensorflow::ops::Input t,
                                     ::tensorflow::ops::Input m,
                                     ::tensorflow::ops::Input v,
                                     ::tensorflow::ops::Input gamma,
                                     ::tensorflow::ops::Input backprop, float
                                     variance_epsilon, bool
                                     scale_after_normalization);

  ::tensorflow::ops::Output dx;
  ::tensorflow::ops::Output dm;
  ::tensorflow::ops::Output dv;
  ::tensorflow::ops::Output db;
  ::tensorflow::ops::Output dg;
};

// Adds `bias` to `value`.
//
// This is a special case of `tf.add` where `bias` is restricted to be 1-D.
// Broadcasting is supported, so `value` may have any number of dimensions.
//
// Arguments:
// * scope: A Scope object
// * value: Any number of dimensions.
// * bias: 1-D with size the last dimension of `value`.
class BiasAdd {
 public:
  // Optional attribute setters for BiasAdd :
  //
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the bias tensor will be added to the last dimension
  // of the value tensor.
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  // The tensor will be added to "in_channels", the third-to-the-last
  //     dimension.
  struct Attrs {
    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    StringPiece data_format_ = "NHWC";
  };
  BiasAdd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input value,
        ::tensorflow::ops::Input bias);
  BiasAdd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input value,
        ::tensorflow::ops::Input bias, const BiasAdd::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// The backward operation for "BiasAdd" on the "bias" tensor.
//
// It accumulates all the values from out_backprop into the feature dimension.
// For NHWC data format, the feature dimension is the last. For NCHW data format,
// the feature dimension is the third-to-last.
//
// Arguments:
// * scope: A Scope object
// * out_backprop: Any number of dimensions.
class BiasAddGrad {
 public:
  // Optional attribute setters for BiasAddGrad :
  //
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the bias tensor will be added to the last dimension
  // of the value tensor.
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  // The tensor will be added to "in_channels", the third-to-the-last
  //     dimension.
  struct Attrs {
    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    StringPiece data_format_ = "NHWC";
  };
  BiasAddGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
            out_backprop);
  BiasAddGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
            out_backprop, const BiasAddGrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// Adds `bias` to `value`.
//
// This is a deprecated version of BiasAdd and will be soon removed.
//
// This is a special case of `tf.add` where `bias` is restricted to be 1-D.
// Broadcasting is supported, so `value` may have any number of dimensions.
//
// Arguments:
// * scope: A Scope object
// * value: Any number of dimensions.
// * bias: 1-D with size the last dimension of `value`.
class BiasAddV1 {
 public:
  BiasAddV1(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input value,
          ::tensorflow::ops::Input bias);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes a 2-D convolution given 4-D `input` and `filter` tensors.
//
// Given an input tensor of shape `[batch, in_height, in_width, in_channels]`
// and a filter / kernel tensor of shape
// `[filter_height, filter_width, in_channels, out_channels]`, this op
// performs the following:
//
// 1. Flattens the filter to a 2-D matrix with shape
//    `[filter_height * filter_width * in_channels, output_channels]`.
// 2. Extracts image patches from the input tensor to form a *virtual*
//    tensor of shape `[batch, out_height, out_width,
//    filter_height * filter_width * in_channels]`.
// 3. For each patch, right-multiplies the filter matrix and the image patch
//    vector.
//
// In detail, with the default NHWC format,
//
//     output[b, i, j, k] =
//         sum_{di, dj, q} input[b, strides[1] * i + di, strides[2] * j + dj, q] *
//                         filter[di, dj, q, k]
//
// Must have `strides[0] = strides[3] = 1`.  For the most common case of the same
// horizontal and vertices strides, `strides = [1, stride, stride, 1]`.
//
// Arguments:
// * scope: A Scope object
// * strides:
//     1-D of length 4.  The stride of the sliding window for each dimension
// of `input`. Must be in the same order as the dimension specified with format.
// * padding:
//     The type of padding algorithm to use.
class Conv2D {
 public:
  // Optional attribute setters for Conv2D :
  //
  // UseCudnnOnGpu(bool): Defaults to true
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the data is stored in the order of:
  //     [batch, in_height, in_width, in_channels].
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  struct Attrs {
    Attrs UseCudnnOnGpu(bool x) {
      Attrs ret = *this;
      ret.use_cudnn_on_gpu_ = x;
      return ret;
    }

    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    bool use_cudnn_on_gpu_ = true;
    StringPiece data_format_ = "NHWC";
  };
  Conv2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
       ::tensorflow::ops::Input filter, const gtl::ArraySlice<int>& strides,
       StringPiece padding);
  Conv2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
       ::tensorflow::ops::Input filter, const gtl::ArraySlice<int>& strides,
       StringPiece padding, const Conv2D::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs UseCudnnOnGpu(bool x) {
    return Attrs().UseCudnnOnGpu(x);
  }
  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes the gradients of convolution with respect to the filter.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, in_height, in_width, in_channels]`.
// * filter_sizes: An integer vector representing the tensor shape of `filter`,
// where `filter` is a 4-D
// `[filter_height, filter_width, in_channels, out_channels]` tensor.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, out_channels]`.
// Gradients w.r.t. the output of the convolution.
// * strides:
//     The stride of the sliding window for each dimension of the input
// of the convolution. Must be in the same order as the dimension specified with
// format.
// * padding:
//     The type of padding algorithm to use.
class Conv2DBackpropFilter {
 public:
  // Optional attribute setters for Conv2DBackpropFilter :
  //
  // UseCudnnOnGpu(bool): Defaults to true
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the data is stored in the order of:
  //     [batch, in_height, in_width, in_channels].
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  struct Attrs {
    Attrs UseCudnnOnGpu(bool x) {
      Attrs ret = *this;
      ret.use_cudnn_on_gpu_ = x;
      return ret;
    }

    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    bool use_cudnn_on_gpu_ = true;
    StringPiece data_format_ = "NHWC";
  };
  Conv2DBackpropFilter(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     input, ::tensorflow::ops::Input filter_sizes,
                     ::tensorflow::ops::Input out_backprop, const
                     gtl::ArraySlice<int>& strides, StringPiece padding);
  Conv2DBackpropFilter(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     input, ::tensorflow::ops::Input filter_sizes,
                     ::tensorflow::ops::Input out_backprop, const
                     gtl::ArraySlice<int>& strides, StringPiece padding, const
                     Conv2DBackpropFilter::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs UseCudnnOnGpu(bool x) {
    return Attrs().UseCudnnOnGpu(x);
  }
  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes the gradients of convolution with respect to the input.
//
// Arguments:
// * scope: A Scope object
// * input_sizes: An integer vector representing the shape of `input`,
// where `input` is a 4-D `[batch, height, width, channels]` tensor.
// * filter: 4-D with shape
// `[filter_height, filter_width, in_channels, out_channels]`.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, out_channels]`.
// Gradients w.r.t. the output of the convolution.
// * strides:
//     The stride of the sliding window for each dimension of the input
// of the convolution. Must be in the same order as the dimension specified with
// format.
// * padding:
//     The type of padding algorithm to use.
class Conv2DBackpropInput {
 public:
  // Optional attribute setters for Conv2DBackpropInput :
  //
  // UseCudnnOnGpu(bool): Defaults to true
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the data is stored in the order of:
  //     [batch, in_height, in_width, in_channels].
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  struct Attrs {
    Attrs UseCudnnOnGpu(bool x) {
      Attrs ret = *this;
      ret.use_cudnn_on_gpu_ = x;
      return ret;
    }

    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    bool use_cudnn_on_gpu_ = true;
    StringPiece data_format_ = "NHWC";
  };
  Conv2DBackpropInput(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    input_sizes, ::tensorflow::ops::Input filter,
                    ::tensorflow::ops::Input out_backprop, const
                    gtl::ArraySlice<int>& strides, StringPiece padding);
  Conv2DBackpropInput(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    input_sizes, ::tensorflow::ops::Input filter,
                    ::tensorflow::ops::Input out_backprop, const
                    gtl::ArraySlice<int>& strides, StringPiece padding, const
                    Conv2DBackpropInput::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs UseCudnnOnGpu(bool x) {
    return Attrs().UseCudnnOnGpu(x);
  }
  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes a 3-D convolution given 5-D `input` and `filter` tensors.
//
// In signal processing, cross-correlation is a measure of similarity of
// two waveforms as a function of a time-lag applied to one of them. This
// is also known as a sliding dot product or sliding inner-product.
//
// Our Conv3D implements a form of cross-correlation.
//
// Arguments:
// * scope: A Scope object
// * input: Shape `[batch, in_depth, in_height, in_width, in_channels]`.
// * filter: Shape `[filter_depth, filter_height, filter_width, in_channels,
// out_channels]`. `in_channels` must match between `input` and `filter`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class Conv3D {
 public:
  Conv3D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
       ::tensorflow::ops::Input filter, const gtl::ArraySlice<int>& strides,
       StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the gradients of 3-D convolution with respect to the filter.
//
// DEPRECATED at GraphDef version 10:
// Use Conv3DBackpropFilterV2.
//
// Arguments:
// * scope: A Scope object
// * input: Shape `[batch, depth, rows, cols, in_channels]`.
// * filter: Shape `[depth, rows, cols, in_channels, out_channels]`.
// `in_channels` must match between `input` and `filter`.
// * out_backprop: Backprop signal of shape `[batch, out_depth, out_rows, out_cols,
// out_channels]`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class Conv3DBackpropFilter {
 public:
  Conv3DBackpropFilter(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     input, ::tensorflow::ops::Input filter,
                     ::tensorflow::ops::Input out_backprop, const
                     gtl::ArraySlice<int>& strides, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the gradients of 3-D convolution with respect to the filter.
//
// Arguments:
// * scope: A Scope object
// * input: Shape `[batch, depth, rows, cols, in_channels]`.
// * filter_sizes: An integer vector representing the tensor shape of `filter`,
// where `filter` is a 5-D
// `[filter_depth, filter_height, filter_width, in_channels, out_channels]`
// tensor.
// * out_backprop: Backprop signal of shape `[batch, out_depth, out_rows, out_cols,
// out_channels]`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class Conv3DBackpropFilterV2 {
 public:
  Conv3DBackpropFilterV2(const ::tensorflow::Scope& scope,
                       ::tensorflow::ops::Input input, ::tensorflow::ops::Input
                       filter_sizes, ::tensorflow::ops::Input out_backprop,
                       const gtl::ArraySlice<int>& strides, StringPiece
                       padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the gradients of 3-D convolution with respect to the input.
//
// DEPRECATED at GraphDef version 10:
// Use Conv3DBackpropInputV2.
//
// Arguments:
// * scope: A Scope object
// * input: Shape `[batch, depth, rows, cols, in_channels]`.
// * filter: Shape `[depth, rows, cols, in_channels, out_channels]`.
// `in_channels` must match between `input` and `filter`.
// * out_backprop: Backprop signal of shape `[batch, out_depth, out_rows, out_cols,
// out_channels]`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class Conv3DBackpropInput {
 public:
  Conv3DBackpropInput(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    input, ::tensorflow::ops::Input filter,
                    ::tensorflow::ops::Input out_backprop, const
                    gtl::ArraySlice<int>& strides, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the gradients of 3-D convolution with respect to the input.
//
// Arguments:
// * scope: A Scope object
// * input_sizes: An integer vector representing the tensor shape of `input`,
// where `input` is a 5-D
// `[batch, depth, rows, cols, in_channels]` tensor.
// * filter: Shape `[depth, rows, cols, in_channels, out_channels]`.
// `in_channels` must match between `input` and `filter`.
// * out_backprop: Backprop signal of shape `[batch, out_depth, out_rows, out_cols,
// out_channels]`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class Conv3DBackpropInputV2 {
 public:
  Conv3DBackpropInputV2(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input input_sizes,
                      ::tensorflow::ops::Input filter, ::tensorflow::ops::Input
                      out_backprop, const gtl::ArraySlice<int>& strides,
                      StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes a 2-D depthwise convolution given 4-D `input` and `filter` tensors.
//
// Given an input tensor of shape `[batch, in_height, in_width, in_channels]`
// and a filter / kernel tensor of shape
// `[filter_height, filter_width, in_channels, channel_multiplier]`, containing
// `in_channels` convolutional filters of depth 1, `depthwise_conv2d` applies
// a different filter to each input channel (expanding from 1 channel to
// `channel_multiplier` channels for each), then concatenates the results
// together. Thus, the output has `in_channels * channel_multiplier` channels.
//
// for k in 0..in_channels-1
//   for q in 0..channel_multiplier-1
//     output[b, i, j, k * channel_multiplier + q] =
//       sum_{di, dj} input[b, strides[1] * i + di, strides[2] * j + dj, k] *
//                         filter[di, dj, k, q]
//
// Must have `strides[0] = strides[3] = 1`.  For the most common case of the same
// horizontal and vertices strides, `strides = [1, stride, stride, 1]`.
//
// Arguments:
// * scope: A Scope object
// * strides:
//     1-D of length 4.  The stride of the sliding window for each dimension
// of `input`.
// * padding:
//     The type of padding algorithm to use.
class DepthwiseConv2dNative {
 public:
  DepthwiseConv2dNative(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input input, ::tensorflow::ops::Input
                      filter, const gtl::ArraySlice<int>& strides, StringPiece
                      padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the gradients of depthwise convolution with respect to the filter.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, in_height, in_width, in_channels]`.
// * filter_sizes: An integer vector representing the tensor shape of `filter`,
// where `filter` is a 4-D
// `[filter_height, filter_width, in_channels, depthwise_multiplier]` tensor.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, out_channels]`.
// Gradients w.r.t. the output of the convolution.
// * strides:
//     The stride of the sliding window for each dimension of the input
// of the convolution.
// * padding:
//     The type of padding algorithm to use.
class DepthwiseConv2dNativeBackpropFilter {
 public:
  DepthwiseConv2dNativeBackpropFilter(const ::tensorflow::Scope& scope,
                                    ::tensorflow::ops::Input input,
                                    ::tensorflow::ops::Input filter_sizes,
                                    ::tensorflow::ops::Input out_backprop,
                                    const gtl::ArraySlice<int>& strides,
                                    StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the gradients of depthwise convolution with respect to the input.
//
// Arguments:
// * scope: A Scope object
// * input_sizes: An integer vector representing the shape of `input`,
// where `input` is a 4-D `[batch, height, width, channels]` tensor.
// * filter: 4-D with shape
// `[filter_height, filter_width, in_channels, depthwise_multiplier]`.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, out_channels]`.
// Gradients w.r.t. the output of the convolution.
// * strides:
//     The stride of the sliding window for each dimension of the input
// of the convolution.
// * padding:
//     The type of padding algorithm to use.
class DepthwiseConv2dNativeBackpropInput {
 public:
  DepthwiseConv2dNativeBackpropInput(const ::tensorflow::Scope& scope,
                                   ::tensorflow::ops::Input input_sizes,
                                   ::tensorflow::ops::Input filter,
                                   ::tensorflow::ops::Input out_backprop, const
                                   gtl::ArraySlice<int>& strides, StringPiece
                                   padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the grayscale dilation of 4-D `input` and 3-D `filter` tensors.
//
// The `input` tensor has shape `[batch, in_height, in_width, depth]` and the
// `filter` tensor has shape `[filter_height, filter_width, depth]`, i.e., each
// input channel is processed independently of the others with its own structuring
// function. The `output` tensor has shape
// `[batch, out_height, out_width, depth]`. The spatial dimensions of the output
// tensor depend on the `padding` algorithm. We currently only support the default
// "NHWC" `data_format`.
//
// In detail, the grayscale morphological 2-D dilation is the max-sum correlation
// (for consistency with `conv2d`, we use unmirrored filters):
//
//     output[b, y, x, c] =
//        max_{dy, dx} input[b,
//                           strides[1] * y + rates[1] * dy,
//                           strides[2] * x + rates[2] * dx,
//                           c] +
//                     filter[dy, dx, c]
//
// Max-pooling is a special case when the filter has size equal to the pooling
// kernel size and contains all zeros.
//
// Note on duality: The dilation of `input` by the `filter` is equal to the
// negation of the erosion of `-input` by the reflected `filter`.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, in_height, in_width, depth]`.
// * filter: 3-D with shape `[filter_height, filter_width, depth]`.
// * strides:
//     The stride of the sliding window for each dimension of the input
// tensor. Must be: `[1, stride_height, stride_width, 1]`.
// * rates:
//     The input stride for atrous morphological dilation. Must be:
// `[1, rate_height, rate_width, 1]`.
// * padding:
//     The type of padding algorithm to use.
class Dilation2D {
 public:
  Dilation2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
           ::tensorflow::ops::Input filter, const gtl::ArraySlice<int>&
           strides, const gtl::ArraySlice<int>& rates, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the gradient of morphological 2-D dilation with respect to the filter.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, in_height, in_width, depth]`.
// * filter: 3-D with shape `[filter_height, filter_width, depth]`.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, depth]`.
// * strides:
//     1-D of length 4. The stride of the sliding window for each dimension of
// the input tensor. Must be: `[1, stride_height, stride_width, 1]`.
// * rates:
//     1-D of length 4. The input stride for atrous morphological dilation.
// Must be: `[1, rate_height, rate_width, 1]`.
// * padding:
//     The type of padding algorithm to use.
class Dilation2DBackpropFilter {
 public:
  Dilation2DBackpropFilter(const ::tensorflow::Scope& scope,
                         ::tensorflow::ops::Input input,
                         ::tensorflow::ops::Input filter,
                         ::tensorflow::ops::Input out_backprop, const
                         gtl::ArraySlice<int>& strides, const
                         gtl::ArraySlice<int>& rates, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return filter_backprop; }
  operator ::tensorflow::ops::Input() const { return filter_backprop; }
  ::tensorflow::Node* node() const { return filter_backprop.node(); }

  ::tensorflow::ops::Output filter_backprop;
};

// Computes the gradient of morphological 2-D dilation with respect to the input.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, in_height, in_width, depth]`.
// * filter: 3-D with shape `[filter_height, filter_width, depth]`.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, depth]`.
// * strides:
//     1-D of length 4. The stride of the sliding window for each dimension of
// the input tensor. Must be: `[1, stride_height, stride_width, 1]`.
// * rates:
//     1-D of length 4. The input stride for atrous morphological dilation.
// Must be: `[1, rate_height, rate_width, 1]`.
// * padding:
//     The type of padding algorithm to use.
class Dilation2DBackpropInput {
 public:
  Dilation2DBackpropInput(const ::tensorflow::Scope& scope,
                        ::tensorflow::ops::Input input,
                        ::tensorflow::ops::Input filter,
                        ::tensorflow::ops::Input out_backprop, const
                        gtl::ArraySlice<int>& strides, const
                        gtl::ArraySlice<int>& rates, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return in_backprop; }
  operator ::tensorflow::ops::Input() const { return in_backprop; }
  ::tensorflow::Node* node() const { return in_backprop.node(); }

  ::tensorflow::ops::Output in_backprop;
};

// Computes exponential linear: `exp(features) - 1` if < 0, `features` otherwise.
//
// See [Fast and Accurate Deep Network Learning by Exponential Linear Units (ELUs)
// ](http://arxiv.org/abs/1511.07289)
//
// Arguments:
// * scope: A Scope object
class Elu {
 public:
  Elu(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return activations; }
  operator ::tensorflow::ops::Input() const { return activations; }
  ::tensorflow::Node* node() const { return activations.node(); }

  ::tensorflow::ops::Output activations;
};

// Computes gradients for the exponential linear (Elu) operation.
//
// Arguments:
// * scope: A Scope object
// * gradients: The backpropagated gradients to the corresponding Elu operation.
// * outputs: The outputs of the corresponding Elu operation.
class EluGrad {
 public:
  EluGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input gradients,
        ::tensorflow::ops::Input outputs);
  operator ::tensorflow::ops::Output() const { return backprops; }
  operator ::tensorflow::ops::Input() const { return backprops; }
  ::tensorflow::Node* node() const { return backprops.node(); }

  ::tensorflow::ops::Output backprops;
};

// Performs fractional average pooling on the input.
//
// Fractional average pooling is similar to Fractional max pooling in the pooling
// region generation step. The only difference is that after pooling regions are
// generated, a mean operation is performed instead of a max operation in each
// pooling region.
//
// Arguments:
// * scope: A Scope object
// * value: 4-D with shape `[batch, height, width, channels]`.
// * pooling_ratio:
//     Pooling ratio for each dimension of `value`, currently only
// supports row and col dimension and should be >= 1.0. For example, a valid
// pooling ratio looks like [1.0, 1.44, 1.73, 1.0]. The first and last elements
// must be 1.0 because we don't allow pooling on batch and channels
// dimensions. 1.44 and 1.73 are pooling ratio on height and width dimensions
// respectively.
class FractionalAvgPool {
 public:
  // Optional attribute setters for FractionalAvgPool :
  //
  // PseudoRandom(bool): Defaults to false
  //     When set to True, generates the pooling sequence in a
  // pseudorandom fashion, otherwise, in a random fashion. Check paper [Benjamin
  // Graham, Fractional Max-Pooling](http://arxiv.org/abs/1412.6071) for
  // difference between pseudorandom and random.
  // Overlapping(bool): Defaults to false
  //     When set to True, it means when pooling, the values at the boundary
  // of adjacent pooling cells are used by both cells. For example:
  //
  // `index  0  1  2  3  4`
  //
  // `value  20 5  16 3  7`
  //
  // If the pooling sequence is [0, 2, 4], then 16, at index 2 will be used twice.
  // The result would be [41/3, 26/3] for fractional avg pooling.
  // Deterministic(bool): Defaults to false
  //     When set to True, a fixed pooling region will be used when
  // iterating over a FractionalAvgPool node in the computation graph. Mainly used
  // in unit test to make FractionalAvgPool deterministic.
  // Seed(int64): Defaults to 0
  //     If either seed or seed2 are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     An second seed to avoid seed collision.
  struct Attrs {
    Attrs PseudoRandom(bool x) {
      Attrs ret = *this;
      ret.pseudo_random_ = x;
      return ret;
    }

    Attrs Overlapping(bool x) {
      Attrs ret = *this;
      ret.overlapping_ = x;
      return ret;
    }

    Attrs Deterministic(bool x) {
      Attrs ret = *this;
      ret.deterministic_ = x;
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

    bool pseudo_random_ = false;
    bool overlapping_ = false;
    bool deterministic_ = false;
    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  FractionalAvgPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  value, const gtl::ArraySlice<float>& pooling_ratio);
  FractionalAvgPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  value, const gtl::ArraySlice<float>& pooling_ratio, const
                  FractionalAvgPool::Attrs& attrs);

  static Attrs PseudoRandom(bool x) {
    return Attrs().PseudoRandom(x);
  }
  static Attrs Overlapping(bool x) {
    return Attrs().Overlapping(x);
  }
  static Attrs Deterministic(bool x) {
    return Attrs().Deterministic(x);
  }
  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output row_pooling_sequence;
  ::tensorflow::ops::Output col_pooling_sequence;
};

// Computes gradient of the FractionalAvgPool function.
//
// Unlike FractionalMaxPoolGrad, we don't need to find arg_max for
// FractionalAvgPoolGrad, we just need to evenly back-propagate each element of
// out_backprop to those indices that form the same pooling cell. Therefore, we
// just need to know the shape of original input tensor, instead of the whole
// tensor.
//
// Arguments:
// * scope: A Scope object
// * orig_input_tensor_shape: Original input tensor shape for `fractional_avg_pool`
// * out_backprop: 4-D with shape `[batch, height, width, channels]`.  Gradients
// w.r.t. the output of `fractional_avg_pool`.
// * row_pooling_sequence: row pooling sequence, form pooling region with
// col_pooling_sequence.
// * col_pooling_sequence: column pooling sequence, form pooling region with
// row_pooling sequence.
class FractionalAvgPoolGrad {
 public:
  // Optional attribute setters for FractionalAvgPoolGrad :
  //
  // Overlapping(bool): Defaults to false
  //     When set to True, it means when pooling, the values at the boundary
  // of adjacent pooling cells are used by both cells. For example:
  //
  // `index  0  1  2  3  4`
  //
  // `value  20 5  16 3  7`
  //
  // If the pooling sequence is [0, 2, 4], then 16, at index 2 will be used twice.
  // The result would be [41/3, 26/3] for fractional avg pooling.
  struct Attrs {
    Attrs Overlapping(bool x) {
      Attrs ret = *this;
      ret.overlapping_ = x;
      return ret;
    }

    bool overlapping_ = false;
  };
  FractionalAvgPoolGrad(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input orig_input_tensor_shape,
                      ::tensorflow::ops::Input out_backprop,
                      ::tensorflow::ops::Input row_pooling_sequence,
                      ::tensorflow::ops::Input col_pooling_sequence);
  FractionalAvgPoolGrad(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input orig_input_tensor_shape,
                      ::tensorflow::ops::Input out_backprop,
                      ::tensorflow::ops::Input row_pooling_sequence,
                      ::tensorflow::ops::Input col_pooling_sequence, const
                      FractionalAvgPoolGrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Overlapping(bool x) {
    return Attrs().Overlapping(x);
  }

  ::tensorflow::ops::Output output;
};

// Performs fractional max pooling on the input.
//
// Fractional max pooling is slightly different than regular max pooling.  In
// regular max pooling, you downsize an input set by taking the maximum value of
// smaller N x N subsections of the set (often 2x2), and try to reduce the set by
// a factor of N, where N is an integer.  Fractional max pooling, as you might
// expect from the word "fractional", means that the overall reduction ratio N
// does not have to be an integer.
//
// The sizes of the pooling regions are generated randomly but are fairly uniform.
// For example, let's look at the height dimension, and the constraints on the
// list of rows that will be pool boundaries.
//
// First we define the following:
//
// 1.  input_row_length : the number of rows from the input set
// 2.  output_row_length : which will be smaller than the input
// 3.  alpha = input_row_length / output_row_length : our reduction ratio
// 4.  K = floor(alpha)
// 5.  row_pooling_sequence : this is the result list of pool boundary rows
//
// Then, row_pooling_sequence should satisfy:
//
// 1.  a[0] = 0 : the first value of the sequence is 0
// 2.  a[end] = input_row_length : the last value of the sequence is the size
// 3.  K <= (a[i+1] - a[i]) <= K+1 : all intervals are K or K+1 size
// 4.  length(row_pooling_sequence) = output_row_length+1
//
// For more details on fractional max pooling, see this paper:
// [Benjamin Graham, Fractional Max-Pooling](http://arxiv.org/abs/1412.6071)
//
// Arguments:
// * scope: A Scope object
// * value: 4-D with shape `[batch, height, width, channels]`.
// * pooling_ratio:
//     Pooling ratio for each dimension of `value`, currently only
// supports row and col dimension and should be >= 1.0. For example, a valid
// pooling ratio looks like [1.0, 1.44, 1.73, 1.0]. The first and last elements
// must be 1.0 because we don't allow pooling on batch and channels
// dimensions. 1.44 and 1.73 are pooling ratio on height and width dimensions
// respectively.
class FractionalMaxPool {
 public:
  // Optional attribute setters for FractionalMaxPool :
  //
  // PseudoRandom(bool): Defaults to false
  //     When set to True, generates the pooling sequence in a
  // pseudorandom fashion, otherwise, in a random fashion. Check paper [Benjamin
  // Graham, Fractional Max-Pooling](http://arxiv.org/abs/1412.6071) for
  // difference between pseudorandom and random.
  // Overlapping(bool): Defaults to false
  //     When set to True, it means when pooling, the values at the boundary
  // of adjacent pooling cells are used by both cells. For example:
  //
  // `index  0  1  2  3  4`
  //
  // `value  20 5  16 3  7`
  //
  // If the pooling sequence is [0, 2, 4], then 16, at index 2 will be used twice.
  // The result would be [20, 16] for fractional max pooling.
  // Deterministic(bool): Defaults to false
  //     When set to True, a fixed pooling region will be used when
  // iterating over a FractionalMaxPool node in the computation graph. Mainly used
  // in unit test to make FractionalMaxPool deterministic.
  // Seed(int64): Defaults to 0
  //     If either seed or seed2 are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     An second seed to avoid seed collision.
  struct Attrs {
    Attrs PseudoRandom(bool x) {
      Attrs ret = *this;
      ret.pseudo_random_ = x;
      return ret;
    }

    Attrs Overlapping(bool x) {
      Attrs ret = *this;
      ret.overlapping_ = x;
      return ret;
    }

    Attrs Deterministic(bool x) {
      Attrs ret = *this;
      ret.deterministic_ = x;
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

    bool pseudo_random_ = false;
    bool overlapping_ = false;
    bool deterministic_ = false;
    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  FractionalMaxPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  value, const gtl::ArraySlice<float>& pooling_ratio);
  FractionalMaxPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  value, const gtl::ArraySlice<float>& pooling_ratio, const
                  FractionalMaxPool::Attrs& attrs);

  static Attrs PseudoRandom(bool x) {
    return Attrs().PseudoRandom(x);
  }
  static Attrs Overlapping(bool x) {
    return Attrs().Overlapping(x);
  }
  static Attrs Deterministic(bool x) {
    return Attrs().Deterministic(x);
  }
  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output row_pooling_sequence;
  ::tensorflow::ops::Output col_pooling_sequence;
};

// Computes gradient of the FractionalMaxPool function.
//
// Arguments:
// * scope: A Scope object
// * orig_input: Original input for `fractional_max_pool`
// * orig_output: Original output for `fractional_max_pool`
// * out_backprop: 4-D with shape `[batch, height, width, channels]`.  Gradients
// w.r.t. the output of `fractional_max_pool`.
// * row_pooling_sequence: row pooling sequence, form pooling region with
// col_pooling_sequence.
// * col_pooling_sequence: column pooling sequence, form pooling region with
// row_pooling sequence.
class FractionalMaxPoolGrad {
 public:
  // Optional attribute setters for FractionalMaxPoolGrad :
  //
  // Overlapping(bool): Defaults to false
  //     When set to True, it means when pooling, the values at the boundary
  // of adjacent pooling cells are used by both cells. For example:
  //
  // `index  0  1  2  3  4`
  //
  // `value  20 5  16 3  7`
  //
  // If the pooling sequence is [0, 2, 4], then 16, at index 2 will be used twice.
  // The result would be [20, 16] for fractional max pooling.
  struct Attrs {
    Attrs Overlapping(bool x) {
      Attrs ret = *this;
      ret.overlapping_ = x;
      return ret;
    }

    bool overlapping_ = false;
  };
  FractionalMaxPoolGrad(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input orig_input,
                      ::tensorflow::ops::Input orig_output,
                      ::tensorflow::ops::Input out_backprop,
                      ::tensorflow::ops::Input row_pooling_sequence,
                      ::tensorflow::ops::Input col_pooling_sequence);
  FractionalMaxPoolGrad(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input orig_input,
                      ::tensorflow::ops::Input orig_output,
                      ::tensorflow::ops::Input out_backprop,
                      ::tensorflow::ops::Input row_pooling_sequence,
                      ::tensorflow::ops::Input col_pooling_sequence, const
                      FractionalMaxPoolGrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Overlapping(bool x) {
    return Attrs().Overlapping(x);
  }

  ::tensorflow::ops::Output output;
};

// Batch normalization.
//
// Note that the size of 4D Tensors are defined by either "NHWC" or "NCHW".
// The size of 1D Tensors matches the dimension C of the 4D Tensors.
//
// Arguments:
// * scope: A Scope object
// * x: A 4D Tensor for input data.
// * scale: A 1D Tensor for scaling factor, to scale the normalized x.
// * offset: A 1D Tensor for offset, to shift to the normalized x.
// * mean: A 1D Tensor for population mean. Used for inference only;
// must be empty for training.
// * variance: A 1D Tensor for population variance. Used for inference only;
// must be empty for training.
class FusedBatchNorm {
 public:
  // Optional attribute setters for FusedBatchNorm :
  //
  // Epsilon(float): Defaults to 0.0001
  //     A small float number added to the variance of x.
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     The data format for x and y. Either "NHWC" (default) or "NCHW".
  // IsTraining(bool): Defaults to true
  //     A bool value to indicate the operation is for training (default)
  // or inference.
  struct Attrs {
    Attrs Epsilon(float x) {
      Attrs ret = *this;
      ret.epsilon_ = x;
      return ret;
    }

    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    Attrs IsTraining(bool x) {
      Attrs ret = *this;
      ret.is_training_ = x;
      return ret;
    }

    float epsilon_ = 0.0001f;
    StringPiece data_format_ = "NHWC";
    bool is_training_ = true;
  };
  FusedBatchNorm(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
               ::tensorflow::ops::Input scale, ::tensorflow::ops::Input offset,
               ::tensorflow::ops::Input mean, ::tensorflow::ops::Input
               variance);
  FusedBatchNorm(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input x,
               ::tensorflow::ops::Input scale, ::tensorflow::ops::Input offset,
               ::tensorflow::ops::Input mean, ::tensorflow::ops::Input
               variance, const FusedBatchNorm::Attrs& attrs);

  static Attrs Epsilon(float x) {
    return Attrs().Epsilon(x);
  }
  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }
  static Attrs IsTraining(bool x) {
    return Attrs().IsTraining(x);
  }

  ::tensorflow::ops::Output y;
  ::tensorflow::ops::Output batch_mean;
  ::tensorflow::ops::Output batch_variance;
  ::tensorflow::ops::Output reserve_space_1;
  ::tensorflow::ops::Output reserve_space_2;
};

// Gradient for batch normalization.
//
// Note that the size of 4D Tensors are defined by either "NHWC" or "NCHW".
// The size of 1D Tensors matches the dimension C of the 4D Tensors.
//
// Arguments:
// * scope: A Scope object
// * y_backprop: A 4D Tensor for the gradient with respect to y.
// * x: A 4D Tensor for input data.
// * scale: A 1D Tensor for scaling factor, to scale the normalized x.
// * reserve_space_1: A 1D Tensor for the computed batch mean, to be reused
// in the gradient computation.
// * reserve_space_2: A 1D Tensor for the computed batch variance (inverted variance
// in the cuDNN case), to be used in the gradient computation.
class FusedBatchNormGrad {
 public:
  // Optional attribute setters for FusedBatchNormGrad :
  //
  // Epsilon(float): Defaults to 0.0001
  //     A small float number added to the variance of x.
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     The data format for y_backprop, x, x_backprop.
  // Either "NHWC" (default) or "NCHW".
  // IsTraining(bool): Defaults to true
  //     A bool value to indicate the operation is for training (default)
  // or inference.
  struct Attrs {
    Attrs Epsilon(float x) {
      Attrs ret = *this;
      ret.epsilon_ = x;
      return ret;
    }

    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    Attrs IsTraining(bool x) {
      Attrs ret = *this;
      ret.is_training_ = x;
      return ret;
    }

    float epsilon_ = 0.0001f;
    StringPiece data_format_ = "NHWC";
    bool is_training_ = true;
  };
  FusedBatchNormGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   y_backprop, ::tensorflow::ops::Input x,
                   ::tensorflow::ops::Input scale, ::tensorflow::ops::Input
                   reserve_space_1, ::tensorflow::ops::Input reserve_space_2);
  FusedBatchNormGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   y_backprop, ::tensorflow::ops::Input x,
                   ::tensorflow::ops::Input scale, ::tensorflow::ops::Input
                   reserve_space_1, ::tensorflow::ops::Input reserve_space_2,
                   const FusedBatchNormGrad::Attrs& attrs);

  static Attrs Epsilon(float x) {
    return Attrs().Epsilon(x);
  }
  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }
  static Attrs IsTraining(bool x) {
    return Attrs().IsTraining(x);
  }

  ::tensorflow::ops::Output x_backprop;
  ::tensorflow::ops::Output scale_backprop;
  ::tensorflow::ops::Output offset_backprop;
  ::tensorflow::ops::Output reserve_space_3;
  ::tensorflow::ops::Output reserve_space_4;
};

// Performs a padding as a preprocess during a convolution.
//
// Similar to FusedResizeAndPadConv2d, this op allows for an optimized
// implementation where the spatial padding transformation stage is fused with the
// im2col lookup, but in this case without the bilinear filtering required for
// resizing. Fusing the padding prevents the need to write out the intermediate
// results as whole tensors, reducing memory pressure, and we can get some latency
// gains by merging the transformation calculations.
// The data_format attribute for Conv2D isn't supported by this op, and 'NHWC'
// order is used instead.
// Internally this op uses a single per-graph scratch buffer, which means that it
// will block if multiple versions are being run in parallel. This is because this
// operator is primarily an optimization to minimize memory usage.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, in_height, in_width, in_channels]`.
// * paddings: A two-column matrix specifying the padding sizes. The number of
// rows must be the same as the rank of `input`.
// * filter: 4-D with shape
// `[filter_height, filter_width, in_channels, out_channels]`.
// * strides:
//     1-D of length 4.  The stride of the sliding window for each dimension
// of `input`. Must be in the same order as the dimension specified with format.
// * padding:
//     The type of padding algorithm to use.
class FusedPadConv2D {
 public:
  FusedPadConv2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               input, ::tensorflow::ops::Input paddings,
               ::tensorflow::ops::Input filter, StringPiece mode, const
               gtl::ArraySlice<int>& strides, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Performs a resize and padding as a preprocess during a convolution.
//
// It's often possible to do spatial transformations more efficiently as part of
// the packing stage of a convolution, so this op allows for an optimized
// implementation where these stages are fused together. This prevents the need to
// write out the intermediate results as whole tensors, reducing memory pressure,
// and we can get some latency gains by merging the transformation calculations.
// The data_format attribute for Conv2D isn't supported by this op, and defaults to
// 'NHWC' order.
// Internally this op uses a single per-graph scratch buffer, which means that it
// will block if multiple versions are being run in parallel. This is because this
// operator is primarily an optimization to minimize memory usage.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, in_height, in_width, in_channels]`.
// * size: A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
// new size for the images.
// * paddings: A two-column matrix specifying the padding sizes. The number of
// rows must be the same as the rank of `input`.
// * filter: 4-D with shape
// `[filter_height, filter_width, in_channels, out_channels]`.
// * strides:
//     1-D of length 4.  The stride of the sliding window for each dimension
// of `input`. Must be in the same order as the dimension specified with format.
// * padding:
//     The type of padding algorithm to use.
class FusedResizeAndPadConv2D {
 public:
  // Optional attribute setters for FusedResizeAndPadConv2D :
  //
  // ResizeAlignCorners(bool): Defaults to false
  //     If true, rescale input by (new_height - 1) / (height - 1),
  // which exactly aligns the 4 corners of images and resized images. If false, rescale
  // by new_height / height. Treat similarly the width dimension.
  struct Attrs {
    Attrs ResizeAlignCorners(bool x) {
      Attrs ret = *this;
      ret.resize_align_corners_ = x;
      return ret;
    }

    bool resize_align_corners_ = false;
  };
  FusedResizeAndPadConv2D(const ::tensorflow::Scope& scope,
                        ::tensorflow::ops::Input input,
                        ::tensorflow::ops::Input size, ::tensorflow::ops::Input
                        paddings, ::tensorflow::ops::Input filter, StringPiece
                        mode, const gtl::ArraySlice<int>& strides, StringPiece
                        padding);
  FusedResizeAndPadConv2D(const ::tensorflow::Scope& scope,
                        ::tensorflow::ops::Input input,
                        ::tensorflow::ops::Input size, ::tensorflow::ops::Input
                        paddings, ::tensorflow::ops::Input filter, StringPiece
                        mode, const gtl::ArraySlice<int>& strides, StringPiece
                        padding, const FusedResizeAndPadConv2D::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs ResizeAlignCorners(bool x) {
    return Attrs().ResizeAlignCorners(x);
  }

  ::tensorflow::ops::Output output;
};

// Says whether the targets are in the top `K` predictions.
//
// This outputs a `batch_size` bool array, an entry `out[i]` is `true` if the
// prediction for the target class is among the top `k` predictions among
// all predictions for example `i`. Note that the behavior of `InTopK` differs
// from the `TopK` op in its handling of ties; if multiple classes have the
// same prediction value and straddle the top-`k` boundary, all of those
// classes are considered to be in the top `k`.
//
// More formally, let
//
//   \\(predictions_i\\) be the predictions for all classes for example `i`,
//   \\(targets_i\\) be the target class for example `i`,
//   \\(out_i\\) be the output for example `i`,
//
// $$out_i = predictions_{i, targets_i} \in TopKIncludingTies(predictions_i)$$
//
// Arguments:
// * scope: A Scope object
// * predictions: A `batch_size` x `classes` tensor.
// * targets: A `batch_size` vector of class ids.
// * k:
//     Number of top elements to look at for computing precision.
class InTopK {
 public:
  InTopK(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input predictions,
       ::tensorflow::ops::Input targets, int64 k);
  operator ::tensorflow::ops::Output() const { return precision; }
  operator ::tensorflow::ops::Input() const { return precision; }
  ::tensorflow::Node* node() const { return precision.node(); }

  ::tensorflow::ops::Output precision;
};

// L2 Loss.
//
// Computes half the L2 norm of a tensor without the `sqrt`:
//
//     output = sum(t ** 2) / 2
//
// Arguments:
// * scope: A Scope object
// * t: Typically 2-D, but may have any dimensions.
class L2Loss {
 public:
  L2Loss(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input t);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Local Response Normalization.
//
// The 4-D `input` tensor is treated as a 3-D array of 1-D vectors (along the last
// dimension), and each vector is normalized independently.  Within a given vector,
// each component is divided by the weighted, squared sum of inputs within
// `depth_radius`.  In detail,
//
//     sqr_sum[a, b, c, d] =
//         sum(input[a, b, c, d - depth_radius : d + depth_radius + 1] ** 2)
//     output = input / (bias + alpha * sqr_sum) ** beta
//
// For details, see [Krizhevsky et al., ImageNet classification with deep
// convolutional neural networks (NIPS 2012)](http://papers.nips.cc/paper/4824-imagenet-classification-with-deep-convolutional-neural-networks).
//
// Arguments:
// * scope: A Scope object
// * input: 4-D.
class LRN {
 public:
  // Optional attribute setters for LRN :
  //
  // DepthRadius(int64): Defaults to 5
  //     0-D.  Half-width of the 1-D normalization window.
  // Bias(float): Defaults to 1
  //     An offset (usually positive to avoid dividing by 0).
  // Alpha(float): Defaults to 1
  //     A scale factor, usually positive.
  // Beta(float): Defaults to 0.5
  //     An exponent.
  struct Attrs {
    Attrs DepthRadius(int64 x) {
      Attrs ret = *this;
      ret.depth_radius_ = x;
      return ret;
    }

    Attrs Bias(float x) {
      Attrs ret = *this;
      ret.bias_ = x;
      return ret;
    }

    Attrs Alpha(float x) {
      Attrs ret = *this;
      ret.alpha_ = x;
      return ret;
    }

    Attrs Beta(float x) {
      Attrs ret = *this;
      ret.beta_ = x;
      return ret;
    }

    int64 depth_radius_ = 5;
    float bias_ = 1.0f;
    float alpha_ = 1.0f;
    float beta_ = 0.5f;
  };
  LRN(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  LRN(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input, const
    LRN::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs DepthRadius(int64 x) {
    return Attrs().DepthRadius(x);
  }
  static Attrs Bias(float x) {
    return Attrs().Bias(x);
  }
  static Attrs Alpha(float x) {
    return Attrs().Alpha(x);
  }
  static Attrs Beta(float x) {
    return Attrs().Beta(x);
  }

  ::tensorflow::ops::Output output;
};

// Gradients for Local Response Normalization.
//
// Arguments:
// * scope: A Scope object
// * input_grads: 4-D with shape `[batch, height, width, channels]`.
// * input_image: 4-D with shape `[batch, height, width, channels]`.
// * output_image: 4-D with shape `[batch, height, width, channels]`.
class LRNGrad {
 public:
  // Optional attribute setters for LRNGrad :
  //
  // DepthRadius(int64): Defaults to 5
  //     A depth radius.
  // Bias(float): Defaults to 1
  //     An offset (usually > 0 to avoid dividing by 0).
  // Alpha(float): Defaults to 1
  //     A scale factor, usually positive.
  // Beta(float): Defaults to 0.5
  //     An exponent.
  struct Attrs {
    Attrs DepthRadius(int64 x) {
      Attrs ret = *this;
      ret.depth_radius_ = x;
      return ret;
    }

    Attrs Bias(float x) {
      Attrs ret = *this;
      ret.bias_ = x;
      return ret;
    }

    Attrs Alpha(float x) {
      Attrs ret = *this;
      ret.alpha_ = x;
      return ret;
    }

    Attrs Beta(float x) {
      Attrs ret = *this;
      ret.beta_ = x;
      return ret;
    }

    int64 depth_radius_ = 5;
    float bias_ = 1.0f;
    float alpha_ = 1.0f;
    float beta_ = 0.5f;
  };
  LRNGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input_grads,
        ::tensorflow::ops::Input input_image, ::tensorflow::ops::Input
        output_image);
  LRNGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input_grads,
        ::tensorflow::ops::Input input_image, ::tensorflow::ops::Input
        output_image, const LRNGrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs DepthRadius(int64 x) {
    return Attrs().DepthRadius(x);
  }
  static Attrs Bias(float x) {
    return Attrs().Bias(x);
  }
  static Attrs Alpha(float x) {
    return Attrs().Alpha(x);
  }
  static Attrs Beta(float x) {
    return Attrs().Beta(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes log softmax activations.
//
// For each batch `i` and class `j` we have
//
//     logsoftmax[i, j] = logits[i, j] - log(sum(exp(logits[i])))
//
// Arguments:
// * scope: A Scope object
// * logits: 2-D with shape `[batch_size, num_classes]`.
class LogSoftmax {
 public:
  LogSoftmax(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input logits);
  operator ::tensorflow::ops::Output() const { return logsoftmax; }
  operator ::tensorflow::ops::Input() const { return logsoftmax; }
  ::tensorflow::Node* node() const { return logsoftmax.node(); }

  ::tensorflow::ops::Output logsoftmax;
};

// Performs max pooling on the input.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D input to pool over.
// * ksize:
//     The size of the window for each dimension of the input tensor.
// * strides:
//     The stride of the sliding window for each dimension of the
// input tensor.
// * padding:
//     The type of padding algorithm to use.
class MaxPool {
 public:
  // Optional attribute setters for MaxPool :
  //
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the data is stored in the order of:
  //     [batch, in_height, in_width, in_channels].
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  struct Attrs {
    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    StringPiece data_format_ = "NHWC";
  };
  MaxPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input, const
        gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>& strides,
        StringPiece padding);
  MaxPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input, const
        gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>& strides,
        StringPiece padding, const MaxPool::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// Performs 3D max pooling on the input.
//
// Arguments:
// * scope: A Scope object
// * input: Shape `[batch, depth, rows, cols, channels]` tensor to pool over.
// * ksize:
//     1-D tensor of length 5. The size of the window for each dimension of
// the input tensor. Must have `ksize[0] = ksize[4] = 1`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class MaxPool3D {
 public:
  MaxPool3D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
          const gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>&
          strides, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes gradients of max pooling function.
//
// Arguments:
// * scope: A Scope object
// * orig_input: The original input tensor.
// * orig_output: The original output tensor.
// * grad: Output backprop of shape `[batch, depth, rows, cols, channels]`.
// * ksize:
//     1-D tensor of length 5. The size of the window for each dimension of
// the input tensor. Must have `ksize[0] = ksize[4] = 1`.
// * strides:
//     1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding:
//     The type of padding algorithm to use.
class MaxPool3DGrad {
 public:
  MaxPool3DGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              orig_input, ::tensorflow::ops::Input orig_output,
              ::tensorflow::ops::Input grad, const gtl::ArraySlice<int>& ksize,
              const gtl::ArraySlice<int>& strides, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes gradients of the maxpooling function.
//
// Arguments:
// * scope: A Scope object
// * orig_input: The original input tensor.
// * orig_output: The original output tensor.
// * grad: 4-D.  Gradients w.r.t. the output of `max_pool`.
// * ksize:
//     The size of the window for each dimension of the input tensor.
// * strides:
//     The stride of the sliding window for each dimension of the
// input tensor.
// * padding:
//     The type of padding algorithm to use.
class MaxPoolGrad {
 public:
  // Optional attribute setters for MaxPoolGrad :
  //
  // DataFormat(StringPiece): Defaults to "NHWC"
  //     Specify the data format of the input and output data. With the
  // default format "NHWC", the data is stored in the order of:
  //     [batch, in_height, in_width, in_channels].
  // Alternatively, the format could be "NCHW", the data storage order of:
  //     [batch, in_channels, in_height, in_width].
  struct Attrs {
    Attrs DataFormat(StringPiece x) {
      Attrs ret = *this;
      ret.data_format_ = x;
      return ret;
    }

    StringPiece data_format_ = "NHWC";
  };
  MaxPoolGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
            orig_input, ::tensorflow::ops::Input orig_output,
            ::tensorflow::ops::Input grad, const gtl::ArraySlice<int>& ksize,
            const gtl::ArraySlice<int>& strides, StringPiece padding);
  MaxPoolGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
            orig_input, ::tensorflow::ops::Input orig_output,
            ::tensorflow::ops::Input grad, const gtl::ArraySlice<int>& ksize,
            const gtl::ArraySlice<int>& strides, StringPiece padding, const
            MaxPoolGrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs DataFormat(StringPiece x) {
    return Attrs().DataFormat(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes gradients of the maxpooling function.
//
// Arguments:
// * scope: A Scope object
// * input: The original input.
// * grad: 4-D with shape `[batch, height, width, channels]`.  Gradients w.r.t. the
// output of `max_pool`.
// * argmax: The indices of the maximum values chosen for each output of `max_pool`.
// * ksize:
//     The size of the window for each dimension of the input tensor.
// * strides:
//     The stride of the sliding window for each dimension of the
// input tensor.
// * padding:
//     The type of padding algorithm to use.
class MaxPoolGradWithArgmax {
 public:
  MaxPoolGradWithArgmax(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input input, ::tensorflow::ops::Input
                      grad, ::tensorflow::ops::Input argmax, const
                      gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>&
                      strides, StringPiece padding);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Performs max pooling on the input and outputs both max values and indices.
//
// The indices in `argmax` are flattened, so that a maximum value at position
// `[b, y, x, c]` becomes flattened index
// `((b * height + y) * width + x) * channels + c`.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, height, width, channels]`.  Input to pool over.
// * ksize:
//     The size of the window for each dimension of the input tensor.
// * strides:
//     The stride of the sliding window for each dimension of the
// input tensor.
// * padding:
//     The type of padding algorithm to use.
class MaxPoolWithArgmax {
 public:
  // Optional attribute setters for MaxPoolWithArgmax :
  //
  // Targmax(DataType): Defaults to DT_INT64
  struct Attrs {
    Attrs Targmax(DataType x) {
      Attrs ret = *this;
      ret.Targmax_ = x;
      return ret;
    }

    DataType Targmax_ = DT_INT64;
  };
  MaxPoolWithArgmax(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  input, const gtl::ArraySlice<int>& ksize, const
                  gtl::ArraySlice<int>& strides, StringPiece padding);
  MaxPoolWithArgmax(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  input, const gtl::ArraySlice<int>& ksize, const
                  gtl::ArraySlice<int>& strides, StringPiece padding, const
                  MaxPoolWithArgmax::Attrs& attrs);

  static Attrs Targmax(DataType x) {
    return Attrs().Targmax(x);
  }

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output argmax;
};

// Produces the average pool of the input tensor for quantized types.
//
// Arguments:
// * scope: A Scope object
// * input: 4-D with shape `[batch, height, width, channels]`.
// * min_input: The float value that the lowest quantized input value represents.
// * max_input: The float value that the highest quantized input value represents.
// * ksize:
//     The size of the window for each dimension of the input tensor.
// The length must be 4 to match the number of dimensions of the input.
// * strides:
//     The stride of the sliding window for each dimension of the input
// tensor.  The length must be 4 to match the number of dimensions of the input.
// * padding:
//     The type of padding algorithm to use.
class QuantizedAvgPool {
 public:
  QuantizedAvgPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 input, ::tensorflow::ops::Input min_input,
                 ::tensorflow::ops::Input max_input, const
                 gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>&
                 strides, StringPiece padding);

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output min_output;
  ::tensorflow::ops::Output max_output;
};

// Quantized Batch normalization.
//
// This op is deprecated and will be removed in the future. Prefer
// `tf.nn.batch_normalization`.
//
// Arguments:
// * scope: A Scope object
// * t: A 4D input Tensor.
// * t_min: The value represented by the lowest quantized input.
// * t_max: The value represented by the highest quantized input.
// * m: A 1D mean Tensor with size matching the last dimension of t.
// This is the first output from tf.nn.moments,
// or a saved moving average thereof.
// * m_min: The value represented by the lowest quantized mean.
// * m_max: The value represented by the highest quantized mean.
// * v: A 1D variance Tensor with size matching the last dimension of t.
// This is the second output from tf.nn.moments,
// or a saved moving average thereof.
// * v_min: The value represented by the lowest quantized variance.
// * v_max: The value represented by the highest quantized variance.
// * beta: A 1D beta Tensor with size matching the last dimension of t.
// An offset to be added to the normalized tensor.
// * beta_min: The value represented by the lowest quantized offset.
// * beta_max: The value represented by the highest quantized offset.
// * gamma: A 1D gamma Tensor with size matching the last dimension of t.
// If "scale_after_normalization" is true, this tensor will be multiplied
// with the normalized tensor.
// * gamma_min: The value represented by the lowest quantized gamma.
// * gamma_max: The value represented by the highest quantized gamma.
// * variance_epsilon:
//     A small float number to avoid dividing by 0.
// * scale_after_normalization:
//     A bool indicating whether the resulted tensor
// needs to be multiplied with gamma.
class QuantizedBatchNormWithGlobalNormalization {
 public:
  QuantizedBatchNormWithGlobalNormalization(const ::tensorflow::Scope& scope,
                                          ::tensorflow::ops::Input t,
                                          ::tensorflow::ops::Input t_min,
                                          ::tensorflow::ops::Input t_max,
                                          ::tensorflow::ops::Input m,
                                          ::tensorflow::ops::Input m_min,
                                          ::tensorflow::ops::Input m_max,
                                          ::tensorflow::ops::Input v,
                                          ::tensorflow::ops::Input v_min,
                                          ::tensorflow::ops::Input v_max,
                                          ::tensorflow::ops::Input beta,
                                          ::tensorflow::ops::Input beta_min,
                                          ::tensorflow::ops::Input beta_max,
                                          ::tensorflow::ops::Input gamma,
                                          ::tensorflow::ops::Input gamma_min,
                                          ::tensorflow::ops::Input gamma_max,
                                          DataType out_type, float
                                          variance_epsilon, bool
                                          scale_after_normalization);

  ::tensorflow::ops::Output result;
  ::tensorflow::ops::Output result_min;
  ::tensorflow::ops::Output result_max;
};

// Adds Tensor 'bias' to Tensor 'input' for Quantized types.
//
// Broadcasts the values of bias on dimensions 0..N-2 of 'input'.
//
// Arguments:
// * scope: A Scope object
// * bias: A 1D bias Tensor with size matching the last dimension of 'input'.
// * min_input: The float value that the lowest quantized input value represents.
// * max_input: The float value that the highest quantized input value represents.
// * min_bias: The float value that the lowest quantized bias value represents.
// * max_bias: The float value that the highest quantized bias value represents.
class QuantizedBiasAdd {
 public:
  QuantizedBiasAdd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 input, ::tensorflow::ops::Input bias, ::tensorflow::ops::Input
                 min_input, ::tensorflow::ops::Input max_input,
                 ::tensorflow::ops::Input min_bias, ::tensorflow::ops::Input
                 max_bias, DataType out_type);

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output min_out;
  ::tensorflow::ops::Output max_out;
};

// Computes a 2D convolution given quantized 4D input and filter tensors.
//
// The inputs are quantized tensors where the lowest value represents the real
// number of the associated minimum, and the highest represents the maximum.
// This means that you can only interpret the quantized output in the same way, by
// taking the returned minimum and maximum values into account.
//
// Arguments:
// * scope: A Scope object
// * filter: filter's input_depth dimension must match input's depth dimensions.
// * min_input: The float value that the lowest quantized input value represents.
// * max_input: The float value that the highest quantized input value represents.
// * min_filter: The float value that the lowest quantized filter value represents.
// * max_filter: The float value that the highest quantized filter value represents.
// * strides:
//     The stride of the sliding window for each dimension of the input
// tensor.
// * padding:
//     The type of padding algorithm to use.
class QuantizedConv2D {
 public:
  // Optional attribute setters for QuantizedConv2D :
  //
  // OutType(DataType): Defaults to DT_QINT32
  struct Attrs {
    Attrs OutType(DataType x) {
      Attrs ret = *this;
      ret.out_type_ = x;
      return ret;
    }

    DataType out_type_ = DT_QINT32;
  };
  QuantizedConv2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                input, ::tensorflow::ops::Input filter,
                ::tensorflow::ops::Input min_input, ::tensorflow::ops::Input
                max_input, ::tensorflow::ops::Input min_filter,
                ::tensorflow::ops::Input max_filter, const
                gtl::ArraySlice<int>& strides, StringPiece padding);
  QuantizedConv2D(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                input, ::tensorflow::ops::Input filter,
                ::tensorflow::ops::Input min_input, ::tensorflow::ops::Input
                max_input, ::tensorflow::ops::Input min_filter,
                ::tensorflow::ops::Input max_filter, const
                gtl::ArraySlice<int>& strides, StringPiece padding, const
                QuantizedConv2D::Attrs& attrs);

  static Attrs OutType(DataType x) {
    return Attrs().OutType(x);
  }

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output min_output;
  ::tensorflow::ops::Output max_output;
};

// Produces the max pool of the input tensor for quantized types.
//
// Arguments:
// * scope: A Scope object
// * input: The 4D (batch x rows x cols x depth) Tensor to MaxReduce over.
// * min_input: The float value that the lowest quantized input value represents.
// * max_input: The float value that the highest quantized input value represents.
// * ksize:
//     The size of the window for each dimension of the input tensor.
// The length must be 4 to match the number of dimensions of the input.
// * strides:
//     The stride of the sliding window for each dimension of the input
// tensor. The length must be 4 to match the number of dimensions of the input.
// * padding:
//     The type of padding algorithm to use.
class QuantizedMaxPool {
 public:
  QuantizedMaxPool(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 input, ::tensorflow::ops::Input min_input,
                 ::tensorflow::ops::Input max_input, const
                 gtl::ArraySlice<int>& ksize, const gtl::ArraySlice<int>&
                 strides, StringPiece padding);

  ::tensorflow::ops::Output output;
  ::tensorflow::ops::Output min_output;
  ::tensorflow::ops::Output max_output;
};

// Computes Quantized Rectified Linear: `max(features, 0)`
//
// Arguments:
// * scope: A Scope object
// * min_features: The float value that the lowest quantized value represents.
// * max_features: The float value that the highest quantized value represents.
class QuantizedRelu {
 public:
  // Optional attribute setters for QuantizedRelu :
  //
  // OutType(DataType): Defaults to DT_QUINT8
  struct Attrs {
    Attrs OutType(DataType x) {
      Attrs ret = *this;
      ret.out_type_ = x;
      return ret;
    }

    DataType out_type_ = DT_QUINT8;
  };
  QuantizedRelu(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              features, ::tensorflow::ops::Input min_features,
              ::tensorflow::ops::Input max_features);
  QuantizedRelu(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              features, ::tensorflow::ops::Input min_features,
              ::tensorflow::ops::Input max_features, const
              QuantizedRelu::Attrs& attrs);

  static Attrs OutType(DataType x) {
    return Attrs().OutType(x);
  }

  ::tensorflow::ops::Output activations;
  ::tensorflow::ops::Output min_activations;
  ::tensorflow::ops::Output max_activations;
};

// Computes Quantized Rectified Linear 6: `min(max(features, 0), 6)`
//
// Arguments:
// * scope: A Scope object
// * min_features: The float value that the lowest quantized value represents.
// * max_features: The float value that the highest quantized value represents.
class QuantizedRelu6 {
 public:
  // Optional attribute setters for QuantizedRelu6 :
  //
  // OutType(DataType): Defaults to DT_QUINT8
  struct Attrs {
    Attrs OutType(DataType x) {
      Attrs ret = *this;
      ret.out_type_ = x;
      return ret;
    }

    DataType out_type_ = DT_QUINT8;
  };
  QuantizedRelu6(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               features, ::tensorflow::ops::Input min_features,
               ::tensorflow::ops::Input max_features);
  QuantizedRelu6(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               features, ::tensorflow::ops::Input min_features,
               ::tensorflow::ops::Input max_features, const
               QuantizedRelu6::Attrs& attrs);

  static Attrs OutType(DataType x) {
    return Attrs().OutType(x);
  }

  ::tensorflow::ops::Output activations;
  ::tensorflow::ops::Output min_activations;
  ::tensorflow::ops::Output max_activations;
};

// Computes Quantized Rectified Linear X: `min(max(features, 0), max_value)`
//
// Arguments:
// * scope: A Scope object
// * min_features: The float value that the lowest quantized value represents.
// * max_features: The float value that the highest quantized value represents.
class QuantizedReluX {
 public:
  // Optional attribute setters for QuantizedReluX :
  //
  // OutType(DataType): Defaults to DT_QUINT8
  struct Attrs {
    Attrs OutType(DataType x) {
      Attrs ret = *this;
      ret.out_type_ = x;
      return ret;
    }

    DataType out_type_ = DT_QUINT8;
  };
  QuantizedReluX(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               features, ::tensorflow::ops::Input max_value,
               ::tensorflow::ops::Input min_features, ::tensorflow::ops::Input
               max_features);
  QuantizedReluX(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               features, ::tensorflow::ops::Input max_value,
               ::tensorflow::ops::Input min_features, ::tensorflow::ops::Input
               max_features, const QuantizedReluX::Attrs& attrs);

  static Attrs OutType(DataType x) {
    return Attrs().OutType(x);
  }

  ::tensorflow::ops::Output activations;
  ::tensorflow::ops::Output min_activations;
  ::tensorflow::ops::Output max_activations;
};

// Computes rectified linear: `max(features, 0)`.
//
// Arguments:
// * scope: A Scope object
class Relu {
 public:
  Relu(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return activations; }
  operator ::tensorflow::ops::Input() const { return activations; }
  ::tensorflow::Node* node() const { return activations.node(); }

  ::tensorflow::ops::Output activations;
};

// Computes rectified linear 6: `min(max(features, 0), 6)`.
//
// Arguments:
// * scope: A Scope object
class Relu6 {
 public:
  Relu6(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return activations; }
  operator ::tensorflow::ops::Input() const { return activations; }
  ::tensorflow::Node* node() const { return activations.node(); }

  ::tensorflow::ops::Output activations;
};

// Computes rectified linear 6 gradients for a Relu6 operation.
//
// Arguments:
// * scope: A Scope object
// * gradients: The backpropagated gradients to the corresponding Relu6 operation.
// * features: The features passed as input to the corresponding Relu6 operation.
class Relu6Grad {
 public:
  Relu6Grad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input gradients,
          ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return backprops; }
  operator ::tensorflow::ops::Input() const { return backprops; }
  ::tensorflow::Node* node() const { return backprops.node(); }

  ::tensorflow::ops::Output backprops;
};

// Computes rectified linear gradients for a Relu operation.
//
// Arguments:
// * scope: A Scope object
// * gradients: The backpropagated gradients to the corresponding Relu operation.
// * features: The features passed as input to the corresponding Relu operation, OR
// the outputs of that operation (both work equivalently).
class ReluGrad {
 public:
  ReluGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input gradients,
         ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return backprops; }
  operator ::tensorflow::ops::Input() const { return backprops; }
  ::tensorflow::Node* node() const { return backprops.node(); }

  ::tensorflow::ops::Output backprops;
};

// Computes softmax activations.
//
// For each batch `i` and class `j` we have
//
//     softmax[i, j] = exp(logits[i, j]) / sum_j(exp(logits[i, j]))
//
// Arguments:
// * scope: A Scope object
// * logits: 2-D with shape `[batch_size, num_classes]`.
class Softmax {
 public:
  Softmax(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input logits);
  operator ::tensorflow::ops::Output() const { return softmax; }
  operator ::tensorflow::ops::Input() const { return softmax; }
  ::tensorflow::Node* node() const { return softmax.node(); }

  ::tensorflow::ops::Output softmax;
};

// Computes softmax cross entropy cost and gradients to backpropagate.
//
// Inputs are the logits, not probabilities.
//
// Arguments:
// * scope: A Scope object
// * features: batch_size x num_classes matrix
// * labels: batch_size x num_classes matrix
// The caller must ensure that each batch of labels represents a valid
// probability distribution.
class SoftmaxCrossEntropyWithLogits {
 public:
  SoftmaxCrossEntropyWithLogits(const ::tensorflow::Scope& scope,
                              ::tensorflow::ops::Input features,
                              ::tensorflow::ops::Input labels);

  ::tensorflow::ops::Output loss;
  ::tensorflow::ops::Output backprop;
};

// Computes softplus: `log(exp(features) + 1)`.
//
// Arguments:
// * scope: A Scope object
class Softplus {
 public:
  Softplus(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return activations; }
  operator ::tensorflow::ops::Input() const { return activations; }
  ::tensorflow::Node* node() const { return activations.node(); }

  ::tensorflow::ops::Output activations;
};

// Computes softplus gradients for a softplus operation.
//
// Arguments:
// * scope: A Scope object
// * gradients: The backpropagated gradients to the corresponding softplus operation.
// * features: The features passed as input to the corresponding softplus operation.
class SoftplusGrad {
 public:
  SoftplusGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
             gradients, ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return backprops; }
  operator ::tensorflow::ops::Input() const { return backprops; }
  ::tensorflow::Node* node() const { return backprops.node(); }

  ::tensorflow::ops::Output backprops;
};

// Computes softsign: `features / (abs(features) + 1)`.
//
// Arguments:
// * scope: A Scope object
class Softsign {
 public:
  Softsign(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return activations; }
  operator ::tensorflow::ops::Input() const { return activations; }
  ::tensorflow::Node* node() const { return activations.node(); }

  ::tensorflow::ops::Output activations;
};

// Computes softsign gradients for a softsign operation.
//
// Arguments:
// * scope: A Scope object
// * gradients: The backpropagated gradients to the corresponding softsign operation.
// * features: The features passed as input to the corresponding softsign operation.
class SoftsignGrad {
 public:
  SoftsignGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
             gradients, ::tensorflow::ops::Input features);
  operator ::tensorflow::ops::Output() const { return backprops; }
  operator ::tensorflow::ops::Input() const { return backprops; }
  ::tensorflow::Node* node() const { return backprops.node(); }

  ::tensorflow::ops::Output backprops;
};

// Computes softmax cross entropy cost and gradients to backpropagate.
//
// Unlike `SoftmaxCrossEntropyWithLogits`, this operation does not accept
// a matrix of label probabilities, but rather a single label per row
// of features.  This label is considered to have probability 1.0 for the
// given row.
//
// Inputs are the logits, not probabilities.
//
// Arguments:
// * scope: A Scope object
// * features: batch_size x num_classes matrix
// * labels: batch_size vector with values in [0, num_classes).
// This is the label for the given minibatch entry.
class SparseSoftmaxCrossEntropyWithLogits {
 public:
  SparseSoftmaxCrossEntropyWithLogits(const ::tensorflow::Scope& scope,
                                    ::tensorflow::ops::Input features,
                                    ::tensorflow::ops::Input labels);

  ::tensorflow::ops::Output loss;
  ::tensorflow::ops::Output backprop;
};

// Finds values and indices of the `k` largest elements for the last dimension.
//
// DEPRECATED at GraphDef version 7:
// Use TopKV2 instead.
//
// If the input is a vector (rank-1), finds the `k` largest entries in the vector
// and outputs their values and indices as vectors.  Thus `values[j]` is the
// `j`-th largest entry in `input`, and its index is `indices[j]`.
//
// For matrices (resp. higher rank input), computes the top `k` entries in each
// row (resp. vector along the last dimension).  Thus,
//
//     values.shape = indices.shape = input.shape[:-1] + [k]
//
// If two elements are equal, the lower-index element appears first.
//
// If `k` varies dynamically, use `TopKV2` below.
//
// Arguments:
// * scope: A Scope object
// * input: 1-D or higher with last dimension at least `k`.
// * k:
//     Number of top elements to look for along the last dimension (along each
// row for matrices).
class TopK {
 public:
  // Optional attribute setters for TopK :
  //
  // Sorted(bool): Defaults to true
  //     If true the resulting `k` elements will be sorted by the values in
  // descending order.
  struct Attrs {
    Attrs Sorted(bool x) {
      Attrs ret = *this;
      ret.sorted_ = x;
      return ret;
    }

    bool sorted_ = true;
  };
  TopK(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input, int64 k);
  TopK(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input, int64 k,
     const TopK::Attrs& attrs);

  static Attrs Sorted(bool x) {
    return Attrs().Sorted(x);
  }

  ::tensorflow::ops::Output values;
  ::tensorflow::ops::Output indices;
};

// Finds values and indices of the `k` largest elements for the last dimension.
//
// If the input is a vector (rank-1), finds the `k` largest entries in the vector
// and outputs their values and indices as vectors.  Thus `values[j]` is the
// `j`-th largest entry in `input`, and its index is `indices[j]`.
//
// For matrices (resp. higher rank input), computes the top `k` entries in each
// row (resp. vector along the last dimension).  Thus,
//
//     values.shape = indices.shape = input.shape[:-1] + [k]
//
// If two elements are equal, the lower-index element appears first.
//
// This is the same as `TopK`, but takes `k` as in input rather than an attr.
//
// Arguments:
// * scope: A Scope object
// * input: 1-D or higher with last dimension at least `k`.
// * k: 0-D.  Number of top elements to look for along the last dimension (along each
// row for matrices).
class TopKV2 {
 public:
  // Optional attribute setters for TopKV2 :
  //
  // Sorted(bool): Defaults to true
  //     If true the resulting `k` elements will be sorted by the values in
  // descending order.
  struct Attrs {
    Attrs Sorted(bool x) {
      Attrs ret = *this;
      ret.sorted_ = x;
      return ret;
    }

    bool sorted_ = true;
  };
  TopKV2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
       ::tensorflow::ops::Input k);
  TopKV2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
       ::tensorflow::ops::Input k, const TopKV2::Attrs& attrs);

  static Attrs Sorted(bool x) {
    return Attrs().Sorted(x);
  }

  ::tensorflow::ops::Output values;
  ::tensorflow::ops::Output indices;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_NN_OPS_H_
