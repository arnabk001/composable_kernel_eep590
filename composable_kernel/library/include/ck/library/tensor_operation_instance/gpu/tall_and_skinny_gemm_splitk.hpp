// SPDX-License-Identifier: MIT
// Copyright (c) 2023, Advanced Micro Devices, Inc. All rights reserved.

#pragma once

#include <vector>
#include <memory>
#include "ck/ck.hpp"
#include "ck/tensor_operation/gpu/device/tensor_layout.hpp"
#include "ck/tensor_operation/gpu/device/device_tall_and_skinny_gemm.hpp"
#include "ck/tensor_operation/gpu/element/element_wise_operation.hpp"

#include "ck/library/tensor_operation_instance/device_operation_instance_factory.hpp"

namespace ck {
namespace tensor_operation {
namespace device {
namespace instance {

void add_device_tall_and_skinny_gemm_splitk_f16_f16_f16_mk_kn_mn_instances(
    std::vector<std::unique_ptr<
        DeviceTsmm<Row, Row, Row, F16, F16, F16, PassThrough, PassThrough, PassThrough>>>&
        instances);

void add_device_tall_and_skinny_gemm_splitk_f16_f16_f16_mk_nk_mn_instances(
    std::vector<std::unique_ptr<
        DeviceTsmm<Row, Col, Row, F16, F16, F16, PassThrough, PassThrough, PassThrough>>>&
        instances);

template <typename ADataType,
          typename BDataType,
          typename CDataType,
          typename ALayout,
          typename BLayout,
          typename CLayout>
struct DeviceOperationInstanceFactory<
    ck::tensor_operation::device::DeviceTsmm<ALayout,
                                             BLayout,
                                             CLayout,
                                             ADataType,
                                             BDataType,
                                             CDataType,
                                             ck::tensor_operation::element_wise::PassThrough,
                                             ck::tensor_operation::element_wise::PassThrough,
                                             ck::tensor_operation::element_wise::PassThrough>>
{
    using DeviceOp = DeviceTsmm<ALayout,
                                BLayout,
                                CLayout,
                                ADataType,
                                BDataType,
                                CDataType,
                                ck::tensor_operation::element_wise::PassThrough,
                                ck::tensor_operation::element_wise::PassThrough,
                                ck::tensor_operation::element_wise::PassThrough>;

    static auto GetInstances()
    {
        std::vector<std::unique_ptr<DeviceOp>> op_ptrs;

        if constexpr(is_same_v<ADataType, half_t> && is_same_v<BDataType, half_t> &&
                     is_same_v<CDataType, half_t>)
        {
            if constexpr(is_same_v<ALayout, Row> && is_same_v<BLayout, Row> &&
                         is_same_v<CLayout, Row>)
            {
                add_device_tall_and_skinny_gemm_splitk_f16_f16_f16_mk_kn_mn_instances(op_ptrs);
            }
            else if constexpr(is_same_v<ALayout, Row> && is_same_v<BLayout, Col> &&
                              is_same_v<CLayout, Row>)
            {
                add_device_tall_and_skinny_gemm_splitk_f16_f16_f16_mk_nk_mn_instances(op_ptrs);
            }
        }

        return op_ptrs;
    }
};

} // namespace instance
} // namespace device
} // namespace tensor_operation
} // namespace ck
