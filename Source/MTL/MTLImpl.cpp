// © 2026  NVIDIA Corporation

#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

#include "SharedExternal.h"
#include "HelperInterface.h"
#include "StreamerInterface.h"


#include "DeviceMTL.h"
#include "CommandAllocatorMTL.h"
#include "CommandBufferMTL.h"

using namespace nri;

Result CreateDeviceMTL(const DeviceCreationDesc& desc, DeviceBase*& device) {

    DeviceMTL* impl = Allocate<DeviceMTL>(desc.allocationCallbacks, desc.callbackInterface, desc.allocationCallbacks);
    if (!impl)
        return Result::OUT_OF_MEMORY;

    Result result = impl->Create(desc);

    if (result != Result::SUCCESS) {
        Destroy(desc.allocationCallbacks, impl);
        device = nullptr;
    } else
        device = (DeviceBase*)impl;

    return result;

}