#include "pch-il2cpp.h"
#include "MessageBase.h"

MessageBase::MessageBase(const MessageHeader& header) : m_Header(header)
{

}

uint32_t MessageBase::requestID() const
{
	return m_Header.requestID();
}

uint32_t MessageBase::messageID() const
{
	return m_Header.messageID();
}

int64_t MessageBase::timestamp() const
{
	return m_Header.timestamp();
}

uint64_t MessageBase::sequenceID() const
{
	return m_Header.sequenceID();
}

MessageHeader& MessageBase::header()
{
	return m_Header;
}
