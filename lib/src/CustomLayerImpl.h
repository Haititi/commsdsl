//
// Copyright 2018 - 2019 (C). Alex Robenko. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "LayerImpl.h"

namespace commsdsl
{

class CustomLayerImpl : public LayerImpl
{
    using Base = LayerImpl;
public:
    CustomLayerImpl(::xmlNodePtr node, ProtocolImpl& protocol);

    bool isIdReplacement() const
    {
        return m_idReplacement;
    }

protected:
    virtual Kind kindImpl() const override final;
    virtual bool parseImpl() override final;
    virtual const XmlWrap::NamesList& extraPropsNamesImpl() const override final;

private:
    bool m_idReplacement = false;
};

} // namespace commsdsl
