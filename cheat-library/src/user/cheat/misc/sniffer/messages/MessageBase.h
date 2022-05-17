#pragma once
#include "MessageHeader.h"
class MessageBase : public PipeSerializedObject
{
public:
	explicit MessageBase(const MessageHeader& header);

	uint32_t requestID() const;
	uint32_t messageID() const;
	int64_t timestamp() const;
	uint64_t sequenceID() const;

	MessageHeader& header();
private:
	MessageHeader m_Header;
};

