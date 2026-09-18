// © 2026 NVIDIA Corporation
#pragma once

BufferMTL::~BufferMTL() {

    if (m_Buffer) {
        m_Device.RemoveFromResidencySet(m_Buffer);
        m_Buffer->release();
    }
}

Result BufferMTL::Create(MemoryLocation location, const BufferDesc& bufferDesc) {

    m_Desc = bufferDesc;

    m_Buffer = m_Device.GetDevice()->newBuffer(bufferDesc.size, GetResourceOptions(location));

    m_Device.AddToResidencySet(m_Buffer);

    return Result::SUCCESS;
}
