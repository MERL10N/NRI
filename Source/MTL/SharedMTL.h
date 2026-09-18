// © 2026  NVIDIA Corporation

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
    MTL::WindingO GetWindingOrder(bool frontCounterClockwise);
    FormatSupportBits GetFormatSupportMTL(Format format);
    MTL::TextureType  GetTextureType(TextureType type, uint32_t sampleNum);
    MTL::StorageMode  GetStorageMode(MemoryLocation location);
}
