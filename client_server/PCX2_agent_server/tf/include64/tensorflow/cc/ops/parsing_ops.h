// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_PARSING_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_PARSING_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Convert CSV records to tensors. Each column maps to one tensor.
//
// RFC 4180 format is expected for the CSV records.
// (https://tools.ietf.org/html/rfc4180)
// Note that we allow leading and trailing spaces with int or float field.
//
// Arguments:
// * scope: A Scope object
// * records: Each string is a record/row in the csv and all records should have
// the same format.
// * record_defaults: One tensor per column of the input record, with either a
// scalar default value for that column or empty if the column is required.
class DecodeCSV {
 public:
  // Optional attribute setters for DecodeCSV :
  //
  // FieldDelim(StringPiece): Defaults to ","
  //     delimiter to separate fields in a record.
  struct Attrs {
    Attrs FieldDelim(StringPiece x) {
      Attrs ret = *this;
      ret.field_delim_ = x;
      return ret;
    }

    StringPiece field_delim_ = ",";
  };
  DecodeCSV(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input records,
          ::tensorflow::ops::InputList record_defaults);
  DecodeCSV(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input records,
          ::tensorflow::ops::InputList record_defaults, const DecodeCSV::Attrs&
          attrs);
  ::tensorflow::ops::Output operator[](size_t index) const { return output[index]; }


  static Attrs FieldDelim(StringPiece x) {
    return Attrs().FieldDelim(x);
  }

  ::tensorflow::ops::OutputList output;
};

// Convert JSON-encoded Example records to binary protocol buffer strings.
//
// This op translates a tensor containing Example records, encoded using
// the [standard JSON
// mapping](https://developers.google.com/protocol-buffers/docs/proto3#json),
// into a tensor containing the same records encoded as binary protocol
// buffers. The resulting tensor can then be fed to any of the other
// Example-parsing ops.
//
// Arguments:
// * scope: A Scope object
// * json_examples: Each string is a JSON object serialized according to the JSON
// mapping of the Example proto.
class DecodeJSONExample {
 public:
  DecodeJSONExample(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  json_examples);
  operator ::tensorflow::ops::Output() const { return binary_examples; }
  operator ::tensorflow::ops::Input() const { return binary_examples; }
  ::tensorflow::Node* node() const { return binary_examples.node(); }

  ::tensorflow::ops::Output binary_examples;
};

// Reinterpret the bytes of a string as a vector of numbers.
//
// Arguments:
// * scope: A Scope object
// * bytes: All the elements must have the same length.
class DecodeRaw {
 public:
  // Optional attribute setters for DecodeRaw :
  //
  // LittleEndian(bool): Defaults to true
  //     Whether the input `bytes` are in little-endian order.
  // Ignored for `out_type` values that are stored in a single byte like
  // `uint8`.
  struct Attrs {
    Attrs LittleEndian(bool x) {
      Attrs ret = *this;
      ret.little_endian_ = x;
      return ret;
    }

    bool little_endian_ = true;
  };
  DecodeRaw(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input bytes,
          DataType out_type);
  DecodeRaw(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input bytes,
          DataType out_type, const DecodeRaw::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs LittleEndian(bool x) {
    return Attrs().LittleEndian(x);
  }

  ::tensorflow::ops::Output output;
};

// Transforms a vector of brain.Example protos (as strings) into typed tensors.
//
// Arguments:
// * scope: A Scope object
// * serialized: A vector containing a batch of binary serialized Example protos.
// * names: A vector containing the names of the serialized protos.
// May contain, for example, table key (descriptive) names for the
// corresponding serialized protos.  These are purely useful for debugging
// purposes, and the presence of values here has no effect on the output.
// May also be an empty vector if no names are available.
// If non-empty, this vector must be the same length as "serialized".
// * sparse_keys: A list of Nsparse string Tensors (scalars).
// The keys expected in the Examples' features associated with sparse values.
// * dense_keys: A list of Ndense string Tensors (scalars).
// The keys expected in the Examples' features associated with dense values.
// * dense_defaults: A list of Ndense Tensors (some may be empty).
// dense_defaults[j] provides default values
// when the example's feature_map lacks dense_key[j].  If an empty Tensor is
// provided for dense_defaults[j], then the Feature dense_keys[j] is required.
// The input type is inferred from dense_defaults[j], even when it's empty.
// If dense_defaults[j] is not empty, its shape must match dense_shapes[j].
// * sparse_types:
//     A list of Nsparse types; the data types of data in each Feature
// given in sparse_keys.
// Currently the ParseExample supports DT_FLOAT (FloatList),
// DT_INT64 (Int64List), and DT_STRING (BytesList).
// * dense_shapes:
//     A list of Ndense shapes; the shapes of data in each Feature
// given in dense_keys.
// The number of elements in the Feature corresponding to dense_key[j]
// must always equal dense_shapes[j].NumEntries().
// If dense_shapes[j] == (D0, D1, ..., DN) then the shape of output
// Tensor dense_values[j] will be (|serialized|, D0, D1, ..., DN):
// The dense outputs are just the inputs row-stacked by batch.
class ParseExample {
 public:
  ParseExample(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
             serialized, ::tensorflow::ops::Input names,
             ::tensorflow::ops::InputList sparse_keys,
             ::tensorflow::ops::InputList dense_keys,
             ::tensorflow::ops::InputList dense_defaults, const DataTypeSlice&
             sparse_types, const gtl::ArraySlice<TensorShape>& dense_shapes);

