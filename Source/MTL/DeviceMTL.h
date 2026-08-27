// © 2026 NVIDIA Corporation
#ifndef NRI_DEVICEMTL_H
#define NRI_DEVICEMTL_H
namespace nri {
 struct DeviceMTL : public DeviceBase {
     DeviceMTL(const CallbackInterface& callbacks, const AllocationCallbacks& allocationCallbacks);
     ~DeviceMTL();

     inline MTL::Device* GetDevice() const {
         return m_Device;
     }

 private:
     MTL::Device* m_Device = nullptr;
 };
}
#endif // NRI_DEVICEMTL_H
