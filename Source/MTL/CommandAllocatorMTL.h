// © 2026 NVIDIA Corporation

#pragma once

namespace nri {

struct CommandAllocatorMTL final : public DebugNameBase {
    inline CommandAllocatorMTL(DeviceMTL &device)
        : m_Device(device){
    }

     ~CommandAllocatorMTL();

    inline operator MTL4::CommandAllocator*() const
    {
        return m_CommandAllocator;
    }

    inline DeviceMTL& GetDevice() const {
        return m_Device;
    }

    void Reset();

    Result Create(const Queue& queue);

private:
    DeviceMTL& m_Device;
    MTL4::CommandAllocator* m_CommandAllocator = nullptr;
};

}
