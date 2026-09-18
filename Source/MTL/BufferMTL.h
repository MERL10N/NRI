// © 2026 NVIDIA Corporation

#pragma once

namespace nri {
    struct BufferMTL final : public DebugNameBase {

        inline BufferMTL(DeviceMTL& device)
            : m_Device(device) {
        }

        ~BufferMTL();

        inline DeviceMTL& GetDevice() {
            return m_Device;
        }

        inline const BufferDesc& GetDesc() const {
            return m_Desc;
        }

        Result Create(MemoryLocation location, const BufferDesc& bufferDesc);

    private:
        DeviceMTL& m_Device;
        MTL::Buffer* m_Buffer = nullptr;
        BufferDesc m_Desc = {};
    };
}
