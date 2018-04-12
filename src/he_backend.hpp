/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#pragma once

#include <map>
#include <memory>

#include "ngraph/runtime/backend.hpp"

namespace ngraph
{
    namespace runtime
    {
        class CallFrame;

        namespace he
        {
            class ExternalFunction;
            class HECallFrame;

            class HEBackend : public runtime::Backend
            {
            public:
                std::shared_ptr<runtime::CallFrame> make_call_frame(
                    const std::shared_ptr<runtime::ExternalFunction>& external_function) override;

                std::shared_ptr<runtime::TensorView>
                    make_primary_tensor_view(const element::Type& element_type,
                                             const Shape& shape) override;

                std::shared_ptr<runtime::TensorView>
                    make_primary_tensor_view(const element::Type& element_type,
                                             const Shape& shape,
                                             void* memory_pointer) override;

                std::shared_ptr<runtime::TensorView>
                    create_tensor(const element::Type& element_type, const Shape& shape) override;

                bool compile(const Function& fun) override;

                bool call(const std::vector<std::shared_ptr<runtime::TensorView>>& outputs,
                          const std::vector<std::shared_ptr<runtime::TensorView>>& inputs) override;

                bool call(const Function& fun,
                          const std::vector<std::shared_ptr<runtime::TensorView>>& outputs,
                          const std::vector<std::shared_ptr<runtime::TensorView>>& inputs) override;

                void remove_compiled_function(const Function& func) override;
            };
        }
    }
}