//
// Created by Kian Marvi on 9/15/26.
//

#pragma once

namespace nri {
    struct BufferMTL;
    struct CommandAllocatorMTL;
    struct CommandBufferMTL;
    struct DeviceMTL;
    struct SwapChainMTL;

    MTL::PixelFormat GetPixelFormat(Format format);
    Format GetNRIFormat(MTL::PixelFormat format);
    MTL::PixelFormat GetSwapChainPixelFormat(SwapChainFormat format);
    MTL::VertexFormat GetVertexFormat(Format format);
    MTL::LoadAction GetLoadAction();
    MTL::CullMode GetCullMode(CullMode cullMode);
    FormatSupportBits GetFormatSupportMTL(Format format);
}
