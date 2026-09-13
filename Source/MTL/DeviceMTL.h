// © 2026 NVIDIA Corporation
#pragma once

namespace nri {
 struct DeviceMTL : public DeviceBase {
     DeviceMTL(const CallbackInterface& callbacks, const AllocationCallbacks& allocationCallbacks);
     ~DeviceMTL();

     inline MTL::Device* GetDevice() const {
         return m_Device;
     }

     inline MTL::ResidencySet* GetResidencySet() const {
         return m_ResidencySet;
     }

     inline const DeviceDesc& GetDesc() const override {
         return m_Desc;
     }

     void AddToResidencySet(MTL::Allocation* allocation);
     void RemoveFromResidencySet(MTL::Allocation* allocation);
     void CommitResidencySet();

     Result Create(const DeviceCreationDesc& desc);

     void Destruct() override {

     }

 private:
     DeviceDesc& m_Desc;
     MTL::Device* m_Device = nullptr;
     MTL::ResidencySet* m_ResidencySet = nullptr;
 };
}
