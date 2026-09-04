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

     inline MTL::Device* GetResidencySet() const {
         return m_ResidencySet;
     }

     void AddToResidencySet(MTL::Allocation* allocation);
     void RemoveFromResidencySet(MTL::Allocation* allocation);
     void CommitResidencySet();

     Result Create(const CallbackInterface& callbacks);

 private:
     MTL::Device* m_Device = nullptr;
     MTL::ResidencySet m_ResidencySet = nullptr;
 };
}
#endif // NRI_DEVICEMTL_H
