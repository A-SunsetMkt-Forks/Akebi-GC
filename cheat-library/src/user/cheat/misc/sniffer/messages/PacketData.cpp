#include <pch-il2cpp.h>
#include "PacketData.h"

void PacketData::Write(PipeTransfer* transfer)
{
	transfer->Write(blockModeEnabled);
	transfer->Write(ioType);
	transfer->Write(dataType);
	transfer->Write(valid);
	transfer->Write(parentID);
	transfer->Write(packetID);
	transfer->Write(headRawData);
	transfer->Write(messageRawData);

	if (dataType == PacketDataType::Parsed)
	{
		transfer->Write(name);
		transfer->Write(headJson);
		transfer->Write(messageJson);
	}
}

void PacketData::Read(PipeTransfer* transfer)
{
	transfer->Read(blockModeEnabled);
	transfer->Read(ioType);
	transfer->Read(dataType);
	transfer->Read(valid);
	transfer->Read(parentID);
	transfer->Read(packetID);
	transfer->Read(headRawData);
	transfer->Read(messageRawData);

	if (dataType == PacketDataType::Parsed)
	{
		transfer->Read(name);
		transfer->Read(headJson);
		transfer->Read(messageJson);
	}
}
