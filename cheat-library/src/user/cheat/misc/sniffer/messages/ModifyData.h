#pragma once
#include <cheat-base/PipeTransfer.h>
#include "MessageBase.h"

enum class PacketModifyType 
{
	Unchanged,
	Modified,
	Blocked
};

class ModifyData : public MessageBase
{
public:
	PacketModifyType modify_type;

	uint16_t message_id;
	std::string modified_head;
	std::string modified_message;

	ModifyData(const MessageHeader& header);
	~ModifyData() {}

	// Inherited via PipeSerializedObject
	void Write(PipeTransfer* transfer) override;
	void Read(PipeTransfer* transfer) override;
};