  ::tensorflow::ops::OutputList sparse_indices;
  ::tensorflow::ops::OutputList sparse_values;
  ::tensorflow::ops::OutputList sparse_shapes;
  ::tensorflow::ops::OutputList dense_values;
};

// Transforms a scalar brain.SequenceExample proto (as strings) into typed tensors.
//
// Arguments:
// * scope: A Scope object
// * serialized: A scalar containing a binary serialized SequenceExample proto.
// * feature_list_dense_missing_assumed_empty: A vector listing the
// FeatureList keys which may be missing from the SequenceExample.  If the
// associated FeatureList is missing, it is treated as empty.  By default,
// any FeatureList not listed in this vector must exist in the SequenceExample.
// * context_sparse_keys: A list of Ncontext_sparse string Tensors (scalars).
// The keys expected in the Examples' features associated with context_sparse
// values.
// * context_dense_keys: A list of Ncontext_dense string Tensors (scalars).
// The keys expected in the SequenceExamples' context features associated with
// dense values.
// * feature_list_sparse_keys: A list of Nfeature_list_sparse string Tensors
// (scalars).  The keys expected in the FeatureLists associated with sparse
// values.
// * feature_list_dense_keys: A list of Nfeature_list_dense string Tensors (scalars).
// The keys expected in the SequenceExamples' feature_lists associated
// with lists of dense values.
// * context_dense_defaults: A list of Ncontext_dense Tensors (some may be empty).
// context_dense_defaults[j] provides default values
// when the SequenceExample's context map lacks context_dense_key[j].
// If an empty Tensor is provided for context_dense_defaults[j],
// then the Feature context_dense_keys[j] is required.
// The input type is inferred from context_dense_defaults[j], even when it's
// empty.  If context_dense_defaults[j] is not empty, its shape must match
// context_dense_shapes[j].
// * debug_name: A scalar containing the name of the serialized proto.
// May contain, for example, table key (descriptive) name for the
// corresponding serialized proto.  This is purely useful for debugging
// purposes, and the presence of values here has no effect on the output.
// May also be an empty scalar if no name is available.
class ParseSingleSequenceExample {
 public:
  // Optional attribute setters for ParseSingleSequenceExample :
  //
  // ContextSparseTypes(const DataTypeSlice&): Defaults to []
  //     A list of Ncontext_sparse types; the data types of data in
  // each context Feature given in context_sparse_keys.
  // Currently the ParseSingleSequenceExample supports DT_FLOAT (FloatList),
  // DT_INT64 (Int64List), and DT_STRING (BytesList).
  // FeatureListDenseTypes(const DataTypeSlice&): Defaults to []
  // ContextDenseShapes(const gtl::ArraySlice<TensorShape>&): Defaults to []
  //     A list of Ncontext_dense shapes; the shapes of data in
  // each context Feature given in context_dense_keys.
  // The number of elements in the Feature corresponding to context_dense_key[j]
  // must always equal context_dense_shapes[j].NumEntries().
  // The shape of context_dense_values[j] will match context_dense_shapes[j].
  // FeatureListSparseTypes(const DataTypeSlice&): Defaults to []
  //     A list of Nfeature_list_sparse types; the data types
  // of data in each FeatureList given in feature_list_sparse_keys.
  // Currently the ParseSingleSequenceExample supports DT_FLOAT (FloatList),
  // DT_INT64 (Int64List), and DT_STRING (BytesList).
  // FeatureListDenseShapes(const gtl::ArraySlice<TensorShape>&): Defaults to []
  //     A list of Nfeature_list_dense shapes; the shapes of
  // data in each FeatureList given in feature_list_dense_keys.
  // The shape of each Feature in the FeatureList corresponding to
  // feature_list_dense_key[j] must always equal
  // feature_list_dense_shapes[j].NumEntries().
  struct Attrs {
    Attrs ContextSparseTypes(const DataTypeSlice& x) {
      Attrs ret = *this;
      ret.context_sparse_types_ = x;
      return ret;
    }

