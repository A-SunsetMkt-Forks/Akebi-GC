#include <pch-il2cpp.h>
#include "ModifyData.h"

ModifyData::ModifyData(const MessageHeader& header) : MessageBase(header), 
	modify_type(PacketModifyType::Unchanged)
{ }

void ModifyData::Write(PipeTransfer* transfer)
{
	transfer->Write<PacketModifyType>(modify_type);
	if (modify_type == PacketModifyType::Modified)
	{
		transfer->Write(message_id);
		transfer->Write(modified_head);
		transfer->Write(modified_message);
	}
}

void ModifyData::Read(PipeTransfer* transfer)
{
	transfer->Read<PacketModifyType>(modify_type);
	if (modify_type == PacketModifyType::Modified)
	{
		transfer->Read(message_id);
		transfer->Read(modified_head);
		transfer->Read(modified_message);
	}
}
