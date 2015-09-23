#ifndef FRAME_PROCESSOR_H_INCLUDED
#define FRAME_PROCESSOR_H_INCLUDED

#include "timer.h"
#include "interface/frame.h"
#include "interface/emuconfiguration.h"
#include "interface/emuinterface.h"
#include "interface/daemonemuinterface.h"
#include "stub/emudaemon.hpp"
#include "ipc-rpc/localsocket.h"
#include "ipc-rpc/pipeinterpreter.hpp"
#include "core/color.h"
#include <string>
#include <mutex>
#include <memory>
#include <deque>
#include <QObject>

class FrameProcessor: public QObject, public EmuInterface {
	Q_OBJECT
	private:
		std::unique_ptr<LocalSocket> socket_;
		std::unique_ptr<PipeInterpreter<FrameProcessor, DaemonEmuInterface>> pipe_;
		EmuConfiguration config_;
		std::deque<Frame> frames_;
		std::mutex m_;
		std::unique_ptr<Timer> timer_;
		bool starved_;
		void timerCallback();
	signals:
		void newFrame(Frame frame);
	public:
		FrameProcessor(const std::string& socket_name);
		virtual ~FrameProcessor();
		const EmuConfiguration& getEmuConfiguration() const;
		void sendFrame(Frame, Frame) override;
};

#endif
