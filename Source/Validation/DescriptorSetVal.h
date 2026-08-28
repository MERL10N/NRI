// © 2021 NVIDIA Corporation

#pragma once

namespace nri {

struct DescriptorSetVal final : public ObjectVal {
    DescriptorSetVal(DeviceVal& device)
        : ObjectVal(device) {
    }

    inline DescriptorSet* GetImpl() const {
        return (DescriptorSet*)m_Impl;
    }

    inline const DescriptorSetDesc& GetDesc() const {
        return *m_Desc;
    }

    inline bool IsCopySource() const {
        return m_IsCopySource;
    }

    void SetImpl(DescriptorSet* impl, const DescriptorSetDesc* desc, bool isCopySource);

    //================================================================================================================
    // NRI
    //================================================================================================================

    void GetOffsets(uint32_t& resourceHeapOffset, uint32_t& samplerHeapOffset) const;

private:
    const DescriptorSetDesc* m_Desc = nullptr; // .natvis
    bool m_IsCopySource = false;
};

} // namespace nri
