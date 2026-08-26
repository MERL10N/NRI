//
// Created by Kian Marvi on 8/26/26.
//

#ifndef NRI_DEVICEMTL_HPP
#define NRI_DEVICEMTL_HPP

DeviceMTL::DeviceMTL(const CallbackInterface& callbacks, const AllocationCallbacks& allocationCallbacks)
    : DeviceBase(callbacks, allocationCallbacks) {

    m_Desc.graphicsAPI = GraphicsAPI::MTL;
    m_Desc.nriVersion  = NRI_VERSTION;

    m_Device = MTL::CreateSystemDefaultDevice();

    if (m_Device) {
        std::cout << "Metal-compatible device initialised";
    }

}


#endif // NRI_DEVICEMTL_HPP
