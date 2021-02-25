/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "custom_dx12_struct_decoders_forward.h"
#include "custom_dx12_struct_decoders.h"
#include "generated/generated_dx12_struct_decoders_forward.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_CLEAR_VALUE* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t             bytes_read = 0;
    D3D12_CLEAR_VALUE* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));

    wrapper->Color.SetExternalMemory(value->Color, 4);
    bytes_read += wrapper->Color.DecodeFloat((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RESOURCE_BARRIER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                  bytes_read = 0;
    D3D12_RESOURCE_BARRIER* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    switch (value->Type)
    {
        case D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:
            wrapper->Transition                = DecodeAllocator::Allocate<Decoded_D3D12_RESOURCE_TRANSITION_BARRIER>();
            wrapper->Transition->decoded_value = &(value->Transition);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Transition);
            break;
        case D3D12_RESOURCE_BARRIER_TYPE_ALIASING:
            wrapper->Aliasing                = DecodeAllocator::Allocate<Decoded_D3D12_RESOURCE_ALIASING_BARRIER>();
            wrapper->Aliasing->decoded_value = &(value->Aliasing);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Aliasing);
            break;
        case D3D12_RESOURCE_BARRIER_TYPE_UAV:
            wrapper->UAV                = DecodeAllocator::Allocate<Decoded_D3D12_RESOURCE_UAV_BARRIER>();
            wrapper->UAV->decoded_value = &(value->UAV);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->UAV);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_TEXTURE_COPY_LOCATION* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                       bytes_read = 0;
    D3D12_TEXTURE_COPY_LOCATION* value      = wrapper->decoded_value;

    bytes_read += wrapper->pResource.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pResource = nullptr;
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));

    switch (value->Type)
    {
        case D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX:
            bytes_read += ValueDecoder::DecodeUInt32Value(
                (buffer + bytes_read), (buffer_size - bytes_read), &(value->SubresourceIndex));
            break;
        case D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT:
            wrapper->PlacedFootprint = DecodeAllocator::Allocate<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>();
            wrapper->PlacedFootprint->decoded_value = &(value->PlacedFootprint);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->PlacedFootprint);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                           bytes_read = 0;
    D3D12_SHADER_RESOURCE_VIEW_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewDimension));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->Shader4ComponentMapping));

    switch (value->ViewDimension)
    {
        case D3D12_SRV_DIMENSION_BUFFER:
            wrapper->Buffer                = DecodeAllocator::Allocate<Decoded_D3D12_BUFFER_SRV>();
            wrapper->Buffer->decoded_value = &(value->Buffer);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Buffer);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE1D:
            wrapper->Texture1D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_SRV>();
            wrapper->Texture1D->decoded_value = &(value->Texture1D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE1DARRAY:
            wrapper->Texture1DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_ARRAY_SRV>();
            wrapper->Texture1DArray->decoded_value = &(value->Texture1DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1DArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2D:
            wrapper->Texture2D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_SRV>();
            wrapper->Texture2D->decoded_value = &(value->Texture2D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DARRAY:
            wrapper->Texture2DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_ARRAY_SRV>();
            wrapper->Texture2DArray->decoded_value = &(value->Texture2DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMS:
            wrapper->Texture2DMS                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_SRV>();
            wrapper->Texture2DMS->decoded_value = &(value->Texture2DMS);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMS);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY:
            wrapper->Texture2DMSArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_ARRAY_SRV>();
            wrapper->Texture2DMSArray->decoded_value = &(value->Texture2DMSArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMSArray);
            break;
        case D3D12_SRV_DIMENSION_TEXTURE3D:
            wrapper->Texture3D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX3D_SRV>();
            wrapper->Texture3D->decoded_value = &(value->Texture3D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture3D);
            break;
        case D3D12_SRV_DIMENSION_TEXTURECUBE:
            wrapper->TextureCube                = DecodeAllocator::Allocate<Decoded_D3D12_TEXCUBE_SRV>();
            wrapper->TextureCube->decoded_value = &(value->TextureCube);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->TextureCube);
            break;
        case D3D12_SRV_DIMENSION_TEXTURECUBEARRAY:
            wrapper->TextureCubeArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEXCUBE_ARRAY_SRV>();
            wrapper->TextureCubeArray->decoded_value = &(value->TextureCubeArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->TextureCubeArray);
            break;
        case D3D12_SRV_DIMENSION_RAYTRACING_ACCELERATION_STRUCTURE:
            wrapper->RaytracingAccelerationStructure =
                DecodeAllocator::Allocate<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV>();
            wrapper->RaytracingAccelerationStructure->decoded_value = &(value->RaytracingAccelerationStructure);
            bytes_read += DecodeStruct(
                (buffer + bytes_read), (buffer_size - bytes_read), wrapper->RaytracingAccelerationStructure);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                            bytes_read = 0;
    D3D12_UNORDERED_ACCESS_VIEW_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewDimension));

    switch (value->ViewDimension)
    {
        case D3D12_UAV_DIMENSION_BUFFER:
            wrapper->Buffer                = DecodeAllocator::Allocate<Decoded_D3D12_BUFFER_UAV>();
            wrapper->Buffer->decoded_value = &(value->Buffer);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Buffer);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE1D:
            wrapper->Texture1D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_UAV>();
            wrapper->Texture1D->decoded_value = &(value->Texture1D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1D);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE1DARRAY:
            wrapper->Texture1DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_ARRAY_UAV>();
            wrapper->Texture1DArray->decoded_value = &(value->Texture1DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1DArray);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2D:
            wrapper->Texture2D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_UAV>();
            wrapper->Texture2D->decoded_value = &(value->Texture2D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2D);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE2DARRAY:
            wrapper->Texture2DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_ARRAY_UAV>();
            wrapper->Texture2DArray->decoded_value = &(value->Texture2DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DArray);
            break;
        case D3D12_UAV_DIMENSION_TEXTURE3D:
            wrapper->Texture3D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX3D_UAV>();
            wrapper->Texture3D->decoded_value = &(value->Texture3D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture3D);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_TARGET_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                         bytes_read = 0;
    D3D12_RENDER_TARGET_VIEW_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewDimension));

    switch (value->ViewDimension)
    {
        case D3D12_RTV_DIMENSION_BUFFER:
            wrapper->Buffer                = DecodeAllocator::Allocate<Decoded_D3D12_BUFFER_RTV>();
            wrapper->Buffer->decoded_value = &(value->Buffer);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Buffer);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE1D:
            wrapper->Texture1D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_RTV>();
            wrapper->Texture1D->decoded_value = &(value->Texture1D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1D);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE1DARRAY:
            wrapper->Texture1DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_ARRAY_RTV>();
            wrapper->Texture1DArray->decoded_value = &(value->Texture1DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1DArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2D:
            wrapper->Texture2D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_RTV>();
            wrapper->Texture2D->decoded_value = &(value->Texture2D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2D);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DARRAY:
            wrapper->Texture2DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_ARRAY_RTV>();
            wrapper->Texture2DArray->decoded_value = &(value->Texture2DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMS:
            wrapper->Texture2DMS                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_RTV>();
            wrapper->Texture2DMS->decoded_value = &(value->Texture2DMS);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMS);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY:
            wrapper->Texture2DMSArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_ARRAY_RTV>();
            wrapper->Texture2DMSArray->decoded_value = &(value->Texture2DMSArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMSArray);
            break;
        case D3D12_RTV_DIMENSION_TEXTURE3D:
            wrapper->Texture3D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX3D_RTV>();
            wrapper->Texture3D->decoded_value = &(value->Texture3D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture3D);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                         bytes_read = 0;
    D3D12_DEPTH_STENCIL_VIEW_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Format));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ViewDimension));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    switch (value->ViewDimension)
    {
        case D3D12_DSV_DIMENSION_TEXTURE1D:
            wrapper->Texture1D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_DSV>();
            wrapper->Texture1D->decoded_value = &(value->Texture1D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1D);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE1DARRAY:
            wrapper->Texture1DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX1D_ARRAY_DSV>();
            wrapper->Texture1DArray->decoded_value = &(value->Texture1DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture1DArray);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2D:
            wrapper->Texture2D                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_DSV>();
            wrapper->Texture2D->decoded_value = &(value->Texture2D);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2D);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DARRAY:
            wrapper->Texture2DArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2D_ARRAY_DSV>();
            wrapper->Texture2DArray->decoded_value = &(value->Texture2DArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DArray);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMS:
            wrapper->Texture2DMS                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_DSV>();
            wrapper->Texture2DMS->decoded_value = &(value->Texture2DMS);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMS);
            break;
        case D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY:
            wrapper->Texture2DMSArray                = DecodeAllocator::Allocate<Decoded_D3D12_TEX2DMS_ARRAY_DSV>();
            wrapper->Texture2DMSArray->decoded_value = &(value->Texture2DMSArray);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Texture2DMSArray);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_PARAMETER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                bytes_read = 0;
    D3D12_ROOT_PARAMETER* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ParameterType));

    switch (value->ParameterType)
    {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            wrapper->DescriptorTable                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_DESCRIPTOR_TABLE>();
            wrapper->DescriptorTable->decoded_value = &(value->DescriptorTable);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DescriptorTable);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            wrapper->Constants                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_CONSTANTS>();
            wrapper->Constants->decoded_value = &(value->Constants);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Constants);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV:
        case D3D12_ROOT_PARAMETER_TYPE_SRV:
        case D3D12_ROOT_PARAMETER_TYPE_UAV:
            wrapper->Descriptor                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_DESCRIPTOR>();
            wrapper->Descriptor->decoded_value = &(value->Descriptor);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Descriptor);
            break;
        default:
            break;
    }

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderVisibility));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_ROOT_PARAMETER1* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                 bytes_read = 0;
    D3D12_ROOT_PARAMETER1* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ParameterType));

    switch (value->ParameterType)
    {
        case D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE:
            wrapper->DescriptorTable                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1>();
            wrapper->DescriptorTable->decoded_value = &(value->DescriptorTable);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->DescriptorTable);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS:
            wrapper->Constants                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_CONSTANTS>();
            wrapper->Constants->decoded_value = &(value->Constants);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Constants);
            break;
        case D3D12_ROOT_PARAMETER_TYPE_CBV:
        case D3D12_ROOT_PARAMETER_TYPE_SRV:
        case D3D12_ROOT_PARAMETER_TYPE_UAV:
            wrapper->Descriptor                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_DESCRIPTOR1>();
            wrapper->Descriptor->decoded_value = &(value->Descriptor);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Descriptor);
            break;
        default:
            break;
    }

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->ShaderVisibility));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                               bytes_read = 0;
    D3D12_VERSIONED_ROOT_SIGNATURE_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Version));

    switch (value->Version)
    {
        case D3D_ROOT_SIGNATURE_VERSION_1_0:
            wrapper->Desc_1_0                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_SIGNATURE_DESC>();
            wrapper->Desc_1_0->decoded_value = &(value->Desc_1_0);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Desc_1_0);
            break;
        case D3D_ROOT_SIGNATURE_VERSION_1_1:
            wrapper->Desc_1_1                = DecodeAllocator::Allocate<Decoded_D3D12_ROOT_SIGNATURE_DESC1>();
            wrapper->Desc_1_1->decoded_value = &(value->Desc_1_1);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Desc_1_1);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_INDIRECT_ARGUMENT_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                        bytes_read = 0;
    D3D12_INDIRECT_ARGUMENT_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->Constant.RootParameterIndex));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->Constant.DestOffsetIn32BitValues));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->Constant.Num32BitValuesToSet));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RAYTRACING_GEOMETRY_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                          bytes_read = 0;
    D3D12_RAYTRACING_GEOMETRY_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));

    switch (value->Type)
    {
        case D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:
            wrapper->Triangles = DecodeAllocator::Allocate<Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC>();
            wrapper->Triangles->decoded_value = &(value->Triangles);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Triangles);
            break;
        case D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS:
            wrapper->AABBs                = DecodeAllocator::Allocate<Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC>();
            wrapper->AABBs->decoded_value = &(value->AABBs);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->AABBs);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                                bytes_read = 0;
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Flags));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->NumDescs));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->DescsLayout));

    switch (value->Type)
    {
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL:
            bytes_read += ValueDecoder::DecodeUInt64Value(
                (buffer + bytes_read), (buffer_size - bytes_read), &(value->InstanceDescs));
            break;
        case D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL:
            switch (value->DescsLayout)
            {
                case D3D12_ELEMENTS_LAYOUT_ARRAY:
                    wrapper->pGeometryDescs =
                        DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RAYTRACING_GEOMETRY_DESC>>();
                    bytes_read += wrapper->pGeometryDescs->Decode((buffer + bytes_read), (buffer_size - bytes_read));
                    value->pGeometryDescs = wrapper->pGeometryDescs->GetPointer();
                    break;
                case D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS:
                    wrapper->ppGeometryDescs =
                        DecodeAllocator::Allocate<StructPointerDecoder<Decoded_D3D12_RAYTRACING_GEOMETRY_DESC*>>();
                    bytes_read += wrapper->ppGeometryDescs->Decode((buffer + bytes_read), (buffer_size - bytes_read));
                    value->ppGeometryDescs = wrapper->ppGeometryDescs->GetPointer();
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                        bytes_read = 0;
    D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Version));

    switch (value->Version)
    {
        case D3D12_DRED_VERSION_1_0:
            wrapper->Dred_1_0                = DecodeAllocator::Allocate<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA>();
            wrapper->Dred_1_0->decoded_value = &(value->Dred_1_0);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Dred_1_0);
            break;
        case D3D12_DRED_VERSION_1_1:
            wrapper->Dred_1_1                = DecodeAllocator::Allocate<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1>();
            wrapper->Dred_1_1->decoded_value = &(value->Dred_1_1);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Dred_1_1);
            break;
        case D3D12_DRED_VERSION_1_2:
            wrapper->Dred_1_2                = DecodeAllocator::Allocate<Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2>();
            wrapper->Dred_1_2->decoded_value = &(value->Dred_1_2);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Dred_1_2);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                              bytes_read = 0;
    D3D12_RENDER_PASS_BEGINNING_ACCESS* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));

    wrapper->Clear = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS>();
    wrapper->Clear->decoded_value = &(value->Clear);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Clear);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_RENDER_PASS_ENDING_ACCESS* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                           bytes_read = 0;
    D3D12_RENDER_PASS_ENDING_ACCESS* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->Type));

    wrapper->Resolve = DecodeAllocator::Allocate<Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS>();
    wrapper->Resolve->decoded_value = &(value->Resolve);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->Resolve);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_LARGE_INTEGER* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t         bytes_read = 0;
    LARGE_INTEGER* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->QuadPart));

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)