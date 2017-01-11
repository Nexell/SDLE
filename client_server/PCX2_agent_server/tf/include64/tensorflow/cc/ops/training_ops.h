// This file is MACHINE GENERATED! Do not edit.

#ifndef D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_TRAINING_OPS_H_
#define D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_TRAINING_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// Update '*var' according to the adadelta scheme.
//
// accum = rho() * accum + (1 - rho()) * grad.square();
// update = (update_accum + epsilon).sqrt() * (accum + epsilon()).rsqrt() * grad;
// update_accum = rho() * update_accum + (1 - rho()) * update.square();
// var -= update;
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * accum_update: Should be from a Variable().
// * lr: Scaling factor. Must be a scalar.
// * rho: Decay factor. Must be a scalar.
// * epsilon: Constant factor. Must be a scalar.
// * grad: The gradient.
class ApplyAdadelta {
 public:
  // Optional attribute setters for ApplyAdadelta :
  //
  // UseLocking(bool): Defaults to false
  //     If True, updating of the var, accum and update_accum tensors will be protected by
  // a lock; otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyAdadelta(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
              ::tensorflow::ops::Input accum, ::tensorflow::ops::Input
              accum_update, ::tensorflow::ops::Input lr,
              ::tensorflow::ops::Input rho, ::tensorflow::ops::Input epsilon,
              ::tensorflow::ops::Input grad);
  ApplyAdadelta(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
              ::tensorflow::ops::Input accum, ::tensorflow::ops::Input
              accum_update, ::tensorflow::ops::Input lr,
              ::tensorflow::ops::Input rho, ::tensorflow::ops::Input epsilon,
              ::tensorflow::ops::Input grad, const ApplyAdadelta::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the adagrad scheme.
//
// accum += grad * grad
// var -= lr * grad * (1 / sqrt(accum))
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * lr: Scaling factor. Must be a scalar.
// * grad: The gradient.
class ApplyAdagrad {
 public:
  // Optional attribute setters for ApplyAdagrad :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var and accum tensors will be protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyAdagrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
             ::tensorflow::ops::Input accum, ::tensorflow::ops::Input lr,
             ::tensorflow::ops::Input grad);
  ApplyAdagrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
             ::tensorflow::ops::Input accum, ::tensorflow::ops::Input lr,
             ::tensorflow::ops::Input grad, const ApplyAdagrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the proximal adagrad scheme.
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * gradient_accumulator: Should be from a Variable().
// * gradient_squared_accumulator: Should be from a Variable().
// * grad: The gradient.
// * lr: Scaling factor. Must be a scalar.
// * l1: L1 regularization. Must be a scalar.
// * l2: L2 regularization. Must be a scalar.
// * global_step: Training step number. Must be a scalar.
class ApplyAdagradDA {
 public:
  // Optional attribute setters for ApplyAdagradDA :
  //
  // UseLocking(bool): Defaults to false
  //     If True, updating of the var and accum tensors will be protected by
  // a lock; otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyAdagradDA(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
               ::tensorflow::ops::Input gradient_accumulator,
               ::tensorflow::ops::Input gradient_squared_accumulator,
               ::tensorflow::ops::Input grad, ::tensorflow::ops::Input lr,
               ::tensorflow::ops::Input l1, ::tensorflow::ops::Input l2,
               ::tensorflow::ops::Input global_step);
  ApplyAdagradDA(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
               ::tensorflow::ops::Input gradient_accumulator,
               ::tensorflow::ops::Input gradient_squared_accumulator,
               ::tensorflow::ops::Input grad, ::tensorflow::ops::Input lr,
               ::tensorflow::ops::Input l1, ::tensorflow::ops::Input l2,
               ::tensorflow::ops::Input global_step, const
               ApplyAdagradDA::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the Adam algorithm.
//
// lr_t <- learning_rate * sqrt(1 - beta2^t) / (1 - beta1^t)
// m_t <- beta1 * m_{t-1} + (1 - beta1) * g_t
// v_t <- beta2 * v_{t-1} + (1 - beta2) * g_t * g_t
// variable <- variable - lr_t * m_t / (sqrt(v_t) + epsilon)
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * m: Should be from a Variable().
// * v: Should be from a Variable().
// * beta1_power: Must be a scalar.
// * beta2_power: Must be a scalar.
// * lr: Scaling factor. Must be a scalar.
// * beta1: Momentum factor. Must be a scalar.
// * beta2: Momentum factor. Must be a scalar.
// * epsilon: Ridge term. Must be a scalar.
// * grad: The gradient.
class ApplyAdam {
 public:
  // Optional attribute setters for ApplyAdam :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var, m, and v tensors will be protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyAdam(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
          ::tensorflow::ops::Input m, ::tensorflow::ops::Input v,
          ::tensorflow::ops::Input beta1_power, ::tensorflow::ops::Input
          beta2_power, ::tensorflow::ops::Input lr, ::tensorflow::ops::Input
          beta1, ::tensorflow::ops::Input beta2, ::tensorflow::ops::Input
          epsilon, ::tensorflow::ops::Input grad);
  ApplyAdam(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
          ::tensorflow::ops::Input m, ::tensorflow::ops::Input v,
          ::tensorflow::ops::Input beta1_power, ::tensorflow::ops::Input
          beta2_power, ::tensorflow::ops::Input lr, ::tensorflow::ops::Input
          beta1, ::tensorflow::ops::Input beta2, ::tensorflow::ops::Input
          epsilon, ::tensorflow::ops::Input grad, const ApplyAdam::Attrs&
          attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the centered RMSProp algorithm.
//
// The centered RMSProp algorithm uses an estimate of the centered second moment
// (i.e., the variance) for normalization, as opposed to regular RMSProp, which
// uses the (uncentered) second moment. This often helps with training, but is
// slightly more expensive in terms of computation and memory.
//
// Note that in dense implementation of this algorithm, mg, ms, and mom will
// update even if the grad is zero, but in this sparse implementation, mg, ms,
// and mom will not update in iterations during which the grad is zero.
//
// mean_square = decay * mean_square + (1-decay) * gradient ** 2
// mean_grad = decay * mean_grad + (1-decay) * gradient
//
// Delta = learning_rate * gradient / sqrt(mean_square + epsilon - mean_grad ** 2)
//
// mg <- rho * mg_{t-1} + (1-rho) * grad
// ms <- rho * ms_{t-1} + (1-rho) * grad * grad
// mom <- momentum * mom_{t-1} + lr * grad / sqrt(ms - mg * mg + epsilon)
// var <- var - mom
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * mg: Should be from a Variable().
// * ms: Should be from a Variable().
// * mom: Should be from a Variable().
// * lr: Scaling factor. Must be a scalar.
// * rho: Decay rate. Must be a scalar.
// * epsilon: Ridge term. Must be a scalar.
// * grad: The gradient.
class ApplyCenteredRMSProp {
 public:
  // Optional attribute setters for ApplyCenteredRMSProp :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var, mg, ms, and mom tensors is
  // protected by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyCenteredRMSProp(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     var, ::tensorflow::ops::Input mg, ::tensorflow::ops::Input
                     ms, ::tensorflow::ops::Input mom, ::tensorflow::ops::Input
                     lr, ::tensorflow::ops::Input rho, ::tensorflow::ops::Input
                     momentum, ::tensorflow::ops::Input epsilon,
                     ::tensorflow::ops::Input grad);
  ApplyCenteredRMSProp(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     var, ::tensorflow::ops::Input mg, ::tensorflow::ops::Input
                     ms, ::tensorflow::ops::Input mom, ::tensorflow::ops::Input
                     lr, ::tensorflow::ops::Input rho, ::tensorflow::ops::Input
                     momentum, ::tensorflow::ops::Input epsilon,
                     ::tensorflow::ops::Input grad, const
                     ApplyCenteredRMSProp::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the Ftrl-proximal scheme.
//
// accum_new = accum + grad * grad
// linear += grad + (accum_new^(-lr_power) - accum^(-lr_power)) / lr * var
// quadratic = 1.0 / (accum_new^(lr_power) * lr) + 2 * l2
// var = (sign(linear) * l1 - linear) / quadratic if |linear| > l1 else 0.0
// accum = accum_new
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * linear: Should be from a Variable().
// * grad: The gradient.
// * lr: Scaling factor. Must be a scalar.
// * l1: L1 regulariation. Must be a scalar.
// * l2: L2 regulariation. Must be a scalar.
// * lr_power: Scaling factor. Must be a scalar.
class ApplyFtrl {
 public:
  // Optional attribute setters for ApplyFtrl :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var and accum tensors will be protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyFtrl(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
          ::tensorflow::ops::Input accum, ::tensorflow::ops::Input linear,
          ::tensorflow::ops::Input grad, ::tensorflow::ops::Input lr,
          ::tensorflow::ops::Input l1, ::tensorflow::ops::Input l2,
          ::tensorflow::ops::Input lr_power);
  ApplyFtrl(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
          ::tensorflow::ops::Input accum, ::tensorflow::ops::Input linear,
          ::tensorflow::ops::Input grad, ::tensorflow::ops::Input lr,
          ::tensorflow::ops::Input l1, ::tensorflow::ops::Input l2,
          ::tensorflow::ops::Input lr_power, const ApplyFtrl::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' by subtracting 'alpha' * 'delta' from it.
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * alpha: Scaling factor. Must be a scalar.
// * delta: The change.
class ApplyGradientDescent {
 public:
  // Optional attribute setters for ApplyGradientDescent :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, the subtraction will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyGradientDescent(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     var, ::tensorflow::ops::Input alpha,
                     ::tensorflow::ops::Input delta);
  ApplyGradientDescent(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     var, ::tensorflow::ops::Input alpha,
                     ::tensorflow::ops::Input delta, const
                     ApplyGradientDescent::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the momentum scheme. Set use_nesterov = True if you
//
// want to use Nesterov momentum.
//
// accum = accum * momentum + grad
// var -= lr * accum
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * lr: Scaling factor. Must be a scalar.
// * grad: The gradient.
// * momentum: Momentum. Must be a scalar.
class ApplyMomentum {
 public:
  // Optional attribute setters for ApplyMomentum :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var and accum tensors will be protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  // UseNesterov(bool): Defaults to false
  //     If `True`, the tensor passed to compute grad will be
  // var - lr * momentum * accum, so in the end, the var you get is actually
  // var - lr * momentum * accum.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    Attrs UseNesterov(bool x) {
      Attrs ret = *this;
      ret.use_nesterov_ = x;
      return ret;
    }

    bool use_locking_ = false;
    bool use_nesterov_ = false;
  };
  ApplyMomentum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
              ::tensorflow::ops::Input accum, ::tensorflow::ops::Input lr,
              ::tensorflow::ops::Input grad, ::tensorflow::ops::Input momentum);
  ApplyMomentum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
              ::tensorflow::ops::Input accum, ::tensorflow::ops::Input lr,
              ::tensorflow::ops::Input grad, ::tensorflow::ops::Input momentum,
              const ApplyMomentum::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }
  static Attrs UseNesterov(bool x) {
    return Attrs().UseNesterov(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' and '*accum' according to FOBOS with Adagrad learning rate.
//
// accum += grad * grad
// prox_v = var - lr * grad * (1 / sqrt(accum))
// var = sign(prox_v)/(1+lr*l2) * max{|prox_v|-lr*l1,0}
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * lr: Scaling factor. Must be a scalar.
// * l1: L1 regularization. Must be a scalar.
// * l2: L2 regularization. Must be a scalar.
// * grad: The gradient.
class ApplyProximalAdagrad {
 public:
  // Optional attribute setters for ApplyProximalAdagrad :
  //
  // UseLocking(bool): Defaults to false
  //     If True, updating of the var and accum tensors will be protected by
  // a lock; otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyProximalAdagrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     var, ::tensorflow::ops::Input accum,
                     ::tensorflow::ops::Input lr, ::tensorflow::ops::Input l1,
                     ::tensorflow::ops::Input l2, ::tensorflow::ops::Input
                     grad);
  ApplyProximalAdagrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     var, ::tensorflow::ops::Input accum,
                     ::tensorflow::ops::Input lr, ::tensorflow::ops::Input l1,
                     ::tensorflow::ops::Input l2, ::tensorflow::ops::Input
                     grad, const ApplyProximalAdagrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' as FOBOS algorithm with fixed learning rate.
//
// prox_v = var - alpha * delta
// var = sign(prox_v)/(1+alpha*l2) * max{|prox_v|-alpha*l1,0}
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * alpha: Scaling factor. Must be a scalar.
// * l1: L1 regularization. Must be a scalar.
// * l2: L2 regularization. Must be a scalar.
// * delta: The change.
class ApplyProximalGradientDescent {
 public:
  // Optional attribute setters for ApplyProximalGradientDescent :
  //
  // UseLocking(bool): Defaults to false
  //     If True, the subtraction will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyProximalGradientDescent(const ::tensorflow::Scope& scope,
                             ::tensorflow::ops::Input var,
                             ::tensorflow::ops::Input alpha,
                             ::tensorflow::ops::Input l1,
                             ::tensorflow::ops::Input l2,
                             ::tensorflow::ops::Input delta);
  ApplyProximalGradientDescent(const ::tensorflow::Scope& scope,
                             ::tensorflow::ops::Input var,
                             ::tensorflow::ops::Input alpha,
                             ::tensorflow::ops::Input l1,
                             ::tensorflow::ops::Input l2,
                             ::tensorflow::ops::Input delta, const
                             ApplyProximalGradientDescent::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the RMSProp algorithm.
//
// Note that in dense implementation of this algorithm, ms and mom will
// update even if the grad is zero, but in this sparse implementation, ms
// and mom will not update in iterations during which the grad is zero.
//
// mean_square = decay * mean_square + (1-decay) * gradient ** 2
// Delta = learning_rate * gradient / sqrt(mean_square + epsilon)
//
// ms <- rho * ms_{t-1} + (1-rho) * grad * grad
// mom <- momentum * mom_{t-1} + lr * grad / sqrt(ms + epsilon)
// var <- var - mom
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * ms: Should be from a Variable().
// * mom: Should be from a Variable().
// * lr: Scaling factor. Must be a scalar.
// * rho: Decay rate. Must be a scalar.
// * epsilon: Ridge term. Must be a scalar.
// * grad: The gradient.
class ApplyRMSProp {
 public:
  // Optional attribute setters for ApplyRMSProp :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var, ms, and mom tensors is protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  ApplyRMSProp(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
             ::tensorflow::ops::Input ms, ::tensorflow::ops::Input mom,
             ::tensorflow::ops::Input lr, ::tensorflow::ops::Input rho,
             ::tensorflow::ops::Input momentum, ::tensorflow::ops::Input
             epsilon, ::tensorflow::ops::Input grad);
  ApplyRMSProp(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
             ::tensorflow::ops::Input ms, ::tensorflow::ops::Input mom,
             ::tensorflow::ops::Input lr, ::tensorflow::ops::Input rho,
             ::tensorflow::ops::Input momentum, ::tensorflow::ops::Input
             epsilon, ::tensorflow::ops::Input grad, const ApplyRMSProp::Attrs&
             attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// var: Should be from a Variable().
//
// Arguments:
// * scope: A Scope object
// * accum: Should be from a Variable().
// * accum_update: : Should be from a Variable().
// * lr: Learning rate. Must be a scalar.
// * rho: Decay factor. Must be a scalar.
// * epsilon: Constant factor. Must be a scalar.
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var and accum.
class SparseApplyAdadelta {
 public:
  // Optional attribute setters for SparseApplyAdadelta :
  //
  // UseLocking(bool): Defaults to false
  //     If True, updating of the var and accum tensors will be protected by
  // a lock; otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  SparseApplyAdadelta(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    var, ::tensorflow::ops::Input accum,
                    ::tensorflow::ops::Input accum_update,
                    ::tensorflow::ops::Input lr, ::tensorflow::ops::Input rho,
                    ::tensorflow::ops::Input epsilon, ::tensorflow::ops::Input
                    grad, ::tensorflow::ops::Input indices);
  SparseApplyAdadelta(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    var, ::tensorflow::ops::Input accum,
                    ::tensorflow::ops::Input accum_update,
                    ::tensorflow::ops::Input lr, ::tensorflow::ops::Input rho,
                    ::tensorflow::ops::Input epsilon, ::tensorflow::ops::Input
                    grad, ::tensorflow::ops::Input indices, const
                    SparseApplyAdadelta::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update relevant entries in '*var' and '*accum' according to the adagrad scheme.
//
// That is for rows we have grad for, we update var and accum as follows:
// accum += grad * grad
// var -= lr * grad * (1 / sqrt(accum))
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * lr: Learning rate. Must be a scalar.
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var and accum.
class SparseApplyAdagrad {
 public:
  // Optional attribute setters for SparseApplyAdagrad :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var and accum tensors will be protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  SparseApplyAdagrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   var, ::tensorflow::ops::Input accum,
                   ::tensorflow::ops::Input lr, ::tensorflow::ops::Input grad,
                   ::tensorflow::ops::Input indices);
  SparseApplyAdagrad(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   var, ::tensorflow::ops::Input accum,
                   ::tensorflow::ops::Input lr, ::tensorflow::ops::Input grad,
                   ::tensorflow::ops::Input indices, const
                   SparseApplyAdagrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update entries in '*var' and '*accum' according to the proximal adagrad scheme.
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * gradient_accumulator: Should be from a Variable().
// * gradient_squared_accumulator: Should be from a Variable().
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var and accum.
// * lr: Learning rate. Must be a scalar.
// * l1: L1 regularization. Must be a scalar.
// * l2: L2 regularization. Must be a scalar.
// * global_step: Training step number. Must be a scalar.
class SparseApplyAdagradDA {
 public:
  // Optional attribute setters for SparseApplyAdagradDA :
  //
  // UseLocking(bool): Defaults to false
  //     If True, updating of the var and accum tensors will be protected by
  // a lock; otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  SparseApplyAdagradDA(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     var, ::tensorflow::ops::Input gradient_accumulator,
                     ::tensorflow::ops::Input gradient_squared_accumulator,
                     ::tensorflow::ops::Input grad, ::tensorflow::ops::Input
                     indices, ::tensorflow::ops::Input lr,
                     ::tensorflow::ops::Input l1, ::tensorflow::ops::Input l2,
                     ::tensorflow::ops::Input global_step);
  SparseApplyAdagradDA(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                     var, ::tensorflow::ops::Input gradient_accumulator,
                     ::tensorflow::ops::Input gradient_squared_accumulator,
                     ::tensorflow::ops::Input grad, ::tensorflow::ops::Input
                     indices, ::tensorflow::ops::Input lr,
                     ::tensorflow::ops::Input l1, ::tensorflow::ops::Input l2,
                     ::tensorflow::ops::Input global_step, const
                     SparseApplyAdagradDA::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the centered RMSProp algorithm.
//
// The centered RMSProp algorithm uses an estimate of the centered second moment
// (i.e., the variance) for normalization, as opposed to regular RMSProp, which
// uses the (uncentered) second moment. This often helps with training, but is
// slightly more expensive in terms of computation and memory.
//
// Note that in dense implementation of this algorithm, mg, ms, and mom will
// update even if the grad is zero, but in this sparse implementation, mg, ms,
// and mom will not update in iterations during which the grad is zero.
//
// mean_square = decay * mean_square + (1-decay) * gradient ** 2
// mean_grad = decay * mean_grad + (1-decay) * gradient
// Delta = learning_rate * gradient / sqrt(mean_square + epsilon - mean_grad ** 2)
//
// ms <- rho * ms_{t-1} + (1-rho) * grad * grad
// mom <- momentum * mom_{t-1} + lr * grad / sqrt(ms + epsilon)
// var <- var - mom
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * mg: Should be from a Variable().
// * ms: Should be from a Variable().
// * mom: Should be from a Variable().
// * lr: Scaling factor. Must be a scalar.
// * rho: Decay rate. Must be a scalar.
// * epsilon: Ridge term. Must be a scalar.
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var, ms and mom.
class SparseApplyCenteredRMSProp {
 public:
  // Optional attribute setters for SparseApplyCenteredRMSProp :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var, mg, ms, and mom tensors is
  // protected by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  SparseApplyCenteredRMSProp(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input var,
                           ::tensorflow::ops::Input mg,
                           ::tensorflow::ops::Input ms,
                           ::tensorflow::ops::Input mom,
                           ::tensorflow::ops::Input lr,
                           ::tensorflow::ops::Input rho,
                           ::tensorflow::ops::Input momentum,
                           ::tensorflow::ops::Input epsilon,
                           ::tensorflow::ops::Input grad,
                           ::tensorflow::ops::Input indices);
  SparseApplyCenteredRMSProp(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input var,
                           ::tensorflow::ops::Input mg,
                           ::tensorflow::ops::Input ms,
                           ::tensorflow::ops::Input mom,
                           ::tensorflow::ops::Input lr,
                           ::tensorflow::ops::Input rho,
                           ::tensorflow::ops::Input momentum,
                           ::tensorflow::ops::Input epsilon,
                           ::tensorflow::ops::Input grad,
                           ::tensorflow::ops::Input indices, const
                           SparseApplyCenteredRMSProp::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update relevant entries in '*var' according to the Ftrl-proximal scheme.
//
// That is for rows we have grad for, we update var, accum and linear as follows:
// accum_new = accum + grad * grad
// linear += grad + (accum_new^(-lr_power) - accum^(-lr_power)) / lr * var
// quadratic = 1.0 / (accum_new^(lr_power) * lr) + 2 * l2
// var = (sign(linear) * l1 - linear) / quadratic if |linear| > l1 else 0.0
// accum = accum_new
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * linear: Should be from a Variable().
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var and accum.
// * lr: Scaling factor. Must be a scalar.
// * l1: L1 regularization. Must be a scalar.
// * l2: L2 regularization. Must be a scalar.
// * lr_power: Scaling factor. Must be a scalar.
class SparseApplyFtrl {
 public:
  // Optional attribute setters for SparseApplyFtrl :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var and accum tensors will be protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  SparseApplyFtrl(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
                ::tensorflow::ops::Input accum, ::tensorflow::ops::Input
                linear, ::tensorflow::ops::Input grad, ::tensorflow::ops::Input
                indices, ::tensorflow::ops::Input lr, ::tensorflow::ops::Input
                l1, ::tensorflow::ops::Input l2, ::tensorflow::ops::Input
                lr_power);
  SparseApplyFtrl(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input var,
                ::tensorflow::ops::Input accum, ::tensorflow::ops::Input
                linear, ::tensorflow::ops::Input grad, ::tensorflow::ops::Input
                indices, ::tensorflow::ops::Input lr, ::tensorflow::ops::Input
                l1, ::tensorflow::ops::Input l2, ::tensorflow::ops::Input
                lr_power, const SparseApplyFtrl::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update relevant entries in '*var' and '*accum' according to the momentum scheme.
//
// Set use_nesterov = True if you want to use Nesterov momentum.
//
// That is for rows we have grad for, we update var and accum as follows:
//
// accum = accum * momentum + grad
// var -= lr * accum
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * lr: Learning rate. Must be a scalar.
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var and accum.
// * momentum: Momentum. Must be a scalar.
class SparseApplyMomentum {
 public:
  // Optional attribute setters for SparseApplyMomentum :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var and accum tensors will be protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  // UseNesterov(bool): Defaults to false
  //     If `True`, the tensor passed to compute grad will be
  // var - lr * momentum * accum, so in the end, the var you get is actually
  // var - lr * momentum * accum.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    Attrs UseNesterov(bool x) {
      Attrs ret = *this;
      ret.use_nesterov_ = x;
      return ret;
    }

    bool use_locking_ = false;
    bool use_nesterov_ = false;
  };
  SparseApplyMomentum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    var, ::tensorflow::ops::Input accum,
                    ::tensorflow::ops::Input lr, ::tensorflow::ops::Input grad,
                    ::tensorflow::ops::Input indices, ::tensorflow::ops::Input
                    momentum);
  SparseApplyMomentum(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                    var, ::tensorflow::ops::Input accum,
                    ::tensorflow::ops::Input lr, ::tensorflow::ops::Input grad,
                    ::tensorflow::ops::Input indices, ::tensorflow::ops::Input
                    momentum, const SparseApplyMomentum::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }
  static Attrs UseNesterov(bool x) {
    return Attrs().UseNesterov(x);
  }

  ::tensorflow::ops::Output out;
};

// Sparse update entries in '*var' and '*accum' according to FOBOS algorithm.
//
// That is for rows we have grad for, we update var and accum as follows:
// accum += grad * grad
// prox_v = var
// prox_v -= lr * grad * (1 / sqrt(accum))
// var = sign(prox_v)/(1+lr*l2) * max{|prox_v|-lr*l1,0}
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * accum: Should be from a Variable().
// * lr: Learning rate. Must be a scalar.
// * l1: L1 regularization. Must be a scalar.
// * l2: L2 regularization. Must be a scalar.
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var and accum.
class SparseApplyProximalAdagrad {
 public:
  // Optional attribute setters for SparseApplyProximalAdagrad :
  //
  // UseLocking(bool): Defaults to false
  //     If True, updating of the var and accum tensors will be protected by
  // a lock; otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  SparseApplyProximalAdagrad(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input var,
                           ::tensorflow::ops::Input accum,
                           ::tensorflow::ops::Input lr,
                           ::tensorflow::ops::Input l1,
                           ::tensorflow::ops::Input l2,
                           ::tensorflow::ops::Input grad,
                           ::tensorflow::ops::Input indices);
  SparseApplyProximalAdagrad(const ::tensorflow::Scope& scope,
                           ::tensorflow::ops::Input var,
                           ::tensorflow::ops::Input accum,
                           ::tensorflow::ops::Input lr,
                           ::tensorflow::ops::Input l1,
                           ::tensorflow::ops::Input l2,
                           ::tensorflow::ops::Input grad,
                           ::tensorflow::ops::Input indices, const
                           SparseApplyProximalAdagrad::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Sparse update '*var' as FOBOS algorithm with fixed learning rate.
//
// That is for rows we have grad for, we update var as follows:
// prox_v = var - alpha * grad
// var = sign(prox_v)/(1+alpha*l2) * max{|prox_v|-alpha*l1,0}
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * alpha: Scaling factor. Must be a scalar.
// * l1: L1 regularization. Must be a scalar.
// * l2: L2 regularization. Must be a scalar.
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var and accum.
class SparseApplyProximalGradientDescent {
 public:
  // Optional attribute setters for SparseApplyProximalGradientDescent :
  //
  // UseLocking(bool): Defaults to false
  //     If True, the subtraction will be protected by a lock;
  // otherwise the behavior is undefined, but may exhibit less contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  SparseApplyProximalGradientDescent(const ::tensorflow::Scope& scope,
                                   ::tensorflow::ops::Input var,
                                   ::tensorflow::ops::Input alpha,
                                   ::tensorflow::ops::Input l1,
                                   ::tensorflow::ops::Input l2,
                                   ::tensorflow::ops::Input grad,
                                   ::tensorflow::ops::Input indices);
  SparseApplyProximalGradientDescent(const ::tensorflow::Scope& scope,
                                   ::tensorflow::ops::Input var,
                                   ::tensorflow::ops::Input alpha,
                                   ::tensorflow::ops::Input l1,
                                   ::tensorflow::ops::Input l2,
                                   ::tensorflow::ops::Input grad,
                                   ::tensorflow::ops::Input indices, const
                                   SparseApplyProximalGradientDescent::Attrs&
                                   attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

// Update '*var' according to the RMSProp algorithm.
//
// Note that in dense implementation of this algorithm, ms and mom will
// update even if the grad is zero, but in this sparse implementation, ms
// and mom will not update in iterations during which the grad is zero.
//
// mean_square = decay * mean_square + (1-decay) * gradient ** 2
// Delta = learning_rate * gradient / sqrt(mean_square + epsilon)
//
// ms <- rho * ms_{t-1} + (1-rho) * grad * grad
// mom <- momentum * mom_{t-1} + lr * grad / sqrt(ms + epsilon)
// var <- var - mom
//
// Arguments:
// * scope: A Scope object
// * var: Should be from a Variable().
// * ms: Should be from a Variable().
// * mom: Should be from a Variable().
// * lr: Scaling factor. Must be a scalar.
// * rho: Decay rate. Must be a scalar.
// * epsilon: Ridge term. Must be a scalar.
// * grad: The gradient.
// * indices: A vector of indices into the first dimension of var, ms and mom.
class SparseApplyRMSProp {
 public:
  // Optional attribute setters for SparseApplyRMSProp :
  //
  // UseLocking(bool): Defaults to false
  //     If `True`, updating of the var, ms, and mom tensors is protected
  // by a lock; otherwise the behavior is undefined, but may exhibit less
  // contention.
  struct Attrs {
    Attrs UseLocking(bool x) {
      Attrs ret = *this;
      ret.use_locking_ = x;
      return ret;
    }

    bool use_locking_ = false;
  };
  SparseApplyRMSProp(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   var, ::tensorflow::ops::Input ms, ::tensorflow::ops::Input
                   mom, ::tensorflow::ops::Input lr, ::tensorflow::ops::Input
                   rho, ::tensorflow::ops::Input momentum,
                   ::tensorflow::ops::Input epsilon, ::tensorflow::ops::Input
                   grad, ::tensorflow::ops::Input indices);
  SparseApplyRMSProp(const ::tensorflow::Scope& scope, ::tensorflow::ops::Input
                   var, ::tensorflow::ops::Input ms, ::tensorflow::ops::Input
                   mom, ::tensorflow::ops::Input lr, ::tensorflow::ops::Input
                   rho, ::tensorflow::ops::Input momentum,
                   ::tensorflow::ops::Input epsilon, ::tensorflow::ops::Input
                   grad, ::tensorflow::ops::Input indices, const
                   SparseApplyRMSProp::Attrs& attrs);
  operator ::tensorflow::ops::Output() const { return out; }
  operator ::tensorflow::ops::Input() const { return out; }
  ::tensorflow::Node* node() const { return out.node(); }

  static Attrs UseLocking(bool x) {
    return Attrs().UseLocking(x);
  }

  ::tensorflow::ops::Output out;
};

}  // namespace ops
}  // namespace tensorflow

#endif  // D_____WORK_TENSORFLOW_FOR_VS_TENSORFLOW_TENSORFLOW_CONTRIB_CMAKE_BUILD_RELEASE_TENSORFLOW_CC_OPS_TRAINING_OPS_H_
