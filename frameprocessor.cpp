#include "frameprocessor.h"
#include <thread>
#include <cmath>
#include <QDebug>

#include "rpc.h"
#include "matrix.h"
#include "array2D.hpp"

#include <iostream>

FrameProcessor::FrameProcessor(): starved_{false} {
	config_ = getConfiguration();
	timer_ = std::unique_ptr<Timer>{new Timer(std::bind(&FrameProcessor::timerCallback, this), std::chrono::milliseconds((int) ceil(1000.0 / config_.framerate)))};
	timer_->start();
}

FrameProcessor::~FrameProcessor() {
	timer_->stop();
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

