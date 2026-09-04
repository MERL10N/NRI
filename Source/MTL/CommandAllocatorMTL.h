// © 2026 NVIDIA Corporation

#pragma once

namespace nri {

struct CommandAllocatorMTL final : public DeviceBase {
    inline CommandAllocatorMTL(DeviceMTL &device)
        : m_Device(device) {

    }

private:
    DeviceMTL& m_Device;
};

}
