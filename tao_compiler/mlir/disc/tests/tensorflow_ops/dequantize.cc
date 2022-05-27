/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/compiler/mlir/disc/tests/mlir_feature_test.h"
#include "tensorflow/compiler/mlir/disc/tests/mlir_test.h"
#include "tensorflow/core/platform/test.h"

namespace mlir_test {

const std::string c_ft_path =
    "tensorflow/compiler/mlir/disc/tests/tensorflow_ops/data/";

// Static shape
TEST(TFDequantizeTest, INT8_CHANNEL_SCALED_StaticShape) {
  int num_elements = 2 * 3 * 4 * 5;
  std::vector<float> values = {-127, -128, 127, 0, 1, 3, 12, -34};
  std::vector<float> data(num_elements, 0);
  for (int i = 0; i < num_elements; ++i) data[i] = values[i % values.size()];
  EXPECT_TRUE(feature_test_main(
      /*mlir_file_path*/ c_ft_path + "dequantize_s_int8_channel_scaled.mlir",
      /*backend_types*/
      kSupportedCPUBackendList,
      /*num_inputs*/ 3,
      /*num_outputs*/ 1,
      /*input_descriptors*/ {"2x3x4x5xqi8_X", "3xf32_X", "3xf32_X"},
      /*output_descriptors*/ {"f32_X"},
      /*input_vals*/
      {data,
       {-255.0, -255.0 * 0.2, -255.0 * 0.3},
       {127.0, 127.0 * 0.2, 127.0 * 0.3}}));
}

// Partial dynamic shape
TEST(TFDequantizeTest, INT8_CHANNEL_SCALED_PartialDynamicShape) {
  int num_elements = 2 * 3 * 4 * 5;
  std::vector<float> values = {-127, -128, 127, 0, 1, 3, 12, -34};
  std::vector<float> data(num_elements, 0);
  for (int i = 0; i < num_elements; ++i) data[i] = values[i % values.size()];
  EXPECT_TRUE(feature_test_main(
      /*mlir_file_path*/ c_ft_path + "dequantize_p_int8_channel_scaled.mlir",
      /*backend_types*/
      kSupportedCPUBackendList,
      /*num_inputs*/ 3,
      /*num_outputs*/ 1,
      /*input_descriptors*/ {"2x3x4x5xqi8_X", "3xf32_X", "3xf32_X"},
      /*output_descriptors*/ {"f32_X"},
      /*input_vals*/
      {data,
       {-255.0, -255.0 * 0.2, -255.0 * 0.3},
       {127.0, 127.0 * 0.2, 127.0 * 0.3}}));
}

// Dynamic shape
TEST(TFDequantizeTest, INT8_CHANNEL_SCALED_DynamicShape) {
  int num_elements = 2 * 3 * 4 * 5;
  std::vector<float> values = {-127, -128, 127, 0, 1, 3, 12, -34};
  std::vector<float> data(num_elements, 0);
  for (int i = 0; i < num_elements; ++i) data[i] = values[i % values.size()];
  EXPECT_TRUE(feature_test_main(
      /*mlir_file_path*/ c_ft_path + "dequantize_d_int8_channel_scaled.mlir",
      /*backend_types*/
      kSupportedCPUBackendList,
      /*num_inputs*/ 3,
      /*num_outputs*/ 1,
      /*input_descriptors*/ {"2x3x4x5xqi8_X", "3xf32_X", "3xf32_X"},
      /*output_descriptors*/ {"f32_X"},
      /*input_vals*/
      {data,
       {-255.0, -255.0 * 0.2, -255.0 * 0.3},
       {127.0, 127.0 * 0.2, 127.0 * 0.3}}));
}

// Static shape
TEST(TFDequantizeTest, INT8_SCALAR_SCALED_StaticShape) {
  int num_elements = 2 * 3 * 4 * 5;
  std::vector<float> values = {-127, -128, 127, 0, 1, 3, 12, -34};
  std::vector<float> data(num_elements, 0);
  for (int i = 0; i < num_elements; ++i) data[i] = values[i % values.size()];
  EXPECT_TRUE(feature_test_main(
      /*mlir_file_path*/ c_ft_path + "dequantize_s_int8_scalar_scaled.mlir",
      /*backend_types*/
      kSupportedCPUBackendList,
      /*num_inputs*/ 3,
      /*num_outputs*/ 1,
      /*input_descriptors*/ {"2x3x4x5xqi8_X", "f32_X", "f32_X"},
      /*output_descriptors*/ {"f32_X"},
      /*input_vals*/ {data, {-255.0}, {127.0}}));
}

// Partial dynamic shape
TEST(TFDequantizeTest, INT8_SCALAR_SCALED_PartialDynamicShape) {
  int num_elements = 2 * 3 * 4 * 5;
  std::vector<float> values = {-127, -128, 127, 0, 1, 3, 12, -34};
  std::vector<float> data(num_elements, 0);
  for (int i = 0; i < num_elements; ++i) data[i] = values[i % values.size()];
  EXPECT_TRUE(feature_test_main(
      /*mlir_file_path*/ c_ft_path + "dequantize_p_int8_scalar_scaled.mlir",
      /*backend_types*/
      kSupportedCPUBackendList,
      /*num_inputs*/ 3,
      /*num_outputs*/ 1,
      /*input_descriptors*/ {"2x3x4x5xqi8_X", "f32_X", "f32_X"},
      /*output_descriptors*/ {"f32_X"},
      /*input_vals*/ {data, {-255.0}, {127.0}}));
}

// Dynamic shape
TEST(TFDequantizeTest, INT8_SCALAR_SCALED_DynamicShape) {
  int num_elements = 2 * 3 * 4 * 5;
  std::vector<float> values = {-127, -128, 127, 0, 1, 3, 12, -34};
  std::vector<float> data(num_elements, 0);
  for (int i = 0; i < num_elements; ++i) data[i] = values[i % values.size()];
  EXPECT_TRUE(feature_test_main(
      /*mlir_file_path*/ c_ft_path + "dequantize_d_int8_scalar_scaled.mlir",
      /*backend_types*/
      kSupportedCPUBackendList,
      /*num_inputs*/ 3,
      /*num_outputs*/ 1,
      /*input_descriptors*/ {"2x3x4x5xqi8_X", "f32_X", "f32_X"},
      /*output_descriptors*/ {"f32_X"},
      /*input_vals*/ {data, {-255.0}, {127.0}}));
}

}  // namespace mlir_test
