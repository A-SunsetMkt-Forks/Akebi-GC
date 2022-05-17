#include <pch-il2cpp.h>
#include "MessageHeader.h"


MessageHeader::MessageHeader(uint32_t messageId, uint32_t requestID /*= 0*/) : 
	m_MessageID(messageId), m_RequestID(requestID), 
	m_SequenceID(GenerateSequenceID()), m_Timestamp(util::GetCurrentTimeMillisec())
{ }

MessageHeader::MessageHeader() : m_MessageID(0), m_RequestID(0), m_SequenceID(0), m_Timestamp(0)
{ }

uint32_t MessageHeader::requestID() const
{
	return m_RequestID;
}

uint32_t MessageHeader::messageID() const
{
	return m_MessageID;
}

int64_t MessageHeader::timestamp() const
{
	return m_Timestamp;
}

uint64_t MessageHeader::sequenceID() const
{
	return m_SequenceID;
}

void MessageHeader::Write(PipeTransfer* transfer)
{
	transfer->Write(m_MessageID);
	transfer->Write(m_RequestID);
	transfer->Write(util::GetCurrentTimeMillisec());
	transfer->Write(m_SequenceID);
}

void MessageHeader::Read(PipeTransfer* transfer)
{
	transfer->Read(m_MessageID);
	transfer->Read(m_RequestID);
	transfer->Read(m_Timestamp);
	transfer->Read(m_SequenceID);
}

uint64_t MessageHeader::GenerateSequenceID()
{
	s_SequenceGlobalID += 1;
	return s_SequenceGlobalID;
}
