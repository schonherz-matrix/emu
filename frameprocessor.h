#ifndef FRAME_PROCESSOR_H_INCLUDED
#define FRAME_PROCESSOR_H_INCLUDED

#include "timer.h"
#include <mutex>
#include <memory>
#include <deque>
#include <QObject>

#include "rpc.h"
#include "matrix.h"

class FrameProcessor: public QObject {
	Q_OBJECT
	private:
		EmuConfiguration config_;
		std::deque<Frame> frames_;
		std::mutex m_;
		std::unique_ptr<Timer> timer_;
		bool starved_;
		void timerCallback();
	signals:
		void newFrame(Frame frame);
	public:
		FrameProcessor();
		virtual ~FrameProcessor();
		const EmuConfiguration& getEmuConfiguration() const;
		void sendFrame(Frame, Frame);
};

#endif
