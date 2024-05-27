// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_gnss_yaw_pred_innov_var_and_h
 *
 * Args:
 *     state: Matrix25_1
 *     P: Matrix24_24
 *     antenna_yaw_offset: Scalar
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     meas_pred: Scalar
 *     innov_var: Scalar
 *     H: Matrix24_1
 */
template <typename Scalar>
void ComputeGnssYawPredInnovVarAndH(const matrix::Matrix<Scalar, 25, 1>& state,
                                    const matrix::Matrix<Scalar, 24, 24>& P,
                                    const Scalar antenna_yaw_offset, const Scalar R,
                                    const Scalar epsilon, Scalar* const meas_pred = nullptr,
                                    Scalar* const innov_var = nullptr,
                                    matrix::Matrix<Scalar, 24, 1>* const H = nullptr) {
  // Total ops: 114

  // Input arrays

  // Intermediate terms (29)
  const Scalar _tmp0 = 1 - 2 * std::pow(state(3, 0), Scalar(2));
  const Scalar _tmp1 = std::sin(antenna_yaw_offset);
  const Scalar _tmp2 = 2 * state(0, 0) * state(3, 0);
  const Scalar _tmp3 = 2 * state(1, 0) * state(2, 0);
  const Scalar _tmp4 = std::cos(antenna_yaw_offset);
  const Scalar _tmp5 =
      _tmp1 * (_tmp0 - 2 * std::pow(state(1, 0), Scalar(2))) + _tmp4 * (_tmp2 + _tmp3);
  const Scalar _tmp6 =
      _tmp1 * (-_tmp2 + _tmp3) + _tmp4 * (_tmp0 - 2 * std::pow(state(2, 0), Scalar(2)));
  const Scalar _tmp7 = _tmp6 + epsilon * ((((_tmp6) > 0) - ((_tmp6) < 0)) + Scalar(0.5));
  const Scalar _tmp8 = 2 * _tmp1;
  const Scalar _tmp9 = std::pow(_tmp7, Scalar(2));
  const Scalar _tmp10 = _tmp5 / _tmp9;
  const Scalar _tmp11 = _tmp10 * _tmp8;
  const Scalar _tmp12 = 4 * _tmp1;
  const Scalar _tmp13 = 2 * _tmp4;
  const Scalar _tmp14 = Scalar(1.0) / (_tmp7);
  const Scalar _tmp15 =
      -_tmp11 * state(2, 0) + _tmp14 * (-_tmp12 * state(1, 0) + _tmp13 * state(2, 0));
  const Scalar _tmp16 = (Scalar(1) / Scalar(2)) * _tmp9 / (std::pow(_tmp5, Scalar(2)) + _tmp9);
  const Scalar _tmp17 = _tmp15 * _tmp16;
  const Scalar _tmp18 = _tmp13 * _tmp14;
  const Scalar _tmp19 = _tmp11 * state(3, 0) + _tmp18 * state(3, 0);
  const Scalar _tmp20 = _tmp16 * _tmp19;
  const Scalar _tmp21 = 4 * _tmp4;
  const Scalar _tmp22 = -_tmp10 * (-_tmp21 * state(3, 0) - _tmp8 * state(0, 0)) +
                        _tmp14 * (-_tmp12 * state(3, 0) + _tmp13 * state(0, 0));
  const Scalar _tmp23 = _tmp16 * state(2, 0);
  const Scalar _tmp24 =
      _tmp16 * (-_tmp10 * (-_tmp21 * state(2, 0) + _tmp8 * state(1, 0)) + _tmp18 * state(1, 0));
  const Scalar _tmp25 =
      _tmp17 * state(0, 0) - _tmp20 * state(1, 0) + _tmp22 * _tmp23 - _tmp24 * state(3, 0);
  const Scalar _tmp26 = _tmp16 * _tmp22;
  const Scalar _tmp27 =
      _tmp17 * state(3, 0) - _tmp19 * _tmp23 + _tmp24 * state(0, 0) - _tmp26 * state(1, 0);
  const Scalar _tmp28 =
      -_tmp15 * _tmp23 - _tmp20 * state(3, 0) + _tmp24 * state(1, 0) + _tmp26 * state(0, 0);

  // Output terms (3)
  if (meas_pred != nullptr) {
    Scalar& _meas_pred = (*meas_pred);

    _meas_pred = std::atan2(_tmp5, _tmp7);
  }

  if (innov_var != nullptr) {
    Scalar& _innov_var = (*innov_var);

    _innov_var = R + _tmp25 * (P(0, 0) * _tmp25 + P(1, 0) * _tmp27 + P(2, 0) * _tmp28) +
                 _tmp27 * (P(0, 1) * _tmp25 + P(1, 1) * _tmp27 + P(2, 1) * _tmp28) +
                 _tmp28 * (P(0, 2) * _tmp25 + P(1, 2) * _tmp27 + P(2, 2) * _tmp28);
  }

  if (H != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _h = (*H);

    _h.setZero();

    _h(0, 0) = _tmp25;
    _h(1, 0) = _tmp27;
    _h(2, 0) = _tmp28;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
