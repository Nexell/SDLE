// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CANDIDATE_SAMPLING_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CANDIDATE_SAMPLING_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Generates labels for candidate sampling with a learned unigram distribution.
//
// See explanations of candidate sampling and the data formats at
// go/candidate-sampling.
//
// For each batch, this op picks a single set of sampled candidate labels.
//
// The advantages of sampling candidates per-batch are simplicity and the
// possibility of efficient dense matrix multiplication. The disadvantage is that
// the sampled candidates must be chosen independently of the context and of the
// true labels.
//
// Arguments:
// * scope: A Scope object
// * true_classes: A batch_size * num_true matrix, in which each row contains the
// IDs of the num_true target_classes in the corresponding original label.
// * num_true:
//     Number of true labels per context.
// * num_sampled:
//     Number of candidates to produce per batch.
// * unique:
//     If unique is true, we sample with rejection, so that all sampled
// candidates in a batch are unique. This requires some approximation to
// estimate the post-rejection sampling probabilities.
class AllCandidateSampler {
 public:
  // Optional attribute setters for AllCandidateSampler :
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
  AllCandidateSampler(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    true_classes, int64 num_true, int64 num_sampled, bool
                    unique);
  AllCandidateSampler(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    true_classes, int64 num_true, int64 num_sampled, bool
                    unique, const AllCandidateSampler::Attrs& attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output sampled_candidates;
  ::tensorflow::ops::Output true_expected_count;
  ::tensorflow::ops::Output sampled_expected_count;
};

// Computes the ids of the positions in sampled_candidates that match true_labels.
//
// When doing log-odds NCE, the result of this op should be passed through a
// SparseToDense op, then added to the logits of the sampled candidates. This has
// the effect of 'removing' the sampled labels that match the true labels by
// making the classifier sure that they are sampled labels.
//
// Arguments:
// * scope: A Scope object
// * true_classes: The true_classes output of UnpackSparseLabels.
// * sampled_candidates: The sampled_candidates output of CandidateSampler.
// * num_true:
//     Number of true labels per context.
class ComputeAccidentalHits {
 public:
  // Optional attribute setters for ComputeAccidentalHits :
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
  ComputeAccidentalHits(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input true_classes,
                      ::tensorflow::ops::Input sampled_candidates, int64
                      num_true);
  ComputeAccidentalHits(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input true_classes,
                      ::tensorflow::ops::Input sampled_candidates, int64
                      num_true, const ComputeAccidentalHits::Attrs& attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output indices;
  ::tensorflow::ops::Output ids;
  ::tensorflow::ops::Output weights;
};

// Generates labels for candidate sampling with a learned unigram distribution.
//
// A unigram sampler could use a fixed unigram distribution read from a
// file or passed in as an in-memory array instead of building up the distribution
// from data on the fly. There is also an option to skew the distribution by
// applying a distortion power to the weights.
//
// The vocabulary file should be in CSV-like format, with the last field
// being the weight associated with the word.
//
// For each batch, this op picks a single set of sampled candidate labels.
//
// The advantages of sampling candidates per-batch are simplicity and the
// possibility of efficient dense matrix multiplication. The disadvantage is that
// the sampled candidates must be chosen independently of the context and of the
// true labels.
//
// Arguments:
// * scope: A Scope object
// * true_classes: A batch_size * num_true matrix, in which each row contains the
// IDs of the num_true target_classes in the corresponding original label.
// * num_true:
//     Number of true labels per context.
// * num_sampled:
//     Number of candidates to randomly sample per batch.
// * unique:
//     If unique is true, we sample with rejection, so that all sampled
// candidates in a batch are unique. This requires some approximation to
// estimate the post-rejection sampling probabilities.
// * range_max:
//     The sampler will sample integers from the interval [0, range_max).
class FixedUnigramCandidateSampler {
 public:
  // Optional attribute setters for FixedUnigramCandidateSampler :
  //
  // VocabFile(StringPiece): Defaults to ""
  //     Each valid line in this file (which should have a CSV-like format)
  // corresponds to a valid word ID. IDs are in sequential order, starting from
  // num_reserved_ids. The last entry in each line is expected to be a value
  // corresponding to the count or relative probability. Exactly one of vocab_file
  // and unigrams needs to be passed to this op.
  // Distortion(float): Defaults to 1
  //     The distortion is used to skew the unigram probability distribution.
  // Each weight is first raised to the distortion's power before adding to the
  // internal unigram distribution. As a result, distortion = 1.0 gives regular
  // unigram sampling (as defined by the vocab file), and distortion = 0.0 gives
  // a uniform distribution.
  // NumReservedIds(int64): Defaults to 0
  //     Optionally some reserved IDs can be added in the range [0,
  // ..., num_reserved_ids) by the users. One use case is that a special unknown
  // word token is used as ID 0. These IDs will have a sampling probability of 0.
  // NumShards(int64): Defaults to 1
  //     A sampler can be used to sample from a subset of the original range
  // in order to speed up the whole computation through parallelism. This parameter
  // (together with 'shard') indicates the number of partitions that are being
  // used in the overall computation.
  // Shard(int64): Defaults to 0
  //     A sampler can be used to sample from a subset of the original range
  // in order to speed up the whole computation through parallelism. This parameter
  // (together with 'num_shards') indicates the particular partition number of a
  // sampler op, when partitioning is being used.
  // Unigrams(const gtl::ArraySlice<float>&): Defaults to []
  //     A list of unigram counts or probabilities, one per ID in sequential
  // order. Exactly one of vocab_file and unigrams should be passed to this op.
  // Seed(int64): Defaults to 0
  //     If either seed or seed2 are set to be non-zero, the random number
  // generator is seeded by the given seed.  Otherwise, it is seeded by a
  // random seed.
  // Seed2(int64): Defaults to 0
  //     An second seed to avoid seed collision.
  struct Attrs {
    Attrs VocabFile(StringPiece x) {
      Attrs ret = *this;
      ret.vocab_file_ = x;
      return ret;
    }

