#pragma once
#include <cheat-base/PipeTransfer.h>

class MessageHeader : public PipeSerializedObject
{
public:
	MessageHeader();
	MessageHeader(uint32_t messageId, uint32_t requestID = 0);
	uint32_t requestID() const;
	uint32_t messageID() const;
	int64_t timestamp() const;
	uint64_t sequenceID() const;

	void Write(PipeTransfer* transfer) final;
	void Read(PipeTransfer* transfer) final;

private:
	inline static std::atomic<uint64_t> s_SequenceGlobalID {};
	static uint64_t GenerateSequenceID();

	uint32_t m_MessageID;
	uint32_t m_RequestID;
	int64_t m_Timestamp;
	int64_t m_SequenceID;
};