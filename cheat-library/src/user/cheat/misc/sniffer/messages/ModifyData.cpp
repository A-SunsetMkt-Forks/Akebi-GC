#include <pch-il2cpp.h>
#include "ModifyData.h"

ModifyData::ModifyData(const MessageHeader& header) : MessageBase(header), 
	modifyType(PacketModifyType::Unchanged), modifiedData({})
{

}

void ModifyData::Write(PipeTransfer* transfer)
{
	transfer->Write<PacketModifyType>(modifyType);
	if (modifyType == PacketModifyType::Modified)
		transfer->Write(modifiedData);
}

void ModifyData::Read(PipeTransfer* transfer)
{
	transfer->Read<PacketModifyType>(modifyType);
	if (modifyType == PacketModifyType::Modified)
		transfer->Read(modifiedData);
}