    Attrs Distortion(float x) {
      Attrs ret = *this;
      ret.distortion_ = x;
      return ret;
    }

    Attrs NumReservedIds(int64 x) {
      Attrs ret = *this;
      ret.num_reserved_ids_ = x;
      return ret;
    }

    Attrs NumShards(int64 x) {
      Attrs ret = *this;
      ret.num_shards_ = x;
      return ret;
    }

    Attrs Shard(int64 x) {
      Attrs ret = *this;
      ret.shard_ = x;
      return ret;
    }

    Attrs Unigrams(const gtl::ArraySlice<float>& x) {
      Attrs ret = *this;
      ret.unigrams_ = x;
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

    StringPiece vocab_file_ = "";
    float distortion_ = 1.0f;
    int64 num_reserved_ids_ = 0;
    int64 num_shards_ = 1;
    int64 shard_ = 0;
    gtl::ArraySlice<float> unigrams_ = {};
    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  FixedUnigramCandidateSampler(const ::tensorflow::Scope& scope,
                             ::tensorflow::ops::Input true_classes, int64
                             num_true, int64 num_sampled, bool unique, int64
                             range_max);
  FixedUnigramCandidateSampler(const ::tensorflow::Scope& scope,
                             ::tensorflow::ops::Input true_classes, int64
                             num_true, int64 num_sampled, bool unique, int64
                             range_max, const
                             FixedUnigramCandidateSampler::Attrs& attrs);

  static Attrs VocabFile(StringPiece x) {
    return Attrs().VocabFile(x);
  }
  static Attrs Distortion(float x) {
    return Attrs().Distortion(x);
  }
  static Attrs NumReservedIds(int64 x) {
    return Attrs().NumReservedIds(x);
  }
  static Attrs NumShards(int64 x) {
    return Attrs().NumShards(x);
  }
  static Attrs Shard(int64 x) {
    return Attrs().Shard(x);
  }
  static Attrs Unigrams(const gtl::ArraySlice<float>& x) {
    return Attrs().Unigrams(x);
  }
  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output sampled_candidates;
  ::tensorflow::ops::Output true_expected_count;
  ::tensorflow::ops::Output sampled_expected_count;
};

// Generates labels for candidate sampling with a learned unigram distribution.
//
// See explanations of candidate sampling and the data formats at
// go/candidate-sampling.
//
// For each batch, this op picks a single set of sampled candidate labels.
//
// The advantages of sampling candidates per-batch are simplicity and the
// possibility of efficient dense matrix multiplication. The disadvantage is that
// the sampled candidates must be chosen independently of the context and of the
// true labels.
//
// Arguments:
// * scope: A Scope object
// * true_classes: A batch_size * num_true matrix, in which each row contains the
// IDs of the num_true target_classes in the corresponding original label.
// * num_true:
//     Number of true labels per context.
// * num_sampled:
//     Number of candidates to randomly sample per batch.
// * unique:
//     If unique is true, we sample with rejection, so that all sampled
// candidates in a batch are unique. This requires some approximation to
// estimate the post-rejection sampling probabilities.
// * range_max:
//     The sampler will sample integers from the interval [0, range_max).
class LearnedUnigramCandidateSampler {
 public:
  // Optional attribute setters for LearnedUnigramCandidateSampler :
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
  LearnedUnigramCandidateSampler(const ::tensorflow::Scope& scope,
                               ::tensorflow::ops::Input true_classes, int64
                               num_true, int64 num_sampled, bool unique, int64
                               range_max);
  LearnedUnigramCandidateSampler(const ::tensorflow::Scope& scope,
                               ::tensorflow::ops::Input true_classes, int64
                               num_true, int64 num_sampled, bool unique, int64
                               range_max, const
                               LearnedUnigramCandidateSampler::Attrs& attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output sampled_candidates;
  ::tensorflow::ops::Output true_expected_count;
  ::tensorflow::ops::Output sampled_expected_count;
};

// Generates labels for candidate sampling with a log-uniform distribution.
//
// See explanations of candidate sampling and the data formats at
// go/candidate-sampling.
//
// For each batch, this op picks a single set of sampled candidate labels.
//
// The advantages of sampling candidates per-batch are simplicity and the
// possibility of efficient dense matrix multiplication. The disadvantage is that
// the sampled candidates must be chosen independently of the context and of the
// true labels.
//
// Arguments:
// * scope: A Scope object
// * true_classes: A batch_size * num_true matrix, in which each row contains the
// IDs of the num_true target_classes in the corresponding original label.
// * num_true:
//     Number of true labels per context.
// * num_sampled:
//     Number of candidates to randomly sample per batch.
// * unique:
//     If unique is true, we sample with rejection, so that all sampled
// candidates in a batch are unique. This requires some approximation to
// estimate the post-rejection sampling probabilities.
// * range_max:
//     The sampler will sample integers from the interval [0, range_max).
class LogUniformCandidateSampler {
 public:
  // Optional attribute setters for LogUniformCandidateSampler :
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
  LogUniformCandidateSampler(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input true_classes, int64
                           num_true, int64 num_sampled, bool unique, int64
                           range_max);
  LogUniformCandidateSampler(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input true_classes, int64
                           num_true, int64 num_sampled, bool unique, int64
                           range_max, const LogUniformCandidateSampler::Attrs&
                           attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output sampled_candidates;
  ::tensorflow::ops::Output true_expected_count;
  ::tensorflow::ops::Output sampled_expected_count;
};

// Generates labels for candidate sampling with a learned unigram distribution.
//
// See explanations of candidate sampling and the data formats at
// go/candidate-sampling.
//
// For each batch, this op picks a single set of sampled candidate labels.
//
// The advantages of sampling candidates per-batch are simplicity and the
// possibility of efficient dense matrix multiplication. The disadvantage is that
// the sampled candidates must be chosen independently of the context and of the
// true labels.
//
// Arguments:
// * scope: A Scope object
// * true_classes: A batch_size * num_true matrix, in which each row contains the
// IDs of the num_true target_classes in the corresponding original label.
// * num_true:
//     Number of true labels per context.
// * num_sampled:
//     Number of candidates to randomly sample per batch.
// * unique:
//     If unique is true, we sample with rejection, so that all sampled
// candidates in a batch are unique. This requires some approximation to
// estimate the post-rejection sampling probabilities.
// * range_max:
//     The sampler will sample integers from the interval [0, range_max).
class ThreadUnsafeUnigramCandidateSampler {
 public:
  // Optional attribute setters for ThreadUnsafeUnigramCandidateSampler :
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
  ThreadUnsafeUnigramCandidateSampler(const ::tensorflow::Scope& scope,
                                    ::tensorflow::ops::Input true_classes,
                                    int64 num_true, int64 num_sampled, bool
                                    unique, int64 range_max);
  ThreadUnsafeUnigramCandidateSampler(const ::tensorflow::Scope& scope,
                                    ::tensorflow::ops::Input true_classes,
                                    int64 num_true, int64 num_sampled, bool
                                    unique, int64 range_max, const
                                    ThreadUnsafeUnigramCandidateSampler::Attrs&
                                    attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output sampled_candidates;
  ::tensorflow::ops::Output true_expected_count;
  ::tensorflow::ops::Output sampled_expected_count;
};

// Generates labels for candidate sampling with a uniform distribution.
//
// See explanations of candidate sampling and the data formats at
// go/candidate-sampling.
//
// For each batch, this op picks a single set of sampled candidate labels.
//
// The advantages of sampling candidates per-batch are simplicity and the
// possibility of efficient dense matrix multiplication. The disadvantage is that
// the sampled candidates must be chosen independently of the context and of the
// true labels.
//
// Arguments:
// * scope: A Scope object
// * true_classes: A batch_size * num_true matrix, in which each row contains the
// IDs of the num_true target_classes in the corresponding original label.
// * num_true:
//     Number of true labels per context.
// * num_sampled:
//     Number of candidates to randomly sample per batch.
// * unique:
//     If unique is true, we sample with rejection, so that all sampled
// candidates in a batch are unique. This requires some approximation to
// estimate the post-rejection sampling probabilities.
// * range_max:
//     The sampler will sample integers from the interval [0, range_max).
class UniformCandidateSampler {
 public:
  // Optional attribute setters for UniformCandidateSampler :
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
  UniformCandidateSampler(const ::tensorflow::Scope& scope,
                        ::tensorflow::ops::Input true_classes, int64 num_true,
                        int64 num_sampled, bool unique, int64 range_max);
  UniformCandidateSampler(const ::tensorflow::Scope& scope,
                        ::tensorflow::ops::Input true_classes, int64 num_true,
                        int64 num_sampled, bool unique, int64 range_max, const
                        UniformCandidateSampler::Attrs& attrs);

  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::ops::Output sampled_candidates;
  ::tensorflow::ops::Output true_expected_count;
  ::tensorflow::ops::Output sampled_expected_count;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_CANDIDATE_SAMPLING_OPS_H_
