// © 2026 NVIDIA Corporation

#pragma once

DeviceMTL::DeviceMTL(const CallbackInterface& callbacks, const AllocationCallbacks& allocationCallbacks)
    : DeviceBase(callbacks, allocationCallbacks) {

    m_Desc.graphicsAPI = GraphicsAPI::MTL;
    m_Desc.nriVersion  = NRI_VERSTION;

}

DeviceMTL::~DeviceMTL() {
    if (m_Device)
        m_Device->release();

    if (m_ResidencySet)
        m_ResidencySet->release();
}

Result DeviceMTL::Create(const DeviceCreationDesc& desc) {

    if (!m_Device)
        m_Device = MTL::CreateSystemDefaultDevice();

    if (m_Device) {
        std::cout << "Metal-compatible device initialised";
    }

    // Initialise ResidencySet Descriptor
    MTL::ResidencySetDescriptor* residencySetDescriptor = MTL::ResidencySetDescriptor::alloc()->init();

    NS::Error* residencyError = nullptr;
    m_ResidencySet = m_Device->newResidencySet(residencySetDescriptor, &residencyError);
    residencySetDescriptor->release();

    m_ResidencySet->requestResidency();
}

DeviceMTL::AddToResidencySet(const MTL::Allocation* allocation) {
    m_ResidencySet->addAllocation(allocation);
}

DeviceMTL::RemoveFromResidencySet(const MTL::Allocation* allocation) {
    m_ResidencySet->removeAllocation(allocation);
}

DeviceMTL::CommitResidencySet() {
    m_ResidencySet->commit();
}
