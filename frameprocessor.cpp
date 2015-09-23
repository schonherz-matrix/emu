#include "frameprocessor.h"
#include <thread>
#include <cmath>
#include <QDebug>

FrameProcessor::FrameProcessor(const std::string& socket_name): starved_{false} {
	socket_ = std::unique_ptr<LocalSocket>{LocalSocket::create()};
	socket_->connectToServer(socket_name.c_str(), 1000);
	socket_->readTimeout(1000);
	socket_->writeTimeout(1000);
	pipe_ = std::unique_ptr<PipeInterpreter<FrameProcessor, DaemonEmuInterface>>{new PipeInterpreter<FrameProcessor, DaemonEmuInterface>{this, socket_.release()}};
	config_ = pipe_->getEmuConfiguration();
	timer_ = std::unique_ptr<Timer>{new Timer(std::bind(&FrameProcessor::timerCallback, this), std::chrono::milliseconds((int) floor(1000.0 / config_.framerate)))};
	timer_->start();
}

FrameProcessor::~FrameProcessor() {
	timer_->stop();
	pipe_->disconnect();
}

const EmuConfiguration& FrameProcessor::getEmuConfiguration() const {
	return config_;
}

void FrameProcessor::timerCallback() {
	std::lock_guard<std::mutex> lock{m_};
	if (frames_.size() == 0) {
		starved_ = true;
		return;
	} else {
		starved_ = false;
		emit newFrame(frames_.front());
		frames_.pop_front();
	}
}

void FrameProcessor::sendFrame(Frame f1, Frame f2) {
	std::lock_guard<std::mutex> lock{m_};
	frames_.push_back(f1);
	frames_.push_back(f2);
	/*if (starved_) {
		timer_->stop();
		timer_->start();
	}*/
}

