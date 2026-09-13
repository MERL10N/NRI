// © 2026 NVIDIA Corporation



CommandAllocatorMTL::~CommandAllocatorMTL() {
    if (m_CommandAllocator) {
        m_CommandAllocator->release();
    }
}

Result CommandAllocatorMTL::Create(const Queue& queue) {

    m_Allocator = m_Device.GetDevice()->newCommandAllocator();
    return m_Allocator ? Result::SUCCESS : Result::FAILURE;
}

void CommandAllocatorMTL::Reset() {

    if (m_Allocator) {
        m_Allocator->reset();
    }
}