    Attrs FeatureListDenseTypes(const DataTypeSlice& x) {
      Attrs ret = *this;
      ret.feature_list_dense_types_ = x;
      return ret;
    }

    Attrs ContextDenseShapes(const gtl::ArraySlice<TensorShape>& x) {
      Attrs ret = *this;
      ret.context_dense_shapes_ = x;
      return ret;
    }

    Attrs FeatureListSparseTypes(const DataTypeSlice& x) {
      Attrs ret = *this;
      ret.feature_list_sparse_types_ = x;
      return ret;
    }

    Attrs FeatureListDenseShapes(const gtl::ArraySlice<TensorShape>& x) {
      Attrs ret = *this;
      ret.feature_list_dense_shapes_ = x;
      return ret;
    }

    DataTypeSlice context_sparse_types_ = {};
    DataTypeSlice feature_list_dense_types_ = {};
    gtl::ArraySlice<TensorShape> context_dense_shapes_ = {};
    DataTypeSlice feature_list_sparse_types_ = {};
    gtl::ArraySlice<TensorShape> feature_list_dense_shapes_ = {};
  };
  ParseSingleSequenceExample(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input serialized,
                           ::tensorflow::ops::Input
                           feature_list_dense_missing_assumed_empty,
                           ::tensorflow::ops::InputList context_sparse_keys,
                           ::tensorflow::ops::InputList context_dense_keys,
                           ::tensorflow::ops::InputList
                           feature_list_sparse_keys,
                           ::tensorflow::ops::InputList
                           feature_list_dense_keys,
                           ::tensorflow::ops::InputList context_dense_defaults,
                           ::tensorflow::ops::Input debug_name);
  ParseSingleSequenceExample(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input serialized,
                           ::tensorflow::ops::Input
                           feature_list_dense_missing_assumed_empty,
                           ::tensorflow::ops::InputList context_sparse_keys,
                           ::tensorflow::ops::InputList context_dense_keys,
                           ::tensorflow::ops::InputList
                           feature_list_sparse_keys,
                           ::tensorflow::ops::InputList
                           feature_list_dense_keys,
                           ::tensorflow::ops::InputList context_dense_defaults,
                           ::tensorflow::ops::Input debug_name, const
                           ParseSingleSequenceExample::Attrs& attrs);

  static Attrs ContextSparseTypes(const DataTypeSlice& x) {
    return Attrs().ContextSparseTypes(x);
  }
  static Attrs FeatureListDenseTypes(const DataTypeSlice& x) {
    return Attrs().FeatureListDenseTypes(x);
  }
  static Attrs ContextDenseShapes(const gtl::ArraySlice<TensorShape>& x) {
    return Attrs().ContextDenseShapes(x);
  }
  static Attrs FeatureListSparseTypes(const DataTypeSlice& x) {
    return Attrs().FeatureListSparseTypes(x);
  }
  static Attrs FeatureListDenseShapes(const gtl::ArraySlice<TensorShape>& x) {
    return Attrs().FeatureListDenseShapes(x);
  }

  ::tensorflow::ops::OutputList context_sparse_indices;
  ::tensorflow::ops::OutputList context_sparse_values;
  ::tensorflow::ops::OutputList context_sparse_shapes;
  ::tensorflow::ops::OutputList context_dense_values;
  ::tensorflow::ops::OutputList feature_list_sparse_indices;
  ::tensorflow::ops::OutputList feature_list_sparse_values;
  ::tensorflow::ops::OutputList feature_list_sparse_shapes;
  ::tensorflow::ops::OutputList feature_list_dense_values;
};

// Transforms a serialized tensorflow.TensorProto proto into a Tensor.
//
// Arguments:
// * scope: A Scope object
// * serialized: A scalar string containing a serialized TensorProto proto.
// * out_type:
//     The type of the serialized tensor.  The provided type must match the
// type of the serialized tensor and no implicit conversion will take place.
class ParseTensor {
 public:
  ParseTensor(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
            serialized, DataType out_type);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Converts each string in the input Tensor to the specified numeric type.
//
// (Note that int32 overflow results in an error while float overflow
// results in a rounded value.)
//
// Arguments:
// * scope: A Scope object
class StringToNumber {
 public:
  // Optional attribute setters for StringToNumber :
  //
  // OutType(DataType): Defaults to DT_FLOAT
  //     The numeric type to interpret each string in `string_tensor` as.
  struct Attrs {
    Attrs OutType(DataType x) {
      Attrs ret = *this;
      ret.out_type_ = x;
      return ret;
    }

    DataType out_type_ = DT_FLOAT;
  };
  StringToNumber(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               string_tensor);
  StringToNumber(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               string_tensor, const StringToNumber::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs OutType(DataType x) {
    return Attrs().OutType(x);
  }

  ::tensorflow::ops::Output output;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_PARSING_OPS_H_
