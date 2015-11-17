#pragma once

#include "Socket.h"
#include "Packet.h"
#include "ThreadPool.h"
#include "Commands.h"
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/FL_Box.H>
#include <FL/Fl_RGB_Image.H>


namespace SL {
	namespace Remote_Access_Library {
		namespace UI {
			class MainWindow : public Fl_Double_Window {
				Fl_Box* mypicturebox = nullptr;
				Fl_RGB_Image* myimage = nullptr;
				struct rgba {
				unsigned char r, g, b, a;};
				std::vector<rgba> curimage;
				Network::NetworkEvents netevents;
				std::shared_ptr<Network::Socket> sock;
				void onreceive(const SL::Remote_Access_Library::Network::Socket* s, std::shared_ptr<SL::Remote_Access_Library::Network::Packet>& p);

			public:
				MainWindow(int x, int y, int w, int h, const char *l);

				void Update(Network::Commands::ImageChange* info, char* data, unsigned int len);
				void Connect();
			};

			

			
		
		}
	}
}