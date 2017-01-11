// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_IMAGE_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_IMAGE_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Deprecated. Disallowed in GraphDef version >= 2.
//
// DEPRECATED at GraphDef version 2:
// Use AdjustContrastv2 instead.
//
// Arguments:
// * scope: A Scope object
class AdjustContrast {
 public:
  AdjustContrast(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               images, ::tensorflow::ops::Input contrast_factor,
               ::tensorflow::ops::Input min_value, ::tensorflow::ops::Input
               max_value);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Adjust the contrast of one or more images.
//
// `images` is a tensor of at least 3 dimensions.  The last 3 dimensions are
// interpreted as `[height, width, channels]`.  The other dimensions only
// represent a collection of images, such as `[batch, height, width, channels].`
//
// Contrast is adjusted independently for each channel of each image.
//
// For each channel, the Op first computes the mean of the image pixels in the
// channel and then adjusts each component of each pixel to
// `(x - mean) * contrast_factor + mean`.
//
// Arguments:
// * scope: A Scope object
// * images: Images to adjust.  At least 3-D.
// * contrast_factor: A float multiplier for adjusting contrast.
class AdjustContrastv2 {
 public:
  AdjustContrastv2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 images, ::tensorflow::ops::Input contrast_factor);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Extracts crops from the input image tensor and bilinearly resizes them (possibly
//
// with aspect ratio change) to a common output size specified by `crop_size`. This
// is more general than the `crop_to_bounding_box` op which extracts a fixed size
// slice from the input image and does not allow resizing or aspect ratio change.
//
// Returns a tensor with `crops` from the input `image` at positions defined at the
// bounding box locations in `boxes`. The cropped boxes are all resized (with
// bilinear interpolation) to a fixed `size = [crop_height, crop_width]`. The
// result is a 4-D tensor `[num_boxes, crop_height, crop_width, depth]`.
//
// Arguments:
// * scope: A Scope object
// * image: A 4-D tensor of shape `[batch, image_height, image_width, depth]`.
// Both `image_height` and `image_width` need to be positive.
// * boxes: A 2-D tensor of shape `[num_boxes, 4]`. The `i`-th row of the tensor
// specifies the coordinates of a box in the `box_ind[i]` image and is specified
// in normalized coordinates `[y1, x1, y2, x2]`. A normalized coordinate value of
// `y` is mapped to the image coordinate at `y * (image_height - 1)`, so as the
// `[0, 1]` interval of normalized image height is mapped to
// `[0, image_height - 1] in image height coordinates. We do allow y1 > y2, in
// which case the sampled crop is an up-down flipped version of the original
// image. The width dimension is treated similarly. Normalized coordinates
// outside the `[0, 1]` range are allowed, in which case we use
// `extrapolation_value` to extrapolate the input image values.
// * box_ind: A 1-D tensor of shape `[num_boxes]` with int32 values in `[0, batch)`.
// The value of `box_ind[i]` specifies the image that the `i`-th box refers to.
// * crop_size: A 1-D tensor of 2 elements, `size = [crop_height, crop_width]`. All
// cropped image patches are resized to this size. The aspect ratio of the image
// content is not preserved. Both `crop_height` and `crop_width` need to be
// positive.
class CropAndResize {
 public:
  // Optional attribute setters for CropAndResize :
  //
  // Method(StringPiece): Defaults to "bilinear"
  //     A string specifying the interpolation method. Only 'bilinear' is
  // supported for now.
  // ExtrapolationValue(float): Defaults to 0
  //     Value used for extrapolation, when applicable.
  struct Attrs {
    Attrs Method(StringPiece x) {
      Attrs ret = *this;
      ret.method_ = x;
      return ret;
    }

    Attrs ExtrapolationValue(float x) {
      Attrs ret = *this;
      ret.extrapolation_value_ = x;
      return ret;
    }

    StringPiece method_ = "bilinear";
    float extrapolation_value_ = 0.0f;
  };
  CropAndResize(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input image,
              ::tensorflow::ops::Input boxes, ::tensorflow::ops::Input box_ind,
              ::tensorflow::ops::Input crop_size);
  CropAndResize(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input image,
              ::tensorflow::ops::Input boxes, ::tensorflow::ops::Input box_ind,
              ::tensorflow::ops::Input crop_size, const CropAndResize::Attrs&
              attrs);
  operator ::tensorflow::ops::Output() const { return crops; }
  operator ::tensorflow::ops::Input() const { return crops; }
  ::tensorflow::Node* node() const { return crops.node(); }

  static Attrs Method(StringPiece x) {
    return Attrs().Method(x);
  }
  static Attrs ExtrapolationValue(float x) {
    return Attrs().ExtrapolationValue(x);
  }

  ::tensorflow::ops::Output crops;
};

// Computes the gradient of the crop_and_resize op wrt the input boxes tensor.
//
// Arguments:
// * scope: A Scope object
// * grads: A 4-D tensor of shape `[num_boxes, crop_height, crop_width, depth]`.
// * image: A 4-D tensor of shape `[batch, image_height, image_width, depth]`.
// Both `image_height` and `image_width` need to be positive.
// * boxes: A 2-D tensor of shape `[num_boxes, 4]`. The `i`-th row of the tensor
// specifies the coordinates of a box in the `box_ind[i]` image and is specified
// in normalized coordinates `[y1, x1, y2, x2]`. A normalized coordinate value of
// `y` is mapped to the image coordinate at `y * (image_height - 1)`, so as the
// `[0, 1]` interval of normalized image height is mapped to
// `[0, image_height - 1] in image height coordinates. We do allow y1 > y2, in
// which case the sampled crop is an up-down flipped version of the original
// image. The width dimension is treated similarly. Normalized coordinates
// outside the `[0, 1]` range are allowed, in which case we use
// `extrapolation_value` to extrapolate the input image values.
// * box_ind: A 1-D tensor of shape `[num_boxes]` with int32 values in `[0, batch)`.
// The value of `box_ind[i]` specifies the image that the `i`-th box refers to.
class CropAndResizeGradBoxes {
 public:
  // Optional attribute setters for CropAndResizeGradBoxes :
  //
  // Method(StringPiece): Defaults to "bilinear"
  //     A string specifying the interpolation method. Only 'bilinear' is
  // supported for now.
  struct Attrs {
    Attrs Method(StringPiece x) {
      Attrs ret = *this;
      ret.method_ = x;
      return ret;
    }

    StringPiece method_ = "bilinear";
  };
  CropAndResizeGradBoxes(const ::tensorflow::Scope& scope,
                       ::tensorflow::ops::Input grads, ::tensorflow::ops::Input
                       image, ::tensorflow::ops::Input boxes,
                       ::tensorflow::ops::Input box_ind);
  CropAndResizeGradBoxes(const ::tensorflow::Scope& scope,
                       ::tensorflow::ops::Input grads, ::tensorflow::ops::Input
                       image, ::tensorflow::ops::Input boxes,
                       ::tensorflow::ops::Input box_ind, const
                       CropAndResizeGradBoxes::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Method(StringPiece x) {
    return Attrs().Method(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes the gradient of the crop_and_resize op wrt the input image tensor.
//
// Arguments:
// * scope: A Scope object
// * grads: A 4-D tensor of shape `[num_boxes, crop_height, crop_width, depth]`.
// * boxes: A 2-D tensor of shape `[num_boxes, 4]`. The `i`-th row of the tensor
// specifies the coordinates of a box in the `box_ind[i]` image and is specified
// in normalized coordinates `[y1, x1, y2, x2]`. A normalized coordinate value of
// `y` is mapped to the image coordinate at `y * (image_height - 1)`, so as the
// `[0, 1]` interval of normalized image height is mapped to
// `[0, image_height - 1] in image height coordinates. We do allow y1 > y2, in
// which case the sampled crop is an up-down flipped version of the original
// image. The width dimension is treated similarly. Normalized coordinates
// outside the `[0, 1]` range are allowed, in which case we use
// `extrapolation_value` to extrapolate the input image values.
// * box_ind: A 1-D tensor of shape `[num_boxes]` with int32 values in `[0, batch)`.
// The value of `box_ind[i]` specifies the image that the `i`-th box refers to.
// * image_size: A 1-D tensor with value `[batch, image_height, image_width, depth]`
// containing the original image size. Both `image_height` and `image_width` need
// to be positive.
class CropAndResizeGradImage {
 public:
  // Optional attribute setters for CropAndResizeGradImage :
  //
  // Method(StringPiece): Defaults to "bilinear"
  //     A string specifying the interpolation method. Only 'bilinear' is
  // supported for now.
  struct Attrs {
    Attrs Method(StringPiece x) {
      Attrs ret = *this;
      ret.method_ = x;
      return ret;
    }

    StringPiece method_ = "bilinear";
  };
  CropAndResizeGradImage(const ::tensorflow::Scope& scope,
                       ::tensorflow::ops::Input grads, ::tensorflow::ops::Input
                       boxes, ::tensorflow::ops::Input box_ind,
                       ::tensorflow::ops::Input image_size, DataType T);
  CropAndResizeGradImage(const ::tensorflow::Scope& scope,
                       ::tensorflow::ops::Input grads, ::tensorflow::ops::Input
                       boxes, ::tensorflow::ops::Input box_ind,
                       ::tensorflow::ops::Input image_size, DataType T, const
                       CropAndResizeGradImage::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Method(StringPiece x) {
    return Attrs().Method(x);
  }

  ::tensorflow::ops::Output output;
};

// Decode the first frame of a GIF-encoded image to a uint8 tensor.
//
// GIF with frame or transparency compression are not supported
// convert animated GIF from compressed to uncompressed by:
//
// convert $src.gif -coalesce $dst.gif
//
// Arguments:
// * scope: A Scope object
// * contents: 0-D.  The GIF-encoded image.
class DecodeGif {
 public:
  DecodeGif(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input contents);
  operator ::tensorflow::ops::Output() const { return image; }
  operator ::tensorflow::ops::Input() const { return image; }
  ::tensorflow::Node* node() const { return image.node(); }

  ::tensorflow::ops::Output image;
};

// Decode a JPEG-encoded image to a uint8 tensor.
//
// The attr `channels` indicates the desired number of color channels for the
// decoded image.
//
// Accepted values are:
//
// *   0: Use the number of channels in the JPEG-encoded image.
// *   1: output a grayscale image.
// *   3: output an RGB image.
//
// If needed, the JPEG-encoded image is transformed to match the requested number
// of color channels.
//
// The attr `ratio` allows downscaling the image by an integer factor during
// decoding.  Allowed values are: 1, 2, 4, and 8.  This is much faster than
// downscaling the image later.
//
// Arguments:
// * scope: A Scope object
// * contents: 0-D.  The JPEG-encoded image.
class DecodeJpeg {
 public:
  // Optional attribute setters for DecodeJpeg :
  //
  // Channels(int64): Defaults to 0
  //     Number of color channels for the decoded image.
  // Ratio(int64): Defaults to 1
  //     Downscaling ratio.
  // FancyUpscaling(bool): Defaults to true
  //     If true use a slower but nicer upscaling of the
  // chroma planes (yuv420/422 only).
  // TryRecoverTruncated(bool): Defaults to false
  //     If true try to recover an image from truncated input.
  // AcceptableFraction(float): Defaults to 1
  //     The minimum required fraction of lines before a truncated
  // input is accepted.
  struct Attrs {
    Attrs Channels(int64 x) {
      Attrs ret = *this;
      ret.channels_ = x;
      return ret;
    }

    Attrs Ratio(int64 x) {
      Attrs ret = *this;
      ret.ratio_ = x;
      return ret;
    }

    Attrs FancyUpscaling(bool x) {
      Attrs ret = *this;
      ret.fancy_upscaling_ = x;
      return ret;
    }

    Attrs TryRecoverTruncated(bool x) {
      Attrs ret = *this;
      ret.try_recover_truncated_ = x;
      return ret;
    }

    Attrs AcceptableFraction(float x) {
      Attrs ret = *this;
      ret.acceptable_fraction_ = x;
      return ret;
    }

    int64 channels_ = 0;
    int64 ratio_ = 1;
    bool fancy_upscaling_ = true;
    bool try_recover_truncated_ = false;
    float acceptable_fraction_ = 1.0f;
  };
  DecodeJpeg(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input contents);
  DecodeJpeg(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input contents,
           const DecodeJpeg::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return image; }
  operator ::tensorflow::ops::Input() const { return image; }
  ::tensorflow::Node* node() const { return image.node(); }

  static Attrs Channels(int64 x) {
    return Attrs().Channels(x);
  }
  static Attrs Ratio(int64 x) {
    return Attrs().Ratio(x);
  }
  static Attrs FancyUpscaling(bool x) {
    return Attrs().FancyUpscaling(x);
  }
  static Attrs TryRecoverTruncated(bool x) {
    return Attrs().TryRecoverTruncated(x);
  }
  static Attrs AcceptableFraction(float x) {
    return Attrs().AcceptableFraction(x);
  }

  ::tensorflow::ops::Output image;
};

// Decode a PNG-encoded image to a uint8 or uint16 tensor.
//
// The attr `channels` indicates the desired number of color channels for the
// decoded image.
//
// Accepted values are:
//
// *   0: Use the number of channels in the PNG-encoded image.
// *   1: output a grayscale image.
// *   3: output an RGB image.
// *   4: output an RGBA image.
//
// If needed, the PNG-encoded image is transformed to match the requested number
// of color channels.
//
// Arguments:
// * scope: A Scope object
// * contents: 0-D.  The PNG-encoded image.
class DecodePng {
 public:
  // Optional attribute setters for DecodePng :
  //
  // Channels(int64): Defaults to 0
  //     Number of color channels for the decoded image.
  // Dtype(DataType): Defaults to DT_UINT8
  struct Attrs {
    Attrs Channels(int64 x) {
      Attrs ret = *this;
      ret.channels_ = x;
      return ret;
    }

    Attrs Dtype(DataType x) {
      Attrs ret = *this;
      ret.dtype_ = x;
      return ret;
    }

    int64 channels_ = 0;
    DataType dtype_ = DT_UINT8;
  };
  DecodePng(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input contents);
  DecodePng(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input contents,
          const DecodePng::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return image; }
  operator ::tensorflow::ops::Input() const { return image; }
  ::tensorflow::Node* node() const { return image.node(); }

  static Attrs Channels(int64 x) {
    return Attrs().Channels(x);
  }
  static Attrs Dtype(DataType x) {
    return Attrs().Dtype(x);
  }

  ::tensorflow::ops::Output image;
};

// Draw bounding boxes on a batch of images.
//
// Outputs a copy of `images` but draws on top of the pixels zero or more bounding
// boxes specified by the locations in `boxes`. The coordinates of the each
// bounding box in `boxes` are encoded as `[y_min, x_min, y_max, x_max]`. The
// bounding box coordinates are floats in `[0.0, 1.0]` relative to the width and
// height of the underlying image.
//
// For example, if an image is 100 x 200 pixels and the bounding box is
// `[0.1, 0.2, 0.5, 0.9]`, the bottom-left and upper-right coordinates of the
// bounding box will be `(10, 40)` to `(50, 180)`.
//
// Parts of the bounding box may fall outside the image.
//
// Arguments:
// * scope: A Scope object
// * images: 4-D with shape `[batch, height, width, depth]`. A batch of images.
// * boxes: 3-D with shape `[batch, num_bounding_boxes, 4]` containing bounding
// boxes.
class DrawBoundingBoxes {
 public:
  DrawBoundingBoxes(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  images, ::tensorflow::ops::Input boxes);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// JPEG-encode an image.
//
// `image` is a 3-D uint8 Tensor of shape `[height, width, channels]`.
//
// The attr `format` can be used to override the color format of the encoded
// output.  Values can be:
//
// *   `''`: Use a default format based on the number of channels in the image.
// *   `grayscale`: Output a grayscale JPEG image.  The `channels` dimension
//     of `image` must be 1.
// *   `rgb`: Output an RGB JPEG image. The `channels` dimension
//     of `image` must be 3.
//
// If `format` is not specified or is the empty string, a default format is picked
// in function of the number of channels in `image`:
//
// *   1: Output a grayscale image.
// *   3: Output an RGB image.
//
// Arguments:
// * scope: A Scope object
// * image: 3-D with shape `[height, width, channels]`.
class EncodeJpeg {
 public:
  // Optional attribute setters for EncodeJpeg :
  //
  // Format(StringPiece): Defaults to ""
  //     Per pixel image format.
  // Quality(int64): Defaults to 95
  //     Quality of the compression from 0 to 100 (higher is better and slower).
  // Progressive(bool): Defaults to false
  //     If True, create a JPEG that loads progressively (coarse to fine).
  // OptimizeSize(bool): Defaults to false
  //     If True, spend CPU/RAM to reduce size with no quality change.
  // ChromaDownsampling(bool): Defaults to true
  //     See http://en.wikipedia.org/wiki/Chroma_subsampling.
  // DensityUnit(StringPiece): Defaults to "in"
  //     Unit used to specify `x_density` and `y_density`:
  // pixels per inch (`'in'`) or centimeter (`'cm'`).
  // XDensity(int64): Defaults to 300
  //     Horizontal pixels per density unit.
  // YDensity(int64): Defaults to 300
  //     Vertical pixels per density unit.
  // XmpMetadata(StringPiece): Defaults to ""
  //     If not empty, embed this XMP metadata in the image header.
  struct Attrs {
    Attrs Format(StringPiece x) {
      Attrs ret = *this;
      ret.format_ = x;
      return ret;
    }

    Attrs Quality(int64 x) {
      Attrs ret = *this;
      ret.quality_ = x;
      return ret;
    }

    Attrs Progressive(bool x) {
      Attrs ret = *this;
      ret.progressive_ = x;
      return ret;
    }

    Attrs OptimizeSize(bool x) {
      Attrs ret = *this;
      ret.optimize_size_ = x;
      return ret;
    }

    Attrs ChromaDownsampling(bool x) {
      Attrs ret = *this;
      ret.chroma_downsampling_ = x;
      return ret;
    }

    Attrs DensityUnit(StringPiece x) {
      Attrs ret = *this;
      ret.density_unit_ = x;
      return ret;
    }

    Attrs XDensity(int64 x) {
      Attrs ret = *this;
      ret.x_density_ = x;
      return ret;
    }

    Attrs YDensity(int64 x) {
      Attrs ret = *this;
      ret.y_density_ = x;
      return ret;
    }

    Attrs XmpMetadata(StringPiece x) {
      Attrs ret = *this;
      ret.xmp_metadata_ = x;
      return ret;
    }

    StringPiece format_ = "";
    int64 quality_ = 95;
    bool progressive_ = false;
    bool optimize_size_ = false;
    bool chroma_downsampling_ = true;
    StringPiece density_unit_ = "in";
    int64 x_density_ = 300;
    int64 y_density_ = 300;
    StringPiece xmp_metadata_ = "";
  };
  EncodeJpeg(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input image);
  EncodeJpeg(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input image,
           const EncodeJpeg::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return contents; }
  operator ::tensorflow::ops::Input() const { return contents; }
  ::tensorflow::Node* node() const { return contents.node(); }

  static Attrs Format(StringPiece x) {
    return Attrs().Format(x);
  }
  static Attrs Quality(int64 x) {
    return Attrs().Quality(x);
  }
  static Attrs Progressive(bool x) {
    return Attrs().Progressive(x);
  }
  static Attrs OptimizeSize(bool x) {
    return Attrs().OptimizeSize(x);
  }
  static Attrs ChromaDownsampling(bool x) {
    return Attrs().ChromaDownsampling(x);
  }
  static Attrs DensityUnit(StringPiece x) {
    return Attrs().DensityUnit(x);
  }
  static Attrs XDensity(int64 x) {
    return Attrs().XDensity(x);
  }
  static Attrs YDensity(int64 x) {
    return Attrs().YDensity(x);
  }
  static Attrs XmpMetadata(StringPiece x) {
    return Attrs().XmpMetadata(x);
  }

  ::tensorflow::ops::Output contents;
};

// PNG-encode an image.
//
// `image` is a 3-D uint8 or uint16 Tensor of shape `[height, width, channels]`
// where `channels` is:
//
// *   1: for grayscale.
// *   2: for grayscale + alpha.
// *   3: for RGB.
// *   4: for RGBA.
//
// The ZLIB compression level, `compression`, can be -1 for the PNG-encoder
// default or a value from 0 to 9.  9 is the highest compression level, generating
// the smallest output, but is slower.
//
// Arguments:
// * scope: A Scope object
// * image: 3-D with shape `[height, width, channels]`.
class EncodePng {
 public:
  // Optional attribute setters for EncodePng :
  //
  // Compression(int64): Defaults to -1
  //     Compression level.
  struct Attrs {
    Attrs Compression(int64 x) {
      Attrs ret = *this;
      ret.compression_ = x;
      return ret;
    }

    int64 compression_ = -1;
  };
  EncodePng(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input image);
  EncodePng(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input image,
          const EncodePng::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return contents; }
  operator ::tensorflow::ops::Input() const { return contents; }
  ::tensorflow::Node* node() const { return contents.node(); }

  static Attrs Compression(int64 x) {
    return Attrs().Compression(x);
  }

  ::tensorflow::ops::Output contents;
};

// Extracts a glimpse from the input tensor.
//
// Returns a set of windows called glimpses extracted at location
// `offsets` from the input tensor. If the windows only partially
// overlaps the inputs, the non overlapping areas will be filled with
// random noise.
//
// The result is a 4-D tensor of shape `[batch_size, glimpse_height,
// glimpse_width, channels]`. The channels and batch dimensions are the
// same as that of the input tensor. The height and width of the output
// windows are specified in the `size` parameter.
//
// The argument `normalized` and `centered` controls how the windows are built:
//
// * If the coordinates are normalized but not centered, 0.0 and 1.0
//   correspond to the minimum and maximum of each height and width
//   dimension.
// * If the coordinates are both normalized and centered, they range from
//   -1.0 to 1.0. The coordinates (-1.0, -1.0) correspond to the upper
//   left corner, the lower right corner is located at (1.0, 1.0) and the
//   center is at (0, 0).
// * If the coordinates are not normalized they are interpreted as
//   numbers of pixels.
//
// Arguments:
// * scope: A Scope object
// * input: A 4-D float tensor of shape `[batch_size, height, width, channels]`.
// * size: A 1-D tensor of 2 elements containing the size of the glimpses
// to extract.  The glimpse height must be specified first, following
// by the glimpse width.
// * offsets: A 2-D integer tensor of shape `[batch_size, 2]` containing
// the x, y locations of the center of each window.
class ExtractGlimpse {
 public:
  // Optional attribute setters for ExtractGlimpse :
  //
  // Centered(bool): Defaults to true
  //     indicates if the offset coordinates are centered relative to
  // the image, in which case the (0, 0) offset is relative to the center
  // of the input images. If false, the (0,0) offset corresponds to the
  // upper left corner of the input images.
  // Normalized(bool): Defaults to true
  //     indicates if the offset coordinates are normalized.
  // UniformNoise(bool): Defaults to true
  //     indicates if the noise should be generated using a
  // uniform distribution or a Gaussian distribution.
  struct Attrs {
    Attrs Centered(bool x) {
      Attrs ret = *this;
      ret.centered_ = x;
      return ret;
    }

    Attrs Normalized(bool x) {
      Attrs ret = *this;
      ret.normalized_ = x;
      return ret;
    }

    Attrs UniformNoise(bool x) {
      Attrs ret = *this;
      ret.uniform_noise_ = x;
      return ret;
    }

    bool centered_ = true;
    bool normalized_ = true;
    bool uniform_noise_ = true;
  };
  ExtractGlimpse(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               input, ::tensorflow::ops::Input size, ::tensorflow::ops::Input
               offsets);
  ExtractGlimpse(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               input, ::tensorflow::ops::Input size, ::tensorflow::ops::Input
               offsets, const ExtractGlimpse::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return glimpse; }
  operator ::tensorflow::ops::Input() const { return glimpse; }
  ::tensorflow::Node* node() const { return glimpse.node(); }

  static Attrs Centered(bool x) {
    return Attrs().Centered(x);
  }
  static Attrs Normalized(bool x) {
    return Attrs().Normalized(x);
  }
  static Attrs UniformNoise(bool x) {
    return Attrs().UniformNoise(x);
  }

  ::tensorflow::ops::Output glimpse;
};

// Convert one or more images from HSV to RGB.
//
// Outputs a tensor of the same shape as the `images` tensor, containing the RGB
// value of the pixels. The output is only well defined if the value in `images`
// are in `[0,1]`.
//
// See `rgb_to_hsv` for a description of the HSV encoding.
//
// Arguments:
// * scope: A Scope object
// * images: 1-D or higher rank. HSV data to convert. Last dimension must be size 3.
class HSVToRGB {
 public:
  HSVToRGB(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input images);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Greedily selects a subset of bounding boxes in descending order of score,
//
// pruning away boxes that have high intersection-over-union (IOU) overlap
// with previously selected boxes.  Bounding boxes are supplied as
// [y1, x1, y2, x2], where (y1, x1) and (y2, x2) are the coordinates of any
// diagonal pair of box corners and the coordinates can be provided as normalized
// (i.e., lying in the interval [0, 1]) or absolute.  Note that this algorithm
// is agnostic to where the origin is in the coordinate system.  Note that this
// algorithm is invariant to orthogonal transformations and translations
// of the coordinate system; thus translating or reflections of the coordinate
// system result in the same boxes being selected by the algorithm.
//
// The output of this operation is a set of integers indexing into the input
// collection of bounding boxes representing the selected boxes.  The bounding
// box coordinates corresponding to the selected indices can then be obtained
// using the `tf.gather operation`.  For example:
//
//   selected_indices = tf.image.non_max_suppression(
//       boxes, scores, max_output_size, iou_threshold)
//   selected_boxes = tf.gather(boxes, selected_indices)
//
// Arguments:
// * scope: A Scope object
// * boxes: A 2-D float tensor of shape `[num_boxes, 4]`.
// * scores: A 1-D float tensor of shape `[num_boxes]` representing a single
// score corresponding to each box (each row of boxes).
// * max_output_size: A scalar integer tensor representing the maximum number of
// boxes to be selected by non max suppression.
class NonMaxSuppression {
 public:
  // Optional attribute setters for NonMaxSuppression :
  //
  // IouThreshold(float): Defaults to 0.5
  //     A float representing the threshold for deciding whether boxes
  // overlap too much with respect to IOU.
  struct Attrs {
    Attrs IouThreshold(float x) {
      Attrs ret = *this;
      ret.iou_threshold_ = x;
      return ret;
    }

    float iou_threshold_ = 0.5f;
  };
  NonMaxSuppression(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  boxes, ::tensorflow::ops::Input scores,
                  ::tensorflow::ops::Input max_output_size);
  NonMaxSuppression(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  boxes, ::tensorflow::ops::Input scores,
                  ::tensorflow::ops::Input max_output_size, const
                  NonMaxSuppression::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return selected_indices; }
  operator ::tensorflow::ops::Input() const { return selected_indices; }
  ::tensorflow::Node* node() const { return selected_indices.node(); }

  static Attrs IouThreshold(float x) {
    return Attrs().IouThreshold(x);
  }

  ::tensorflow::ops::Output selected_indices;
};

// Converts one or more images from RGB to HSV.
//
// Outputs a tensor of the same shape as the `images` tensor, containing the HSV
// value of the pixels. The output is only well defined if the value in `images`
// are in `[0,1]`.
//
// `output[..., 0]` contains hue, `output[..., 1]` contains saturation, and
// `output[..., 2]` contains value. All HSV values are in `[0,1]`. A hue of 0
// corresponds to pure red, hue 1/3 is pure green, and 2/3 is pure blue.
//
// Arguments:
// * scope: A Scope object
// * images: 1-D or higher rank. RGB data to convert. Last dimension must be size 3.
class RGBToHSV {
 public:
  RGBToHSV(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input images);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Randomly crop `image`.
//
// DEPRECATED at GraphDef version 8:
// Random crop is now pure Python.
//
// `size` is a 1-D int64 tensor with 2 elements representing the crop height and
// width.  The values must be non negative.
//
// This Op picks a random location in `image` and crops a `height` by `width`
// rectangle from that location.  The random location is picked so the cropped
// area will fit inside the original image.
//
// Arguments:
// * scope: A Scope object
// * image: 3-D of shape `[height, width, channels]`.
// * size: 1-D of length 2 containing: `crop_height`, `crop_width`..
class RandomCrop {
 public:
  // Optional attribute setters for RandomCrop :
  //
  // Seed(int64): Defaults to 0
  //     If either seed or seed2 are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     An second seed to avoid seed collision.
  struct Attrs {
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

    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  RandomCrop(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input image,
           ::tensorflow::ops::Input size);
  RandomCrop(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input image,
           ::tensorflow::ops::Input size, const RandomCrop::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output output;
};

// Resize `images` to `size` using area interpolation.
//
// Input images can be of different types but output images are always float.
//
// Arguments:
// * scope: A Scope object
// * images: 4-D with shape `[batch, height, width, channels]`.
// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
// new size for the images.
class ResizeArea {
 public:
  // Optional attribute setters for ResizeArea :
  //
  // AlignCorners(bool): Defaults to false
  //     If true, rescale input by (new_height - 1) / (height - 1), which
  // exactly aligns the 4 corners of images and resized images. If false, rescale
  // by new_height / height. Treat similarly the width dimension.
  struct Attrs {
    Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeArea(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input images,
           ::tensorflow::ops::Input size);
  ResizeArea(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input images,
           ::tensorflow::ops::Input size, const ResizeArea::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return resized_images; }
  operator ::tensorflow::ops::Input() const { return resized_images; }
  ::tensorflow::Node* node() const { return resized_images.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::ops::Output resized_images;
};

// Resize `images` to `size` using bicubic interpolation.
//
// Input images can be of different types but output images are always float.
//
// Arguments:
// * scope: A Scope object
// * images: 4-D with shape `[batch, height, width, channels]`.
// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
// new size for the images.
class ResizeBicubic {
 public:
  // Optional attribute setters for ResizeBicubic :
  //
  // AlignCorners(bool): Defaults to false
  //     If true, rescale input by (new_height - 1) / (height - 1), which
  // exactly aligns the 4 corners of images and resized images. If false, rescale
  // by new_height / height. Treat similarly the width dimension.
  struct Attrs {
    Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeBicubic(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              images, ::tensorflow::ops::Input size);
  ResizeBicubic(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              images, ::tensorflow::ops::Input size, const
              ResizeBicubic::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return resized_images; }
  operator ::tensorflow::ops::Input() const { return resized_images; }
  ::tensorflow::Node* node() const { return resized_images.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::ops::Output resized_images;
};

// Resize `images` to `size` using bilinear interpolation.
//
// Input images can be of different types but output images are always float.
//
// Arguments:
// * scope: A Scope object
// * images: 4-D with shape `[batch, height, width, channels]`.
// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
// new size for the images.
class ResizeBilinear {
 public:
  // Optional attribute setters for ResizeBilinear :
  //
  // AlignCorners(bool): Defaults to false
  //     If true, rescale input by (new_height - 1) / (height - 1), which
  // exactly aligns the 4 corners of images and resized images. If false, rescale
  // by new_height / height. Treat similarly the width dimension.
  struct Attrs {
    Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeBilinear(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               images, ::tensorflow::ops::Input size);
  ResizeBilinear(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               images, ::tensorflow::ops::Input size, const
               ResizeBilinear::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return resized_images; }
  operator ::tensorflow::ops::Input() const { return resized_images; }
  ::tensorflow::Node* node() const { return resized_images.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::ops::Output resized_images;
};

// Computes the gradient of bilinear interpolation.
//
// Arguments:
// * scope: A Scope object
// * grads: 4-D with shape `[batch, height, width, channels]`.
// * original_image: 4-D with shape `[batch, orig_height, orig_width, channels]`,
// The image tensor that was resized.
class ResizeBilinearGrad {
 public:
  // Optional attribute setters for ResizeBilinearGrad :
  //
  // AlignCorners(bool): Defaults to false
  //     If true, rescale grads by (orig_height - 1) / (height - 1), which
  // exactly aligns the 4 corners of grads and original_image. If false, rescale by
  // orig_height / height. Treat similarly the width dimension.
  struct Attrs {
    Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeBilinearGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   grads, ::tensorflow::ops::Input original_image);
  ResizeBilinearGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   grads, ::tensorflow::ops::Input original_image, const
                   ResizeBilinearGrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::ops::Output output;
};

// Resize `images` to `size` using nearest neighbor interpolation.
//
// Arguments:
// * scope: A Scope object
// * images: 4-D with shape `[batch, height, width, channels]`.
// * size: = A 1-D int32 Tensor of 2 elements: `new_height, new_width`.  The
// new size for the images.
class ResizeNearestNeighbor {
 public:
  // Optional attribute setters for ResizeNearestNeighbor :
  //
  // AlignCorners(bool): Defaults to false
  //     If true, rescale input by (new_height - 1) / (height - 1), which
  // exactly aligns the 4 corners of images and resized images. If false, rescale
  // by new_height / height. Treat similarly the width dimension.
  struct Attrs {
    Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeNearestNeighbor(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input images, ::tensorflow::ops::Input
                      size);
  ResizeNearestNeighbor(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input images, ::tensorflow::ops::Input
                      size, const ResizeNearestNeighbor::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return resized_images; }
  operator ::tensorflow::ops::Input() const { return resized_images; }
  ::tensorflow::Node* node() const { return resized_images.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::ops::Output resized_images;
};

// Computes the gradient of nearest neighbor interpolation.
//
// Arguments:
// * scope: A Scope object
// * grads: 4-D with shape `[batch, height, width, channels]`.
// * size: = A 1-D int32 Tensor of 2 elements: `orig_height, orig_width`. The
// original input size.
class ResizeNearestNeighborGrad {
 public:
  // Optional attribute setters for ResizeNearestNeighborGrad :
  //
  // AlignCorners(bool): Defaults to false
  //     If true, rescale grads by (orig_height - 1) / (height - 1), which
  // exactly aligns the 4 corners of grads and original_image. If false, rescale by
  // orig_height / height. Treat similarly the width dimension.
  struct Attrs {
    Attrs AlignCorners(bool x) {
      Attrs ret = *this;
      ret.align_corners_ = x;
      return ret;
    }

    bool align_corners_ = false;
  };
  ResizeNearestNeighborGrad(const ::tensorflow::Scope& scope,
                          ::tensorflow::ops::Input grads,
                          ::tensorflow::ops::Input size);
  ResizeNearestNeighborGrad(const ::tensorflow::Scope& scope,
                          ::tensorflow::ops::Input grads,
                          ::tensorflow::ops::Input size, const
                          ResizeNearestNeighborGrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs AlignCorners(bool x) {
    return Attrs().AlignCorners(x);
  }

  ::tensorflow::ops::Output output;
};

// Generate a single randomly distorted bounding box for an image.
//
// Bounding box annotations are often supplied in addition to ground-truth labels
// in image recognition or object localization tasks. A common technique for
// training such a system is to randomly distort an image while preserving
// its content, i.e. *data augmentation*. This Op outputs a randomly distorted
// localization of an object, i.e. bounding box, given an `image_size`,
// `bounding_boxes` and a series of constraints.
//
// The output of this Op is a single bounding box that may be used to crop the
// original image. The output is returned as 3 tensors: `begin`, `size` and
// `bboxes`. The first 2 tensors can be fed directly into `tf.slice` to crop the
// image. The latter may be supplied to `tf.image.draw_bounding_boxes` to visualize
// what the bounding box looks like.
//
// Bounding boxes are supplied and returned as `[y_min, x_min, y_max, x_max]`. The
// bounding box coordinates are floats in `[0.0, 1.0]` relative to the width and
// height of the underlying image.
//
// For example,
//
// ```python
//     # Generate a single distorted bounding box.
//     begin, size, bbox_for_draw = tf.image.sample_distorted_bounding_box(
//         tf.shape(image),
//         bounding_boxes=bounding_boxes)
//
//     # Draw the bounding box in an image summary.
//     image_with_box = tf.image.draw_bounding_boxes(tf.expand_dims(image, 0),
//                                                   bbox_for_draw)
//     tf.image_summary('images_with_box', image_with_box)
//
//     # Employ the bounding box to distort the image.
//     distorted_image = tf.slice(image, begin, size)
// ```
//
// Note that if no bounding box information is available, setting
// `use_image_if_no_bounding_boxes = true` will assume there is a single implicit
// bounding box covering the whole image. If `use_image_if_no_bounding_boxes` is
// false and no bounding boxes are supplied, an error is raised.
//
// Arguments:
// * scope: A Scope object
// * image_size: 1-D, containing `[height, width, channels]`.
// * bounding_boxes: 3-D with shape `[batch, N, 4]` describing the N bounding boxes
// associated with the image.
class SampleDistortedBoundingBox {
 public:
  // Optional attribute setters for SampleDistortedBoundingBox :
  //
  // Seed(int64): Defaults to 0
  //     If either `seed` or `seed2` are set to non-zero, the random number
  // generator is seeded by the given `seed`.  Otherwise, it is seeded by a random
  // seed.
  // Seed2(int64): Defaults to 0
  //     A second seed to avoid seed collision.
  // MinObjectCovered(float): Defaults to 0.1
  //     The cropped area of the image must contain at least this
  // fraction of any bounding box supplied.
  // AspectRatioRange(const gtl::ArraySlice<float>&): Defaults to [0.75, 1.33]
  //     The cropped area of the image must have an aspect ratio =
  // width / height within this range.
  // AreaRange(const gtl::ArraySlice<float>&): Defaults to [0.05, 1]
  //     The cropped area of the image must contain a fraction of the
  // supplied image within in this range.
  // MaxAttempts(int64): Defaults to 100
  //     Number of attempts at generating a cropped region of the image
  // of the specified constraints. After `max_attempts` failures, return the entire
  // image.
  // UseImageIfNoBoundingBoxes(bool): Defaults to false
  //     Controls behavior if no bounding boxes supplied.
  // If true, assume an implicit bounding box covering the whole input. If false,
  // raise an error.
  struct Attrs {
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

    Attrs MinObjectCovered(float x) {
      Attrs ret = *this;
      ret.min_object_covered_ = x;
      return ret;
    }

    Attrs AspectRatioRange(const gtl::ArraySlice<float>& x) {
      Attrs ret = *this;
      ret.aspect_ratio_range_ = x;
      return ret;
    }

    Attrs AreaRange(const gtl::ArraySlice<float>& x) {
      Attrs ret = *this;
      ret.area_range_ = x;
      return ret;
    }

    Attrs MaxAttempts(int64 x) {
      Attrs ret = *this;
      ret.max_attempts_ = x;
      return ret;
    }

    Attrs UseImageIfNoBoundingBoxes(bool x) {
      Attrs ret = *this;
      ret.use_image_if_no_bounding_boxes_ = x;
      return ret;
    }

    int64 seed_ = 0;
    int64 seed2_ = 0;
    float min_object_covered_ = 0.1f;
    gtl::ArraySlice<float> aspect_ratio_range_ = {0.75f, 1.33f};
    gtl::ArraySlice<float> area_range_ = {0.05f, 1.0f};
    int64 max_attempts_ = 100;
    bool use_image_if_no_bounding_boxes_ = false;
  };
  SampleDistortedBoundingBox(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input image_size,
                           ::tensorflow::ops::Input bounding_boxes);
  SampleDistortedBoundingBox(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input image_size,
                           ::tensorflow::ops::Input bounding_boxes, const
                           SampleDistortedBoundingBox::Attrs& attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }
  static Attrs MinObjectCovered(float x) {
    return Attrs().MinObjectCovered(x);
  }
  static Attrs AspectRatioRange(const gtl::ArraySlice<float>& x) {
    return Attrs().AspectRatioRange(x);
  }
  static Attrs AreaRange(const gtl::ArraySlice<float>& x) {
    return Attrs().AreaRange(x);
  }
  static Attrs MaxAttempts(int64 x) {
    return Attrs().MaxAttempts(x);
  }
  static Attrs UseImageIfNoBoundingBoxes(bool x) {
    return Attrs().UseImageIfNoBoundingBoxes(x);
  }

  ::tensorflow::ops::Output begin;
  ::tensorflow::ops::Output size;
  ::tensorflow::ops::Output bboxes;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_IMAGE_OPS_H_
