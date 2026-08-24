// © 2026 NVIDIA Corporation

NRI_INLINE VideoSessionParametersVal::VideoSessionParametersVal(DeviceVal& device, VideoSessionParameters* impl, VideoSessionVal& session, const VideoSessionParametersDesc& desc)
    : ObjectVal(device, (Object*)impl)
    , m_Session(session) {
    if (!desc.h264Parameters)
        return;

    for (uint32_t i = 0; i < desc.h264Parameters->sequenceParameterSetNum; i++)
        m_H264SequenceParameterSetMask |= 1u << desc.h264Parameters->sequenceParameterSets[i].sequenceParameterSetId;

    for (uint32_t i = 0; i < desc.h264Parameters->pictureParameterSetNum; i++) {
        const VideoH264PictureParameterSetDesc& pictureParameterSet = desc.h264Parameters->pictureParameterSets[i];
        m_H264PictureParameterSetMasks[pictureParameterSet.pictureParameterSetId / 64] |= 1ull << (pictureParameterSet.pictureParameterSetId % 64);
        m_H264PictureParameterSetToSequence[pictureParameterSet.pictureParameterSetId] = pictureParameterSet.sequenceParameterSetId;
    }
}

NRI_INLINE VideoSessionParameters* VideoSessionParametersVal::GetImpl() const {
    return (VideoSessionParameters*)m_Impl;
}

NRI_INLINE VideoSessionVal& VideoSessionParametersVal::GetSession() const {
    return m_Session;
}

NRI_INLINE bool VideoSessionParametersVal::IsH264ParameterSetValid(uint8_t sequenceParameterSetId, uint8_t pictureParameterSetId) const {
    if (sequenceParameterSetId >= 32)
        return false;

    const bool hasSequenceParameterSet = (m_H264SequenceParameterSetMask & (1u << sequenceParameterSetId)) != 0;
    const bool hasPictureParameterSet = (m_H264PictureParameterSetMasks[pictureParameterSetId / 64] & (1ull << (pictureParameterSetId % 64))) != 0;

    return hasSequenceParameterSet && hasPictureParameterSet && m_H264PictureParameterSetToSequence[pictureParameterSetId] == sequenceParameterSetId;
}
