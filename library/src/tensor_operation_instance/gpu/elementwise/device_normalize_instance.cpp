// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2024, Advanced Micro Devices, Inc. All rights reserved.

#include <cstdlib>

#include "ck/ck.hpp"
#include "ck/tensor_operation/gpu/device/tensor_layout.hpp"
#include "ck/tensor_operation/gpu/device/gemm_specialization.hpp"
#include "ck/tensor_operation/gpu/device/impl/device_elementwise_dynamic_vector_dims_impl.hpp"
#include "ck/library/tensor_operation_instance/add_device_operation_instance.hpp"

namespace ck {
namespace tensor_operation {
namespace device {
namespace instance {

using F16 = ck::half_t;
using F32 = float;

using inputType      = F16;
using MeanType       = F32;
using SquareMeanType = F32;
using GammaDataType  = F16;
using BetaDataType   = F16;
using outputType     = F16;

using Normalize = ck::tensor_operation::element_wise::Normalize;
using device_normalize_from_mean_squaremean_f16_f32_f32_f16_f16_instances = std::tuple<
    // clang-format off
    //###################|<in, mean, square_mean, gamma, beta>| <out>|  functor| NDim| BlockSize| M/NPerBlock|| M/NPerThread| ThreadClusterArrangeOrder| <in, mean, square_mean, gamma, beta ScalarPerVector>| <out ScalarPerVector>|
    DeviceElementwiseImpl<Tuple<F16, F32, F32, F16, F16>,  Tuple<F16>,  Normalize,  2, 256,          128, 128,         8, 8,         ck::Sequence<1, 0>,                             Sequence<8, 1, 1, 8, 8>,      Sequence<8>>,
    DeviceElementwiseImpl<Tuple<F16, F32, F32, F16, F16>,  Tuple<F16>,  Normalize,  2,  64,           64,  64,         8, 8,         ck::Sequence<1, 0>,                             Sequence<8, 1, 1, 8, 8>,      Sequence<8>>,
    DeviceElementwiseImpl<Tuple<F16, F32, F32, F16, F16>,  Tuple<F16>,  Normalize,  2, 256,           64,  64,         4, 4,         ck::Sequence<1, 0>,                             Sequence<4, 1, 1, 4, 4>,      Sequence<4>>,
    DeviceElementwiseImpl<Tuple<F16, F32, F32, F16, F16>,  Tuple<F16>,  Normalize,  2,  64,           32,  32,         4, 4,         ck::Sequence<1, 0>,                             Sequence<4, 1, 1, 4, 4>,      Sequence<4>>,
    DeviceElementwiseImpl<Tuple<F16, F32, F32, F16, F16>,  Tuple<F16>,  Normalize,  2, 256,           64,  64,         4, 4,         ck::Sequence<1, 0>,                             Sequence<2, 1, 1, 2, 2>,      Sequence<2>>,
    DeviceElementwiseImpl<Tuple<F16, F32, F32, F16, F16>,  Tuple<F16>,  Normalize,  2,  64,           16,  16,         2, 2,         ck::Sequence<1, 0>,                             Sequence<2, 1, 1, 2, 2>,      Sequence<2>>
    // clang-format on
    >;

using device_normalize_from_mean_squaremean_f16_f32_f32_f16_f16_generic_instance = std::tuple<
    // clang-format off
    DeviceElementwiseImpl<Tuple<F16, F32, F32, F16, F16>,  Tuple<F16>,  Normalize,  2, 256,           64,  64,         4, 4,         ck::Sequence<1, 0>,                             Sequence<1, 1, 1, 1, 1>,      Sequence<1>>,
    DeviceElementwiseImpl<Tuple<F16, F32, F32, F16, F16>,  Tuple<F16>,  Normalize,  2, 64,            32,  32,         4, 4,         ck::Sequence<1, 0>,                             Sequence<1, 1, 1, 1, 1>,      Sequence<1>>
    // clang-format on
    >;

void add_device_normalize_from_mean_squaremean_f16_f32_f32_f16_f16_instances(
    std::vector<DeviceElementwisePtr<Tuple<F16, F32, F32, F16, F16>, Tuple<F16>, Normalize, 2>>&
        instances)
{
    add_device_operation_instances(
        instances, device_normalize_from_mean_squaremean_f16_f32_f32_f16_f16_generic_instance{});

    add_device_operation_instances(
        instances, device_normalize_from_mean_squaremean_f16_f32_f32_f16_f16_instances{});
}

} // namespace instance
} // namespace device
} // namespace tensor_operation
} // namespace ck
