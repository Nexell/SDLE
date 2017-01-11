// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_LINALG_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_LINALG_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchCholesky {
 public:
  BatchCholesky(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchCholeskyGrad {
 public:
  BatchCholeskyGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input l,
                  ::tensorflow::ops::Input grad);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchMatrixDeterminant {
 public:
  BatchMatrixDeterminant(const ::tensorflow::Scope& scope,
                       ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchMatrixInverse {
 public:
  // Optional attribute setters for BatchMatrixInverse :
  //
  // Adjoint(bool): Defaults to false
  struct Attrs {
    Attrs Adjoint(bool x) {
      Attrs ret = *this;
      ret.adjoint_ = x;
      return ret;
    }

    bool adjoint_ = false;
  };
  BatchMatrixInverse(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   input);
  BatchMatrixInverse(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   input, const BatchMatrixInverse::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Adjoint(bool x) {
    return Attrs().Adjoint(x);
  }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchMatrixSolve {
 public:
  // Optional attribute setters for BatchMatrixSolve :
  //
  // Adjoint(bool): Defaults to false
  struct Attrs {
    Attrs Adjoint(bool x) {
      Attrs ret = *this;
      ret.adjoint_ = x;
      return ret;
    }

    bool adjoint_ = false;
  };
  BatchMatrixSolve(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 matrix, ::tensorflow::ops::Input rhs);
  BatchMatrixSolve(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 matrix, ::tensorflow::ops::Input rhs, const
                 BatchMatrixSolve::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Adjoint(bool x) {
    return Attrs().Adjoint(x);
  }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchMatrixSolveLs {
 public:
  // Optional attribute setters for BatchMatrixSolveLs :
  //
  // Fast(bool): Defaults to true
  struct Attrs {
    Attrs Fast(bool x) {
      Attrs ret = *this;
      ret.fast_ = x;
      return ret;
    }

    bool fast_ = true;
  };
  BatchMatrixSolveLs(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   matrix, ::tensorflow::ops::Input rhs,
                   ::tensorflow::ops::Input l2_regularizer);
  BatchMatrixSolveLs(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   matrix, ::tensorflow::ops::Input rhs,
                   ::tensorflow::ops::Input l2_regularizer, const
                   BatchMatrixSolveLs::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Fast(bool x) {
    return Attrs().Fast(x);
  }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchMatrixTriangularSolve {
 public:
  // Optional attribute setters for BatchMatrixTriangularSolve :
  //
  // Lower(bool): Defaults to true
  // Adjoint(bool): Defaults to false
  struct Attrs {
    Attrs Lower(bool x) {
      Attrs ret = *this;
      ret.lower_ = x;
      return ret;
    }

    Attrs Adjoint(bool x) {
      Attrs ret = *this;
      ret.adjoint_ = x;
      return ret;
    }

    bool lower_ = true;
    bool adjoint_ = false;
  };
  BatchMatrixTriangularSolve(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input matrix,
                           ::tensorflow::ops::Input rhs);
  BatchMatrixTriangularSolve(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input matrix,
                           ::tensorflow::ops::Input rhs, const
                           BatchMatrixTriangularSolve::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Lower(bool x) {
    return Attrs().Lower(x);
  }
  static Attrs Adjoint(bool x) {
    return Attrs().Adjoint(x);
  }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchSelfAdjointEig {
 public:
  BatchSelfAdjointEig(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchSelfAdjointEigV2 {
 public:
  // Optional attribute setters for BatchSelfAdjointEigV2 :
  //
  // ComputeV(bool): Defaults to true
  struct Attrs {
    Attrs ComputeV(bool x) {
      Attrs ret = *this;
      ret.compute_v_ = x;
      return ret;
    }

    bool compute_v_ = true;
  };
  BatchSelfAdjointEigV2(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input input);
  BatchSelfAdjointEigV2(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input input, const
                      BatchSelfAdjointEigV2::Attrs& attrs);

  static Attrs ComputeV(bool x) {
    return Attrs().ComputeV(x);
  }

  ::tensorflow::ops::Output e;
  ::tensorflow::ops::Output v;
};

// TODO: add doc.
//
// Arguments:
// * scope: A Scope object
class BatchSvd {
 public:
  // Optional attribute setters for BatchSvd :
  //
  // ComputeUv(bool): Defaults to true
  // FullMatrices(bool): Defaults to false
  struct Attrs {
    Attrs ComputeUv(bool x) {
      Attrs ret = *this;
      ret.compute_uv_ = x;
      return ret;
    }

    Attrs FullMatrices(bool x) {
      Attrs ret = *this;
      ret.full_matrices_ = x;
      return ret;
    }

    bool compute_uv_ = true;
    bool full_matrices_ = false;
  };
  BatchSvd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  BatchSvd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
         const BatchSvd::Attrs& attrs);

  static Attrs ComputeUv(bool x) {
    return Attrs().ComputeUv(x);
  }
  static Attrs FullMatrices(bool x) {
    return Attrs().FullMatrices(x);
  }

  ::tensorflow::ops::Output s;
  ::tensorflow::ops::Output u;
  ::tensorflow::ops::Output v;
};

// Computes the Cholesky decomposition of one or more square matrices.
//
// The input is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices, with the same constraints as the single matrix Cholesky
// decomposition above. The output is a tensor of the same shape as the input
// containing the Cholesky decompositions for all input submatrices `[..., :, :]`.
//
// Arguments:
// * scope: A Scope object
// * input: Shape is `[..., M, M]`.
class Cholesky {
 public:
  Cholesky(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the reverse mode backpropagated gradient of the Cholesky algorithm.
//
// For an explanation see "Differentiation of the Cholesky algorithm" by
// Iain Murray http://arxiv.org/abs/1602.07527.
//
// Arguments:
// * scope: A Scope object
// * l: Output of batch Cholesky algorithm l = cholesky(A). Shape is `[..., M, M]`.
// Algorithm depends only on lower triangular part of the innermost matrices of
// this tensor.
// * grad: df/dl where f is some scalar function. Shape is `[..., M, M]`.
// Algorithm depends only on lower triangular part of the innermost matrices of
// this tensor.
class CholeskyGrad {
 public:
  CholeskyGrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input l,
             ::tensorflow::ops::Input grad);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the determinant of one ore more square matrices.
//
// The input is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices. The output is a tensor containing the determinants
// for all input submatrices `[..., :, :]`.
//
// Arguments:
// * scope: A Scope object
// * input: Shape is `[..., M, M]`.
class MatrixDeterminant {
 public:
  MatrixDeterminant(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                  input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the inverse of one or more square invertible matrices or their
//
// adjoints (conjugate transposes).
//
// The input is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices. The output is a tensor of the same shape as the input
// containing the inverse for all input submatrices `[..., :, :]`.
//
// The op uses LU decomposition with partial pivoting to compute the inverses.
//
// If a matrix is not invertible there is no guarantee what the op does. It
// may detect the condition and raise an exception or it may simply return a
// garbage result.
//
// Arguments:
// * scope: A Scope object
// * input: Shape is `[..., M, M]`.
class MatrixInverse {
 public:
  // Optional attribute setters for MatrixInverse :
  //
  // Adjoint(bool): Defaults to false
  struct Attrs {
    Attrs Adjoint(bool x) {
      Attrs ret = *this;
      ret.adjoint_ = x;
      return ret;
    }

    bool adjoint_ = false;
  };
  MatrixInverse(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  MatrixInverse(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input,
              const MatrixInverse::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Adjoint(bool x) {
    return Attrs().Adjoint(x);
  }

  ::tensorflow::ops::Output output;
};

// Solves systems of linear equations.
//
// `Matrix` is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices. `Rhs` is a tensor of shape `[..., M, K]`. The `output` is
// a tensor shape `[..., M, K]`.  If `adjoint` is `False` then each output matrix
// satisfies `matrix[..., :, :] * output[..., :, :] = rhs[..., :, :]`.
// If `adjoint` is `True` then each output matrix satisfies
// `adjoint(matrix[..., :, :]) * output[..., :, :] = rhs[..., :, :]`.
//
// Arguments:
// * scope: A Scope object
// * matrix: Shape is `[..., M, M]`.
// * rhs: Shape is `[..., M, K]`.
class MatrixSolve {
 public:
  // Optional attribute setters for MatrixSolve :
  //
  // Adjoint(bool): Defaults to false
  //     Boolean indicating whether to solve with `matrix` or its (block-wise)
  // adjoint.
  struct Attrs {
    Attrs Adjoint(bool x) {
      Attrs ret = *this;
      ret.adjoint_ = x;
      return ret;
    }

    bool adjoint_ = false;
  };
  MatrixSolve(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input matrix,
            ::tensorflow::ops::Input rhs);
  MatrixSolve(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input matrix,
            ::tensorflow::ops::Input rhs, const MatrixSolve::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Adjoint(bool x) {
    return Attrs().Adjoint(x);
  }

  ::tensorflow::ops::Output output;
};

// Solves one or more linear least-squares problems.
//
// `matrix` is a tensor of shape `[..., M, N]` whose inner-most 2 dimensions
// form matrices of size `[M, N]`. Rhs is a tensor of shape `[..., M, K]`.
// The output is a tensor shape `[..., N, K]` where each output matrix solves
// each of the equations matrix[..., :, :] * output[..., :, :] = rhs[..., :, :]
// in the least squares sense.
//
// matrix and right-hand sides in the batch:
//
// `matrix`=\\(A \in \Re^{m \times n}\\),
// `rhs`=\\(B  \in \Re^{m \times k}\\),
// `output`=\\(X  \in \Re^{n \times k}\\),
// `l2_regularizer`=\\(\lambda\\).
//
// If `fast` is `True`, then the solution is computed by solving the normal
// equations using Cholesky decomposition. Specifically, if \\(m \ge n\\) then
// \\(X = (A^T A + \lambda I)^{-1} A^T B\\), which solves the least-squares
// problem \\(X = \mathrm{argmin}_{Z \in \Re^{n \times k}} ||A Z - B||_F^2 +
// \lambda ||Z||_F^2\\). If \\(m \lt n\\) then `output` is computed as
// \\(X = A^T (A A^T + \lambda I)^{-1} B\\), which (for \\(\lambda = 0\\)) is the
// minimum-norm solution to the under-determined linear system, i.e.
// \\(X = \mathrm{argmin}_{Z \in \Re^{n \times k}} ||Z||_F^2 \\), subject to
// \\(A Z = B\\). Notice that the fast path is only numerically stable when
// \\(A\\) is numerically full rank and has a condition number
// \\(\mathrm{cond}(A) \lt \frac{1}{\sqrt{\epsilon_{mach}}}\\) or\\(\lambda\\) is
// sufficiently large.
//
// If `fast` is `False` an algorithm based on the numerically robust complete
// orthogonal decomposition is used. This computes the minimum-norm
// least-squares solution, even when \\(A\\) is rank deficient. This path is
// typically 6-7 times slower than the fast path. If `fast` is `False` then
// `l2_regularizer` is ignored.
//
// Arguments:
// * scope: A Scope object
// * matrix: Shape is `[..., M, N]`.
// * rhs: Shape is `[..., M, K]`.
// * l2_regularizer: Scalar tensor.
class MatrixSolveLs {
 public:
  // Optional attribute setters for MatrixSolveLs :
  //
  // Fast(bool): Defaults to true
  struct Attrs {
    Attrs Fast(bool x) {
      Attrs ret = *this;
      ret.fast_ = x;
      return ret;
    }

    bool fast_ = true;
  };
  MatrixSolveLs(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              matrix, ::tensorflow::ops::Input rhs, ::tensorflow::ops::Input
              l2_regularizer);
  MatrixSolveLs(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
              matrix, ::tensorflow::ops::Input rhs, ::tensorflow::ops::Input
              l2_regularizer, const MatrixSolveLs::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Fast(bool x) {
    return Attrs().Fast(x);
  }

  ::tensorflow::ops::Output output;
};

// Solves systems of linear equations with upper or lower triangular matrices by
//
// backsubstitution.
//
// `matrix` is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions form
// square matrices. If `lower` is `True` then the strictly upper triangular part
// of each inner-most matrix is assumed to be zero and not accessed.
// If `lower` is False then the strictly lower triangular part of each inner-most
// matrix is assumed to be zero and not accessed.
// `rhs` is a tensor of shape `[..., M, K]`.
//
// The output is a tensor of shape `[..., M, K]`. If `adjoint` is
// `True` then the innermost matrices in output` satisfy matrix equations
// `matrix[..., :, :] * output[..., :, :] = rhs[..., :, :]`.
// If `adjoint` is `False` then the strictly then the  innermost matrices in
// `output` satisfy matrix equations
// `adjoint(matrix[..., i, k]) * output[..., k, j] = rhs[..., i, j]`.
//
// Arguments:
// * scope: A Scope object
// * matrix: Shape is `[..., M, M]`.
// * rhs: Shape is `[..., M, K]`.
class MatrixTriangularSolve {
 public:
  // Optional attribute setters for MatrixTriangularSolve :
  //
  // Lower(bool): Defaults to true
  //     Boolean indicating whether the innermost matrices in `matrix` are
  // lower or upper triangular.
  // Adjoint(bool): Defaults to false
  //     Boolean indicating whether to solve with `matrix` or its (block-wise)
  // adjoint.
  struct Attrs {
    Attrs Lower(bool x) {
      Attrs ret = *this;
      ret.lower_ = x;
      return ret;
    }

    Attrs Adjoint(bool x) {
      Attrs ret = *this;
      ret.adjoint_ = x;
      return ret;
    }

    bool lower_ = true;
    bool adjoint_ = false;
  };
  MatrixTriangularSolve(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input matrix, ::tensorflow::ops::Input
                      rhs);
  MatrixTriangularSolve(const ::tensorflow::Scope& scope,
                      ::tensorflow::ops::Input matrix, ::tensorflow::ops::Input
                      rhs, const MatrixTriangularSolve::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs Lower(bool x) {
    return Attrs().Lower(x);
  }
  static Attrs Adjoint(bool x) {
    return Attrs().Adjoint(x);
  }

  ::tensorflow::ops::Output output;
};

// Computes the Eigen Decomposition of a batch of square self-adjoint matrices.
//
// DEPRECATED at GraphDef version 11:
// Use SelfAdjointEigV2 instead..
//
// The input is a tensor of shape `[..., M, M]` whose inner-most 2 dimensions
// form square matrices, with the same constraints as the single matrix
// SelfAdjointEig.
//
// The result is a [..., M+1, M] matrix with [..., 0,:] containing the
// eigenvalues, and subsequent [...,1:, :] containing the eigenvectors.
//
// Arguments:
// * scope: A Scope object
// * input: Shape is `[..., M, M]`.
class SelfAdjointEig {
 public:
  SelfAdjointEig(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
               input);
  operator ::tensorflow::ops::Output() const { return output; }
  operator ::tensorflow::ops::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::ops::Output output;
};

// Computes the eigen decomposition of one or more square self-adjoint matrices.
//
// Computes the eigenvalues and (optionally) eigenvectors of each inner matrix in
// `input` such that `input[..., :, :] = v[..., :, :] * diag(e[..., :])`.
//
// ```prettyprint
// # a is a tensor.
// # e is a tensor of eigenvalues.
// # v is a tensor of eigenvectors.
// e, v = self_adjoint_eig(a)
// e = self_adjoint_eig(a, compute_v=False)
// ```
//
// Arguments:
// * scope: A Scope object
// * input: `Tensor` input of shape `[N, N]`.
class SelfAdjointEigV2 {
 public:
  // Optional attribute setters for SelfAdjointEigV2 :
  //
  // ComputeV(bool): Defaults to true
  //     If `True` then eigenvectors will be computed and returned in `v`.
  // Otherwise, only the eigenvalues will be computed.
  struct Attrs {
    Attrs ComputeV(bool x) {
      Attrs ret = *this;
      ret.compute_v_ = x;
      return ret;
    }

    bool compute_v_ = true;
  };
  SelfAdjointEigV2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 input);
  SelfAdjointEigV2(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                 input, const SelfAdjointEigV2::Attrs& attrs);

  static Attrs ComputeV(bool x) {
    return Attrs().ComputeV(x);
  }

  ::tensorflow::ops::Output e;
  ::tensorflow::ops::Output v;
};

// Computes the singular value decompositions of one or more matrices.
//
// Computes the SVD of each inner matrix in `input` such that
// `input[..., :, :] = u[..., :, :] * diag(s[..., :, :]) * transpose(v[..., :, :])`
//
// ```prettyprint
// # a is a tensor containing a batch of matrices.
// # s is a tensor of singular values for each matrix.
// # u is the tensor containing of left singular vectors for each matrix.
// # v is the tensor containing of right singular vectors for each matrix.
// s, u, v = svd(a)
// s, _, _ = svd(a, compute_uv=False)
// ```
//
// Arguments:
// * scope: A Scope object
// * input: A tensor of shape `[..., M, N]` whose inner-most 2 dimensions
// form matrices of size `[M, N]`. Let `P` be the minimum of `M` and `N`.
class Svd {
 public:
  // Optional attribute setters for Svd :
  //
  // ComputeUv(bool): Defaults to true
  //     If true, left and right singular vectors will be
  // computed and returned in `u` and `v`, respectively.
  // If false, `u` and `v` are not set and should never referenced.
  // FullMatrices(bool): Defaults to false
  //     If true, compute full-sized `u` and `v`. If false
  // (the default), compute only the leading `P` singular vectors.
  // Ignored if `compute_uv` is `False`.
  struct Attrs {
    Attrs ComputeUv(bool x) {
      Attrs ret = *this;
      ret.compute_uv_ = x;
      return ret;
    }

    Attrs FullMatrices(bool x) {
      Attrs ret = *this;
      ret.full_matrices_ = x;
      return ret;
    }

    bool compute_uv_ = true;
    bool full_matrices_ = false;
  };
  Svd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input);
  Svd(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input input, const
    Svd::Attrs& attrs);

  static Attrs ComputeUv(bool x) {
    return Attrs().ComputeUv(x);
  }
  static Attrs FullMatrices(bool x) {
    return Attrs().FullMatrices(x);
  }

  ::tensorflow::ops::Output s;
  ::tensorflow::ops::Output u;
  ::tensorflow::ops::Output v;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_LINALG_OPS_H_
