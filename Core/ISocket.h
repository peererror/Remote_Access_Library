#pragma once
#include <memory>
#include "SocketStats.h"

namespace SL {
	namespace Remote_Access_Library {
		namespace Network {
			class Packet;
			struct PacketHeader;
			//this class is async so all calls return immediately and are later executed
			class ISocket : public std::enable_shared_from_this<ISocket> {
			public:

				virtual ~ISocket() { }
				//adds the data to the internal queue, does not block and returns immediately.
				virtual void send(std::shared_ptr<Packet>& pack) = 0;
				//sends a request that the socket be closed. NetworkEvents::OnClose will be called when the call is successful
				virtual void close() = 0;

				//Get the statstics for this socket
				virtual SocketStats get_SocketStats() const = 0;
				//calling connected with a host and port will attempt an async connection returns immediatly and executes the OnConnect Callback when connected. If connection fails, the OnClose callback is called
				virtual void connect(const char* host, const char* port) = 0;

			protected:
				virtual void readheader() = 0;
				virtual void readbody() = 0;
				virtual void writeheader() = 0;
				virtual void writebody() = 0;
				virtual std::shared_ptr<Packet> decompress(PacketHeader& header, char* buffer) = 0;
				virtual std::shared_ptr<Packet> compress(std::shared_ptr<Packet>& packet) = 0;
			};
		}
	}
}