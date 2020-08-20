// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/*!
 * @file test.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "test.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>



I_Kit_Logging::I_Kit_Logging()
{
    // m_A_payload com.eprosima.idl.parser.typecode.AliasTypeCode@517cd4b


}

I_Kit_Logging::~I_Kit_Logging()
{
}

I_Kit_Logging::I_Kit_Logging(const I_Kit_Logging &x)
{
    m_A_payload = x.m_A_payload;
}

I_Kit_Logging::I_Kit_Logging(I_Kit_Logging &&x)
{
    m_A_payload = std::move(x.m_A_payload);
}

I_Kit_Logging& I_Kit_Logging::operator=(const I_Kit_Logging &x)
{

    m_A_payload = x.m_A_payload;

    return *this;
}

I_Kit_Logging& I_Kit_Logging::operator=(I_Kit_Logging &&x)
{

    m_A_payload = std::move(x.m_A_payload);

    return *this;
}

size_t I_Kit_Logging::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    current_alignment += (100 * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t I_Kit_Logging::getCdrSerializedSize(const I_Kit_Logging& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.A_payload().size() > 0)
    {
        current_alignment += (data.A_payload().size() * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }



    return current_alignment - initial_alignment;
}

void I_Kit_Logging::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_A_payload;}

void I_Kit_Logging::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_A_payload;}

/*!
 * @brief This function copies the value in member A_payload
 * @param _A_payload New value to be copied in member A_payload
 */
void I_Kit_Logging::A_payload(const T_Payload &_A_payload)
{
m_A_payload = _A_payload;
}

/*!
 * @brief This function moves the value in member A_payload
 * @param _A_payload New value to be moved in member A_payload
 */
void I_Kit_Logging::A_payload(T_Payload &&_A_payload)
{
m_A_payload = std::move(_A_payload);
}

/*!
 * @brief This function returns a constant reference to member A_payload
 * @return Constant reference to member A_payload
 */
const T_Payload& I_Kit_Logging::A_payload() const
{
    return m_A_payload;
}

/*!
 * @brief This function returns a reference to member A_payload
 * @return Reference to member A_payload
 */
T_Payload& I_Kit_Logging::A_payload()
{
    return m_A_payload;
}

size_t I_Kit_Logging::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;



    return current_align;
}

bool I_Kit_Logging::isKeyDefined()
{
   return false;
}

void I_Kit_Logging::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
}