// © 2026 NVIDIA Corporation

#pragma once

namespace nri {

constexpr uint32_t VIDEO_ENCODE_RATE_CONTROL_CQP = 1u << (uint32_t)VideoEncodeRateControlMode::CQP;
constexpr uint32_t VIDEO_ENCODE_RATE_CONTROL_CBR = 1u << (uint32_t)VideoEncodeRateControlMode::CBR;
constexpr uint32_t VIDEO_ENCODE_RATE_CONTROL_VBR = 1u << (uint32_t)VideoEncodeRateControlMode::VBR;

inline uint32_t GetVideoEncodeRateControlModeMask(VideoEncodeRateControlMode mode) {
    return 1u << (uint32_t)mode;
}

template <typename T>
inline const T* FindVideoReferenceDesc(const T* references, uint32_t referenceNum, uint32_t slot) {
    if (!references)
        return nullptr;

    for (uint32_t i = 0; i < referenceNum; i++) {
        if (references[i].slot == slot)
            return &references[i];
    }

    return nullptr;
}

inline uint32_t GetVideoDecodeSetupSlot(const VideoDecodeDesc& desc) {
    const VideoH264DecodePictureDesc* h264PictureDesc = desc.h264PictureDesc;

    if (h264PictureDesc && h264PictureDesc->hasReferenceSlot)
        return h264PictureDesc->referenceSlot;

    return desc.dstSlot;
}

} // namespace nri
