// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2023, Advanced Micro Devices, Inc. All rights reserved.

#include <cstdlib>

#include "ck/ck.hpp"
#include "ck/tensor_operation/gpu/device/tensor_layout.hpp"
#include "ck/tensor_operation/gpu/device/gemm_specialization.hpp"
#include "ck/tensor_operation/gpu/device/impl/device_gemm_multiple_abd_xdl_cshuffle.hpp"

#include "device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_common.hpp"

#include "ck/library/tensor_operation_instance/add_device_operation_instance.hpp"

namespace ck {
namespace tensor_operation {
namespace device {
namespace instance {

void add_device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_bias_gelu_v1_instances(
    std::vector<std::unique_ptr<DeviceGemmMultipleABD<AsLayout,
                                                      ck::Tuple<B0Layout, B1Layout>,
                                                      ck::Tuple<D0Layout>,
                                                      ELayout,
                                                      AsDataType,
                                                      ck::Tuple<B0DataType, B1DataType>,
                                                      ck::Tuple<D0DataType>,
                                                      EDataType,
                                                      AElementOp,
                                                      Multiply,
                                                      AddFastGelu>>>& instances)
{
    add_device_operation_instances(instances,
                                   device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_comp_instances<
                                       ck::Tuple<B0Layout, B1Layout>,
                                       ck::Tuple<D0Layout>,
                                       ck::Tuple<B0DataType, B1DataType>,
                                       ck::Tuple<D0DataType>,
                                       Multiply,
                                       AddFastGelu,
                                       GemmMNKPadding,
                                       Interwave>{});
    add_device_operation_instances(instances,
                                   device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_mem_instances<
                                       ck::Tuple<B0Layout, B1Layout>,
                                       ck::Tuple<D0Layout>,
                                       ck::Tuple<B0DataType, B1DataType>,
                                       ck::Tuple<D0DataType>,
                                       Multiply,
                                       AddFastGelu,
                                       GemmMNKPadding,
                                       Interwave>{});
}

void add_device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_bias_v1_instances(
    std::vector<std::unique_ptr<DeviceGemmMultipleABD<AsLayout,
                                                      ck::Tuple<B0Layout, B1Layout>,
                                                      ck::Tuple<D0Layout>,
                                                      ELayout,
                                                      AsDataType,
                                                      ck::Tuple<B0DataType, B1DataType>,
                                                      ck::Tuple<D0DataType>,
                                                      EDataType,
                                                      AElementOp,
                                                      Multiply,
                                                      Add>>>& instances)
{
    add_device_operation_instances(instances,
                                   device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_comp_instances<
                                       ck::Tuple<B0Layout, B1Layout>,
                                       ck::Tuple<D0Layout>,
                                       ck::Tuple<B0DataType, B1DataType>,
                                       ck::Tuple<D0DataType>,
                                       Multiply,
                                       Add,
                                       GemmMNKPadding,
                                       Interwave>{});
    add_device_operation_instances(instances,
                                   device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_mem_instances<
                                       ck::Tuple<B0Layout, B1Layout>,
                                       ck::Tuple<D0Layout>,
                                       ck::Tuple<B0DataType, B1DataType>,
                                       ck::Tuple<D0DataType>,
                                       Multiply,
                                       Add,
                                       GemmMNKPadding,
                                       Interwave>{});
}

void add_device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_v1_instances(
    std::vector<std::unique_ptr<DeviceGemmMultipleABD<AsLayout,
                                                      ck::Tuple<B0Layout, B1Layout>,
                                                      ck::Tuple<>,
                                                      ELayout,
                                                      AsDataType,
                                                      ck::Tuple<B0DataType, B1DataType>,
                                                      ck::Tuple<>,
                                                      EDataType,
                                                      AElementOp,
                                                      Multiply,
                                                      PassThrough>>>& instances)
{
    add_device_operation_instances(instances,
                                   device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_comp_instances<
                                       ck::Tuple<B0Layout, B1Layout>,
                                       ck::Tuple<>,
                                       ck::Tuple<B0DataType, B1DataType>,
                                       ck::Tuple<>,
                                       Multiply,
                                       PassThrough,
                                       GemmMNKPadding,
                                       Interwave>{});
    add_device_operation_instances(instances,
                                   device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_mem_instances<
                                       ck::Tuple<B0Layout, B1Layout>,
                                       ck::Tuple<>,
                                       ck::Tuple<B0DataType, B1DataType>,
                                       ck::Tuple<>,
                                       Multiply,
                                       PassThrough,
                                       GemmMNKPadding,
                                       Interwave>{});
}

void add_device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_gelu_v1_instances(
    std::vector<std::unique_ptr<DeviceGemmMultipleABD<AsLayout,
                                                      ck::Tuple<B0Layout, B1Layout>,
                                                      ck::Tuple<>,
                                                      ELayout,
                                                      AsDataType,
                                                      ck::Tuple<B0DataType, B1DataType>,
                                                      ck::Tuple<>,
                                                      EDataType,
                                                      AElementOp,
                                                      Multiply,
                                                      FastGelu>>>& instances)
{
    add_device_operation_instances(instances,
                                   device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_comp_instances<
                                       ck::Tuple<B0Layout, B1Layout>,
                                       ck::Tuple<>,
                                       ck::Tuple<B0DataType, B1DataType>,
                                       ck::Tuple<>,
                                       Multiply,
                                       FastGelu,
                                       GemmMNKPadding,
                                       Interwave>{});

    add_device_operation_instances(instances,
                                   device_gemm_xdl_multi_abd_bf16_i8_bf16_mk_kn_mn_mem_instances<
                                       ck::Tuple<B0Layout, B1Layout>,
                                       ck::Tuple<>,
                                       ck::Tuple<B0DataType, B1DataType>,
                                       ck::Tuple<>,
                                       Multiply,
                                       FastGelu,
                                       GemmMNKPadding,
                                       Interwave>{});
}

} // namespace instance
} // namespace device
} // namespace tensor_operation
} // namespace ck
