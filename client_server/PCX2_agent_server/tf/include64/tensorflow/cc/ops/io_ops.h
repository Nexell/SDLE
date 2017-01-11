// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_IO_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_IO_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// A Reader that outputs fixed-length records from a file.
//
// Arguments:
// * scope: A Scope object
class FixedLengthRecordReader {
 public:
  // Optional attribute setters for FixedLengthRecordReader :
  //
  // HeaderBytes(int64): Defaults to 0
  // FooterBytes(int64): Defaults to 0
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this reader is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this reader is named in the given bucket
  // with this shared_name. Otherwise, the node name is used instead.
  struct Attrs {
    Attrs HeaderBytes(int64 x) {
      Attrs ret = *this;
      ret.header_bytes_ = x;
      return ret;
    }

    Attrs FooterBytes(int64 x) {
      Attrs ret = *this;
      ret.footer_bytes_ = x;
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

    int64 header_bytes_ = 0;
    int64 footer_bytes_ = 0;
    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  FixedLengthRecordReader(const ::tensorflow::Scope& scope, int64 record_bytes);
  FixedLengthRecordReader(const ::tensorflow::Scope& scope, int64 record_bytes,
                        const FixedLengthRecordReader::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return reader_handle; }
  operator ::tensorflow::ops::Input() const { return reader_handle; }
  ::tensorflow::Node* node() const { return reader_handle.node(); }

  static Attrs HeaderBytes(int64 x) {
    return Attrs().HeaderBytes(x);
  }
  static Attrs FooterBytes(int64 x) {
    return Attrs().FooterBytes(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output reader_handle;
};

// A Reader that outputs the queued work as both the key and value.
//
// To use, enqueue strings in a Queue.  ReaderRead will take the front
// work string and output (work, work).
//
// Arguments:
// * scope: A Scope object
class IdentityReader {
 public:
  // Optional attribute setters for IdentityReader :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this reader is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this reader is named in the given bucket
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
  IdentityReader(const ::tensorflow::Scope& scope);
  IdentityReader(const ::tensorflow::Scope& scope, const IdentityReader::Attrs&
               attrs);
  operator ::tensorflow::ops::Output() const { return reader_handle; }
  operator ::tensorflow::ops::Input() const { return reader_handle; }
  ::tensorflow::Node* node() const { return reader_handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output reader_handle;
};

// Returns the set of files matching a pattern.
//
// Note that this routine only supports wildcard characters in the
// basename portion of the pattern, not in the directory portion.
//
// Arguments:
// * scope: A Scope object
// * pattern: A (scalar) shell wildcard pattern.
class MatchingFiles {
 public:
  MatchingFiles(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              pattern);
  operator ::tensorflow::ops::Output() const { return filenames; }
  operator ::tensorflow::ops::Input() const { return filenames; }
  ::tensorflow::Node* node() const { return filenames.node(); }

  ::tensorflow::ops::Output filenames;
};

// V2 format specific: merges the metadata files of sharded checkpoints.  The
//
// result is one logical checkpoint, with one physical metadata file and renamed
// data files.
//
// Intended for "grouping" multiple checkpoints in a sharded checkpoint setup.
//
// If delete_old_dirs is true, attempts to delete recursively the dirname of each
// path in the input checkpoint_prefixes.  This is useful when those paths are non
// user-facing temporary locations.
//
// Arguments:
// * scope: A Scope object
// * checkpoint_prefixes: prefixes of V2 checkpoints to merge.
// * destination_prefix: scalar.  The desired final prefix.  Allowed to be the same
// as one of the checkpoint_prefixes.
class MergeV2Checkpoints {
 public:
  // Optional attribute setters for MergeV2Checkpoints :
  //
  // DeleteOldDirs(bool): Defaults to true
  //     see above.
  struct Attrs {
    Attrs DeleteOldDirs(bool x) {
      Attrs ret = *this;
      ret.delete_old_dirs_ = x;
      return ret;
    }

    bool delete_old_dirs_ = true;
  };
  MergeV2Checkpoints(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   checkpoint_prefixes, ::tensorflow::ops::Input
                   destination_prefix);
  MergeV2Checkpoints(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   checkpoint_prefixes, ::tensorflow::ops::Input
                   destination_prefix, const MergeV2Checkpoints::Attrs& attrs);
  operator ::tensorflow::ops::Operation() const { return operation; }

  static Attrs DeleteOldDirs(bool x) {
    return Attrs().DeleteOldDirs(x);
  }

  Operation operation;
};

// Reads and outputs the entire contents of the input filename.
//
// Arguments:
// * scope: A Scope object
class ReadFile {
 public:
  ReadFile(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input filename);
  operator ::tensorflow::ops::Output() const { return contents; }
  operator ::tensorflow::ops::Input() const { return contents; }
  ::tensorflow::Node* node() const { return contents.node(); }

  ::tensorflow::ops::Output contents;
};

// Returns the number of records this Reader has produced.
//
// This is the same as the number of ReaderRead executions that have
// succeeded.
//
// Arguments:
// * scope: A Scope object
// * reader_handle: Handle to a Reader.
class ReaderNumRecordsProduced {
 public:
  ReaderNumRecordsProduced(const ::tensorflow::Scope& scope,
                         ::tensorflow::ops::Input reader_handle);
  operator ::tensorflow::ops::Output() const { return records_produced; }
  operator ::tensorflow::ops::Input() const { return records_produced; }
  ::tensorflow::Node* node() const { return records_produced.node(); }

  ::tensorflow::ops::Output records_produced;
};

// Returns the number of work units this Reader has finished processing.
//
// Arguments:
// * scope: A Scope object
// * reader_handle: Handle to a Reader.
class ReaderNumWorkUnitsCompleted {
 public:
  ReaderNumWorkUnitsCompleted(const ::tensorflow::Scope& scope,
                            ::tensorflow::ops::Input reader_handle);
  operator ::tensorflow::ops::Output() const { return units_completed; }
  operator ::tensorflow::ops::Input() const { return units_completed; }
  ::tensorflow::Node* node() const { return units_completed.node(); }

  ::tensorflow::ops::Output units_completed;
};

// Returns the next record (key, value pair) produced by a Reader.
//
// Will dequeue from the input queue if necessary (e.g. when the
// Reader needs to start reading from a new file since it has finished
// with the previous file).
//
// Arguments:
// * scope: A Scope object
// * reader_handle: Handle to a Reader.
// * queue_handle: Handle to a Queue, with string work items.
class ReaderRead {
 public:
  ReaderRead(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
           reader_handle, ::tensorflow::ops::Input queue_handle);

  ::tensorflow::ops::Output key;
  ::tensorflow::ops::Output value;
};

// Returns up to `num_records` (key, value) pairs produced by a Reader.
//
// Will dequeue from the input queue if necessary (e.g. when the
// Reader needs to start reading from a new file since it has finished
// with the previous file).
// It may return less than `num_records` even before the last batch.
//
// Arguments:
// * scope: A Scope object
// * reader_handle: Handle to a `Reader`.
// * queue_handle: Handle to a `Queue`, with string work items.
// * num_records: number of records to read from `Reader`.
class ReaderReadUpTo {
 public:
  ReaderReadUpTo(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               reader_handle, ::tensorflow::ops::Input queue_handle,
               ::tensorflow::ops::Input num_records);

  ::tensorflow::ops::Output keys;
  ::tensorflow::ops::Output values;
};

// Restore a Reader to its initial clean state.
//
// Arguments:
// * scope: A Scope object
// * reader_handle: Handle to a Reader.
class ReaderReset {
 public:
  ReaderReset(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
            reader_handle);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Restore a reader to a previously saved state.
//
// Not all Readers support being restored, so this can produce an
// Unimplemented error.
//
// Arguments:
// * scope: A Scope object
// * reader_handle: Handle to a Reader.
// * state: Result of a ReaderSerializeState of a Reader with type
// matching reader_handle.
class ReaderRestoreState {
 public:
  ReaderRestoreState(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   reader_handle, ::tensorflow::ops::Input state);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Produce a string tensor that encodes the state of a Reader.
//
// Not all Readers support being serialized, so this can produce an
// Unimplemented error.
//
// Arguments:
// * scope: A Scope object
// * reader_handle: Handle to a Reader.
class ReaderSerializeState {
 public:
  ReaderSerializeState(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     reader_handle);
  operator ::tensorflow::ops::Output() const { return state; }
  operator ::tensorflow::ops::Input() const { return state; }
  ::tensorflow::Node* node() const { return state.node(); }

  ::tensorflow::ops::Output state;
};

// Restores a tensor from checkpoint files.
//
// Reads a tensor stored in one or several files. If there are several files (for
// instance because a tensor was saved as slices), `file_pattern` may contain
// wildcard symbols (`*` and `?`) in the filename portion only, not in the
// directory portion.
//
// If a `file_pattern` matches several files, `preferred_shard` can be used to hint
// in which file the requested tensor is likely to be found. This op will first
// open the file at index `preferred_shard` in the list of matching files and try
// to restore tensors from that file.  Only if some tensors or tensor slices are
// not found in that first file, then the Op opens all the files. Setting
// `preferred_shard` to match the value passed as the `shard` input
// of a matching `Save` Op may speed up Restore.  This attribute only affects
// performance, not correctness.  The default value -1 means files are processed in
// order.
//
// See also `RestoreSlice`.
//
// Arguments:
// * scope: A Scope object
// * file_pattern: Must have a single element. The pattern of the files from
// which we read the tensor.
// * tensor_name: Must have a single element. The name of the tensor to be
// restored.
// * dt:
//     The type of the tensor to be restored.
class Restore {
 public:
  // Optional attribute setters for Restore :
  //
  // PreferredShard(int64): Defaults to -1
  //     Index of file to open first if multiple files match
  // `file_pattern`.
  struct Attrs {
    Attrs PreferredShard(int64 x) {
      Attrs ret = *this;
      ret.preferred_shard_ = x;
      return ret;
    }

    int64 preferred_shard_ = -1;
  };
  Restore(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
        file_pattern, ::tensorflow::ops::Input tensor_name, DataType dt);
  Restore(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
        file_pattern, ::tensorflow::ops::Input tensor_name, DataType dt, const
        Restore::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return tensor; }
  operator ::tensorflow::ops::Input() const { return tensor; }
  ::tensorflow::Node* node() const { return tensor.node(); }

  static Attrs PreferredShard(int64 x) {
    return Attrs().PreferredShard(x);
  }

  ::tensorflow::ops::Output tensor;
};

// Restores a tensor from checkpoint files.
//
// This is like `Restore` except that restored tensor can be listed as filling
// only a slice of a larger tensor.  `shape_and_slice` specifies the shape of the
// larger tensor and the slice that the restored tensor covers.
//
// The `shape_and_slice` input has the same format as the
// elements of the `shapes_and_slices` input of the `SaveSlices` op.
//
// Arguments:
// * scope: A Scope object
// * file_pattern: Must have a single element. The pattern of the files from
// which we read the tensor.
// * tensor_name: Must have a single element. The name of the tensor to be
// restored.
// * shape_and_slice: Scalar. The shapes and slice specifications to use when
// restoring a tensors.
// * dt:
//     The type of the tensor to be restored.
class RestoreSlice {
 public:
  // Optional attribute setters for RestoreSlice :
  //
  // PreferredShard(int64): Defaults to -1
  //     Index of file to open first if multiple files match
  // `file_pattern`. See the documentation for `Restore`.
  struct Attrs {
    Attrs PreferredShard(int64 x) {
      Attrs ret = *this;
      ret.preferred_shard_ = x;
      return ret;
    }

    int64 preferred_shard_ = -1;
  };
  RestoreSlice(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
             file_pattern, ::tensorflow::ops::Input tensor_name,
             ::tensorflow::ops::Input shape_and_slice, DataType dt);
  RestoreSlice(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
             file_pattern, ::tensorflow::ops::Input tensor_name,
             ::tensorflow::ops::Input shape_and_slice, DataType dt, const
             RestoreSlice::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return tensor; }
  operator ::tensorflow::ops::Input() const { return tensor; }
  ::tensorflow::Node* node() const { return tensor.node(); }

  static Attrs PreferredShard(int64 x) {
    return Attrs().PreferredShard(x);
  }

  ::tensorflow::ops::Output tensor;
};

// Restores tensors from a V2 checkpoint.
//
// For backward compatibility with the V1 format, this Op currently allows
// restoring from a V1 checkpoint as well:
//   - This Op first attempts to find the V2 index file pointed to by "prefix", and
//     if found proceed to read it as a V2 checkpoint;
//   - Otherwise the V1 read path is invoked.
// Relying on this behavior is not recommended, as the ability to fall back to read
// V1 might be deprecated and eventually removed.
//
// By default, restores the named tensors in full.  If the caller wishes to restore
// specific slices of stored tensors, "shape_and_slices" should be non-empty
// strings and correspondingly well-formed.
//
// Callers must ensure all the named tensors are indeed stored in the checkpoint.
//
// Arguments:
// * scope: A Scope object
// * prefix: Must have a single element.  The prefix of a V2 checkpoint.
// * tensor_names: shape {N}.  The names of the tensors to be restored.
// * shape_and_slices: shape {N}.  The slice specs of the tensors to be restored.
// Empty strings indicate that they are non-partitioned tensors.
// * dtypes:
//     shape {N}.  The list of expected dtype for the tensors.  Must match
// those stored in the checkpoint.
class RestoreV2 {
 public:
  RestoreV2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input prefix,
          ::tensorflow::ops::Input tensor_names, ::tensorflow::ops::Input
          shape_and_slices, const DataTypeSlice& dtypes);
  ::tensorflow::ops::Output operator[](size_t index) const { return tensors[index]; }


  ::tensorflow::ops::OutputList tensors;
};

// Saves the input tensors to disk.
//
// The size of `tensor_names` must match the number of tensors in `data`. `data[i]`
// is written to `filename` with name `tensor_names[i]`.
//
// See also `SaveSlices`.
//
// Arguments:
// * scope: A Scope object
// * filename: Must have a single element. The name of the file to which we write
// the tensor.
// * tensor_names: Shape `[N]`. The names of the tensors to be saved.
// * data: `N` tensors to save.
class Save {
 public:
  Save(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input filename,
     ::tensorflow::ops::Input tensor_names, ::tensorflow::ops::InputList data);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Saves input tensors slices to disk.
//
// This is like `Save` except that tensors can be listed in the saved file as being
// a slice of a larger tensor.  `shapes_and_slices` specifies the shape of the
// larger tensor and the slice that this tensor covers. `shapes_and_slices` must
// have as many elements as `tensor_names`.
//
// Elements of the `shapes_and_slices` input must either be:
//
// *  The empty string, in which case the corresponding tensor is
//    saved normally.
// *  A string of the form `dim0 dim1 ... dimN-1 slice-spec` where the
//    `dimI` are the dimensions of the larger tensor and `slice-spec`
//    specifies what part is covered by the tensor to save.
//
// `slice-spec` itself is a `:`-separated list: `slice0:slice1:...:sliceN-1`
// where each `sliceI` is either:
//
// *  The string `-` meaning that the slice covers all indices of this dimension
// *  `start,length` where `start` and `length` are integers.  In that
//    case the slice covers `length` indices starting at `start`.
//
// See also `Save`.
//
// Arguments:
// * scope: A Scope object
// * filename: Must have a single element. The name of the file to which we write the
// tensor.
// * tensor_names: Shape `[N]`. The names of the tensors to be saved.
// * shapes_and_slices: Shape `[N]`.  The shapes and slice specifications to use when
// saving the tensors.
// * data: `N` tensors to save.
class SaveSlices {
 public:
  SaveSlices(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input filename,
           ::tensorflow::ops::Input tensor_names, ::tensorflow::ops::Input
           shapes_and_slices, ::tensorflow::ops::InputList data);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Saves tensors in V2 checkpoint format.
//
// By default, saves the named tensors in full.  If the caller wishes to save
// specific slices of full tensors, "shape_and_slices" should be non-empty strings
// and correspondingly well-formed.
//
// Arguments:
// * scope: A Scope object
// * prefix: Must have a single element. The prefix of the V2 checkpoint to which we
// write the tensors.
// * tensor_names: shape {N}. The names of the tensors to be saved.
// * shape_and_slices: shape {N}.  The slice specs of the tensors to be saved.
// Empty strings indicate that they are non-partitioned tensors.
// * tensors: `N` tensors to save.
class SaveV2 {
 public:
  SaveV2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input prefix,
       ::tensorflow::ops::Input tensor_names, ::tensorflow::ops::Input
       shape_and_slices, ::tensorflow::ops::InputList tensors);
  operator ::tensorflow::ops::Operation() const { return operation; }

  Operation operation;
};

// Generate a sharded filename. The filename is printf formatted as
//
//    %s-%05d-of-%05d, basename, shard, num_shards.
//
// Arguments:
// * scope: A Scope object
class ShardedFilename {
 public:
  ShardedFilename(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                basename, ::tensorflow::ops::Input shard,
                ::tensorflow::ops::Input num_shards);
  operator ::tensorflow::ops::Output() const { return filename; }
  operator ::tensorflow::ops::Input() const { return filename; }
  ::tensorflow::Node* node() const { return filename.node(); }

  ::tensorflow::ops::Output filename;
};

// Generate a glob pattern matching all sharded file names.
//
// Arguments:
// * scope: A Scope object
class ShardedFilespec {
 public:
  ShardedFilespec(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                basename, ::tensorflow::ops::Input num_shards);
  operator ::tensorflow::ops::Output() const { return filename; }
  operator ::tensorflow::ops::Input() const { return filename; }
  ::tensorflow::Node* node() const { return filename.node(); }

  ::tensorflow::ops::Output filename;
};

// A Reader that outputs the records from a TensorFlow Records file.
//
// Arguments:
// * scope: A Scope object
class TFRecordReader {
 public:
  // Optional attribute setters for TFRecordReader :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this reader is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this reader is named in the given bucket
  // with this shared_name. Otherwise, the node name is used instead.
  // CompressionType(StringPiece): Defaults to ""
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

    Attrs CompressionType(StringPiece x) {
      Attrs ret = *this;
      ret.compression_type_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
    StringPiece compression_type_ = "";
  };
  TFRecordReader(const ::tensorflow::Scope& scope);
  TFRecordReader(const ::tensorflow::Scope& scope, const TFRecordReader::Attrs&
               attrs);
  operator ::tensorflow::ops::Output() const { return reader_handle; }
  operator ::tensorflow::ops::Input() const { return reader_handle; }
  ::tensorflow::Node* node() const { return reader_handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }
  static Attrs CompressionType(StringPiece x) {
    return Attrs().CompressionType(x);
  }

  ::tensorflow::ops::Output reader_handle;
};

// A Reader that outputs the lines of a file delimited by '\n'.
//
// Arguments:
// * scope: A Scope object
class TextLineReader {
 public:
  // Optional attribute setters for TextLineReader :
  //
  // SkipHeaderLines(int64): Defaults to 0
  //     Number of lines to skip from the beginning of every file.
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this reader is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this reader is named in the given bucket
  // with this shared_name. Otherwise, the node name is used instead.
  struct Attrs {
    Attrs SkipHeaderLines(int64 x) {
      Attrs ret = *this;
      ret.skip_header_lines_ = x;
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

    int64 skip_header_lines_ = 0;
    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  TextLineReader(const ::tensorflow::Scope& scope);
  TextLineReader(const ::tensorflow::Scope& scope, const TextLineReader::Attrs&
               attrs);
  operator ::tensorflow::ops::Output() const { return reader_handle; }
  operator ::tensorflow::ops::Input() const { return reader_handle; }
  ::tensorflow::Node* node() const { return reader_handle.node(); }

  static Attrs SkipHeaderLines(int64 x) {
    return Attrs().SkipHeaderLines(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output reader_handle;
};

// A Reader that outputs the entire contents of a file as a value.
//
// To use, enqueue filenames in a Queue.  The output of ReaderRead will
// be a filename (key) and the contents of that file (value).
//
// Arguments:
// * scope: A Scope object
class WholeFileReader {
 public:
  // Optional attribute setters for WholeFileReader :
  //
  // Container(StringPiece): Defaults to ""
  //     If non-empty, this reader is placed in the given container.
  // Otherwise, a default container is used.
  // SharedName(StringPiece): Defaults to ""
  //     If non-empty, this reader is named in the given bucket
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
  WholeFileReader(const ::tensorflow::Scope& scope);
  WholeFileReader(const ::tensorflow::Scope& scope, const WholeFileReader::Attrs&
                attrs);
  operator ::tensorflow::ops::Output() const { return reader_handle; }
  operator ::tensorflow::ops::Input() const { return reader_handle; }
  ::tensorflow::Node* node() const { return reader_handle.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::ops::Output reader_handle;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_IO_OPS_H_
