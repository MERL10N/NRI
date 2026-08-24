// © 2026 NVIDIA Corporation

#pragma once

namespace nri {

struct VideoSessionParametersVal final : public ObjectVal {
    VideoSessionParametersVal(DeviceVal& device, VideoSessionParameters* impl, VideoSessionVal& session, const VideoSessionParametersDesc& desc);

    VideoSessionParameters* GetImpl() const;
    VideoSessionVal& GetSession() const;
    bool IsH264ParameterSetValid(uint8_t sequenceParameterSetId, uint8_t pictureParameterSetId) const;

private:
    VideoSessionVal& m_Session;
    uint32_t m_H264SequenceParameterSetMask = 0;
    std::array<uint64_t, 4> m_H264PictureParameterSetMasks = {};
    std::array<uint8_t, 256> m_H264PictureParameterSetToSequence = {};
};
} // namespace nri
