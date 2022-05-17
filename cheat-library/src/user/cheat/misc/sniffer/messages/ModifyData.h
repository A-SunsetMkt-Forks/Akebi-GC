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
	PacketModifyType modifyType;
	std::string modifiedData;

	ModifyData(const MessageHeader& header);
	~ModifyData() {}

	// Inherited via PipeSerializedObject
	virtual void Write(PipeTransfer* transfer) override;
	virtual void Read(PipeTransfer* transfer) override;
};

