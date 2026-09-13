// © 2026 NVIDIA Corporation

#pragma once

namespace nri {
    struct CommandBufferMTL final : public DeviceBase {

        inline const DeviceDesc& GetDesc() const override {
            return m_Desc;
        }

        void Destruct() override {}

    private:

        DeviceDesc m_Desc = {};
    };
}

