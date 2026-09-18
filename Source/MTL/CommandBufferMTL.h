// © 2026 NVIDIA Corporation

#pragma once

namespace nri {

    enum class EncoderTypeMTL {
        NONE,
        RENDER,
        COMPUTE,
    };
    struct CommandBufferMTL final : public DebugNameBase {
        inline CommandBufferMTL(DeviceMTL& device)
            : m_Device(device) {

        }

        inline ~CommandBufferMTL() {

        }

    //================================================================================================================
    // NRI
    //================================================================================================================

        Result Create(const CommandAllocator& commandAllocator);

        Result Begin(const DescriptorPool* descriptorPool);
        Result End();

        void SetViewports(const Viewport* viewports, uint32_t viewportNum);
        void SetScissors(const Rect* rects, uint32_t rectNum);
        void SetPipelineLayout(BindPoint bindPoint, const PipelineLayout& pipelineLayout);
        void SetPipeline(const Pipeline& pipeline);
        void SetDescriptorSet(const SetDescriptorSetDesc& setDescriptorSetDesc);
        void SetRootConstants(const SetRootConstantsDesc& setRootConstantsDesc);
        void SetRootDescriptor(const SetRootDescriptorDesc& setRootDescriptorDesc);
        void SetVertexBuffers(uint32_t baseSlot, const VertexBufferDesc* vertexBufferDescs, uint32_t vertexBufferNum);
        void SetIndexBuffer(const Buffer& buffer, uint64_t offset, IndexType indexType);
        void SetStencilReference(uint8_t frontRef, uint8_t backRef);
        void SetBlendConstants(const Color32f& color);
        void BeginRendering(const RenderingDesc& renderingDesc);
        void EndRendering();
        void ClearAttachments(const ClearAttachmentDesc* clearAttachmentDescs, uint32_t clearAttachmentDescNum, const Rect* rects, uint32_t rectNum);
        void Draw(const DrawDesc& drawDesc);
        void DrawIndexed(const DrawIndexedDesc& drawIndexedDesc);
        void DrawIndirect(const Buffer& buffer, uint64_t offset, uint32_t drawNum, uint32_t stride, const Buffer* countBuffer, uint64_t countBufferOffset);
        void DrawIndexedIndirect(const Buffer& buffer, uint64_t offset, uint32_t drawNum, uint32_t stride, const Buffer* countBuffer, uint64_t countBufferOffset);
        void Dispatch(const DispatchDesc& dispatchDesc);
        void DispatchIndirect(const Buffer& buffer, uint64_t offset);
        void CopyBuffer(Buffer& dstBuffer, uint64_t dstOffset, const Buffer& srcBuffer, uint64_t srcOffset, uint64_t size);
        void CopyTexture(Texture& dstTexture, const TextureRegionDesc* dstRegion, const Texture& srcTexture, const TextureRegionDesc* srcRegion);
        void UploadBufferToTexture(Texture& dstTexture, const TextureRegionDesc& dstRegion, const Buffer& srcBuffer, const TextureDataLayoutDesc& srcDataLayout);
        void ReadbackTextureToBuffer(Buffer& dstBuffer, const TextureDataLayoutDesc& dstDataLayout, const Texture& srcTexture, const TextureRegionDesc& srcRegion);
        void ZeroBuffer(Buffer& buffer, uint64_t offset, uint64_t size);
        void ResolveTexture(Texture& dstTexture, const TextureRegionDesc* dstRegion, const Texture& srcTexture, const TextureRegionDesc* srcRegion, ResolveOp resolveOp);
        void ClearStorage(const ClearStorageDesc& clearStorageDesc);
        void Barrier(const BarrierDesc& barrierDesc);
        void ResetQueries(QueryPool& queryPool, uint32_t offset, uint32_t num);
        void BeginQuery(QueryPool& queryPool, uint32_t offset);
        void EndQuery(QueryPool& queryPool, uint32_t offset);
        void CopyQueries(const QueryPool& queryPool, uint32_t offset, uint32_t num, Buffer& dstBuffer, uint64_t dstOffset);
        void BeginAnnotation(const char* name, uint32_t bgra);
        void EndAnnotation();
        void Annotation(const char* name, uint32_t bgra);

    private:
        DeviceMTL& m_Device;
        MTL4::CommandAllocator* m_CommandAllocator;

        EncoderTypeMTL m_EncoderType = EncoderTypeMTL::NONE;
    };
}

